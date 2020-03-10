#include <iostream>
 
using namespace std;
 
int INF = 1e9;
 
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int a[n + 1][n + 1];
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) a[i][j] = INF;
        }
    }
    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (a[i][k] < INF && a[k][j] < INF)
                    a[i][j] = min (a[i][j], a[i][k] + a[k][j]);
    if (a[x - 1][y - 1] != INF) cout << a[x - 1][y - 1];
        else cout << -1;
 
 
    return 0;
}
