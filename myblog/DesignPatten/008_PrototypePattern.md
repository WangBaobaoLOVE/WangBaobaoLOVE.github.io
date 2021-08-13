# 原型模式

|[上一篇](./007_BuilderPattern.md)|[目录](./index.md)|[下一篇](./009_SinglePattern.md)|
|:---:|:---:|:---:|
|[建造者模式](./007_BuilderPattern.md)|[目录](./index.md)|[单例模式](./009_SinglePattern.md)|

## 原型模式简介

原型模式通过复制一个已有对象来获取更多相同或者相似的对象。原型模式定义如下：

    原型模式：

    使用原型实例指定待创建对象的类型，并且通过复制这个原型来创建新的对象。

原型模式的工作原理是将一个原型对象传给要发动创建的对象（即客户端对象），这个要发动创建的对象通过**请求原型对象复制自己来实现创建过程**。从工厂方法角度而言，创建新对象的工厂就是原型类自己。软件系统中有些对象的创建过程比较复杂，且有时需要频繁创建，原型模式通过给出一个原型对象来指明所要创建的对象的类型，然后用复制这个原型对象的办法创建出更多同类型的对象，这就是原型模式的意图所在。

## 原型模式结构

原型式的结构包含以下几个角色：

* 抽象原型类（AbstractPrototype）：声明克隆clone自身的接口
* 具体原型类（ConcretePrototype）：实现clone接口
* 客户端（Client）：客户端中声明一个抽象原型类，根据客户需求clone具体原型类对象实例

原型模式的UML图如下：

