# 迭代器模式

|[上一篇](./019_InterpreterPattern.md)|[目录](./index.md)|[下一篇](./021_MediatorPattern.md)|
|:---:|:---:|:---:|
|[解释器模式](./019_InterpreterPattern.md)|[目录](./index.md)|[中介者模式](./021_MediatorPattern.md)|

    写代码不少使用数组或者类似的集合对象吧？每次要遍历一遍数组怎么办？
    For 循环！或者while循环，一个一个访问每个位置的元素，直到数组末尾。
    STL里面甚至有专门的迭代器，针对具体的集合类对象，有对应使用的迭代器。
    STL的迭代器提供了丰富的遍历方法，如访问集合对象的首位元素、末位元素、
    指定位置的元素、下一个元素……怎么样，是不是感觉有了迭代器，遍历方法不再是难事了？

## 迭代器模式概述

遍历在日常编码过程中经常使用，通常是需要对一个具有很多对象实例的集合（称为**聚合对象**）进行访问或获取。比如要取聚合对象的首位元素、判断是否在聚合对象的末尾等。针对聚合对象的遍历，迭代器模式是一种很有效的解决方案，也是一种使用频率很高的设计模式。

    迭代器模式：

    提供一种方法顺序访问一个聚合对象中的各个元素，而又不暴露该对象的内部表示。

通过引入迭代器，可以将数据的遍历功能从聚合对象中分离出来，这样一来，聚合对象只需负责存储数据，而迭代器对象负责遍历数据，使得聚合对象的职责更加单一，符合单一职责原则。

## 迭代器模式结构

迭代器模式结构中包含聚合和迭代器两个层次的结构。为方便扩展，迭代器模式常常和工厂方法模式结合。迭代器模式的UML图如下。有图可知，迭代器模式有以下几个角色：

![](https://img-blog.csdnimg.cn/2019110310444590.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

* **Iterator（抽象迭代器）**：声明了访问和遍历聚合对象元素的接口，如first()方法用于访问聚合对象中第一个元素，next()方法用于访问下一个元素，hasNext()判断是否还有下一个元素，currentItem()方法用于获取当前元素。
* **ConcreteIterator（具体迭代器）**：实现抽象迭代器声明的方法，通常具体迭代器中会专门用一个变量（称为游标）来记录迭代器在聚合对象中所处的位置。
* **Aggregate（抽象聚合类）**：用于存储和管理元素对象，声明一个创建迭代器的接口，其实是一个抽象迭代器工厂的角色。
* **ConcreteAggregate（具体聚合类）**：实现了方法createIterator()，该方法返回一个与该具体聚合类对应的具体迭代器ConcreteIterator的实例。

## 迭代器模式代码实例

    电视机遥控器是迭代器的一个现实应用，通过它可以实现对电视频道集合的遍历操作，电视机可以看成一个存储频道的聚合对象。本例Jungle将采用迭代器模式来模拟遥控器操作电视频道的过程。

很明显，遥控器是一个具体的迭代器，具有上一个频道previous() 、下一个频道next()、当前频道currentChannel()等功能；需要遍历的聚合对象是电视频道的集合，即电视机。本例的UML图如下：

![](https://img-blog.csdnimg.cn/20191103141040241.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### 抽象聚合类和具体聚合类

```C++
#ifndef __AGGREGATE_H__
#define __AGGREGATE_H__
 
#include <vector>
using namespace std;
 
// 前向声明，因为两个类互相引用
class Iterator;
class RemoteControl;
 
// 抽象聚合类 Aggregate
class Aggregate
{
public:
	Aggregate(){}
	virtual Iterator* createIterator() = 0;
};
 
// 具体聚合类 Television
class Television :public Aggregate
{
public:
	Television();
	Television(vector<string> iChannelList);
	// 实现创建迭代器
	Iterator* createIterator();
	// 获取总的频道数目
	int getTotalChannelNum();
	void play(int i);
private:
	vector<string> channelList;
};
 
#endif //__AGGREGATE_H__
```

实现：

```C++
#include "Iterator.h"
 
Television::Television(){}
 
Television::Television(vector<string> iChannelList){
	this->channelList = iChannelList;
}
 
Iterator* Television::createIterator(){
	RemoteControl *it = new RemoteControl();
	it->setTV(this);
	return (Iterator*)it;
}
 
int Television::getTotalChannelNum(){
	return channelList.size();
}
 
void Television::play(int i){
	printf("现在播放：%s……\n", channelList[i].c_str());
}
```

### 抽象迭代器

```C++
// 抽象迭代器
class Iterator
{
public:
	Iterator(){}
	// 声明抽象遍历方法
	virtual void first() = 0;
	virtual void last() = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool hasNext() = 0;
	virtual bool hasPrevious() = 0;
	virtual void currentChannel() = 0;
};
```

### 具体迭代器：RemoteControl

```C++
// 遥控器：具体迭代器
class RemoteControl :public Iterator
{
public:
	RemoteControl(){}
	void setTV(Television *iTv){
		this->tv = iTv;
		cursor = -1;
		totalNum = tv->getTotalChannelNum();
	}
	// 实现各个遍历方法
	void first(){
		cursor = 0;
	}
	void last(){
		cursor = totalNum - 1;
	}
	void next(){
		cursor++;
	}
	void previous(){
		cursor--;
	}
	bool hasNext(){
		return !(cursor == totalNum);
	}
	bool hasPrevious(){
		return !(cursor == -1);
	}
	void currentChannel(){
		tv->play(cursor);
	}
private:
	// 游标
	int cursor;
	// 总的频道数目
	int totalNum;
	// 电视
	Television* tv;
};
```

### 客户端代码示例及结果 

```C++
#include <iostream>
#include "Iterator.h"
 
int main()
{
	vector<string> channelList = { "新闻频道", "财经频道", "体育频道", "电影频道", "音乐频道", "农业频道", "四川卫视", "成都卫视" };
	// 创建电视
	Television *tv = new Television(channelList);
	// 创建遥控器
	Iterator *remoteControl = tv->createIterator();
 
	// 顺序遍历
	printf("顺序遍历:\n");
	remoteControl->first();
	// 遍历电视所有频道
	while (remoteControl->hasNext()){
		remoteControl->currentChannel();
		remoteControl->next();
	}
 
	printf("\n\n");
 
	// 逆序遍历
	printf("逆序遍历:\n");
	remoteControl->last();
	// 遍历电视所有频道
	while (remoteControl->hasPrevious()){
		remoteControl->currentChannel();
		remoteControl->previous();
	}
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

|[上一篇](./019_InterpreterPattern.md)|[目录](./index.md)|[下一篇](./021_MediatorPattern.md)|
|:---:|:---:|:---:|
|[解释器模式](./019_InterpreterPattern.md)|[目录](./index.md)|[中介者模式](./021_MediatorPattern.md)|