/*
First, N stones
if n % 3 == 0, u can take 1 or 2
if n % 3 == 1, u can take 1 or 3
if n % 3 == 2, u can take 1 or 2 or 3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n + 2];
	a[1] = 1; a[2] = 1; a[3] = 2;
	for (int i = 4; i <= n; i++) {
		if (i % 3 == 0) {
			if (a[i - 1] == 1 && a[i - 2] == 1) 
				a[i] = 2;
			else 
				a[i] = 1;
		} else if (i % 3 == 1) {
			if (a[i - 1] == 1 && a[i - 3] == 1) 
				a[i] = 2;
			else 
				a[i] = 1;
		} else {
			if (a[i - 1] == 1 && a[i - 3] == 1 && a[i - 2] == 1) 
				a[i] = 2;
			else 
				a[i] = 1;
		}
	}
	cout << a[n];
	
	
	return 0;
}
