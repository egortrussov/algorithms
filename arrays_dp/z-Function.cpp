#include <bits/stdc++.h>

using namespace std;

int main() {
	int Q; cin >> Q;
	while (Q--) {
		int n; cin >> n;
		int d = 1 + 8 * n;
		int sq = sqrt(d);
		int a1 = (1 + sq) / 2;
		cout << a1 << endl;
	}
	
	
	
	return 0;
}
