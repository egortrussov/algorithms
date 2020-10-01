#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a1, k, b, m;
	int INF = (int) 1e9;
	cin >> n >> a1 >> k >> b >> m;
	vector <int> a(n + 2), d(n + 1, INF);
	d[0] = -INF;
	a[0] = a1;
	for (int i = 0; i < n - 1; i++) 
		a[i + 1] = (k * a[i] + b) % m;
	vector <int> p(n + 2, -1), pa(n + 2, -1);
	for (int i = 0; i < n; i++) {
		int j = (int) (upper_bound(d.begin(), d.end(), a[i]) - d.begin());
		if (d[j - 1] < a[i] && a[i] < d[j]) {
			p[j] = i;
			pa[i] = p[j - 1];
			d[j] = a[i];	
		}
	}
	int ansx = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] != INF) ansx = i;
	}
	int val = a[p[ansx]];
	int inx = pa[p[ansx]];
	vector <int> ans;
	ans.push_back(val);
	while (inx != -1) {
		ans.push_back(a[inx]);
		inx = pa[inx];
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	
	
	return 0;
}
