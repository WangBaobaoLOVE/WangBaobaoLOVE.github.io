# 状态模式

|[上一篇](./023_ObserverPattern.md)|[目录](./index.md)|[下一篇](./025__StrategyPattern.md)|
|:---:|:---:|:---:|
|[观察者模式](./023_ObserverPattern.md)|[目录](./index.md)|[策略模式](./025__StrategyPattern.md)|

    “人有悲欢离合，月有阴晴圆缺”。
    
    很多事物在特定条件下转换成不同的状态，
    
    在不同状态下表现出不同的行为。

在软件系统中，有些对象在不同的条件下也具有不同的状态，不同状态之间可以相互转换。通过判断不同的条件分支（if...else...或者switch..case...）可以进行状态的转换。但这样势必使得代码的判断逻辑变得复杂，降低系统的可维护性。如果新加入一种状态，还需要修改判断逻辑，不符合开闭原则。

为解决复杂对象的多种状态转换问题，并使客户端代码与对象状态之间的耦合度降低，可以使用状态模式。

## 状态模式简介

状态模式将一个对象的状态从对象中分离出来，封装到专门的状态类中，使得对象状态可以灵活变化。对于客户端而言，无需关心对象转态的转换以及对象所处的当前状态，无论处于何种状态的对象，客户端都可以一致处理。

    状态模式：

    允许一个对象在其内部状态改变时改变它的行为。对象看起来似乎修改了它的类。

## 状态模式结构

状态模式的UML图如下。

