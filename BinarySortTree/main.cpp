#include<iostream>
//#include"STACK_S.h"
//#include"LinkQueue.h"
//#include"LinkList.h"
using namespace std;
#define OVERFLOW -2
#define TRUE 1
#define OK 1
#define FALSE 0

typedef int Status;
typedef int ElemType;
typedef int keyType;
struct DATA
{
    ElemType data;
    keyType Key;
};

typedef  struct BiTNode 
{
	DATA data;
	struct BiTNode    *lchild, *rchild; //左右孩子指针
}BiTNode, *BiTree;  //定义了两个此结构的类型别名

/*普通查询*/
BiTree searchBST(BiTree T,keyType Key)
{
    if(!T||T->data.Key==Key) return T;
    else if(Key<T->data.Key) return(searchBST(T->lchild,Key));
    else return(searchBST(T->rchild,Key));
}

/*插入算法调用的查询*/
Status SearchBST(BiTree T,keyType Key,BiTree &r,BiTree parents)
{
    if(!T) {r = parents; return FALSE;}
    else if(Key == T->data.Key) {r = T; return TRUE;} 
    else if(Key < T->data.Key) return(SearchBST(T->lchild,Key,r,T));
    else return(SearchBST(T->rchild,Key,r,T));
}

/*插入*/
Status InsertBST(BiTree &T, DATA * e)
{
    BiTree r;
    if(!SearchBST(T,e->Key,r,NULL)) 
    {
        BiTree s;
        s = new BiTNode;
        s->data=*e;
        s->lchild = s->rchild = NULL;
        if(!r) T = s;
        else if (e->Key<r->data.Key) r->lchild = s;
        else r->rchild = s;
        return TRUE;
    }
    else return FALSE;
}

Status read_data(DATA *d)
{
    //DATA * d;
    //d = new DATA;
    cout<<"输入节点内容:"<<endl;
    cin>>d->data;
    if(d->data == -1) return FALSE;
    cout<<"输入节点Key:"<<endl;
    cin>>d->Key;
    return TRUE;
}

/*建立二叉排序树*/
Status CreateBST(BiTree &T)
{
    //BiTree T;
    //T = new BiTNode;
    cout<<"创建二叉排序树:"<<endl;
    cout<<"建立根节点:"<<endl;
    DATA * d;
    d = new DATA;
    //单独创建头节点
    if(read_data(d)) {T->lchild = T->rchild = NULL; T->data = *d;}
    d = new DATA;
    //创建完毕
    while(read_data(d))
    {
        InsertBST(T,d);
        d = new DATA;
    }
    cout<<"创建结束"<<endl;
    return OK;
}

/*删除一个节点*/
Status Delete(BiTree &p)
{
    BiTree q;
    if (!p->lchild) //左子树空，则只要重接右子树
    {
        q = p;
        p = p->rchild;
        delete q;
    }
    else if (!p->rchild)//右子树为空，则只要重接左子树
    {
        q = p;
        p = p->lchild;
        delete q;
    }
    else //左右都不空
    {
        BiTree s;
        q = p;
        s = p->lchild;
        while(s->rchild) {q = s; s = s->rchild;}
        p->data = s->data;
        if(q != p) q->rchild = s -> lchild;
        else q->lchild = s->lchild;
    }
}

Status DeleteBST(BiTree &T,keyType Key)
{
    if(!T) return FALSE;
    else
    {
        if(Key == T->data.Key) return(Delete(T));
        else if (Key<T->data.Key) return(DeleteBST(T->lchild,Key));
        else return(DeleteBST(T->rchild,Key));
    }
}//DeleteBST

void test_delete(BiTree &T)
{
    keyType k;
    cout<<"测试删除操作:"<<endl;
    for(;;)
    {
        cout<<"输入要删除的key(-1退出)"<<endl;
        cin>>k;
        if(k==-1) break;
        if(DeleteBST(T,k)) cout<<"成功查询到并删除"<<endl;
        else { cout<<"不存在"<<endl; continue; }
    }
    cout<<"测试删除操作结束"<<endl;
}

void test_insert(BiTree &T)
{
    DATA * d;
    d = new DATA;
    cout<<"测试插入操作(-1退出):"<<endl;
    for(;;)
    {
        if(read_data(d)) 
        {
            if(InsertBST(T,d)) cout<<"插入成功"<<endl;
            else cout<<"已存在"<<endl;
        }
        else break;
    }
    cout<<"测试插入操作结束"<<endl;
}

void test_search(BiTree T)
{
    keyType k;
    cout<<"测试查找操作:"<<endl;
    for(;;)
    {
        cout<<"输入Key(-1退出)"<<endl;
        cin>>k;
        if(k==-1) break;
        else
        {
            if(searchBST(T,k)) cout<<"查找成功"<<endl;
            else cout<<"不存在"<<endl;
        }
    }
    cout<<"查找操作测试结束"<<endl;
}


int main()
{
    DATA * d;
    d = new DATA;
    BiTree T;
    T = new BiTNode;
    CreateBST(T);
    test_search(T);
    test_insert(T);
    test_delete(T);
    system("pause");
    return 0;
}


