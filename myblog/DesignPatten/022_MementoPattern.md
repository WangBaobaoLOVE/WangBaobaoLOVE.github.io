# ����¼ģʽ

|[��һƪ](./021_MediatorPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./023_ObserverPattern.md)|
|:---:|:---:|:---:|
|[�н���ģʽ](./021_MediatorPattern.md)|[Ŀ¼](./index.md)|[�۲���ģʽ](./023_ObserverPattern.md)|

    ��Ctrl+Z����ʲô��������λ���ù������Ҿ���ʹ�ðɣ�������
    ������һ������������һ��״̬�����������ü���������
    ���ص���������֮ǰ��״̬����������ǳ����ã�һ������ĳһ������ʧ��
    ����ѡ��������������ԭ�����޴�״̬��

    ��ôϵͳ��ô֪��ÿһ����״̬�أ���һ��������һ����������ʷ״̬��
    ����Git�汾����һ����������ÿһ���ύ��״̬��
    ʹ���߿�����ʱreset����ʷĳ��״̬������һ������¼һ����������ĳЩ�׶ε�״̬��

## ����¼ģʽ���

�������������Ե����ӣ������ϵͳ�Ĳ��������У���������һЩ�����Ĳ�����ʹ��ϵͳ״̬����ĳЩ���ϡ�����ܹ���һ�ֻ��ơ���**�ܹ�����ϵͳÿ���׶ε�״̬�����û�����ʧ���ʱ�򣬿��Գ��������Ĳ������ص���ʷĳ���׶�**������ô���ϵͳ�������������Ի���

��û��������һ�ֽ�������أ��У��Ǿ��Ǳ���¼ģʽ������¼ģʽ�ṩ��һ��״̬�ָ��Ļ��ƣ��û����Է���ػص�ָ����ĳ����ʷ״̬���ܶ�����ĳ�����������ʹ���˱���¼ģʽ��

    ����¼ģʽ��

    �ڲ��ƻ���װ��ǰ���²���һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬��
    �����������Ժ󽫶���ָ���ԭ�ȱ����״̬�� 

## ����¼ģʽ�ṹ

����¼ģʽ��UMLͼ������ʾ��

![](https://img-blog.csdnimg.cn/2019110422545122.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

����¼ģʽ��Ҫ�����½�ɫ��

* Originator��ԭ��������ͨ������һ������¼��洢��ǰ���ڲ�״̬��Ҳ����ʹ�ñ���¼���ָ����ڲ�״̬��ͨ���ǽ�ϵͳ����Ҫ�����ڲ�״̬�������Ϊԭ������
* Memento������¼�������ڴ洢ԭ�������ڲ�״̬������¼����ƿ��Բο�ԭ��������ƣ�������Ҫȷ������¼���е����ԣ�����ԭ��������󣬲��������������޸ı���¼��
* Caretaker�������ˣ������𱣴汸��¼�����Դ洢һ����������¼���󣬵��Ǹ�����ֻ���𱣴���󣬲����޸Ķ���Ҳ����֪�������ʵ��ϸ�ڡ��������ˣ������˿��Դ洢�������¼������һ������ʲô�ã��ǲ��ǿ��Ա�������ʷ״̬��ʵ�ֶಽ���������ˣ�

����¼ģʽ�Ĺؼ��Ǳ���¼��͸����������ƣ�����������������ɫ�ĵ���ʵ�֣�

```C++
#ifndef __DEMO_H__
#define __DEMO_H__
 
// ǰ������
class Memento;
 
// ԭ����  ����ʵ��
class Originator
{
public:
	Originator(){
		state = "";
	}
	Originator(String iState){
		state = iState;
	}
	// ��������¼����
	Memento* createMemento(){
		return new Memento(this);
	}
	// ���ñ���¼����ָ�ԭ����״̬
	void restoreMemento(Memento* m){
		state = m->getState();
	}
	void setState(string iState){ 
		state = iState; 
	}
	string getState(){ 
		return state; 
	}
private:
	string state;
};
 
// ����¼  ����ʵ�֣�����ԭ��������ƣ�
class Memento
{
public:
	Memento(){
		state = "";
	}
	Memento(Originator* o){
		state = o->getState();
	}
	void setState(String iState){
		state = iState;
	}
	string getState(){
		return state;
	}
private:
	String state;
};
 
// ������  ����ʵ��
class Caretaker
{
public:
	Caretaker(){}
	Memento* getMemento(){
		return memento;
	}
	void setMemento(Memento *m){
		memento = m;
	}
private:
	Memento* memento;
};
 
// �ͻ��� ʾ������
int main()
{
	// ����ԭ��������
	Originator o = new Originator("״̬1");
	// ���������˶���
	Caretaker *c = new Caretaker();
	c->setMemento(o->createMemento());
 
	o->setState("״̬2");
 
	// �Ӹ����˶�����ȡ������¼����ʵ�ֳ���
	o->restoreMemento(c->getMemento());
 
	return 0;
}
 
#endif
```

## ����¼ģʽ����ʵ��

    Jungle����Ϊ����汾������գ���ʱ��Ϊ�˳���ĳ�����ܾ�ȥ�޸Ĵ��룬
	����ԭ�еĽ�׳�Ĵ��뱻�ƻ�������Jungleϣ���ܹ����һ�����뱣���
	�汾���˹��ܵ�demo���������Ĺ���

��ʵ���У�ԭ����ΪCodeVersion�����а汾��version���ύ����date�ͱ�ǩlabel����״̬��Ҫ����¼Memento���棻��������CodeManager�������ύ����commit��������һ���汾�������˵�ָ���汾switchToPointedVersion���������������Ͳ鿴�ύ��ʷcodeLog�Ĺ��ܡ���ʵ����UMLͼ����ͼ������������¡�������������Դ��https://github.com/FengJungle/DesignPattern��

![](https://img-blog.csdnimg.cn/20191105223730981.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### ����¼Memento

```C++
#ifndef __MEMENTO_H__
#define __MEMENTO_H__
 
class Memento
{
public:
	Memento(){}
	Memento(int iVersion, string iDate, string iLabel){
		version = iVersion;
		date = iDate;
		label = iLabel;
	}
	void setVersion(int iVersion){
		version = iVersion;
	}
	int getVersion(){
		return version;
	}
	void setLabel(string iLabel){
		label = iLabel;
	}
	string getLabel(){
		return label;
	}
	void setDate(string iDate){
		date = iDate;
	}
	string getDate(){
		return date;
	}
private:
	int version;
	string date;
	string label;
};
 
#endif
```

### ԭ����CodeVersion

```C++
#ifndef __CODEVERSION_H__
#define __CODEVERSION_H__
 
#include <iostream>
using namespace std;
 
#include "Memento.h"
 
// ԭ������CodeVersion
class CodeVersion
{
public:
	CodeVersion(){
		version = 0;
		date = "1900-01-01";
		label = "none";
	}
	CodeVersion(int iVersion, string iDate, string iLabel){
		version = iVersion;
		date = iDate;
		label = iLabel;
	}
	// �������
	Memento* save(){
		return new Memento(this->version, this->date, this->label);
	}
	// ���˰汾
	void restore(Memento* memento){
		setVersion(memento->getVersion());
		setDate(memento->getDate());
		setLabel(memento->getLabel());
	}
	void setVersion(int iVersion){
		version = iVersion;
	}
	int getVersion(){
		return version;
	}
	void setLabel(string iLabel){
		label = iLabel;
	}
	string getLabel(){
		return label;
	}
	void setDate(string iDate){
		date = iDate;
	}
	string getDate(){
		return date;
	}
private:
	// ����汾
	int version;
	// �����ύ����
	string date;
	// �����ǩ
	string label;
};
 
#endif
```

### ������CodeManager 

```C++
#ifndef __CODEMANAGER_H__
#define __CODEMANAGER_H__
 
#include "Memento.h"
#include <vector>
using namespace std;
 
// ������
class CodeManager
{
public:
	CodeManager(){}
	void commit(Memento* m){
		printf("�ύ���汾-%d, ����-%s, ��ǩ-%s\n", m->getVersion(), m->getDate().c_str(), m->getLabel().c_str());
		mementoList.push_back(m);
	}
	// �л���ָ���İ汾�������˵�ָ���汾
	Memento* switchToPointedVersion(int index){
		mementoList.erase(mementoList.begin() + mementoList.size() - index, mementoList.end());
		return mementoList[mementoList.size() - 1];
	}
	// ��ӡ��ʷ�汾
	void codeLog(){
		for (int i = 0; i < mementoList.size(); i++){
			printf("[%d]���汾-%d, ����-%s, ��ǩ-%s\n", i, mementoList[i]->getVersion(),
				mementoList[i]->getDate().c_str(), mementoList[i]->getLabel().c_str());
		}
	}
private:
	vector<Memento*> mementoList;
};
 
#endif
```

### �ͻ��˴���ʾ����Ч��

```C++
#include "Originator.h"
#include "Memento.h"
#include "CodeManager.h"
 
int main()
{
	CodeManager *Jungle = new CodeManager();
 
	CodeVersion* codeVer = new CodeVersion(1001, "2019-11-03", "Initial version");
 
	// �ύ��ʼ�汾
	printf("�ύ��ʼ�汾:\n");
	Jungle->commit(codeVer->save());
 
	// �޸�һ���汾����������־����
	printf("\n�ύһ���汾����������־����:\n");
	codeVer->setVersion(1002);
	codeVer->setDate("2019-11-04");
	codeVer->setLabel("Add log funciton");
	Jungle->commit(codeVer->save());
 
	// �޸�һ���汾��������QtͼƬ�����
	printf("\n�ύһ���汾��������QtͼƬ�����:\n");
	codeVer->setVersion(1003);
	codeVer->setDate("2019-11-05");
	codeVer->setLabel("Add Qt Image Browser");
	Jungle->commit(codeVer->save());
 
	// �鿴�ύ��ʷ
	printf("\n�鿴�ύ��ʷ\n");
	Jungle->codeLog();
 
	// ���˵���һ���汾
	printf("\n���˵���һ���汾\n");
	codeVer->restore(Jungle->switchToPointedVersion(1));
 
	// �鿴�ύ��ʷ
	printf("\n�鿴�ύ��ʷ\n");
	Jungle->codeLog();
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

## �ܽ�

### �ŵ㣺

* ʵ��״̬�ָ������������Ĺ��ܣ��û����Իָ���ָ������ʷ״̬�������ϵͳ�������Ի���
* ����¼��װ����Ϣ������ԭ�������⣬����������ʲ��˱���¼�Ĵ��룻

### ȱ�㣺

* ��Դ���Ĵ������Ҫ����ԭ��������Ķ����ʷ״̬����ô�������������¼���󣻻������ԭ��������ĺܶ�״̬����Ҫ���棬Ҳ�����Ĵ����洢��Դ��

### ���û�����

* ����һ���������ʷ״̬��ϵͳ��Ҫ��ƻ��˻��߳������ܣ�
* ����¼����Է�װһ���������ʷ״̬������������ʷ״̬������޸ġ�

|[��һƪ](./021_MediatorPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./023_ObserverPattern.md)|
|:---:|:---:|:---:|
|[�н���ģʽ](./021_MediatorPattern.md)|[Ŀ¼](./index.md)|[�۲���ģʽ](./023_ObserverPattern.md)|