#include<iostream>
#include"Graph_L_UDG.h"
#include"Graph_L_DG.h"
#include"Graph_L_UDN.h"
#include"Graph_L_DN.h"
#include"STACK_S.h"

using namespace std;

status Creategraph()
{
	int vexn, arcn;
	int Kind;
	cout << "����ͼ������" << endl;
	cout << "1-����ͼ 2-������ 3-����ͼ 4-������" << endl;
	//cin >> G.kind;
	cin >> Kind;
	cout << "���붥�����ͱ���" << endl;
	cin >> vexn >> arcn;
	switch (Kind)
	{
	case 1:
	{
			  Graph_L_DG<char> G(vexn, arcn);
			  G.depthTraverse();
			  cout << endl;
			  G.breadthTraverse();
			  break;
	}
	case 2:
	{
			  Graph_L_DN<char> G(vexn, arcn);
			  G.depthTraverse();
			  cout << endl;
			  G.breadthTraverse();
			  break;
	}
	case 3:
	{
			  Graph_L_UDG<char> G(vexn, arcn);
			  G.depthTraverse();
			  cout << endl;
			  G.breadthTraverse();
			  break;
	}
	case 4:
	{
			  Graph_L_UDN<char> G(vexn, arcn);
			  G.depthTraverse();
			  cout << endl;
			  G.breadthTraverse();
			  break;
	}
	default: return ERROR;
	}
	return OK;
}

int main()
{
	int vexn, arcn;
	cout << "(����ͼ)���붥�����ͱ���" << endl;
	cin >> vexn >> arcn;
	Graph_L_DG<char> G(vexn, arcn);
	if (G.TopologicalSort()) cout << "�������޻�ͼ" << endl;
	system("pause");
	return 0;
}