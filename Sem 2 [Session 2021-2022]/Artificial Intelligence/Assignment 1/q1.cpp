#include<iostream>
#include<list>
#include<string>
using namespace std;

class Graph{
    int vertices;
    list<int> *adj;
    bool *visited;

    public:
        Graph(){
            vertices = 0;
            adj = NULL;
            visited = NULL;
        }

        Graph(int v){
            vertices = v;
            adj = new list<int>[vertices];
            visited = new bool[vertices];
            for(int i=0; i<vertices; i++){
                visited[i] = false;
            }
        }

        void addEdge(int v, int w){
            adj[v].push_back(w);
        }

        void DFS(int item){
            visited[item] = true;
            cout<< item << "->";
            list<int>::iterator vertex;
            for(vertex = adj[item].begin(); vertex != adj[item].end(); ++vertex){
                if(!visited[*vertex]){
                    DFS(*vertex);
                }
            }
        }

        void DLS(int item, int i, int depth){
            for(i = 0; i < depth; i++){
                visited[item] = true;
                cout<< item << "->";
                list<int>::iterator vertex;
                for(vertex = adj[item].begin(); vertex != adj[item].end(); ++vertex){
                    if(!visited[*vertex]){
                        DLS(*vertex, i, depth-1);
                    }
                }
            }
        }

        void BFS(int item){
            bool *visited = new bool[vertices];
            for(int i=0; i<vertices; i++){
                visited[i] = false;
            }

            list<int> queue;
            visited[item] = true;
            queue.push_back(item);

            list<int>::iterator vertex;

            while(!queue.empty()){
                item = queue.front();
                cout<<item<<"->";
                queue.pop_front();

                for(vertex = adj[item].begin(); vertex != adj[item].end(); ++vertex){
                    if(!visited[*vertex]){
                        visited[*vertex] = true;
                        queue.push_back(*vertex);
                    }
                }
            }
        }

        int getVertices(){
            return vertices;
        }
};

int searchMenu() {
    int choice;
    cout<<"1. BFS.\n";
    cout<<"2. DFS.\n";
    cout<<"3. DLS.\n";
    cout<<"4. Iterative Depending Search.\n";
    cout<<"5. IBS.\n";
    cout<<"Enter Uninformed Search Technique: ";
    cin>>choice;
    return choice;
}

int problemMenu(){
    int choice;
    cout<<"1. Graph.\n";
    cout<<"2. Puzzle Problem.\n";
    cout<<"Enter Youur Problem Type: ";
    cin>>choice;
    return choice;
}

Graph initGraph(){
    int vertices;
    cout<<"Enter Number of Vertices in the Graph:\n";
    cin>>vertices;
    Graph graph(vertices);

    int addMoreEdge;
    cout<<"*Press 1 to Add Edges to the Graph*\n";
    cin>>addMoreEdge;
    if(addMoreEdge == 0){
        cout<<"No Edges Found..terminating.\n";
        exit(0);
    }

    while(addMoreEdge == 1){
        int a, b;
        cout<<"\nEnter Two Ends of the Current Edge:\n";
        cout<<"Enter First End: ";
        cin>>a;
        cout<<"Enter Second End: ";
        cin>>b;
        graph.addEdge(a, b);
        cout<<"Want to add more edges? Press 1 to continue 0 to exit.\n";
        cin>>addMoreEdge;
    }
    return graph;
}

void dfsOnGraph(){
    Graph graph = initGraph();
    int vertex;
    cout<<"Enter the vertex to be searched: ";
    cin>>vertex;
    cout<<"The DFS on the entered graph is as follows:\n";
    graph.DFS(vertex);
}

void bfsOnGraph(){
    Graph graph = initGraph();
    int vertex;
    cout<<"Enter the vertex to be searched: ";
    cin>>vertex;
    cout<<"The BFS on the entered graph is as follows:\n";
    graph.BFS(vertex);
}

void dlsOnGraph(){
    Graph graph = initGraph();
    int vertex, depth;
    cout<<"Enter the vertex to be searched: ";
    cin>>vertex;
    cout<<"Enter Depth Limit for DLS Algorithm: ";
    cin>>depth;
    while(depth > graph.getVertices()){
        cout<<"Invalid Depth Limit! Enter a value less than or equal to "<<graph.getVertices()<<".\n";
        cout<<"Enter Depth Limit for DLS Algorithm: ";
        cin>>depth;
    }
    cout<<"The BFS on the entered graph is as follows:\n";
    graph.DLS(vertex, 0, depth);
}

void dfsOnPuzzle(){

}

void bfsOnPuzzle(){

}

void dlsOnPuzzle(){
    
}

int main(){
    int searchTechnique = searchMenu();
    int problemType = problemMenu();

    switch(searchTechnique){
        case 1:
            switch(problemType){
                case 1:
                    bfsOnGraph();
                    break;
                case 2:
                    bfsOnPuzzle();
                    break;
                default:
                    cout<<"Invalid Problem Type Selected!!\n";
            }
            break;
        case 2:
            switch(problemType){
                case 1:
                    dfsOnGraph();
                    break;
                case 2:
                    dfsOnPuzzle();
                    break;
                case 3:
                    
                default:
                    cout<<"Invalid Problem Type Selected!!\n";
            }
            break;
        case 3:
            switch(problemType){
                case 1:
                    dlsOnGraph();
                    break;
                case 2:
                    dlsOnPuzzle();
                    break;
                case 3:
                    
                default:
                    cout<<"Invalid Problem Type Selected!!\n";
            }
            break;
    }
}