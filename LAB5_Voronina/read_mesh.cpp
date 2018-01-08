#include "header.h"

void POINTS::read_points(ifstream &f)
{
	f >> POINT_AMO;
	cout << POINT_AMO << endl;

	float x, y, z;
	for (int i = 0; i < POINT_AMO; i++)
	{
		f >> x >> y >> z;
		P.push_back(POINT(x, y, z));
	}
	P[POINT_AMO - 1].print_point();
};


void MESH::read_obj(ifstream &f, vector<POINT> P)
{
	int TETH_AMO;
	f >> TETH_AMO;
	cout << TETH_AMO << endl;

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
