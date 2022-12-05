#include "header.h"
#include "prim.h"

// https://vnoi.info/wiki/algo/graph-theory/minimum-spanning-tree.md
// https://sites.google.com/site/kc97ble/algorithm-graph/prim---tim-cay-khung-nho-nhat

void initPrim(int n, int *dist, int *pre) {
    for(int i = 0; i <= n; ++i) {
        dist[i] = int(INFINITY);
        pre[i] = -1;
    }

    return;
}

int prim(int s, vector <vector <pair<int, int>> > adj, int *dist, int *pre) {
    int res = 0;
    // Sử dụng priority_queue lưu khoảng cách của các đỉnh tăng dần đối với cây khung
    // Vì priority_queue.top luôn là phần tử lớn nhất, ta sẽ phải sử dụng greater<pair<int,int>>
    // để priority_queue.top là phần tử nhỏ nhất
    // các phần tử lưu trong priority queue sẽ có dạng pair<dist[u],u>
        // priority_queue trong trường hợp lưu cấu trúc air<int, int> sẽ sort theo phần tử thứ nhất,
    // nên ta pair<int, int> có dạng <dist[u], u>
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // khởi tạo đỉnh nguồn có khoảng cách là 0 và push đỉnh này vào
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        // lấy đỉnh có khoảng cách nhỏ nhất chưa được kết nạp
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (du != dist[u]) continue;

        // kết nạp đỉnh u vào cây khung
        res += dist[u]; dist[u] = 0;

        // cập nhật khoảng cách cho các đỉnh kề u
        for (auto p : adj[u]) {
            int uv = p.first;
            int v = p.second;
            if (dist[v] > uv) {
                dist[v] = uv;
                pre[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return res;
}

void mainPrim() {
    // n, m: số đỉnh, số cạnh
    int n = 0, m = 0;

    // adj[u]: danh sách các đỉnh kề của u
    vector <vector <pair<int, int>> > adj;

    // Khởi tạo đồ thị n đỉnh, m cạnh, danh sách kề adj
    inputWithLength(n, m, adj);

    // dist[u]: khoảng cách từ nút u đến cây khung đang xây dựng
    // dist[u] = 0 khi u thuộc cây
    int *dist = new int[n + 1];

    // pre[v] = u: u là đỉnh nối tới v
    int *pre = new int[n + 1];

    // Khởi tạo giá trị ban đầu cho các tham số
    initPrim(n, dist, pre);

    int s = 0;

    cout << "w(T) = " << prim(s, adj, dist, pre) << "\n";

    for(int i = 0; i < n; ++i) {
        cout << i << "\n";
        cout << "pre: " << pre[i] << "\n";
        cout << "\n";
    }

    return;
}
