#include <bits/stdc++.h>
using namespace std;

int main() {
	// Find all prime numbers from l to r
	
	int l, r;
	cin >> l >> r;
	vector <bool> a(r + 1, true);
	for (int i = 2; i <= r / 2; i++) {
		if (!a[i])
			continue;
		for (int j = i * 2; j <= r; j += i)	
			a[j] = false;
	}
	bool isF = false;
	for (int i = l; i <= r; i++) 
		if (a[i])  {
			isF = true;
			cout << i << endl;
		}
	if (!isF) 
		cout << "Absent";
	
	
	return 0;
}
