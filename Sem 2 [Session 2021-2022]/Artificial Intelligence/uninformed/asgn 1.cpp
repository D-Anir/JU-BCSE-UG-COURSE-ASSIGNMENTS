/*
    Anirban Das
    JU BCSE III
    001910501077
*/

#include <bits/stdc++.h>
#include <set>

using namespace std;

template <typename T>
class Node {
    T data;
    // other attributes;
public:
    // Node(T val) {
    //     data = val;
    // }
    void input() {
        cout << "Enter data: \n";
        cin >> data;
    }
    T get() {
        return data;
    }
};

template <typename T>
class Graph {
    int n;  // no of nodes
    int m;  // no of edges
    vector< Node< T > > nodelist; // details of node
    vector< vector<int> > adj;    // adjacency matrix for graph
public:
    // Input
    void input() {
        cout << "Enter no of nodes: \n";
        cin >> n;
        nodelist = vector< Node< T > >(n);
        adj = vector< vector<int> >(n);
        cout << "Enter node details for " << n << " nodes: \n";
        for (int i = 0; i < n; ++i) {
            cout << "For " << i << "\'th node: \n";
            nodelist[i].input();
        }
        cout << "Enter no of edges: \n";
        cin >> m;
        cout << "Enter " << m << " edges in the form <a> <b> for a directed edge like <a> -> <b>: \n";
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }
    }
    // DFS
    void dfs(int node, unordered_set<int> &goals, int &foundAll, vector<int> &order, vector<int> &path, vector<bool> &vis, map<int, vector<int>> &paths) {
        path.push_back(node);
        order.push_back(node);
        vis[node] = true;
        if (foundAll == 0)
            return;
        if (goals.find(node) != goals.end()) {
            paths[node] = path;
            --foundAll;
        }
        int sz = adj[node].size();
        for (int i = 0; i < sz; ++i) {
            int child = adj[node][i];
            if (vis[child] == false) {
                dfs(child, goals, foundAll, order, path, vis, paths);
                if (foundAll == 0)
                    return;
            }
        }
        path.pop_back();
    }
    // BFS
    void bfs(int start, unordered_set<int> &goals, int &foundAll, vector<int> &order, vector<int> &path, vector<int> &par, vector<bool> &vis, map<int, vector<int>> &paths) {
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = true;
            order.push_back(node);
            if (goals.find(node) != goals.end()) {
                --foundAll;
            }
            if (foundAll == 0) {
                break;
            }
            int sz = adj[node].size();
            for (int i = 0; i < sz; ++i) {
                int child = adj[node][i];
                if (vis[child] == false) {
                    vis[child] = true;
                    par[child] = node;
                    q.push(child);
                }
            }
        }

        for (auto itr = goals.begin(); itr != goals.end(); ++itr) {
            int goal = *itr;
            path.clear();
            while (par[goal] != -1 && goal != start) {
                path.push_back(goal);
                goal = par[goal];
            }
            path.push_back(goal);
            reverse(path.begin(), path.end());
            paths[*itr] = path;
        }
    }
    // DLS
    void dls(int node, unordered_set<int> &goals, int limit, int &foundAll, vector<int> &order, vector<int> &path, vector<bool> &vis, map<int, vector<int>> &paths) {
        path.push_back(node);
        order.push_back(node);
        vis[node] = true;
        if (foundAll == 0)
            return;
        if (goals.find(node) != goals.end()) {
            paths[node] = path;
            --foundAll;
        }
        int sz = adj[node].size();
        for (int i = 0; i < sz; ++i) {
            int child = adj[node][i];
            if (vis[child] == false) {
                if (limit > 0)
                    dls(child, goals, limit - 1, foundAll, order, path, vis, paths);
                if (foundAll == 0)
                    return;
            }
        }
        path.pop_back();
    }
    // IDS
    int ids(int node, unordered_set<int> &goals, int max_depth, int &foundAll, vector<int> &order, vector<int> &path, vector<bool> &vis, map<int, vector<int>> &paths) {
        for (int depth = 0; depth <= max_depth; ++depth) {
            int f = foundAll;
            order.clear();
            path.clear();
            vis = vector<bool>(n, false);
            paths.clear();
            dls(node, goals, depth, f, order, path, vis, paths);
            if (f == 0) {
                foundAll = 0;
                return depth;
            }
        }
        return -1;
    }
    // BLS
    void bls(int start, unordered_set<int> &goals, int limit, int &foundAll, vector<int> &order, vector<int> &path, vector<int> &par, vector<bool> &vis, map<int, vector<int>> &paths) {
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = true;
            order.push_back(node);
            if (goals.find(node) != goals.end()) {
                --foundAll;
            }
            if (foundAll == 0) {
                break;
            }
            int sz = adj[node].size();
            for (int i = 0; i < min(limit, sz); ++i) {
                int child = adj[node][i];
                if (vis[child] == false) {
                    vis[child] = true;
                    par[child] = node;
                    q.push(child);
                }
            }
        }

        for (auto itr = goals.begin(); itr != goals.end(); ++itr) {
            int goal = *itr;
            path.clear();
            while (par[goal] != -1 && goal != start) {
                path.push_back(goal);
                goal = par[goal];
            }
            path.push_back(goal);
            reverse(path.begin(), path.end());
            paths[*itr] = path;
        }
    }
    // IBS
    int ibs(int node, unordered_set<int> &goals, int max_breadth, int &foundAll, vector<int> &order, vector<int> &path, vector<int> &par, vector<bool> &vis, map<int, vector<int>> &paths) {
        for (int breadth = 0; breadth <= max_breadth; ++breadth) {
            int f = foundAll;
            order.clear();
            path.clear();
            par = vector<int>(n, -1);
            vis = vector<bool>(n, false);
            paths.clear();
            bls(node, goals, breadth, f, order, path, par, vis, paths);
            if (f == 0) {
                foundAll = 0;
                return breadth;
            }
        }
        return -1;
    }
    // Menu
    void menu() {
        while (1) {
            cout << "\n Select an option:\n";
            cout << "1. Input/Reset the graph.\n";
            cout << "2. DFS.\n";
            cout << "3. BFS.\n";
            cout << "4. DLS.\n";
            cout << "5. IDS.\n";
            cout << "6. IBS.\n";
            cout << "7. Exit.\n";
            int choice;
            cin >> choice;
            switch (choice) {
            case 1:
            {
                input();
            }
            break;
            case 2:
            {
                int s, dcnt, d;
                unordered_set<int> goals;
                cout << "Enter start node: \n";
                cin >> s;
                cout << "Enter no of goal nodes: \n";
                cin >> dcnt;
                vector<int> ds(dcnt);
                cout << "Enter goal nodes: \n";
                for (int i = 0; i < dcnt; ++i) {
                    cin >> d;
                    ds[i] = d;
                    goals.insert(d);
                }
                vector<int> path, order;
                map<int, vector<int>> paths;
                vector<bool> vis(n, false);
                int foundAll = dcnt;
                dfs(s, goals, foundAll, order, path, vis, paths);
                cout << "Order of DFS: \n";
                int sz = order.size();
                for (int i = 0; i < sz; ++i) {
                    if (i != sz - 1)
                        cout << order[i] << " -> ";
                    else
                        cout << order[i] << "\n";
                }
                cout << "\n";
                cout << "Paths of DFS: \n";
                for (int i = 0; i < dcnt; ++i) {
                    cout << "Path to " << ds[i] << ":\n";
                    int sz = paths[ds[i]].size();
                    if (sz == 0) {
                        cout << "No Path Found.\n";
                    } else {
                        for (int j = 0; j < sz; ++j) {
                            if (j != sz - 1)
                                cout << paths[ds[i]][j] << " -> ";
                            else
                                cout << paths[ds[i]][j] << "\n";
                        }
                    }
                }
            }
            break;
            case 3:
            {
                int s, dcnt, d;
                unordered_set<int> goals;
                cout << "Enter start node: \n";
                cin >> s;
                cout << "Enter no of goal nodes: \n";
                cin >> dcnt;
                vector<int> ds(dcnt);
                cout << "Enter goal nodes: \n";
                for (int i = 0; i < dcnt; ++i) {
                    cin >> d;
                    ds[i] = d;
                    goals.insert(d);
                }
                vector<int> path, order, par(n, -1);
                map<int, vector<int>> paths;
                vector<bool> vis(n, false);
                int foundAll = dcnt;
                bfs(s, goals, foundAll, order, path, par, vis, paths);
                cout << "Order of BFS: \n";
                int sz = order.size();
                for (int i = 0; i < sz; ++i) {
                    if (i != sz - 1)
                        cout << order[i] << " -> ";
                    else
                        cout << order[i] << "\n";
                }
                cout << "\n";
                cout << "Paths of BFS: \n";
                for (int i = 0; i < dcnt; ++i) {
                    cout << "Path to " << ds[i] << ":\n";
                    int sz = paths[ds[i]].size();
                    if (sz == 0) {
                        cout << "No Path Found.\n";
                    } else {
                        for (int j = 0; j < sz; ++j) {
                            if (j != sz - 1)
                                cout << paths[ds[i]][j] << " -> ";
                            else
                                cout << paths[ds[i]][j] << "\n";
                        }
                    }
                }
            }
            break;
            case 4:
            {
                int s, dcnt, d, limit;
                unordered_set<int> goals;
                cout << "Enter start node: \n";
                cin >> s;
                cout << "Enter no of goal nodes: \n";
                cin >> dcnt;
                vector<int> ds(dcnt);
                cout << "Enter goal nodes: \n";
                for (int i = 0; i < dcnt; ++i) {
                    cin >> d;
                    ds[i] = d;
                    goals.insert(d);
                }
                cout << "Enter depth limit for DLS: \n";
                cin >> limit;
                vector<int> path, order;
                map<int, vector<int>> paths;
                vector<bool> vis(n, false);
                int foundAll = dcnt;
                dls(s, goals, limit, foundAll, order, path, vis, paths);
                cout << "Order of DLS: \n";
                int sz = order.size();
                for (int i = 0; i < sz; ++i) {
                    if (i != sz - 1)
                        cout << order[i] << " -> ";
                    else
                        cout << order[i] << "\n";
                }
                cout << "\n";
                cout << "Paths of DLS: \n";
                for (int i = 0; i < dcnt; ++i) {
                    cout << "Path to " << ds[i] << ":\n";
                    int sz = paths[ds[i]].size();
                    if (sz == 0) {
                        cout << "No Path Found.\n";
                    } else {
                        for (int j = 0; j < sz; ++j) {
                            if (j != sz - 1)
                                cout << paths[ds[i]][j] << " -> ";
                            else
                                cout << paths[ds[i]][j] << "\n";
                        }
                    }
                }
            }
            break;
            case 5:
            {
                int s, dcnt, d, limit;
                unordered_set<int> goals;
                cout << "Enter start node: \n";
                cin >> s;
                cout << "Enter no of goal nodes: \n";
                cin >> dcnt;
                vector<int> ds(dcnt);
                cout << "Enter goal nodes: \n";
                for (int i = 0; i < dcnt; ++i) {
                    cin >> d;
                    ds[i] = d;
                    goals.insert(d);
                }
                cout << "Enter max depth limit for IDS: \n";
                cin >> limit;
                vector<int> path, order;
                map<int, vector<int>> paths;
                vector<bool> vis(n, false);
                int foundAll = dcnt;
                int foundAtLimit = ids(s, goals, limit, foundAll, order, path, vis, paths);
                cout << "Order of IDS: \n";
                int sz = order.size();
                for (int i = 0; i < sz; ++i) {
                    if (i != sz - 1)
                        cout << order[i] << " -> ";
                    else
                        cout << order[i] << "\n";
                }
                cout << "\n";
                if (foundAtLimit == -1) {
                    cout << "IDS exhausted at depth limit " << limit << ". Couldn\'t reach all goals.\n";
                } else {
                    cout << "All goals were found by limit: " << foundAtLimit << "\n";
                    cout << "Paths of IDS: \n";
                    for (int i = 0; i < dcnt; ++i) {
                        cout << "Path to " << ds[i] << ":\n";
                        int sz = paths[ds[i]].size();
                        if (sz == 0) {
                            cout << "No Path Found.\n";
                        } else {
                            for (int j = 0; j < sz; ++j) {
                                if (j != sz - 1)
                                    cout << paths[ds[i]][j] << " -> ";
                                else
                                    cout << paths[ds[i]][j] << "\n";
                            }
                        }
                    }
                }
            }
            break;
            case 6:
            {
                int s, dcnt, d, limit;
                unordered_set<int> goals;
                cout << "Enter start node: \n";
                cin >> s;
                cout << "Enter no of goal nodes: \n";
                cin >> dcnt;
                vector<int> ds(dcnt);
                cout << "Enter goal nodes: \n";
                for (int i = 0; i < dcnt; ++i) {
                    cin >> d;
                    ds[i] = d;
                    goals.insert(d);
                }
                cout << "Enter max depth limit for IBS: \n";
                cin >> limit;
                vector<int> path, order, par(n, -1);
                map<int, vector<int>> paths;
                vector<bool> vis(n, false);
                int foundAll = dcnt;
                int foundAtLimit = ibs(s, goals, limit, foundAll, order, path, par, vis, paths);
                cout << "Order of IBS: \n";
                int sz = order.size();
                for (int i = 0; i < sz; ++i) {
                    if (i != sz - 1)
                        cout << order[i] << " -> ";
                    else
                        cout << order[i] << "\n";
                }
                cout << "\n";
                if (foundAtLimit == -1) {
                    cout << "IBS exhausted at breadth limit " << limit << ". Couldn\'t reach all goals.\n";
                } else {
                    cout << "All goals were found by limit: " << foundAtLimit << "\n";
                    cout << "Paths of IBS: \n";
                    for (int i = 0; i < dcnt; ++i) {
                        cout << "Path to " << ds[i] << ":\n";
                        int sz = paths[ds[i]].size();
                        if (sz == 0) {
                            cout << "No Path Found.\n";
                        } else {
                            for (int j = 0; j < sz; ++j) {
                                if (j != sz - 1)
                                    cout << paths[ds[i]][j] << " -> ";
                                else
                                    cout << paths[ds[i]][j] << "\n";
                            }
                        }   
                    }
                }
            }
            break;
            case 7:
            {
                exit(0);
            }
            break;
            default:
                cout << "Invalid Option!\n";
            }
        }
    }

};

signed main() {

    Graph<int> G;
    G.menu();

    return 0;
}