![](https://img-blog.csdnimg.cn/20191109074950587.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

状态模式引入了抽象层，具有抽象状态类和具体状态类，还包括一个上下文境类:

* **Context（上下文类）**：是拥有多种状态的对象。上下文类的状态存在多样性，并且在不同的状态下，对象表现出不同的行为。在上下文类中，维护了一个抽象状态类的实例。
* **State（抽象状态类）**：声明了一个接口，用于封装与在上下文类中的一个特定状态相关的行为，在子类中实现在各种不同状态对应的方法。不同的子类可能存在不同的实现方法，相同的方法可以写在抽象状态类中。
* **ConcreteState（具体状态类）**：实现具体状态下的方法，每一个具体状态类对应一个具体的状态。

值得注意的是，上下文中维护了一个状态类的指针或者引用，**可以由上下文类来觉得具体实例化为哪一个具体的状态对象，也可以由具体的状态类来决定转换为哪一个实例，所以，上下文类和状态类之间存在依赖甚至相互引用的关系**：

```C++
// 1.由环境类来决定实例化为哪一个具体状态类对象
class Context
{
public:
	void convertState(){
		if (condition1){
			this->state = new ConcreteStateA();
		}
		else if (condition2){
			this->state = new ConcreteStateB();
		}
		else{
			// do something
		}
	}
private:
	// 引用状态对象
	State *state;
};
// 2.有具体状态类来决定转换成哪一个具体状态类对象
class ConcreteState :public State
{
public:
	void convertState(Context* ctx){
		if (condition1){
			ctx->setState(new ConcreteStateA());
		}
		else if (condition2){
			ctx->setState(new ConcreteStateB());
		}
		else{
			// do something
		}
	}
};
```

下面是状态模式的典型用法：

```C++
#ifndef __DEMO_H__
#define __DEMO_H__
 
// 抽象状态类
class State
{
public:
	// 声明抽象方法
	virtual void handle() = 0;
};
 
// 具体状态类
class ConcreteState :public State
{
public:
	// 实现
	void handle(){
		// ……
	}
};
 
// 上下文类
class Context
{
public:
	// set方法设置状态对象
	void setState(State* iState){
		this->state = iState;
	}
	// 对外封装的方法
	void request(){
		// do something
		state->handle();
	}
private:
	// 引用状态对象
	State *state;
};
 
#endif //__DEMO_H__
```

## 状态模式代码实例

接下来Jungle用一个实例来应用状态模式。

    在某纸牌游戏中，游戏人物分为入门级（primary）、熟练级（Secondary）、
    高手级（Professional）和骨灰级（Final）四种级别，由人物的积分来划分
    角色等级，游戏胜利将增加积分，失败将扣除积分。入门级有最基本的游戏功能
    play()，熟练级增加了游戏胜利积分加倍功能doubleScore()，高手级在熟练级
    的基础上增加了换牌功能changeCards()，骨灰级在高手级的基础上再增加了
    偷看他人纸牌的功能peekCards()。

    积分规则如下：

    基础分：100，游戏胜利+50分，游戏失败+30分；

    入门级：0~150；熟练级150~200；高手级：200~250；骨灰级：250以上

![](https://img-blog.csdnimg.cn/20191109100845108.png)

本例设计游戏账户GameAccount为上下文类，维护了一个级别类（Level）的对象实例。GameAccount中定义了一个代表积分的score整型和统一封装的方法playcard()，在该方法中再调用具体级别的各个技能方法。采用随机数的方式来随机判定牌局的输赢，以增减积分。

级别类Level为抽象类，声明了play()、doubleScore()、changeCards()、seekCards()的抽象方法，在四个具体级别类Primary、Secondary、Professional和Final类中具体实现了该方法，具体来说是根据该级别是否有权利使用该技能来打印一行话。upgradeLevel()方法用于判断每局牌结束后该游戏账户的积分是否可以升级或者降级，通过setLevel()方法改变当前账户的游戏级别。

该实例的UML图如下：

![](https://img-blog.csdnimg.cn/2019110910182763.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### 上下文类：游戏账户类

```C++
//头文件
#ifndef __GAMEACCOUNT_H__
#define __GAMEACCOUNT_H__
 
using namespace std;
#include <iostream>
// 前向声明
class Level;
 
class GameAccount
{
public:
	GameAccount();
	GameAccount(string iName);
	string getName();
	void win();
	void lose();
	void playCard();
	void setLevel(Level*);
	int getScore();
	void setScore(int);
 
private:
	Level* level;
	int score;
	string name;
};
 
#endif
 
//源文件
#include "GameAccount.h"
#include "Level.h"
#include <Windows.h>
#include <time.h>
#define  random(x) (rand()%x)
 
GameAccount::GameAccount(){
	printf("创立游戏角色，积分：100，级别：PRIMARY\n");
	score = 100;
	name = "none";
	setLevel(new Primary(this));
}
 
GameAccount::GameAccount(string iName){
	printf("创立游戏角色，积分：100，级别：PRIMARY\n");
	score = 100;
	name = iName;
	setLevel(new Primary(this));
}
 
void GameAccount::setLevel(Level* iLevel){
	this->level = iLevel;
}
 
string GameAccount::getName(){
	return name;
}
 
void GameAccount::playCard(){
	this->level->playCard();
 
	Sleep(100);
	srand((int)time(0));
	int res = random(2);
	if (res % 2 == 0){
		this->win();
	}
	else{
		this->lose();
	}
 
	this->level->upgradeLevel();
}
 
void GameAccount::win(){
	if (this->getScore() < 200){
		setScore(getScore() + 50);
	}
	else{
		setScore(getScore() + 100);
	}
	printf("\n\t胜利，最新积分为 %d\n", score);
}
 
void GameAccount::lose(){
	setScore(getScore() + 30);
	printf("\n\t输牌，最新积分为 %d\n", score);
}
 
int GameAccount::getScore(){
	return this->score;
}
 
void GameAccount::setScore(int iScore){
	this->score = iScore;
}
```

### 状态类

##### 抽象状态类：Level

头文件：

```C++
#include "GameAccount.h"
 
class Level
{
public :
	Level();
	// 声明方法
	void playCard();
	void play();
	virtual void doubleScore() = 0;
	virtual void changeCards() = 0;
	virtual void peekCards() = 0;
	// 升级
	virtual void upgradeLevel() = 0;
	GameAccount* getGameAccount();
	void setGameAccount(GameAccount* iGameAccount);
private:
	GameAccount* gameAccount;
};
```

源文件：

```C++
Level::Level(){}
 
void Level::playCard(){
	this->play();
	this->doubleScore();
	this->changeCards();
	this->peekCards();
}
 
void Level::play(){
	printf("\t使用基本技能,");
}
 
void Level::setGameAccount(GameAccount* iGameAccount){
	this->gameAccount = iGameAccount;
}
 
GameAccount* Level::getGameAccount(){
	return gameAccount;
}
```

#### 具体状态类：Primary

头文件：

```C++
    class Primary :public Level
    {
    public:
    	Primary();
    	Primary(Level* level);
    	Primary(GameAccount* ga);
    	void doubleScore();
    	void changeCards();
    	void peekCards();
    	// 升级
    	void upgradeLevel();
    };
```

源文件：

```C++
    Primary::Primary(){}
     
    Primary::Primary(GameAccount* iGameAccount){
    	this->setGameAccount(iGameAccount);
    }
     
    Primary::Primary(Level* level){
    	getGameAccount()->setLevel(level);
    }
     
    void Primary::doubleScore(){
    	return;
    }
     
    void Primary::changeCards(){
    	return;
    }
     
    void Primary::peekCards(){
    	return;
    }
     
    void Primary::upgradeLevel(){
    	if (this->getGameAccount()->getScore() > 150){
    		this->getGameAccount()->setLevel(new Secondary(this));
    		printf("\t升级！ 级别：SECONDARY\n\n");
    	}
    	else{
    		printf("\n");
    	}
    }
```

#### 具体状态类：Secondary

头文件：

```C++
    class Secondary :public Level
    {
    public:
    	Secondary();
    	Secondary(Level* level);
    	void doubleScore();
    	void changeCards();
    	void peekCards();
    	// 升级
    	void upgradeLevel();
    };
```

源文件：

```C++
   Secondary::Secondary(){
     
    }
     
    Secondary::Secondary(Level* level){
    	this->setGameAccount(level->getGameAccount());
    	getGameAccount()->setLevel(level);
    }
     
    void Secondary::doubleScore(){
    	printf("使用胜利双倍积分技能");
    }
     
    void Secondary::changeCards(){
    	return;
    }
     
    void Secondary::peekCards(){
    	return;
    }
     
    void Secondary::upgradeLevel(){
    	if (this->getGameAccount()->getScore() < 150){
    		this->getGameAccount()->setLevel(new Primary(this));
    		printf("\t降级！ 级别：PRIMARY\n\n");
    	}
    	else if (this->getGameAccount()->getScore() > 200){
    		this->getGameAccount()->setLevel(new Professional(this));
    		printf("\t升级！ 级别：PROFESSIONAL\n\n");
    	}
    }
```

#### 具体状态类：Professional

头文件：

```C++
  class Professional :public Level
    {
    public:
    	Professional();
    	Professional(Level* level);
    	void doubleScore();
    	void changeCards();
    	void peekCards();
    	// 升级
    	void upgradeLevel();
    };
```

源文件：

```C++
   Professional::Professional(){
     
    }
     
    Professional::Professional(Level* level){
    	this->setGameAccount(level->getGameAccount());
    	getGameAccount()->setLevel(level);
    }
     
    void Professional::doubleScore(){
    	printf("使用胜利双倍积分技能,");
    }
     
    void Professional::changeCards(){
    	printf("使用换牌技能");
    }
     
    void Professional::peekCards(){
    	return;
    }
     
    void Professional::upgradeLevel(){
    	if (this->getGameAccount()->getScore() < 200){
    		this->getGameAccount()->setLevel(new Secondary(this));
    		printf("\t降级！ 级别：SECONDARY\n\n");
    	}
    	else if (this->getGameAccount()->getScore() > 250){
    		this->getGameAccount()->setLevel(new Final(this));
    		printf("\t升级！ 级别：FINAL\n\n");
    	}
    }
```

#### 具体状态类：Final

头文件：

```C++
   class Final :public Level
    {
    public:
    	Final();
    	Final(Level* level);
    	void doubleScore();
    	void changeCards();
    	void peekCards();
    	// 升级
    	void upgradeLevel();
    };
```

源文件：

```C++
  Final::Final(){
     
    }
     
    Final::Final(Level* level){
    	this->setGameAccount(level->getGameAccount());
    	getGameAccount()->setLevel(level);
    }
     
    void Final::doubleScore(){
    	printf("使用胜利双倍积分技能,");
    }
     
    void Final::changeCards(){
    	printf("使用换牌技能,");
    }
     
    void Final::peekCards(){
    	printf("使用偷看卡牌技能");
    }
     
    void Final::upgradeLevel(){
    	if (this->getGameAccount()->getScore() < 250){
    		this->getGameAccount()->setLevel(new Professional(this));
    		printf("\t降级！ 级别：PROFESSIONAL\n\n");
    	}
    	else{
    		printf("\t%s 已经是最高级\n\n", this->getGameAccount()->getName().c_str());
    	}
    }
```
  
### 客户端代码示例及结果

客户端代码创建了一个游戏账户Jungle，初始积分为100分，级别为Primary，即入门级，Jungle一共玩了5局牌。

```C++
    #include "GameAccount.h"
    #include "Level.h"
     
    int main()
    {
    	GameAccount *jungle = new GameAccount("Jungle");
     
    	for (int i = 0; i < 5; i++){
    		printf("第%d局：\n", i + 1);
    		jungle->playCard();
    	}
     
    	printf("\n\n");
    	system("pause");
    	return 0;
    }
```

 上面的代码不管Jungle当前是什么级别，都统一地调用了上下文类封装好的方法playcard()，即外界并不知道不同级别内部的具体实现细节。运行结果显示，Jungle的在不同的状态（级别）下能够表现不同的行为（不同的技能），并且能够不断改变自身的状态（升级或降级）。

## 总结

### 优点：

* 状态模式封装了状态转换的规则，只给外界暴露了统一的接口，客户端可以无差别地调用该接口（如上述实例的客户端代码）
* 状态模式将所有与具体状态有关的行为放到一个类（具体状态类）中，只需要注入（依赖）不同的状态类对象到上下文类中，即可使上下文中拥有不同的行为

### 缺点：

* 状态模式增加了系统中类的个数（不同的具体状态类）
* 结构相对复杂（如前述实例的UML图），代码逻辑也较复杂
* 如果要增加新的状态，需要修改负责状态转换的代码，不符合开闭原则（如上述实例，如果增加了一个中间级别，是不是得修改很多状态转换的逻辑？）

### 适用环境：

* 对象的行为根据它的状态的改变而不同
* 代码中含有大量与对象状态有关的判断逻辑（if……else……或switch……case……）

|[上一篇](./023_ObserverPattern.md)|[目录](./index.md)|[下一篇](./025__StrategyPattern.md)|
|:---:|:---:|:---:|
|[观察者模式](./023_ObserverPattern.md)|[目录](./index.md)|[策略模式](./025__StrategyPattern.md)|