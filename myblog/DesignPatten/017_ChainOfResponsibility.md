# ְ����ģʽ

|[��һƪ](./016_ProxyPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./018_CommandPattern.md)|
|:---:|:---:|:---:|
|[����ģʽ](./016_ProxyPattern.md)|[Ŀ¼](./index.md)|[����ģʽ](./018_CommandPattern.md)|

    Ӧ��Ŀ���󣬹�˾����Jungleȥ�ɶ�����һ��ʱ�䡣�ⲻ��Jungle�ս����������
    �ص���˾׼������������һ�£�Jungleһ���д��50���һ��С��Ʊ����Ҫ������
    ���չ�˾�涨��Jungle����ȥ���Լ����鳤ǩ�֡�

    �鳤һ����������������ֻ�ܴ���10�������µı��������ⵥ����ǩ���֣�
    �㻹���ұ��磨���ܣ�ǩ�֡�������Jungle����ȥ�ұ��硣

    ���翴�ˣ����������������ֻ�ܹܽ�����30��ĵ��ӣ�
    ����Ҵ��ܣ�����ǩ�֡���Jungle�ֲ����䷳���ҵ��˴��ܡ�

    ����һ�������ǣ�50�򣬲��ٰ�����60�������Ҷ����������ⵥ���Ҹ���ǩ�ˣ�
    Ҫ�ǳ���60�����⹷�ӻ���ȥ���ϰ壡��Jungle��������һ������
    һ��һ���������쵼��Ҳ�ǲ�����ѽ��

![](https://img-blog.csdnimg.cn/20191028235056481.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

�ڵ�λ��ÿ���쵼���в�ͬ������Ȩ�ޣ���ͬ��ȵı���������ϱ������յ���Ȩ����ý�Χ���쵼����õ��Ӳ���������ɡ�����Jungle���ڵĹ�˾������Ҳ�Ǵ󲿷ֹ�˾�����ƶȡ����Ҫ�ô�����ģ�������ƶȣ���û��һ��ģʽ���Բο��أ�

���ǣ��У��Ǿ���ְ����ģʽ��

## ְ����ģʽ���

**ְ����ģʽ�ֽ�������ģʽ**���ܶ�����£����Դ���ĳ������Ķ�����ܲ�ֹһ���������������ĳһ������֮���γɵĹ�ϵһ��һ�����¼Ҵ��ݵ��ϼң��γ�һ��������ְ������ְ����������ֱ�ߣ�Ҳ�����ǻ������νṹ��������ְ������ʽ��ֱ�ߡ�**���ϵ�ÿһ������������Ĵ����ߣ��ͻ���Ҫ���Ľ����Ƿ������󣬲���Ҫ��������Ĵ���ϸ�ڹ��̡��ɴˣ�ְ����ģʽ�������ߺ�����Ľ����߽��**

ְ����ģʽ�������£�

    ְ����ģʽ��

    ���⽫һ������ķ����ߺͽ����������һ���ö�������л��ᴦ�����󡣽���������Ķ������ӳ�һ����������������������������ֱ����һ�������ܹ�������Ϊֹ��

## ְ����ģʽ�ṹ

ְ����ģʽ��UML�ṹ����ͼ��ʾ��ְ����ģʽ�ĺ�������������һ���������ߣ�

![](https://img-blog.csdnimg.cn/20191028225550991.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

ְ����ģʽ��һ������������ɫ:

* **Handler���������ߣ�**����������һ��Ϊ�����࣬������һ����������Ľӿ�handleRequest()��������һ�������������͵Ķ�����Ϊ����¼ҵ����ã�ͨ�������ÿ����γ�һ����������
* **ConcreteHandler�����崦���ߣ�**�� �ǳ������ߵ����࣬ʵ���˴�������Ľӿڡ��ھ����ʵ���У�����þ��崦�����ܹ���������󣬾ʹ����������򽫸�����ת��������ߡ����崦���߿��Է�����һ������

��������֪����ְ����ģʽ�кܶ������ÿһ����������¼ҵ��������������γ�һ������������������������𼶴��ݣ�֪��ĳһ���ܹ������������Ϊֹ��**�ͻ��˲�֪��Ҳ����֪������һ�������ߴ����˸�������Ϊÿ�������߶�����ͬ�Ľӿ�handleRequest()**��������ͨ��һ��ʵ������һ����ʶְ����ģʽ��

## ְ����ģʽ����ʵ��

�������е�����Ϊ�������ڲ�ͬ����Ʊ�ݣ���˾��ͬ������쵼����������£�

    ���0~10���鳤�ɴ���

    ���10~30�����ܴ���

    ���30~60�򣺾�����

    ����60���ϰ崦��

����Jungle����C++ģ��ù��̡���ʵ��UMLͼ���£�

![](https://img-blog.csdnimg.cn/20191029221017526.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### Ʊ����

```C++
// ����Ʊ��
class Bill
{
public:
	Bill(){}
	Bill(int iId, string iName, double iAccount){
		id = iId;
		name = iName;
		account = iAccount;
	}
	double getAccount(){
		return this->account;
	}
	void print(){
		printf("\nID:\t%d\n", id);
		printf("Name:\t%s\n", name.c_str());
		printf("Account:\t%f\n", account);
	}
private:
	int id;
	string name;
	double account;
};
```

### ��������

```C++
// ��������
class Approver
{
public:
	Approver(){}
	Approver(string iName){
		setName(iName);
	}
	// ����ϼ�
	void setSuperior(Approver *iSuperior){
		this->superior = iSuperior;
	}
	// ��������
	virtual void handleRequest(Bill*) = 0;
	string getName(){
		return name;
	}
	void setName(string iName){
		name = iName;
	}
protected:
	Approver *superior;
private:
	string name;
};
```

### ���崦����

#### ���崦���ߣ��鳤

```C++
// ���崦���ߣ��鳤
class GroupLeader :public Approver
{
public:
	GroupLeader(){}
	GroupLeader(string iName){
		setName(iName);
	}
	// ��������
	void handleRequest(Bill *bill){
		if (bill->getAccount() < 10){
			printf("�鳤 %s �����˸�Ʊ�ݣ�Ʊ����Ϣ��",this->getName().c_str());
			bill->print();
		}
		else{
			printf("�鳤��Ȩ����ת���ϼ�����\n");
			this->superior->handleRequest(bill);
		}
	}
};
```

#### ���崦���ߣ�����

```C++
// ���崦���ߣ�����
class Head :public Approver
{
public:
	Head(){}
	Head(string iName){
		setName(iName);
	}
	// ��������
	void handleRequest(Bill *bill){
		if (bill->getAccount() >= 10 && bill->getAccount()<30){
			printf("���� %s �����˸�Ʊ�ݣ�Ʊ����Ϣ��", this->getName().c_str());
			bill->print();
		}
		else{
			printf("������Ȩ����ת���ϼ�����\n");
			this->superior->handleRequest(bill);
		}
	}
};
```

#### ���崦���ߣ�����

```C++
// ���崦���ߣ�����
class Manager :public Approver
{
public:
	Manager(){}
	Manager(string iName){
		setName(iName);
	}
	// ��������
	void handleRequest(Bill *bill){
		if (bill->getAccount() >= 30 && bill->getAccount()<60){
			printf("���� %s �����˸�Ʊ�ݣ�Ʊ����Ϣ��", this->getName().c_str());
			bill->print();
		}
		else{
			printf("������Ȩ����ת���ϼ�����\n");
			this->superior->handleRequest(bill);
		}
	}
};
```

#### ���崦���ߣ��ϰ�

```C++
// ���崦���ߣ��ϰ�
class Boss :public Approver
{
public:
	Boss(){}
	Boss(string iName){
		setName(iName);
	}
	// ��������
	void handleRequest(Bill *bill){
		printf("�ϰ� %s �����˸�Ʊ�ݣ�Ʊ����Ϣ��", this->getName().c_str());
		bill->print();
	}
};
```

### �ͻ��˴���ʾ��

�ͻ��˴������ĸ���ɫ���ֱ����鳤�����ܡ�������ϰ壬�����������¼���ϵ��Ȼ�󴴽���4��Ʊ�ݣ����ȣ�����ͳһ�����鳤����

```C++
#include <iostream>
#include "ChainOfResponsibility.h"
 
int main()
{
	// �������ߣ��鳤�����磬���ܣ��ϰ�
	Approver *zuzhang, *bingge, *chunzong, *laoban;
 
	zuzhang = new GroupLeader("����");
	bingge = new Head("����");
	chunzong = new Manager("����");
	laoban = new Boss("���ϰ�");
 
	zuzhang->setSuperior(bingge);
	bingge->setSuperior(chunzong);
	chunzong->setSuperior(laoban);
 
	// ����������
	Bill *bill1 = new Bill(1, "Jungle", 8); 
	Bill *bill2 = new Bill(2, "Lucy", 14.4);
	Bill *bill3 = new Bill(3, "Jack", 32.9);
	Bill *bill4 = new Bill(4, "Tom", 89);
 
	// ȫ���Ƚ����鳤����
	zuzhang->handleRequest(bill1); printf("\n");
	zuzhang->handleRequest(bill2); printf("\n");
	zuzhang->handleRequest(bill3); printf("\n");
	zuzhang->handleRequest(bill4);
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

## �ܽ�

### �ŵ㣺

* ������Ľ����ߺʹ����߽���ͻ�������֪�����崦���ߣ�ֻ��Գ������߱�̣����˿ͻ��˱�̹��̣�����ϵͳ��϶ȣ�
* ��ϵͳ������һ���µĴ�����ʱ��ֻ��Ҫ�̳г������ߣ�����ʵ��handleRequest()�ӿڣ�����Ķ�ԭ�д��룬���Ͽ���ԭ��
* ���������ְ��ʱ��ְ����ģʽ����ϵͳ��������ԡ�

### ȱ�㣺

* ����û��һ����ȷ�Ľ����ߣ��п������������޷���Ӧ�����⣻
* �Ƚϳ���ְ�������䴦����̻�ܳ���
* ����ְ�����Ĺ������ڿͻ��˽��У�����������������ܵ���ѭ�����û��ߵ���ʧ�ܡ�

### ���û�����

  * �ж��������ͬһ�����󣬾�����˭��������������ʱ�������ͻ���ֻ�跢������ְ�����ϣ���������ľ�����˭������
  * �ɶ�ָ̬��һ����������󣬿ͻ��˿��Զ�̬����ְ�������������󣬻����Ըı�ְ�����и���������֮������¼���ϵ��

|[��һƪ](./016_ProxyPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./018_CommandPattern.md)|
|:---:|:---:|:---:|
|[����ģʽ](./016_ProxyPattern.md)|[Ŀ¼](./index.md)|[����ģʽ](./018_CommandPattern.md)|