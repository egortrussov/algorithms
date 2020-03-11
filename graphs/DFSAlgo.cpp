#include <iostream>
#include <vector>

using namespace std;

vector <int> g[10000];
int n, kol = 0;
bool isVisited[10000] = {false, };

void dfs(int x) {
	isVisited[x] = true;
	kol++;
	for (int i : g[x]) {
		if (!isVisited[i]) 
			dfs(i);
	}
}

int main() {
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int mm;
			cin >> mm;
			if (mm) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	dfs(m);
	cout << kol;
	
	
	
	return 0;
}
