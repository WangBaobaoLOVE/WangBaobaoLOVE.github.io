# ������ģʽ

|[��һƪ](./019_InterpreterPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./021_MediatorPattern.md)|
|:---:|:---:|:---:|
|[������ģʽ](./019_InterpreterPattern.md)|[Ŀ¼](./index.md)|[�н���ģʽ](./021_MediatorPattern.md)|

    д���벻��ʹ������������Ƶļ��϶���ɣ�ÿ��Ҫ����һ��������ô�죿
    For ѭ��������whileѭ����һ��һ������ÿ��λ�õ�Ԫ�أ�ֱ������ĩβ��
    STL����������ר�ŵĵ���������Ծ���ļ���������ж�Ӧʹ�õĵ�������
    STL�ĵ������ṩ�˷ḻ�ı�������������ʼ��϶������λԪ�ء�ĩλԪ�ء�
    ָ��λ�õ�Ԫ�ء���һ��Ԫ�ء�����ô�����ǲ��Ǹо����˵��������������������������ˣ�

## ������ģʽ����

�������ճ���������о���ʹ�ã�ͨ������Ҫ��һ�����кܶ����ʵ���ļ��ϣ���Ϊ**�ۺ϶���**�����з��ʻ��ȡ������Ҫȡ�ۺ϶������λԪ�ء��ж��Ƿ��ھۺ϶����ĩβ�ȡ���Ծۺ϶���ı�����������ģʽ��һ�ֺ���Ч�Ľ��������Ҳ��һ��ʹ��Ƶ�ʺܸߵ����ģʽ��

    ������ģʽ��

    �ṩһ�ַ���˳�����һ���ۺ϶����еĸ���Ԫ�أ����ֲ���¶�ö�����ڲ���ʾ��

ͨ����������������Խ����ݵı������ܴӾۺ϶����з������������һ�����ۺ϶���ֻ�踺��洢���ݣ���������������������ݣ�ʹ�þۺ϶����ְ����ӵ�һ�����ϵ�һְ��ԭ��

## ������ģʽ�ṹ

������ģʽ�ṹ�а����ۺϺ͵�����������εĽṹ��Ϊ������չ��������ģʽ�����͹�������ģʽ��ϡ�������ģʽ��UMLͼ���¡���ͼ��֪��������ģʽ�����¼�����ɫ��

