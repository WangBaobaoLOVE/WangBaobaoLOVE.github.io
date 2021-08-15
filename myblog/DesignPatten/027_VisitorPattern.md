# ������ģʽ

|[��һƪ](./026_TemplateMethodPattern.md)|[Ŀ¼](./index.md)|[��һƪ]()|
|:---:|:---:|:---:|
|[ģ�巽��ģʽ](./026_TemplateMethodPattern.md)|[Ŀ¼](./index.md)|[]()|

    ŷҮ������Jungle����ҵ���������ˣ���ҵ��ʲô�أ��������һ��ϰ��ᡣ
    Jungle����֮�󣬵��üҳ����ϰ��Ტǩ�֣��ڶ��콻��ѧУ���鳤�ó���
    �����ҵ�Ƿ����ꡢ�ҳ��Ƿ�ǩ�֣�Ȼ����ʦ��������ҵ�Ƿ���ȷ�����������֡�

    ������ôһ��ϰ��ᣬ���Ǿ��˶����˵��ְ���

                Jungle�������ϰ����ϵ��⣻

                Jungle�ҳ����������ӵ���ҵ������ϰ�����ǩ�֣�

                �鳤�����������Jungle��ϰ����Ƿ���ɣ�

                ��ʦ��������ϰ��ᣬ�������֡�

**ͬ��һ������ϰ��ᣩ����ͬ���˶�ȥ�����������ҷ��ʵķ�ʽ��ͬ**��Jungle��Ϊ�������ҵ��Jungle�ְ���Ϊ��ǩ�֣��鳤��Ϊ�˼��Jungle�Ƿ���ɣ�����ʦ��Ϊ�����֡� ÿһ���˶������˷����ߵĽ�ɫ��

ʲô�������ߣ�

## ������ģʽ���

������������ϰ��ᣬ��������Ҳ��Ҫ������������ϰ���Ķ���ṹ����ͬ�Ķ����Ӧ��ͬ�Ĵ������ģʽ�У�**������ģʽ����Ϊ���Բ�ͬ�ķ�ʽ���������ӵĶ���ṹ**��

������ģʽ��һ�ֽ�Ϊ���ӵ���Ϊ�����ģʽ������**������**��**������Ԫ��**������Ҫ�Ľ�ɫ�������ʵ�Ԫ�س����в�ͬ�����ͣ���ͬ�ķ����߿��Զ������ṩ��ͬ�ķ��ʷ�ʽ��������Ԫ��ͨ�����ǵ������ڣ������Լ��ϵ���ʽ������һ������ṹ�У������߿��Ա����ö���ṹ��������������е�ÿһ��Ԫ�ء�

    ������ģʽ��

    ��ʾһ��������ĳ����ṹ�еĸ���Ԫ�صĲ�����������ģʽ���û������ڲ��ı��Ԫ�ص�ǰ���¶�����������ЩԪ�ص��²�����

## ������ģʽ�ṹ

������ģʽ�Ľṹ��Խϸ��ӣ���ɫ�����¼�����

* **Visitor����������ߣ�**�������࣬�����˷��ʶ���ṹ�в�ͬ����Ԫ�صķ������ɷ������ƿ�֪�÷��������ʶ���ṹ�е�ĳ������Ԫ�أ�
* **ConcreteVisitor����������ߣ�**������ĳ������Ԫ�صķ����ߣ�ʵ�־���ķ��ʷ�����
* **Element������Ԫ�أ�**�������࣬һ������һ��accept()�ķ��������ڽ��ܷ����ߵķ��ʣ�accept()����������һ����������ߵ�ָ����Ϊ������
* **ConcreteElement������Ԫ�أ�**����Ծ��屻���ʵ�Ԫ�أ�ʵ��accept()������
* **ObjectStructure������ṹ��**��Ԫ�صļ��ϣ��ṩ�˱�������ṹ������Ԫ�صķ���������ṹ�洢�˲�ͬ���͵�Ԫ�ض����Թ���ͬ�ķ����߷��ʡ�

������ģʽ��UML�ṹͼ���£�

