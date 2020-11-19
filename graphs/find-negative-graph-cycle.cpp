#include <bits/stdc++.h>

using namespace std;

struct edge {
	int u, v, c;
};

edge createEdge(int u, int v, int c) {
	edge res;
	res.u = u; res.v = v; res.c = c;
	return res;
}

int main() {
	int n;
	cin >> n;
	vector < edge > v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cost; cin >> cost;
			if (i != j && cost != 100000) 
				v.push_back(createEdge(i, j, cost));
		}
	}
	vector <int> d(n + 1, 100000000), par(n + 1, -1);
	int x;
	for (int i = 0; i < n; i++) {
		x = -1;
		for (int j = 0; j < v.size(); j++) {
			int u = v[j].u, to = v[j].v, c = v[j].c;
			if (d[to] > d[u] + c) {
				d[to] = max(d[u] + c, -100000000);
				par[to] = u;
				x = to;
			}
		}
	}
	if (x == -1) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	int y = x;
	for (int i = 0; i < n; i++) 
		y = par[y];
	vector <int> ans;
	int curr = y;
	while (true) {
		ans.push_back(curr);
		if (curr == y && ans.size() > 1) 
			break;
		curr = par[curr];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i] + 1 << " ";
	
	return 0;
}
