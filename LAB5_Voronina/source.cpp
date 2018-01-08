#include "header.h"

int main()
{
	POINTS P;
	MESH M;

	ifstream f;
	f.open("D://mesh");

	P.read_points(f);
	M.read_obj(f, P.P);
	M.get_volume();

	f.close();

	M.print_results();

	system("pause");
	return 0;
}