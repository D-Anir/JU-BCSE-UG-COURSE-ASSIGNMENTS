#include<bits/stdc++.h>
#define INF 100001
using namespace std;


class Node{
    public:
    int u;
    int curr;
    int h;
    Node(int u,int curr,int h){
        this->u=u;
        this->curr=curr;
        this->h=h;
    }
    bool operator< (const Node &n) const{
        return (curr+h>n.curr+n.h);
    }
};

void Astar(int s,int end,vector<vector<pair<int,int>>> adj,vector<int> heur,vector<int> &order){
    int n=heur.size();
    priority_queue<Node> q;
    vector<int> dist(n,INF);
    dist[s]=heur[s];
    q.push(Node(s,0,heur[s]));
    while(!q.empty()){
        Node n=q.top();q.pop();
        int u=n.u;
        int curr=n.curr;
        if(curr+heur[u]!=dist[u])continue;
        order.push_back(u);
        if(u==end){
            cout<<"Done";
            return;
        }
        for(auto e:adj[u]){
            int v=e.first;
            if(curr+e.second+heur[v]<dist[v]){
                dist[v]=curr+heur[v]+e.second;
                q.push(Node(v,curr+e.second,heur[v]));
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter number of node:\n";
    cin>>n;
    vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
    int e;
    cout<<"Enter number of edges:\n";
    cin>>e;
    while(e--){
        int u,v,w;
        cout<<"Enter u-->v and w: ";
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<int> heur(n,0);
    cout<<"Enter heuristic values for the nodes:\n";
    for(int i=0;i<n;i++){
        cin>>heur[i];
    }
    int start,end;
    cout<<"Enter start node: ";
    cin>>start;
    cout<<"Enter end node: ";
    cin>>end;
    vector<int> order;
    Astar(start,end,adj,heur,order);
    for(int i=0;i<n;i++)cout<<order[i]<<" ";
}