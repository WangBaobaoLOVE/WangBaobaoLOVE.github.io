# ��Ԫģʽ

|[��һƪ](./014_FacadePattern.md)|[Ŀ¼](./index.md)|[��һƪ](./016_ProxyPattern.md)|
|:---:|:---:|:---:|
|[���ģʽ](./014_FacadePattern.md)|[Ŀ¼](./index.md)|[����ģʽ](./016_ProxyPattern.md)|

    ֪��Χ���𣿲�����Χ�����ܼ����ɣ����ķ����������ϣ�
    ��ɫ���Ӻͺ�ɫ���ӷֲ������̵ĸ���λ���ϡ�

    ����������֮���������ʲô��������ɫ��λ�ã�����ûʲô��ͬ�˰ɣ�
    Ҳ����˵��ÿ�����Ӷ���Ĵ󲿷�״̬����һ���ģ���״�����ϡ��ʵصȣ���
    �������Ҫ���һ��������ʵ����Χ��Ĺ��ܣ�
    ��������������߱�ʾ���ϰٸ����Ӷ����أ�

���Ƶģ���������һ��Ӣ�Ķ��䣬����ÿ�������ٳ��ٸ��ӣ�Ҳ�޷Ƕ�����26����ĸ�еļ�����ɵġ���������ʾ���Ĺ�ͬ�����ڣ�**���������д��ڴ�����ͬ�������Ƶġ���Ҫ�ظ�ʹ�õĶ���**��������ĳ�������������������һ��ֵ�ý�������ģʽ�ǲ���Ľ������������Ԫģʽ��

## ��Ԫģʽ���

���һ��ϵͳ������ʱ����̫����ͬ�������ƵĶ��󣬻�ռ�ô����ڴ����Դ������ϵͳ���ܡ�**��Ԫģʽͨ��������ʵ����ͬ�����Ƶ�ϸ���ȶ���ĸ��ã��ṩһ����Ԫ�ش洢�Ѿ������õĶ��󣬲�ͨ����Ԫ�����ཫ��Ԫ�����ṩ���ͻ���ʹ�á�**

    ��Ԫģʽ��
    ���ù�������Ч��֧�ִ���ϸ���ȶ���ĸ��á�

**��ԪģʽҪ�󱻹���Ķ��������ϸ���ȶ���**�������ᵽ������Ӣ�Ķ�������ӣ�26����ĸ������ʱ���ͻ��ظ�ʹ�á�����ÿ����ĸ���ܳ��ֵ�λ�ò�һ�����������������ǹ���ͬһ������ͬһ��ʵ������������Ԫģʽ�����Դ���һ���洢26����ĸ�������Ԫ�أ���Ҫʱ����Ԫ����ȡ����

![](https://img-blog.csdnimg.cn/20191027095806263.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

��Ԫ�����ܹ���������Ĺؼ������������ڲ�״̬���ⲿ״̬��

* **�ڲ�״̬**���洢����Ԫ�����ڲ����������Ż����ĸı���ı�ģ��ڲ�״̬���Թ�������Χ�������ӵ���״����С�����������ⲿ�仯���仯��������ĸA������˭ʹ�ã�����A������仯��
* **�ⲿ״̬**���滷���仯���仯�������Թ����״̬�������ӵ�λ�á���ɫ����ÿ����ĸ��λ�á��ⲿ״̬һ���ɿͻ��˱��棬��ʹ��ʱ�ٴ��뵽��Ԫ�����ڲ�����ͬ���ⲿ״̬֮�����໥�����ģ�����A������B��λ�ÿ��Բ�ͬ�����Ҳ����໥Ӱ�졣

## ��Ԫģʽ�ṹ

��Ԫģʽ������Ϲ���ģʽһ��ʹ�ã���ṹ����������Ԫ�ࡢ������Ԫ�ࡢ�ǹ��������Ԫ�����Ԫ�����ࣺ

* **Flyweight��������Ԫ�ࣩ**����һ�������࣬�����˾�����Ԫ�๫���ķ�������Щ�����������ⲿ�ṩ��Ԫ������ڲ�״̬���ݣ�Ҳ����ͨ����Щ���������ⲿ״̬��
* **ConcreteFlyweight��������Ԫ�ࣩ**������ʵ�ֳ�����Ԫ�������ķ�����������Ԫ����Ϊ�ڲ�״̬�ṩ�洢�ռ䡣������Ԫ�ೣ����ϵ���ģʽ�����ʵ�֣���֤ÿ����Ԫ�����ֻ������һ�Σ�Ϊÿ��������Ԫ���ṩΨһ����Ԫ����
* **UnsharedConcreteFlyweight���ǹ��������Ԫ�ࣩ**�����������г�����Ԫ������඼��Ҫ���������Խ���Щ�����Ϊ�ǹ��������Ԫ�ࣻ
* **FlyweightFactory����Ԫ�����ࣩ**�����ڴ�����������Ԫ������Գ�����Ԫ���̣������־�����Ԫ�����洢��һ����Ԫ���У���Ԫ��һ�����Ϊһ���洢��ֵ�Եļ��ϣ������������͵ļ��ϣ����ɽ�Ϲ���ģʽ��ơ��ͻ���Ҫĳ����Ԫ����ʱ�������Ԫ�������иö���ʵ�����򷵻ظ�ʵ�������򴴽�һ���µ�ʵ�������ͻ������µ�ʵ����������ʵ����������Ԫ���С�

![](https://img-blog.csdnimg.cn/20191027103011515.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

## ��Ԫģʽ����ʵ��

    �ܶ������豸����֧�ֹ���ģ��罻������switch������������hub���ȡ�
    ��̨�жϼ������������ͬһ̨�����豸����ͨ�������豸��������ת����
    ����Jungle��ʹ����Ԫģʽ��ģ�⹲�������豸��ʵ����

�����У���������switch���ͼ�������hub���Ǿ�����Ԫ����UMLͼ������ʾ��

![](https://img-blog.csdnimg.cn/20191027152331572.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### ������Ԫ��

```C++
// ������Ԫ��
class NetDevice
{
public:
	NetDevice(){}
	virtual string getName() = 0;
 
	void print(){
		printf("NetDevice :%s\n",getName().c_str());
	}
};
```

### ������Ԫ��

������Ԫ���м������ͽ�������ʵ���˳�����Ԫ�������ķ�����

```C++
// ������Ԫ��:������
class Hub :public NetDevice
{
public:
	Hub(){}
	string getName(){
		return "������";
	}
};
 
// ������Ԫ��:������
class Switch :public NetDevice
{
public:
	Switch(){}
	string getName(){
		return "������";
	}
};
```

### ��Ԫ������

��Ԫ����������˵���ģʽ����֤����ʵ����Ψһ�ԡ�����һ��vector��Ϊ����ء�

```C++
// ��Ԫ������
class NetDeviceFactory
{
public:
	NetDevice* getNetDevice(char ch){
		if (ch == 'S'){
			return devicePool[1];
		}
		else if (ch == 'H'){
			return devicePool[0];
		}
		else{
			printf("wrong input!\n");
		}
		return NULL;
	}
 
	// ����ģʽ��������Ԫ�������Ψһʵ��
	static NetDeviceFactory* getFactory(){
		if (instance == NULL){
			m_mutex.lock();
			if (instance == NULL){
				instance = new NetDeviceFactory();
			}
			m_mutex.unlock();
		}
		return instance;
	}
 
private:
	NetDeviceFactory(){
		Hub *hub = new Hub();
		Switch *switcher = new Switch();
		devicePool.push_back(hub);
		devicePool.push_back(switcher);
	}
	static NetDeviceFactory* instance;
	static std::mutex m_mutex;
 
	// ����أ���һ��vector����ʾ
	vector<NetDevice*> devicePool;
};
 
NetDeviceFactory* NetDeviceFactory::instance = NULL;
std::mutex NetDeviceFactory::m_mutex;
```

### �ͻ��˴���ʾ��

```C++
#include <iostream>
#include "FlyweightPattern.h"
 
int main()
{
	NetDeviceFactory *factory = NetDeviceFactory::getFactory();
 
	NetDevice *device1, *device2, *device3, *device4;
 
	// �ͻ���1��ȡһ��hub
	device1 = factory->getNetDevice('H');
	device1->print();
	// �ͻ���2��ȡһ��hub
	device2 = factory->getNetDevice('H');
	device2->print();
	// �ж�����hub�Ƿ���ͬһ��
	printf("�ж�����hub�Ƿ���ͬһ��:\n");
	printf("device1:%p\ndevice2:%p\n", device1, device2);
 
	printf("\n\n\n\n");
	// �ͻ���3��ȡһ��switch
	device3 = factory->getNetDevice('S');
	device3->print();
	// �ͻ���4��ȡһ��switch
	device4 = factory->getNetDevice('S');
	device4->print();
	// �ж�����switch�Ƿ���ͬһ��
	printf("�ж�����switch�Ƿ���ͬһ��:\n");
	printf("device3:%p\ndevice4:%p\n", device3, device4);
 
	printf("\n\n");
 
	system("pause");
	return 0;
}
```

�ͻ��˴����У������ͻ��˷ֱ��ȡ��������Jungle��ӡ�������������ĵ�ַ�����ж��Ƿ���ͬһ������ͬ���Խ�������JungleҲ�������Ƶ��жϡ� 

�ɲ��Խ�����Կ�������������������ĵ�ַ����ͬ�ģ�˵�����Ƕ���ͬһ��ʵ����������������Ҳ��ָ��ͬһ��������ʵ�������ɴ�˵�������Ĵ���ʵ���������豸�Ĺ��� 

## �ܽ�

### �ŵ㣺

* ��Ԫģʽͨ����Ԫ�ش洢�Ѿ������õ���Ԫ����ʵ����ͬ�����Ƶ�ϸ���ȶ���ĸ��ã���������ϵͳ�еĶ�����������Լ���ڴ�ռ䣬������ϵͳ���ܣ�
* ��Ԫģʽͨ���ڲ�״̬���ⲿ״̬�����֣��ⲿ״̬�໥�������ͻ��˿��Ը�����������ʹ�á�

### ȱ�㣺

* ��Ԫģʽ��Ҫ�����߼���ȡ�ֳ��ڲ�״̬���ⲿ״̬�������˱�̵ĸ��Ӷȣ�

### ���û�����

* ��һ��ϵͳ���д����ظ�ʹ�õ���ͬ�����ƶ���ʱ��ʹ����Ԫģʽ���Խ�Լϵͳ��Դ��
* ����Ĵ󲿷�״̬�������ⲿ�������Խ���Щ״̬��������С�

|[��һƪ](./014_FacadePattern.md)|[Ŀ¼](./index.md)|[��һƪ](./016_ProxyPattern.md)|
|:---:|:---:|:---:|
|[���ģʽ](./014_FacadePattern.md)|[Ŀ¼](./index.md)|[����ģʽ](./016_ProxyPattern.md)|