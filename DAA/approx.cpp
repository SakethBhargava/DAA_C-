#include <bits/stdc++.h>
using namespace std;

// graph class
class undirected_graph{
public:

    // adj list
    vector<int> *vertices;
    int total_vertices;

    // constructor
    undirected_graph(int number_of_vertices){
        total_vertices = number_of_vertices;
        vertices = new vector<int>[number_of_vertices];
    }

    // function to add edge in our graph
    void addEdge(int v, int w){
        vertices[v].push_back(w);
        vertices[w].push_back(v);
    }

    // solving vertex cover problem
    void solve(){
        // visited boolean array
        vector<bool> visited(total_vertices, false);

        // visiting all of the vertices one by one
        for(int u = 0; u < total_vertices; u++){

            // if current vertex is not visited
            // process it
            if(!visited[u]){

                // visiting all of the vertices from 'u'
                for(int v : vertices[u]){

                    // if it's not already visited 
                    // mark it as visited and break the loop
                    if(!visited[v]){
                        visited[u] = visited[v] = true;
                        break;
                    }
                }
            }
        }

        // printing vertex cover
        for(int i = 0; i < total_vertices; i++){
            if(visited[i]) cout << i << " ";
        }
    }
};



int main(){ 
    // creating graph
    undirected_graph G(7);
    G.addEdge(0, 1);
    G.addEdge(1, 3);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.addEdge(4, 6);
    G.addEdge(5, 6);
    G.addEdge(6, 2);
    G.addEdge(2, 0);

    // calling the function for vertex cover problem
    cout << "Vertex cover: ";
    G.solve();
    return 0;
}