#include <bits/stdc++.h>

using namespace std;

int c[1010][1010];

int main() {
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	int m;
	cin >> m;
	int b[m + 1];
	for (int i = 1; i <= m; i++) 
		cin >> b[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) 
				c[i][j] = c[i - 1][j - 1] + 1;
			else 
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
		}
	}
	int tmp = c[n][m], i = n, j = m;
	vector <int> ans;
	while (tmp) {
		if (a[i] == b[j]) {
			ans.push_back(a[i]);
			i--; j--; tmp--;
		} else {
			if (c[i - 1][j] > c[i][j - 1]) 
				i--;
			else 
				j--;
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i] << " ";
	
	
	return 0;
}
