# ������ģʽ

|[��һƪ](./018_CommandPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./020_IteratorPattern.md)|
|:---:|:---:|:---:|
|[����ģʽ](./018_CommandPattern.md)|[Ŀ¼](./index.md)|[������ģʽ](./020_IteratorPattern.md)|

    ��������������1566��������Jungle����������ʷ�統������ϲ�����Ƴ��һ���硣
    �����ⲿ���С����Ƕ�֪�����ξ��ʵ�˵���������������װ�˵����������ϲ������
    ˵������˵�������ϸϸ���⣬������֪���ξ�˵����ʵ������ʲô�����������º�˵
    ���е�ˮ�����������ʱ�����º����ᵽ�������������ݣ�̫��ϲ����ӣ��ξ�����
    ���������Ҫ��Jungle��������ʱ���Կ���ñ�󰡣����촧��ʵ۵���ͼ�����ˡ�Ҫ
    ���и��������ͺ��ˣ��ܹ��ѻʵ۵Ļ�����Ϊ�����װ׵����ԣ�

## ������ģʽ����

������ģʽ��������һ���򵥵����Խ���������ҪӦ����ʹ������������Կ����Ľ���������ơ�����Ҫ����һ���µ�����ʱ������ʹ�ý�����ģʽ��

    ������ģʽ��

    ����һ�����ԣ����������ķ���һ�ֱ�ʾ��������һ�������������������ʹ�øñ�ʾ�����������еľ��ӡ�

**������ģʽ��Ҫ������ǣ����һ���ض����͵����ⷢ����Ƶ���㹻�ߣ���ô���ܾ�ֵ�ý�������ĸ���ʵ������Ϊһ���������еľ��ӡ������Ϳ��Թ���һ�����������ý�����ͨ��������Щ���ӣ������������**��������ģʽ���������Ϊ�򵥵����Զ���һ���ķ�������ڸ������б�ʾһ�����ӣ��Լ���ν�����Щ���ӡ�

## ������ģʽ�ṹ

������ģʽ�Ľṹ�ɳ�����ʽ���ս�����ʽ�����ս�����ʽ�ͻ�������ɣ�

* **AbstractExpression��������ʽ��**�������˳���Ľ��Ͳ���interpret()���������ս�����ʽ�ͷ��ս�����ʽ�Ļ��ࣻ
* **TerminalExpression���ս�����ʽ��**���ս�����ķ���������Ԫ��������������Ե�λ�������ٷֽ⡣�ս�����ʽʵ�������ķ��������ս����صĽ��Ͳ����������е�ÿһ���ս�����Ǹ����һ��ʵ����
* **NonterminalExpression�����ս�����ʽ��**��ʵ�����ķ������з��ս���Ľ��Ͳ�������Ϊ���ս�����ʽͬ�����԰����ս�����ʽ�������ս�����ʽ�����Ƿ��ս�����ʽ�ĳ�Ա��
* **Context�������ࣩ**�����������࣬���ڴ洢������֮���һЩȫ����Ϣ��ͨ����ʱ�洢��Ҫ���͵���䡣

