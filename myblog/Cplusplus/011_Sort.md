# Sort(排序算法)

|   [上一篇](./010_Graph.md)   | [目录](./index.md) | [下一篇]() |
| :--------------------------: | :----------------: | :--------: |
| [图（Graph)](./010_Graph.md) | [目录](./index.md) |    []()    |

- [Sort(排序算法)](#sort排序算法)
  - [排序算法概述](#排序算法概述)
    - [算法分类](#算法分类)
    - [算法复杂度](#算法复杂度)
  - [冒泡排序(Bubble Sort)](#冒泡排序bubble-sort)
    - [算法描述](#算法描述)
    - [动图演示](#动图演示)
    - [代码实现](#代码实现)
  - [简单选择排序（Selection Sort）](#简单选择排序selection-sort)
    - [算法描述](#算法描述-1)
    - [动图演示](#动图演示-1)
    - [代码实现](#代码实现-1)
  - [直接插入排序（Insertion Sort）](#直接插入排序insertion-sort)
    - [算法描述](#算法描述-2)
    - [动图演示](#动图演示-2)
    - [代码实现](#代码实现-2)
  - [希尔排序（Shell Sort）](#希尔排序shell-sort)
    - [算法描述](#算法描述-3)
    - [动图演示](#动图演示-3)
    - [代码实现](#代码实现-3)
  - [归并排序](#归并排序)
    - [算法描述](#算法描述-4)
    - [动图演示](#动图演示-4)
    - [代码实现](#代码实现-4)
    - [算法分析](#算法分析)
  - [快速排序（Quick Sort）](#快速排序quick-sort)
    - [算法描述](#算法描述-5)
    - [动图演示](#动图演示-5)
    - [代码实现](#代码实现-5)
  - [堆排序（Heap Sort）](#堆排序heap-sort)
    - [算法描述](#算法描述-6)
    - [动图演示](#动图演示-6)
    - [代码实现](#代码实现-6)
  - [计数排序（Counting Sort）](#计数排序counting-sort)
    - [算法描述](#算法描述-7)
    - [动图演示](#动图演示-7)
    - [代码实现](#代码实现-7)
  - [桶排序（Bucket Sort）](#桶排序bucket-sort)
    - [算法描述](#算法描述-8)
    - [动图演示](#动图演示-8)
    - [代码实现](#代码实现-8)
  - [基数排序（Radix Sort）](#基数排序radix-sort)
    - [算法描述](#算法描述-9)
    - [动图演示](#动图演示-9)
    - [代码实现](#代码实现-9)
  - [参考](#参考)
   
## 排序算法概述

### 算法分类

十种常见排序算法可以分为两大类：

- 比较类排序：通过比较来决定元素间的相对次序，由于其时间复杂度不能突破O(nlogn)，因此也称为非线性时间比较类排序。
- 非比较类排序：不通过比较来决定元素间的相对次序，它可以突破基于比较排序的时间下界，以线性时间运行，因此也称为线性时间非比较类排序。 

![alt](./images/011_001.png)

### 算法复杂度

![alt](./images/011_002.png)
 

## 冒泡排序(Bubble Sort)

冒泡排序是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。 

### 算法描述


- 比较相邻的元素。如果第一个比第二个大，就交换它们两个；
- 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
- 针对所有的元素重复以上的步骤，除了最后一个；
- 重复步骤1~3，直到排序完成。

### 动图演示

![alt](./images/011_003.gif)

### 代码实现

[bubble.cpp](./011_sort/001_bubble.cpp)

```C++
#include <iostream>

using namespace std;

int main(){
    int arr[] = {12,13,25,1,23,54,24,67,15,16,46};
    int len = sizeof(arr)/sizeof(int);

    for(int i = 0; i < len -1; i++){
        for (int j = 0; j < len - 1 - i; j++){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    for (int i = 0; i < len; i++){
        cout << arr[i] << '\t';
    }
    return 0;
}
```

## 简单选择排序（Selection Sort）

选择排序(Selection-sort)是一种简单直观的排序算法。它的工作原理：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。

### 算法描述

n个记录的直接选择排序可经过n-1趟直接选择排序得到有序结果。具体算法描述如下：

- 初始状态：无序区为R[1..n]，有序区为空；
- 第i趟排序(i=1,2,3…n-1)开始时，当前有序区和无序区分别为R[1..i-1]和R(i..n）。该趟排序从当前无序区中-选出关键字最小的记录 R[k]，将它与无序区的第1个记录R交换，使R[1..i]和R[i+1..n)分别变为记录个数增加1个的新有序区和记录个数减少1个的新无序区；
- n-1趟结束，数组有序化了。

### 动图演示

![](./images/011_004.gif)

### 代码实现

[Selection.cpp](./011_sort/002_Selection.cpp)

```C++
#include <iostream>

using namespace std;

int main(){
    int arr[] = {12,13,25,1,23,54,24,67,15,16,46};
    int len = sizeof(arr)/sizeof(int);

    for(int i = 0; i < len -1; i++){
        int minindex = i;
        for (int j = i; j < len; j++){
            if (arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        int tmp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = tmp;
    }

    for (int i = 0; i < len; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;

    for(int i = 0; i < len -1; i++){
        int maxindex = i;
        for (int j = i; j < len; j++){
            if (arr[j] > arr[maxindex]){
                maxindex = j;
            }
        }
        int tmp = arr[maxindex];
        arr[maxindex] = arr[i];
        arr[i] = tmp;
    }

    for (int i = 0; i < len; i++){
        cout << arr[i] << '\t';
    }
    return 0;
}
```

## 直接插入排序（Insertion Sort）

插入排序（Insertion-Sort）的算法描述是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。

### 算法描述

一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：

- 从第一个元素开始，该元素可以认为已经被排序；
- 取出下一个元素，在已经排序的元素序列中从后向前扫描；
- 如果该元素（已排序）大于新元素，将该元素移到下一位置；
- 重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
- 将新元素插入到该位置后；
- 重复步骤2~5。

### 动图演示

![alt](./images/011_005.gif)

### 代码实现

[insert.cpp](./011_sort/003_insert.cpp)

```C++
#include <iostream>

using namespace std;

int main(){
    int arr[] = {12,13,25,1,23,54,24,67,15,16,46};
    int len = sizeof(arr)/sizeof(int);

    for(int i = 1; i < len; i++){
        int insertvalue = arr[i];

        int j = i-1;
        for (; j > -1; j--){
            if (arr[j] > insertvalue){
                arr[j+1] = arr[j];
            }
            else{
                arr[j+1] = insertvalue; 
                break;
            }
        }
        if (j < 0) {arr[0] = insertvalue;}

    }

    for (int i = 0; i < len; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;
    return 0;
}
```

## 希尔排序（Shell Sort）

1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。

### 算法描述

先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，具体算法描述：

- 选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
- 按增量序列个数k，对序列进行k 趟排序；
- 每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。

### 动图演示

![alt](./images/011_006.gif)

### 代码实现

[shell.cpp](./011_sort/004_shell.cpp)

```C++
#include <iostream>

using namespace std;

int main(){
    int arr[] = {12,13,25,1,23,54,24,67,15,16,46};
    int len = sizeof(arr)/sizeof(int);
    
    for (int gap = len / 2; gap > 0; gap = gap / 2) {
        // 注意：这里和动图演示的不一样，动图是分组执行，实际操作是多个分组交替执行
        for (int i = gap; i < len; i++) {
            int j = i;
            int current = arr[i];
            while (j - gap >= 0 && current < arr[j - gap]) {
                 arr[j] = arr[j - gap];
                 j = j - gap;
            }
            arr[j] = current;
        }
    }

    for (int i = 0; i < len; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;
    return 0;
}
```

## 归并排序

归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为2-路归并。

### 算法描述

- 把长度为n的输入序列分成两个长度为n/2的子序列；
- 对这两个子序列分别采用归并排序；
- 将两个排序好的子序列合并成一个最终的排序序列。

### 动图演示

![alt](./images/011_007.gif)

### 代码实现

[merge.cpp](./011_sort/005_merge.cpp)

```C++
#include<iostream>
 
using namespace std;
 
void Merge(int arr[], int l, int q, int r){
    int n=r-l+1;//临时数组存合并后的有序序列
    int* tmp=new int[n];
    int i=0;
    int left=l;
    int right=q+1;
    while(left<=q && right<=r)
        tmp[i++] = arr[left]<= arr[right]?arr[left++]:arr[right++];
    while(left<=q)
        tmp[i++]=arr[left++];
    while(right<=r)
        tmp[i++]=arr[right++];
    for(int j=0;j<n;++j)
        arr[l+j]=tmp[j];
    delete [] tmp;//删掉堆区的内存
}
 
void MergeSort(int arr[], int l, int r){
    if(l==r)
        return;  //递归基是让数组中的每个数单独成为长度为1的区间
    int q = (l + r)/2;
    MergeSort(arr, l, q);
    MergeSort(arr, q + 1, r);
    Merge(arr, l, q, r);
}
 
int main(){
    int a[] = {12,13,25,1,23,54,24,67,15,16,46};
    int len = sizeof(a)/sizeof(int);
    MergeSort(a,0,len-1);
    for(int i=0;i<len;++i)
        cout<<a[i]<<" ";
}
```

### 算法分析

归并排序是一种稳定的排序方法。和选择排序一样，归并排序的性能不受输入数据的影响，但表现比选择排序好的多，因为始终都是O(nlogn）的时间复杂度。代价是需要额外的内存空间。

## 快速排序（Quick Sort）

快速排序的基本思想：通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序。

### 算法描述

快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法描述如下：

- 从数列中挑出一个元素，称为 “基准”（pivot）；
- 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
- 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。

### 动图演示

![alt](./images/011_008.gif)

### 代码实现

[quick.cpp](./011_sort/006_quick.cpp)

```C++
#include<iostream>
 
using namespace std;
 
int Parition(int a[], int low,int high){
    int pivot=a[high];
    int i=low;
    for(int j=low;j<high;++j)
    {
        //j指向当前遍历元素，如果大于等于pivot，继续向前
        //如果小于当前元素，则和i指向的元素交换
        if (a[j]<pivot) {
            swap(a[j], a[i]);
            i++;
        }
    }
    swap(a[i], a[high]);
    return i;
    
}
 
void QuickSort(int a[], int low, int high){
    if(low<high)
    {
        int q=Parition(a,low, high);
        QuickSort(a, low, q-1);
        QuickSort(a, q+1,high);
        
    }
    
}
 
int main(){
    int a[8] = {3,1,2,4,5,8,7,6};
    QuickSort(a,0,7);
    for(int i=0;i<8;++i)
        cout<<a[i]<<" ";
}
```


## 堆排序（Heap Sort）

堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。

### 算法描述

- 将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区；
- 将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),且满足R[1,2…n-1]<=R[n]；
- 由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,……Rn-1)调整为新堆，然后再次将R[1]与无序区最后一个元素交换，得到新的无序区(R1,R2….Rn-2)和新的有序区(Rn-1,Rn)。不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。

### 动图演示

![alt](./images/011_009.gif)

### 代码实现

## 计数排序（Counting Sort）

### 算法描述


### 动图演示

![alt](./images/011_010.gif)

### 代码实现

## 桶排序（Bucket Sort）

### 算法描述


### 动图演示

![alt](./images/011_011.png)

### 代码实现

## 基数排序（Radix Sort）

### 算法描述


### 动图演示

![alt](./images/011_012.gif)

### 代码实现

## 参考

1. [十大经典排序算法（动图演示）](https://www.cnblogs.com/onepixel/articles/7674659.html)
2. [C++ 归并排序与快速排序](https://blog.csdn.net/zpznba/article/details/83745205)

|   [上一篇](./010_Graph.md)   | [目录](./index.md) | [下一篇]() |
| :--------------------------: | :----------------: | :--------: |
| [图（Graph)](./010_Graph.md) | [目录](./index.md) |    []()    |