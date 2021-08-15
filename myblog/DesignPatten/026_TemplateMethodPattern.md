# ģ�巽��ģʽ

|[��һƪ](./025__StrategyPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./027_VisitorPattern.md)|
|:---:|:---:|:---:|
|[����ģʽ](./025__StrategyPattern.md)|[Ŀ¼](./index.md)|[������ģʽ](./027_VisitorPattern.md)|

    ��ļ̳���һ���ù��������าд����ķ�����Ҳһ���ù���\
    ֻ������ܲ�֪��������Ǵ�˵�е�һ�����ģʽ����

## ģ�巽��ģʽ���

ģ�巽��ģʽ�ǽϼ��ҳ��õ�һ�����ģʽ���ǻ�����ļ̳е�һ�ִ��븴�ü�������ṹֻ���ڻ����������֮��ļ̳й�ϵ��ģ�巽����һ������ķ�����������һ�������߼����̿�ܡ�

    ģ�巽��ģʽ��

    ����һ�������е��㷨�Ŀ�ܣ�����һЩ�����ӳٵ������С�ģ�巽��ģʽʹ��������Բ��ı�һ���㷨�Ľṹ�����ض�����㷨��ĳЩ�ض����衣

## ģ�巽���ṹ

ģ�巽���Ľṹ�ܼ򵥣�ֻ�л����������������ɫ��

* **AbstractClass�����ࣩ**���������࣬�ڻ����ж����������һϵ�л�������method����Щ�����Ǿ�����߳���ģ�ÿһ����������Ӧ�㷨��һ�����裬�����������п����ض��塣**�����ж�����һ��ģ�巽����template method�������涨���㷨�����̿��**��ģ�巽���ɻ��ඨ���������һϵ�л�����������һ������ʵ�֡�
* **ConcreteClass�������ࣩ**��ʵ���ڻ����������ĳ��󷽷���Ҳ���Ը����ڻ������Ѿ�ʵ�ֵķ�����

ģ�巽��ģʽ��UMLͼ���£�

