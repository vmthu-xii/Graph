#include "header.h"
#include "dijkstra.h"

// https://vnoi.info/wiki/algo/graph-theory/shortest-path.md
// https://sites.google.com/site/kc97ble/algorithm-graph/dijkstra-cpp
void initDijkstra(int n, int *dist, int *pre) {
    for(int i = 0; i <= n; ++i) {
        dist[i] = int(INFINITY);
        pre[i] = -1;
    }

    return;
}

void dijkstra(int s, vector <vector <pair<int, int>> > adj, int *dist, int *pre) {
    // Sử dụng priority_queue lưu khoảng cách của các đỉnh kề tăng dần với các đỉnh đã thêm vào đồ thị
    // Vì priority_queue.top luôn là phần tử lớn nhất, ta sẽ phải sử dụng greater<pair<int,int>>
    // để priority_queue.top là phần tử nhỏ nhất
    // các phần tử lưu trong priority queue sẽ có dạng pair<dist[u],u>
    // priority_queue trong trường hợp lưu cấu trúc air<int, int> sẽ sort theo phần tử thứ nhất,
    // nên ta pair<int, int> có dạng <dist[u], u>
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {

        // Lấy ra đỉnh đầu priority_queue
        // (đỉnh u có đường đi từ s -> u ngắn nhất trong pq)
        int u = pq.top().second;
        int du = pq.top().first;

        // Xóa đỉnh đầu queue
        pq.pop();

        // dist[u] được cập nhật bởi các đỉnh trước nó để đạt min
        // nên có thể khi du nhỏ nhất trong pq thì dist[u] đã được
        // cập nhật nhỏ hơn rồi. Khi đó chắc chắn dùng du cập nhật
        // cho các đỉnh kề sẽ không nhỏ hơn -> ta bỏ qua
        if(du != dist[u])
            continue;

        // Duyệt tất cả các đỉnh v kề u
        // Nếu độ dài đường đi từ s -> v > độ dài đường đi từ s -> u + u -> v
        // Cập nhật lại độ dường đường đi s -> v
        // Cha của v là u
        // Thêm v vào priority_queue để cập nhật các đỉnh kề của v
        for(auto p : adj[u]) {
            int v = p.second;
            int uv = p.first;

            if(dist[v] > dist[u] + uv) {
                dist[v] = dist[u] + uv;
                pre[v] = u;
                pq.push({dist[v], v});
            }
        }
    }


    return;
}

void mainDijkstra() {
    // n, m: số đỉnh, số cạnh
    int n = 0, m = 0;

    // adj[u]: danh sách các đỉnh kề của u
    vector <vector <pair<int, int>> > adj;

    // Khởi tạo đồ thị n đỉnh, m cạnh, danh sách kề adj
    inputWithLength(n, m, adj);

    // dist[v]: đường đi ngắn nhất từ gốc u -> v
    int *dist = new int[n + 1];

    // pre[v] = u: u là đỉnh nối tới v
    int *pre = new int[n + 1];

    // Khởi tạo giá trị ban đầu cho các tham số
    initDijkstra(n, dist, pre);

    int s = 1;

    dijkstra(s, adj, dist, pre);

    for(int i = 1; i <= n; ++i) {
        cout << i << "\n";
        cout << "min_length(" << s << " -> " << i << ") = " << dist[i] << "\n";
        cout << "pre: " << pre[i] << "\n";
        cout << "\n";
    }

    return;
}
