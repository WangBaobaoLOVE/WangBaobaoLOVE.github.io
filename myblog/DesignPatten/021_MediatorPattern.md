# �н���ģʽ

|[��һƪ](./020_IteratorPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./022_MementoPattern.md)|
|:---:|:---:|:---:|
|[������ģʽ](./020_IteratorPattern.md)|[Ŀ¼](./index.md)|[����¼ģʽ](./022_MementoPattern.md)|

    �뿪ѧУ�μӹ���֮ǰ����һ������һ��ʱ���������⣬JungleҲ����ˡ�

    JungleΪ���ҵ����ʵķ��ӣ����ŵ�����һ��С��һ��С����ȥ�������ʱ�����
    ��������С���ſ�չ���ϵķ�������ϵ��ʽȥ�ҷ������������Ѿ���ȥ������ˣ�
    ��Jungle�����������Ǿ��ú��鷳���鷳�������������������ϵ����������
    ͨ��¼��΢�ŵüӺö෿������

    ��ʵ�и�ʡ�µİ취���Ǿ������н飬�ⷿ�н��Ķ����ǡ���Ȼ����Ҫԭ�򣩣�
    ���ǵ�ȷΪ���ʡ�˺ܶ��£���ʵҲΪ����ʡ�˺ܶ��¡�

