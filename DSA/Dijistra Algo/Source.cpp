#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CITIES = 50;

struct City {
    char name[50];
    int index;
};

struct Node {
    int city;
    double weight;  // Weight of the edge (distance)
    Node* next;
};

// Sample code: insert_edge(adj_list, 0, 1, 2448.0);  // New York to Los Angeles
void insert_edge(Node* adj_list[], int src, int dest, double weight) {
    Node* newNode = new Node;
    newNode->city = dest;
    newNode->weight = weight;
    newNode->next = adj_list[src];
    adj_list[src] = newNode;
    // Visual representation
    // adj_list[0] -> [city: 1, weight: 2448.0, next: nullptr]
    // adj_list[0] -> [city: 2, weight: 733.0, next: [city: 1, weight: 2448.0, next: nullptr]]
}

int min_distance(double dist[], bool visited[], int n)
{
    double minDist = 1e9;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(Node* adj_list[], double temp_distances[], int src, int n, int parent[]) {
    // dist[] holds the shortest distances from the source to each city.
    double dist[MAX_CITIES];
    bool visited[MAX_CITIES] = { false };

    for (int i = 0; i < n; i++) {
        dist[i] = 1e9;
        parent[i] = -1;
    }
    dist[src] = 0.0;

    for (int count = 0; count < n - 1; count++) {
        int u = min_distance(dist, visited, n);
        visited[u] = true;

        Node* temp = adj_list[u];
        while (temp != nullptr) {
            int v = temp->city;
            double weight = temp->weight;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) {
        temp_distances[i] = dist[i];
    }
}

void add_distance(double distances[][MAX_CITIES], int src, int dest, double weight) {
    distances[src][dest] = weight;
}

double find_distance(double distances[][MAX_CITIES], int src, int dest) {
    return distances[src][dest];
}

void compute_all_distances(Node* adj_list[], double distances[][MAX_CITIES], int n, int parents[][MAX_CITIES]) {
    // The outer loop iterates over each city, treating it as the source city.
    for (int i = 0; i < n; i++) {
        double temp_distances[MAX_CITIES];
        dijkstra(adj_list, temp_distances, i, n, parents[i]);
        for (int j = 0; j < n; j++) {
            if (i != j) {
                add_distance(distances, i, j, temp_distances[j]);
            }
        }
    }
}

void print_path(int parent[], int src, int dest, City cities[]) {
    if (dest == src) {
        cout << cities[src].name;
    }
    else if (parent[dest] == -1) {
        cout << "No path exists between " << cities[src].name << " and " << cities[dest].name << "." << endl;
    }
    else {
        print_path(parent, src, parent[dest], cities);
        cout << " -> " << cities[dest].name;
    }
}

int main() {
    City cities[MAX_CITIES];

    // Initialize cities (for example, first 5 cities)
    strcpy_s(cities[0].name, "New York");
    cities[0].index = 0;
    strcpy_s(cities[1].name, "Los Angeles");
    cities[1].index = 1;
    strcpy_s(cities[2].name, "Chicago");
    cities[2].index = 2;
    strcpy_s(cities[3].name, "San Francisco");
    cities[3].index = 3;
    strcpy_s(cities[4].name, "Houston");
    cities[4].index = 4;

    // Initialize adjacency list
    Node* adj_list[MAX_CITIES];
    for (int i = 0; i < MAX_CITIES; ++i) {
        adj_list[i] = nullptr;
    }

    // Add distances between cities
    insert_edge(adj_list, 0, 1, 2448.0);  // New York to Los Angeles
    insert_edge(adj_list, 0, 2, 733.0);   // New York to Chicago
    insert_edge(adj_list, 0, 3, 2571.0);  // New York to San Francisco
    insert_edge(adj_list, 0, 4, 7000.0);  // New York to Houston

    insert_edge(adj_list, 1, 0, 2448.0);  // Los Angeles to New York
    insert_edge(adj_list, 1, 2, 1755.0);  // Los Angeles to Chicago
    insert_edge(adj_list, 1, 3, 381.0);   // Los Angeles to San Francisco
    insert_edge(adj_list, 1, 4, 2342.0);  // Los Angeles to Houston

    insert_edge(adj_list, 2, 0, 733.0);   // Chicago to New York
    insert_edge(adj_list, 2, 1, 1755.0);  // Chicago to Los Angeles 
    insert_edge(adj_list, 2, 3, 1858.0);  // Chicago to San Francisco
    insert_edge(adj_list, 2, 4, 1376.0);  // Chicago to Houston

    insert_edge(adj_list, 3, 0, 2571.0);  // San Francisco to New York
    insert_edge(adj_list, 3, 1, 381.0);   // San Francisco to Los Angeles
    insert_edge(adj_list, 3, 2, 1858.0);  // San Francisco to Chicago
    insert_edge(adj_list, 3, 4, 3053.0);  // San Francisco to Houston

    insert_edge(adj_list, 4, 0, 7000.0);  // Houston to New York
    insert_edge(adj_list, 4, 1, 2342.0);  // Houston to Los Angeles
    insert_edge(adj_list, 4, 2, 1376.0);  // Houston to Chicago
    insert_edge(adj_list, 4, 3, 3053.0);  // Houston to San Francisco 

    // 2D array to store computed distances
    double distances[MAX_CITIES][MAX_CITIES];
    for (int i = 0; i < MAX_CITIES; ++i) {
        for (int j = 0; j < MAX_CITIES; ++j) {
            distances[i][j] = -1;  // Initialize with -1 indicating no path found yet
        }
    }

    int parents[MAX_CITIES][MAX_CITIES];

    // Compute shortest distances between all pairs of cities
    compute_all_distances(adj_list, distances, 5, parents); // 5 is the number of cities

    // Example: Print shortest distance between New York (0) and Los Angeles (1)
    int city1, city2;
    cout << "Cities are:" << endl;
    cout << "0. New York" << endl;
    cout << "1. Los Angeles" << endl;
    cout << "2. Chicago" << endl;
    cout << "3. San Francisco" << endl;
    cout << "4. Houston" << endl;
    cout << endl;
    cout << "Enter the starting city index: ";
    cin >> city1;
    cout << "Enter the destination city index: ";
    cin >> city2;

    double distance = find_distance(distances, city1, city2);

    if (distance == -1) {
        cout << "No path exists between " << cities[city1].name << " and " << cities[city2].name << "." << endl;
    }
    else {
        cout << "Shortest distance between " << cities[city1].name << " and " << cities[city2].name
            << " is: " << distance << " miles." << endl;

        cout << "Shortest path: ";
        print_path(parents[city1], city1, city2, cities);
        cout << endl;
    }
}
