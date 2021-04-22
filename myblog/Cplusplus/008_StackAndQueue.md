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

##### 斐波那契数列实现

|月数|1|2|3|4|5|6|7|8|9|10|11|12|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|兔子对数|1|1|2|3|5|8|13|21|34|55|89|144|

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cSn27mY3Ywpy--if%2F66import.png?alt=media)

数学函数来定义就是：

1. F(n) = 0; n=0
2. F(n) = 1; n=1
3. F(n) = F(n-1)+F(n-2); n>1

打印出前40位的斐波那契数列数。代码如下：

[](./008_StackAndQueue/Fibonacci.c)
```C++
#include "stdio.h"

int Fbi(int i)  /* 斐波那契的递归函数 */
{
    if( i < 2 )
        return i == 0 ? 0 : 1;  
    return Fbi(i - 1) + Fbi(i - 2);  /* 这里Fbi就是函数自己，等于在调用自己 */
}  

int main()
{
    int i;
    int a[40];  
    printf("迭代显示斐波那契数列：\n");
    a[0]=0;
    a[1]=1;
    printf("%d ",a[0]);  
    printf("%d ",a[1]);  
    for(i = 2;i < 40;i++)  
    { 
        a[i] = a[i-1] + a[i-2];  
        printf("%d ",a[i]);  
    } 
    printf("\n");

    printf("递归显示斐波那契数列：\n");
    for(i = 0;i < 40;i++)  
        printf("%d \n", Fbi(i));  

    printf("显示某个具体位置斐波那契数列的值：\n"); 
    printf("%d ", Fbi(39));  
    return 0;
}
```

Fbi(i)函数当i=5的执行过程:

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cSn7nr4dhUZHbjBP%2F68import.png?alt=media)
 

**我们把一个直接调用自己或通过一系列的调用语句间接地调用自己的函数，称做递归函数。**

递归函数的代码格式：

```C++
type functionName( int value){
    if(value == ) 到了递归的终止条件
        return 一个具体的值。
    return functionName(value-1); 传入的下一个数字根据具体问题不同，具体的递归公式也有所不同。
}
```

#### 四则运算表达式求值

##### 

## 队列

**队列是指允许在一端进行插入操作，而在另一端进行删除操作的线性表。**允许插入的一端称为队尾，允许删除的一端称为队头。

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cTXyzl1_TZWuaeqx%2F80import.png?alt=media)

### 队列的抽象数据类型

```C++
ADT 队列(Queue)
Data    
    同线性表。元素具有相同的类型，相邻元素具有前驱和后继关系。
Operation    
    InitQueue(*Q):    初始化操作，建立一个空队列Q。    
    DestroyQueue(*Q): 若队列Q存在，则销毁它。    
    ClearQueue(*Q):   将队列Q清空。    
    QueueEmpty(Q):    若队列Q为空，返回true，否则返回false。    
    GetHead(Q, *e):   若队列Q存在且非空，用e返回队列Q的队头元素。    
    EnQueue(*Q, e):   若队列Q存在，插入新元素e到队列Q中并成为队尾元素。    
    DeQueue(*Q, *e):  删除队列Q中队头元素，并用e返回其值。    
    QueueLength(Q):   返回队列Q的元素个数
endADT
```

### 循环队列

#### 队列顺序存储的不足

假设一个队列有n个元素，则顺序存储的队列需建立一个大于n的数组，并把队列的所有元素存储在数组的前n个单元，数组下标为0的一端即是队头。入队列操作就是在队尾追加一个元素，不需要移动任何元素，时间复杂度为O(1)。

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cTDZljb6jJq4ZYrQ%2F81import.png?alt=media)

队列元素的出列是在队头，即下标为0的位置，队列中的所有元素都得向前移动，以保证队列的队头，也就是下标为0的位置不为空，此时时间复杂度为O(n).

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cTDfqMosB9LOsTRB%2F82import.png?alt=media)

`队头不一定就要一定在下标为0的位置`.

为了避免当只有一个元素时，队头和队尾重合使处理变得麻烦，引入两个指针，front指针指向队头元素，rear指针指向队尾元素的下一个位置，当front等于rear时，此队列不是还剩一个元素，而是空队列。

假设是长度为5的数组，初始状态，空队列如左图，front与rear指针均指向下标为0的位置。然后入队a1,a2,a3,a4，front指针依然指向下标为0位置，而rear指针指向下标为4的位置.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cTDjOru1ckJ8ZxY-%2F83import.png?alt=media)

出队a1,a2，front指针指向下标为2的位置，rear不变，如左图，再入队a5，front指针不变，rear指针移动到数组之外.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cTDlWH_DCARqcYaE%2F84import.png?alt=media)

如果接着入队的话，因数组末尾元素已经占用，再向后加，就会产生数组越界的错误，可实际上，下标为0和1的地方还是空闲的,这种现象叫做`假溢出`。

#### 循环队列定义

`队列的这种头尾相接的顺序存储结构称为循环队列。`rear可以改为指向下标为的位置.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cTDoeJAhzmov9Dh4%2F85import.png?alt=media)

接着入队a6，将它放置于下标为0处，rear指针指向下标为1处，如左图。再入队a7，则rear指针就与front指针重合，同时指向下标为2的位置，如右图.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cTDqtnf-bCvwmwCk%2F86import.png?alt=media)

`如何判断此时的队列究竟是空还是满呢？`

1. 办法一：设置一个标志变量flag，当front==rear，且flag=0时为队列空，当front==rear，且flag=1时为队列满。
2. 办法二：当队列空时，条件就是front=rear，当队列满时，保留一个元素空间，如下图。也就是说，队列满时，数组中还有一个空闲单元，就认为此队列已经满了，即不允许上图右图情况出现.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cTDs8InbvQFpZiRE%2F87import.png?alt=media)