![](https://img-blog.csdnimg.cn/20191020091656554.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

## 关于克隆方法：浅拷贝/深拷贝

原型模式可以说是“复制”，即克隆，但这个复制不是代码的复制，而是将对象包含的所有属性都创建一份拷贝。但不同的复制操作，可能会产生两种不同的拷贝，即**浅拷贝**和**深拷贝**。

### 浅拷贝

在浅拷贝中，如果原型对象的成员变量是**值类型**（如int、double、char等基本数据类型），将复制一份给拷贝对象；如果原型对象的成员变量是**引用/指针**，则将引用/指针指向的地址拷贝一份给拷贝对象，即原型对象和拷贝对象中的成员变量指向同一个地址。

### 深拷贝

在深拷贝中，无论原型对象中的成员变量是值类型还是指针/引用类型，都将复制一份给拷贝对象。注意，深拷贝中，指针/引用对象也会被拷贝一份给拷贝对象。

下图举例说明了浅拷贝与深拷贝的区别：

![](https://img-blog.csdnimg.cn/20191020093201763.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

## 原型模式代码实例

    明天就是周一了，Jungle又陷入了苦恼中，因为作业还没完成。
    于是Jungle想拿着哥哥Single的作业来抄一份。
    虽然抄袭作业并不好，但是边抄边学借鉴一下也是可以的。
    于是乎，Jungle开始动起手来……

 作业包含几个部分：姓名（name）、学号（idNum）、模型(workModel)。首先定义一个workModel类：

```C++
//work model类
class WorkModel
{
public:
    char *modelName;
    void setWorkModelName(char *iName){
        this->modelName = iName;
    }
};
```

该实例UML图如下：

![](https://img-blog.csdnimg.cn/20191020110342531.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### 定义原型类和克隆方法

```C++
//抽象原型类PrototypeWork
class PrototypeWork
{
public:
	PrototypeWork(){}
	virtual PrototypeWork *clone() = 0;
 
private:
	
};
 
//具体原型类ConcreteWork
class ConcreteWork :public PrototypeWork
{
private:
	char* name;
	int idNum;
	WorkModel *workModel;
public:
	ConcreteWork(){}
	ConcreteWork(char* iName, int iIdNum, char* modelName){
		this->name = iName;
		this->idNum = iIdNum;
		this->workModel = new WorkModel();
		this->workModel->setWorkModelName(modelName);
	}
	
	ConcreteWork *clone(){
		ConcreteWork *work = new ConcreteWork();
		work->setName(this->name);
		work->setIdNum(this->idNum);
		work->workModel = this->workModel;
		return work;
	}
 
	void setName(char* iName){
		this->name = iName;
	}
	void setIdNum(int iIdNum){
		this->idNum = iIdNum;
	}
	void setModel(WorkModel *iWorkModel){
		this->workModel = iWorkModel;
	}
	//打印work信息
	void printWorkInfo(){
		printf("name:%s\t\n", this->name);
		printf("idNum:%d\t\n", this->idNum);
		printf("modelName:%s\t\n", this->workModel->modelName);
	}
};
```

### 客户端使用代码示例

#### 示例一：浅拷贝

```C++
#include "PrototypePattern.h"
 
int main()
{
	ConcreteWork *singleWork = new ConcreteWork("Single",1001,"Single_Model");
	printf("\nSingle的作业：\n");
	singleWork->printWorkInfo();
	
	printf("\njungle直接抄作业……\n");
	ConcreteWork *jungleWork = singleWork;
	printf("\nJungle的作业：\n");
	jungleWork->printWorkInfo();
 
	//抄完改名字和学号，否则会被老师查出来
	printf("\njungle抄完改名字和学号，否则会被老师查出来……\n");
	jungleWork->setName("jungle");
	jungleWork->setIdNum(1002);
	WorkModel *jungleModel = new WorkModel();
	jungleModel->setWorkModelName("Jungle_Model");
	jungleWork->setModel(jungleModel);
	
	//检查下是否改对了
	printf("\nSingle的作业：\n");
	singleWork->printWorkInfo();
	printf("\nJungle的作业：\n");
	jungleWork->printWorkInfo();
 
	system("pause");
	return 0;
}
```

#### 示例二：深拷贝

```C++
#include "PrototypePattern.h"
 
int main()
{
	ConcreteWork *singleWork = new ConcreteWork("Single", 1001, "Single_Model");
	printf("\nSingle的作业：\n");
 
	ConcreteWork *jungleWork = singleWork->clone();
	printf("\nJungle的作业：\n");
 
	//抄完改名字和学号，否则会被老师查出来
	printf("\njungle抄完改名字和学号，否则会被老师查出来……\n");
	jungleWork->setName("jungle");
	jungleWork->setIdNum(1002);
	WorkModel *jungleModel = new WorkModel();
	jungleModel->setWorkModelName("Jungle_Model");
	jungleWork->setModel(jungleModel);
 
	//检查下是否改对了
	printf("\nSingle的作业：\n");
	singleWork->printWorkInfo();
	printf("\nJungle的作业：\n");
	jungleWork->printWorkInfo();
 
	system("pause");
	return 0;
}
```

## 原型模式总结

### 优点：

* 当创建新的对象实例较为复杂时，原型模式可以简化创建过程，提高创建对象的效率；
* 可扩展：模式中提供了抽象原型类，具体原型类可适当扩展；
* 创建结构简单：创建工厂即为原型对象本身

### 缺点：

* 深克隆代码较为复杂；
* 每一个类都得配备一个clone方法，且该方法位于类的内部，修改时违背开闭原则；

### 适用环境：

* 当创建新的对象实例较为复杂时，原型模式可以简化创建过程；
* 结合优点第3条，需要避免使用分层次的工厂类来创建分层次的对象，并且类的实例对象只有一个或很少几个的组合状态，通过复制原型对象得到新实例，比通过使用构造函数创建一个新实例会更加方便。

|[上一篇](./007_BuilderPattern.md)|[目录](./index.md)|[下一篇](./009_SinglePattern.md)|
|:---:|:---:|:---:|
|[建造者模式](./007_BuilderPattern.md)|[目录](./index.md)|[单例模式](./009_SinglePattern.md)|