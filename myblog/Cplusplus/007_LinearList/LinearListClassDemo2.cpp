#include <iostream>

using namespace std;

#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int ElemType;   /* ElemType类型根据实际情况而定，这里假设为int */

#define OK 1
#define ERROR 0

typedef int Status;

class LinearList{
    private:
        ElemType data[MAXSIZE];
        int length;

    public:
    Status InitList() // 初始化
    {
        length=0;
        return OK;
    }
    
    int GetLength(){
        return length;
    }
};

int main(){
    LinearList L;
    cout << L.InitList() <<endl;
    cout << L.GetLength() << endl;
    return 0;
}