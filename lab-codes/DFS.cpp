#include <bits/stdc++.h>
using namespace std;

vector<int> vec[11];
char color[11];
int n, e;


void DFS(int source) {
    int u = source;
    color[u] = 'G';
    for (int &adjNode : vec[u])
        if (color[adjNode] == 'W') 
            DFS(adjNode);
    
    color[u] = 'B';
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

int main (void)
{
    cin >> n >> e;
    for (int i=0; i<e; i++) {
        int A, B; cin >> A >> B;
        vec[A].push_back(B);
        vec[B].push_back(A);
    }

    for (int i=1; i<=n; i++)
        color[i] = 'W';

    DFS(1);
    printAdjacencyList();

}