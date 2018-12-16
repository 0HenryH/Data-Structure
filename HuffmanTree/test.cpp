
#include"heap.h"
#include<iostream>
using namespace std;
int main()
{
    int * b;
    int a[5] = {-1,4,3,2,1};
    Heap<int> H(a,4);
    H.Insert(0);
    H.Delete(b);
    H.show();
    cout<<*b<<endl;
    system("pause");
    return 0;
}