![](https://img-blog.csdnimg.cn/20191110093359949.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

ģ�巽��ģʽ�ĵ��ʹ������£�

```C++
#ifndef __DEMO_H__
#define __DEMO_H__
 
// �����ࣨ���ࣩ
class AbstractClass
{
public:
	// ģ�巽��������һ���㷨�Ŀ������
	void templateMethod(){
		// do something
		method1();
		method2();
		method3();
	}
	// ��������������������
	void mehtod1(){
		// do something
	}
	// ��������2
	virtual void method2() = 0;
	// ��������3����Ĭ��ʵ��
	void mehtod3(){
		// do something
	}
};
 
// �����ࣨ������)
class ConcreteClass :public AbstractClass
{
public:
	// ʵ�ֻ�������2
	void method2(){
		// do something
	}
	// �ض����������3�����ǻ���ķ���3
	void method3(){
		// do something
	}
};
 
#endif
```

## ģ�巽��ģʽ����ʵ��

    ĳ��ָ�ƴ���ģ�����������ģʽ�´����㷨������ȫģʽ�ͷǰ�ȫģʽ��
    �ڰ�ȫģʽ�£�Ϊ�˱�֤���ݰ�ȫ��ĳ��ָ��ʶ��������Ҫ�Բɵõ�ָ��ͼ����м��ܣ�
    �ڴ���ͼ��֮ǰ�ٶԼ������ݽ��н��ܡ����ǰ�ȫģʽ�ⲻ��Ҫ���ܽ��ܹ��̡�
    ָ���㷨�������£���ͼ�������ܡ������ܡ����㷨����ָ�ơ�����������
    ����ģ�巽��ģʽģ���������̡�

�����ʵ���У�Jungle���ȶ����˻���FingerprintModule�������˻�����������ͼgetImage()���ж��Ƿ��ڰ�ȫģʽisSafeMode()������encrypt()������decrypt()������ָ��ͼ��processImage()��������output()���ڻ����ж�����һ��**ģ�巽��algorithm()���÷����ﶨ����ָ���㷨����**��

�ӻ���FingerprintModule������3�����࣬�ֱ���FingerprintModuleA��FingerprintModuleB��FingerprintModuleC������������ص����ڣ�

* **FingerprintModuleA**����ȫģʽ������RSA��Կ�ӽ��ܣ����õ�һ���汾�㷨����ָ��ͼ��
* **FingerprintModuleB**���ǰ�ȫģʽ�����õڶ����汾�㷨����ָ��ͼ��
* **FingerprintModuleC**����ȫģʽ������DH��Կ�ӽ��ܣ����õ�һ���汾�㷨����ָ��ͼ��

��ʵ����UMLͼ���£�

![](https://img-blog.csdnimg.cn/20191110104438879.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### ����

```C++
// ����
class FingerprintModule
{
public:
	FingerprintModule(){}
	void getImage(){
		printf("��ָ��ͼ��\n");
	}
	void output(){
		printf("ָ��ͼ�������!\n");
	}
	virtual bool isSafeMode() = 0;
	virtual void processImage() = 0;
	// �ӽ���
	virtual void encrypt() = 0;
	virtual void decrypt() = 0;
 
	// ģ�巽��
	void algorithm(){
		// 1.��ͼ
		getImage();
		// 2.��ȫģʽ�¼��ܺͽ���
		if (isSafeMode()){
			// 2.1. ����
			encrypt();
			// 2.2. ����
			decrypt();
		}
		// 3.����Image
		processImage();
		// 4.������
		output();
	}
};
```

### ������

```C++
// ������
class FingerprintModuleA :public FingerprintModule
{
public:
	FingerprintModuleA(){}
	void processImage(){
		printf("ʹ�� ��һ���汾�㷨 ����ָ��ͼ��\n");
	}
	bool isSafeMode(){
		printf("��ȫģʽ\n");
		return true;
	}
	void encrypt(){
		printf("ʹ��RSA��Կ����\n");
	}
	void decrypt(){
		printf("ʹ��RSA��Կ����\n");
	}
};
 
// ������
class FingerprintModuleB :public FingerprintModule
{
public:
	FingerprintModuleB(){}
	void processImage(){
		printf("ʹ�� �ڶ����汾�㷨 ����ָ��ͼ��\n");
	}
	bool isSafeMode(){
		printf("�ǰ�ȫģʽ\n");
		return false;
	}
	void encrypt(){}
	void decrypt(){}
};
 
// ������
class FingerprintModuleC :public FingerprintModule
{
public:
	FingerprintModuleC(){}
	void processImage(){
		printf("ʹ�� ��һ���汾�㷨 ����ָ��ͼ��\n");
	}
	bool isSafeMode(){
		printf("��ȫģʽ\n");
		return true;
	}
	void encrypt(){
		printf("ʹ��DH��Կ����\n");
	}
	void decrypt(){
		printf("ʹ��DH��Կ����\n");
	}
```

### �ͻ��˴���ʵ����Ч��

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

## �ܽ�

ģ�巽��ģʽ�ǻ�����ļ̳е�һ�����ģʽ��ʹ�÷ǳ�Ƶ�������㷺Ӧ���ڿ����ơ�

### �ŵ㣺

* �ڻ����ж����㷨�Ŀ�ܣ�������һЩ���̷������ɾ���������ʵ��ϸ�ڣ��������е�ʵ�ֲ�����Ӱ����ඨ����㷨�Ŀ�����̣�
* ������Ϊ�ڻ������ṩʵ�֣������ڴ��븴�ã�
* ��������Ը��ǻ���ķ���������ʵ��ĳЩ��������������ԣ�
* ���Ժܷ������չ�͸������������Ӱ���������������࣬���Ͽ���ԭ��͵�һְ��ԭ��

### ȱ�㣺

* ģ�巽��ģʽҪΪÿһ����ͬ�Ļ��������ṩһ�������࣬��������л��������ܶ࣬��ϵͳ�лᶨ��ܶ�������࣬������ĸ����ܶ࣬ϵͳ�����Ӵ�

### ���û�����

* �ָ���㷨�����Խ��㷨�Ŀ�����̶����ڻ����У����Ϊģ�巽�����������ϸ�������������ʵ�֣�
* ����������Ĺ���������ȡ�������У���ʵ�ִ��븴�ã�
* ��������Ҫ���ǻ����ĳЩ������

|[��һƪ](./025__StrategyPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./027_VisitorPattern.md)|
|:---:|:---:|:---:|
|[����ģʽ](./025__StrategyPattern.md)|[Ŀ¼](./index.md)|[������ģʽ](./027_VisitorPattern.md)|