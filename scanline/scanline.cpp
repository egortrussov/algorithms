#include <bits/stdc++.h>

using namespace std;

struct point {
	int x, type;
};

bool cmp(point a, point b) {
	return a.x < b.x || a.x == b.x && a.type > b.type;
}

int main() {
	int n;
	cin >> n;
	int x1, y1;
	cin >> x1 >> y1;
	vector <point> pp;
	pp.resize(n * 2);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < x1 || y > y1)
			continue;
		point a, b;
		a.x = x; a.type = 1; 
		b.x = y; b.type = -1;
		pp[i * 2] = a;
		pp[i * 2 + 1] = b;
	}
	sort(pp.begin(), pp.end(), cmp);
	int res = 0;
	for (int i = 0; i < pp.size(); i++) {
		point cr = pp[i];
		cout << cr.x << " " << cr.type << endl;
		res += cr.type;
		if (!res) {
			cout << "NO";
			return 0;
		} 
	}
	cout << "YES";
	
	
	return 0;
}
