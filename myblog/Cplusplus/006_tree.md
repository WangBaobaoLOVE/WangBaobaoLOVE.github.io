# Tree(树)

|[上一篇](./009_String.md)|[目录](./index.md)|[下一篇](./010_Graph.md)|
|:---:|:---:|:---:|
|[串](./009_String.md)|[目录](./index.md)|[图（Graph)](./010_Graph.md)|

## 树的定义

树（Tree）是n（n≥0）个结点的有限集。n=0时称为空树。在任意一棵非空树中：（1）有且仅有一个特定的称为根（Root）的结点；（2）当n＞1时，其余结点可分为m（m＞0）个互不相交的有限集T1、T2、……、Tm，其中每一个集合本身又是一棵树，并且称为根的子树（SubTree）。

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cRGQ0I6kJxMqVxe4%2F108import.png?alt=media)

子树T1和子树T2就是根结点A的子树。D、G、H、I组成的树又是B为根结点的子树，E、J组成的树是以C为根结点的子树。

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cRGSn0KlNhV1nxfF%2F109import.png?alt=media)

树的定义还需要强调两点：

1. n>0时根结点是唯一的，不可能存在多个根结点，
2. m>0时，子树的个数没有限制，但它们一定是互不相交的。下图中的两个结构就不符合树的定义，因为它们都有相交的子树

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cRGUor5hlAjt4hZS%2F110import.png?alt=media)


### 结点分类

树的结点包含一个数据元素及若干指向其子树的分支。结点拥有的子树数称为结点的度（Degree）。度为0的结点称为叶结点（Leaf）或终端结点；度不为0的结点称为非终端结点或分支结点。除根结点之外，分支结点也称为内部结点。树的度是树内各结点的度的最大值。

![](https://img-blog.csdnimg.cn/20190226104545845.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTI2MjQ1Mw==,size_16,color_FFFFFF,t_70)

### 结点间关系

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cRGY6-DnT0gMXVcG%2F112import.png?alt=media)


### 树的其他相关概念

