
#include <iostream>
#include <fstream>
using namespace std;
// const int Infinity = -1;
typedef char VexType;
const int MVN = 51;

typedef struct ArcNode
{
	int adjvex;
	int adj;
	//
	ArcNode *nextarc;
}*ArcPtr;

struct VexNode
{
	VexType data;
	ArcPtr firstarc;
	bool visited;

};

struct ALGraph
{
	VexNode vexs[MVN];
	int kind, vexnum, arcnum;

};


int LocateVex(ALGraph &G, VexType v)
{
	int i;
	for (i = G.vexnum; i > 0; --i)
	{
		if (G.vexs[i].data == v)
			return i;
	}
	return -1;
}


bool InsertArc(ALGraph &G, VexType a, VexType b, int weight = 1)
{
	int loc1 = LocateVex(G, a); if (loc1 <= 0)return false;
	int loc2 = LocateVex(G, b); if (loc2 <= 0 || loc2 == loc1)return false;
	ArcPtr ptr = NULL;

	for (ptr = G.vexs[loc1].firstarc; ptr != NULL; ptr = ptr->nextarc)
	{
		if (ptr->adjvex == loc2)return false;
	}


	++G.arcnum;
	ptr = new ArcNode;
	ptr->adjvex = loc2;
	ptr->adj = weight;
	ptr->nextarc = G.vexs[loc1].firstarc;
	G.vexs[loc1].firstarc = ptr;

	if (G.kind > 2)
	{
		++G.arcnum;
		ptr = new ArcNode;
		ptr->adjvex = loc1;
		ptr->adj = weight;
		ptr->nextarc = G.vexs[loc2].firstarc;
		G.vexs[loc2].firstarc = ptr;
	}
	return true;

}



void  CreatGraph(ALGraph &G, char filename[])
{
	ifstream file;
	file.open(filename);
	file >> G.kind;
	G.arcnum = 0;

	int num = 0;
	VexType vex1, vex2;
	while (true)
	{
		file >> vex1;
		if (vex1 == '#')break;
		++num;
		G.vexs[num].data = vex1;
		G.vexs[num].firstarc = NULL;
	}

	int weight;
	G.vexnum = num;
	while (true)
	{
		file >> vex1 >> vex2;
		if (vex1 == '#' || vex2 == '#')break;
		if (G.kind == 1 || G.kind == 3)weight = 1;
		else file >> weight;
		InsertArc(G, vex1, vex2, weight);
		// ++G.arcnum;
	}
	file.close();

}


int OutDegree(ALGraph &G, VexType vex)
{
	int loc = LocateVex(G, vex);
	if (loc <= 0)return 0;
	ArcPtr ptr = G.vexs[loc].firstarc;
	int num = 0;
	while (ptr != NULL)
	{
		num += 1;
		ptr = ptr->nextarc;
	}
	return num;
}

int InDegree(ALGraph &G, VexType vex)
{
	int loc = LocateVex(G, vex);
	if (loc <= 0)return 0;
	ArcPtr ptr ;
	int num = 0;
	int i;
	for (i = 1; i <= G.vexnum; ++i)
	{
		for (ptr = G.vexs[i].firstarc; ptr != NULL; ptr = ptr->nextarc)
		{
			if (ptr->adjvex == loc)
				num += 1;
		}
	}
	return num;
}


void InDegreeOfAll(ALGraph &G, int *degree)
{

	int i;
	for (i = 1; i <= G.vexnum; ++i)degree[i] = 0;
	ArcPtr ptr ;

	for (i = 1; i <= G.vexnum; ++i)
	{
		for (ptr = G.vexs[i].firstarc; ptr != NULL; ptr = ptr->nextarc)
		{
			degree[ptr->adjvex] += 1;
		}
	}
}


void showGraph(ALGraph &G)
{
	cout << "kind : " << G.kind << endl;
	int i;
	cout << "vexs" << endl;
	for (i = 1; i <= G.vexnum; i++)
		cout << G.vexs[i].data << "\t";
	cout << endl;
	cout << "vexnum : " << G.vexnum << endl;
	ArcPtr ptr = NULL;
	int j;
	for (i = 1; i <= G.vexnum; i++)
	{
		cout << G.vexs[i].data << "  :\t\t";
		for (ptr = G.vexs[i].firstarc; ptr != NULL; ptr = ptr->nextarc)
		{
			cout  << G.vexs[i].data << "\t->\t" << G.vexs[ptr->adjvex].data << "\t\t";

		}
		cout << endl;
	}
	cout << "arcnum : " << G.arcnum << endl;

	cout << endl;
}



int main(int argc, char const *argv[])
{
	ALGraph G;
	char filename[] = "graphdata.txt";
	CreatGraph(G, filename);
	showGraph(G);

	int i;
	cout << "vex\t\toutdegree\tindegree" << endl;
	for (i = 1; i <= G.vexnum; ++i)
	{
		cout << G.vexs[i].data << ":\t\t" << OutDegree(G, G.vexs[i].data) << "\t\t\t" << InDegree(G, G.vexs[i].data) << endl;
	}





	char filename1[] = "graphdata1.txt";
	ALGraph G1;
	CreatGraph(G1, filename1);
	showGraph(G1);
	int degree[MVN];
	InDegreeOfAll(G1, degree);
	cout << "vex\t\toutdegree\tindegree" << endl;
	for (i = 1; i <= G.vexnum; ++i)
	{
		cout << G.vexs[i].data << ":\t\t" << OutDegree(G1, G1.vexs[i].data) << "\t\t\t" << degree[i] << endl;
	}
	return 0;
}