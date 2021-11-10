#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int arc[N][N];
int tsp(int n, int w){
    int edgenum = 0, TSPLength = 0;
    int min, u, v, j;
    int flag[10] = {0};
    u = w;
    flag[u] = 1;
    while (edgenum < n - 1){
        min = 100;
        for (j = 0; j < n; j++)
            if (flag[j] == 0 && arc[u][j] != 0 && arc[u][j] < min){
                v = j;
                min = arc[u][v];
            }
        TSPLength += arc[u][v];
        flag[v] = 1;
        edgenum++;
        cout << u << "-->" << v << endl;
        u = v;
    }
    cout << v << "-->" << w << endl;
    return TSPLength + arc[u][w];
}
int main(){
    int n, i, j, w;
    cin >> n >> w;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> arc[i][j];
    cout << tsp(n, w);
    return 0;
}
