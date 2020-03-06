#include <bits/stdc++.h>
 
using namespace std;
 
struct edge {
    int u, v, c;    
};
 
int INF = 30000;
int n, m, v;
vector <int> dist(10000, INF);
vector <edge> e;
int x;
 
void algo() {
    dist[v] = 0;
    for (int i = 1; i <= n; i++) {
    	x = -1;
    	for (int j = 0; j < e.size(); j++) {
    		edge to = e[j];
    		if (dist[to.v] > dist[to.u] + to.c) {
    			dist[to.v] = max(-INF, dist[to.u] + to.c);			
				x = to.v;
			}
		}
	}
}
 
int main() {
    cin >> n;
    v = 1;
    dist.resize(n + 1);
//    for (int i = 0; i < m; i++) {
//        edge ee;
//        cin >> ee.u >> ee.v >> ee.c;
//        e.push_back(ee);
//    } 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp; cin >> tmp;
            if (tmp != 100000) {
                edge ee; 
                ee.u = i; ee.v = j; ee.c = tmp;
                e.push_back(ee);
            }
        }
    }
    algo();
    if (x != -1) 
    	cout << "YES";
    else 
    	cout << "NO";
     
     
    return 0;
}
