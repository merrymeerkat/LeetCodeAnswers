#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

typedef vector <int> vi;
vector <vi> AL;
vi visited;

int main(){

    // get number of houses and cables
    int N, M; cin >> N >> M; 

    AL.assign(N, vi());
    visited.assign(N, 0);

    int u, v;
    while (M--){
        cin >> u >> v;
        AL[u-1].push_back(v-1);
        AL[v-1].push_back(u-1);
    }

    queue <int> houses;
    houses.push(0); visited[0] = 1;
    while (!houses.empty()){
        u = houses.front(); houses.pop();
        for (auto n : AL[u]){
            if (visited[n]) continue;
            visited[n] = 1;
            houses.push(n);
        }
    }

    if (accumulate(visited.begin(), visited.end(), 0) == N){
        cout << "Connected\n";
        return 0;
    }

    for (int i = 0; i < N; i++){
        if (!visited[i])
            cout << i + 1 << '\n';
    }
    return 0;
}
