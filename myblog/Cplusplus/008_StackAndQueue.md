# 栈和队列

## 栈

栈是限定仅在表尾进行插入和删除操作的线性表。

- [Learn RefLink](https://blog.csdn.net/dibing0354/article/details/101883066)
- [Code RefLink](https://blog.csdn.net/lxy_2011/article/details/95486470)

栈也是线性表，是一个特殊的线性表，之前说线性的表的时候，线性表可以在任意位置进行插入插入，而栈比线性表特殊的地方的就是不能随意的插入和删除了，栈的插入和删除只能在规定的同一端进行，而被允许插入和删除的一端称为栈顶，另一端称为栈底。

![](https://images2017.cnblogs.com/blog/743587/201709/743587-20170910162400882-1483729795.png)

**进栈和出栈操作**

1. 判断栈是否已经满了，如果满了当然就入不了栈。
2. 栈顶指针+1，在新栈顶位置存入要进栈的元素。

![进栈](https://images2017.cnblogs.com/blog/743587/201709/743587-20170910162402929-544083625.png)

1. 判断栈是否为空，里面没有数据先出栈也没有。
2. 将栈顶元素出栈，栈顶指针-1。

![出栈](https://images2017.cnblogs.com/blog/743587/201709/743587-20170910162403663-930172926.png)

## 代码实现

### 栈的抽象数据结构

```C++
ADT 栈(stack)
Data
Operation
    InitStack ( *S )：初始化操作.建立一个空栈S。
    DestroyStack ( *S )：若栈存在，則销毁它。
    ClearStack (*S)：将栈清空。
    StackEmpty ( S ):若栈为空，返回true,否則返回 false。
    GetTop (S,*e)：若栈存在且非空，用e返回S的栈顶元素。
    Push (*S,e)：若栈S存在，插入新元素e到栈S中并成为栈顶元素。(进栈)
    Pop (*S,*e)：删除栈S中栈顶元素，并用e返回其值。(出栈)
    StackLength (S)：返回栈S的元素个数。
endADT
```

### 栈的顺序存储

[SqStackDemo1.cpp](./008_StackAndQueue/SqStackDemo1.cpp)

一般把下标为0的一端作为栈底。 栈的结构定义：

```C++
typedef int SElemType;

typedef struct
{	
    SElemType data[MAXSIZE];	    
	int top;                 //用于栈顶指针     

}SqStack;
```

**我个人觉得可以再在上面的结构体中加入`length`来表示当前栈的`装载量`。**

栈的三种状态-----栈空、栈满、栈未满，见下图：

![](https://images2017.cnblogs.com/blog/743587/201709/743587-20170910162402054-514010176.png)

1. 栈空时：栈顶指针`（top）= -1`
2. 栈满时：栈顶指针`（top）=MAXSIZE-1`；
3. 栈未满：就是占中存在元素，`top`指针还未达到`MAXSIZE-1`.

#### 进栈操作

```C++
Status Push(SqStack *S, SElemType e)
{
    if(S->top == MAXSIZE - 1)
    	return ERROR;
    S->top++;
    S->data[S->top]=e;
    return OK;
}
```

#### 出栈操作

```C++
Status Pop(SqStack *S, SElemType *e)
{
    if(S->top == - 1)
    	return ERROR;
    *e = S->data[S->top];         //将要删除的栈顶元素赋值
    S->top--;
    return OK;
}
```

#### 两栈共享空间

- [RefLink](https://baozoulin.gitbook.io/-data-structure/di-4-zhang-zhan-yu-dui-lie/44liang-zhan-gong-xiang-kong-jian)
- [SqDoubleStackDemo2.cpp](./008_StackAndQueue/SqDoubleStackDemo2.cpp)

用一个数组来存储两个栈，数组有两个端点，两个栈有两个栈底，让一个栈的栈底为数组的始端，即下标为0处，另一个栈为数组的末端，即下标为数组长度n-处。两个栈如果增加元素，就是两端点向中间延伸。

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cL5BlMxdS84JqVe3%2F61import.png?alt=media)

判断是否栈满：`top1+1=top2`则栈满.

两栈共享空间的结构的代码如下：

```C++
/* 两栈共享空间结构 */
typedef struct
{    
    SElemType data[MAXSIZE];    
    int top1;    /* 栈1栈顶指针 */    
    int top2;    /* 栈2栈顶指针 */
} SqDoubleStack;
```

对于两栈共享空间的`push`方法，除了要插入元素值参数外，还需要有一个判断是`栈1`还是`栈2`的栈号参数`stackNumber`。插入元素的代码如下：

```C++
/* 插入元素e为新的栈顶元素 */
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{    
    /* 栈已满，不能再push新元素了 */    
    if (S->top1 + 1 == S->top2)            
        return ERROR;    
    /* 栈1有元素进栈 */    
    if (stackNumber == 1)                  
        /* 若栈1则先top1+1后给数组元素赋值 */        
        S->data[++S->top1] = e;        
    /* 栈2有元素进栈 */    
    else if (stackNumber == 2)             
        /* 若栈2则先top2-1后给数组元素赋值 */        
        S->data[--S->top2] = e;        
    return OK;
}
```

对于两栈共享空间的`pop`方法，参数就只是判断`栈1`,`栈2`的参数`stackNumber`。

```C++
/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
        if (stackNumber==1) 
        {
                if (S->top1==-1) 
                        return ERROR; /* 说明栈1已经是空栈，溢出 */
                *e=S->data[S->top1--]; /* 将栈1的栈顶元素出栈 */
        }
        else if (stackNumber==2)
        { 
                if (S->top2==MAXSIZE) 
                        return ERROR; /* 说明栈2已经是空栈，溢出 */
                *e=S->data[S->top2++]; /* 将栈2的栈顶元素出栈 */
        }
        return OK;
}
```

### 栈的链式存储

- [Code RefLink](https://blog.csdn.net/lxy_2011/article/details/95486470)
- [Learn and Code RefLink](https://baozoulin.gitbook.io/-data-structure/di-4-zhang-zhan-yu-dui-lie/45zhan-de-lian-shi-cun-chu-jie-gou-ji-shi-xian)

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cSlfNeBv-7_9KC7X%2F62import.png?alt=media)

**栈的链式存储结构，简称为链栈.**

由于单链表有头指针，而栈顶指针也是必须的，所以比较好的办法是把栈顶放在单链表的头部。另外，都已经有了栈顶在头部了，单链表中比较常用的头结点也就失去了意义，通常对于链栈来说，是不需要头结点的.

对于链栈来说，基本不存在栈满的情况，除非内存已经没有可以使用的空间，如果真的发生，那此时的计算机操作系统已经面临死机崩溃的情况，而不是这个链栈是否溢出的问题。但对于空栈来说，链表原定义是头指针指向空，那么链栈的空其实就是top=NULL的时候.

**链栈的结构代码如下**：

```C++
/* 链栈结构 */
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;


typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;
```

#### 进栈操作

对于链栈的进栈push操作，假设元素值为e的新结点是s，top为栈顶指针。

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cSliTonSDvZvVmdE%2F63import.png?alt=media)

```C++
/* 插入元素e为新的栈顶元素 */
Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
    s->data=e; 
    s->next=S->top;    /* 把当前的栈顶元素赋值给新结点的直接后继，见图中1 */
    S->top=s;         /* 将新的结点s赋值给栈顶指针，见图中2 */
    S->count++;
    return OK;
}
```

#### 出栈操作

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cSllNXjyTo-ug_oj%2F64import.png?alt=media)

```C++
/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
    LinkStackPtr p;
    if(StackEmpty(*S))
        return ERROR;
    *e=S->top->data;
    p=S->top;                    /* 将栈顶结点赋值给p，见图中③ */
    S->top=S->top->next;    /* 使得栈顶指针下移一位，指向后一结点，见图中④ */
    free(p);                    /* 释放结点p */        
    S->count--;
    return OK;
}
```

### 顺序存储和链存储的优缺点（顺序栈与链栈）

1. 时间复杂度上均为O(1)。
2. 对于空间性能，顺序栈需要事先确定一个固定的长度，可能会存在内存空间浪费的问题，但它的优势是存取时定位很方便，而链栈则要求每个元素都有指针域，这同时也增加了一些内存开销，但对于栈的长度无限制。
3. 如果栈的使用过程中元素变化不可预料，有时很小，有时非常大，那么最好是用链栈，如果它的变化在可控范围内，建议使用顺序栈。

### 栈的应用

#### 递归

#### 四则运算表达式求值

## 队列

队列是指允许在一端进行插入操作，而在另一端进行删除操作的线性表。

