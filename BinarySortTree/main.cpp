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
	struct BiTNode    *lchild, *rchild; //���Һ���ָ��
}BiTNode, *BiTree;  //�����������˽ṹ�����ͱ���

/*��ͨ��ѯ*/
BiTree searchBST(BiTree T,keyType Key)
{
    if(!T||T->data.Key==Key) return T;
    else if(Key<T->data.Key) return(searchBST(T->lchild,Key));
    else return(searchBST(T->rchild,Key));
}

/*�����㷨���õĲ�ѯ*/
Status SearchBST(BiTree T,keyType Key,BiTree &r,BiTree parents)
{
    if(!T) {r = parents; return FALSE;}
    else if(Key == T->data.Key) {r = T; return TRUE;} 
    else if(Key < T->data.Key) return(SearchBST(T->lchild,Key,r,T));
    else return(SearchBST(T->rchild,Key,r,T));
}

/*����*/
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
    cout<<"����ڵ�����:"<<endl;
    cin>>d->data;
    if(d->data == -1) return FALSE;
    cout<<"����ڵ�Key:"<<endl;
    cin>>d->Key;
    return TRUE;
}

/*��������������*/
Status CreateBST(BiTree &T)
{
    //BiTree T;
    //T = new BiTNode;
    cout<<"��������������:"<<endl;
    cout<<"�������ڵ�:"<<endl;
    DATA * d;
    d = new DATA;
    //��������ͷ�ڵ�
    if(read_data(d)) {T->lchild = T->rchild = NULL; T->data = *d;}
    d = new DATA;
    //�������
    while(read_data(d))
    {
        InsertBST(T,d);
        d = new DATA;
    }
    cout<<"��������"<<endl;
    return OK;
}

/*ɾ��һ���ڵ�*/
Status Delete(BiTree &p)
{
    BiTree q;
    if (!p->lchild) //�������գ���ֻҪ�ؽ�������
    {
        q = p;
        p = p->rchild;
        delete q;
    }
    else if (!p->rchild)//������Ϊ�գ���ֻҪ�ؽ�������
    {
        q = p;
        p = p->lchild;
        delete q;
    }
    else //���Ҷ�����
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
    cout<<"����ɾ������:"<<endl;
    for(;;)
    {
        cout<<"����Ҫɾ����key(-1�˳�)"<<endl;
        cin>>k;
        if(k==-1) break;
        if(DeleteBST(T,k)) cout<<"�ɹ���ѯ����ɾ��"<<endl;
        else { cout<<"������"<<endl; continue; }
    }
    cout<<"����ɾ����������"<<endl;
}

void test_insert(BiTree &T)
{
    DATA * d;
    d = new DATA;
    cout<<"���Բ������(-1�˳�):"<<endl;
    for(;;)
    {
        if(read_data(d)) 
        {
            if(InsertBST(T,d)) cout<<"����ɹ�"<<endl;
            else cout<<"�Ѵ���"<<endl;
        }
        else break;
    }
    cout<<"���Բ����������"<<endl;
}

void test_search(BiTree T)
{
    keyType k;
    cout<<"���Բ��Ҳ���:"<<endl;
    for(;;)
    {
        cout<<"����Key(-1�˳�)"<<endl;
        cin>>k;
        if(k==-1) break;
        else
        {
            if(searchBST(T,k)) cout<<"���ҳɹ�"<<endl;
            else cout<<"������"<<endl;
        }
    }
    cout<<"���Ҳ������Խ���"<<endl;
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


