# �۲���ģʽ

|[��һƪ](./022_MementoPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./024_StatePattern.md)|
|:---:|:---:|:---:|
|[����¼ģʽ](./022_MementoPattern.md)|[Ŀ¼](./index.md)|[״̬ģʽ](./024_StatePattern.md)|

    ÿ��Jungle���ںš�Jungle�ʼǡ����·��������£���ΪJungle�Ĺ�ע�ߣ�
    ����һʱ��ӵ���Ϣ���������Ȼ��Ϳ���ȥ�鿴�����ޡ����ۺ�ת����
    ��������һ���㶼�߸����ˣ�

    ÿ��Jungle������CSDN���ͣ���ΪJungle��֧���ߣ���Ҳ���ڴ�CSDN��վ��ʱ�򿴵�
    ��Ϣ���������Ȼ����Ϳ���ȥ�鿴�����ޡ����ۺ�ת������������һ���㶼�߸����ˡ�

Ҳ����˵����Jungle���·������¡������Ϊ���ܻᵼ�¡���ע�߲鿴�����ۡ����ޡ���һϵ����Ϊ���������Jungle���·������¡������ǹ����ģ��������ڶ��������˹�����**һ��������Ϊ�ĸı䣬��������Ķ��󶼻�õ�֪ͨ�����Զ�������Ӧ����Ϊ������������ģʽ�У����ǹ۲���ģʽ**��

## �۲���ģʽ���

���ϵͳ�еĶ��󲢲��ǹ������ڵģ�һ��������Ϊ�ĸı���ܻ����������������Ķ����״̬����ΪҲ�����ı䣬����ǣһ������ȫ�����۲���ģʽ������һ��һ�Զ��������һ������ı�ʱ���Զ�֪ͨ����������������������Ӧ���۲���ģʽ�У������ı�Ķ����Ϊ���۲�Ŀ�ꡱ����֪ͨ�Ķ����Ϊ���۲��ߡ���һ���۲�Ŀ������кܶ���۲��ߡ�

�۲���ģʽ�������£�

    �۲���ģʽ��

    �������֮���һ��һ�Զ��������ϵ��ʹ��ÿ��һ������״̬�����ı�ʱ��
    ������������󶼵õ�֪ͨ�����Զ����¡�

�۲���ģʽ�ֱ���Ϊ����-����ģʽ��Publish-Subscribe����ģ��-��ͼģʽ��Model-View����Դ-������ģʽ��Source-Listener����������ģʽ��Dependents���� 

## �۲���ģʽ�ṹ

�۲���ģʽ�ɹ۲��ߺ͹۲�Ŀ����ɣ�Ϊ������չ��������ɫ������˳���㡣�۲���ģʽ��UMLͼ���£�

