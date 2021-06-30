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
