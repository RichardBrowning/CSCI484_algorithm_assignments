#include <iostream>
#include <vector>
#include <string>

int longestCommonSubsequenceLength(const std::string& X, const std::string& Y) {
    int m = X.length();
    int n = Y.length();
    // dp[i][j] stores the length of LCS of substring X[0..i-1], Y[0..j-1]
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    // fill the lookup table in bottom-up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // if current character of X and Y matches
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // else if current character of X and Y don't match 
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // LCS length will be last entry in the lookup table
    return dp[m][n];
}

int main() {
    std::string X = "ABCBDAB";
    std::string Y = "BDCABA";

    int lcsLength = longestCommonSubsequenceLength(X, Y);

    std::cout << "Longest Common Subsequence Length: " << lcsLength << std::endl;

    return 0;
}