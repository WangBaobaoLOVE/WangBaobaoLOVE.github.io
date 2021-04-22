#include <iostream>

using namespace std;

#define OK 1
#define ERROR 0

typedef bool Status;
typedef int Elemtype;

class QNode{
    public:
    Elemtype data;
    QNode *next;
};

class LinkQueue{
    private:
    QNode *front;
    QNode *rear;

    public:
    LinkQueue(void){
        front = new QNode;
        rear = front;
    }

    /* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
    Status DeQueue(Elemtype *e)
    {
        QNode *p;
        if(front==rear)
            return ERROR;
        p=front->next;       /* 将欲删除的队头结点暂存给p，见图中1 */
        *e=p->data;             /* 将欲删除的队头结点的值赋值给e */
        front->next=p->next;/* 将原队头结点的后继p->next赋值给头结点后继，见图中2 */
        if(rear==p)      /* 若队头就是队尾，则删除后将rear指向头结点，见图中3 */
            rear=front;
        free(p);
        return OK;
    }

    /* 插入元素e为Q的新的队尾元素 */
    Status EnQueue(Elemtype e)
    { 
        QNode *s = new QNode;
        if(!s) /* 存储分配失败 */
            return ERROR;
        s->data=e;
        s->next=NULL;
        rear->next=s;    /* 把拥有元素e的新结点s赋值给原队尾结点的后继，见图中1 */
        rear=s;      /* 把当前的s设置为队尾结点，rear指向s，见图中2 */
        return OK;
    }

    void DispQueue(){
        QNode *p;
        p = front->next;
        while(p!=rear){
            cout << p->data << '\t';
            p = p->next;
        }
        cout << p->data <<endl;
    }
};

int main(){
    LinkQueue L;

    for(int i=0; i<8; i++){
        L.EnQueue(i);
    }
    L.DispQueue();

    Elemtype *e;
    L.DeQueue(e);
    cout << *e << '\t';
    cout << endl;
    L.DispQueue();

    L.DeQueue(e);
    cout << *e << '\t';
    cout << endl;
    L.DispQueue();

    L.DeQueue(e);
    cout << *e << '\t';
    cout << endl;
    L.DispQueue();
    return 0;
}
