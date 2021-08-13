# 单例模式

|[上一篇](./008_PrototypePattern.md)|[目录](./index.md)|[下一篇](./010_AdapterPattern.md)|
|:---:|:---:|:---:|
|[原型模式](./008_PrototypePattern.md)|[目录](./index.md)|[适配器模式](./010_AdapterPattern.md)|

    你能在电脑上调出两个Windows任务管理器吗？

    假设能，如果两个管理器显示的数据相同，那何必要存在两个呢？

    如果两个管理器显示的数据不同，那我该相信哪一个呢？

试试看，应该有且仅有一个吧？**一个系统里有且仅有一个Windows任务管理器实例供外界访问。**如何保证系统里有且仅有一个实例对象呢？并且能够供外界访问？你可以在系统里定义一个统一的全局变量，但这并不能防止创建多个对象（想一想，为什么？）这就是单例模式的典型应用。

对于一个软件系统中的某些类来说，只有一个实例很重要。假设Windows系统上可以同时调出两个Windows任务管理器，这两个任务管理器显示的都是同样的信息，那势必造成**内存资源的浪费**；如果这两个任务管理器显示的是不同的信息，这也给用户带来了困惑，到底哪一个才是真实的状态？

## 单例模式简介

单例模式定义：

    单例模式：

    确保一个类只有一个实例，并提供一个全局访问点来访问这个唯一实例。

单例模式有3个要点：

1. 这个类只能有一个实例；
2. 它必须自己创建这个实例；
3. 它必须自己向整个系统提供这个实例。

## 单例模式结构

单例模式结构非常简单，其UML图如下所示，只包含一个类，即单例类。为防止创建多个对象，其构造函数必须是私有的（外界不能访问）。另一方面，为了提供一个全局访问点来访问该唯一实例，单例类提供了一个公有方法getInstance来返回该实例。

![](https://img-blog.csdnimg.cn/20191020174208514.png)

## 单例模式代码及效果

### 代码

单例模式代码:

```C++
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
 
#include <iostream>
#include <string.h>
using namespace std;
 
//抽象产品类AbstractBall
class Singleton
{
public:
	static Singleton* getInstance(){
		if (instance == NULL){
			printf("创建新的实例\n");
			instance = new Singleton();
		}
		return instance;
	}
private:
	Singleton(){}
 
	static Singleton* instance;
};
 
Singleton* Singleton::instance = NULL;
 
#endif //__SINGLETON_H__
```

可以看到，构造函数是私有的（private），即单例模式对象只能在类内部实例化（这就满足了单例模式的第二个要点）​。同时，实例对象instance是静态static的，也就是全局的，假设客户端实例化了两个Singleton，但instance只有一个（这就满足了第一个要点）​。那第三个要点如何满足呢？即外界如何获取​单例对象呢？上述代码中定义了一个方法（同样也是static的）getInstance(). 接下来看看客户端如何使用​。

### 客户端代码验证：

```C++
int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    
    system("pause");
    return 0;
}
```

## 单例模式总结

### 优点：

* 单例模式提供了严格的对唯一实例的创建和访问
* 单例模式的实现可以节省系统资源

### 缺点：

* 如果某个实例负责多重职责但又必须实例唯一，那单例类的职责过多，这违背了单一职责原则
* 多线程下需要考虑线程安全机制
* 单例模式没有抽象层，不方便扩展

### 适用环境：

* 系统只需要一个实例对象
* 某个实例只允许有一个访问接口

|[上一篇](./008_PrototypePattern.md)|[目录](./index.md)|[下一篇](./010_AdapterPattern.md)|
|:---:|:---:|:---:|
|[原型模式](./008_PrototypePattern.md)|[目录](./index.md)|[适配器模式](./010_AdapterPattern.md)|