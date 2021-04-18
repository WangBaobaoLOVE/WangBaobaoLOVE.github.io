#include <iostream>

using namespace std;

int main ()
{
   int  *ptr = NULL;

   cout << "ptr 的值是 " << ptr ;

   if(ptr)
      cout << false;
   if(!ptr)
      cout << true;

   return 0;
}