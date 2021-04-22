#include <iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef bool Status;
typedef int Elemtype;

class SqQueue{
    private:
    Elemtype data[MAXSIZE];
    int front;
    int rear;

    public:
    SqQueue(void){
        front = 0;
        rear = 0;
    }

    int QueueLength(){
        return (rear-front+MAXSIZE)%MAXSIZE;
    }

    Status EnQueue(Elemtype e){
        if((rear+1)%MAXSIZE == front)
            return ERROR;

        data[rear] = e;
        rear = (rear+1)%MAXSIZE;
        return OK;
    }

    Status DeQueue(Elemtype *e){
        if(front == rear)
            return ERROR;

        *e = data[front];
        front = (front+1)%MAXSIZE;
        return OK;
    }
};


int main(){
    SqQueue L;
    cout << L.QueueLength() << endl;

    for(int i=0; i<5; i++)
        L.EnQueue(i);
    cout << L.QueueLength() << endl;

    Elemtype e;
    for(int i=0; i<5; i++){
        L.DeQueue(&e);
        cout << "出栈：" << e << endl;
        cout << L.QueueLength() << endl;
    }
    return 0;
}