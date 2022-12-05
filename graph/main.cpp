#include "header.h"
#include "bfs.h"
#include "dfs.h"
#include "dijkstra.h"
#include "prim.h"

int main() {

    //mainBFS();

    //mainDFS();

    //mainDijkstra();

    mainPrim();

    return 0;
}

/* BFS

https://vnoi.info/wiki/uploads/breadth-first-search_img1.png

14 15
1 2
1 3
1 4
2 5
2 6
4 7
4 8
4 9
6 10
6 11
7 11
8 12
8 13
9 13
9 14
*/

/* DFS

https://vnoi.info/wiki/uploads/Depth-First-Search-Tree_img3.png

8 7
1 8
8 2
8 4
2 3
3 5
3 6
2 7
*/

/* DIJKSTRA (test này là của trường hợp có hướng, tự kiếm test vô hướng nếu thích nhe)

// Khi nhập test này nhớ comment dòng adj[v].push_back({d,u}) inputWithLength(n, m, adj);

https://slideplayer.com/slide/14797814/90/images/29/V%C3%AD+d%E1%BB%A5+T%C3%ACm+%C4%91%C6%B0%E1%BB%9Dng+%C4%91i+ng%E1%BA%AFn+nh%E1%BA%A5t+t%E1%BB%AB+%C4%91%E1%BB%89nh+1+%C4%91%E1%BA%BFn+t%E1%BA%A5t+c%E1%BA%A3+c%C3%A1c+%C4%91%E1%BB%89nh+c%C3%B2n+l%E1%BA%A1i+6+1.jpg

6 11
1 2 1
2 3 5
2 4 2
2 6 7
3 5 2
3 6 1
4 1 2
4 3 1
4 5 4
5 4 3
6 5 10
*/

/* PRIM

https://i.imgur.com/E8xqn14.gif

6 8
0 1 5
0 2 6
1 2 1
1 3 3
1 4 1
2 3 2
3 4 7
4 5 2

*/
