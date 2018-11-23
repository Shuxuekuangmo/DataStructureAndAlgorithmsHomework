
#include <iostream>
#include <fstream>
using namespace std;

const int Infinity = -1;
typedef char VexType;
struct VexCell
{
	VexType data;
	bool visited;
};

struct ArcCell
{
	int adj;
};
const int MVN = 51;
struct MGraph
{
	VexCell vexs[MVN];
	ArcCell arcs[MVN][MVN];
	int kind, vexnum, arcnum;
};

int LocateVex(MGraph &G, VexType vex)
{
	int i;
	for (i = G.vexnum; i > 0 && G.vexs[i].data != vex; --i);
	return i;
}

bool InsertArc(MGraph &G, VexType u, VexType v, int w = 1)
{
	int i, j;
	i = LocateVex(G, u); if (i == 0)return false;
	j = LocateVex(G, v);
	if (j == 0 || i == j || G.arcs[i][j].adj != Infinity)return false;
	G.arcs[i][j].adj = w;
	G.arcnum++;
	if (G.kind >= 3)
	{
		G.arcs[j][i].adj = w;
		G.arcnum++;
	}
	return true;
}


void CreatGraph(MGraph &G, char fn[])
{
	int i, j, w;
	VexType u, v;
	ifstream f;
	f.open(fn); f >> G.kind;
	i = 0;
	while (true)
	{
		f >> u; if (u == '#')break;
		++i;
		G.vexs[i].data = u;
	}
	G.vexnum = i;
	// cout << i << endl;
	for (i = 1; i <= G.vexnum; ++i)
	{
		for (j = 1; j <= G.vexnum; ++j)
		{
			G.arcs[i][j].adj = Infinity;
		}
	}
	G.arcnum = 0;
	while (true)
	{
		f >> u >> v;
		if (u == '#' || v == '#')break;
		if (G.kind == 1 || G.kind == 3)w = 1;
		else f >> w;
		InsertArc(G, u, v, w);
	}
	f.close();
}


bool InsertVec(MGraph &G, VexType vex)
{
	int loc = LocateVex(G, vex);
	// cout << loc << endl;
	if (G.vexnum >= MVN || loc > 0)return false;
	G.vexnum += 1;
	G.vexs[G.vexnum].data = vex;
	G.vexs[G.vexnum].visited = false;
	int i;
	for (i = 1; i <= G.vexnum; ++i)
	{
		G.arcs[i][G.vexnum].adj = Infinity;
		G.arcs[G.vexnum][i].adj = Infinity;
	}
	return true;
}
bool DleeteArc(MGraph &G, VexType a, VexType b)
{
	int loc1 = LocateVex(G, a);
	int loc2 = LocateVex(G, b);
	if (!(loc1 > 0 && loc2 > 0))return false;
	G.arcs[loc1][loc2].adj = Infinity;
	G.arcnum -= 1;
	if (G.kind > 2)
	{
		G.arcs[loc2][loc1].adj = Infinity;
		G.arcnum -= 1;
	}
	return true;
}

bool DleeteVex(MGraph &G, VexType a)
{
	int loc = LocateVex(G, a);
	if (loc <= 0)return false;
	G.vexs[loc] = G.vexs[G.vexnum];

	int i;
	for (i = 1; i <= G.vexnum; ++i)
	{
		if (G.arcs[loc][i].adj != Infinity)G.arcnum -= 1;
		G.arcs[loc][i] = G.arcs[G.vexnum][i];
		if (G.arcs[i][loc].adj != Infinity)G.arcnum -= 1;
		G.arcs[i][loc] = G.arcs[i][G.vexnum];

	}
	G.vexnum -= 1;

	return true;

}

void showGraph(MGraph &G)
{
	cout << "kind : " << G.kind << endl;
	int i;
	cout << "vexs" << endl;
	for (i = 1; i <= G.vexnum; ++i)
		cout << G.vexs[i].data << "\t";
	cout << endl;
	cout << "vexnum : " << G.vexnum << endl;
	int j;
	for (i = 1; i <= G.vexnum; ++i)
	{
		for (j = 1; j <= G.vexnum; ++j)
		{
			if (G.arcs[i][j].adj != Infinity)
			{
				cout << G.vexs[i].data << "\t->\t" << G.vexs[j].data << endl;
			}
		}
	}
	cout << "arcnum : " << G.arcnum << endl;

	cout << endl;
}
int main(int argc, char const *argv[])
{
	MGraph G;
	char filename[] = "graphdata.txt";
	CreatGraph(G, filename);	showGraph(G);

	InsertVec(G, 'h');	showGraph(G);
	InsertArc(G, 'h', 'a');	showGraph(G);
	DleeteArc(G, 'h', 'a');	showGraph(G);
	DleeteVex(G, 'h');	showGraph(G);
	DleeteVex(G, 'e');	showGraph(G);
	return 0;
}