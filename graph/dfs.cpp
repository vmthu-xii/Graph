#include "header.h"
#include "dfs.h"

int timeDfs = 0;

void dfs(int u, vector <vector <int> > adj, int *d, int *parent, bool *isVisit, int *num, int *tail) {

    // Đánh dấu đỉnh u đã thăm
    isVisit[u] = true;

    // num[u]: Thứ tự/ Thời điểm duyệt đến đỉnh u
    num[u] = ++timeDfs;

    // Duyệt tất cả các đỉnh v kề u
    // Nếu v chưa được thăm thì bắt đầu thăm v
    // Độ cài đường đi từ s -> v = Độ dài đường đi từ s -> u + 1
    // Cha của v là u
    // Thăm v
    for(int v : adj[u]) {
        if(!isVisit[v]) {
            d[v] = d[u] + 1;
            parent[v] = u;
            dfs(v, adj, d, parent, isVisit, num, tail);
        }
    }

    // tail[u]: Thời điểm duyệt hết cây gốc u
    tail[u] = timeDfs;

    return;
}

void mainDFS() {
    // n, m: số đỉnh, số cạnh
    int n = 0, m = 0;

    // adj[u]: danh sách các đỉnh kề của u
    vector <vector <int> > adj;

    // Khởi tạo đồ thị n đỉnh, m cạnh, danh sách kề adj
    input(n, m, adj);

    // d[v]: độ dài từ gốc u -> v
    int *d = new int[n + 1];

    // parent[v] = u: u là cha của v
    int *parent = new int[n + 1];

    // isVisit[v] = true: đỉnh v đã được thăm
    bool *isVisit = new bool[n + 1];

    // num[u]: Thứ tự/ Thời điểm duyệt đến đỉnh u
    int *num = new int[n + 1];

    // tail[u]: Thời điểm duyệt hết cây gốc u
    int *tail = new int[n + 1];

    // Khởi tạo giá trị ban đầu cho các tham số
    init(n, d, parent, isVisit);

    int s = 1;

    dfs(s, adj, d, parent, isVisit, num, tail);

    for(int i = 1; i <= n; ++i) {
        cout << i << "\n";
        cout << "length(" << s << " -> " << i << ") = " << d[i] << "\n";
        cout << "parent: " << parent[i] << "\n";
        cout << "num: " << num[i] << "\n";
        cout << "tail: " << tail[i] << "\n";
        cout << "\n";
    }

    return;
}