![](https://img-blog.csdnimg.cn/20190226104156841.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTI2MjQ1Mw==,size_16,color_FFFFFF,t_70)

### 总结

1. 节点的度：一个节点含有的子树的个数称为该节点的度，树的度是树内各节点的度的最大值
2. 叶节点或终端节点：度为零的节点称为叶节点；
3. 非终端节点或分支节点：度不为零的节点；
4. 双亲节点或父节点：若一个结点含有子节点，则这个节点称为其子节点的父节点；
5. 孩子节点或子节点：一个节点含有的子树的根节点称为该节点的子节点；
6. 兄弟节点：具有相同父节点的节点互称为兄弟节点；
7. 树的高度或深度：定义一棵树的根结点层次为1，其他节点的层次是其父结点层次加1。一棵树中所有结点的层次的最大值称为这棵树的深度。
8. 节点的层次：从根开始定义起，根为第1层，根的子结点为第2层，以此类推；
9. 树的度：一棵树中，最大的节点的度称为树的度；
10. 节点的祖先：从根到该节点所经分支上的所有节点；
11. 子孙：以某节点为根的子树中任一节点都称为该节点的子孙。
12. 森林：由m（m>=0）棵互不相交的树的集合称为森林；

## 树的抽象数据类型[Link](https://baozoulin.gitbook.io/-data-structure/di-6-zhang-shu/62shu-de-chou-xiang-shu-ju-lei-xing)

```
ADT 树 (tree)
Data:
      树是由一个根结点和若干棵子数构成.树中结点具有相同数据类型及层次关系
 Operation:
        InitTree (*T):构成空树T
        DestroyTree(*T):销毁树T
        CreateTree(*T,definition):按definition中给出的树的定义来构造树
        ClearTree(*T):若树T存在,则将树T请为空树
        TreeEmpty(T):若T为空树,返回true,否则返回false
        TreeDepth(T):返回T的深度
        Root(T):返回T的根结点
        Value(T,cur_e):cur_e是树T中一个结点,返回此结点的值
        Assign(T,cur_e,value):给树T的结点cur_e赋值为value
        Parent(T,cur_e):若cur_e是树T的非根结点,返回它的双亲,否则返回空
        LeftChild(T,cur_e):若cur_e是树T的非叶节点,则返回它的最左孩子,否则返回空
        RightSibling(T,cur_e):若cur_e有右兄弟,则返回他的右兄弟,否则返回空
        InsertChild(*T,*p,i,c):其中p指向树T的某个结点,T为所指结点p的度加上1,非空树c与T不相交,操作结果为插入c为树T中p所指结点的第i棵子树
        DeleteChile(*T,*p,i):其中p指向树T的某个结点,i为所指结点p的度,操作结果为删除T中p所指结点的第i棵子树
endADT   
```

## 树的存储结构

### 双亲表示法

假设以一组连续空间存储树的结点，同时在每个结点中，附设一个指示器指示其双亲结点在数组中的位置。每个结点除了知道自己是谁以外，还知道它的双亲在哪里。

|data|parent|
|:---:|:---:|
|数据域，存储结点的数据信息|指针域，存储该结点的双亲在数组中的下标|

```C++
//树的双亲表示法结点结构定义
#define MAX_TREE_SIZE 100
typedef int TElemType;   //树结点的数据类型,目前暂定义为整型
typedef struct PTNode   //结点结构
{
      TElemType data;     //结点数据
      int parent;               //双亲位置
}PTNode;
typedef struct                 //树结构
{
      PTNode nodes[MAX_TREE_SIZE];     //结点数组
      int r,n;                     //根的位置和结点数
}PTree;
```

**由于根结点是没有双亲的,约定根结点的位置域设置为-1,这就意味着所有的结点都存在他的双亲结点.**

![](https://blobscdn.gitbook.com/v0/b/gitbook-28427.appspot.com/o/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbCXcTyzPe3jWspDkf%2F-LmbCj1OluN7qtanzUon%2F851071-8c15b75546c75a60.png?alt=media&token=3fc698bf-d94f-4c56-8241-a34e8bcd93ae)


### 孩子表示法

### 孩子兄弟表示法

## 二叉树

### 定义

**二叉树是n(n>=0)个结点的有限集合,该集合或者为空集(称为空二叉树),或者由一个根结点和两棵互不相交的,分别称为根结点的左子树和右子树的二叉树组成。**

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbT8gPxtw_PzE-yAWU%2F-LmbTTgmAKk1P5NDI0OJ%2F851071-2cf0898d8befcaf6.png?alt=media&token=14cfe5cf-e2bb-4f96-be08-a829c6ec9059)

### 二叉树特点

1. 每个结点最多有两颗子树,所以二叉树不存在度大于2的结点
2. 左子树和右子树是有顺序的,次序不能任意颠倒
3. 即使树中某结点只有一颗子树,也要区分左子树和右子树的 

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbT8gPxtw_PzE-yAWU%2F-LmbTZJPhBp-z6e9gnUp%2F851071-44a8eb0d9731cb36.png?alt=media&token=822c9db3-831e-421d-ac0c-0744f6bbaa2d)

**二叉树的五种基本形态：**

1. 空二叉树
2. 只有一个根结点
3. 根结点只有左子树
4. 根结点只有右子树
5. 树既有左子树也有右子树

只从形态上考虑，三个结点的树只有两种情况，图中有两层的树1和有三层的后四种的任意一种，对于二叉树来说，由于要区分左右，就演变成五种形态，树2、树3、树4和树5分别代表不同的二叉树

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cSOC5bPWmYv95nBk%2F117import.png?alt=media)

### 特殊二叉树

#### 斜树

斜树一定是斜的,所有的结点都只有左子树的二叉树叫左斜树.所有的二叉树只有右子数的树叉树叫右斜树.两者统称为斜树。斜树每一层都只有一个结点,结点的个数跟二叉树的深度相同.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbT8gPxtw_PzE-yAWU%2F-LmbThLcMRKJO8CDTIWe%2F851071-91b069343b92d9b9.png?alt=media&token=88273c4d-df3e-488f-9130-18dafc20e679)

**线性表就是特殊的二叉树**

#### 满二叉树

**在一棵二叉树中,如果所有分支结点都存在左子树和右子树,并且所有叶子都在同一层上,这样的二叉树称为满二叉树**

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbT8gPxtw_PzE-yAWU%2F-LmbTna3AGgvH1mYdi-4%2F851071-bcb35fe4316cb8ce.png?alt=media&token=1b08f0b6-b56d-4a09-a1f7-be1c86fb5719)

**满二叉树的特点:**

1. 叶子只能出现在最下一层,出现在其他层就不可能达到平衡
2. 非叶子结点的度一定是2
3. 在同样深度的二叉树中,满二叉树的结点个数最多,叶子树最多

#### 完全二叉树

