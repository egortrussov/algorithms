#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	int ans = 0; 
	bool state = 0;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c == ':' || c == ';') {
			state = true;
		}
			
		else if (c == '-') {
			if (!state) state = 0;
		}
			
		else {
			if (c == ')' || c == '(' || c == '[' || c == ']') {
				if (state) {
					state = false;
					ans++;
				}
			} else {
				state = 0;
			}
		} 
	}
	cout << ans;
	
	
	return 0;
}
