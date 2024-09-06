#include "LCS.h"

// Longest Common Substring function
std::pair<int, int> longest_common_substring(const std::string& text1, const std::string& text2) {
    int n = text1.length();
    int m = text2.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    int maxLength = 0;
    int endIndex = 0;  // End index in text1

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;  // Track end index in text1
                }
            }
        }
    }

    int startIndex = endIndex - maxLength + 1;
    return {startIndex, endIndex};  // Return 1-based indices
}
