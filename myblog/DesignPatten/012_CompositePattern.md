# ���ģʽ

|[��һƪ](./011_BridgePattern.md)|[Ŀ¼](./index.md)|[��һƪ](./013_DecoratorPattern.md)|
|:---:|:---:|:---:|
|[�Ž�ģʽ](./011_BridgePattern.md)|[Ŀ¼](./index.md)|[װ��ģʽ](./013_DecoratorPattern.md)|

    ����Jungle���Ǳ�ѹե��һ�죺

    ͬ���ð�æ�������ԣ�һ�����һ���磻���ܽ�ȥ���ᣬ���������������ܣ�
    ��Ҳ��Jungle������ѽ����ĥ�˵��ں�ͷ��

    Jungle������Ŀ��Ҫ��Ҫ����ĳ��ITȨ�ޣ���Ҫ�������ܡ�
    �������ܡ��ɶ����ܾ�������������

    �⹫˾Ӵ����ֱ����һ������Jungleֻ��һƬ��Ҷ����Ҷǰ������֦��
    ��֦ǰ�滹����֦��ֱ���������ɡ���Jungle��ʱ���ܳ�Ϊ����֦�أ�

��һĻ�����Ŵ�Ҷ���ͬ���ܰɣ�������˾����֯�ṹ������һ�����νṹ����˾�ֳɼ�������ÿ�����ֳɼ�����Ʒ���ţ�һ����Ʒ�����ֻ�ֳɼ����飬������ܻ�����ϸ�֣��ֵ���󣬾���������Jungle������С���ˡ�

��������**��������ģʽ�ĵ���Ӧ�ó�����**ʲô�����ģʽ�أ�����Jungleһһ������

## ���ģʽ���

���ģʽ��ע����Ҷ�ӽڵ�������ڵ�Ľṹ�Լ����ǹ��ɵ���֯��ʽ����������֯��ʽ���ص����ڣ�Ҷ�ӽڵ㲻�ٰ�����Ա���󣬶������ڵ���԰�����Ա������Щ���������Ҷ�ӽڵ㣬Ҳ�����������ڵ㡣��Щ�ڵ�ͨ����ͬ��**�ݹ����**�γ�һ�����νṹ��**�ñ�Windowsϵͳ��Ŀ¼�ṹ���ļ���������ļ������ļ��У����ļ����ﻹ���԰����ļ����ļ��С�**

