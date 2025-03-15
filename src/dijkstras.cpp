#include "dijkstras.h"
#include <algorithm> // For reverse function

// Comparator for priority queue in Dijkstra's algorithm
struct NodeComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // Min-heap based on distance
    }
};

// Dijkstra's algorithm implementation
vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    
    // Safety check for empty graph
    if (n <= 0) {
        return vector<int>();
    }
    
    // Safety check for invalid source
    if (source < 0 || source >= n) {
        cerr << "Invalid source vertex: " << source << endl;
        return vector<int>(n, INF);
    }
    
    // Initialize distance and previous arrays
    vector<int> distances(n, INF);
    previous.resize(n, -1);
    vector<bool> visited(n, false);
    
    // Distance to source vertex is 0
    distances[source] = 0;
    
    // Priority queue to store vertices by their current distance
    // pair<vertex, distance>
    priority_queue<pair<int, int>, vector<pair<int, int>>, NodeComparator> pq;
    pq.push(make_pair(source, 0));
    
    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        
        // Skip if already visited
        if (visited[u]) {
            continue;
        }
        
        // Mark as visited
        visited[u] = true;
        
        // Check all adjacent vertices
        for (const Edge& edge : G[u]) {
            int v = edge.dst;
            
            // Safety check for invalid destination
            if (v < 0 || v >= n) {
                continue;
            }
            
            int weight = edge.weight;
            
            // Relaxation step: If we've found a shorter path to v through u
            if (!visited[v] && distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push(make_pair(v, distances[v]));
            }
        }
    }
    
    return distances;
}

// Extract the shortest path from the previous array
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    
    // Safety check for empty arrays
    if (distances.empty() || previous.empty()) {
        return path;
    }
    
    // Safety check for invalid destination
    if (destination < 0 || destination >= distances.size()) {
        cerr << "Invalid destination vertex: " << destination << endl;
        return path;
    }
    
    // If destination is unreachable
    if (distances[destination] == INF) {
        return path; // Return empty path
    }
    
    // Special case: if destination is the source
    if (previous[destination] == -1) {
        path.push_back(destination);
        return path;
    }
    
    // Reconstruct the path by following previous pointers
    // Set a limit to prevent infinite loops in case of cycle
    const int MAX_PATH_LENGTH = 1000;
    int path_length = 0;
    
    for (int v = destination; v != -1 && path_length < MAX_PATH_LENGTH; v = previous[v]) {
        path.push_back(v);
        path_length++;
    }
    
    // Check if we hit the limit (indicating a likely cycle)
    if (path_length >= MAX_PATH_LENGTH) {
        cerr << "Warning: Possible cycle detected in path construction" << endl;
        return vector<int>(); // Return empty path
    }
    
    // Reverse the path to get the correct order (source to destination)
    reverse(path.begin(), path.end());
    
    return path;
}

// Print the shortest path and its total cost
void print_path(const vector<int>& path, int total) {
    if (path.empty()) {
        cout << "No path exists.\nTotal cost is " << total << endl;
        return;
    }
    
    // Print vertices with spaces
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {  // Only add space if not the last element
            cout << " ";
        }
    }
    cout << "\nTotal cost is " << total << endl;
}