# 指针

1. [菜鸟教程 C++ 指针](https://www.runoob.com/cplusplus/cpp-pointers.html)


## What is pointer（什么是指针）

每一个变量都有一个内存位置，每一个内存位置都定义了可使用连字号（&）运算符访问的地址，它表示了在内存中的一个地址。

[demo1.cpp](./004_pointer/demo1.cpp)
```C++

#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var1;
   char var2[10];
 
   cout << "var1 变量的地址： ";
   cout << &var1 << endl; // &: 取地址符号
 
   cout << "var2 变量的地址： ";
   cout << &var2 << endl;
 
   return 0;
}
```

而指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。就像其他变量或常量一样，必须在使用指针存储其他变量地址之前，对其进行声明。**星号是用来指定一个变量是指针。**

```C++
int    *ip;    /* 一个整型的指针 */
double *dp;    /* 一个 double 型的指针 */
float  *fp;    /* 一个浮点型的指针 */
char   *ch;    /* 一个字符型的指针 */
```

所有指针的值的实际数据类型，不管是整型、浮点型、字符型，还是其他的数据类型，都是一样的，都是一个代表内存地址的长的十六进制数。不同数据类型的指针之间唯一的不同是，指针所指向的变量或常量的数据类型不同。

## 指针的简单使用

使用指针时会频繁进行以下几个操作：定义一个指针变量、把变量地址赋值给指针、访问指针变量中可用地址的值。这些是通过使用一元运算符 `*` 来返回位于操作数所指定地址的变量的值。

在定义的时候，`*` 表示这是一个指针，在使用的时候，`*` 表示指针指向的值。

[demo2.cpp](./004_pointer/demo2.cpp)
```C++
#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var = 20;   // 实际变量的声明
   int  *ip;        // 指针变量的声明
 
   ip = &var;       // 在指针变量中存储 var 的地址
 
   cout << "Value of var variable: ";
   cout << var << endl;
 
   // 输出在指针变量中存储的地址
   cout << "Address stored in ip variable: ";
   cout << ip << endl;
 
   // 访问指针中地址的值
   cout << "Value of *ip variable: ";
   cout << *ip << endl;
 
   return 0;
}
```

当上面的代码被编译和执行时，它会产生下列结果：
```
Value of var variable: 20
Address stored in ip variable: 0xbfc601ac
Value of *ip variable: 20
```

## Null指针

在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯。赋为 NULL 值的指针被称为空指针。

NULL 指针是一个定义在标准库中的值为零的常量。

[demo3.cpp](./004_pointer/demo3.cpp)
```C++
#include <iostream>

using namespace std;

int main ()
{
   int  *ptr = NULL;

   cout << "ptr 的值是 " << ptr ;
 
   return 0;
}
```
执行结果：
```
ptr 的值是 0
```

在大多数的操作系统上，程序不允许访问地址为 0 的内存，因为该内存是操作系统保留的。然而，内存地址 0 有特别重要的意义，它表明该指针不指向一个可访问的内存位置。但按照惯例，如果指针包含空值（零值），则假定它不指向任何东西。

如需检查一个空指针，您可以使用 if 语句，如下所示：

```
if(ptr)     /* 如果 ptr 非空，则完成 */
if(!ptr)    /* 如果 ptr 为空，则完成 */
```

## 指针的算术运算

指针是一个用数值表示的地址。因此，可以对指针执行算术运算。可以对指针进行四种算术运算：`++、--、+、-`。

假设 ptr 是一个指向地址 1000 的整型指针，是一个 32 位的整数，对该指针执行下列的算术运算：`ptr++`。在执行完上述的运算之后，ptr 将指向位置 `1004`，因为 ptr 每增加一次，它都将指向`下一个整数位置`，即当前位置往后移 `4 个字节`。这个运算会在不影响内存位置中实际值的情况下，移动指针到下一个内存位置。如果 ptr 指向一个地址为 1000 的字符，上面的运算会导致指针指向位置 1001，因为下一个字符位置是在 1001。

### 递增一个指针

在程序中使用指针代替数组，因为变量指针可以递增，而数组不能递增，因为数组是一个常量指针。下面的程序递增变量指针，以便顺序访问数组中的每一个元素：

[demo4.cpp](./004_pointer/demo4.cpp)
```C++

#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // 指针中的数组地址
   ptr = var;
   for (int i = 0; i < MAX; i++)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;
 
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;
 
      // 移动到下一个位置
      ptr++;
   }
   return 0;
}
```
执行结果：
```
Address of var[0] = 0x61fefc
Value of var[0] = 10
Address of var[1] = 0x61ff00
Value of var[1] = 100
Address of var[2] = 0x61ff04
Value of var[2] = 200
```

### 递减一个指针

[demo5.cpp](./004_pointer/demo5.cpp)
```C++
#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // 指针中最后一个元素的地址
   ptr = &var[MAX-1];
   for (int i = MAX; i > 0; i--)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;
 
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;
 
      // 移动到下一个位置
      ptr--;
   }
   return 0;
}
```
执行结果：
```
Address of var[3] = 0x61ff04
Value of var[3] = 200
Address of var[2] = 0x61ff00
Value of var[2] = 100
Address of var[1] = 0x61fefc
Value of var[1] = 10
```

### 指针的比较

指针可以用关系运算符进行比较，如 ==、< 和 >。如果 p1 和 p2 指向两个相关的变量，比如同一个数组中的不同元素，则可对 p1 和 p2 进行大小比较。

[demo6.cpp](./004_pointer/demo6.cpp)
```C++

#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;
 
   // 指针中第一个元素的地址
   ptr = var;
   int i = 0;
   while ( ptr <= &var[MAX - 1] )
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;
 
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;
 
      // 指向上一个位置
      ptr++;
      i++;
   }
   return 0;
}
```
执行结果：
```
Address of var[0] = 0x61fefc
Value of var[0] = 10
Address of var[1] = 0x61ff00
Value of var[1] = 100
Address of var[2] = 0x61ff04
Value of var[2] = 200
```

## 指针 vs 数组

## 指针数组

## 指向指针的指针

## 传递指针给函数

## 从函数返回指针