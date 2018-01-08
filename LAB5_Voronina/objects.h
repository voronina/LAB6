class POINT {
public:
	float x, y, z;

	POINT(float new_x, float new_y, float new_z) : x(new_x), y(new_y), z(new_z) {};

	void print_point() { cout << x << "; " << y << "; " << z << endl; };
};

class POINTS {
public:
	int POINT_AMO;
	vector<POINT> P;

	void read_points(ifstream &f);
};

class VECT {
public:
	float x, y, z;

	VECT(POINT P0, POINT P1)
	{
		x = P1.x - P0.x;
		y = P1.y - P0.y;
		z = P1.z - P0.z;
	};
	VECT() {};

	void print_vect() { cout << x << "; " << y << "; " << z << endl; };
};



class TETH {
public:
	VECT V1, V2, V3;
	float V;

	TETH(POINT P0, POINT P1, POINT P2, POINT P3)
	{
		V1 = VECT(P0, P1);
		V2 = VECT(P0, P2);
		V3 = VECT(P0, P3);

		get_volume();
	};
	
	void get_volume();
};	

class OBJ {
public:
	int OBJ_NUM;
	vector<TETH> T;
	float V;
	float V_MED, V_MAX, V_MIN;

	OBJ(int new_N) : OBJ_NUM(new_N) {};

	void get_volume();
};

class MESH {
public:
	vector<OBJ> O;
	float V_MED, V_MAX, V_MIN;

	void read_obj(ifstream &f, vector<POINT> P);

	void get_volume();

	void print_results();
};


