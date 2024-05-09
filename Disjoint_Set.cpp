#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the disjoint set

struct DisjointSet {
    int parent[MAX_SIZE];
    int rank[MAX_SIZE];

    void makeSet(int x) {
        parent[x] = x;
        rank[x] = 0;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    // Function to get the rank of an element
    int getRank(int x) {
        return rank[find(x)];
    }
    int getParent(int x){
        return parent[find(x)];
    }
};

int main() {
    DisjointSet ds;

    // Example usage:
    ds.makeSet(1);
    ds.makeSet(2);
    ds.makeSet(3);
    ds.makeSet(4);
    ds.unionSets(1, 2);
    //ds.unionSets(2, 3);
    ds.unionSets(3,4);
    ds.unionSets(1,4);

    // Print the rank of a number
    cout << "Rank of 1: " << ds.getRank(1) <<endl;
    cout << "Parent of 4: " << ds.getParent(4) <<endl;


    return 0;
}

