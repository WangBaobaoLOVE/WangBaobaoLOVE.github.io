# ���ģʽ

|[��һƪ](./013_DecoratorPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./015_FlyweightPattern.md)|
|:---:|:---:|:---:|
|[װ��ģʽ](./013_DecoratorPattern.md)|[Ŀ¼](./index.md)|[��Ԫģʽ](./015_FlyweightPattern.md)|

    �ò������ε���ĩ����Jungle��Ե�õ������Լ���
    ��ʲô�أ��ع��⣡�ǵģ��Իع��⣡

    ��������̺��鷳�����ȵ�ȥ�г������⣬�������ϴ�ã�Ȼ���кã��ٳ��⣬
    �����ܳ��ϣ��������̷��ӣ�����Jungle���ø��г��������򽻵������붼ͷ��

    ����и���ʦ�ͺ��ˣ�Jungleֱ�Ӹ��߳�ʦ����Ҫ�Իع��⡱��20���Ӻ��ʦ
    ֱ�Ӷ������Ϳ��ԡ����м���Щ����ϴ������Ĺ���Jungleͳͳ�������ˣ�
    ����JungleҲ�����ٹ����г��ͳ�����ֱ�Ӻͳ�ʦ˵�仰��ok�����Ƿ��㣡

![](https://img-blog.csdnimg.cn/20191026143857967.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

 ����������У���ʦ������һϵ�и��ӵĹ��̣���磨Jungle��ֻ�����ʦ�������ɡ���������ģʽ�У���һ�����ģʽ��ʽ��ˡ������ģʽ��

 ## ���ģʽ���

���ģʽ��һ��ʹ��Ƶ�ʽϸߵ����ģʽ�����ṩһ����۽�ɫ��װ������ӵ���ϵͳ���򻯿ͻ�������ϵͳ֮��Ľ���������ͻ���ʹ�á����ģʽ���Խ���ϵͳ����϶ȡ����û������࣬��ͬ�Ŀͻ�������Ҫ�Ͷ����ͬ����ϵͳ������ϵͳ�н����ڸ��ӵ����ù�ϵ������ͼ������������࣬ԭ�еĸ��ӵ����ù�ϵ���������ʵ�֣���ͬ�Ŀͻ���ֻ��Ҫ������ཻ����

![](https://img-blog.csdnimg.cn/20191026145332587.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

    ���ģʽ��

    Ϊ��ϵͳ�е�һ��ӿ��ṩһ��ͳһ����ڡ����ģʽ������һ���߲�ӿڣ�����ӿ�ʹ����һ��ϵͳ��������ʹ�á�

 ���ģʽ��Ӧ�úܶ࣬������������û�Ҫ����ʲô���������������֪������Ѷ����CSDN���û���ֻ��Ҫ����������ɣ�ʣ�µ������������������ɡ�

## ���ģʽ�ṹ

���ģʽ��UML�ṹͼ������ʾ��

![](https://img-blog.csdnimg.cn/20191026145707708.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

���ģʽһ�������½�ɫ��

* **Facade����۽�ɫ��**����۽�ɫ����֪����������ϵͳ�Ĺ��ܣ��������дӿͻ��˷���������ί�ɸ���Ӧ����ϵͳ�����ݸ���Ӧ����ϵͳ����
* **SubSystem����ϵͳ��ɫ��**����ϵͳ��һ���࣬�����ɶ������ɵ���ļ��ϣ���ʵ����ϵͳ����Ĺ��ܡ� 

## ���ģʽ����ʵ��

    ����������Mainframe����ֻ��Ҫ���������Ŀ�����ť��powerOn����
    ���ɵ�������Ӳ���豸��������������������ڴ棨Memory�����Լ죨selfCheck����
    CPU�����У�run����Ӳ�̣�HardDisk���Ķ�ȡ��read��������ϵͳ��OS��������
    ��load���ȡ����ĳһ���̷�����������Կ���ʧ�ܡ�

����Jungle�����ģʽ��ģ��ù��̣�������UMLͼ���£�

![](https://img-blog.csdnimg.cn/20191026152510899.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### ��ϵͳ��

������һ����4����ϵͳ��������4���ࣺMemory��CPU��HardDisk��OS������ÿ����ϵͳ�����Լ����������̡�

```C++
//��ϵͳ���ڴ�
class Memory
{
public:
	Memory(){}
	void selfCheck(){
		printf("���������ڴ��Լ졭��\n");
	}
};
 
//��ϵͳ��CPU
class CPU
{
public:
	CPU(){}
	void run(){
		printf("������������CPU���С���\n");
	}
};
 
//��ϵͳ��Ӳ��
class HardDisk
{
public:
	HardDisk(){}
	void read(){
		printf("����������ȡӲ�̡���\n");
	}
};
 
//��ϵͳ������ϵͳ
class OS
{
public:
	OS(){}
	void load(){
		printf("���������������ϵͳ����\n");
	}
};
```

### ��������

```C++
//�����
class Facade
{
public:
	Facade(){
		memory = new Memory();
		cpu = new CPU();
		hardDisk = new HardDisk();
		os = new OS();
	}
	void powerOn(){
		printf("���ڿ�������\n");
		memory->selfCheck();
		cpu->run();
		hardDisk->read();
		os->load();
		printf("������ɣ�\n");
	}
private:
	Memory *memory;
	CPU *cpu;
	HardDisk *hardDisk;
	OS *os;
};
```

### �ͻ��˴���ʾ��

```C++
#include <iostream>
#include "FacadePattern.h"
 
int main()
{
	Facade *facade = new Facade();
	facade->powerOn();
 
	printf("\n\n");
 
	system("pause");
	return 0;
}
```

## �ܽ�

### �ŵ㣺

* ���ģʽʹ�ÿͻ��˲��ع�����ϵͳ�������������ͻ��˽����Ķ�������������˿ͻ��˵ı�̣�
* ���ģʽ���Դ�󽵵�ϵͳ����϶ȣ�
* ��ϵͳ�ı仯������Ҫ�޸Ŀͻ��ˣ�ֻ��Ҫ�ʵ��޸�����༴�ɣ�
* ��ϵͳ֮�䲻���໥Ӱ�졣

### ȱ�㣺

* �����Ҫ���ӻ��߼�����ϵͳ����Ҫ�޸�����࣬Υ������ԭ��
* ���������ƿͻ���ֱ������ϵͳ�������������ǿ���ƣ���ʹ��ϵͳ���Ƚ��͡�

### ���ó�����

* Ϊ����һϵ�и��ӵ���ϵͳ�ṩһ��ͳһ�ġ��򵥵���ڣ�����ʹ�����ģʽ��
* �ͻ���������ϵͳ֮����ںܴ����������ڿͻ��˱�̣��ֻ�����ϵͳ��϶ȣ���ʹ�ͻ��˱�̸��ӣ�����ʹ�����ģʽ��

|[��һƪ](./013_DecoratorPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./015_FlyweightPattern.md)|
|:---:|:---:|:---:|
|[װ��ģʽ](./013_DecoratorPattern.md)|[Ŀ¼](./index.md)|[��Ԫģʽ](./015_FlyweightPattern.md)|