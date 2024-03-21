#include <bits/stdc++.h>
using namespace std;
 
// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
 
    // Function to add an edge to graph
    void addEdge(int v, int w);
 
    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
    void BFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
}
 
void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
void Graph::BFS(int v){
    queue<int>q;
    q.push(v);
    visited[v]=true;
    while(!q.empty()){
        int n=q.front();
        q.pop();
        cout<<n<<endl;
        for(auto i=adj[n].begin();i!=adj[n].end();i++){
                if(!visited[*i]){
                    visited[*i]=true;
                    q.push(*i);
                }
        }
    }
}
 
// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(1, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(4, 1);
    g.addEdge(4, 2);
 
    // cout << "Following is Depth First Traversal"
    //         " (starting from vertex 2) \n";
 
    // // Function call
    // g.DFS(2);
    cout<<"Breath first search"<<endl;
    g.BFS(2);
 
    return 0;
}
 