# ״̬ģʽ

|[��һƪ](./023_ObserverPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./025__StrategyPattern.md)|
|:---:|:---:|:---:|
|[�۲���ģʽ](./023_ObserverPattern.md)|[Ŀ¼](./index.md)|[����ģʽ](./025__StrategyPattern.md)|

    �����б�����ϣ���������Բȱ����
    
    �ܶ��������ض�������ת���ɲ�ͬ��״̬��
    
    �ڲ�ͬ״̬�±��ֳ���ͬ����Ϊ��

�����ϵͳ�У���Щ�����ڲ�ͬ��������Ҳ���в�ͬ��״̬����ͬ״̬֮������໥ת����ͨ���жϲ�ͬ��������֧��if...else...����switch..case...�����Խ���״̬��ת�����������Ʊ�ʹ�ô�����ж��߼���ø��ӣ�����ϵͳ�Ŀ�ά���ԡ�����¼���һ��״̬������Ҫ�޸��ж��߼��������Ͽ���ԭ��

Ϊ������Ӷ���Ķ���״̬ת�����⣬��ʹ�ͻ��˴��������״̬֮�����϶Ƚ��ͣ�����ʹ��״̬ģʽ��

## ״̬ģʽ���

״̬ģʽ��һ�������״̬�Ӷ����з����������װ��ר�ŵ�״̬���У�ʹ�ö���״̬�������仯�����ڿͻ��˶��ԣ�������Ķ���ת̬��ת���Լ����������ĵ�ǰ״̬�����۴��ں���״̬�Ķ��󣬿ͻ��˶�����һ�´���

    ״̬ģʽ��

    ����һ�����������ڲ�״̬�ı�ʱ�ı�������Ϊ�����������ƺ��޸��������ࡣ

## ״̬ģʽ�ṹ

״̬ģʽ��UMLͼ���¡�

![](https://img-blog.csdnimg.cn/20191109074950587.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

״̬ģʽ�����˳���㣬���г���״̬��;���״̬�࣬������һ�������ľ���:

* **Context���������ࣩ**����ӵ�ж���״̬�Ķ������������״̬���ڶ����ԣ������ڲ�ͬ��״̬�£�������ֳ���ͬ����Ϊ�������������У�ά����һ������״̬���ʵ����
* **State������״̬�ࣩ**��������һ���ӿڣ����ڷ�װ�������������е�һ���ض�״̬��ص���Ϊ����������ʵ���ڸ��ֲ�ͬ״̬��Ӧ�ķ�������ͬ��������ܴ��ڲ�ͬ��ʵ�ַ�������ͬ�ķ�������д�ڳ���״̬���С�
* **ConcreteState������״̬�ࣩ**��ʵ�־���״̬�µķ�����ÿһ������״̬���Ӧһ�������״̬��

ֵ��ע����ǣ���������ά����һ��״̬���ָ��������ã�**�������������������þ���ʵ����Ϊ��һ�������״̬����Ҳ�����ɾ����״̬��������ת��Ϊ��һ��ʵ�������ԣ����������״̬��֮��������������໥���õĹ�ϵ**��

```C++
// 1.�ɻ�����������ʵ����Ϊ��һ������״̬�����
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
	// ����״̬����
	State *state;
};
// 2.�о���״̬��������ת������һ������״̬�����
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

������״̬ģʽ�ĵ����÷���

```C++
#ifndef __DEMO_H__
#define __DEMO_H__
 
// ����״̬��
class State
{
public:
	// �������󷽷�
	virtual void handle() = 0;
};
 
// ����״̬��
class ConcreteState :public State
{
public:
	// ʵ��
	void handle(){
		// ����
	}
};
 
// ��������
class Context
{
public:
	// set��������״̬����
	void setState(State* iState){
		this->state = iState;
	}
	// �����װ�ķ���
	void request(){
		// do something
		state->handle();
	}
private:
	// ����״̬����
	State *state;
};
 
#endif //__DEMO_H__
```

## ״̬ģʽ����ʵ��

������Jungle��һ��ʵ����Ӧ��״̬ģʽ��

    ��ĳֽ����Ϸ�У���Ϸ�����Ϊ���ż���primary������������Secondary����
    ���ּ���Professional���͹ǻҼ���Final�����ּ���������Ļ���������
    ��ɫ�ȼ�����Ϸʤ�������ӻ��֣�ʧ�ܽ��۳����֡����ż������������Ϸ����
    play()����������������Ϸʤ�����ּӱ�����doubleScore()�����ּ���������
    �Ļ����������˻��ƹ���changeCards()���ǻҼ��ڸ��ּ��Ļ�������������
    ͵������ֽ�ƵĹ���peekCards()��

    ���ֹ������£�

    �����֣�100����Ϸʤ��+50�֣���Ϸʧ��+30�֣�

    ���ż���0~150��������150~200�����ּ���200~250���ǻҼ���250����

![](https://img-blog.csdnimg.cn/20191109100845108.png)

���������Ϸ�˻�GameAccountΪ�������࣬ά����һ�������ࣨLevel���Ķ���ʵ����GameAccount�ж�����һ��������ֵ�score���ͺ�ͳһ��װ�ķ���playcard()���ڸ÷������ٵ��þ��弶��ĸ������ܷ���������������ķ�ʽ������ж��ƾֵ���Ӯ�����������֡�

������LevelΪ�����࣬������play()��doubleScore()��changeCards()��seekCards()�ĳ��󷽷������ĸ����弶����Primary��Secondary��Professional��Final���о���ʵ���˸÷�����������˵�Ǹ��ݸü����Ƿ���Ȩ��ʹ�øü�������ӡһ�л���upgradeLevel()���������ж�ÿ���ƽ��������Ϸ�˻��Ļ����Ƿ�����������߽�����ͨ��setLevel()�����ı䵱ǰ�˻�����Ϸ����

��ʵ����UMLͼ���£�

![](https://img-blog.csdnimg.cn/2019110910182763.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### �������ࣺ��Ϸ�˻���

```C++
//ͷ�ļ�
#ifndef __GAMEACCOUNT_H__
#define __GAMEACCOUNT_H__
 
using namespace std;
#include <iostream>
// ǰ������
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
 
//Դ�ļ�
#include "GameAccount.h"
#include "Level.h"
#include <Windows.h>
#include <time.h>
#define  random(x) (rand()%x)
 
GameAccount::GameAccount(){
	printf("������Ϸ��ɫ�����֣�100������PRIMARY\n");
	score = 100;
	name = "none";
	setLevel(new Primary(this));
}
 
GameAccount::GameAccount(string iName){
	printf("������Ϸ��ɫ�����֣�100������PRIMARY\n");
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
	printf("\n\tʤ�������»���Ϊ %d\n", score);
}
 
void GameAccount::lose(){
	setScore(getScore() + 30);
	printf("\n\t���ƣ����»���Ϊ %d\n", score);
}
 
int GameAccount::getScore(){
	return this->score;
}
 
void GameAccount::setScore(int iScore){
	this->score = iScore;
}
```

### ״̬��

##### ����״̬�ࣺLevel

ͷ�ļ���

```C++
#include "GameAccount.h"
 
class Level
{
public :
	Level();
	// ��������
	void playCard();
	void play();
	virtual void doubleScore() = 0;
	virtual void changeCards() = 0;
	virtual void peekCards() = 0;
	// ����
	virtual void upgradeLevel() = 0;
	GameAccount* getGameAccount();
	void setGameAccount(GameAccount* iGameAccount);
private:
	GameAccount* gameAccount;
};
```

Դ�ļ���

```C++
Level::Level(){}
 
void Level::playCard(){
	this->play();
	this->doubleScore();
	this->changeCards();
	this->peekCards();
}
 
void Level::play(){
	printf("\tʹ�û�������,");
}
 
void Level::setGameAccount(GameAccount* iGameAccount){
	this->gameAccount = iGameAccount;
}
 
GameAccount* Level::getGameAccount(){
	return gameAccount;
}
```

#### ����״̬�ࣺPrimary

ͷ�ļ���

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
    	// ����
    	void upgradeLevel();
    };
```

Դ�ļ���

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
    		printf("\t������ ����SECONDARY\n\n");
    	}
    	else{
    		printf("\n");
    	}
    }
```

#### ����״̬�ࣺSecondary

ͷ�ļ���

```C++
    class Secondary :public Level
    {
    public:
    	Secondary();
    	Secondary(Level* level);
    	void doubleScore();
    	void changeCards();
    	void peekCards();
    	// ����
    	void upgradeLevel();
    };
```

Դ�ļ���

```C++
   Secondary::Secondary(){
     
    }
     
    Secondary::Secondary(Level* level){
    	this->setGameAccount(level->getGameAccount());
    	getGameAccount()->setLevel(level);
    }
     
    void Secondary::doubleScore(){
    	printf("ʹ��ʤ��˫�����ּ���");
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
    		printf("\t������ ����PRIMARY\n\n");
    	}
    	else if (this->getGameAccount()->getScore() > 200){
    		this->getGameAccount()->setLevel(new Professional(this));
    		printf("\t������ ����PROFESSIONAL\n\n");
    	}
    }
```

#### ����״̬�ࣺProfessional

ͷ�ļ���

```C++
  class Professional :public Level
    {
    public:
    	Professional();
    	Professional(Level* level);
    	void doubleScore();
    	void changeCards();
    	void peekCards();
    	// ����
    	void upgradeLevel();
    };
