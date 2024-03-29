# 观察者模式

|[上一篇](./022_MementoPattern.md)|[目录](./index.md)|[下一篇](./024_StatePattern.md)|
|:---:|:---:|:---:|
|[备忘录模式](./022_MementoPattern.md)|[目录](./index.md)|[状态模式](./024_StatePattern.md)|

    每当Jungle公众号【Jungle笔记】更新发布了文章，作为Jungle的关注者，
    你会第一时间接到消息，（如果）然后就可以去查看、点赞、评论和转发，
    接下来的一天你都高高兴兴；

    每当Jungle更新了CSDN博客，作为Jungle的支持者，你也会在打开CSDN网站的时候看到
    消息，（如果）然后你就可以去查看、点赞、评论和转发，接下来的一周你都高高兴兴。

也就是说，“Jungle更新发布文章”这个行为可能会导致“关注者查看、评论、点赞”等一系列行为。这表明“Jungle更新发布文章”并不是孤立的，而是与众多对象产生了关联。**一个对象行为的改变，其相关联的对象都会得到通知，并自动产生对应的行为。这在软件设计模式中，即是观察者模式**。

## 观察者模式简介

软件系统中的对象并不是孤立存在的，一个对象行为的改变可能会引起其他所关联的对象的状态或行为也发生改变，即“牵一发而动全身”。观察者模式建立了一种一对多的联动，一个对象改变时将自动通知其他对象，其他对象将作出反应。观察者模式中，发生改变的对象称为“观察目标”，被通知的对象称为“观察者”。一个观察目标可以有很多个观察者。

观察者模式定义如下：

    观察者模式：

    定义对象之间的一种一对多的依赖关系，使得每当一个对象状态发生改变时，
    其相关依赖对象都得到通知并被自动更新。

观察者模式又被称为发布-订阅模式（Publish-Subscribe）、模型-视图模式（Model-View）、源-监听器模式（Source-Listener）、从属者模式（Dependents）。 

## 观察者模式结构

观察者模式由观察者和观察目标组成，为便于扩展，两个角色都设计了抽象层。观察者模式的UML图如下：