对一棵具有n个结点的二叉树按层序编号,如果编号为i(1<= i<=n)的结点与同样深度的满二叉树中编号为i的结点在二叉树中位置完全相同,则这棵二叉树树完全二叉树

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbT8gPxtw_PzE-yAWU%2F-LmbTsD7qGx3lVpDmcr0%2F851071-14d589a906b5540d.png?alt=media&token=c7a1168d-7ac7-4022-a7a1-0fe2ea6aa699)

**尽管不是满二叉树，但是编号是连续的，所以它是完全二叉树**

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbT8gPxtw_PzE-yAWU%2F-LmbTvrzhzJZyR3NNGvy%2F851071-1f5b091daf8fca83.png?alt=media&token=178781ae-1d36-438d-8568-3bb416e7bf4c)

**满二叉树一定是完全二叉树,而完全二叉树不一定是满二叉树**

**完全二叉树的特点:**

1. 叶子结点只能出现在最下两层
2. 最下层的叶子一定集中在左部连续位置
3. 倒数两层,若有叶子结点,一定都在右部连续位置
4. 若结点度为1,则该结点只有左孩子,即不存在只有右子树的情况
5. 同样结点数的二叉树,完全二叉树的深度最小

## 二叉树的性质

### 性质1

在二叉树的第i层上至多有个结点`pow(2,i-1)`,其中(i>=1)

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbU6rMnKwg7jluyImX%2F-LmbUAqPCR0fVc3YiQxx%2F851071-4d867eb9ed8033c0.png?alt=media&token=0571873c-2b29-4033-b018-b5c31c2e67e2)

### 性质2

深度为k的二叉树至多有`pow(2,k)-1`个结点(k>=1)

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbU6rMnKwg7jluyImX%2F-LmbUEDWOnKwyvpZkZup%2F851071-8e27a12ccaa011ca.png?alt=media&token=a969b827-e1d3-4e11-860c-345fb3e86106)

### 性质3

对任何一棵二叉树T,如果其终端结点数(叶子结点数)为`n0`,度为2的结点数为`n2`,则`n0=n2+1`.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbU6rMnKwg7jluyImX%2F-LmbUU2UF1ChHiYQ4vqZ%2F851071-816bc979d99483e3.png?alt=media&token=98ea7601-f1c9-4f6e-9b92-c4a564ff5755)

## 二叉树的存储结构

### 二叉树顺序存储结构

二叉树的顺序结构是用一维数组存储二叉树中的结点,并且结点的存储位置,也就是数组的下标要能体现结点之间的逻辑关系,比如双亲与孩子的关系,左右兄弟的关系。

#### 完全二叉树的存储

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbUdI_QEyIAke9L0DF%2F-LmbUnDEw59HlZK4ul6a%2F851071-97ccc7664ad183dd.png?alt=media&token=81919906-36cc-45ab-a4f6-c03249500d20)

将这棵二叉树存入到数组中,相应的下标对应其同样的位置:

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbUdI_QEyIAke9L0DF%2F-LmbUr0gWPxMjaouk_fk%2F851071-9efb4e954ffa3849.png?alt=media&token=c147b8f5-fdc9-42ed-aa55-b653c6659dca)

完全二叉树存入到数组中,相应的下标对应其同样的位置,一般的二叉树层序编号不能反映逻辑关系,但可以将其按完全二叉树编号,把不存在的结点设置为"^".

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbUdI_QEyIAke9L0DF%2F-LmbUv3MUJge70uC2weo%2F851071-96331e5db062f0e5.png?alt=media&token=0fb40a2c-46c7-4fb9-832f-63934d41c6b1)

一种极端的情况,一棵深度为k的右斜树,它只有k个结点,却需要分配`pow(2,k)-1`个存储单元,会造成对空间的极度浪费,所以顺序结构一般只用于完全二叉树.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbUdI_QEyIAke9L0DF%2F-LmbV-hEd7_sfOWigavv%2F851071-c86f656c2c0f6952.png?alt=media&token=ebffacf7-5c50-4344-bc71-b9ebdaee5b97)

### 二叉链表

**二叉树每个结点最多有两个孩子,设计一个数据域和两个指针域,这样的链表为二叉链表**

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-LmbUdI_QEyIAke9L0DF%2F-LmbV5NWR-zTHKDmbqHp%2F851071-919f592cedfa2143.png?alt=media&token=65cd1bb6-d0d4-4c97-9042-630feaa6f865)

二叉链表的结点结构定义代码：

