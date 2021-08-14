# �Ž�ģʽ

|[��һƪ](./010_AdapterPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./012_CompositePattern.md)|
|:---:|:---:|:---:|
|[������ģʽ](./010_AdapterPattern.md)|[Ŀ¼](./index.md)|[���ģʽ](./012_CompositePattern.md)|

    Jungle�������ֻ����ֱ���M�ֻ���N�ֻ���M�ֻ�������ϷGame1��N�ֻ�����Game2��
    ÿ��Jungle����Game1ʱ����ʹ��M�ֻ�������Game2ʱ������N�ֻ���
    Ҫ��ĳ��Jungle����������ã�������Ϸ�����棬��Jungle���ô��������ֻ�������
    �鲻�鷳��

    ����³�һ����ϷGame3����Jungle�ǲ���Ҫ����һ���ֻ��أ�

    ͬ��������Ϸ�����Ϊʲô����������Ϸ��װ��һ���ֻ����أ�

![](https://img-blog.csdnimg.cn/20191023073011756.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

## �Ž�ģʽ���

���ϵͳ�е�ĳ����������������仯��ά�ȣ�ͨ���Ž�ģʽ���Խ�������ά�ȷ��뿪����ʹ���߶�����չ����ͬ����ʵ����Jungle�����ֻ�����Ϸ���ֻ�����Ϸ�����������仯��ά�ȣ�����һ����Ϸ���ֻ�û��Ӱ�죬����һ���ֻ�����ϷҲû��Ӱ�졣**�ֻ��Ͽ��԰�װ��Ϸ������Ϸ�������ֻ����棬������Ƕȶ��ԣ��ֻ�����Ϸ֮����ڽ�ǿ����ϡ�**

�����߿��ԺܺõĽ���ҽ������չ��������Ϸ��װ��һ���ֻ��ϣ��³�һ����Ϸ���°�װ��ok���������ֻ���ͬ������װ��������Ϸ��������Ž�ģʽ��

    �Ž�ģʽ��

    �����󲿷�������ʵ�ֲ��ֽ��ʹ�����߶��ܹ������仯��

**�Ž�ģʽ�����������仯��ά����Ƴ����������ļ̳еȼ��ṹ�������Ὣ���������һ���γɶ��̳нṹ�����ڳ���㽫���߽�����һ������������ù�����ϵ����һ���ţ������������ĵȼ��ṹ��������**����Ի���Ž�ģʽ����

## �Ž�ģʽ�ṹ

�Ž�ģʽUMLͼ����ͼ����ͼ��֪���Ž�ģʽ�������½�ɫ��

![](https://img-blog.csdnimg.cn/20191023075147330.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

* **Abstraction�������ࣩ**�����������Ľӿڣ�����ӿڣ����ɾۺϹ�ϵ��֪���������а���һ��Implementor���͵Ķ�������Implementor֮���й�����ϵ���ȿ��԰�������ҵ�񷽷���Ҳ���԰�������ҵ�񷽷���
* **Implementor��ʵ����ӿڣ�**������ʵ����Ľӿڣ�����ӿڿ�����Abstraction��Ľӿڲ�ͬ��һ����ԣ�ʵ����ӿ�ֻ���������������������Ľӿڻ����ܻ������ิ�ӵĲ�����
* **RefinedAbstraction����������ࣩ**�������࣬ʵ���ڳ������ж���Ľӿڣ����Ե�����Implementor�ж���ķ�����
* **ConcreteImplementor������ʵ���ࣩ**������ʵ����Implementor�ӿڣ��ڲ�ͬ�ľ���ʵ������ʵ�ֲ�ͬ�ľ������������ʱConcreteImplementor���滻���ࡣ

����֮����Abstraction����ά��һ��**Implementor**��ָ�룬��Ҫ���ò�ͬ��ʵ�ַ�ʽ��ʱ��ֻ��Ҫ���벻ͬ��Implementor������Ϳ����ˡ�

## �Ž�ģʽ����ʵ��

�������еĹ���Ϊ����Jungleѧϰ���Ž�ģʽ�������������ʵ�����²�����

    ���ֻ����ܹ�Ѹ�������ֻ��ϰ�װ��setup�����棨play����Ϸ

    ������һ����ϷʱJungle�ܹ��������ֻ��ϰ�װ��play


�����ʵ����ֻ���**������Abstraction**����������Ϸ������**ʵ����ӿ�Implementor**����ͬ���ֻ�Ʒ������**������RefinedAbstraction**�������ͬ����Ϸ����**����ʵ����ConcreteImplementor**��

![](https://img-blog.csdnimg.cn/20191023081052665.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### ʵ����

```C++
//ʵ����ӿ�
class Game
{
public:
	Game(){}
	virtual void play() = 0;
private:
};
 
//����ʵ����GameA
class GameA:public Game
{
public:
	GameA(){}
	void play(){
		printf("Jungle����ϷA\n");
	}
};
 
//����ʵ����GameB
class GameB :public Game
{
public:
	GameB(){}
	void play(){
		printf("Jungle����ϷB\n");
	}
};
```

ʵ����Game��������play�Ľӿڣ���������һ���鷽������ʵ���ھ���ʵ����GameA��GameB�ж��塣

### ����������������

```C++
//������Phone
class Phone
{
public:
	Phone(){
	}
	//��װ��Ϸ
	virtual void setupGame(Game *igame) = 0;
	virtual void play() = 0;
private:
	Game *game;
};
 
//���������PhoneA
class PhoneA:public Phone 
{
public:
	PhoneA(){
	}
	//��װ��Ϸ
	void setupGame(Game *igame){
		this->game = igame;
	}
	void play(){
		this->game->play();
	}
private:
	Game *game;
};
 
//���������PhoneB
class PhoneB :public Phone
{
public:
	PhoneB(){
	}
	//��װ��Ϸ
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

������Phone��Ҳ�����������鷽�������Ҷ�����һ��ʵ����Ķ���ʹ�����ʵ�־��й�����ϵ���������ʵ��������ڿͻ���ʹ��ʱ���С�

### �ͻ��˴���ʾ��

```C++
#include <iostream>
#include "BridgePattern.h"
 
int main()
{
	Game *game;
	Phone *phone;
 
	//Jungle����PhoneAƷ�Ƶ��ֻ���������ϷA
	phone = new PhoneA();
	game = new GameA();
	phone->setupGame(game);
	phone->play();
	printf("++++++++++++++++++++++++++++++++++\n");
 
	//Jungle��������ֻ�������ϷB
	game = new GameB();
	phone->setupGame(game);
	phone->play();
 
	system("pause");
	return 0;
}
```

## �Ž�ģʽ�ܽ�

### �ŵ㣺

* �������ӿ���ʵ�ֲ��֣�ʹ�ö����Ĺ�����ϵʹ������ʵ�ֽ��
* �Ž�ģʽ����ȡ�����̳й�ϵ�����̳�Υ����һְ��ԭ�򣬲����ڴ��븴�ã�
* �Ž�ģʽ�����ϵͳ����չ�ԣ�ĳ��ά����Ҫ��չֻ������ʵ����ӿڻ��߾���ʵ���࣬���Ҳ�Ӱ����һ��ά�ȣ����Ͽ���ԭ��

### ȱ�㣺

* �Ž�ģʽ������⣬��Ϊ������ϵ�����ڳ���㣬��Ҫһ��ʼ����Ƴ���㣻
* ���׼ȷʶ��ϵͳ�е�����ά����Ӧ���Ž�ģʽ���ѵ㡣

### ���ó����� 

* ���һ��ϵͳ��Ҫ�ڳ��󻯺;��廯֮����������ԣ��������������֮�����Ӽ̳й�ϵ������ʹ���Ž�ģʽ�ڳ���㽨��������ϵ��
* ���󲿷ֺ�ʵ�ֲ��ֿ��Ը�����չ������Ӱ�죻
* һ������ڶ�������仯��ά�ȣ��ɲ����Ž�ģʽ��

|[��һƪ](./010_AdapterPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./012_CompositePattern.md)|
|:---:|:---:|:---:|
|[������ģʽ](./010_AdapterPattern.md)|[Ŀ¼](./index.md)|[���ģʽ](./012_CompositePattern.md)|