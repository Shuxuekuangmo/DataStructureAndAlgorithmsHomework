
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




bool InsertVec(ALGraph &G, VexType vex)
{
	int loc = LocateVex(G, vex);

	if (loc > 0 || G.vexnum >= MVN)return false;
	G.vexnum += 1;
	G.vexs[G.vexnum].data = vex;
	G.vexs[G.vexnum].visited = false;
	G.vexs[G.vexnum].firstarc = NULL;

	return true;
}
bool DleteArc(ALGraph &G, VexType a, VexType b)
{
	int loc1 = LocateVex(G, a);
	int loc2 = LocateVex(G, b);
	if (loc1 <= 0 && loc2 <= 0 || loc1 == loc2)return false;

	ArcPtr ptr, preptr;
	for (preptr = ptr = G.vexs[loc1].firstarc; ptr != NULL; preptr = ptr, ptr = ptr->nextarc)
	{
		if (ptr->adjvex == loc2)
		{
			if ( ptr == G.vexs[loc1].firstarc)G.vexs[loc1].firstarc = ptr->nextarc;
			else preptr->nextarc = ptr->nextarc;
			delete ptr;
			--G.arcnum;
		}
	}

	if (G.kind > 2)
	{
		for (preptr = ptr = G.vexs[loc2].firstarc; ptr != NULL; preptr = ptr, ptr = ptr->nextarc)
		{
			if (ptr->adjvex == loc1)
			{
				if ( ptr == G.vexs[loc2].firstarc)G.vexs[loc2].firstarc = ptr->nextarc;
				else preptr->nextarc = ptr->nextarc;
				delete ptr;
				--G.arcnum;
			}
		}
	}
	return true;
}


//!!!!!!
bool DleeteVex(ALGraph &G, VexType a)
{
	int loc = LocateVex(G, a);
	if (loc <= 0)return false;


	int i;
	for (i = 1; i <= G.vexnum; ++i)
	{
		DleteArc(G, a, G.vexs[i].data);
		// --G.arcnum //don't need
	}
	G.vexs[loc] = G.vexs[G.vexnum];
	ArcPtr ptr;
	for (i = 1; i <= G.vexnum; ++i)
	{
		for (ptr = G.vexs[i].firstarc; ptr != NULL; ptr = ptr->nextarc)
		{
			if (ptr->adjvex == G.vexnum)ptr->adjvex = loc;

		}
	}

	G.vexnum -= 1;
	return true;

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
	char filename[] = "graphdata1.txt";
	CreatGraph(G, filename);
	// showGraph(G);

	InsertVec(G, 'z');
	showGraph(G);
	InsertArc(G, 'z', 'a');
	showGraph(G);

	//nothing will haappen
	InsertArc(G, 'z', 'z');
	InsertArc(G, 'z', 'a');
	showGraph(G);


	DleteArc(G, 'z', 'a');
	showGraph(G);

	//nothing will haappen
	DleteArc(G, 'z', 'a');
	DleteArc(G, 'a', 'a');
	showGraph(G);


	InsertArc(G, 'a', 'a');
	InsertArc(G, 'a', 'b');
	InsertArc(G, 'a', 'c');
	InsertArc(G, 'a', 'e');
	InsertArc(G, 'a', 'f');
	InsertArc(G, 'a', 'g');
	DleeteVex(G, 'a');
	showGraph(G);
	DleeteVex(G, 'z');
	showGraph(G);
	DleeteVex(G, 'h');
	showGraph(G);
	return 0;
}