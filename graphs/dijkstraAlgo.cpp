#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, s, f;
vector < pair <int, int> > g[10000];
vector < int > unvisited;
int dist[10000];

bool cmp(int a, int b) {
    return dist[a] < dist[b];
}

void dijkstra() {
    while (unvisited.size()) {
    	sort(unvisited.begin(), unvisited.end(), cmp);
        int i = unvisited[0];
        unvisited.erase(unvisited.begin());
        if (dist[i] == 10e7) continue;
        //cout << i << endl;
        for (auto j : g[i]) {
            dist[j.first] = min(dist[j.first], dist[i] + j.second);
        }
        //for (int i = 1; i <= n; i++) {
        //	cout << dist[i] << " ";
        //}
       // cout << endl;

    }
}

int main() {
    cin >> n >> s >> f;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		int c;
    		cin >> c;
    		if (c && c != -1) {
    			g[i].push_back({ j, c });
    			//g[j].push_back({ i, c });
    		}
    	}
    }
    for (int i = 1; i <= n; i++) {
        unvisited.push_back(i);
        dist[i] = 10e7;
    }
    dist[s] = 0;
    dijkstra();
    if (dist[f] != 10e7) {
    	cout << dist[f];
    } else cout << -1;

    return 0;
}
