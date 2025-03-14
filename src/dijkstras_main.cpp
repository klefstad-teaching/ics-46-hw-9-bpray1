#include "dijkstras.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <graph_file>" << endl;
        return 1;
    }
    
    string filename = argv[1];
    Graph G;
    
    try {
        file_to_graph(filename, G);
        cout << "Graph loaded from " << filename << " with " << G.numVertices << " vertices." << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    // Source vertex is 0
    int source = 0;
    vector<int> previous;
    
    // Run Dijkstra's algorithm
    vector<int> distances = dijkstra_shortest_path(G, source, previous);
    
    cout << "\nShortest paths from vertex " << source << ":" << endl;
    cout << "=====================================" << endl;
    
    // Extract and print the shortest path to each vertex
    for (int i = 0; i < G.numVertices; ++i) {
        vector<int> path = extract_shortest_path(distances, previous, i);
        
        cout << "To vertex " << i << ": ";
        if (distances[i] == INF) {
            cout << "No path exists." << endl;
        } else {
            print_path(path, distances[i]);
        }
    }
    
    return 0;
}