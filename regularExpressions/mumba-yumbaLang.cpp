#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'a' && s[i] != 'b' && s[i] != 'c') {
			cout << "NO";
			return 0;
		}
	}
	if (s.find("bb") != -1 || s.find("aaa") != -1 || s.find("ccc") != -1) {
		cout << "NO";
		return 0;
	}
	if (s.size() <= 3) {
		cout << "YES";
		return 0;
	}
	int len = 2;
	while (len <= s.size() / 3) {
		for (int i = 0; i <= s.size() - len * 3; i++) {
			// cout << s.substr(i, len) << " " <<  s.substr(i + len, len) << " " << s.substr(i + len * 2, len) << endl;
			if (s.substr(i, len) == s.substr(i + len, len) && s.substr(i, len) == s.substr(i + len * 2, len)) {
				cout << "NO";
				return 0;
			}
		}
		len++;
	} 
	cout << "YES";
	
	
	
	return 0;
}
