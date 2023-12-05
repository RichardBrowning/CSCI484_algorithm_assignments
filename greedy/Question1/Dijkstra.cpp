#include "Dijkstra.h"

Dijkstra::Dijkstra(int *matrix_data, int size, int source, int dest)
{
    this->size = size;
    this->matrix = new int *[size];
    for (int i = 0; i < size; i++)
    {
        this->matrix[i] = matrix_data + i * size;
    }
    this->d = new int[size];
    this->s = new int[size];
    this->source = source;
    this->destination = dest;
    this->path = new int[size];
    this->path_size = 0;
}

Dijkstra::~Dijkstra()
{
    delete[] this->matrix;
    delete[] this->d;
    delete[] this->s;
    delete[] this->path;
}

void Dijkstra::run(){
    //initialized set IN and arrays 
    IN.push_back(source);
    d[source] = 0;
    //for all nodes z not in IN
    for (int i = 0; i < size; i++){
        //found 
        if (std::find(IN.begin(), IN.end(), i) != IN.end()){
            continue;
        } else { // not found
            d[i] = matrix[source][i];
            s[i] = source;
        }
    }
    //while nodes outside IN remains 
    while (IN.size() != this->size){
        // p = node z not in IN with smallest d[z]
        int p = 0;
        int min = INT_MAX;
        for (int i = 0; i < size; i++){
            if (std::find(IN.begin(), IN.end(), i) != IN.end()){
                continue;
            } else {
                if (d[i] < min){
                    min = d[i];
                    p = i;
                }
            }
        }
        // add p to IN
        IN.push_back(p);
        // for all nodes z not in IN, recompute d for non-IN nodes, adjust s if necessary
        for (int i = 0; i < size; i++){
            if (std::find(IN.begin(), IN.end(), i) != IN.end()){
                continue;
            } else {
                if (d[p] + matrix[p][i] < d[i]){
                    d[i] = d[p] + matrix[p][i];
                    s[i] = p;
                }
            }
        }
    this->printINmatrix();
    }
}

void Dijkstra::printINmatrix() {
	std::cout << "IN: {";
    for (int i = 0; i < IN.size(); i++) {
		std::cout << (char)(IN[i] + 97) << " ";
	}
    std::cout << "}" << std::endl;
    std::cout << "d: {- ";
    for (int i = 1; i < size; i++) {
        std::cout << d[i] << " ";
    }
    std::cout << "}" << std::endl;
    std::cout << "s: {- ";
    for (int i = 1; i < size; i++) {
		std::cout << s[i] << " ";
	}
    std::cout << "}" << std::endl;
	std::cout << std::endl;
}

void Dijkstra::printPath(){
    //get user's input for destination node
    //std::cout << "Enter destination node: ";
    //std::cin >> destination;
    //map destination letter a-e to 0-5
    //destination -= 97;
    //print path
    std::cout << "Path: ";
    int current = destination;
    while (current != source){
        path[path_size] = current;
        path_size++;
        current = s[current];
    }
    path[path_size] = source;
    path_size++;
    for (int i = path_size - 1; i >= 0; i--){
        std::cout << (char)(path[i] + 97) << " ";
    }
    //also print destination node
    std::cout << std::endl;
    //print distance
    std::cout << "Distance: " << d[destination] << std::endl;
}