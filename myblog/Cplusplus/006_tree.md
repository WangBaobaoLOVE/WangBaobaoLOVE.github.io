# Tree(树)

## 树的定义

![](https://img-blog.csdnimg.cn/20190226104545845.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTI2MjQ1Mw==,size_16,color_FFFFFF,t_70)
![](https://img-blog.csdnimg.cn/20190226104156841.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MTI2MjQ1Mw==,size_16,color_FFFFFF,t_70)

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



### 孩子表示法

### 孩子兄弟表示法