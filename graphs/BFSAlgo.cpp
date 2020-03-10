#include <iostream>
#include <vector>
#include <queue>


using namespace std;

vector <int> g[10000];
int n, kol = 0;
bool isVisited[10000] = {false, };
int par[1000];
int dist[1000] = {0, };

void bfs(int x) {
	queue <int> q;
	q.push(x);
	//bool isVisited[10000] = {false, };
	isVisited[x] = true;
	dist[x] = 0;

    par[x] = -1;
	while (!q.empty()) {
		int i = q.front();
	//	cout << q.size() << endl;
		q.pop();
		for (int j : g[i]) {
		//	cout << i << " " << j << " " << isVisited[j] << endl;
			if (!isVisited[j]) {
				isVisited[j] = true;
				q.push(j);
				dist[j] = dist[i] + 1;
				par[j] = i;
			}
		}
	}
}

int main() {
	int m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int mm;
			cin >> mm;
			if (mm) {
				g[i].push_back(j);
			}
		}
	}
	//for (int i = 0; i <= n; i++)cout << isVisited[i] << " "; cout << endl;
	int b, e;
	cin  >> b >> e;
	bfs(b);
	int ind = par[e];
	if (!isVisited[e]) {
        cout << "-1";
        return 0;
    } else if (dist[e] == 0) {
        cout << 0;
        return 0;
    } else {
        cout << dist[e] << "\n";
        vector <int> rez;
        while (ind != 0) {
            rez.push_back(ind);
            ind = par[ind];
        }
        for (int i = rez.size() - 2; i >= 0; i--) {
            cout << rez[i] << " ";
        }
        cout << e << " ";
    }



	return 0;
}
