#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// 图的邻接矩阵表示
class Graph {
private:
    int n; // 城市数量
    vector<vector<int>> adjMatrix; // 邻接矩阵

public:
    Graph(int n) : n(n) {
        adjMatrix.resize(n, vector<int>(n, INT_MAX)); // 初始化邻接矩阵
        for (int i = 0; i < n; i++) {
            adjMatrix[i][i] = 0; // 自己到自己是0
        }
    }

    // 增加边
    void addEdge(int u, int v, int weight) {
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adjMatrix[u][v] = weight;
            adjMatrix[v][u] = weight; // 无向图
        }
    }

    // 删除边
    void removeEdge(int u, int v) {
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adjMatrix[u][v] = INT_MAX;
            adjMatrix[v][u] = INT_MAX;
        }
    }

    // 修改边
    void modifyEdge(int u, int v, int newWeight) {
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adjMatrix[u][v] = newWeight;
            adjMatrix[v][u] = newWeight; // 无向图
        }
    }

    // 显示邻接矩阵
    void display() {
        cout << "邻接矩阵: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjMatrix[i][j] == INT_MAX) {
                    cout << "INF ";
                } else {
                    cout << adjMatrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    // 获取边的权重
    int getWeight(int u, int v) {
        return adjMatrix[u][v];
    }

    // 获取城市数量
    int getCityCount() {
        return n;
    }
};

// Prim算法实现
void prim(Graph graph, int start) {
    int n = graph.getCityCount();
    vector<bool> inMST(n, false); // 记录每个节点是否在最小生成树中
    vector<int> key(n, INT_MAX);   // 用于记录最小权重边
    vector<int> parent(n, -1);     // 用于记录生成树中的父节点

    key[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        // 选择权重最小的边
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        inMST[u] = true;

        // 更新相邻节点的key值
        for (int v = 0; v < n; v++) {
            int weight = graph.getWeight(u, v);
            if (weight != INT_MAX && !inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    // 输出最小生成树的边
    cout << "使用Prim算法构建的最小生成树:\n";
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " 权值: " << graph.getWeight(parent[i], i) << endl;
        }
    }
}

// Kruskal算法实现
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& e) const {
        return weight < e.weight;
    }
};

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

void kruskal(int n, Graph graph) {
    vector<Edge> edges;
    // 收集所有的边
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int weight = graph.getWeight(i, j);
            if (weight != INT_MAX) {
                edges.push_back({i, j, weight});
            }
        }
    }

    sort(edges.begin(), edges.end()); // 按照边的权值排序

    UnionFind uf(n);
    vector<Edge> mst;
    int mstWeight = 0;

    // Kruskal算法
    for (const Edge& e : edges) {
        if (uf.find(e.u) != uf.find(e.v)) {
            uf.unionSets(e.u, e.v);
            mst.push_back(e);
            mstWeight += e.weight;
        }
    }

    // 输出最小生成树的边
    cout << "使用Kruskal算法构建的最小生成树:\n";
    for (const Edge& e : mst) {
        cout << e.u << " - " << e.v << " 权值: " << e.weight << endl;
    }
    cout << "最小生成树的总权值: " << mstWeight << endl;
}

// 主函数
int main() {
    int n, choice;
    cout << "请输入城市的数量: ";
    cin >> n;

    Graph graph(n);
    while (true) {
        cout << "\n1. 增加边\n2. 删除边\n3. 修改边\n4. 显示邻接矩阵\n5. 使用Prim算法构建通信网\n6. 使用Kruskal算法构建通信网\n7. 退出\n";
        cout << "请输入选择: ";
        cin >> choice;

        if (choice == 1) {
            int u, v, w;
            cout << "请输入两个城市编号（0-" << n-1 << "）和边的权重: ";
            cin >> u >> v >> w;
            graph.addEdge(u, v, w);
        }
        else if (choice == 2) {
            int u, v;
            cout << "请输入要删除的两个城市编号（0-" << n-1 << "）: ";
            cin >> u >> v;
            graph.removeEdge(u, v);
        }
        else if (choice == 3) {
            int u, v, w;
            cout << "请输入两个城市编号（0-" << n-1 << "）和新的权重: ";
            cin >> u >> v >> w;
            graph.modifyEdge(u, v, w);
        }
        else if (choice == 4) {
            graph.display();
        }
        else if (choice == 5) {
            int start;
            cout << "请输入起始城市编号: ";
            cin >> start;
            prim(graph, start);
        }
        else if (choice == 6) {
            kruskal(n, graph);
        }
        else if (choice == 7) {
            break;
        }
        else {
            cout << "无效选择，请重新输入。" << endl;
        }
    }
    return 0;
}
