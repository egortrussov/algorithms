/*
Given coordinates of 2 horses on a chess board.
return the number of moves when the 2 will be on the same spot.
the figures move together
*/

#include <bits/stdc++.h>

using namespace std;

struct coord {
	int x, y;
};

coord getCoord(int x, int y) {
	coord res;
	res.x = x; res.y = y;
	return res;
}

vector < vector <int> > g, use;
vector <coord> m1;
vector <coord> m2;
bool isF = false;
int currN = 1;

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

void search1() {
	vector <coord> c = m1;
	m1.clear();
	vector < vector <int> > used = use;
	for (int i = 0; i < c.size(); i++) {
		int x = c[i].x, y = c[i].y;
		for (int j = 0; j < 8; j++) {
			int x1 = x + xMove[j], y1 = y + yMove[j];
			if (x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8) { 
				if (used[x1][y1]) continue;
				used[x1][y1] = 1;
				g[x1][y1] = currN;
				m1.push_back(getCoord(x1, y1));
			}
		}
	}
}

void search2() {
	vector <coord> c = m2;
	m2.clear();
	vector < vector <int> > g1 = g;
	vector < vector <int> > used = use;
//	for (int i = 0; i < 8; i++) {
//			for (int j = 0; j < 8; j++) cout << used[i][j]<< " "; cout << endl;
//		}
//		cout << endl;
	for (int i = 0; i < c.size(); i++) {
		int x = c[i].x, y = c[i].y;
//		cout << x << " " << y << endl;
		for (int j = 0; j < 8; j++) {
			int x1 = x + xMove[j], y1 = y + yMove[j];
			if (x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8) {
				if (g1[x1][y1] == currN) {
					isF = true;
					return;
				}
				if (used[x1][y1]) continue;
				used[x1][y1] = 1;
				g[x1][y1] = currN;
				m2.push_back(getCoord(x1, y1));
			}
		}
	}
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	coord a, b;
	g.resize(8, vector <int>(8, 0));
	use.resize(8, vector <int>(8, 0));
	a.x = (int) s1[0] - 'a'; a.y = (int) s1[1] - '1';	
	b.x = (int) s2[0] - 'a'; b.y = (int) s2[1] - '1';
	m1.push_back(a);
	m2.push_back(b);
	for (int i = 0; i < 64; i++) { 
		search1();
		search2();
		if (isF) {
			cout << currN;
			return 0;
		}
		currN++;
	}
	cout << -1;
	
	
	return 0;
}