![](https://img-blog.csdnimg.cn/20191101224415514.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

������ģʽ��UMLͼ������ʾ��������ʽ�����˳���ӿ�interpret()���ս�����ʽ�ͷ��ս�����ʽʽ����ʵ���˸ýӿڡ����У��ս�����ʽ��interpret()�ӿ�ʵ���˾���Ľ��Ͳ�������**���ս�����ʽ�п��ܰ����ս�����ʽ���߷��ս�����ʽ�����Է��ս�����ʽ��interpret()�ӿ��п����ǵݹ����ÿһ����ɲ��ֵ�interpret()����**�� 

## ������ģʽ����ʵ��

    ����Jungleʹ�ý�����ģʽʵ������һ��С���ܣ�

    ���һ���򵥵Ľ�������ʹ��ϵͳ���Խ���0��1�Ļ�����������㣨�����ǻ��������
    ��������ȼ��������������������㣩�������ʽ���������ļ���ʵ�����±�

**���ʽ������������ʵ����**

 ���ʽ | ������ |���ʽ | ������
---------|----------|---------|---------
1 and 1 | 1 | 0 or 0  | 0
1 or 1 | 1 | 1 and 1 or 0 | 1
1 or 0 | 1 | 0 or 1 and 0 | 0
1 and 0 | 0 | 0 or 1 and 1 or 1 | 1
0 and 0 | 0 | 1 or 0 and 1 and 0 or 0 | 0

���ǰ�������Ľ�����ģʽ�Ľṹ�ͱ��������Ի��ֳ����½�ɫ��

* **�ս�����ʽ��ɫ����ֵ�ڵ㣨ValueNode��**��0��1����Ϊ�����Ǳ��ʽ�Ļ������Ԫ�أ�������ϸ��
* **�ս�����ʽ��ɫ����������ڵ㣨OperatorNode��**��������š�and���͡�or�� ��ͬ��Ҳ�Ǳ��ʽ�Ļ������Ԫ��
* **���ս�����ʽ��ɫ�������ӽڵ㣨SentenceNode��**�������ڡ�1 and 1�������ı��ʽ���߸�������ϱ��ʽ
* **���������ɫ���������ߣ�Handler��**����������ı��ʽ������Ľ��

�ɴˣ�������UMLʵ��ͼ���£�

![](https://img-blog.csdnimg.cn/20191102221920656.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### ������ʽ

```C++
    // ������ʽ��
    class AbstractNode
    {
    public:
    	AbstractNode(){}
    	// ��������ӿ�
    	virtual char interpret() = 0;
    };
```

### �ս�����ʽ��ɫ����ֵ�ڵ�

```C++
// �ս�����ʽ��ValueNode
class ValueNode :public AbstractNode
{
public :
	ValueNode(){}
	ValueNode(int iValue){
		this->value = iValue;
	}
	// ʵ�ֽ��Ͳ���
	char interpret(){
		return value;
	}
private:
	int value;
};
```

### �ս�����ʽ��ɫ����������ڵ�

```C++
// �ս�����ʽ��OperationNode
class OperatorNode :public AbstractNode
{
public:
	OperatorNode(){}
	OperatorNode(string iOp){
		this->op = iOp;
	}
	// ʵ�ֽ��Ͳ���
	char interpret(){
		if (op == "and"){
			return '&';
		}
		else if (op == "or"){
			return '|';
		}
		return 0;
	}
private:
	string op;
};
```

### ���ս�����ʽ��ɫ�������ӽڵ�

ÿһ�����ӽڵ��ɡ���ֵ�ڵ�+������ڵ�+��ֵ�ڵ㡱��ɡ�

```C++
// ���ս�����ʽ��SentenceNode
class SentenceNode :public AbstractNode
{
public:
	SentenceNode(){}
	SentenceNode(AbstractNode *iLeftNode,
		AbstractNode *iRightNode, AbstractNode* iOperatorNode){
		this->leftNode = iLeftNode;
		this->rightNode = iRightNode;
		this->operatorNode = iOperatorNode;
	}
	char interpret(){
		if (operatorNode->interpret() == '&'){
			return leftNode->interpret()&rightNode->interpret();
		}
		else{
			return leftNode->interpret()|rightNode->interpret();
		}
		return 0;
	}
private:
	AbstractNode *leftNode;
	AbstractNode *rightNode;
	AbstractNode *operatorNode;
};
```

### �����Ľ�ɫ����������

�����߽���������ı��ʽ�������ͳ����ʽ���յĽ����

```C++
// ������
class Handler
{
public:
	Handler(){}
	void setInput(string iInput){
		this->input = iInput;
	}
	void handle(){
		AbstractNode      *left = NULL;
		AbstractNode     *right = NULL;
		AbstractNode        *op = NULL;
		AbstractNode  *sentence = NULL;
		string iInput = this->input;
		vector<string>inputList;
		char* inputCh = const_cast<char*>(iInput.c_str());
		char *token = strtok(inputCh, " ");
		while (token != NULL){
			inputList.push_back(token);
			token = strtok(NULL, " ");
		}
		for (int i = 0; i < inputList.size() - 2; i += 2){
			left = new ValueNode(*(inputList[i].c_str()));
			op = new OperatorNode(inputList[i + 1]);
			right = new ValueNode(*(inputList[i+2].c_str()));
			sentence = new SentenceNode(left, right, op);
			inputList[i + 2] = string(1, sentence->interpret());
		}
		string tmpRes = inputList[inputList.size() - 1];
		if (tmpRes == "1"){
			result = 1;
		}
		else if (tmpRes == "0"){
			result = 0;
		}
		else{
			result = -1;
		}
		this->output();
	}
	void output(){
		printf("%s = %d\n", input.c_str(), result);
	}
private:
	string input;
	char result;
};
```

### �ͻ��˴���ʾ���ͽ�� 

```C++
#include <iostream>
#include "InterpreterPattern.h"
 
int main()
{
	Handler *handler = new Handler();
 
	string input_1 = "1 and 1";
	string input_2 = "1 and 0";
	string input_3 = "0 and 1";
	string input_4 = "0 and 0";
	string input_5 = "0 or 0";
	string input_6 = "0 or 1";
	string input_7 = "1 or 0";
	string input_8 = "1 or 1";
	string input_9 = "1 and 0 or 1";
	string input_10 = "0 or 0 and 1";
	string input_11 = "1 or 1 and 1 and 0";
	string input_12 = "0 and 1 and 1 and 1";
	string input_13 = "0 and 1 and 1 and 1 or 1 or 0 and 1";
	handler->setInput(input_1); handler->handle();
	handler->setInput(input_2); handler->handle();
	handler->setInput(input_3); handler->handle();
	handler->setInput(input_4); handler->handle();
	handler->setInput(input_5); handler->handle();
	handler->setInput(input_6); handler->handle();
	handler->setInput(input_7); handler->handle();
	handler->setInput(input_8); handler->handle();
	handler->setInput(input_9); handler->handle();
	handler->setInput(input_10); handler->handle();
	handler->setInput(input_11); handler->handle();
	handler->setInput(input_12); handler->handle();
	handler->setInput(input_13); handler->handle();
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

## �ܽ�

### �ŵ㣺

* ���ڸı����չ�ķ����ڽ�������ʹ�����ʾ���Ե��ķ����򣬿���ͨ���̳еȻ�����ı����չ�ķ���
* ÿһ���ķ����򶼿��Ա�ʾΪһ���࣬��˿��Է����ʵ��һ���򵥵����ԣ�
* ���Ҫ�����µĽ��ͱ��ʽ��ֻ������һ���µ��ս�����ʽ����ս�����ʽ�࣬�����޸�ԭ�д��룬���Ͽ���ԭ��

### ȱ�㣺

* ���ڸ����ķ�����ά�����ڽ�����ģʽ��ÿһ������������Ҫ����һ���࣬������һ�����԰���̫���ķ�������ĸ�������������ӣ�����ϵͳ���Թ����ά����
* ִ��Ч�ʵͣ���Ϊ������ģʽ���д���ѭ���͵ݹ���á�

### ���û�����

* һЩ�ظ����ֵ����������һ�ּ򵥵����Խ��б�
* һ�����Ե��ķ���Ϊ�򵥣�
* ������ִ��Ч�ʵ�����ʱ����ʹ�ý�����ģʽ��

|[��һƪ](./018_CommandPattern.md)|[Ŀ¼](./index.md)|[��һƪ](./020_IteratorPattern.md)|
|:---:|:---:|:---:|
|[����ģʽ](./018_CommandPattern.md)|[Ŀ¼](./index.md)|[������ģʽ](./020_IteratorPattern.md)|