由于rear可能比front大，也可能比front小，若队列的最大尺寸为QueueSize，队列满的条件是:（取模“%”的目的就是为了整合rear与front大小为一个问题）。

`(rear+1)%QueueSize == front`

- 比如QueueSize=5，. `(4+1)%5=0`所以此时队列满。比如front=2而rear=1。`(1+1)%5=2`，此时队列也是满的。
- front=2而rear=0,`(0+1)%5=1`,1≠2。此时队列并没有满。
- 当rear>front时，队列的长度为rear-front。当rear<front时，队列长度分为两段，一段是QueueSize-front，另一段是0+rear，加在一起，队列长度为QueueSize-front+rear。因此通用的`计算队列长度公式`为：`(QueueSize-front+rear)%QueueSize`.

#### 代码实现

[SqQueueDemo3.cpp](./008_StackAndQueue/SqQueueDemo3.cpp)

##### 顺序存储结构代码

```C++
/* 循环队列的顺序存储结构 */
typedef struct
{
    QElemType data[MAXSIZE];
    int front;      /* 头指针 */
    int rear;       /* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
}SqQueue;
```

##### 初始化代码

```C++
/* 初始化一个空队列Q */
Status InitQueue(SqQueue *Q)
{
    Q->front=0;
    Q->rear=0;
    return  OK;
}
```

##### 队列长度代码

```C++
/* 返回Q的元素个数，也就是队列的当前长度 */
int QueueLength(SqQueue Q)
{
    return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
```

##### 入队代码

```C++
/* 若队列未满，则插入元素e为Q新的队尾元素 */
Status EnQueue(SqQueue *Q,QElemType e)
{
    if ((Q->rear+1)%MAXSIZE == Q->front)    /* 队列满的判断 */
        return ERROR;
    Q->data[Q->rear]=e;         /* 将元素e赋值给队尾 */
    Q->rear=(Q->rear+1)%MAXSIZE;/* rear指针向后移一位置， */
                                /* 若到最后则转到数组头部 */
    return  OK;
}
```

##### 出队代码

```C++
/* 若队列不空，则删除Q中队头元素，用e返回其值 */
Status DeQueue(SqQueue *Q,QElemType *e)
{
    if (Q->front == Q->rear)            /* 队列空的判断 */
        return ERROR;
    *e=Q->data[Q->front];               /* 将队头元素赋值给e */
    Q->front=(Q->front+1)%MAXSIZE;  /* front指针向后移一位置， */
                                    /* 若到最后则转到数组头部 */
    return  OK;
}
```

### 队列的链式存储结构

**队列的链式存储结构就是线性表的单链表，只不过它只能尾进头出，简称为链队列。**

将队头指针指向链队列的头结点，队尾指针指向终端结点。

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cSifLCyNbwZxtE8P%2F88import.png?alt=media)

空队列时，front和rear都指向头结点.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cSiluYPpTO67LJ4L%2F89import.png?alt=media)

[LinkQueueDemo4.cpp](./008_StackAndQueue/LinkQueueDemo4.cpp)

链队列的结构为：

```C++
/* QElemType类型根据实际情况而定，这里假设为int */
typedef int QElemType;

typedef struct QNode    /* 结点结构 */
{
    QElemType data;
    struct QNode *next;
} QNode,*QueuePtr;

typedef struct          /* 队列的链表结构 */
{
    QueuePtr front,rear; /* 队头、队尾指针 */
} LinkQueue;
```

#### 出队

出队操作时，就是头结点的后继结点出队，将头结点的后继改为它后面的结点，若链表除头结点外只剩一个元素时，则需将rear指向头结点.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cSipWc9eXKws9L6O%2F91import.png?alt=media)

```C++
/* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
Status DeQueue(LinkQueue *Q,QElemType *e)
{
    QueuePtr p;
    if(Q->front==Q->rear)
        return ERROR;
    p=Q->front->next;       /* 将欲删除的队头结点暂存给p，见图中1 */
    *e=p->data;             /* 将欲删除的队头结点的值赋值给e */
    Q->front->next=p->next;/* 将原队头结点的后继p->next赋值给头结点后继，见图中2 */
    if(Q->rear==p)      /* 若队头就是队尾，则删除后将rear指向头结点，见图中3 */
        Q->rear=Q->front;
    free(p);
    return OK;
}
```


#### 入队

入队操作时就是在链表尾部插入结点。

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cSin_BeMJp-a43_O%2F90import.png?alt=media)

```C++
/* 插入元素e为Q的新的队尾元素 */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
    if(!s) /* 存储分配失败 */
        exit(OVERFLOW);
    s->data=e;
    s->next=NULL;
    Q->rear->next=s;    /* 把拥有元素e的新结点s赋值给原队尾结点的后继，见图中1 */
    Q->rear=s;      /* 把当前的s设置为队尾结点，rear指向s，见图中2 */
    return OK;
}
```

### 循环队列与链队列：

1. 时间上，基本操作都为O(1)，不过循环队列是事先申请好空间，使用期间不释放，而对于链队列，每次申请和释放结点也会存在一些时间开销，如果入队出队频繁，则两者还是有细微差异。
2. 空间上，循环队列必须有一个固定的长度，所以就有了存储元素个数和空间浪费的问题。而链队列不存在这个问题，尽管它需要一个指针域，会产生一些空间上的开销，但也可以接受。所以在空间上，链队列更加灵活。
3. 在可以确定队列长度最大值的情况下，建议用循环队列，如果无法预估队列的长度时，则用链队列