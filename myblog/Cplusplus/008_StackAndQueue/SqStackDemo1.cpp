#include <iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef bool Status;
typedef int Elemtype;

// typedef struct{
//     Elemtype data[MAXSIZE];
//     int top;
//     int length;
// } SqStackList;

class SqStackList{
    private:
    Elemtype data[MAXSIZE];
    int top=-1;
    int length=0;

    public:
    SqStackList(void){
        top = -1;
        length = 0;
    }

    SqStackList(Elemtype *a, int num){
        for(int i=0; i<num; i++){
            top++;
            data[top] = a[i];
            length++;
        }
    }

    void DispStack(){
        int ptop = top;
        while(ptop!=-1){
            cout << data[ptop] << '\t';
            ptop--;
        }
        cout << endl;
    }

    Status push(Elemtype e){
        if(length==MAXSIZE)
            return ERROR;

        top++;
        data[top] = e;
        length++;
        return OK;
    }

    Status pop(Elemtype *e){
        if(top==-1)
            return ERROR;
        *e = data[top];
        top--;
        length--;
        return OK;
    }

    int GetLength(){
        return length;
    }
};


int main(){
    SqStackList L;
    Elemtype x[] = {0,1,2,3,4,5,6};
    SqStackList L2(x, sizeof(x)/sizeof(Elemtype));
    cout << L2.GetLength() << endl;
    L2.DispStack();

    L2.push(4);
    cout << L2.GetLength() << endl;
    L2.DispStack();

    Elemtype e;
    L2.pop(&e);
    cout << L2.GetLength() << endl;
    cout << e << endl;
    L2.DispStack();

    L2.pop(&e);
    cout << L2.GetLength() << endl;
    cout << e << endl;
    L2.DispStack();
    return 0;
}