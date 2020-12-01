#include <bits/stdc++.h>

using namespace std;

int n, m;
vector < vector <int> > g;
vector <int> part;
bool ans = true;

void dfs(int x) {
	
	for (int i = 0; i < g[x].size(); i++) {
		int to = g[x][i];
		if (part[to] == -1) {
			part[to] = !part[x];
			dfs(to);
		} else if (part[to] == part[x]) {
			ans = false;
		}
	}
}

int main() {
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	part.resize(n + 1, -1);
	for (int i = 0; i < n; i++) {
		if (part[i] == -1) {
			part[i] = 0;
			dfs(i);
		}
	}
	
	if (ans) cout << "YES\n";
		else cout << "NO\n";
	
	
	
	return 0;
}
