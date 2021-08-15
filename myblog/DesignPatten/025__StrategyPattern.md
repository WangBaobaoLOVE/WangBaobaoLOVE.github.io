# ����ģʽ

|[��һƪ](./024_StatePattern.md)|[Ŀ¼](./index.md)|[��һƪ](./026_TemplateMethodPattern.md)|
|:---:|:---:|:---:|
|[״̬ģʽ](./024_StatePattern.md)|[Ŀ¼](./index.md)|[ģ�巽��ģʽ](./026_TemplateMethodPattern.md)|

    ͬ���������㷨�������ѡ��ð������ѡ�����򡢲������򡢿�������ȵȣ�
    Ҳ����˵��Ϊ��ʵ��������һ��Ŀ�ģ��кܶ����㷨����ѡ����Щ��ͬ������
    �㷨������һ���㷨�壬���������Ҫ��ʱ�򣬸�����������������ƣ��ڴ桢
    ���Ӷȵȣ���ʱѡ�������㷨��

��������������������������һ���㷨���أ��������˶����㷨����ʹ�õ�ʱ���ֻ����������ѡ�������㷨����ͻ��õ�������ģʽ�еġ�������ģʽ��

## ����ģʽ���

����ģʽ�����㷨�������л�����չ����Ӧ�ڽ��ĳһ�����һ���㷨�壬�����û��Ӹ��㷨��������ѡ��һ���㷨������⣬ͬʱ�����Է���ظ����㷨���������µ��㷨������ģʽ���㷨���е�ÿһ���㷨����װ��һ���࣬ÿһ�����Ϊһ�����ԣ�Strategy����

    ����ģʽ��

    ����һϵ���㷨����ÿһ���㷨��װ�������������ǿ����໥�滻������ģʽ���㷨���Զ�����ʹ�����Ŀͻ����仯��

## ����ģʽ�ṹ

Ϊ�˷����㷨���еĲ�ͬ�㷨��ʹ���о���һ���ԣ��ڲ���ģʽ�л��ṩһ������������������ӿڣ��ھ���Ĳ�������ʵ�ָ����㷨������ģʽ����������Ͳ�������ɣ���UML�ṹ����ͼ��

![](https://img-blog.csdnimg.cn/20191109115537961.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

* **Context���������ࣩ** ������������ʹ���㷨�Ľ�ɫ�������ڽ����ͬ���������ʱʵ������ͬ�ľ�����������
* **Strategy����������ࣩ**�������㷨�ķ��������������ʹ������������޲��ĵ��ò�ͬ�ľ�����Եķ�����
* **ConcreteStrategy����������ࣩ**��ʵ�־�����㷨��

## ����ģʽ����ʵ��

    ĳϵͳ�ṩ��һ�����ڶ�������в������࣬�����װ�˶�����ĳ���������
    �����������Ϊ����ʹ�ò���ģʽ��Ƹ���������࣬ʹ�ÿͻ��˿��Զ�̬
    ���������㷨�����Ը�����Ҫѡ��ð���������ѡ��������߲�������
    Ҳ�ܹ���������µ������㷨 ��

 ��Ȼ���ڸ�ʵ���У�����ð������ѡ������Ͳ�������ֱ��װΪ3����������࣬�����й�ͬ�Ļ���SortStrategy������Ҫһ����������Context��Context��ά����һ��SortStrategy��ָ�룬�ڿͻ�����Ҫ��ʱ��ͨ��Context��setSortStrategy()������ʵ�����������������󡣸�ʵ����UML�ṹͼ���£�

![](https://img-blog.csdnimg.cn/20191109211602496.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzIxMTA3NDMz,size_16,color_FFFFFF,t_70)

### ���������

#### �������������

```C++
    // ���������
    class Strategy
    {
    public:
    	Strategy(){}
    	virtual void sort(int arr[], int N) = 0;
    };
```

#### ��������ࣺð��������

```C++
// ������ԣ�ð������
class BubbleSort :public Strategy
{
public:
	BubbleSort(){
		printf("ð������\n");
	}
	void sort(int arr[], int N){
		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j<N - i - 1; j++)
			{
				if (arr[j]>arr[j + 1]){
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}
};
```

#### ��������ࣺѡ��������

```C++
// ������ԣ�ѡ������
class SelectionSort :public Strategy
{
public:
	SelectionSort(){
		printf("ѡ������\n");
	}
	void sort(int arr[], int N){
		int i, j, k;
		for (i = 0; i<N; i++)
		{
			k = i;
			for (j = i + 1; j<N; j++)
			{
				if (arr[j] < arr[k]){
					k = j;
				}
			}
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
};
```

#### ��������ࣺ����������

```C++
// ������ԣ���������
class InsertSort :public Strategy
{
public:
	InsertSort(){
		printf("��������\n");
	}
	void sort(int arr[], int N){
		int i, j;
		for (i = 1; i<N; i++)
		{
			for (j = i - 1; j >= 0; j--)
			{
				if (arr[i]>arr[j]){
					break;
				}
			}
			int temp = arr[i];
			for (int k = i - 1; k > j; k--){
				arr[k + 1] = arr[k];
			}
			arr[j + 1] = temp;
		}
	}
};
```

### ��������

```C++
#ifndef __CONTEXT_H__
#define __CONTEXT_H__
 
#include "Strategy.h"
#include <stdio.h>
 
// ��������
class Context
{
public:
	Context(){
		arr = NULL;
		N = 0;
	}
	Context(int iArr[], int iN){
		this->arr = iArr;
		this->N = iN;
	}
	void setSortStrategy(Strategy* iSortStrategy){
		this->sortStrategy = iSortStrategy;
	}
	void sort(){
		this->sortStrategy->sort(arr, N);
		printf("����� ");
		this->print();
	}
	void setInput(int iArr[], int iN){
		this->arr = iArr;
		this->N = iN;
	}
	void print(){
		for (int i = 0; i < N; i++){
			printf("%3d ", arr[i]);
		}
		printf("\n");
	}
 
private:
	Strategy* sortStrategy;
	int* arr;
	int N;
};
 
#endif // __CONTEXT_H__
```

### �ͻ��˴���ʾ�������

```C++
#include "Context.h"
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	Context* ctx = new Context();
	int arr[] = { 10, 23, -1, 0, 300, 87, 28, 77, -32, 2 };
	ctx->setInput(arr, sizeof(arr)/sizeof(int));
	printf("���룺");
	ctx->print();
 
	// ð������
	ctx->setSortStrategy(new BubbleSort());
	ctx->sort();
 
	// ѡ������
	ctx->setSortStrategy(new SelectionSort());
	ctx->sort();
 
	// ��������
	ctx->setSortStrategy(new InsertSort());
	ctx->sort();
 
	printf("\n\n");
	system("pause");
	return 0;
}
```

## �ܽ�

### �ŵ㣺

* ���Ͽ���ԭ�򣬲���ģʽ������չ�������µ��㷨ʱֻ��̳г�������࣬�����ʵ��һ����������༴�ɣ�
* �ͻ��˿����޲���ͨ�������ӿڵ��ã�������ʽ�滻ԭ�����ʹ�ò�ͬ���㷨���ԣ�
* �ṩ��һ���㷨�������ƺ�ά�����ơ�

### ȱ�㣺

* �ͻ��˱���Ҫ֪�����еĲ��ԣ��Ա���ʹ��ʱ����ʵ����������ԣ�
* ϵͳ������ܶ൥�����࣬����ϵͳ�����������
* �ͻ�����ͬһʱ��ֻ��ʹ��һ�ֲ��ԡ�

### ���û�����

* ϵͳ��Ҫ��һ���㷨���ж�̬ѡ��һ���㷨�����Խ���Щ�㷨��װ����������㷨���У���Щ�㷨�඼�й�ͬ�Ļ��࣬������ͨ��һ��ͳһ�Ľӿڵ�������һ���㷨���ͻ��˿���ʹ������һ���㷨��
* ��ϣ���ͻ���֪�����ӵġ����㷨��ص����ݽṹ���ھ���������з�װ���㷨��ص����ݽṹ����������㷨�İ�ȫ�ԡ�

|[��һƪ](./024_StatePattern.md)|[Ŀ¼](./index.md)|[��һƪ](./026_TemplateMethodPattern.md)|
|:---:|:---:|:---:|
|[״̬ģʽ](./024_StatePattern.md)|[Ŀ¼](./index.md)|[ģ�巽��ģʽ](./026_TemplateMethodPattern.md)|