![](https://img-blog.csdnimg.cn/20191103193458934.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

## �н���ģʽ���

����Jungle�ⷿ����������ͼ�����Jungle�Լ�ȥ�ⷿ���ú͸����������Խ����������һ����ͼ�����Ҳ���Լ��ҷ���ͬ��Ҳ�úͺܶ෿���򽻵�������Ҳ��һ�����ú��ڶ಻ͬ�������ϵ��**������н����ˣ�������ֻ��Ҫȥ�н�������ע��һ�£��Լ��ķ������Ķ���ʲô������ʩ���۸���٣���ok�ˣ�Jungle�ͼ�����Ҳֻ��Ҫ��һ���˴򽻵����Ǿ����н顣�н�ĳ���ʹ���߶�ʡȥ�˲����¡�**

������ģʽ�У�Ҳ��һ�����ƵĽ���������Ǿ����н���ģʽ.

    �н���ģʽ��

    ����һ����������װһϵ�ж���Ľ������н���ģʽʹ��������֮�䲻��Ҫ��ʾ���໥���ã��Ӷ�ʹ�������ɢ�������û����Զ����ظı�����֮��Ľ�����

���һ��ϵͳ���������֮����ڶ�Զ���໥��ϵ�����Խ�����֮���һЩ������Ϊ�Ӹ��������з�����������з�װ��һ���н��߶����У�ʹ�������ɢ�������н���ͳһЭ����ͨ���н��ߣ�����֮��Ķ�Զ��ϵ�ͼ�����Ը��򵥵�һ�Զ��ϵ�� 

## �н���ģʽ�ṹ

�н���ģʽ��UMLͼ���£�Ϊ�˱�����չ��ϵͳ�����˳����н��ߡ�

![](https://img-blog.csdnimg.cn/20191103194143491.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

��ͼ��֪���н���ģʽ��Ҫ�����½�ɫ��

* **Mediator�������н��ߣ�**������һ�����������ͬ�¶���֮�佻���Ľӿڣ�ͨ������һ��ע�᷽������������ͬ�¶���
* **ConcreteMediator�������н��ߣ�**��ʵ������Ľӿڣ�Э������ͬ�¶�����ʵ��Э����Ϊ��ά�ֶԸ���ͬ�¶�������ã�
* **Colleague������ͬ���ࣩ**����������ͬ���๫�еĽӿڣ�**ͬʱά����һ���Գ����н����������**��
* **ConcreteColleague������ͬ���ࣩ**�� ����ʵ�ֽӿڣ�����ͬ����ֻ�����н���ͨ�ţ�ͨ���н������������ͬ�����ͨ�š�

**�н���ģʽ�ĺ��������������н�����**���н�����е���������ε�ְ��

* **�ṹ������ת����**��ͨ���н��ߵ���ת������ͬ��֮�䲻�����໥��ʾ���û����ã�ֻ��ͨ���н���ʵ�ּ�ӵ��õ�Ŀ�ģ�
* **��Ϊ����Э������**���н��߿��Խ�һ���ؽ�ͬ��֮��Ĺ�ϵ���з�װ��ͬ�¿���һ�µغ��н��߽��н�����������ָ���н��߾������β������н��߸��ݷ�װ�������ڲ���Э���߼���ͬ�µ������һ��������ͬ�³�Ա֮��Ĺ�ϵ��Ϊ���з���ͷ�װ��

## �н���ģʽ����ʵ��

����Jungle�������н���ģʽģ�⡰��͡��������н顪��������֮��İ������

�������Ĵ�����Խϸ��ӣ����������Դ���https://github.com/FengJungle/DesignPattern��

    Jungle�ͼ�������Ҫͨ�������н飨Agency���ⷿ����Ҫȥ�н鴦�˽ⷿ����Landlord��
    ����Ϣ���������۸񣬵�ַ����ϵ��ʽ���������ǣ�Landlord����Ҫ���н鴦
    ע���Լ��ķ�Դ��ͬʱҲ���Դ��н鴦�˽���ͣ�Tenant������Ϣ����������

������UMLͼ���£� 

![](https://img-blog.csdnimg.cn/20191104073214663.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### ����ͷ�ļ�

Ϊ���ַ�������ͣ�Jungle������һ��ö�����ͺͶ�Ӧ��setter��getter������

```C++
#ifndef __COMMON_H__
#define __COMMON_H__
 
// ����ͷ�ļ�
 
#include <vector>
using namespace std;
 
enum PERSON_TYPE
{
	NONE_PERSON,
	LANDLORD,
	TENANT
};
 
#endif  //__COMMON_H__
```

### �н���

#### �����н���

```C++
// �����н���
class Mediator
{
public:
	Mediator(){}
	// �������󷽷�
	virtual void operation(Colleague*) = 0;
	// ����ע�᷽��
	virtual void registerMethod(Colleague*) = 0;
};
```

#### �����н���Agency 

�����н��߾�����ʵ���н�����࣬�������з�����������landlordList�������������tenantList�������������ͨ��registerMethod()���н鴦�Ǽ�ע�ᡣͬʱ����������ѯ���н������Ϣ�����Ҳ�������н�ѯ�ʷ�����Ϣ��

```C++
// �����н���
class Agency:public Mediator
{
public:
	Agency(){}
	void registerMethod(Colleague* person){
		switch (person->getPersonType()){
		case LANDLORD:
			landlordList.push_back((Landlord*)person);
			break;
		case TENANT:
			tenantList.push_back((Tenant*)person);
			break;
		default:
			printf("wrong person\n");
		}
	}
	void operation(Colleague* person){
		switch (person->getPersonType()){
		case LANDLORD:
			for (int i = 0; i < tenantList.size(); i++){
				tenantList[i]->answer();
			}
			break;
		case TENANT:
			for (int i = 0; i < landlordList.size(); i++){
				landlordList[i]->answer();
			}
			break;
		default:
			break;
		}
	}
private:
	vector<Landlord*>landlordList;
	vector<Tenant*>tenantList;
};
```

### ͬ����

#### ����ͬ����

```C++
// ǰ������
class Mediator;
class Agency;
 
// ����ͬ����
class Colleague
{
public:
	Colleague(){}
	void setMediator(Mediator* iMediator){
		this->mediator = iMediator;
	}
	Mediator* getMediator(){
		return this->mediator;
	}
	void setPersonType(PERSON_TYPE iPersonType){
		this->personType = iPersonType;
	}
	PERSON_TYPE getPersonType(){
		return this->personType;
	}
	virtual void ask() = 0;
	virtual void answer() = 0;
private:
	PERSON_TYPE personType;
	Mediator* mediator;
};
```

#### ����ͬ���ࡪ��������Landlord��

```C++
// ����ͬ���ࣺ����
class Landlord :public Colleague
{
public:
	Landlord();
	Landlord(string iName, int iPrice, string iAddress, string iPhoneNum);
	void ask();
	void answer();
private:
	string name;
	int price;
	string address;
	string phoneNumber;
};
```

ʵ�֣�

```C++
#include "Colleague.h"
#include "Mediator.h"
 
Landlord::Landlord(){
	name = "none";
	price = 0;
	address = "none";
	phoneNumber = "none";
	setPersonType(NONE_PERSON);
}
 
Landlord::Landlord(string iName, int iPrice, 
	string iAddress, string iPhoneNum){
	name = iName;
	price = iPrice;
	address = iAddress;
	phoneNumber = iPhoneNum;
	setPersonType(LANDLORD);
}
 
void Landlord::answer(){
	printf("����������%s, ���⣺%d, ��ַ��%s, ��ϵ�绰��%s\n",
		name.c_str(), price, address.c_str(), phoneNumber.c_str());
}
 
void Landlord::ask(){
	printf("����%s�鿴�����Ϣ��\n",name.c_str());
	(this->getMediator())->operation(this);
}
```

#### ����ͬ���ࡪ����ͣ�Tenant�� 

������

```C++
    // ����ͬ���ࣺ���
    class Tenant :public Colleague
    {
    public:
    	Tenant();
    	Tenant(string name);
    	void ask();
    	void answer();
    private:
    	string name;
    };
```

ʵ�֣�

```C++
#include "Colleague.h"
#include "Mediator.h"
 
Tenant::Tenant(){
	name = "none";
	setPersonType(NONE_PERSON);
}
 
Tenant::Tenant(string iName){
	name = iName;
	setPersonType(TENANT);
}
 
void Tenant::ask(){
	printf("���%sѯ�ʷ�����Ϣ\n", name.c_str()); 
	(this->getMediator())->operation(this);
}
 
void Tenant::answer(){
	printf("���������%s\n", name.c_str());
}
```

### �ͻ��˴���ʾ����Ч��

```C++
#include <iostream>
#include "Mediator.h"
#include "Colleague.h"
 
int main()
{
	// �����ⷿ�н�
	Agency *mediator = new Agency();
 
	// ����3λ����
	Landlord *fangdong1 = new Landlord("����", 1350, "�ɶ���˫����", "1351025");
	Landlord *fangdong2 = new Landlord("����", 1500, "�ɶ��������", "1378390");
	Landlord *fangdong3 = new Landlord("�ŷ�", 1000, "�ɶ�����Ȫ��", "1881166");
	fangdong1->setMediator(mediator);
	fangdong2->setMediator(mediator);
	fangdong3->setMediator(mediator);
	// �������н鴦�Ǽ�ע�᷿Դ��Ϣ
	mediator->registerMethod(fangdong1);
	mediator->registerMethod(fangdong2);
	mediator->registerMethod(fangdong3);
 
	// ������λ���Jungle�ͼ�����
	Tenant *jungle = new Tenant("Jungle");
	Tenant *jianmengtu = new Tenant("������");
	jungle->setMediator(mediator);
	jianmengtu->setMediator(mediator);
	// Jungle�ͼ��������н鴦�Ǽ�������Ϣ
	mediator->registerMethod(jungle);
	mediator->registerMethod(jianmengtu);
 
	jungle->ask();
	printf("\n\n");
	fangdong1->ask();
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

## �ܽ�

### �ŵ㣺

* ���˶���֮��Ľ�����ͨ���н��ߣ�����֮��Ķ�Զ��ϵ�ͼ�����Ը��򵥵�һ�Զ��ϵ��
* �ɽ�����ͬ�¶��������ڸ���ͬ��֮�����ɢ��ϣ��ɶ����ظı�͸���ÿһ��ͬ�¶��������µ��н��ߺ�ͬ�¶��ȽϷ��㣬���Ͽ���ԭ��
* �ɼ����������ɣ���ԭ���ֲ��ڶ������֮�����Ϊ��װ��һ��ֻ�������µľ����н�����Ϳ��Ըı���Щ��Ϊ�� 

### ȱ�㣺

* �����н������а����˴�����ͬ��֮�佻����ϸ�ں��߼�������ʹ���н�����ܸ������������Թ���ά����

### ���û�����

* ϵͳ�еĶ���֮����ڸ��ӵĽ�����ϵ��ʹ��ϵͳ���߼����۸��ӣ����Թ���
* һ�����������������ܶ���󣬲�ֱ�Ӻ���Щ���󽻻������¸ö������Ը��á�

|[��һƪ](./020_IteratorPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./022_MementoPattern.md)|
|:---:|:---:|:---:|
|[������ģʽ](./020_IteratorPattern.md)|[Ŀ¼](./index.md)|[����¼ģʽ](./022_MementoPattern.md)|