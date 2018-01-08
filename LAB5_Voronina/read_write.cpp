#include "header.h"

void POINTS::read_points(ifstream &f)
{
	f >> POINT_AMO;

	float x, y, z;
	for (int i = 0; i < POINT_AMO; i++)
	{
		f >> x >> y >> z;
		P.push_back(POINT(x, y, z));
	}
};


void MESH::read_obj(ifstream &f, vector<POINT> P)
{
	int TETH_AMO;
	f >> TETH_AMO;

	int N = 0;
	int P0, P1, P2, P3;
	for (int i = 0; i < TETH_AMO; i++)
	{
		f >> N;
		if (N > O.size()) O.push_back(OBJ(N - 1));
		f >> P0 >> P1 >> P2 >> P3;
		O[N - 1].T.push_back(TETH(P[P0-1], P[P1-1], P[P2-1], P[P3-1]));
	}
}


void  MESH::print_results()
{
	cout << "VOLUMES:" << endl;

	for (int i = 0; i < O.size(); i++)	cout << "Object # " << i + 1 << " V = " << O[i].V << endl;

	cout << endl << "TETRAHEDRONS:" << endl;
	cout << "V_MIN = " << abs(V_MIN) << endl;
	cout << "V_MAX = " << V_MAX << endl;
	cout << "V_MED = " << V_MED << endl;
}