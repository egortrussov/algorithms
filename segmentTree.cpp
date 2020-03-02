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

void add_num(int v, int vl, int vr, int l, int r, int val) {
	if (l > r) 
		return;
	if (vl == vr) {
		t[v] += val;
		return;
	}
	int vm = (vl + vr) / 2;
	add_num(2 * v + 1, vl, vm, l, min(vm, r), val);
	add_num(2 * v + 2, vm + 1, vr, max(vm + 1, l), r, val);
	t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

void set_num(int v, int vl, int vr, int l, int r, int val) {
	if (l > r) 
		return;
	if (vl == vr) {
		t[v] = val;
		return;
	}
	int vm = (vl + vr) / 2;
	set_num(2 * v + 1, vl, vm, l, min(vm, r), val);
	set_num(2 * v + 2, vm + 1, vr, max(vm + 1, l), r, val);
	t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int main() {
	int a[100000], n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build(0, 0, n - 1, a);
	
	int Q;
	cin >> Q;
	while (Q--) {
		string ch;
		cin >> ch;
		if (ch == "rsq") {
			int l, r;
			cin >> l >> r;
			cout << query(0, 0, n - 1, l - 1, r - 1) << endl;
		} else if (ch == "add") {
			int l, r, x;
			cin >> l >> r >> x;
			add_num(0, 0, n - 1, l - 1, r - 1, x);
		} else if (ch == "update") {
			int l, r, x;
			cin >> l >> r >> x;
			set_num(0, 0, n - 1, l - 1, r - 1, x);
			for (int i = 0; i < n * 4; i++) 
				cout << t[i] << " "; cout << endl;
		}
		 
		
	}
	
	return 0;
}
