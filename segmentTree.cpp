#include <bits/stdc++.h>

using namespace std;

int t[4 * 100000];

void build(int v, int vl, int vr, int a[]) {
	if (vl == vr) {
		t[v] = a[vl];
		return;
	}
	int vm = (vl + vr) / 2;
	build(2 * v + 1, vl, vm, a);
	build(2 * v + 2, vm + 1, vr, a);
	t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int query(int v, int vl, int vr, int l, int r) {
	if (r < vl || vr < l)
		return 0;
	if (l <= vl && r >= vr) 
		return t[v];
	int vm = (vl + vr) / 2;
	int ql = query(2 * v + 1, vl, vm, l, r);
	int qr = query(2 * v + 2, vm + 1, vr, l, r);
	return ql + qr;
}

int main() {
	int a[100000], n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build(0, 0, n - 1, a);
	for (int i = 0; i < n * 2; i++) 
		cout << t[i] << " ";
	int Q;
	cin >> Q;
	while (Q--) {
		int l, r;
		cin >> l >> r;
		cout << query(0, 0, n - 1, l, r) << endl;
	}
	
	return 0;
}
