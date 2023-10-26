#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

const int N = 1010;
int table[N][N], dist[N][N];

using pii = pair<int, int>;

int main(){
    int n, m; scanf("%d %d", &n, &m);

    for(int i=1; i<=n; ++i){
        for(int j=1 ; j<=m; ++j){
            scanf("%d", &table[i][j]);
            dist[i][j] = INF;
        }
    }

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    int tx[] = {-1, 1, 0, 0}, ty[] = {0, 0, -1, 1};

    pq.push({1, 1});
    dist[1][1] = table[1][1];
    while(!pq.empty()){ // dijkstra's algorithm on 2d array
        int  x = pq.top().first, y = pq.top().second;
        pq.pop();

        for(int i=0; i<4; ++i){
            int h = x + tx[i], k = y + ty[i];
            if(h < 1 || k < 1 || h > n || k > m) continue;
            int w = table[h][k];

            if(dist[x][y] + w < dist[h][k]){
                dist[h][k] = dist[x][y] + w;

                pq.push({h, k});
            }
        }
    }


    printf("%d", dist[n][m]); // shortest path
    return 0;
}
