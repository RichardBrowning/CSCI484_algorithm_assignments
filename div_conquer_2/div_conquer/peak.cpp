#include <iostream>
#include <fstream>

int counter = 0;
//peak finding function
int findPeak(int A[], int low, int high) {
    counter++;
    // get mid index
    int mid = (low + high) / 2;
    // check if mid is peak
    if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) return mid;
    // given nature of C++ compiler, using an else here can cause the program to predict-run the statement in the else block when the condition in the if block is being judged
    // explore left half
    else if (A[mid] < A[mid - 1]) return findPeak(A, low, mid - 1);
    // explore right half
    else return findPeak(A, mid + 1, high);
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

int main() {
    int* A = new int[32];
    //read only the first 32 lines of the file
    readFromFile("peak.txt", A);
    if (A == nullptr) {
		std::cout << "Error: Cannot read file" << std::endl;
		return 1;
	}
    std::cout << "Array: ";
    for (int i = 0; i < 32; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    int peakIndex = findPeak(A, 0, 31);
    int peakValue = A[peakIndex];
    std::cout << "Peak Index: " << peakIndex << " counting from 0" << std::endl;
    std::cout << "Peak Value: " << peakValue << std::endl;

    return 0;
}