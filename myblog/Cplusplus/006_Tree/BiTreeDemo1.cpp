#include <iostream>

using namespace std;

#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int ElemType;   /* ElemType类型根据实际情况而定，这里假设为int */

#define OK 1
#define ERROR 0

typedef int Status;

class BiNode{
    public:
    ElemType data;
    BiNode *lchild;
    BiNode *rchild;

    BiNode(void){
        lchild = NULL;
        rchild = NULL;
    }
};

class BiTree{
    private:
    BiNode *root;
    int length;

    public:
    BiTree(void){
        root = NULL;
        length = 0;
    }

    BiTree(ElemType *a, int num){
        root = NULL;
        length = 0;
        for(int i=0; i<num; i++){
            AddNode(a[i]);
        }
    }

    Status AddNode(ElemType e){
        BiNode *p = new BiNode;
        p->data = e;
        if(root==NULL){
            root = p;
            length++;
            return OK;
        }

        BiNode *q = root;
        while(true){
            if(e<q->data){
                if(q->lchild==NULL){
                    q->lchild = p;
                    length++;
                    return OK;
                }
                else{
                    q = q->lchild;
                    continue;
                }
            }else if(e>q->data){
                if(q->rchild==NULL){
                    q->rchild = p;
                    length++;
                    return OK;
                }
                else{
                    q = q->rchild;
                    continue;
                }
            }else{
                return ERROR;
            }
        }
    }

    BiNode * GetRoot(){
        return root;
    }

    int GetLength(){
        return length;
    }

    void PreTraversal(BiNode *r){
        if(r!=NULL){
            cout << r->data;
            PreTraversal(r->lchild);
            PreTraversal(r->rchild);
        }
    }

    
    void MidTraversal(BiNode *r){
        if(r!=NULL){
            MidTraversal(r->lchild);
            cout << r->data;
            MidTraversal(r->rchild);
        }
    }

    void LapTraversal(BiNode *r){
        if(r!=NULL){
            LapTraversal(r->lchild);
            LapTraversal(r->rchild);
            cout << r->data;
        }
    }
    
};

int main(){
    BiTree b;
    b.AddNode(5);
    b.AddNode(6);
    b.AddNode(4);
    b.AddNode(3);
    b.AddNode(49);
    // for(int i=0; i<5; i++){
    //     b.AddNode(i);
    // }


    ElemType x[]={5,3,4,2,7,6,8};
    BiTree c(x,sizeof(x)/sizeof(ElemType));
    c.PreTraversal(c.GetRoot());
    cout << endl;
    c.MidTraversal(c.GetRoot());
    cout << endl;
    c.LapTraversal(c.GetRoot());
    cout << endl;

    cout << c.GetLength() << endl;
    return 0;
}