# ����ģʽ

|[��һƪ](./017_ChainOfResponsibility.md)|[Ŀ¼](./index.md)|[��һƪ](./019_InterpreterPattern.md)|
|:---:|:---:|:---:|
|[ְ����ģʽ](./017_ChainOfResponsibility.md)|[Ŀ¼](./index.md)|[������ģʽ](./019_InterpreterPattern.md)|

    ���ǵ�Jungle������Ƶ�QtͼƬ����������������һ�š��������һ��ͼƬ��
    �������һ�š��������һ��ͼƬ��������Զ����š������Զ����ϵ��²���ÿһ��ͼƬ��
    �ǲ��Ǻ���Ȥ��һ��С����

�����ĳ�������ͺ����û�����ͼƬ���������ָ�ͼƬ������ڲ����յ�ָ���ʼ������Ӧ�ĺ��������ս���ǲ�����һ�Ż���һ��ͼƬ����ִ�л���Ӧ���û�����������ͻ�����֪��������������ʲô��ʽ��Ҳ��֪��ͼƬ������ڲ����������ִ�еģ�ͬ����������ڲ�Ҳ��֪����˭���������**����ķ��ͷ��ͽ��շ���ִ�з���û���κι���**����������ģʽ�У���һ��**������ķ�������ִ���߽�������ģʽ��������ģʽ**��

![](https://img-blog.csdnimg.cn/20191030071941696.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

## ����ģʽ���

����ģʽ���Խ���������ķ��������������ȫ����������������֮��û��ֱ�����ù�ϵ����������Ķ���ֻ��Ҫ֪����η������󣬶�����֪�������������ɵġ������ǱȽϻ�ɬ�Ѷ�������ģʽ�Ķ��壺

    ����ģʽ��

    ��һ�������װΪһ�����󣬴Ӷ����ò�ͬ������Կͻ����в��������������Ŷӻ��߼�¼������־���Լ�֧�ֿɳ����Ĳ�����

 ����ģʽ�Ķ���Ƚϸ��ӣ�Ҳ�ᵽһЩ�����Щ��������Ĳ����;���������һ��˵����

## ����ģʽ�ṹ

![](https://img-blog.csdnimg.cn/20191029235510879.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

����ģʽ��UML�ṹ����ͼ������ģʽһ�������¼��ֽ�ɫ��

* **Command�����������ࣩ**����һ�������࣬����������ִ������Ľӿ�execute()��
* **ConcreteCommand�����������ࣩ**������������࣬ʵ����ִ������Ľӿ�execute()������Ӧ����Ľ����߶��󣬽������ߣ�Receiver���Ķ���action()�����С���execu()�����н����ý����ߵĶ���action()��**������Ƕ����еġ��������װ��һ�����󡱵����֣�**
* **Invoker�������ߣ�**������ķ����ߣ�ͨ�����������ִ������һ�������߲���Ҫ�����ʱȷ��������ߣ����Ե�����ͨ���ۺϣ������������������**����ʵ���У����Խ�һ�������������ע�뵽�������У���ͨ�����þ�����������execute()������ʵ�ּ����������ִ���ߣ������ߣ��Ĳ���**��
* **Receiver�������ߣ�**�� ʵ�ִ�������ľ��������action����

## ����ģʽ����ʵ��

    �����е�**���أ�Button��**��������ģʽ��һ��ʵ�֣�����ʹ������ģʽ��ģ�⿪�ع���
    ���ɿ��ƵĶ������**��ƣ�Lamp��**��**���ȣ�Fan��**���û�ÿ�δ�����touch�����أ�
    �����Դ򿪻��߹رյ�ƻ��ߵ��ȡ�

![](https://img-blog.csdnimg.cn/20191030075605236.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

��ʵ����UMLͼ������ʾ�����������������execute()�ӿڡ����������������࣬�ֱ��ǿ��ƵƵ�LampCommand�Ϳ��Ʒ��ȵ�FanCommand�࣬������������ʵ����execute()�ӿڣ���ִ�п��ص�/�������󡣱����еĵ������ǰ�ťButton��ÿ���û�����touch()�����ذ�ť�������ڷ������󡣱����������ʵ�ֹ������¡�

### �������ࣺ��ƺͷ���

```C++
// �����ߣ������
class Lamp
{
public :
	Lamp(){
		this->lampState = false;
	}
	void on(){
		lampState = true;
		printf("Lamp is on\n");
	}
	void off(){
		lampState = false;
		printf("Lamp is off\n");
	}
	bool getLampState(){
		return lampState;
	}
private:
	bool lampState;
};
 
// �����ߣ�������
class Fan
{
public:
	Fan(){
		this->fanState = false;
	}
	void on(){
		fanState = true;
		printf("Fan is on\n");
	}
	void off(){
		fanState = false;
		printf("Fan is off\n");
	}
	bool getFanState(){
		return fanState;
	}
private:
	bool fanState;
};
```

### ����������

```C++
    // ���������� Command
    class Command
    {
    public:
    	Command(){}
    	// ��������ӿڣ���������
    	virtual void execute() = 0;
    private:
    	Command *command;
    };
```

### ���������� 

```C++
// ���������� LampCommand
class LampCommand :public Command
{
public:
	LampCommand(){
		printf("���ؿ��Ƶ��\n");
		lamp = new Lamp();
	}
	// ʵ��execute()
	void execute(){
		if (lamp->getLampState()){
			lamp->off();
		}
		else{
			lamp->on();
		}
	}
private:
	Lamp *lamp;
};
 
// ���������� FanCommand
class FanCommand :public Command
{
public:
	FanCommand(){
		printf("���ؿ��Ʒ���\n");
		fan = new Fan();
	}
	// ʵ��execute()
	void execute(){
		if (fan->getFanState()){
			fan->off();
		}
		else{
			fan->on();
		}
	}
private:
	Fan *fan;
};
```

### �����ߣ�Button

```C++
// ������ Button
class Button
{
public:
	Button(){}
	// ע��������������
	void setCommand(Command *cmd){
		this->command = cmd;
	}
	// �������������ť
	void touch(){
		printf("��������:");
		command->execute();
	}
private:
	Command *command;
};
```

### �ͻ��˴���ʾ��

```C++
#include <iostream>
#include "CommandPattern.h"
 
int main()
{
	// ʵ���������ߣ���ť
	Button *button = new Button();
	Command *lampCmd, *fanCmd;
 
	// ��ť���Ƶ��
	lampCmd = new LampCommand();
	button->setCommand(lampCmd);
	button->touch();
	button->touch();
	button->touch();
 
	printf("\n\n");
 
	// ��ť���Ʒ���
	fanCmd = new FanCommand();
	button->setCommand(fanCmd);
	button->touch();
	button->touch();
	button->touch();
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

## �������

��ʱ�򣬵��������߷���һ������ʱ���в�ֹһ����������߲�����Ӧ��Qt�źŲۣ�һ���źſ������Ӷ���ۣ�����Щ��������߽����ִ��ҵ�񷽷�����ɶ�����Ĵ�����ʱ���������������ʵ�֡�**���簴ť����ͬʱ���Ƶ�ƺͷ��ȣ���������У����������ǰ�ť���أ������������߲�����Ӧ���ֱ��ǵ�ƺͷ���**��

���Բο���������е�ʵ�ַ�ʽ������һ����������ࣨCommandQueue�����洢���������󣬲�ͬ��������Ӧ��ͬ����������ߡ�������Ҳ���������������̣�����ע�����������������ķ���setCommandQueue(CommandQueue *cmdQueue)��

���������չʾ�˰�ť��������ʱ����ƺͷ���ͬʱ��Ϊ����Ľ����ߡ�����������ʾ��

```C++
#ifdef COMMAND_QUEUE
/*************************************/
/*             �������              */
#include <vector>
 
// ���������
class CommandQueue
{
public:
	CommandQueue(){
	}
	void addCommand(Command *cmd){
		commandQueue.push_back(cmd);
	}
	void execute(){
		for (int i = 0; i < commandQueue.size(); i++)
		{
			commandQueue[i]->execute();
		}
	}
private:
	vector<Command*>commandQueue;
 
};
 
// ������
class Button2
{
public:
	Button2(){}
	// ע�����������������
	void setCommandQueue(CommandQueue *cmdQueue){
		this->cmdQueue = cmdQueue;
	}
	// �������������ť
	void touch(){
		printf("��������:");
		cmdQueue->execute();
	}
private:
	CommandQueue *cmdQueue;
};
#endif
```

 �ͻ��˴������£�

```C++
#ifdef COMMAND_QUEUE
 
	printf("\n\n***********************************\n");
	Button2 *button2 = new Button2();
	Command *lampCmd2, *fanCmd2;
	CommandQueue *cmdQueue = new CommandQueue();
 
	// ��ť���Ƶ��
	lampCmd2 = new LampCommand();
	cmdQueue->addCommand(lampCmd2);
 
	// ��ť���Ʒ���
	fanCmd2 = new FanCommand();
	cmdQueue->addCommand(fanCmd2);
 
	button2->setCommandQueue(cmdQueue);
	button2->touch();
 
#endif
```

## ����ģʽ����Ӧ��

### ��¼������־

����ʷ�����¼��������־���������־���ܶ����ϵͳ���ṩ����־�ļ�����¼���й����е����̡�һ��ϵͳ�������ϣ���־��Ϊ�˷�������Ĺؼ�����־Ҳ���Ա�����������е������������ÿִ����һ������ʹ���־��ɾ��һ����Ӧ�Ķ���

### ������

�������ֽ������������ģʽ������ģʽ�Ľ�ϡ���������һ�����������࣬ӵ��һ������ϣ�������а����˶����������������á�������ͨ����ֱ���������߽���������ͨ�����ĳ�Ա���������ý����ߵķ����������ú������execute()����ʱ���ͱ���ִ��ÿһ��������������execute()��������������ǰ���������У�

## �ܽ�

### �ŵ㣺

* ����ϵͳ��϶ȣ��������������������߷����������ߺͷ����߲�����ֱ�ӹ��������Զ�������Ӱ�졣
* ������չ���µ���������׼��뵽ϵͳ�У��ҷ��Ͽ���ԭ��
* ������ʵ��������л�����
* Ϊ����ĳ����ͻظ������ṩ��һ�����ʵ�ַ�����

### ȱ�㣺

* ����ģʽ���ܵ���ϵͳ���й���ľ��������࣬������ϵͳ�ж����������

### ���û�����

* ϵͳ��Ҫ���������ߺͽ����߽��ʹ�÷����ߺͽ����߻���Ӱ�졣
* ϵͳ��Ҫ�ڲ�ͬʱ��ָ�����󡢽������ŶӺ�ִ������
* ϵͳ��Ҫ֧������ĳ����ͻָ�������
* ϵͳ��Ҫ��һ����������һ���γɺ����

|[��һƪ](./017_ChainOfResponsibility.md)|[Ŀ¼](./index.md)|[��һƪ](./019_InterpreterPattern.md)|
|:---:|:---:|:---:|
|[ְ����ģʽ](./017_ChainOfResponsibility.md)|[Ŀ¼](./index.md)|[������ģʽ](./019_InterpreterPattern.md)|