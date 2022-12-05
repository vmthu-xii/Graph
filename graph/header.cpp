#include "header.h"

void input(int &n, int &m, vector <vector <int> > &adj) {
    cin >> n;
    cin >> m;
    adj.resize(n + 1);

    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return;
}

void init(int n, int *d, int *parent, bool *isVisit) {
    for(int i = 0; i <= n; ++i) {
        d[i] = 0;
        parent[i] = -1;
        isVisit[i] = false;
    }

    return;
}

void inputWithLength(int &n, int &m, vector <vector <pair<int, int>> > &adj) {
    cin >> n;
    cin >> m;
    adj.resize(n + 1);

    for(int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
    }

    return;
}