![](https://img-blog.csdnimg.cn/20191106074204410.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

* **Subject��Ŀ�꣩**���Ǳ��۲�Ķ���Ŀ���ж�����һ���۲��ߵļ��ϣ���һ��Ŀ����ܻ��ж���۲��ߣ�ͨ��attach()��detach()��������ɾ�۲��߶���Ŀ��������֪ͨ����notify()������������״̬�����ı�ʱ֪ͨ�۲��ߡ�
* **ConcreteSubject������Ŀ�꣩**������Ŀ��ʵ����֪ͨ����notify()��ͬʱ����Ŀ���м�¼����״̬�����Ժͳ�Ա������
* **Observer���۲��ߣ�**���۲��߽��Խ��յ���Ŀ�귢���ı��֪ͨ��������ķ�Ӧ������������˸��·���update()��
* **ConcreteObserver������۲��ߣ�**�� ʵ���˸��·���update()������۲�����ά����һ������Ŀ���������ã�ָ�룩�����ڴ洢Ŀ���״̬��

�����ǹ۲���ģʽ�ĵ���ʵ�֣�

```C++
#ifndef __DEMO_H__
#define __DEMO_H__
 
// ����۲���
class Observer
{
public:
	// ������Ӧ���·���
	virtual void update() = 0;
};
 
// ����۲���
class ConcreteObserver:public Observer
{
public:
	// ʵ����Ӧ���·���
	void update(){
		// �������
	}
};
 
// ����Ŀ��
class Subject
{
public:
	// ��ӹ۲���
	void attach(Observer* obs){
		obsList.push_back(obs);
	}
	// �Ƴ��۲���
	void detach(Observer* obs){
		obsList.remove(obs);
	}
	// ����֪ͨ����
	virtual void notify() = 0;
protected:
	// �۲����б�
	list<Observer*>obsList;
};
 
// ����Ŀ��
class ConcreteSubject :public Subject
{
public:
	// ʵ��֪ͨ����
	void notify(){
		// �������
		// ����֪ͨ�۲��߶���
		for (int i = 0; i < obsList.size(); i++){
			obsList[i]->update();
		}
	}
};
 
// �ͻ��˴���ʾ��
int main()
{
	Subject  *sub = new ConcreteSubject();
	Observer *obs = new ConcreteObserver();
	sub->attach(obs);
	sub->notify();
	return 0;
}
#endif //__DEMO_H__
```

## �۲���ģʽ����ʵ��

    �����ƽ��Ӣ�����Ϸ��������Ӿ�����������һ�����ѷ�������ʱ��
    ���Է���Ϣ�������������ʡ������������������������ȥȡ���ʣ�
    ��һ����������Σ��ʱ��Ҳ���Է���Ϣ���Ⱦ��ҡ��������������ѵõ�
    ��Ϣ��������ȥӪ�ȡ�����Jungle���ù۲���ģʽ��ģ��������̡�

������UMLͼ���£�

![](https://img-blog.csdnimg.cn/20191106210750554.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

�����У�����۲�����Observer�������˷������ʻ�����Ҫ���ʱ�ĺ��еķ���call()������۲�����Player������ң�Playerʵ���˺���call()���������һ�������ȡ����come()��֧Ԯ����help()�ķ���������������AllyCenter��Ϊ����Ŀ�꣬��ά����һ������б�playerList�����Ҷ����˼���ս�Ӻ��޳���ҵķ���������Ŀ�����������Ŀ�����AllyCenterController����ʵ����֪ͨnotify()�������÷���������call����Ϣ���������б����������ѣ���������Ӧ����Ӧ��Դ�����https://github.com/FengJungle/DesignPattern��

### ����ͷ�ļ�

ͨ��һ��ö������������������Ϣ���ͣ����������ʺ�����

```C++
    #ifndef __COMMON_H__
    #define __COMMON_H__
     
    enum INFO_TYPE{
    	NONE,
    	RESOURCE,
    	HELP
    };
     
    #endif //__COMMON_H__
```

### �۲���

#### ����۲���Observer

```C++
// ����۲��� Observer
class Observer
{
public:
	Observer(){}
	// �������󷽷�
	virtual void call(INFO_TYPE infoType, AllyCenter* ac) = 0;
	string getName(){
		return name;
	}
	void setName(string iName){
		this->name = iName;
	}
private:
	string name;
};
```

#### ����۲���Player

```C++
// ����۲��� 
class Player :public Observer
{
public:
	Player(){
		setName("none");
	}
	Player(string iName){
		setName(iName);
	}
	// ʵ��
	void call(INFO_TYPE infoType, AllyCenter* ac){
		switch (infoType){
		case RESOURCE:
			printf("%s :������������\n", getName().c_str());
			break;
		case HELP:
			printf("%s :�Ⱦ���\n", getName().c_str());
			break;
		default:
			printf("Nothing\n");
		}
		ac->notify(infoType, getName());
	}
	// ʵ�־��巽��
	void help(){
		printf("%s:���ס���������㣡\n", getName().c_str());
	}
	void come(){
		printf("%s:�õģ�����ȡ����\n", getName().c_str());
	}
};
```

### Ŀ���� 

#### ����Ŀ��AllyCenter

```C++
// ����Ŀ�꣺��������
class AllyCenter
{
public:
	AllyCenter();
	// ����֪ͨ����
	virtual void notify(INFO_TYPE infoType, std::string name) = 0;
	// �������
	void join(Observer* player);
	// �Ƴ����
	void remove(Observer* player);
protected:
	// ����б�
	std::vector<Observer*>playerList;
};
```

```C++
#include "AllyCenter.h"
#include "Observer.h"
 
AllyCenter::AllyCenter(){
	printf("�󼪴���������Լ�!\n");
}
 
// �������
void AllyCenter::join(Observer* player){
	if (playerList.size() == 4){
		printf("�������\n");
		return;
	}
	printf("��� %s ����\n", player->getName().c_str());
	playerList.push_back(player);
	if (playerList.size() == 4){
		printf("��ӳɹ�����Ҫ�ˣ�һ���ϣ�\n");
	}
}
// �Ƴ����
void AllyCenter::remove(Observer* player){
	printf("��� %s �˳�\n", player->getName().c_str());
	//playerList.remove(player);
}
```

#### ����Ŀ��AllyCenterController

```C++
// ����Ŀ��
class AllyCenterController :public AllyCenter
{
public:
	AllyCenterController();
	// ʵ��֪ͨ����
	void notify(INFO_TYPE infoType, std::string name);
};

AllyCenterController::AllyCenterController(){}
 
// ʵ��֪ͨ����
void AllyCenterController::notify(INFO_TYPE infoType, std::string name){
	switch (infoType){
	case RESOURCE:
		for each (Observer* obs in playerList){
			if (obs->getName() != name){
				((Player*)obs)->come();
			}
		}
		break;
	case HELP:
		for each (Observer* obs in playerList){
			if (obs->getName() != name){
				((Player*)obs)->help();
			}
		}
		break;
	default:
		printf("Nothing\n");
	}
}
```

### �ͻ��˴���ʾ����Ч��

```C++
#include "Observer.h"
#include "AllyCenter.h"
 
int main()
{
	// ����һ��ս��
	AllyCenterController* controller = new AllyCenterController();
 
	// ����4����ң�������ս��
	Player* Jungle = new Player("Jungle");
	Player* Single = new Player("Single");
	Player* Jianmengtu = new Player("������");
	Player* SillyDog = new Player("ɵ�ӹ�");
	controller->join(Jungle);
	controller->join(Single);
	controller->join(Jianmengtu);
	controller->join(SillyDog);
 
	printf("\n\n");
 
	// Jungle�������ʣ����ж���
	Jungle->call(RESOURCE, controller);
 
	printf("\n\n");
 
	// ɵ�ӹ�����Σ�գ���ȶ���
	SillyDog->call(HELP, controller);
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

## �۲���ģʽ��Ӧ��

�۲���ģʽ��һ��ʹ��Ƶ�ʷǳ��ߵ����ģʽ�������޴����ڡ������漰һ��һ��һ�Զ�Ķ��󽻻�������������ʹ�ù۲��߻�ģʽ�����繺�ﳵ�������Ʒʱ�������ﳵ�����һ����Ʒ��������UI�෽��ı仯�����ﳵ����Ʒ��������Ӧ���̵���ʾ���۸����ʾ�ȣ������ֱ�����Ե�GUI�¼������ʵ�֣����е�������¼���mouseover��keypress�ȣ�����ʹ�ù۲���ģʽ�����ӡ�

## �ܽ�

### �ŵ㣺

* �۲���ģʽʵ�����ȶ�����Ϣ���ºʹ��ݵĻ��ƣ�ͨ���������������չ��ͬ�ľ���۲��߽�ɫ��
* ֧�ֹ㲥ͨ�ţ�������ע��Ĺ۲��ߣ���ӵ�Ŀ���б��еĶ��󣩶���õ���Ϣ���µ�֪ͨ������һ�Զ���Ƶ��Ѷȣ�
* ���Ͽ���ԭ�������µĹ۲��������޸����д��룬�ھ���۲�����۲�Ŀ��֮�䲻���ڹ�����ϵ������������µĹ۲�Ŀ��Ҳ�ܷ��㡣

### ȱ�㣺

* �����й۲��ߺ͹۲�Ŀ���໥���ã�����ѭ���������۲�Ŀ��ᴥ������ѭ�����ã�������ϵͳ�����ķ��գ�
* ���һ���۲�Ŀ������кܶ�ֱ�Ӻͼ��۲��ߣ������еĹ۲��߶�֪ͨ����ķѴ���ʱ�䡣

### ���û�����

* һ������ĸı��������������������ı䣬������֪������Щ���������ı��Լ�����ʲô���ĸı䣻
* �����Ҫ���һ����ʽ������ϵͳ������ʹ�ù۲���ģʽ��
* �㲥ͨ�š���Ϣ����֪ͨ�ȳ�����

|[��һƪ](./022_MementoPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./024_StatePattern.md)|
|:---:|:---:|:---:|
|[����¼ģʽ](./022_MementoPattern.md)|[Ŀ¼](./index.md)|[״̬ģʽ](./024_StatePattern.md)|