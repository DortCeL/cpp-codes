#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> vec[11];
int level[11];
int parent[11];


void BFS(int source) {
    level[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int &element : vec[u]) {
            if (level[element] == -1) {
                parent[element] = u;
                level[element] = level[u]+1;
                q.push(element);
            }
        }
    }
}

void printAdjacencyList() {
    for (int i=1; i<=n; i++) {
        cout << i << " ==> ";
        for (int &edge : vec[i]) 
            cout << edge << " ";
        cout << endl;
    }
    cout << endl;
}

void path(int des) {
    if (parent[des] != des)
        path(parent[des]);

    cout << des << " ";
}

int main (void )
{
    cin >> n >> e;

    for (int i=0; i<e; i++) {
        int A, B; cin >> A >> B;
        vec[A].push_back(B);
        vec[B].push_back(A);
    }

    for (int i=1; i<=n; i++) {
        level[i] = -1;
        parent[i] = i;
    }

    BFS(1);
    printAdjacencyList();
    cout << "Shortest path distance is : " << level[10] << endl;
    path(10);

}