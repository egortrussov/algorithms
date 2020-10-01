#include <bits/stdc++.h>

using namespace std;

int main() {
	int Q;
	cin >> Q;
	while (Q--) {
		
		string s, ss, t;
		cin >> s;
		int n = (int) s.size();
		
		vector <int> z(n, 0);
		int l = 0, r = 0;
		for (int i = 1; i < n; i++) {
			if (i <= r) 
				z[i] = min(r - i + 1, z[i - l]);
			while (i + z[i] < n && s[z[i]] == s[i + z[i]])
				z[i]++;
			if (i + z[i] - 1 > r) {
				l = i;
				r = i + z[i] - 1;
			}
		}
		vector <int> kol(n, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < z[i]; j++)	
				kol[j]++;
		}
		for (int i = 0; i < n; i++) 
			cout << kol[i] << " ";
		cout << endl;
	}
	
	return 0;
}
