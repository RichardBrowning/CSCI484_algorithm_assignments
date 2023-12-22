#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class LIS {
private:
    std::vector<int> nums;
    std::vector<int> L;
    std::vector<int> sequence;

public:
    LIS(const std::vector<int>& nums) {
        this->nums = nums;
        this->L = std::vector<int>(nums.size(), 1);
    }
    int longestIncreasingSubsequence() {
        int n = nums.size();
        // use L to store the length of the longest increasing subsequence ending at nums[i]
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && L[i] <= L[j]) {
                    L[i] = L[j] + 1;
                }
            }
        }
        std::cout << std::endl;
        // return maximum value in dp
        return *std::max_element(L.begin(), L.end());
    }
    void printLIS() {
        //get the values in the longest increasing subsequence
        int max = *std::max_element(L.begin(), L.end());
        for (int i = nums.size() - 1; i >= 0; i--) {
            // std::cout << L[i] << " ";
            if (L[i] == max) {
                // std::cout << "yes ";
                sequence.push_back(this->nums[i]);
                max--;
            }
        }
        for (int i = sequence.size() - 1; i >= 0; i--) {
            std::cout << sequence[i] << " ";
        }
    }
};


void readFromFile(const std::string& filename, std::vector<int>& arr) {
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
            arr.push_back(num);
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
    std::vector<int> nums;
    readFromFile("incseq.txt", nums);
    LIS lis(nums);
    std::cout << "The lenght of the longest increasing subsequence is: " << lis.longestIncreasingSubsequence() << std::endl;
    std::cout << "The longest increasing subsequence is: ";
    lis.printLIS();
    return 0;
}
