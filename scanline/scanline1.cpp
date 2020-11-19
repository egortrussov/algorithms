#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	pair <int, int> a[n];
	pair <int, bool> x[n * 2];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		x[i * 2] = make_pair(a[i].first, false);
		x[i * 2 + 1] = make_pair(a[i].second, true);
	}
	sort(x, x + n * 2);
	int res = 0, c = 0;
	for (int i = 0; i < n * 2; i++)  {
		if (c) 
			res += x[i].first - x[i - 1].first;
		if (x[i].second) 
			c++;
		else 
			c--;
	}
	
	cout << res << endl;
	
	
	return 0;
}
