#include <iostream>

typedef int Status;

using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status CreatBST(BiTree T, int key){
    if(!T->data){
        T->data=key;
        return true;
    }
    else if(key==T->data){
        return false;
    }
    else if(key>T->data){
        return CreatBST(T->rchild, key);
    }
    else{
        return CreatBST(T->lchild, key);
    }
}
// 递归查找二叉排序树T中是否存在key
// 指针f指向T的双亲，其初始调用值为NULL
// 若查找成功，则指针p指向该数据元素节点，并返回True
// 否则指针p指向查找路径上访问的最后一个结点并返回False
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p){
    if(!T){
        *p=f;
        return false;
    }
    else if(key==T->data){
        *p=T;
        return true;
    }
    else if(key<T->data){
        return SearchBST(T->lchild, key, T, p);
    }
    else{
        return SearchBST(T->rchild, key, T, p);
    }
}

void DispBST(BiTree T){
    if(T->lchild)
        DispBST(T->lchild);
    cout << T->data;
    if(T->rchild)
        DispBST(T->rchild);
}


int main(){
    int x[]={62,58,88,47,73,99,35,51,93,37};
    BiTree root;
    for(int i=0; i<sizeof(x)/sizeof(int);i++){
        CreatBST(root, x[i]);
    }
    DispBST(root);
    cout << *x <<endl;
    cout << sizeof(x)/sizeof(int) << endl;
    return 0;
}