#pragma once
#include<iostream>
using namespace std;
#define MAXSIZE 30
#define MIN -1
/*----------------------------------//
* 数据结构——函数结果状态代码
* SUFE 2018 Spring
//----------------------------------*/
#ifndef STATUS_H
#define STATUS_H

#define	TRUE		1			
#define	FALSE		0			
#define YES			1			
#define NO          0			
#define	OK			1			
#define	ERROR		0			
#define SUCCESS		1			
#define UNSUCCESS	0			
#define	INFEASIBLE	-1			

#ifndef _MATH_H_ 				 
#define	OVERFLOW	-2			
#define UNDERFLOW	-3			
#endif 
#ifndef NULL
#define NULL ((void*)0)
#endif
typedef int status;
#endif

template<class T>
class Heap
{
private:
    T CBT[MAXSIZE+1];
public:
    int size;
    Heap(T List[],int size);
    void sift(int root);
    status Delete(T * &e);
    status Insert(T e);
    void show();
};

template<class T>
Heap<T>::Heap(T List[],int size)
{
    this->size = size;
    int init,i;
    for(i=0;i<=size;i++)
    {
        CBT[i] = List[i];
    }
    //CBT[0] = MIN;
    for(init = size/2; init>=1 ; init--) sift(init);
}

template<class T>
void Heap<T>::sift(int root)
{
    int parent,child;
    T temp = CBT[root];
    for(parent=root;parent*2<=size;parent=child)
    {
        child = parent * 2;
        if(child+1<=size && CBT[child+1]<CBT[child]) child ++;
        if(temp<CBT[child]) break;
        else CBT[parent] = CBT[child];
    }
    CBT[parent] = temp;
}

template<class T>
status Heap<T>::Delete(T * &e)
{
    T * temp;
    temp = new T;
    if(size == 0) return FALSE;
    *temp = CBT[1];
    e = temp;
    CBT[1] = CBT[size--];
    sift(1);
    return OK;
}

template<class T>
status Heap<T>::Insert(T e)
{
    if(size == MAXSIZE) return FALSE;
    int i = ++size;
    for(;e < CBT[i/2];i/=2) CBT[i] = CBT[i/2]; 
    CBT[i] = e;
}

template<class T>
void Heap<T>::show()
{
    int i;
    for(i=1;i<=size;i++) cout<<CBT[i];
    cout<<endl;
}

