# 图的存储结构

|[上一篇](./010_1_Graph.md)|[目录](./index.md)|[下一篇](./010_3_Graph.md)|
|:---:|:---:|:---:|
|[图的定义和抽象数据类型](./010_1_Graph.md)|[目录](./index.md)|[图的遍历](./010_3_Graph.md)|

从图的逻辑结构定义来看，图上任何一个顶点都可被看成是第一个顶点，任一顶点的邻接点之间也不存在次序关系.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cT-4B9WBs0LzforW%2Fimport.png7?alt=media)

## 邻接矩阵

**图的邻接矩阵（Adjacency Matrix）存储方式是用两个数组来表示图。一个一维数组存储图中顶点信息，一个二维数组（称为邻接矩阵）存储图中的边或弧的信息**

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cT-AaM-NvBZGBa_g%2Fimport.png0?alt=media)

有了这个矩阵，很容易知道图中的信息：

1. 判定任意两顶点是否有边无边
2. 要知道某个顶点的度，就是这个顶点在邻接矩阵中第i行（或第i列）的元素之和。
3. 求顶点的所有邻接点就是将矩阵中第i行元素扫描一遍，arc[i][j]为1就是邻接点

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cT-CDj_aDZl8QWta%2Fimport.pngq?alt=media)

因为是有向图，所以此矩阵并不对称（入度列之和，出度行之和）.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cT-Ed6JeqQW0w2xp%2Fimport.png13?alt=media)

网图的邻接矩阵（权为矩阵元素，无边为无穷）

## 邻接表

**数组与链表相结合的存储方法称为邻接表(Adjacency List)**

邻接表的处理办法：

1. 图中顶点用一个一维数组存储，对于顶点数组中，每个数据元素还需要存储指向第一个邻接点的指针，以便于查找该顶点的边信息
2. 图中每个顶点vi的所有邻接点构成一个线性表，由于邻接点的个数不定，所以用单链表存储，无向图称为顶点vi的边表，有向图则称为顶点vi作为弧尾的出边表

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cT-Gt2MuWdYdFfxU%2Fimport.png15?alt=media)

顶点表的各个结点由data 和 firstedge两个域表示，data是数据域，存储顶点的信息，firstedge是指针域，指向边表的第一个结点，即此结点的第一个邻接点

边表结点由adjvex和next 两个域组成，adjvex 是邻接点域，存储某顶点的邻接点在顶点表中的下标，next则存储指向边表中下一个结点的指针

要想知道某个顶点的度，就去查找这个顶点的边表中结点的个数。若要判断顶点vi到vj是否存在边，只需要测试顶点vi的边表中adjvex是否存在结点vj的下标j就行了。若求顶点的所有邻接点，其实就是对此顶点的边表进行遍历，得到的adjvex域对应的顶点就是邻接点

若是有向图，第一幅图的邻接表就是第二幅图。有向图由于有方向，是以顶点为弧尾来存储边表的，很容易得到每个顶点的出度。有时为了便于确定顶点的入度或以顶点为弧头的弧，可以建立一个有向图的逆邻接表，即对每个顶点vi都建立一个链接为vi为弧头的表

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cT-Iex2ciKyW3Bjj%2Fimport.png16?alt=media)

对于带权值的网图，可以在边表结点定义中再增加一个weight的数据域存储权值信息

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cT-KB8nury2R8xVj%2Fimport.png17?alt=media)

## 十字链表

**十字链表（Orthogonal List）：把邻接表和逆邻接表结合起来的存储方式**

重新定义顶点表结点结构如下:

data | firstin | firstout
---------|----------|---------
 数据或信息 | firstin表示入边表头指针，指向该顶点的入边表中第一个结点， | firstout表示出边表头指针，指向该顶点的出边表中的第一个结点

重新定义的边表结点结构如下：

tailvex | headvex | headlink | taillink
---------|----------|---------|---------

顶点依然是存入一个一维数组v0,v1,v2,v3，实线箭头指针的图示与邻接表相同。以顶点v0来说，firstout指向的是出边表中的第一个结点v3。所以边表结点的headvex=3，而tailvex其实就是当前顶点v0的下标0，由于v0只有一个出边顶点，所以headlink和taillink都是空

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cT-MzJCJFkU5gxUO%2Fimport.png20?alt=media)

## 邻接多重表

重新定义的边表结点结构如下：

ivex | ilink | jvex | jlink
---------|----------|---------|---------

    ivex和jvex是与某条边依附的两个顶点在顶点表中的下标。ilink指向依附顶点ivex的下一条边，jlink指向依附顶点jvex的下一条边。这就是邻接多重表结构

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cT-O06ZFkevK-80e%2Fimport.png21?alt=media)



![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cT-QgBfgkLAH09Ce%2F212import.png?alt=media)

## 边集数组

边集数组是由两个一维数组构成。一个是存储顶点的信息；另一个是存储边的信息，这个边数组每个数据元素由一条边的起点下标(begin)、终点下标(end)和权(weight)组成

定义的边数组结构如下所示：


begin | end | weight
---------|----------|---------
 存储起点下标 | 存储终点下标 | 存储权值

 ![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cT-SutFRP60ejZ-4%2Fimport.png23?alt=media)

边集数组关注的是边的集合，在边集数组中要查找一个顶点的度需要扫描整个边数组，效率并不高。因此它更适合对边依次进行处理的操作，而不适合对顶点相关的操作

|[上一篇](./010_1_Graph.md)|[目录](./index.md)|[下一篇](./010_3_Graph.md)|
|:---:|:---:|:---:|
|[图的定义和抽象数据类型](./010_1_Graph.md)|[目录](./index.md)|[图的遍历](./010_3_Graph.md)|