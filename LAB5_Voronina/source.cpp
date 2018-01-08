#include "header.h"

int main()
{
	POINTS P;
	MESH M;

	ifstream f;
	f.open("D://mesh");

	P.read_points(f);
	M.read_obj(f, P.P);

	cout << M.O[0].T[0].V1.x << endl;

	f.close();

	system("pause");
	return 0;
}