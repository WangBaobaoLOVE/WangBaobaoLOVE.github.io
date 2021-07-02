# 最短路径

|[上一篇](./010_4_Graph.md)|[目录](./index.md)|[下一篇](./010_6_Graph.md)|
|:---:|:---:|:---:|
|[最小生成树](./010_4_Graph.mdd)|[目录](./index.md)|[拓扑排序](./010_6_Graph.md)|

非网图的最短路径，是指两顶点之间经过的边数最少的路径；网图的最短路径是指两顶点之间经过的边上权值之和最少的路径，并且称路径上的第一个顶点是源点，最后一个顶点是终点。就地图来说，距离就是两顶点间的权值之和。非网图可以理解为所有的边的权值都为1的网

## 迪杰斯特拉（Dijkstra）算法

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cOBOyu2Idom164Ty%2Fimport.png50?alt=media)

## 弗洛伊德（Floyd）算法

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cOBh0X2wNB5y7xhT%2Fimport.png59?alt=media)

|[上一篇](./010_4_Graph.md)|[目录](./index.md)|[下一篇](./010_6_Graph.md)|
|:---:|:---:|:---:|
|[最小生成树](./010_4_Graph.mdd)|[目录](./index.md)|[拓扑排序](./010_6_Graph.md)|