#include "header.h"
#include "bfs.h"

void bfs(int s, vector <vector <int> > adj, int *d, int *parent, bool *isVisit) {

    // Khởi tạo queue chứa các đỉnh đã thăm
    queue <int> qu;
    qu.push(s);

    // Đánh dấu đỉnh s đã thăm
    isVisit[s] = true;

    while(!qu.empty()) {

        // Lấy ra đỉnh đầu queue
        int u = qu.front();

        // Xóa đỉnh đầu queue
        qu.pop();

        // Duyệt tất cả các đỉnh v kề u
        // Nếu v chưa được thăm thì bắt đầu thăm v
        // Độ cài đường đi từ s -> v = Độ dài đường đi từ s -> u + 1
        // Cha của v là u
        // Đánh dấu v đã được thăm
        // Thêm v vào queue để chờ thăm các đỉnh kề của v
        for(int v : adj[u]) {
            if(!isVisit[v]) {
                d[v] = d[u] + 1;
                parent[v] = u;
                isVisit[v] = true;
                qu.push(v);
            }
        }
    }

    return;
}

void mainBFS() {

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

    // Khởi tạo giá trị ban đầu cho các tham số
    init(n, d, parent, isVisit);

    int s = 1;

    bfs(s, adj, d, parent, isVisit);

    for(int i = 1; i <= n; ++i) {
        cout << i << "\n";
        cout << "length(" << s << " -> " << i << ") = " << d[i] << "\n";
        cout << "parent: " << parent[i] << "\n";
        cout << "\n";
    }

    return;
}
