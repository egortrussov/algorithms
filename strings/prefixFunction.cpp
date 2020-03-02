#include <bits/stdc++.h>

using namespace std;

int main() {
	string ss, t;
	cin >> ss >> t;
	string s = t + "#" + ss;
	int n = s.length();
	vector <int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	for (int i = 0; i < n; i++) {
		if (pi[i] == t.length()) {
			cout << i - t.length() - t.length() << " ";
		}
	}
	
	
	return 0;
}
