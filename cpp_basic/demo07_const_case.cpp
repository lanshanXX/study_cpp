#include <iostream>


using namespace std;

/*
    const与一级指针，引用结合
*/


int main()
{
    //写一句代码，在内存0x00188ff44处写一个四字节的10
    int *&&p = (int *)0x00188ff44;




    return 0;
}