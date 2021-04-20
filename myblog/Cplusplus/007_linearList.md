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

## 线性表的链式存储结构

### 定义

