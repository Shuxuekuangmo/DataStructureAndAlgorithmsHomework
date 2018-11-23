
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

int OutDegree(MGraph &G, VexType vex)
{
	int i, out = 0;
	int loc = LocateVex(G, vex);
	for (i = 1; i <= G.vexnum; ++i)
	{
		if (G.arcs[loc][i].adj != Infinity)++out;
	}
	return out;
}
int InDegree(MGraph &G, VexType vex)
{
	int loc = LocateVex(G, vex);
	int i;
	int in = 0;
	for (i = 1; i <= G.vexnum; ++i)
	{
		if (G.arcs[i][loc].adj != Infinity)++in;
	}
	return in;
}



int main(int argc, char const *argv[])
{
	MGraph G;
	char filename[] = "graphdata.txt";
	CreatGraph(G, filename);
	// cout << InDegree(G, 'a') << endl;
	// cout << OutDegree(G, 'a') << endl;

	cout << "vex" << "\t" << "indegree" << "\t" << "outdegree" << endl;
	int i;
	for (i = 1; i <= G.vexnum; ++i)
	{
		cout << G.vexs[i].data << "\t" << InDegree(G, G.vexs[i].data) << "\t\t\t" << OutDegree(G, G.vexs[i].data) << endl;
	}
	return 0;
}