![](https://img-blog.csdnimg.cn/20191023230047797.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

���ģʽΪҶ�ӽڵ�������ڵ��ṩ�˹����ĳ��󹹽��࣬�ͻ�����������������Ķ�����Ҷ�ӽڵ㻹�������ڵ㣬ֻ����Գ��󹹽����̴����ɡ�

    ���ģʽ���壺

    ��϶�������γ����νṹ�Ա�ʾ���в���-�����ϵ�Ĳ�νṹ�����ģʽ�ÿͻ��˿���ͳһ�Դ������������϶���

## ���ģʽ�ṹ

���ģʽ�ṹͼ����ͼ��

![](https://img-blog.csdnimg.cn/20191024072101678.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

������Լ����ģʽUMLͼ��֪���ģʽ�����½�ɫ��

* **Component�����󹹼���**��Component��һ�������࣬�����˹�����һЩ�����ӿڣ���Щ�ӿ��ǹ�����߷��������ӹ����ķ�����������ӹ������������ʵ����Ҷ�ӹ��������������н��С�
* **Leaf��Ҷ�ӹ�����**�����������νṹ�е�Ҷ�ӽڵ����Ҷ�ӹ���û���ӽڵ㣬��ʵ�����ڳ��󹹼��ж������Ϊ�����ڳ��󹹼�����Ĺ����ӹ����ķ�����Ҷ�ӹ�������ͨ���׳��쳣����ʾ����ȷ�ʽ���д���
* **Composite������������** ����������һ�������ʵ�ֹ����ӿڣ���һ����ͨ���ۺϹ�ϵ�����ӹ������ӹ�������������������Ҳ������Ҷ�ӹ�����

��Ϲ�˾��֯�ܹ������ӣ������ּ�����������������������Jungle��Ա����Ҷ�ӹ��������WindowsĿ¼�ṹ���ļ������������������԰������ļ��к��ļ������ļ�����Ҷ�ӹ����������ٰ����ӹ�����

### ͸�����ģʽ

��UMLͼ��ʾ�����ģʽ��Ϊ͸�����ģʽ�Ͱ�ȫ���ģʽ����͸�����ģʽ�У����󹹼�Component������add��remove��getChild�����й���ͷ����ӹ����ķ�����������Ҷ�ӹ���������������������ͬ�Ľӿڡ�**�ͻ�����ʹ��ʱ����һ�µضԴ����ж��󣬼�������Ҷ�ӹ������������������Կͻ��˶�����͸���ģ���Ϊ���Ƕ���¶��ͬ�Ľӿڡ�**

���ǣ�Ҷ�ӹ�����û���ӹ����ģ����о�û��add��remove��getChild�����ģ����Ա�����Ҷ�ӹ�����ʵ�����ṩ��Ӧ�Ĵ�������룬�����������

### ��ȫ���ģʽ

�ڰ�ȫ���ģʽ�У����󹹼�Componentû�������κι���ͷ����ӹ����ķ������ھ����ʵ�����в�ȥ������Щ��Ϊ��֮���ԽС���ȫ��������ΪҶ�ӹ���û���ӹ�����Ҳ�Ͳ��ض����������ӹ����ķ������Կͻ��˶��ԣ����������ӹ���ʱ�������ܵ��õ�����͸�����ģʽ�е��ӹ�����add��remove�ȷ��������Ҳ�Ͳ������

**��ȫģʽ�Ĳ������ڲ���͸�����ͻ���ʹ��ʱ����������ĶԴ�Ҷ�ӹ���������������**

## ���ģʽ����ʵ��

����ͼ��ĳ����˾����֯�ṹ��Ϊ�ܲ���ʡ���ֲ����м��ֲ��͸����ֲ��������칫�Һͽ���칫�ң�

![](https://img-blog.csdnimg.cn/20191024212840743.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

����һ�����͵����νṹ������������͸����ģʽ��ʵ�������ṹ��

### ���󹹼�

```C++
//���󹹼�
class Component
{
public:
	Component(){}
	Component(string iName){
		this->name = iName;
	}
	//����һ�����Ż�칫��
	virtual void add(Component*) = 0;
	//����һ�����Ż�칫��
	virtual void remove(Component*) = 0;
	//
	virtual Component* getChild(int) = 0;
	//�����Ų���
	virtual void operation() = 0;
	string getName(){
		return name;
	}
private:
	string name;
};
```

### Ҷ�ӹ���

Ҷ�ӹ��������������칫�Һͽ���칫�ң���������Office��

```C++
//Ҷ�ӹ������칫��
class Office :public Component
{
public:
	Office(string iName){
		this->name = iName;
	}
	Office(){}
	void add(Component* c){
		printf("not support!\n");
	}
	void remove(Component* c){
		printf("not support!\n");
	}
	Component* getChild(int i){
		printf("not support!\n");
		return NULL;
	}
private:
	string name;
};
 
//Ҷ�ӹ����������칫��
class AdminOffice :public Office
{
public:
	AdminOffice(string iName){
		this->name = iName;
	}
	void operation(){
		printf("-----Administration Office:%s\n", name.c_str());
	}
private:
	string name;
};
 
//Ҷ�ӹ���������칫��
class DeanOffice :public Office
{
public:
	DeanOffice(string iName){
		this->name = iName;
	}
	void operation(){
		printf("-----Dean Office:%s\n", name.c_str());
	}
private:
	string name;
};
```

### ��������

```C++
//��������SubComponent
class SubComponent :public Component
{
public:
	SubComponent(string iName){
		this->name = iName;
	}
	void add(Component *c){
		componentList.push_back(c);
	}
	void remove(Component *c){
		for (int i = 0; i < componentList.size(); i++){
			if (componentList[i]->getName() == c->getName()){
				componentList.erase(componentList.begin() + i);
				break;
			}
		}
	}
	Component* getChild(int i){
		return (Component*)componentList[i];
	}
	void operation(){
		printf("%s\n", this->name.c_str());
		for (int i = 0; i < componentList.size(); i++){
			((Component*)componentList[i])->operation();
		}
	}
private:
	string name;
 
	//�����б�
	vector<Component*>componentList;
};
```

### �ͻ��˴���ʾ��

```C++
#include <iostream>
#include "CompositePattern.h"
 
int main()
{
	Component *head, *sichuanBranch, *cdBranch, *myBranch, *office1, *office2, *office3,
		*office4, *office5, *office6, *office7, *office8;
 
	head = new SubComponent("�ܲ�");
	sichuanBranch = new SubComponent("�Ĵ��ֲ�");
	office1 = new AdminOffice("�����칫��");
	office2 = new DeanOffice("����칫��");
	
	cdBranch = new SubComponent("�ɶ��ֲ�");
	myBranch = new SubComponent("�����ֲ�");
	office3 = new AdminOffice("�����칫��");
	office4 = new DeanOffice("����칫��");
	
	office5 = new AdminOffice("�����칫��");
	office6 = new DeanOffice("����칫��");
	
	office7 = new AdminOffice("�����칫��");
	office8 = new DeanOffice("����칫��");
	
	cdBranch->add(office5);
	cdBranch->add(office6);
 
	myBranch->add(office7);
	myBranch->add(office8);
 
	sichuanBranch->add(office3);
	sichuanBranch->add(office4);
	sichuanBranch->add(cdBranch);
	sichuanBranch->add(myBranch);
 
	head->add(office1);
	head->add(office2);
	head->add(sichuanBranch);
	
	head->operation();
 
	system("pause");
	return 0;
}
```

## ���ģʽ�ܽ�

### �ŵ㣺

* ����ض���ֲ�εĸ��Ӷ��󣬱�ʾ�����Ӷ���Ĳ�νṹ���ÿͻ��˺��Բ�εĲ��죻
* �ͻ��˿���һ�µ�ʹ�ò�νṹ�и�����εĶ��󣬶����ع�������幹������Ϊ���ʵ�֣�
* �����ģʽ�������µ�Ҷ�ӹ��������������ǳ����㣬������չ�����Ͽ���ԭ��
* Ϊ���νṹ�İ����ṩ�˽��������

### ȱ�㣺

* �ӹ�����������������Ϊ�����ƣ���Ϊ����������ͬ�ĳ���㡣���Ҫ����ĳ����������ĳ��Ҷ�ӽڵ����еķ�������ôҪ��������ʱ�ж϶������ͣ������˴���ĸ��Ӷȡ�

### ���ó�����

* ϵͳ����Ҫ�õ����νṹ��
* ϵͳ���ܹ�����������ڵ��Ҷ�ӽڵ㣻
* ��������Ͳ��ŵĲ�νṹ�У��ܹ�ͨ��ĳ�ַ�ʽ���Բ�β��죬ʹ�ÿͻ��˿���һ�¶Դ���

|[��һƪ](./011_BridgePattern.md)|[Ŀ¼](./index.md)|[��һƪ](./013_DecoratorPattern.md)|
|:---:|:---:|:---:|
|[�Ž�ģʽ](./011_BridgePattern.md)|[Ŀ¼](./index.md)|[װ��ģʽ](./013_DecoratorPattern.md)|