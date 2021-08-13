# 图的遍历

|[上一篇](./010_2_Graph.md)|[目录](./index.md)|[下一篇](./010_4_Graph.md)|
|:---:|:---:|:---:|
|[图的存储结构](./010_2_Graph.mdd)|[目录](./index.md)|[最小生成树](./010_4_Graph.md)|

**从图中的某一顶点出发，访遍图中其余顶点，且使每一顶点仅被访问一次，这一过程就叫做图的遍历(Traversing Graph)**

## 深度优先遍历

**深度优先遍历(Depth First Search)，也有称为深度优先搜索，简称为DFS。**类似于树的前序遍历

从图中某个顶点v出发，访问此顶点，然后从v的未被访问的邻接点出发深度优先遍历图，直至图中所有和v有路径相通的顶点都被访问到，以上说的只是连通图，对于非连通图，只需要对它的连通分量分别进行深度优先遍历，即在先前一个顶点进行一次深度优先遍历后，若图中尚有顶点未被访问，则另选图中一个未曾被访问的顶点作为起始点，重复上述过程，直至图中所有顶点都被访问到位置

## 广度优先遍历

**广度优先遍历(Breadth_First_Search)，又称为广度优先搜索，简称为BFS。**类似于树的层序遍历。

将第一幅图稍微变形，变形原则是顶点A放置在最上第一层，让与它有边的顶点B、F为第二层，再让与B和F有边的顶点C、I、G、E为第三层，再将这四个顶点有边的D、H放在第四层

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cOqEO3rMxf82uGbP%2Fimport.png24?alt=media)

|[上一篇](./010_2_Graph.md)|[目录](./index.md)|[下一篇](./010_4_Graph.md)|
|:---:|:---:|:---:|
|[图的存储结构](./010_2_Graph.mdd)|[目录](./index.md)|[最小生成树](./010_4_Graph.md)|