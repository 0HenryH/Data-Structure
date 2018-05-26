#pragma once
#pragma once
#include"STACK_S.h"
#include "Graph_lnk.h"

template<class vertextype>
class Graph_L_DG : public Graph_lnk<vertextype>
{
public:
	Graph_L_DG(int vexn, int arcn);
	//~Graph_L_DG();
	void count_in_degree(int in_degree[]);
	status TopologicalSort();
};


template<class vertextype>
Graph_L_DG<vertextype>::Graph_L_DG(int vexn, int arcn)
{
	ArcNode * s;
	int i;
	vertextype v1, v2;
	kind = DG;
	vexnum = vexn;
	arcnum = arcn;
	cout << "输入顶点" << endl;
	for (i = 0; i < vexn; i++)
	{
		cin >> VErtices[i].data;
		VErtices[i].firstarc = NULL;
	}
	cout << "输入边" << endl;
	for (i = 0; i < arcn; i++)
	{
		s = new ArcNode;
		cout << "v1<char>" << endl;
		cin >> v1;
		cout << "v2<char>" << endl;
		cin >> v2;
		s->weight = 1;
		s->adjvex = Location(v2);
		s->nextarc = VErtices[Location(v1)].firstarc;
		VErtices[Location(v1)].firstarc = s;
		//s.adjvex = Location(v2);
		//s.nextarc = VErtices[Location(v1)].firstarc;
		//VErtices[Location(v1)].firstarc = s;
	}

}

template<class vertextype>
void Graph_L_DG<vertextype>::count_in_degree(int in_degree[])
{
	int i,count;
	ArcNode * p;
	for (i = 0; i < vexnum; i++)
		for (p = VErtices[i].firstarc; p; p = p->nextarc)
			in_degree[p->adjvex]++;
}



template<class vertextype>
status Graph_L_DG<vertextype>::TopologicalSort()
{
	STACK_S<int> stack; int i, k, count; ArcNode *p;
	int in_degree[MAX_VERTEX_NUM] = {0};
	count_in_degree(in_degree);
	for (i = 0; i < vexnum; i++)
	{
		if (!in_degree[i]) stack.push(i);
	}
	count = 0; // 初始化计数器，对输出顶点计数
	while (!stack.is_empty())
	{
		stack.pop(i); count++;
		cout << VErtices[i].data<<"  ";
		for (p = VErtices[i].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			if (!(--in_degree[k])) stack.push(k);
		}//for
	}//while
	if (count < vexnum) return ERROR;
	else return OK;
}
