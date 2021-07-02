# 图的定义和抽象数据类型

|[上一篇](./010_Graph.md)|[目录](./index.md)|[下一篇](./010_2_Graph.md)|
|:---:|:---:|:---:|
|[图（Graph）](./010_Graph.md)|[目录](./index.md)|[](./010_2_Graph.md)|

## 图的定义

**图（Graph）是由顶点的有穷非空集合和顶点之间边的集合组成，通常表示为：G(V,E)，其中G表示一个图，V是图G中顶点的集合，E是图G中边的集合.**

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cRt1lMxBtesMdYGt%2F150import.png?alt=media)

1. 线性表中数据元素叫元素，树中将数据元素叫结点，图中数据元素称之为顶点（Vertex）
2. 线性表中可以没有数据元素，称为空表。树中可以没有结点，叫做空树。在图结构中，不允许没有顶点。在定义中，若V是顶点的集合，则强调了顶点集合V有穷非空
3. 线性表中，相邻的数据元素之间具有线性关系，树结构中，相邻两层的结点具有层次关系，图中任意两个顶点之间都可能有关系，顶点之间的逻辑关系用边来表示，边集可以是空的

### 各种图定义

若顶点vi到vj之间的边没有方向，则称这条边为**无向边**（Edge），用**无序偶对(vi,vj)**来表示。如果图中任意两个顶点之间的边都是无向边，则称该图为**无向图（Undirected graphs）**.

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cRt3lYqfdR6nIYkn%2F151import.png?alt=media)

由于是无方向的，连接顶点A与D的边，可以表示成无序对(A,D)，也可以写成(D,A)

**对于无向图G1**：

1. ​G1=(V1,{E1})
2. 顶点集合V1={A,B,C,D}
3. 边集合E1={(A,B),(B,C),(C,D),(D,A),(A,C)}

若从顶点vi到vj的边有方向，则称这条边为**有向边**，也称为**弧（Arc）**。用**有序偶**<vi,vj>来表示，vi称为**弧尾（Tail）**，vj称为**弧头（Head）**。如果图中任意两个顶点之间的边都是有向边，则称该图为**有向图（Directed graphs）**

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cRt5321_J49kl9M1%2F152import.png?alt=media)

连接顶点A到D的有向边就是弧，A是弧尾，D是弧头，<A,D>表示弧，不能写成<D,A>

**对于有向图G2**：

1. G2 = (V2,{E2})
2. 顶点集合V2 = {A,B,C,D}
3. 弧集合E2 = {<A,D>,<B,A>,<C,A>,<B,C>}

无向边用小括号“()”表示，而有向边则是用尖括号“<>”表示

**在图中，若不存在顶点到其自身的边，且同一条边不重复出现，则称这样的图为简单图.**

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cRt7CynRsrGKTLC6%2F154import.png?alt=media)

**在无向图中，如果任意两个顶点之间都存在边，则称该图为无向完全图。**

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cRt978JKnPIz7QYD%2F155import.png?alt=media)

**在有向图中，如果任意两个顶点之间都存在方向互为相反的两条弧，则称该图为有向完全图。**

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cRtB3KlFhLKE-rMT%2F157import.png?alt=media)

**有很少条边或弧的图称为稀疏图，反之称为稠密图。**稀疏和稠密是模糊的概念，是相对而言的

有些图的边或弧具有与它相关的数字，这种与图的边或弧相关的数叫做权（Weight）。这些权可以表示从一个顶点到另一个顶点的距离或耗费。这种带权的图通常称为网（Network）

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cRtDvg1tMY4FOmrL%2F158import.png?alt=media)

### 图的顶点与边间关系

### 图的定义与术语总结

图按照有无方向分为无向图和有向图。无向图由顶点和边构成，有向图由顶点和弧构成。弧有弧尾和弧头之分

图按照边或弧的多少分稀疏图和稠密图。如果任意两个顶点之间都存在边叫完全图，有向的叫有向完全图。若无重复的边或顶点到自身的边则叫简单图

图中顶点之间有邻接点、依附的概念。无向图顶点的边数叫做度，有向图顶点分为入度和出度

图上的边或弧上带权则称为网

图中顶点间存在路径，两顶点存在路径则说明是连通的，如果路径最终回到起始点则称为环，当中不重复叫简单路径。若任意两顶点都是连通的，则图就是连通图，有向则称强连通图。图中有子图，若子图极大，连通则就是连通分量，有向的则称强连通分量

无向图中连通且n个顶点n-1条边叫生成树。有向图中一顶点入度为0其余顶点入度为1的叫有向树。一个有向图由若干棵有向树构成生成森林


## 图的抽象数据类型

```C++
ADT 图(Graph)  

Data  

    顶点的有穷非空集合和边的集合  

Operation  

    CreateGraph(*G,V,VR):按照顶点集合V和边弧集VR的定义构造图G。 

    DestroyGraph(*G):图G存在则销毁。  

    LocateVex(G,u):若图G中存在顶点u，则返回图中的位置。  

    GetVex(G,v):返回图G中顶点v的值。  

    PutVex(G,v,value):将图G中顶点v赋值value。  

    FirstAdjvex(G,*v):返回顶点v的一个邻接顶点，若顶点在G中无邻接顶点返回空。  

    NextAdjVex(G,v,*w):返回顶点v相对于顶点w的下一个邻接顶点，若w是v的最后一个邻接点则返回“空”。  

    InsertVex(*G,v):在图G中增添新顶点v.  

    DeleteVex(*G,v):删除图G中顶点v及其相关的弧。  

    InsertArc(*G,v,w):在图G中增添弧<v,w>,若G是无向图，还需要增添对称弧<w,v>。  

    DeleteArc(*G,v,w):在图G中删除弧<v,w>，若G是无向图，则还删除对称弧<w,v>。  

    DESTraverse(G):对图G中进行深度优先遍历，在遍历过程中对每个顶点调用。  

    HFSTraverse(G):对图G中进行广度优先遍历，在遍历过程中对每个顶点调用。  

endADT
```

|[上一篇](./010_Graph.md)|[目录](./index.md)|[下一篇](./010_2_Graph.md)|
|:---:|:---:|:---:|
|[图（Graph）](./010_Graph.md)|[目录](./index.md)|[](./010_2_Graph.md)|
