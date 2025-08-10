
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Struct representing a vertex
struct Vertex {
    string name;
    int distance;
    bool visited;
    string predecessor; // To store the predecessor vertex in the shortest path
};

// Function prototypes
int findVertexIndex(Vertex vertices[], int verticesCount, string vertexName);
vector<string> getPath(Vertex vertices[], int verticesCount, string source, string destination);

// Function to find minimum distance vertex
int minDistance(Vertex vertices[], int verticesCount) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < verticesCount; v++) {
        if (!vertices[v].visited && vertices[v].distance <= min) {
            min = vertices[v].distance;
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to calculate shortest path using Dijkstra's algorithm
int dijkstra(Vertex vertices[], unordered_map<string, vector<pair<string, int>>>& adjList, int verticesCount, string source, string destination) {
    // Find source and destination indices
    int sourceIndex = -1, destinationIndex = -1;
    for (int i = 0; i < verticesCount; i++) {
        if (vertices[i].name == source) {
            sourceIndex = i;
        }
        if (vertices[i].name == destination) {
            destinationIndex = i;
        }
    }

    // If source or destination not found, return -1
    if (sourceIndex == -1 || destinationIndex == -1) {
        return -1;
    }

    // Initialize distances and predecessors
    for (int i = 0; i < verticesCount; i++) {
        vertices[i].distance = INT_MAX;
        vertices[i].visited = false;
        vertices[i].predecessor = "";
    }

    // Distance to source is 0
    vertices[sourceIndex].distance = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < verticesCount - 1; count++) {
        int u = minDistance(vertices, verticesCount);
        vertices[u].visited = true;

        for (const auto& edge : adjList[vertices[u].name]) {
            string dest = edge.first;
            int weight = edge.second;
            for (int i = 0; i < verticesCount; i++) {
                if (vertices[i].name == dest) {
                    if (!vertices[i].visited && weight != 0 && vertices[u].distance != INT_MAX &&
                        vertices[u].distance + weight < vertices[i].distance) {
                        vertices[i].distance = vertices[u].distance + weight;
                        vertices[i].predecessor = vertices[u].name; // Update predecessor
                    }
                    break;
                }
            }
        }
    }

    return vertices[destinationIndex].distance;
}

// Function to get the path from source to destination
vector<string> getPath(Vertex vertices[], int verticesCount, string source, string destination) {
    vector<string> path;
    int destinationIndex = -1;
    for (int i = 0; i < verticesCount; i++) {
        if (vertices[i].name == destination) {
            destinationIndex = i;
            break;
        }
    }

    // If destination not found or no path exists, return empty path
    if (destinationIndex == -1 || vertices[destinationIndex].distance == INT_MAX) {
        return path;
    }

    // Trace back the path using predecessors
    int current = destinationIndex;
    while (current != -1 && vertices[current].name != source) {
        path.push_back(vertices[current].name);
        current = findVertexIndex(vertices, verticesCount, vertices[current].predecessor);
    }
    path.push_back(source);

    // Reverse the path to get source -> destination order
    reverse(path.begin(), path.end());

    return path;
}

// Function to find the index of a vertex by its name
int findVertexIndex(Vertex vertices[], int verticesCount, string vertexName) {
    for (int i = 0; i < verticesCount; i++) {
        if (vertices[i].name == vertexName) {
            return i;
        }
    }
    return -1; // Not found
}

int main() {
    // Define vertices
    Vertex vertices[] = {{"SBP", INT_MAX, false, ""},
                         {"SURAT", INT_MAX, false, ""},
                         {"VEDODORA", INT_MAX, false, ""},
                         {"VEROVAL", INT_MAX, false, ""},
                         {"NAGPUR", INT_MAX, false, ""},
                         {"PUNE", INT_MAX, false, ""},
                         {"BHIMPUR", INT_MAX, false, ""},
                         {"UJJAIN", INT_MAX, false, ""},
                         {"HARIDWAR", INT_MAX, false, ""},
                         {"AMBALA_CNT", INT_MAX, false, ""},
                         {"RISHIKESH", INT_MAX, false, ""},
                         {"KEDARNATH", INT_MAX, false, ""}};

    // Define adjacency list using unordered map
    unordered_map<string, vector<pair<string, int>>> adjList = {
        {"SBP", {{"SURAT", 630}, {"VEDODORA", 700}, {"NAGPUR", 500}, {"PUNE", 850}, {"AMBALA_CNT", 720}}},
        {"SURAT", {{"SBP", 630}, {"VEROVAL", 300}}},
        {"VEDODORA", {{"SBP", 700}, {"VEROVAL", 320}, {"SURAT", 300}}},
        {"VEROVAL", {{"VEDODORA", 320}, {"SURAT", 300}, {"UJJAIN", 450}}},
        {"NAGPUR", {{"PUNE", 500}, {"SBP", 500}}},
        {"PUNE", {{"NAGPUR", 500}, {"UJJAIN", 500}, {"BHIMPUR", 300}, {"VEROVAL", 500}, {"AMBALA_CNT", 750}}},
        {"BHIMPUR", {{"PUNE", 300}, {"UJJAIN", 0}}},
        {"UJJAIN", {{"PUNE", 500}, {"BHIMPUR", 0}, {"VEROVAL", 450},{"HARIDWAR", 500}}},
        {"HARIDWAR", {{"UJJAIN", 500}, {"NAGPUR", 500}, {"RISHIKESH", 150}}},
        {"AMBALA_CNT", {{"SBP", 720}, {"RISHIKESH", 150}}},
        {"RISHIKESH", {{"HARIDWAR", 150}, {"AMBALA_CNT", 150}, {"KEDARNATH", 500}}},
        {"KEDARNATH", {{"RISHIKESH", 500}}}
    };

    string source, destination;
    cout << "Enter the source:";
    cin >> source;
    cout << "Enter the destination:";
    cin >> destination;

    // Find minimum cost using Dijkstra's algorithm
    int minCost = dijkstra(vertices, adjList, 12, source, destination);
    if (minCost != INT_MAX) {
        cout << "Minimum Cost from " << source << " to " << destination << ": " << minCost << endl;
        // Get the path
        vector<string> path = getPath(vertices, 12, source, destination);
        if (!path.empty()) {
            cout << "Path: ";
            for (const string& vertex : path) {
                cout << vertex << " -> ";
            }
            cout << destination << endl;
        }
    } else {
        cout << "No path found from " << source << " to " << destination << endl;
    }

    return 0;
}
