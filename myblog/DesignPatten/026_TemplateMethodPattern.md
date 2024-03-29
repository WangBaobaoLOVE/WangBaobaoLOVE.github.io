# 模板方法模式

|[上一篇](./025__StrategyPattern.md)|[目录](./index.md)|[下一篇](./027_VisitorPattern.md)|
|:---:|:---:|:---:|
|[策略模式](./025__StrategyPattern.md)|[目录](./index.md)|[访问者模式](./027_VisitorPattern.md)|

    类的继承你一定用过，派生类覆写基类的方法你也一定用过，\
    只是你可能不知道，这就是传说中的一种设计模式……

## 模板方法模式简介

模板方法模式是较简单且常用的一种设计模式，是基于类的继承的一种代码复用技术，其结构只存在基类和派生类之间的继承关系。模板方法是一个具体的方法，给出了一个顶层逻辑流程框架。

    模板方法模式：

    定义一个操作中的算法的框架，而将一些步骤延迟到子类中。模板方法模式使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。

## 模板方法结构

模板方法的结构很简单，只有基类和派生类两个角色：

* **AbstractClass（基类）**：即抽象类，在基类中定义或声明了一系列基本操作method，这些操作是具体或者抽象的，每一个操作都对应算法的一个步骤，在其派生类中可以重定义。**基类中定义了一个模板方法（template method），它规定了算法的流程框架**，模板方法由基类定义或声明的一系列基本操作按照一定流程实现。
* **ConcreteClass（派生类）**：实现在基类中声明的抽象方法，也可以覆盖在基类中已经实现的方法。

模板方法模式的UML图如下：

![](https://img-blog.csdnimg.cn/20191110093359949.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

模板方法模式的典型代码如下：

```C++
#ifndef __DEMO_H__
#define __DEMO_H__
 
// 抽象类（基类）
class AbstractClass
{
public:
	// 模板方法，定义一个算法的框架流程
	void templateMethod(){
		// do something
		method1();
		method2();
		method3();
	}
	// 基本方法——公共方法
	void mehtod1(){
		// do something
	}
	// 基本方法2
	virtual void method2() = 0;
	// 基本方法3——默认实现
	void mehtod3(){
		// do something
	}
};
 
// 具体类（派生类)
class ConcreteClass :public AbstractClass
{
public:
	// 实现基本方法2
	void method2(){
		// do something
	}
	// 重定义基本方法3，覆盖基类的方法3
	void method3(){
		// do something
	}
};
 
#endif
```

## 模板方法模式代码实例

    某个指纹处理模块可以在两种模式下处理算法，即安全模式和非安全模式。
    在安全模式下，为了保证数据安全，某个指纹识别流程需要对采得的指纹图像进行加密，
    在处理图像之前再对加密数据进行解密。而非安全模式这不需要加密解密过程。
    指纹算法流程如下：采图——加密——解密——算法处理指纹——处理结果。
    现用模板方法模式模拟上述过程。

在这个实例中，Jungle首先定义了基类FingerprintModule，声明了基本方法：采图getImage()、判断是否在安全模式isSafeMode()、加密encrypt()、解密decrypt()、处理指纹图像processImage()、输出结果output()，在基类中定义了一个**模板方法algorithm()，该方法里定义了指纹算法流程**。

从基类FingerprintModule派生出3个子类，分别是FingerprintModuleA、FingerprintModuleB和FingerprintModuleC，三个子类的特点在于：

* **FingerprintModuleA**：安全模式，采用RSA秘钥加解密，采用第一代版本算法处理指纹图像；
* **FingerprintModuleB**：非安全模式，采用第二代版本算法处理指纹图像；
* **FingerprintModuleC**：安全模式，采用DH秘钥加解密，采用第一代版本算法处理指纹图像；

该实例的UML图如下：

![](https://img-blog.csdnimg.cn/20191110104438879.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### 基类

```C++
// 基类
class FingerprintModule
{
public:
	FingerprintModule(){}
	void getImage(){
		printf("采指纹图像\n");
	}
	void output(){
		printf("指纹图像处理完成!\n");
	}
	virtual bool isSafeMode() = 0;
	virtual void processImage() = 0;
	// 加解密
	virtual void encrypt() = 0;
	virtual void decrypt() = 0;
 
	// 模板方法
	void algorithm(){
		// 1.采图
		getImage();
		// 2.安全模式下加密和解密
		if (isSafeMode()){
			// 2.1. 加密
			encrypt();
			// 2.2. 解密
			decrypt();
		}
		// 3.处理Image
		processImage();
		// 4.处理结果
		output();
	}
};
```

### 派生类

```C++
// 派生类
class FingerprintModuleA :public FingerprintModule
{
public:
	FingerprintModuleA(){}
	void processImage(){
		printf("使用 第一代版本算法 处理指纹图像\n");
	}
	bool isSafeMode(){
		printf("安全模式\n");
		return true;
	}
	void encrypt(){
		printf("使用RSA密钥加密\n");
	}
	void decrypt(){
		printf("使用RSA密钥解密\n");
	}
};
 
// 派生类
class FingerprintModuleB :public FingerprintModule
{
public:
	FingerprintModuleB(){}
	void processImage(){
		printf("使用 第二代版本算法 处理指纹图像\n");
	}
	bool isSafeMode(){
		printf("非安全模式\n");
		return false;
	}
	void encrypt(){}
	void decrypt(){}
};
 
// 派生类
class FingerprintModuleC :public FingerprintModule
{
public:
	FingerprintModuleC(){}
	void processImage(){
		printf("使用 第一代版本算法 处理指纹图像\n");
	}
	bool isSafeMode(){
		printf("安全模式\n");
		return true;
	}
	void encrypt(){
		printf("使用DH密钥加密\n");
	}
	void decrypt(){
		printf("使用DH密钥解密\n");
	}
```

### 客户端代码实例及效果

```C++
#include "FingerprintModule.h"
#include <Windows.h>
 
int main()
{
	FingerprintModule *fp = new FingerprintModuleA();
	fp->algorithm();
 
	fp = new FingerprintModuleB();
	fp->algorithm();
 
	fp = new FingerprintModuleC();
	fp->algorithm();
 
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

## 总结

模板方法模式是基于类的继承的一种设计模式，使用非常频繁，被广泛应用于框架设计。

### 优点：

* 在基类中定义算法的框架，并声明一些流程方法，由具体派生类实现细节，派生类中的实现并不会影响基类定义的算法的框架流程；
* 公共行为在基类中提供实现，有利于代码复用；
* 派生类可以覆盖基类的方法，重新实现某些方法，具有灵活性；
* 可以很方便的扩展和更换派生类而不影响基类和其他派生类，符合开闭原则和单一职责原则。

### 缺点：

* 模板方法模式要为每一个不同的基本方法提供一个派生类，如果基类中基本方法很多，那系统中会定义很多个派生类，导致类的个数很多，系统更加庞大。

### 适用环境：

* 分割复杂算法，可以将算法的框架流程定义在基类中，设计为模板方法；而具体的细节由派生类设计实现；
* 各个派生类的公共部分提取到基类中，以实现代码复用；
* 派生类需要覆盖基类的某些方法。

|[上一篇](./025__StrategyPattern.md)|[目录](./index.md)|[下一篇](./027_VisitorPattern.md)|
|:---:|:---:|:---:|
|[策略模式](./025__StrategyPattern.md)|[目录](./index.md)|[访问者模式](./027_VisitorPattern.md)|