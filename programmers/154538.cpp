#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, n;
    cin >> x >> y >> n;

    vector<int> dp(y+1, 1000009);   // max값
    dp[x] = 1;
    for (int i = x+1; i <= y; i++) {
        if (i % 2 == 0 && dp[i/2] != 1000009) {
            dp[i] = min(dp[i/2]+1, dp[i]);
        }
        if (i % 3 == 0 && dp[i/3] != 1000009) {
            dp[i] = min(dp[i/3]+1, dp[i]);
        }
        if (i - n > 0 && dp[i-n] != 1000009) {
            dp[i] = min(dp[i-n]+1, dp[i]);
        }
    }
    if (dp[y] == 1000009) {
        cout << -1 << '\n';
        return 0;
    }
    cout << dp[y] - 1 << '\n';

    return 0;
}


// dp!