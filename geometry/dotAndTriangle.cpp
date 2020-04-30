#include <bits/stdc++.h>

using namespace std;

struct coord {
	double x, y;
};

double skew(coord a, coord b) {
	return a.x * b.y - a.y * b.x;
}

int main() {
	coord a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
	coord v1, v2, v3;
	double k1 = (a.x - d.x) * (b.y - a.y) - (b.x - a.x) * (a.y - d.y);
    double k2 = (b.x - d.x) * (c.y - b.y) - (c.x - b.x) * (b.y - d.y);
    double k3 = (c.x - d.x) * (a.y - c.y) - (a.x - c.x) * (c.y - d.y);
	if ((k1 >= 0 && k2 >= 0 && k3 >= 0) || (k1 <= 0 && k2 <= 0 && k3 <= 0)) 
		cout << "In";
	else 
		cout << "Out";
	
	return 0;
}
