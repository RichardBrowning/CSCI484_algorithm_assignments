#include <iostream>
#include <fstream>

int counter = 0;
//peak finding function
int findPeak(int A[], int low, int high) {
    counter++;
    // get mid index
    int mid = (low + high) / 2;
    // check if mid is peak
    if (A[mid] > A[mid-1] && A[mid] > A[mid+1]) return mid;
    // given nature of C++ compiler, using an else here can cause the program to predict-run the statement in the else block when the condition in the if block is being judged
    // explore left half
    else if (A[mid] < A[mid-1]) return findPeak(A, low, mid-1);
    // explore right half
    else return findPeak(A, mid+1, high);
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

    // extra experiment
    // int sizes[4] = {16, 32, 64, 128};
    // // Size 16
    // int* arr1 = new int[16]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 5, 4, 3, 2}; 
    // // Size 32
    // int* arr2 = new int[32]{-1, 2, 3, 4, 5, 15, 16, 
    //                 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
    //                 33, 32, 31, 30, 29, 28, 27, -2, -1};
    // // Size 64                
    // int* arr3 = new int[64]{-2, -1, 1, 2, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
    //                 17, 18, 19, 20, 21, 28, 29, 30, 31, 32, 
    //                 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 
    //                 49, 48, 39, 38, 37, 36, 35, 34, 14, 13, 12, 11, 10, -1, -3, -4, -5, -6, -7, -8, -9, -10};        
    // // Size 128
    // int* arr4 = new int[128]{-2, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
    //                 129, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 
    //                 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, -3};
    // int* arrs[4] = {arr1, arr2, arr3, arr4};
    // //TimeInterval timer;
    // for (int i = 0; i < 4; i++) {
    //     counter = 0;
    //     std::cout << "Array Size: " << sizes[i] << std::endl;
    //     int peakIndex = findPeak(arrs[i], 0, sizes[i] - 1);
    //     int peakValue = arrs[i][peakIndex];
    //     std::cout << "Peak Index: " << peakIndex << " counting from 0" << std::endl;
    //     std::cout << "Peak Value: " << peakValue << std::endl;
    //     std::cout << "cycles elapsed: " << counter << " calls" << std::endl;
    // }