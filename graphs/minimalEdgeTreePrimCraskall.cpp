#include <bits/stdc++.h>

using namespace std;

struct edge {
	int u, v, c;
};

edge start;

vector <edge> minimise(vector < vector <edge> > g, vector <edge> edges) {
	set <int> unvisited;
	unvisited.insert(1);
	vector < vector <edge> > res(g.size() + 1);
	vector <edge> newEdges;
	vector <bool> used(g.size() + 1, false);
	used[1] = true;
	while (unvisited.size() < g.size() - 1) {
		int inx1 = -1;
		edge mn;
		mn.c = (int) 1e9;
		for (int inx = 0; inx < edges.size(); inx++) {
			edge e = edges[inx];
			if (used[e.u] 
				&& !used[e.v]
				&& (e.c < mn.c || inx1 == -1)) {
					mn = e;
					inx1 = inx;
				}
		}
		newEdges.push_back(mn);
		unvisited.insert(mn.v);
		used[mn.v] = true;
	}
	
	return newEdges;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector < vector <edge> > g(n + 1);
	vector <edge> edges;
	start.u = -1;
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({ u, v, c });
		g[v].push_back({ v, u, c });
		edges.push_back({ u, v, c });
		edges.push_back({ v, u, c });
	}
	vector <edge> res = minimise(g, edges);
	
	int ans = 0;
	for (int i = 0; i < res.size(); i++) {
		ans += res[i].c;
	}
	cout << ans;
	
	
	return 0;
}
