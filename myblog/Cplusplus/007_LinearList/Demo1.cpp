#include <iostream>

using namespace std;

#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int ElemType;   /* ElemType类型根据实际情况而定，这里假设为int */

#define OK 1
#define ERROR 0

typedef int Status;

typedef struct
{
	ElemType data[MAXSIZE]; /* 数组，存储数据元素 */
	int length;             /* 线性表当前长度 */
}SqList;

Status InitList(SqList *L) // 初始化
{
    L->length=0;
    return OK;
}

int addList(SqList *L, int elem){ // 插入一个元素，并返回插入的索引位置
    if(L->length==MAXSIZE){ 
        cout << "线性表已满";
        return -1;
    }
    L->data[L->length]=elem;
    L->length = L->length+1;
    return L->length-1;
}
 
Status ClearList(SqList *L){  //清空
    if(L->length==0){
        cout << "已经是空表" << endl;
        return ERROR;
    }
    L->length = 0;
    return OK;
}

Status Getelem(SqList *L, int i, ElemType *e){ // 获得某个元素
    if(L->length==0 || i<1 || i>L->length)
        return ERROR;
    *e = L->data[i-1];
    return OK;
}

int main(){
    SqList L;
    cout << "初始化："<< InitList(&L) << endl;
    for(int i=0; i<MAXSIZE+1; i++){
        cout << "当前线性表长度："<< L.length << endl;
        cout << "插入一个元素的索引：" << addList(&L, i) << endl;
        cout << "当前线性表长度："<< L.length << endl;
    }
    cout << "清空线性表：" << ClearList(&L) << endl;
    cout << "当前线性表长度："<< L.length << endl;

    for(int i=0; i<MAXSIZE+1; i++){
        cout << "当前线性表长度："<< L.length << endl;
        cout << "插入一个元素的索引：" << addList(&L, i) << endl;
        cout << "当前线性表长度："<< L.length << endl;
    }

    ElemType e;
    Getelem(&L, 5, &e);
    cout << e << endl;
    return 0;
}