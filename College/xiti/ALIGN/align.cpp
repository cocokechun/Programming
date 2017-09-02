#include <iostream>

using namespace std;

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;
    int m = s1.size();
    int n = s2.size();

    int scores[m][n];
    bool ends[m][n];
    memset(scores, 0, m * n * sizeof(int));

    // dp part
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (s1[i] == s2[j]) {
                scores[i][j] = max(scores[i][j],
                    2 + scores[i-1][j-1]);
                ends[i][j] = false;
            } else {
                scores[i][j] = max(scores[i][j],
                    scores[i-1][j-1]);
                scores[i][j] = max(scores[i][j],
                scores[i-1][j]);

            }
        }
    }

    

}
