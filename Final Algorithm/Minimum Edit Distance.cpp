#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_edit_dis(const string& str1, const string& str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    // Initialization
    for(int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for(int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    // Compute the DP table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
    }

    // Backtracking to find the sequence of edits
    vector<string> edits;
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(str1[i-1] == str2[j-1]) {
            i--;
            j--;
        } else {
            if(dp[i-1][j-1] <= dp[i-1][j] && dp[i-1][j-1] <= dp[i][j-1]) {
                edits.push_back("Replace " + string(1, str1[i-1]) + " with " + string(1, str2[j-1]));
                i--;
                j--;
            } else if(dp[i-1][j] < dp[i][j-1]) {
                edits.push_back("Delete " + string(1, str1[i-1]));
                i--;
            } else {
                edits.push_back("Insert " + string(1, str2[j-1]));
                j--;
            }
        }
    }

    // Handle remaining characters in strings
    while(i > 0) {
        edits.push_back("Delete " + string(1, str1[i-1]));
        i--;
    }
    while(j > 0) {
        edits.push_back("Insert " + string(1, str2[j-1]));
        j--;
    }

    // Print the edits (optional)
    reverse(edits.begin(), edits.end());
    for(const string& edit : edits) {
        cout << edit << endl;
    }

    return dp[n][m];
}

int main() {
    string str1 = "abcdef";
    string str2 = "azced";
    int ans = min_edit_dis(str1, str2);
    cout << "Minimum edit distance: " << ans << endl;

    return 0;
}
