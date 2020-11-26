#include <bits/stdc++.h>

using namespace std;

struct edge {
	int u, v, c;
};

edge start;

bool cmp(edge a, edge b) {
	return a.c < b.c;
}

int cost = 0;

vector <edge> minimise(vector < vector <edge> > g, vector <edge> edges) {
	vector <edge> newEdges;
	int n = g.size();
	vector <int> comp(n + 1, -1);
	for (int i = 0; i < n; i++)
		comp[i] = i;
	for (int i = 0; i < edges.size(); i++) {
		int w = edges[i].c,
			u = edges[i].u,
			v = edges[i].v;
		if (comp[u] != comp[v]) {
			cost += w;
			int a = comp[u], b = comp[v];
			for (int ii = 0; ii < n; ii++)
            	if (comp[ii] == b)
                	comp[ii] = a;
		}
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
	sort(edges.begin(), edges.end(), cmp);
	vector <edge> res = minimise(g, edges);
	
	cout << cost << endl;
	
	
	return 0;
}
