# װ��ģʽ

|[��һƪ](./012_CompositePattern.md)|[Ŀ¼](./index.md)|[��һƪ](./014_FacadePattern.md)|
|:---:|:---:|:---:|
|[���ģʽ](./012_CompositePattern.md)|[Ŀ¼](./index.md)|[���ģʽ](./014_FacadePattern.md)|

    �ɶ�������˵���ͽ�������û�����أ��¶���Ȼ�½���ֻ��10���ˡ�
    ����ס�ˣ�JungleҪ��һ��ë�£�

    ����Ż��Ǻ��䣡���ٴ���Χ��

    �죬�ϰ������ˣ��°�����ô��~~~������㣡

    ����ǰ�����룬����������Ħ�ݵ���һ���������䣬����Jungle�ִ��������ס���

    �������������ˣ�Jungle���ʲô�¿㼴��ʲô�¿㣬����װ����Jungle���ٸе����䡣����������Jungle���ٶ��·���Jungleʼ�ջ����Ǹ�Jungle���Ǹ������ڳɶ��Ĺ��ӣ���һ���ǲ���ģ�

����������������������װ��ģʽ�ĵ���Ӧ�ã�**�����ٶ���β�����ı�Jungle�ı��ʣ�����������Jungle������ů��˧��������Jungle������е�����**���������У������ж���Ĺ��ܽ�����չ���Ի�ø��ӷ����û�����Ķ���ʹ�ö�����и���ǿ��Ĺ��ܣ������װ��ģʽ��

## װ��ģʽ���

װ��ģʽ�����ڲ��ı�һ���������ܵĻ����ϸ��������Ӷ��������Ϊ�������ֻ���Ϊ��ֹˤ�������Ը��ֻ���Ĥ���ߴ��ϱ����ף�Ϊ���ۣ������ڱ�����������ͨ��ֽ��Ϊ����Я���������ӹ���������ͼ�����Ⲣ���ı��ֻ��ı��ʡ�

