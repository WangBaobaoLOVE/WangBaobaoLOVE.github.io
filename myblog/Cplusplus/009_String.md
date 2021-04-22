# 串（String）

|[上一篇](./008_StackAndQueue.md)|[目录](./index.md)|[下一篇](./006_tree.md)|
|:---:|:---:|:---:|
|[栈和队列](./008_StackAndQueue.md)|[目录](./index.md)|[Tree(树)](./006_tree.md)|

**串（string）是由零个或多个字符组成的有限序列，又名叫字符串。**

## 串的比较 

串的比较是通过组成串的字符之间的`编码`来进行的，而字符的编码指的是字符在对应字符集中的序号。

计算机中的常用字符是使用标准的`ASCII`编码，由`7位`二进制数表示一个字符，总共可以表示`128`个字符,后来扩展`ASCII码`由`8位`二进制数表示一个字符，总共可以表示256个字符。

`Unicode编码`，由`16位`的二进制数表示一个字符，这样总共就可以表示`6.5万`个字符，为了和`ASCII码`兼容，`Unicode`的前256个字符与ASCII码完全相同。

## 串的抽象数据类型

线性表更关注的是单个元素的操作，比如查找一个元素，插入或删除一个元素，但串中更多的是查找`子串`位置、得到指定位置子串、替换子串等操作。

```C++
ADT 串（string）
Data
    串中元素仅由一个字符组成，相邻元素具有前驱和后继关系。
Operation
    StrAssign(T, *chars);//生成一个其值等于字符串常量chars的串T。
    StrCopy(T, S);//串S存在，由串S复制得串T。
    ClearString(S);//串S存在，将串清空
    StringEmpty(S);//若S为空，返回true，否则返回flase。
    StrLength(S);//返回串S的元素个数，即串的长度。
    StrCompare(S, T);//若S>T，返回值>0；若S=T，返回0；若S<T，返回值<0。
    Concat(T, S1, S2);//用T返回有S1和S2联接而成的新串。    
    SubString(Sub, S, pos, len);//串S存在，1<=pos<=StrLength(S)，且0<=len<=Length(S)-pos+1；
                                //用串S的第pos个字符起长度为len的子串。
    Index(S, T, pos);//串S和T存在，T是非空串，1<=pos<=StrLength(S)。若主串S中存在和串T值相同的子串，
                     //则返回它在主串S中第pos个字符之后第一次出现的位置，否则返回0。
    Replace(S, T, V);//串S、T和V存在，T是非空串。用V替换主串S中出现的所有与T相等的不重叠的子串。
    StrInsert(S, pos, T);//串S和T存在，1<=pos<=StrLength(S)+1。在串S的第pos个字符之前插入串T。
    StrDelete(S, pos, len);//串S存在，1<=pos<=StrLength(S)-len+1。从串S中删除第pos个字符起长度为len的子串。
endADT
```

操作Index的实现算法,用到了StrLength\SubString\StrCompare等基本操作：

```C++
/* T为非空串。若主串S中第pos个字符之后存在与T相等的子串，则返回第一个这样的子串在S中的位置，否则返回0 */
int Index(String S, String T, int pos)
{
    int n, m, i;
    String sub;
    if (pos > 0)
    {
        /* 得到主串S的长度 */
        n = StrLength(S);                   
        /* 得到子串T的长度 */
        m = StrLength(T);                   
        i = pos;
        while (i <= n - m + 1)
        {
            /* 取主串第i个位置 */
            /* 长度与T相等子串给sub */
            SubString(sub, S, i, m);        
            /* 如果两串不相等 */
            if (StrCompare(sub, T) != 0)    
                ++i;
            /* 如果两串相等 */
            else                            
                /* 则返回i值 */
                return i;                   
        }
    }
    /* 若无子串与T相等，返回0 */
    return 0;                               
}
```

## 串的存储结构

### 顺序存储

**串的顺序存储结构是用一组地址连续的存储单元来存储串中的字符序列。**

### 链式存储

由于串结构的特殊性，结构中的每个元素数据是一个字符，如果也简单的应用链表存储串值，一个结点对应一个字符，就会存在很大的空间浪费。因此，一个结点可以存放一个字符，也可以考虑存放多个字符，最后一个结点若是未被占满时，可以用`“#”`或其他非串值字符补全。

![](https://gblobscdn.gitbook.com/assets%2F-Le0cHgsa8V5yblGT8Aj%2F-Le0cJJ8yl1BP-xyO82L%2F-Le0cQW32hValB_3nEpu%2F94import.png?alt=media)

**串的链式存储结构除了在连接串与串操作时有一定方便之外，总的来说不如顺序存储灵活，性能也不如顺序存储结构好。**

## 朴素的模式匹配算法

**子串的定位操作通常称做串的模式匹配。**类似去找一个单词在一篇文章（相当于一个大字符串）中的定位问题。

最简单，最容易实现的就是对主串的每一个字符作为子串开头，与要匹配的字符串进行匹配。对主串做大循环，每个字符开头做要匹配子串长度的小循环，直到匹配成功或全部遍历完成为止。

考虑不用串的其他操作，而是只用基本的数组来实现同样的算法`Index`。假设主串和要匹配的子串的长度存在`S[0]`(主串)与`T[0]`（要匹配的字串）中。

```C++
/* 返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数返回值为0。 */
/* T非空，1≤pos≤StrLength(S)。 */
int Index(String S, String T, int pos)
{
    /* i用于主串S中当前位置下标，若pos不为1, 则从pos位置开始匹配 */
    int i = pos;                      
    /* j用于子串T中当前位置下标值 */
    int j = 1;                        
    /* 若i小于S长度且j小于T的长度时循环 */
    while (i <= S[0] && j <= T[0])  /* S[0],T[0]储存着当前串的长度 */  
    {
        /* 两字母相等则继续 */
        if (S[i] == T[j])             
        {
            ++i;
            ++j;
        }
        /* 指针后退重新开始匹配 */
        else                          
        {
            /* i退回到上次匹配首位的下一位 */
            i = i - j + 2;            
            /* j退回到子串T的首位 */
            j = 1;                    
        }
    }
    if (j = T[0])
        return i - T[0]; // 大话数据结构这本书里是这样写的，我认为应该在加一：i - T[0]+1
    else
        return 0;
}
```

**这个算法太低效了。**

## KMP模式匹配算法


|[上一篇](./008_StackAndQueue.md)|[目录](./index.md)|[下一篇](./006_tree.md)|
|:---:|:---:|:---:|
|[栈和队列](./008_StackAndQueue.md)|[目录](./index.md)|[Tree(树)](./006_tree.md)|