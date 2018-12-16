#include"heap.h"
#include<iostream>
//#include<string>
using namespace std;
typedef int Dtype; //�����������������Ľڵ�����Ϊ��Ȩ��
struct HNode
{
    Dtype data;
    int weight;
    HNode * lchild;
    HNode * rchild;
    bool operator<(const HNode H)const
    {
        return (this->weight<H.weight);
    }
};

class HuffmanTree
{
private:
    HNode * root;
public:
    HuffmanTree();
    void HuffmanCode(HNode *p,char ch[]);
};

HuffmanTree::HuffmanTree()
{
    int i,size;
    HNode * List;
    cout<<"����Ҷ�ӽڵ����"<<endl;
    cin>>size;
    List = new HNode[size+1];
    List[0].weight = MIN;
    for(i=1;i<=size;i++)
    {
        cout<<"��"<<i<<"��Ȩ��"<<endl;
        cin>>List[i].weight;
        List[i].data = List[i].weight;
        List[i].lchild = List[i].rchild = NULL;
    }
    Heap<HNode> H(List,size);
    HNode * H1,* H2;
    HNode * H3;
    while(H.size>1)
    {
        H.Delete(H1);
        H.Delete(H2);
        H3 = new HNode;
        H3->weight = H1->weight+H2->weight;
        H3->lchild = H1;
        H3->rchild = H2;
        H.Insert(*H3);
    }
    H.Delete(root);
    char ch[30];
    HuffmanCode(root,ch);
}

void HuffmanTree::HuffmanCode(HNode *p,char ch[])
{
    static int i = 0;
    if(p->lchild==NULL && p->rchild == NULL)
    {
        ch[i] = '\0';
        cout<<p->data<<" : "<<ch<<endl;
    }
    else
    {
        ch[i++] = '0';
        HuffmanCode(p->lchild,ch);
        ch[i++] = '1';
        HuffmanCode(p->rchild,ch);
    }
    i--;
}

int main()
{
    HuffmanTree T;
    system("pause");
    return 0;
}