![](https://img-blog.csdnimg.cn/20191106074204410.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

* **Subject（目标）**：是被观察的对象，目标中定义了一个观察者的集合，即一个目标可能会有多个观察者，通过attach()和detach()方法来增删观察者对象。目标声明了通知方法notify()，用于在自身状态发生改变时通知观察者。
* **ConcreteSubject（具体目标）**：具体目标实现了通知方法notify()，同时具体目标有记录自身状态的属性和成员方法；
* **Observer（观察者）**：观察者将对接收到的目标发生改变的通知做出自身的反应，抽象层声明了更新方法update()；
* **ConcreteObserver（具体观察者）**： 实现了更新方法update()，具体观察者中维护了一个具体目标对象的引用（指针），用于存储目标的状态。

下述是观察者模式的典型实现：

```C++
#ifndef __DEMO_H__
#define __DEMO_H__
 
// 抽象观察者
class Observer
{
public:
	// 声明响应更新方法
	virtual void update() = 0;
};
 
// 具体观察者
class ConcreteObserver:public Observer
{
public:
	// 实现响应更新方法
	void update(){
		// 具体操作
	}
};
 
// 抽象目标
class Subject
{
public:
	// 添加观察者
	void attach(Observer* obs){
		obsList.push_back(obs);
	}
	// 移除观察者
	void detach(Observer* obs){
		obsList.remove(obs);
	}
	// 声明通知方法
	virtual void notify() = 0;
protected:
	// 观察者列表
	list<Observer*>obsList;
};
 
// 具体目标
class ConcreteSubject :public Subject
{
public:
	// 实现通知方法
	void notify(){
		// 具体操作
		// 遍历通知观察者对象
		for (int i = 0; i < obsList.size(); i++){
			obsList[i]->update();
		}
	}
};
 
// 客户端代码示例
int main()
{
	Subject  *sub = new ConcreteSubject();
	Observer *obs = new ConcreteObserver();
	sub->attach(obs);
	sub->notify();
	return 0;
}
#endif //__DEMO_H__
```

## 观察者模式代码实例

    玩过和平精英这款游戏吗？四人组队绝地求生，当一个队友发现物资时，
    可以发消息“我这里有物资”，其余三个队友听到后可以去取物资；
    当一个队友遇到危险时，也可以发消息“救救我”，其余三个队友得到
    消息后便立马赶去营救。本例Jungle将用观察者模式来模拟这个过程。

本例的UML图如下：

![](https://img-blog.csdnimg.cn/20191106210750554.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

本例中，抽象观察者是Observer，声明了发现物资或者需要求救时的呼叫的方法call()，具体观察者是Player，即玩家，Player实现了呼叫call()方法，并且还定义了取物资come()和支援队友help()的方法。本例定义了AllyCenter作为抽象目标，它维护了一个玩家列表playerList，并且定义了加入战队和剔除玩家的方法。具体目标是联盟中心控制器AllyCenterController，它实现了通知notify()方法，该方法将队友call的消息传达给玩家列表里的其余队友，并作出相应的响应。源代码见https://github.com/FengJungle/DesignPattern。

### 公共头文件

通过一个枚举类型来定义两种消息类型，即发现物资和求助

```C++
    #ifndef __COMMON_H__
    #define __COMMON_H__
     
    enum INFO_TYPE{
    	NONE,
    	RESOURCE,
    	HELP
    };
     
    #endif //__COMMON_H__
```

### 观察者

#### 抽象观察者Observer

```C++
// 抽象观察者 Observer
class Observer
{
public:
	Observer(){}
	// 声明抽象方法
	virtual void call(INFO_TYPE infoType, AllyCenter* ac) = 0;
	string getName(){
		return name;
	}
	void setName(string iName){
		this->name = iName;
	}
private:
	string name;
};
```

#### 具体观察者Player

```C++
// 具体观察者 
class Player :public Observer
{
public:
	Player(){
		setName("none");
	}
	Player(string iName){
		setName(iName);
	}
	// 实现
	void call(INFO_TYPE infoType, AllyCenter* ac){
		switch (infoType){
		case RESOURCE:
			printf("%s :我这里有物资\n", getName().c_str());
			break;
		case HELP:
			printf("%s :救救我\n", getName().c_str());
			break;
		default:
			printf("Nothing\n");
		}
		ac->notify(infoType, getName());
	}
	// 实现具体方法
	void help(){
		printf("%s:坚持住，我来救你！\n", getName().c_str());
	}
	void come(){
		printf("%s:好的，我来取物资\n", getName().c_str());
	}
};
```

### 目标类 

#### 抽象目标AllyCenter

```C++
// 抽象目标：联盟中心
class AllyCenter
{
public:
	AllyCenter();
	// 声明通知方法
	virtual void notify(INFO_TYPE infoType, std::string name) = 0;
	// 加入玩家
	void join(Observer* player);
	// 移除玩家
	void remove(Observer* player);
protected:
	// 玩家列表
	std::vector<Observer*>playerList;
};
```

```C++
#include "AllyCenter.h"
#include "Observer.h"
 
AllyCenter::AllyCenter(){
	printf("大吉大利，今晚吃鸡!\n");
}
 
// 加入玩家
void AllyCenter::join(Observer* player){
	if (playerList.size() == 4){
		printf("玩家已满\n");
		return;
	}
	printf("玩家 %s 加入\n", player->getName().c_str());
	playerList.push_back(player);
	if (playerList.size() == 4){
		printf("组队成功，不要怂，一起上！\n");
	}
}
// 移除玩家
void AllyCenter::remove(Observer* player){
	printf("玩家 %s 退出\n", player->getName().c_str());
	//playerList.remove(player);
}
```

#### 具体目标AllyCenterController

```C++
// 具体目标
class AllyCenterController :public AllyCenter
{
public:
	AllyCenterController();
	// 实现通知方法
	void notify(INFO_TYPE infoType, std::string name);
};

AllyCenterController::AllyCenterController(){}
 
// 实现通知方法
void AllyCenterController::notify(INFO_TYPE infoType, std::string name){
	switch (infoType){
	case RESOURCE:
		for each (Observer* obs in playerList){
			if (obs->getName() != name){
				((Player*)obs)->come();
			}
		}
		break;
	case HELP:
		for each (Observer* obs in playerList){
			if (obs->getName() != name){
				((Player*)obs)->help();
			}
		}
		break;
	default:
		printf("Nothing\n");
	}
}
```

### 客户端代码示例及效果

```C++
#include "Observer.h"
#include "AllyCenter.h"
 
int main()
{
	// 创建一个战队
	AllyCenterController* controller = new AllyCenterController();
 
	// 创建4个玩家，并加入战队
	Player* Jungle = new Player("Jungle");
	Player* Single = new Player("Single");
	Player* Jianmengtu = new Player("贱萌兔");
	Player* SillyDog = new Player("傻子狗");
	controller->join(Jungle);
	controller->join(Single);
	controller->join(Jianmengtu);
	controller->join(SillyDog);
 
	printf("\n\n");
 
	// Jungle发现物资，呼叫队友
	Jungle->call(RESOURCE, controller);
 
	printf("\n\n");
 
	// 傻子狗遇到危险，求救队友
	SillyDog->call(HELP, controller);
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

## 观察者模式的应用

观察者模式是一种使用频率非常高的设计模式，几乎无处不在。凡是涉及一对一、一对多的对象交互场景，都可以使用观察者会模式。比如购物车，浏览商品时，往购物车里添加一件商品，会引起UI多方面的变化（购物车里商品数量、对应商铺的显示、价格的显示等）；各种编程语言的GUI事件处理的实现；所有的浏览器事件（mouseover，keypress等）都是使用观察者模式的例子。

## 总结

### 优点：

* 观察者模式实现了稳定的消息更新和传递的机制，通过引入抽象层可以扩展不同的具体观察者角色；
* 支持广播通信，所有已注册的观察者（添加到目标列表中的对象）都会得到消息更新的通知，简化了一对多设计的难度；
* 符合开闭原则，增加新的观察者无需修改已有代码，在具体观察者与观察目标之间不存在关联关系的情况下增加新的观察目标也很方便。

### 缺点：

* 代码中观察者和观察目标相互引用，存在循环依赖，观察目标会触发二者循环调用，有引起系统崩溃的风险；
* 如果一个观察目标对象有很多直接和简介观察者，将所有的观察者都通知到会耗费大量时间。

### 适用环境：

* 一个对象的改变会引起其他对象的联动改变，但并不知道是哪些对象会产生改变以及产生什么样的改变；
* 如果需要设计一个链式触发的系统，可是使用观察者模式；
* 广播通信、消息更新通知等场景。

|[上一篇](./022_MementoPattern.md)|[目录](./index.md)|[下一篇](./024_StatePattern.md)|
|:---:|:---:|:---:|
|[备忘录模式](./022_MementoPattern.md)|[目录](./index.md)|[状态模式](./024_StatePattern.md)|