#include <iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef bool Status;
typedef int Elemtype;

class SqDoubleStack{
    private:
    Elemtype data[MAXSIZE];
    int top1=-1;
    int top2=MAXSIZE;
    int length=0;

    public:

    /* 插入元素e为新的栈顶元素 */
    Status Push(Elemtype e, int stackNumber)
    {    
        /* 栈已满，不能再push新元素了 */    
        if (top1 + 1 == top2)            
            return ERROR;    
        /* 栈1有元素进栈 */    
        if (stackNumber == 1){
            /* 若栈1则先top1+1后给数组元素赋值 */     
            top1++;   
            data[top1] = e;   
        }                  
        /* 栈2有元素进栈 */    
        else if (stackNumber == 2)
        {
            /* 若栈2则先top2-1后给数组元素赋值 */   
            top2--;     
            data[top2] = e;   
        }             
        else{
            return ERROR;
        }
        length++;     
        return OK;
    }

    /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
    Status Pop(Elemtype *e,int stackNumber)
    { 
        if (stackNumber==1) 
        {
            if (top1==-1) 
                return ERROR; /* 说明栈1已经是空栈，溢出 */
            *e=data[top1--]; /* 将栈1的栈顶元素出栈 */
        }
        else if (stackNumber==2)
        { 
            if (top2==MAXSIZE) 
                return ERROR; /* 说明栈2已经是空栈，溢出 */
            *e=data[top2++]; /* 将栈2的栈顶元素出栈 */
        }
        else{
            return ERROR;
        }
        length--;
        return OK;
    }

    void DispStack(){
        int ptop = top1;
        cout << "栈1：";
        while(ptop!=-1){
            cout << data[ptop] << '\t';
            ptop--;
        }
        cout << endl;

        ptop = top2;
        cout << "栈2：";
        while(ptop!=MAXSIZE){
            cout << data[ptop] << '\t';
            ptop++;
        }
        cout << endl;
    }

    int GetLength(){
        return length;
    }
};

int main(){
    SqDoubleStack L;
    L.Push(5, 1);
    L.DispStack();
    cout << L.GetLength() << endl;

    L.Push(5, 2);
    L.DispStack();
    cout << L.GetLength() << endl;

    L.Push(1, 1);
    L.Push(2, 1);
    L.Push(3, 2);
    L.Push(4, 2);
    L.DispStack();
    cout << L.GetLength() << endl;
    return 0;
}