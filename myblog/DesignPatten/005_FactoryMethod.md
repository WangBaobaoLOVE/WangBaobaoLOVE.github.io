# 工厂方法模式

|[上一篇](./004_SimpleFactory.md)|[目录](./index.md)|[下一篇](./006_AbstractFactory.md)|
|:---:|:---:|:---:|
|[简单工厂模式](./004_SimpleFactory.md)|[目录](./index.md)|[抽象工厂模式](./006_AbstractFactory.md)|

简单工厂模式存在最大的问题是违背了“开闭原则”，每当增加新的产品时，需要修改工厂类的逻辑。为了规避这种不足，同时很好的利用简单工厂模式的优点，本节奉上工厂方法模式。

## 工厂方法模式简介

简单工厂模式中，每新增一个具体产品，就需要修改工厂类内部的判断逻辑。为了不修改工厂类，遵循**开闭原则**，**工厂方法模式中不再使用工厂类统一创建所有的具体产品，而是针对不同的产品设计了不同的工厂，每一个工厂只生产特定的产品**。

工厂方法模式定义：

**工厂方法模式：定义一个用于创建对象的接口，但是让子类决定将哪一个类实例化。工厂方法模式让一个类的实例化延迟到其子类。**

## 工厂方法模式结构

从工厂方法模式简介中，可以知道该模式有以下几种角色：

1. 抽象工厂（AbstractFactory）：所有生产具体产品的工厂类的基类，提供工厂类的公共方法；
2. 具体工厂（ConcreteFactory）：生产具体的产品
3. 抽象产品（AbstractProduct）：所有产品的基类，提供产品类的公共方法
4. 具体产品（ConcreteProduct）：具体的产品类

工厂方法模式UML类图如下：

![](https://img-blog.csdnimg.cn/20191017225402677.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

## 工厂方法模式代码实例

考虑这样一个场景，如下图：

Jungle想要进行户外运动，它可以选择打篮球、踢足球或者玩排球。和上一次的体育保管室不同，这次分别由篮球保管室、足球保管室和排球保管室，Jungle只需直接去相应的保管室就可以拿到对应的球！然后Jungle就可以愉快地玩耍了。

![](https://img-blog.csdnimg.cn/20191017225742820.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

对应的UML实例图如下图：

![](https://img-blog.csdnimg.cn/20191017235722100.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### 义抽象产品类AbstractSportProduct，方法不提供实现

```C++
    //抽象产品类AbstractProduct
    class AbstractSportProduct
    {
    public:
    	AbstractSportProduct(){
     
    	}
    	//抽象方法：
    	void printName(){};
    	void play(){};
    };
```

### 定义三个具体产品类

```C++
//具体产品类Basketball
class Basketball :public AbstractSportProduct
{
public:
	Basketball(){
		printName();
		play();
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Basketball\n");
	}
	void play(){
		printf("Jungle play Basketball\n\n");
	}
};
 
//具体产品类Football
class Football :public AbstractSportProduct
{
public:
	Football(){
		printName();
		play();
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Football\n");
	}
	void play(){
		printf("Jungle play Football\n\n");
	}
};
 
//具体产品类Volleyball
class Volleyball :public AbstractSportProduct
{
public:
	Volleyball(){
		printName();
		play();
	}
	//具体实现方法
	void printName(){
		printf("Jungle get Volleyball\n");
	}
	void play(){
		printf("Jungle play Volleyball\n\n");
	}
};
```

### 定义抽象工厂类AbstractFactory，方法为纯虚方法

```C++
//抽象工厂类
class AbstractFactory
{
public:
	virtual AbstractSportProduct *getSportProduct() = 0;
};
```

### 定义三个具体工厂类

```C++
/具体工厂类BasketballFactory
class BasketballFactory :public AbstractFactory
{
public:
	BasketballFactory(){
		printf("BasketballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
		printf("basketball");
		return new Basketball();
	}
};
 
//具体工厂类FootballFactory
class FootballFactory :public AbstractFactory
{
public:
	FootballFactory(){
		printf("FootballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
		return new Football();
	}
};
 
//具体工厂类VolleyballFactory
class VolleyballFactory :public AbstractFactory
{
public:
	VolleyballFactory(){
		printf("VolleyballFactory\n");
	}
	AbstractSportProduct *getSportProduct(){
		return new Volleyball();
	}
};
```

### 客户端使用方法示例

```C++
#include <iostream>
#include "FactoryMethod.h"
 
int main()
{
	printf("工厂方法模式\n");
	
	//定义工厂类对象和产品类对象
	AbstractFactory *fac = NULL;
	AbstractSportProduct *product = NULL;
 
	fac = new BasketballFactory();
	product = fac->getSportProduct();
 
	fac = new FootballFactory();
	product = fac->getSportProduct();
 
	fac = new VolleyballFactory();
	product = fac->getSportProduct();	
 
	system("pause");
	return 0;
}
```

### 效果

![](https://img-blog.csdnimg.cn/20191018002817934.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

## 工厂方法模式总结

如果Jungle想玩**棒球**（Baseball），只需要增加一个**棒球工厂**（BaseballFacory），然后在客户端代码中修改具体工厂类的类名，而原有的类的代码无需修改。由此可看到，相较简单工厂模式，**工厂方法模式更加符合开闭原则**。工厂方法是使用频率最高的设计模式之一，是很多开源框架和API类库的核心模式。

优点：

1. 工厂方法用于创建客户所需产品，同时向客户隐藏某个具体产品类将被实例化的细节，用户只需关心所需产品对应的工厂；
2. 工厂自主决定创建何种产品，并且创建过程封装在具体工厂对象内部，**多态性设计**是工厂方法模式的关键；
3. 新加入产品时，无需修改原有代码，**增强了系统的可扩展性，符合开闭原则。**

缺点：

1. 添加新产品时需要同时添加新的产品工厂，系统中类的数量成对增加，增加了系统的复杂度，更多的类需要编译和运行，增加了系统的额外开销；
2. 工厂和产品都引入了抽象层，客户端代码中均使用的抽象层（AbstractFactory和AbstractSportProduct ），增加了系统的抽象层次和理解难度。

适用环境：

1. 客户端不需要知道它所需要创建的对象的类；
2. 抽象工厂类通过其子类来指定创建哪个对象（运用多态性设计和里氏代换原则）

|[上一篇](./004_SimpleFactory.md)|[目录](./index.md)|[下一篇](./006_AbstractFactory.md)|
|:---:|:---:|:---:|
|[简单工厂模式](./004_SimpleFactory.md)|[目录](./index.md)|[抽象工厂模式](./006_AbstractFactory.md)|