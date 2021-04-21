# Linear List(线性表)

**线性表：零个或多个数据元素的有限序列。**

## 线性表的抽象数据类型

**对于复杂的个性化操作，其实就是把基本操作组合起来实现的。**

```
ADT 线性表 (List)
Data
Operation  
    void initList(*L);	//创建并初始化一个空线性表，如果成功返回true，修改表传指针   
    bool listEmpty(L);	//判断一个线性表是否为空，不修改表传值   
    void clearList(*L);	//清空一个线性表，成功返回true   
    bool getElem(L,i,*e);	//从某个位置取出元素并赋值给e(i的范围是[1,L.length])，修改e的值所以传递一个指针，成功返回true  
    int locateElem(L,e);	//查找线性表中是否有e，如果有返回它的位置(从1开始)，否则返回0表示失败  
    bool listInsert(*L,i,e);	//插入一个元素e在第i个元素之前(i的取值范围是[1,L.length+1]) ，成功返回true   
    bool listDelete(*L,i,*e);	//删除在第i个位置上的元素(i的取值范围是[1,L.length]),删除的元素赋给e，成功返回true  
    int listLength(L);	//返回线性表的元素个数  
endADT
```

## 线性表的顺序存储结构

### 定义、基础

线性表的顺序存储结构，指的是用**一段地址连续的存储单元**依次存储线性表的数据元素。

线性表的顺序存储的结构体定义为：
```C++
#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int ElemType;   /* ElemType类型根据实际情况而定，这里假设为int */

typedef struct
{
	ElemType data[MAXSIZE]; /* 数组，存储数据元素 */
	int length;             /* 线性表当前长度 */
}SqList;
```

描述顺序存储结构需要三个属性：

- 存储空间的起始位置：数组data,它的存储位置就是存储空间的存储位置。
- 线性表的最大存储容量：数组长度MaxSize。
- 线性表的当前长度：length。

### 操作

- [Demo1.cpp(函数形式)](./007_LinearList/Demo1.cpp)
- [LinearListClassDemo2.cpp(类形式)](./007_LinearList/LinearListClassDemo2.cpp)
  
#### 初始化

```C++
/* 初始化顺序线性表 */
Status InitList(SqList *L)
{
    L->length=0;
    return OK;
}
```

#### 获得元素

```C++
Status Getelem(SqList *L, int i, ElemType *e){ // 获得某个元素
    if(L->length==0 || i<1 || i>L->length)
        return ERROR;
    *e = L->data[i-1];
    return OK;
}
```

#### 插入元素
```C++
/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList *L,int i,ElemType e)
{
	int k;
	if (L->length==MAXSIZE)  /* 顺序线性表已经满 */
		return ERROR;
	if (i<1 || i>L->length+1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
		return ERROR;

	if (i<=L->length)        /* 若插入数据位置不在表尾 */
	{
		for(k=L->length-1; k>=i-1; k--)  /* 将要插入位置之后的数据元素向后移动一位 */
			L->data[k+1] = L->data[k];
	}
	L->data[i-1]=e;          /* 将新元素插入 */
	L->length++;

	return OK;
}
```

#### 删除元素

删除算法的思路：

1. 如果删除位置不合理，抛出异常；
2. 取出删除元素；
3. 从删除元素位置开始遍历到最后一个元素位置，分别将它们都向前移动一个位置；
4. 表长减1。

```C++
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L,int i,ElemType *e)
{
    int k;
    if (L->length==0)               /* 线性表为空 */
		return ERROR;
    if (i < 1 || i>L->length)         /* 删除位置不正确 */
        return ERROR;
    *e=L->data[i-1];
    if (i < L->length)                /* 如果删除不是最后位置 */
    {
        for(k=i;k < L->length; k++)/* 将删除位置后继元素前移 */
			L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}
```

### 优缺点

**优点**：

具有简单、运算方便等优点，特别是对于小线性表或长度固定的线性表，采用顺序存储结构的优越性更为突出；

**缺点**：

- 顺序存储插入与删除一个元素，必须移动大了的数据元素，以此对大的线性表，特别是在元素的插入和删除很频繁的情况下，采取顺序存储很是不方便，效率低；
- 顺序存储空间容易满，出现上溢，程序访问容易出问题，顺序存储结构下，存储空间不便扩充；
- 顺序存储空间的分配问题，分多了浪费，分少了空间不足上溢。

## 线性表的链式存储结构

### 定义

线性表的链式存储结构的特点是用一组任意的存储单元存储线性表的数据元素，这组存储单元可以是连续的，也可以是不连续的。这就意味着，这些数据元素可以存在内存未被占用的任意位置，比如下图：