```C++
/* 二叉树的二叉链表结点结构定义 */
typedef struct BiTNode        /* 结点结构 */    
{        
    TElemType data;           /* 结点数据 */                      
    struct BiTNode *lchild, *rchild; /* 左右孩子指针 */    
} BiTNode, *BiTree;
```

结构示意图如图：

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cPr9dPEsFI2hzuZS%2F119import.png?alt=media)

## 遍历二叉树

**二叉树的遍历是指从根结点出发,按照某种次序依次访问二叉树中所有结点,使得某个结点被访问一次且仅被访问一次**

### 二叉树遍历方法

#### 前序遍历

若二叉树为空,则空操作返回,否则

1. 先访问根结点
2. 前序遍历左子树,
3. 前序遍历右子树.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cShbfqxC1Ro-cU5n%2F120import.png?alt=media)

```C++
/*二叉树的前序遍历递归算法*/
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)            //若树为空，返回为空
            return;
    printf("%c",T->data); //显示结点数据，可以更改为其它对结点操作   
    PreOrderTraverse(T->lchild);    //再先序遍历左子树
    PreOrderTraverse(T->rchild);    //最后先序遍历右子树
}
```

#### 中序遍历

若树为空,则空操作返回,否则

1. 从根结点开始(注意不是先访问根结点)
2. 中序遍历根结点的左子树,然后是访问根结点
3. 中序遍历右子树

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cShfVPOPFc5jTAzi%2F121import.png?alt=media)

```C++
/*二叉树的中序遍历递归算法*/
void InOrderTraverse(BiTree T)
{
    if(T == NULL)
            return;
    InOrderTraverse(T->lchild);    //中序遍历左子树
    printf("%c",T->data);                //显示结点数据，能够更改为其它对结点操作
    InOrderTraverse(T->rchild);    //最后中序遍历右子树
}
```

#### 后序遍历

若树为空,则空操作返回，否则

1. 从左到右先叶子后结点的方式遍历访问左右子树
2. 最后是访问根结点.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cShjm857lQQG_Fmq%2F122import.png?alt=media)

```C++
/*二叉树的后序遍历递归算法*/
void PostOrderTraverse(BiTree T)
{
    if(T==NULL)
            return;
   PostOrderTraverse(T->lchild);//先后序遍历左子树
   PostOrderTraverse(T->rchild);//再后序遍历右子树
   printf("%c",T->data);                //显示结点数据。能够更改为其它对结点操作  
}
```

#### 层序遍历

若树为空,则空操作返回，否则

1. 从树的第一层,也就是根结点开始访问
2. 从上而下逐层遍历
3. 在同一层中,按从左到右的顺序对结点逐个访问

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cShl6tSsJvn-mUdG%2F123import.png?alt=media)

#### 推导遍历结果

二叉树遍历性质：

1. 已知前序遍历序列和中序遍历序列，能够唯一确定一颗二叉树;
2. 已知后序遍历序列和中序遍历序列。能够唯一确定一颗二叉树;
3. 已知前序和后序遍历，不能确定一棵二叉树

## 二叉树的建立

对于一颗普通的二叉树，将二叉树中每一个结点的空指针引出一个虚结点，其值为一特定值，比方"#"。处理后的二叉树为原二叉树的扩展二叉树，扩展二叉树能够通过一个"前序"或"中序"或"后序"遍历序列确定一颗二叉树

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cSa7bWC4JSweAju6%2Fimport.png120?alt=media)

[BiTreeDemo1.cpp](./006_Tree/BiTreeDemo1.cpp)
```C++
/*按前序输入而二叉树中借点的值(一个字符)*/    
/*#表示空树，构造二叉链表表示二叉树T*/
void CreateBitree(Bitree *T)
{
    TElemType ch;
    scanf("%c",&ch);        //输入结点数据字符
    if(ch=='#')                    
            *T=NULL;
    else
     {
            *T=(BiTree)malloc(sizeof(BiTNode));    //为数据为字符的结点在内存中分配空间
            if(!*T)                                                    //假设分配未成功则异常结束(内存溢出)
                    exit(OVERFLOW);
            (*T)->data = ch;                                    //生成根结点
            CreateBiTree(&(*T)->lchild);                //构造左子树
            CreateBiiTree(&(*T)->rchild);                //构造右子树
    }
}
```

|[上一篇](./009_String.md)|[目录](./index.md)|[下一篇](./010_Graph.md)|
|:---:|:---:|:---:|
|[串](./009_String.md)|[目录](./index.md)|[图（Graph)](./010_Graph.md)|