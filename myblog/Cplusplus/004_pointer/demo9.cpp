
#include <iostream>
#include <ctime>
 
using namespace std;
 
// 在写函数时应习惯性的先声明函数，然后在定义函数
void getSeconds(unsigned long *par);
 
int main ()
{
   unsigned long sec;
 
 
   getSeconds( &sec );
 
   // 输出实际值
   cout << "Number of seconds :" << sec << endl;
 
   return 0;
}
 
void getSeconds(unsigned long *par)
{
   // 获取当前的秒数
   *par = time( NULL );
   return;
}