![](https://img-blog.csdnimg.cn/20191024220520320.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

    װ��ģʽ��

    ��̬�ظ�һ����������һЩ�����ְ�𡣾���չ���ܶ��ԣ�װ��ģʽ�ṩ��һ�ֱ�ʹ����������������������

 װ��ģʽ��һ����������̳еļ�����ͨ��һ�����붨������ķ�ʽ������̬����ְ��ʹ�ö���֮��Ĺ�����ϵȡ����֮��ļ̳й�ϵ��װ��ģʽ��������װ���࣬��װ�����мȿ��Ե��ô�װ�ε�ԭ�ж���ķ����������������µķ�����������ԭ����Ĺ��ܡ�

 ## װ��ģʽ�ṹ

 װ��ģʽ�Ľṹ��ͼ��ʾ��

 ![](https://img-blog.csdnimg.cn/20191024221618611.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

װ��ģʽ�������½�ɫ��

* **Component�����󹹼���**���Ǿ��幹�����װ����Ĺ�ͬ���࣬�������ھ��幹���ж���ķ������ͻ��˿���һ�µĶԴ�ʹ��װ��ǰ��Ķ���
* **ConcreteComponent�����幹����**�����幹�������˹�������ķ�����װ������Ը������Ӹ���Ĺ��ܣ�
* **Decorator������װ���ࣩ**�����ڸ����幹������ְ�𣬵�����ְ������������ʵ�֡�����װ����ͨ���ۺϹ�ϵ����һ�����󹹼��Ķ���ͨ���ö�����Ե���װ��֮ǰ�����ķ�������ͨ����������չ�÷������ﵽװ�ε�Ŀ�ģ�
* **ConcreteDecorator������װ���ࣩ**�� �򹹼������µĹ��ܡ�

�������ᵽ���ֻ�Ϊ�����ֻ�����һ�����幹�������ֻ��ǡ��ֻ���ֽ���ֻ����������Ǿ����װ���ࡣ��Jungle���������ǰ���Ĵ��Ϊ����Jungle������һ�����幹�����󣬸����¿�Χ�����׶��Ǿ����װ�������

## װ��ģʽ����ʵ��

�����Ը��ֻ������ֻ��ǡ������ֻ���ֽ��ϵ���ֻ�����Ϊ����չʾװ��ģʽ�Ĵ��롣������UMLͼ������ʾ��

![](https://img-blog.csdnimg.cn/20191024224124413.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### ���󹹼���

```C++
    //���󹹼�
    class Component
    {
    public:
    	Component(){}
    	virtual void operation() = 0;
    };
```

### ���幹����

```C++
    //���幹����
    class Phone :public Component
    {
    public:
    	Phone(){}
    	void operation(){
    		printf("�ֻ�\n");
    	}
    };
```

### װ����

#### ����װ����

```C++
//����װ����
class Decorator :public Component
{
public:
	Decorator(){}
	Decorator(Component *c){
		this->component = c;
	}
	void operation(){
		this->component->operation();
	}
	Component *getComponent(){
		return this->component;
	}
	void setComponent(Component *c){
		this->component = c;
	}
private:
	Component *component;
};
```

����װ��������һ����Ա����component���Լ�setter��getter������

#### ����װ����

����װ����һ�����������ֱ����ֻ���װ����DecoratorShell����ֽװ����DecoratorSticker�͹���װ����DecoratorRope��ÿһ������װ���඼�����˸����µ�ְ��newBehavior��

```C++
//����װ���ࣺ�ֻ���
class DecoratorShell:public Decorator
{
public:
	DecoratorShell(){}
	DecoratorShell(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		printf("װ�ֻ���\n");
	}
};
 
//����װ���ࣺ�ֻ���ֽ
class DecoratorSticker :public Decorator
{
public:
	DecoratorSticker(){}
	DecoratorSticker(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		printf("����ͨ��ֽ\n");
	}
};
 
//����װ���ࣺ�ֻ�����
class DecoratorRope :public Decorator
{
public:
	DecoratorRope(){}
	DecoratorRope(Component *c){
		this->setComponent(c);
	}
	void operation(){
		this->getComponent()->operation();
		this->newBehavior();
	}
	void newBehavior(){
		printf("ϵ�ֻ�����\n");
	}
};
```

## �ͻ��˴���ʾ��

�ͻ���չʾ�����δ��룬�ֱ�Ϊ�����ֻ����ϲ�ͬ��װ�Σ�

```C++
#include <iostream>
#include "DecoratorPattern.h"
 
int main()
{
	printf("\nJungle�ĵ�һ���ֻ���\n");
	Component *c;
	Component *com_Shell;
	c = new Phone();
	com_Shell = new DecoratorShell(c);
	com_Shell->operation();
 
	printf("\nJungle�ĵڶ����ֻ���\n");
	Component *c2;
	Component *com_Shell2;
	c2 = new Phone();
	com_Shell2 = new DecoratorShell(c2);
	Component *com_Sticker;
	com_Sticker = new DecoratorSticker(com_Shell2);
	com_Sticker->operation();
 
	printf("\nJungle�ĵ������ֻ���\n");
	Component *c3;
	Component *com_Shell3;
	c3 = new Phone();
	com_Shell3 = new DecoratorShell(c3);
	Component *com_Sticker2;
	com_Sticker2 = new DecoratorSticker(com_Shell3);
	Component *com_Rope;
	com_Rope = new DecoratorRope(com_Sticker2);
	com_Rope->operation();
 
	printf("\n\n");
 
	system("pause");
	return 0;
}
```

## �ܽ�

### �ŵ㣺

* ������չһ������¹��ܣ�װ��ģʽ�ȼ̳и�����
* ��̬��չһ������Ĺ��ܣ�
* ���Զ�һ��������ж��װ�Σ����������ӵڶ����ֻ��͵������ֻ�����
* ���幹����;���װ������Զ����仯����չ�����Ͽ���ԭ��

### ȱ�㣺

* װ��ģʽ�л����Ӻܶ�С�Ķ��󣬶����������Ҫ���ڸ���װ�ε����ӷ�ʽ��ͬ����������ְ��ͬ������С����Ĳ�����ռ�ý϶��ϵͳ��Դ��
* װ��ģʽ�ȼ̳�ģʽ������Ҳ�����׳����������Ŵ�

### ���ó�����

* �ڲ�Ӱ���������������£�����������̬��չְ��
* �����˲��ü̳еķ�ʽ������չ��ʱ�򣬿��Կ���ʹ��װ��ģʽ��


|[��һƪ](./012_CompositePattern.md)|[Ŀ¼](./index.md)|[��һƪ](./014_FacadePattern.md)|
|:---:|:---:|:---:|
|[���ģʽ](./012_CompositePattern.md)|[Ŀ¼](./index.md)|[���ģʽ](./014_FacadePattern.md)|