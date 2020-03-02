#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	vector <int> c(n + 1, 1), par(n + 1, 0);
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) 
			if (a[j] > a[i] && c[i] + 1 > c[j])  {
				c[j] = c[i] + 1;
				par[j] = i;
			}
	}
	int mx = 0, inx = -1;
	for (int i = 1; i <= n; i++) {
		if (c[i] > mx) {
			mx = c[i];
			inx = i;
		}
	}
	vector <int> ans;
	do {
		ans.push_back(a[inx]);
		inx = par[inx];
	} while (inx);
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	
	
	return 0;
}
