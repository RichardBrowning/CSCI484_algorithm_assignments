#include <iostream>
#include <fstream>
#include "Dijkstra.h"

void readFromFile(const std::string& filename, int* arr);
int getDest();

int main(){
	// read input file of a 6x6 matrix
	//init a 6x6 matrix on heap
    int* matrix_data = new int[36];
    readFromFile("matrix.txt", matrix_data);
    int dest = getDest();
    Dijkstra d = Dijkstra(matrix_data, 6, 0, dest);
    d.run();
    d.printPath();
}

int getDest() {
	char dest = NULL;
    while (true) {
	    std::cout << "Enter destination (a - f): ";
        std::cin >> dest;
        int destInt = (int)dest - 97;
        if (destInt < 1 || destInt > 5) {
		    std::cout << "Invalid destination" << std::endl;
        }
        else {
			return destInt;
		}
    }
}

void readFromFile(const std::string& filename, int* arr) {
    // open file
    std::ifstream file(filename);
    // recheck if file is open
    if (!file.is_open()) {
        return;
    }
    // read file
    int num;
    int index = 0;
    while (file >> num) {
        // in case trying to write to a out-of-bound index, ignore the rest
        try {
            arr[index] = num;
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
            break;
        }
        index++;
    }
    //close read stream
    file.close();
}