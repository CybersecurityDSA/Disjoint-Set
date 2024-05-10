#include <iostream>

const int MAXN = 1000; // Maximum number of elements

int parent[MAXN];
int rank[MAXN];

// Function to initialize disjoint sets
void makeSet(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find operation with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

// Union operation by rank
void Union(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);

    if (xRoot == yRoot) return;

    if (rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

// Driver code
int main() {
    int n = 5;
    
    // Initialize disjoint sets
    makeSet(n);

    // Perform union operations
    Union(0, 2);
    Union(4, 2);
    Union(3, 1);

    // Check if elements belong to the same set
    if (find(4) == find(0))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
    
    if (find(1) == find(0))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";

    return 0;
}