![](http://www.nowamagic.net/librarys/images/201208/2012_08_30_02.jpg)

以前在顺序结构中，每个数据元素只需要存数据元素信息就可以了。现在链式结构中，除了要存数据元素信息外，还要存储它的后继元素的存储地址。


- 数据域：我们把存储数据元素信息的域称为数据域。
- 指针域：存储直接后继位置的域称为指针域。
- 指针/链：指针域中存储的信息称做指针或链。
- 结点(Node)：数据域与指针域这两部分信息组成数据元素ai的存储映像，称为结点(Node)

![](http://www.nowamagic.net/librarys/images/201208/2012_08_30_03.jpg)

### 单链表

#### 概念

链表的每个结点中只包含一个指针域，因为指针域中存储的信息称做链，而且这个链每个结点都只有一个，所以叫做单链表。

![](http://www.nowamagic.net/librarys/images/201208/2012_08_31_01.jpg)

- 头结点是为了操作的统一与方便而设立的，放在第一个元素结点之前，其数据域一般无意义（当然有些情况下也可存放链表的长度、用做监视哨等等）。
- 有了头结点后，对在第一个元素结点前插入结点和删除第一个结点，其操作与对其它结点的操作统一了。
- 首元结点也就是第一个元素的结点，它是头结点后边的第一个结点。
- 头结点不是链表所必需的。
- 在线性表的链式存储结构中，头指针是指链表指向第一个结点的指针，若链表有头结点，则头指针就是指向链表头结点的指针。
- 头指针具有标识作用，故常用头指针冠以链表的名字。
- 无论链表是否为空，头指针均不为空。头指针是链表的必要元素。

![](http://www.nowamagic.net/librarys/images/201208/2012_08_31_02.jpg)

#### 代码定义

定义一个结构体来描述单链表的结点。[结构体指针（RefLink）](http://c.biancheng.net/view/246.html)
```C++
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /* 定义LinkList (头指针)*/
```

#### 操作

- [SingleLinkListClassDemo3.cpp](./007_LinearList/SingleLinkListClassDemo3.cpp)
- [程序 RefLink](https://blog.csdn.net/qq_35143440/article/details/78896638)

- 创建
- 读取
- 插入
- 删除
- （new和delete）与（malloc和free）

```C++
#include<iostream>
using namespace std;
 
typedef int DataType;
#define Node ElemType
#define ERROR NULL
 
//构建一个节点类
class Node						  
{
    public:
        int data;     //数据域
        Node *next;  //指针域
};
 
//构建一个单链表类
class LinkList					  
{
public:
	LinkList();					  //构建一个单链表;
	~LinkList();                  //销毁一个单链表;
	void CreateLinkList(int n);   //创建一个单链表
	void TravalLinkList();        //遍历线性表
	int GetLength();              //获取线性表长度
	bool IsEmpty();               //判断单链表是否为空
	ElemType * Find(DataType data); //查找节点
	void InsertElemAtEnd(DataType data);            //在尾部插入指定的元素
	void InsertElemAtIndex(DataType data,int n);    //在指定位置插入指定元素
	void InsertElemAtHead(DataType data);           //在头部插入指定元素
	void DeleteElemAtEnd();       //在尾部删除元素
	void DeleteAll();             //删除所有数据
	void DeleteElemAtPoint(DataType data);     //删除指定的数据
	void DeleteElemAtHead();      //在头部删除节点
private:
	ElemType *head;              //头结点
    int length;
};
 
//初始化单链表
LinkList::LinkList()                  
{
	head = new ElemType;            
	head->data = 0;               //将头结点的数据域定义为0
	head->next = NULL;            //头结点的下一个定义为NULL
    length = 0;
}     
 
//销毁单链表
LinkList::~LinkList()
{
	delete head;                 //删除头结点
} 
 
//创建一个单链表
void LinkList::CreateLinkList(int n)
{
	ElemType *pnew, *ptemp;
	ptemp = head;
	if (n < 0) {       //当输入的值有误时，处理异常
		cout << "输入的节点个数有误" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n;i++) {        //将值一个一个插入单链表中
		pnew = new ElemType;
		cout << "请输入第" << i + 1 << "个值: " ;
		cin >> pnew->data;
		pnew->next = NULL;          //新节点的下一个地址为NULL
		ptemp->next = pnew;         //当前结点的下一个地址设为新节点
		ptemp = pnew;               //将当前结点设为新节点
        length++;
	}
}
 
//遍历单链表
void LinkList::TravalLinkList()
{
	if (head == NULL || head->next ==NULL) {
		cout << "链表为空表" << endl;
	}
    else{
        ElemType *p = head;                 //另指针指向头结点
        while (p->next != NULL)        //当指针的下一个地址不为空时，循环输出p的数据域
        {
            p = p->next;               //p指向p的下一个地址
            cout << p->data << " ";
        }
    }
}
 
//获取单链表的长度
int LinkList::GetLength()
{
	return length;                   //返回count的数据
}
 
//判断单链表是否为空
bool LinkList::IsEmpty()
{
	if (length == 0) {                 
		return true;
	}
	return false;
}
 
//查找节点
ElemType * LinkList::Find(DataType data)
{
	ElemType *p = head;
	if (p->next == NULL) {                           //当为空表时，报异常
		cout << "此链表为空链表" << endl;
		return NULL;
	}
	else
	{
		while (p->next != NULL)               //循环每一个节点
		{
            p = p->next;
			if (p->data == data) {
				return p;                     //返回指针域
			}
		}
		return NULL;                           //未查询到结果
	}
}
 
//在尾部插入指定的元素
void LinkList::InsertElemAtEnd(DataType data)
{
	ElemType * newNode = new ElemType;    //定义一个Node结点指针newNode
	newNode->next = NULL;         //定义newNode的数据域和指针域
	newNode->data = data;
	ElemType * p = head;              //定义指针p指向头结点
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
    length++;
}
 
//在指定位置插入指定元素
void LinkList::InsertElemAtIndex(DataType data,int n)
{
	if (n<1 || n>GetLength())                   //输入有误报异常
		cout << "输入的值错误" << endl;
	else
	{
		ElemType * ptemp = new ElemType;        //创建一个新的节点
		ptemp->data = data;                     //定义数据域
		ElemType * p = head;                    //创建一个指针指向头结点
		while (--n != 0)                           //遍历到指定的位置
		{
			p = p->next;
		}
		ptemp->next = p->next;                 //将新节点插入到指定位置
		p->next = ptemp;
        length++;
	}
}
 
//在头部插入指定元素
void LinkList::InsertElemAtHead(DataType data)
{
	ElemType * newNode = new ElemType;    //定义一个Node结点指针newNode
	newNode->data = data;
	ElemType * p;              //定义指针p指向头结点
    p = head->next;
    head->next = newNode;
    newNode->next = p;
    length++;
}
 
//在尾部删除元素
void LinkList::DeleteElemAtEnd()
{
	ElemType * p = head;          //创建一个指针指向头结点
	ElemType * ptemp = NULL;      //创建一个占位节点
	if (p->next == NULL) {        //判断链表是否为空
		cout << "单链表空" << endl;
	}
	else
	{
		while (p->next != NULL)   //循环到尾部的前一个
		{
			ptemp = p;            //将ptemp指向尾部的前一个节点
			p = p->next;          //p指向最后一个节点
		}
		delete p;                //删除尾部节点
		p = NULL;
		ptemp->next = NULL;
	}
}
 
//删除所有数据
void LinkList::DeleteAll()
{
	ElemType * p = head->next;
	ElemType * ptemp = new ElemType;
	while (p != NULL)                    //在头结点的下一个节点逐个删除节点
	{
		ptemp = p;
		p = p->next;
		head->next = p;
		ptemp->next = NULL;
		delete ptemp;
	}
	head->next = NULL;                 //头结点的下一个节点指向NULL
}
 
//删除指定的数据
void LinkList::DeleteElemAtPoint(DataType data)
{
	ElemType * ptemp = Find(data);    //查找到指定数据的节点位置
	if (ptemp == head->next) {        //判断是不是头结点的下一个节点，如果是就从头部删了它
		DeleteElemAtHead();
	}
	else
	{
		ElemType * p = head;          //p指向头结点
		while (p->next != ptemp)      //p循环到指定位置的前一个节点
		{
			p = p->next;
		}
		p->next = ptemp->next;         //删除指定位置的节点
		delete ptemp;
		ptemp = NULL;               
	}
 
}
 
//在头部删除节点
void LinkList::DeleteElemAtHead()
{
	ElemType * p = head;
	if (p == NULL || p->next == NULL) {   //判断是否为空表，报异常
		cout << "该链表为空表" << endl;
	}
	else
	{
		ElemType * ptemp = NULL;      //创建一个占位节点
		p = p->next;
		ptemp = p->next;              //将头结点的下下个节点指向占位节点
		delete p;                     //删除头结点的下一个节点
		p = NULL;
		head->next = ptemp;           //头结点的指针更换
	}
}
 
//测试函数
int main()
{
	LinkList l;
	int i;
	cout << "1.创建单链表   2.遍历单链表   3.获取单链表的长度   4.判断单链表是否为空   5.获取节点\n";
	cout << "6.在尾部插入指定元素   7.在指定位置插入指定元素   8.在头部插入指定元素\n";
	cout<<"9.在尾部删除元素   10.删除所有元素   11.删除指定元素   12.在头部删除元素   0.退出" << endl;
	do
	{
		cout << "请输入要执行的操作: ";
		cin >> i;
		switch (i)
		{
		case 1:
			int n;
			cout << "请输入单链表的长度: ";
			cin >> n;
			l.CreateLinkList(n);
			break;
		case 2:
			l.TravalLinkList();
			break;
		case 3:
			cout << "该单链表的长度为" << l.GetLength() << endl;
			break;
		case 4:
			if (l.IsEmpty() == 1)
				cout << "该单链表是空表" << endl;
			else
			{
				cout << "该单链表不是空表" << endl;
			}
			break;
		case 5:
			DataType data;
			cout << "请输入要获取节点的值: ";
			cin >> data;
			cout << "该节点的值为" << l.Find(data)->data << endl;
			break;
		case 6:
			DataType endData;
			cout << "请输入要在尾部插入的值: ";
			cin >> endData;
			l.InsertElemAtEnd(endData);
			break;
		case 7:
			DataType pointData;
			int index;
			cout << "请输入要插入的数据: ";
			cin >> pointData;
			cout << "请输入要插入数据的位置: ";
			cin >> index;
			l.InsertElemAtIndex(pointData, index);
			break;
		case 8:
			DataType headData;
			cout << "请输入要在头部插入的值: ";
			cin >> headData;
			l.InsertElemAtHead(headData);
			break;
		case 9:
			l.DeleteElemAtEnd();
			break;
		case 10:
			l.DeleteAll();
			break;
		case 11:
			DataType pointDeleteData;
			cout << "请输入要删除的数据: ";
			cin >> pointDeleteData;
			l.DeleteElemAtPoint(pointDeleteData);
			break;
		case 12:
			l.DeleteElemAtHead();
			break;
		default:
			break;
		}
	}while (i != 0);
 
	system("pause");
    return 0;
}
```

## 静态链表

对于没有指针的编程语言，可以用数组替代指针，来描述链表。让数组的每个元素由data和cur两部分组成，其中cur相当于链表的next指针，这种用数组描述的链表叫做静态链表，这种描述方法叫做游标实现法。我们对数组的第一个和最后一个元素做特殊处理，不存数据。让数组的第一个元素cur存放第一个备用元素（未被占用的元素）下标，而数组的最后一个元素cur存放第一个有值的元素下标，相当于头结点作用。空的静态链表如下图：

![](https://images2017.cnblogs.com/blog/675248/201710/675248-20171030155818996-1272480786.png)

- [SStaticLinkListDemo4.cpp](./007_LinearList/StaticLinkListDemo4.cpp)
- [RefLink](https://blog.csdn.net/weixin_39966065/article/details/104041644)
- [RefLink](https://www.cnblogs.com/zhaoxy/p/7754906.html)

## 循环链表

 将单链表中终端节点的指针改为指向头结点，就使整个单链表形成一个环，这种头尾相接的单链表称为单循环链表，简称循环链表。

带头节点的空循环链表（左）和带头结点的非空循环链表（右）

![](https://images2017.cnblogs.com/blog/675248/201710/675248-20171030154244386-2061118430.png)
![](https://images2017.cnblogs.com/blog/675248/201710/675248-20171030154302308-1256198626.png)

循环链表判断结束的条件为：节点是否指向链表的头节点。循环列表访问第一个元素的复杂度为O(1)，但访问最后一个元素的复杂度为O(n)。为了方便最后一个元素的访问，经常使用尾指针指向循环链表的最后一个元素。如下图

![](https://images2017.cnblogs.com/blog/675248/201710/675248-20171031111701340-215536680.png)

## 双向链表

双向链表（double linked list）是在单链表的每个节点中，再设置一个指向其前驱节点的指针域。所以，双向链表中都有2个指针，一个指向其直接前驱，另一个指向直接后继。

双向循环链表，与循环链表类似，带头结点的双向循环空链表如下图（左），非空如下图（右边）

![](https://images2017.cnblogs.com/blog/675248/201710/675248-20171031112943871-633213278.png)
![](https://images2017.cnblogs.com/blog/675248/201710/675248-20171031112958308-416997820.png)

 双向链表的插入操作如下图:

 ![](https://images2017.cnblogs.com/blog/675248/201710/675248-20171031113139465-1873572320.png)

 双向链表的删除操作如下图:

 https://images2017.cnblogs.com/blog/675248/201710/675248-20171031113208449-1140407840.png