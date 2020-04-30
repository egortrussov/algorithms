#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, S;
	cin >> n >> S;
	int a[n];
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	int itCount = 1 << (n - 1);
	for (int i = 0; i < itCount; i++) {
		int tmp = a[0];
		for (int j = 0; j < n - 1; j++) {
			if (i & (1 << j)) {
				tmp += a[j + 1];
			} else 
				tmp -= a[j + 1];
		}
		if (tmp == S) {
			cout << a[0];
			for (int j = 0; j < n - 1; j++) {
				if (i & (1 << j)) {
					cout << "+" << a[j + 1];
				} else 
					cout << "-" << a[j + 1];
			}
			cout << "=" << S;
			return 0;
		}
	}
	cout << "No solution";
	
	return 0;
}
