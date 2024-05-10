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

        if (rank[x] < rank[y])
            parent[x] = y;
        else if (rank[x] > rank[y])
            parent[y] = x;
        else {
            parent[y] = x;
            rank[x]++;
        }
    }

    // Function to get the rank of an element
    int getRank(int x) {
        return rank[x];
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
    cout << "Rank of 4: " << ds.getRank(4) <<endl;
    cout << "Parent of 4: " << ds.getParent(4) <<endl;
    ds.unionSets(1, 2);
    //ds.unionSets(2, 3);
    ds.unionSets(3,4);
    cout << "Rank of 4: " << ds.getRank(4) <<endl;
    cout << "Parent of 4: " << ds.getParent(4) <<endl;
    ds.unionSets(1,4);

    // Print the rank of a number
    cout << "Rank of 4: " << ds.getRank(4) <<endl;
    cout << "Parent of 4: " << ds.getParent(4) <<endl;
    

    return 0;
}