![](https://img-blog.csdnimg.cn/20191110175737470.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

 ����ͼ��ǰ�����Կ�����**������ģʽ����������νṹ**��

* **�����ߵĲ�νṹ**����������ߺ;�������ߣ���ͬ�ľ���������в�ͬ�ķ��ʷ�ʽ��visit()��ʽ����
* **������Ԫ�صĲ�νṹ**������Ԫ�غ;���Ԫ�أ���ͬ�ľ���Ԫ���в�ͬ�ı����ʷ�ʽ��accept()��ʽ��

��ʽ��������������νṹ���������µķ�����ʱ�������޸����еĴ��룬ͨ���̳г�������߼���ʵ����չ�����Ͽ���ԭ��ϵͳ��չ�ԽϺá������������µ�Ԫ��ʱ����Ҫ�޸ĳ���������ࣨ���ӷ�������Ԫ�ط���������������Ҫ�޸ľ�������ߣ������µľ���������ࣩ�������Ͽ���ԭ��

������ģʽ��ʾ���������£�

```C++
#ifndef __DEMO_H__
#define __DEMO_H__
 
// ��������� Visitor
class Visitor
{
public:
	virtual void visit(ConcreteElementA*) = 0;
	virtual void visit(ConcreteElementB*) = 0;
};
 
// ��������� ConcreteVisitor
class ConcreteVisitor :public Visitor
{
public:
	// ʵ��һ������ض�Ԫ�صķ��ʲ���
	void visit(ConcreteElementA*){
		// Ԫ��A�ķ��ʲ�������
	}
	void visit(ConcreteElementB*){
		// Ԫ��B�ķ��ʲ�������
	}
};
 
// ����Ԫ��
class Element
{
public:
	// �������󷽷�����һ����������ߵ�ָ����Ϊ��������
	virtual void accept(Visitor*) = 0;
};
 
// ����Ԫ��
class ConcreteElement :public Element
{
public:
	void accept(Visitor* visitor){
		visitor->visit(this);
	}
};
 
// ����ṹ
class ObjectStructure
{
public:
	//  �ṩ�ӿڽ��ܷ����߷���
	void accept(Visitor* visitor){
		// �������ʶ���ṹ�е�Ԫ��
		for (){
			elementList[i]->accept(visitor);
		}
	}
	void addElement(){}
	void removeElement(){}
private:
	lsit<Element*>elementList;
};
 
#endif
```

## ������ģʽ����ʵ��

    Jungle��Ϊһ���˿ͣ�ȥ���й�����빺�ﳵ����Ʒ��������ƻ���������飬
    ����ʱ����Ա��Ҫ���������Ʒ�ĵļ۸񡣱���Jungle���÷�����ģʽ��ģ��ù��̡�

�����У��ͻ�Jungle������Ա����ȥ������Ʒ�������ĵĵط���ͬ��Jungle���ĵ���ƻ������ĵ��ۡ�Ʒ�Ƶȣ�����Ա��ע������Ʒ�ļ۸���ˣ��ͻ�Customer������ԱCashier�Ǿ�������ߣ���ƻ��Apple����Book�Ǿ��屻����Ԫ�أ������ﳵ���Ƕ���ṹ��������UMLͼ���£�

![](https://img-blog.csdnimg.cn/20191110225041936.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### Ԫ����

#### ����Ԫ��

```C++
// ����Ԫ��
class Element
{
public:
	Element(){};
	virtual void accept(Visitor*) = 0;
	void setPrice(int iPrice){
		this->price = iPrice;
	}
	int getPrice(){
		return this->price;
	}
	void setNum(int iNum){
		this->num = iNum;
	}
	int getNum(){
		return num;
	}
	void setName(string iName){
		this->name = iName;
	}
	string getName(){
		return this->name;
	}
private:
	int price;
	int num;
	string name;
};
```

#### ����Ԫ��Apple

```C++
    // ����Ԫ�أ�Apple
    class Apple :public Element
    {
    public:
    	Apple();
    	Apple(string name, int price);
    	void accept(Visitor*);
    };

    Apple::Apple(){
	setPrice(0);
	setNum(0);
	setName("");
    }
    Apple::Apple(string name, int price){
        setPrice(price);
        setNum(0);
        setName(name);
    }
    
    void Apple::accept(Visitor* visitor){
        visitor->visit(this);
}
```

#### ����Ԫ��Book

```C++
    // ����Ԫ�أ�Book
    class Book :public Element
    {
    public:
    	Book();
    	Book(string name, int price);
    	void accept(Visitor*);
    };

    Book::Book(){
	setPrice(0);
	setNum(0);
	setName("");
    }
    
    Book::Book(string iName, int iPrice){
        setPrice(iPrice);
        setNum(0);
        setName(iName);
    }
    
    void Book::accept(Visitor* visitor){
        visitor->visit(this);
    }
```

### ������

#### ���������

```C++
    // ���������
    class Visitor
    {
    public:
    	Visitor(){};
    	// ����һ����ʷ���
    	virtual void visit(Apple*) = 0;
    	virtual void visit(Book*) = 0;
    };
```

#### ���������Customer

```C++
// ��������ߣ��˿�
class Customer :public Visitor
{
public:
	Customer();
	Customer(string iName);
	void setNum(Apple*, int);
	void setNum(Book*, int);
	void visit(Apple* apple);
	void visit(Book* book);
private:
	string name;
};

Customer::Customer(){
	this->name = "";
}
 
Customer::Customer(string iName){
	this->name = iName;
}
 
void Customer::setNum(Apple* apple, int iNum){
	apple->setNum(iNum);
}
void Customer::setNum(Book* book, int iNum){
	book->setNum(iNum);
}
 
void Customer::visit(Apple* apple){
	int price = apple->getPrice();
	printf("  %s \t����: \t%d Ԫ/kg\n", apple->getName().c_str(), apple->getPrice());
}
 
void Customer::visit(Book* book){
	int price = book->getPrice();
	string name = book->getName();
	printf("  ��%s��\t����: \t%d Ԫ/��\n", book->getName().c_str(), book->getPrice());
}
```

#### ���������Cashier

```C++
class Cashier :public Visitor
{
public:
    Cashier();
    void visit(Apple* apple);
    void visit(Book* book);
};

Cashier::Cashier(){

}
 
void Cashier::visit(Apple* apple){
	string name = apple->getName();
	int price = apple->getPrice();
	int num = apple->getNum();
	int total = price*num;
	printf("  %s �ܼۣ� %d Ԫ\n", name.c_str(), total);
}
 
void Cashier::visit(Book* book){
	int price = book->getPrice();
	string name = book->getName();
	int num = book->getNum();
	int total = price*num;
	printf("  ��%s�� �ܼۣ� %d Ԫ\n", name.c_str(), total);
}
```

### ���ﳵShoppingCart

```C++
class ShoppingCart
{
public:
	ShoppingCart(){}
	void addElement(Element* element){
		printf("  ��Ʒ����%s, \t������%d, \t���빺�ﳵ�ɹ���\n", element->getName().c_str(), element->getNum());
		elementList.push_back(element);
	}
	void accept(Visitor* visitor){
		for (int i = 0; i < elementList.size(); i++){
			elementList[i]->accept(visitor);
		}
	}
private:
	vector<Element*>elementList;
};
```

### �ͻ��˴���ʾ�������

```C++
#include "Element.h"
#include "Visitor.h"
#include "ShoppingCart.h"
#include <Windows.h>
 
int main()
{
	Apple *apple1 = new Apple("�츻ʿƻ��", 7);
	Apple *apple2 = new Apple("��ţƻ��", 5);
	Book *book1 = new Book("��¥��", 129);
	Book *book2 = new Book("�ս���", 49);
 
	Cashier* cashier = new Cashier();
	Customer* jungle = new Customer("Jungle");
	jungle->setNum(apple1, 2);
	jungle->setNum(apple2, 4);
	jungle->setNum(book1, 1);
	jungle->setNum(book2, 3);
 
	ShoppingCart* shoppingCart = new ShoppingCart();
	shoppingCart->addElement(apple1);
	shoppingCart->addElement(apple2);
	shoppingCart->addElement(book1);
	shoppingCart->addElement(book2);
 
	printf("\n\n");
	shoppingCart->accept(jungle);
 
	printf("\n\n");
	shoppingCart->accept(cashier);
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

## �ܽ�

������ģʽ�Ľṹ��Խϸ��ӣ���ʵ��Ӧ����ʹ��Ƶ�ʽϵ͡����ϵͳ�д���һ�����ӵĶ���ṹ���Ҳ�ͬ�ķ����߶�����в�ͬ�Ĳ�������ô���Կ���ʹ�÷�����ģʽ��������ģʽ���ص��ܽ����£�

### �ŵ㣺

* �����µķ����ߺܷ��㣬������һ���µľ���������࣬�����µķ��ʷ�ʽ�������޸�ԭ�д��룬���Ͽ���ԭ��
* ������Ԫ�ؼ�����һ������ṹ�У����ְ������������ڶ���ṹ��Ԫ�ض���ĸ��ã�

### ȱ�㣺

* �����µ�Ԫ��������ѣ������µ�Ԫ��ʱ���ڳ��������������Ҫ����һ����������Ԫ�ط�������������Ҫ�޸ĳ�������ߴ��룻���⻹Ҫ�����µľ����������ʵ�ֶ�����Ԫ�صķ��ʣ������Ͽ���ԭ��
* �ƻ��˶���ķ�װ�ԣ�������ģʽҪ������߶�����ʲ�����ÿһ��Ԫ�ض���Ĳ�������ôԪ�ض�����뱩¶�Լ����ڲ�������״̬������������޷����ʡ�


|[��һƪ](./026_TemplateMethodPattern.md)|[Ŀ¼](./index.md)|[��һƪ]()|
|:---:|:---:|:---:|
|[ģ�巽��ģʽ](./026_TemplateMethodPattern.md)|[Ŀ¼](./index.md)|[]()|