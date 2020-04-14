#include <bits/stdc++.h>

using namespace std;

bool isSign(char ch) {
	return ch == '+' || ch == '-';
}

bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

int main() {
	string s;
	cin >> s;
	int state = 0;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (state == 0) {
			if (isSign(c)) 
				state = 1;
			else if (isDigit(c))
				state = 2;
			else {
				cout << "NO";
				return 0;
			}
			continue;
		} 
		if (state == 1) {
			if (isDigit(c))
				state = 2;
			else {
				cout << "NO";
				return 0;
			}
			continue;
		}
		if (state == 2) {
			if (isDigit(c)) {}
			else if (c == '.')
				state = 3;
			else if (c == 'E' || c == 'e') 
				state = 5;
			else {
				cout << "NO";
				return 0;
			}
			continue;
		}
		if (state == 3) {
			if (isDigit(c)) 
				state = 4;
			else {
				cout << "NO";
				return 0;
			}
			continue;
		}
		if (state == 4) {
			if (isDigit(c)) {} 
			else if (c == 'E' || c == 'e') 
				state = 5;
			else {
				cout << "NO";
				return 0;
			}
			continue;
		}
		if (state == 5) {
			if (isSign(c)) 
				state = 6;
			else if (isDigit(c)) 
				state = 7;
			else {
				cout << "NO";
				return 0;
			}
			continue;
		} 
		if (state == 6) {
			if (isDigit(c)) 
				state = 7;
			else {
				cout << "NO";
				return 0;
			}
			continue;
		}
		if (state == 7) {
			if (!isDigit(c)) {
				cout << "NO";
				return 0;
			}
		}
	}
	if (state == 1 || state == 3 || state == 5 || state == 6)	cout << "NO";
	else 
	cout << "YES";
	
	
	
	return 0;
}
