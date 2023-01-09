#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> adj;
int n, m;

void bestFirstGreedySearch(int start, unordered_set<int> &goals, int &foundAll, vector<int> &order, vector<int> &path, vector<int> &par, vector<bool> &vis, map<int, vector<int>> &paths) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    vis[start] = true;
    while (!pq.empty()) {
        int node = pq.top().second;
        order.push_back(node);
        pq.pop();
        vis[node] = true;
        if (goals.find(node) != goals.end()) {
            --foundAll;
        }
        if (foundAll == 0) {
            break;
        }
        int sz = adj[node].size();
        for (int i = 0; i < sz; ++i) {
            int child = adj[node][i].second;
            if (vis[child] == false) {
                vis[child] = true;
                par[child] = node;
                pq.push({adj[node][i].first, child});
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

signed main()
{
    cout << "Enter no of nodes: \n";
    cin >> n;
    cout << "Enter no of edges: \n";
    cin >> m;
    cout << "Enter " << m << " edges in the form <a> <b> <w> for a directed edge like <a> -> <b> with weight <w>: \n";
    
    adj = vector<vector<pair<int, int>>>(n);
    
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
    }
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
    bestFirstGreedySearch(s, goals, foundAll, order, path, par, vis, paths);
    cout << "Order of Best First Greedy Search: \n";
    int sz = order.size();
    for (int i = 0; i < sz; ++i) {
        if (i != sz - 1)
            cout << order[i] << " -> ";
        else
            cout << order[i] << "\n";
    }
    cout << "\n";
    cout << "Paths of Best First Greedy Search: \n";
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
    return 0;
}