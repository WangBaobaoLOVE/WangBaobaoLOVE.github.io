# 最小生成树

|[上一篇](./010_3_Graph.md)|[目录](./index.md)|[下一篇](./010_5_Graph.md)|
|:---:|:---:|:---:|
|[图的遍历](./010_3_Graph.mdd)|[目录](./index.md)|[最短路径](./010_5_Graph.md)|

**最小成本，就是n个顶点，用n-1条边把一个连通图连接起来，并且使得权值的和最小**

**最小生成树：构造连通网的最小代价生成树**

其实实际解决的问题是，我想要去n个地方旅游，这n个地方都要去，并且不需要返回自己一开始出发的地方，但是呢，两个地点之间的路费或者路程是不一样的，那么怎么规划可以使得最后的路费或者路程最小呢。

## 普里姆（Prim）算法

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cPAWuCUeBH1n6VT6%2Fimport.png25?alt=media)

## 克鲁斯卡尔（Kruskal）算法

将邻接矩阵通过程序转化为右图的边集数组，并且对它们按权值从小到大排序

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cPAqJNLfZWZzcpXk%2Fimport.png31?alt=media)

|[上一篇](./010_3_Graph.md)|[目录](./index.md)|[下一篇](./010_5_Graph.md)|
|:---:|:---:|:---:|
|[图的遍历](./010_3_Graph.mdd)|[目录](./index.md)|[最短路径](./010_5_Graph.md)|