```

Դ�ļ���

```C++
   Professional::Professional(){
     
    }
     
    Professional::Professional(Level* level){
    	this->setGameAccount(level->getGameAccount());
    	getGameAccount()->setLevel(level);
    }
     
    void Professional::doubleScore(){
    	printf("ʹ��ʤ��˫�����ּ���,");
    }
     
    void Professional::changeCards(){
    	printf("ʹ�û��Ƽ���");
    }
     
    void Professional::peekCards(){
    	return;
    }
     
    void Professional::upgradeLevel(){
    	if (this->getGameAccount()->getScore() < 200){
    		this->getGameAccount()->setLevel(new Secondary(this));
    		printf("\t������ ����SECONDARY\n\n");
    	}
    	else if (this->getGameAccount()->getScore() > 250){
    		this->getGameAccount()->setLevel(new Final(this));
    		printf("\t������ ����FINAL\n\n");
    	}
    }
```

#### ����״̬�ࣺFinal

ͷ�ļ���

```C++
   class Final :public Level
    {
    public:
    	Final();
    	Final(Level* level);
    	void doubleScore();
    	void changeCards();
    	void peekCards();
    	// ����
    	void upgradeLevel();
    };
```

Դ�ļ���

```C++
  Final::Final(){
     
    }
     
    Final::Final(Level* level){
    	this->setGameAccount(level->getGameAccount());
    	getGameAccount()->setLevel(level);
    }
     
    void Final::doubleScore(){
    	printf("ʹ��ʤ��˫�����ּ���,");
    }
     
    void Final::changeCards(){
    	printf("ʹ�û��Ƽ���,");
    }
     
    void Final::peekCards(){
    	printf("ʹ��͵�����Ƽ���");
    }
     
    void Final::upgradeLevel(){
    	if (this->getGameAccount()->getScore() < 250){
    		this->getGameAccount()->setLevel(new Professional(this));
    		printf("\t������ ����PROFESSIONAL\n\n");
    	}
    	else{
    		printf("\t%s �Ѿ�����߼�\n\n", this->getGameAccount()->getName().c_str());
    	}
    }
```
  
### �ͻ��˴���ʾ�������

�ͻ��˴��봴����һ����Ϸ�˻�Jungle����ʼ����Ϊ100�֣�����ΪPrimary�������ż���Jungleһ������5���ơ�

```C++
    #include "GameAccount.h"
    #include "Level.h"
     
    int main()
    {
    	GameAccount *jungle = new GameAccount("Jungle");
     
    	for (int i = 0; i < 5; i++){
    		printf("��%d�֣�\n", i + 1);
    		jungle->playCard();
    	}
     
    	printf("\n\n");
    	system("pause");
    	return 0;
    }
```

 ����Ĵ��벻��Jungle��ǰ��ʲô���𣬶�ͳһ�ص��������������װ�õķ���playcard()������粢��֪����ͬ�����ڲ��ľ���ʵ��ϸ�ڡ����н����ʾ��Jungle���ڲ�ͬ��״̬���������ܹ����ֲ�ͬ����Ϊ����ͬ�ļ��ܣ��������ܹ����ϸı������״̬�������򽵼�����

## �ܽ�

### �ŵ㣺

* ״̬ģʽ��װ��״̬ת���Ĺ���ֻ����籩¶��ͳһ�Ľӿڣ��ͻ��˿����޲��ص��øýӿڣ�������ʵ���Ŀͻ��˴��룩
* ״̬ģʽ�����������״̬�йص���Ϊ�ŵ�һ���ࣨ����״̬�ࣩ�У�ֻ��Ҫע�루��������ͬ��״̬��������������У�����ʹ��������ӵ�в�ͬ����Ϊ

### ȱ�㣺

* ״̬ģʽ������ϵͳ����ĸ�������ͬ�ľ���״̬�ࣩ
* �ṹ��Ը��ӣ���ǰ��ʵ����UMLͼ���������߼�Ҳ�ϸ���
* ���Ҫ�����µ�״̬����Ҫ�޸ĸ���״̬ת���Ĵ��룬�����Ͽ���ԭ��������ʵ�������������һ���м伶���ǲ��ǵ��޸ĺܶ�״̬ת�����߼�����

### ���û�����

* �������Ϊ��������״̬�ĸı����ͬ
* �����к��д��������״̬�йص��ж��߼���if����else������switch����case������

|[��һƪ](./023_ObserverPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./025__StrategyPattern.md)|
|:---:|:---:|:---:|
|[�۲���ģʽ](./023_ObserverPattern.md)|[Ŀ¼](./index.md)|[����ģʽ](./025__StrategyPattern.md)|