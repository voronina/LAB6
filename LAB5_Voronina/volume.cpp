#include "header.h"

void TETH::get_volume()
{
	float diag1 = V1.x * V2.y * V3.z;
	float triag1 = V1.y * V2.z * V3.x;
	float triag2 = V1.z * V2.x * V3.y;

	float diag2 = V1.z * V2.y * V3.x;
	float triag3 = V1.y * V2.x * V3.z;
	float triag4 = V1.x * V2.z * V3.y;

	V = abs( (diag1 + triag1 + triag2 - diag2 - triag3 - triag4) / 6);
}

void OBJ::get_volume()
{
	V = 0;
	V_MAX = T[0].V;
	V_MIN = T[0].V;

	for (int i = 0; i < T.size(); i++)
	{
		V += T[i].V;
		if (T[i].V > V_MAX) V_MAX = T[i].V;
		if (T[i].V < V_MIN) V_MIN = T[i].V;
	}

	V_MED = V / T.size();
}

void MESH::get_volume()
{
	V_MAX = O[0].V_MAX;
	V_MIN = O[0].V_MIN;

	V_MED = 0;

	for (int i = 0; i < O.size(); i++)
	{
		O[i].get_volume();
		if (O[i].V_MAX > V_MAX) V_MAX = O[i].V_MAX;
		if (O[i].V_MIN < V_MIN) V_MIN = O[i].V_MIN;
		V_MED += O[i].V_MED;
	}

	V_MED = V_MED / O.size();
}