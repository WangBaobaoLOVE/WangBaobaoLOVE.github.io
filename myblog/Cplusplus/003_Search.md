# Search（搜索）


|[上一篇](./005_class.md)|[目录](./index.md)|[下一篇](007_linearList.md)|
|:---:|:---:|:---:|
|[类class****](./005_class.md)|[目录](./index.md)|[线性表数据结构](007_linearList.md)|


## Hash Table(哈希表/散列表)

- [案例程序(HashDemo1.c) Link](./003_Search/HashDemo1.c)
- [案例参考 Link](https://blog.csdn.net/sxhelijian/article/details/50084981)

## 顺序表查找

```C++
// 顺序查找
// a为数组，
// n为数组长度，
// key为要查找的关键字。
int Sequential_Search(int *a, int n, int key){
    int i;
    for(i=0; i<n; i++){
        if(a[i]==key)
            return i;
    }
    return -1;
}
```


```C++
// 顺序查找优化：哨兵顺序查找
// a为数组，
// n为数组长度，
// key为要查找的关键字。
int Sequential_Search(int *a, int n, int key){
    int i=n; 
    a[0] = key; // 设置a[0]为关键字值，称之为“哨兵”
    for(a[i]!=key){
        i--;
    }
    return i; // 返回0说明查找失败
}
```

## 有序表查找

### 折半查找/二分查找（Binary_Search）

![](http://latex.codecogs.com/gif.latex?\\mid = \frac{low+high}{2}=low+\frac{1}{2}(high-low))

### 插值查找（Interpolation Search）

插值查找是根据要查找的关键字key与查找表中的最大最小记录的关键字比较后的查找方法。跟二分查找的不同在于，根据前边的查找选择性的在某个区间先去查找，比如0~10000之间的100个元素，查找5，自然考虑从下标小的开始查找。

![](http://latex.codecogs.com/gif.latex?\\mid = low + \frac{key-a[low]}{a[high]-a[low]}(high-low))

对于表长较大，而关键字分布有比较均匀的查找表来说，插值查找算法的平均性能比二分查找要好的多。反之，如果分布极度不均匀的话，则未必合适。


### 斐波那契查找Fibonacci Search（黄金分割原理）

斐波那契数列：

|下标|0|1|2|3|4|5|6|7|8|9|10|
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|F|0|1|1|2|3|5|8|13|21|34|$\cdots$|

[FibonacciDemo.cpp](./003_Search/FibonacciDemo1.cpp)
```C++
int F[]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610};

int Fibonacci_Search(int *a, int n, int key){
    int low, high, mid, i, k;
    low =1; // 定义最低下标为记录首位
    high = n; // 定义最高下标为记录末位
    k=0;
    while(n>F[k]-1) // 计算n位于斐波那契数列的位置
        k++;
    for(i=n;i<F[k]-1;i++) // 将不满的数值补全
        a[i]=a[n];

    while(low<=high){
        mid=low+F[k-1]-1; // 计算当前分隔的下标
        if(key<a[mid]){ // 若查找记录小于当前分隔记录
            high=mid-1; // 最高下标调整到分隔下标mid-1处
            k=k-1; // 斐波那契数列下标减一位
        }
        else if(key>a[mid]){ //若查找记录大于当前分隔记录
            low=mid+1; // 最低下标调整到分隔下标mid+1处
            k=k-2;// 斐波那契数列下标减两位
        }
        else{
            if(mid<=n)
                return mid; // 若相等则说明mid即为查找到的位置
            else
                return n; // 若mid>n说明是补全数值，返回n
        }
    }
    return 0;
}
```

斐波那契查找的核心在于：
1. 当key=a[mid],查找成功；
2. 当key<a[mid], 新范围[low,mid-1],范围个数F[k-1]-1
3. 当key>a[mid], 新范围[mid+1,high],范围个数F[k-2]-1

## 线性索引查找

许多数据都是按照先后顺序存储的。——索引。

按照结构：
1. 线性索引（就是将索引项集合组织为线性结构，也称索引表。）
   1. 稠密索引
   2. 分块索引
   3. 倒排索引
2. 树形索引
3. 多级索引

### 稠密索引

**稠密索引是指在线性索引中，将数据集中的每个记录对应一个索引项。对于稠密索引这个索引表来说，索引项一定是按照关键码有序的排列。通俗的理解就是数据库中的一个字段，有顺序。** 稠密索引的索引项与数据集的记录个数相同，空间代价较大。

![稠密索引](https://oscimg.oschina.net/oscnet/up-2c238bb4b073d2258d5193983d113f1e167.png)

### 分块索引

**分块有序，就是把数据集分成了若干块（分门别类），并且这些快要满足两个条件：**
1. 块内无序：不要求有序，但是有序更好。
2. 块间有序：第二块的所有关键字大于第一块的所有关键字。

定义的分块索引的索引项结构分为**三个数据项**：
1. **最大关键字**：它存储每一块中的最大关键字，这样的好处就是可以使得在他之后的下一块中的最小关键字也能比这一块的最大关键字要大；
2. 存储了块中的记录个数，以便于循环时使用；
3. 用于指向块首数据元素的指针，便于开始对这一块中的记录进行遍历。

![分块索引](https://oscimg.oschina.net/oscnet/up-e088ceb5428e07f2865e846caba9dc52531.png)

### 倒排索引

![倒排索引](https://oscimg.oschina.net/oscnet/up-7238ba9237a1a87c7302a84a4eed9e59106.png)

索引项的通用结构是：
1. 次关键码：上面的关键词；
2. 记录号表：上面的文章编号。

## 二叉搜索/查找树（Binary Sort tree）

插入和删除效率不错，又可以比较高效地实现查找的算法。

![](https://img-blog.csdn.net/20180609163735594?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3UwMTEyMjE4MjA=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

1. 中序遍历：一个有序的序列。
2. 前序遍历：
3. 后序遍历：
4. 若他的左子树不空，则左子树上所有结点的值均小于他的根节点的值；
5. 若他的右子树不空，则右子树上所有结点的值均大于他的根节点的值；
6. 他的左右字数也分别为二叉排序树。

### 二叉排序树查找操作

二叉树结构
```C++
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
```

二叉排序树查找
```C++
// 递归查找二叉排序树T中是否存在key
// 指针f指向T的双亲，其初始调用值为NULL
// 若查找成功，则指针p指向该数据元素节点，并返回True
// 否则

```


|[上一篇](./005_class.md)|[目录](./index.md)|[下一篇](007_linearList.md)|
|:---:|:---:|:---:|
|[类class****](./005_class.md)|[目录](./index.md)|[线性表数据结构](007_linearList.md)|
