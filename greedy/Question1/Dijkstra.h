#include <iostream>
#include <vector>

class Dijkstra {
    private:
        int** matrix;
        int size;
        int source;
        int destination;
        std::vector<int> IN;
        int* d;
        int* s;
        int* path;
        int path_size;
    public:
        Dijkstra(int* matrix_data, int size, int source, int dest);
        ~Dijkstra();
        void run();
        void printINmatrix();
        void printPath();
};