![](https://img-blog.csdnimg.cn/2019110310444590.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

* **Iterator�������������**�������˷��ʺͱ����ۺ϶���Ԫ�صĽӿڣ���first()�������ڷ��ʾۺ϶����е�һ��Ԫ�أ�next()�������ڷ�����һ��Ԫ�أ�hasNext()�ж��Ƿ�����һ��Ԫ�أ�currentItem()�������ڻ�ȡ��ǰԪ�ء�
* **ConcreteIterator�������������**��ʵ�ֳ�������������ķ�����ͨ������������л�ר����һ����������Ϊ�α꣩����¼�������ھۺ϶�����������λ�á�
* **Aggregate������ۺ��ࣩ**�����ڴ洢�͹���Ԫ�ض�������һ�������������Ľӿڣ���ʵ��һ����������������Ľ�ɫ��
* **ConcreteAggregate������ۺ��ࣩ**��ʵ���˷���createIterator()���÷�������һ����þ���ۺ����Ӧ�ľ��������ConcreteIterator��ʵ����

## ������ģʽ����ʵ��

    ���ӻ�ң�����ǵ�������һ����ʵӦ�ã�ͨ��������ʵ�ֶԵ���Ƶ�����ϵı������������ӻ����Կ���һ���洢Ƶ���ľۺ϶��󡣱���Jungle�����õ�����ģʽ��ģ��ң������������Ƶ���Ĺ��̡�

�����ԣ�ң������һ������ĵ�������������һ��Ƶ��previous() ����һ��Ƶ��next()����ǰƵ��currentChannel()�ȹ��ܣ���Ҫ�����ľۺ϶����ǵ���Ƶ���ļ��ϣ������ӻ���������UMLͼ���£�

![](https://img-blog.csdnimg.cn/20191103141040241.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### ����ۺ���;���ۺ���

```C++
#ifndef __AGGREGATE_H__
#define __AGGREGATE_H__
 
#include <vector>
using namespace std;
 
// ǰ����������Ϊ�����໥������
class Iterator;
class RemoteControl;
 
// ����ۺ��� Aggregate
class Aggregate
{
public:
	Aggregate(){}
	virtual Iterator* createIterator() = 0;
};
 
// ����ۺ��� Television
class Television :public Aggregate
{
public:
	Television();
	Television(vector<string> iChannelList);
	// ʵ�ִ���������
	Iterator* createIterator();
	// ��ȡ�ܵ�Ƶ����Ŀ
	int getTotalChannelNum();
	void play(int i);
private:
	vector<string> channelList;
};
 
#endif //__AGGREGATE_H__
```

ʵ�֣�

```C++
#include "Iterator.h"
 
Television::Television(){}
 
Television::Television(vector<string> iChannelList){
	this->channelList = iChannelList;
}
 
Iterator* Television::createIterator(){
	RemoteControl *it = new RemoteControl();
	it->setTV(this);
	return (Iterator*)it;
}
 
int Television::getTotalChannelNum(){
	return channelList.size();
}
 
void Television::play(int i){
	printf("���ڲ��ţ�%s����\n", channelList[i].c_str());
}
```

### ���������

```C++
// ���������
class Iterator
{
public:
	Iterator(){}
	// ���������������
	virtual void first() = 0;
	virtual void last() = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool hasNext() = 0;
	virtual bool hasPrevious() = 0;
	virtual void currentChannel() = 0;
};
```

### �����������RemoteControl

```C++
// ң���������������
class RemoteControl :public Iterator
{
public:
	RemoteControl(){}
	void setTV(Television *iTv){
		this->tv = iTv;
		cursor = -1;
		totalNum = tv->getTotalChannelNum();
	}
	// ʵ�ָ�����������
	void first(){
		cursor = 0;
	}
	void last(){
		cursor = totalNum - 1;
	}
	void next(){
		cursor++;
	}
	void previous(){
		cursor--;
	}
	bool hasNext(){
		return !(cursor == totalNum);
	}
	bool hasPrevious(){
		return !(cursor == -1);
	}
	void currentChannel(){
		tv->play(cursor);
	}
private:
	// �α�
	int cursor;
	// �ܵ�Ƶ����Ŀ
	int totalNum;
	// ����
	Television* tv;
};
```

### �ͻ��˴���ʾ������� 

```C++
#include <iostream>
#include "Iterator.h"
 
int main()
{
	vector<string> channelList = { "����Ƶ��", "�ƾ�Ƶ��", "����Ƶ��", "��ӰƵ��", "����Ƶ��", "ũҵƵ��", "�Ĵ�����", "�ɶ�����" };
	// ��������
	Television *tv = new Television(channelList);
	// ����ң����
	Iterator *remoteControl = tv->createIterator();
 
	// ˳�����
	printf("˳�����:\n");
	remoteControl->first();
	// ������������Ƶ��
	while (remoteControl->hasNext()){
		remoteControl->currentChannel();
		remoteControl->next();
	}
 
	printf("\n\n");
 
	// �������
	printf("�������:\n");
	remoteControl->last();
	// ������������Ƶ��
	while (remoteControl->hasPrevious()){
		remoteControl->currentChannel();
		remoteControl->previous();
	}
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

|[��һƪ](./019_InterpreterPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./021_MediatorPattern.md)|
|:---:|:---:|:---:|
|[������ģʽ](./019_InterpreterPattern.md)|[Ŀ¼](./index.md)|[�н���ģʽ](./021_MediatorPattern.md)|