# 桥接模式

|[上一篇](./010_AdapterPattern.md)|[目录](./index.md)|[下一篇](./012_CompositePattern.md)|
|:---:|:---:|:---:|
|[适配器模式](./010_AdapterPattern.md)|[目录](./index.md)|[组合模式](./012_CompositePattern.md)|

    Jungle有两个手机，分别是M手机和N手机，M手机上有游戏Game1，N手机上有Game2。
    每次Jungle想玩Game1时，就使用M手机，想玩Game2时，就玩N手机。
    要是某天Jungle外出，心情大好，两个游戏都想玩，那Jungle还得带上两个手机？？？
    麻不麻烦？

    如果新出一个游戏Game3，那Jungle是不是要再买一个手机呢？

    同样都是游戏软件，为什么不把所有游戏都装到一个手机上呢？

![](https://img-blog.csdnimg.cn/20191023073011756.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

## 桥接模式简介

如果系统中的某个类存在两个独立变化的维度，通过桥接模式可以将这两个维度分离开来，使两者独立扩展。如同上述实例，Jungle想用手机玩游戏，手机和游戏是两个独立变化的维度，增加一个游戏对手机没有影响，增加一个手机对游戏也没有影响。**手机上可以安装游戏，而游戏必须在手机上玩，从这个角度而言，手机和游戏之间存在较强的耦合。**

但两者可以很好的解耦，且解耦后扩展灵活：所有游戏安装在一个手机上，新出一个游戏，新安装就ok！买了新手机，同样可以装上所有游戏。这就是桥接模式：

    桥接模式：

    将抽象部分与它的实现部分解耦，使得两者都能够独立变化。

**桥接模式将两个独立变化的维度设计成两个独立的继承等级结构（而不会将两者耦合在一起形成多层继承结构），在抽象层将二者建立起一个抽象关联，该关联关系类似一座桥，将两个独立的等级结构连接起来**，故曰“桥接模式”。

## 桥接模式结构

桥接模式UML图如下图。由图可知，桥接模式包含以下角色：

![](https://img-blog.csdnimg.cn/20191023075147330.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

* **Abstraction（抽象类）**：定义抽象类的接口（抽象接口），由聚合关系可知，抽象类中包含一个Implementor类型的对象，它与Implementor之间有关联关系，既可以包含抽象业务方法，也可以包含具体业务方法；
* **Implementor（实现类接口）**：定义实现类的接口，这个接口可以与Abstraction类的接口不同。一般而言，实现类接口只定义基本操作，而抽象类的接口还可能会做更多复杂的操作。
* **RefinedAbstraction（扩充抽象类）**：具体类，实现在抽象类中定义的接口，可以调用在Implementor中定义的方法；
* **ConcreteImplementor（具体实现类）**：具体实现了Implementor接口，在不同的具体实现类中实现不同的具体操作。运行时ConcreteImplementor将替换父类。

简言之，在Abstraction类中维护一个**Implementor**类指针，需要采用不同的实现方式的时候只需要传入不同的Implementor派生类就可以了。

## 桥接模式代码实例

以引言中的故事为例，Jungle学习了桥接模式后大受启发，想实现如下操作：

    新手机上能够迅速在新手机上安装（setup）并玩（play）游戏

    新增加一个游戏时Jungle能够在已有手机上安装并play


在这个实例里，手机是**抽象类Abstraction**，具有玩游戏这样的**实现类接口Implementor**，不同的手机品牌扩充**抽象类RefinedAbstraction**，多个不同的游戏则是**具体实现类ConcreteImplementor**。

![](https://img-blog.csdnimg.cn/20191023081052665.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### 实现类

```C++
//实现类接口
class Game
{
public:
	Game(){}
	virtual void play() = 0;
private:
};
 
//具体实现类GameA
class GameA:public Game
{
public:
	GameA(){}
	void play(){
		printf("Jungle玩游戏A\n");
	}
};
 
//具体实现类GameB
class GameB :public Game
{
public:
	GameB(){}
	void play(){
		printf("Jungle玩游戏B\n");
	}
};
```

实现类Game中声明了play的接口，不过它是一个虚方法，其实现在具体实现类GameA和GameB中定义。

### 抽象类和扩充抽象类

```C++
//抽象类Phone
class Phone
{
public:
	Phone(){
	}
	//安装游戏
	virtual void setupGame(Game *igame) = 0;
	virtual void play() = 0;
private:
	Game *game;
};
 
//扩充抽象类PhoneA
class PhoneA:public Phone 
{
public:
	PhoneA(){
	}
	//安装游戏
	void setupGame(Game *igame){
		this->game = igame;
	}
	void play(){
		this->game->play();
	}
private:
	Game *game;
};
 
//扩充抽象类PhoneB
class PhoneB :public Phone
{
public:
	PhoneB(){
	}
	//安装游戏
	void setupGame(Game *igame){
		this->game = igame;
	}
	void play(){
		this->game->play();
	}
private:
	Game *game;
};
```

抽象类Phone中也声明了两个虚方法，并且定义了一个实现类的对象，使抽象和实现具有关联关系。而对象的实例化则放在客户端使用时进行。

### 客户端代码示例

```C++
#include <iostream>
#include "BridgePattern.h"
 
int main()
{
	Game *game;
	Phone *phone;
 
	//Jungle买了PhoneA品牌的手机，想玩游戏A
	phone = new PhoneA();
	game = new GameA();
	phone->setupGame(game);
	phone->play();
	printf("++++++++++++++++++++++++++++++++++\n");
 
	//Jungle想在这个手机上玩游戏B
	game = new GameB();
	phone->setupGame(game);
	phone->play();
 
	system("pause");
	return 0;
}
```

## 桥接模式总结

### 优点：

* 分离抽象接口与实现部分，使用对象间的关联关系使抽象与实现解耦；
* 桥接模式可以取代多层继承关系，多层继承违背单一职责原则，不利于代码复用；
* 桥接模式提高了系统可扩展性，某个维度需要扩展只需增加实现类接口或者具体实现类，而且不影响另一个维度，符合开闭原则。

### 缺点：

* 桥接模式难以理解，因为关联关系建立在抽象层，需要一开始就设计抽象层；
* 如何准确识别系统中的两个维度是应用桥接模式的难点。

### 适用场景： 

* 如果一个系统需要在抽象化和具体化之间增加灵活性，避免在两个层次之间增加继承关系，可以使用桥接模式在抽象层建立关联关系；
* 抽象部分和实现部分可以各自扩展而互不影响；
* 一个类存在多个独立变化的维度，可采用桥接模式。

|[上一篇](./010_AdapterPattern.md)|[目录](./index.md)|[下一篇](./012_CompositePattern.md)|
|:---:|:---:|:---:|
|[适配器模式](./010_AdapterPattern.md)|[目录](./index.md)|[组合模式](./012_CompositePattern.md)|