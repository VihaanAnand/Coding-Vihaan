#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int solve() {   
        int N, A, B;
        cin >> N >> A >> B;
        vector<string> rows(N);
        for (auto &row : rows) {
                cin >> row;
        }
        vector<vector<bool> > has_star(N, vector<bool>(N));
        for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                        if (rows[r][c] == 'B') {
                                if (r - B < 0 || c - A < 0) {
                                        return -1;
                                }
                                has_star[r][c] = has_star[r - B][c - A] = 1;
                        }
                }
        }
        for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                        if (rows[r][c] == 'W') {
                                if (has_star[r][c]) {
                                        return -1;
                                }
                        }
                        else if (rows[r][c] == 'G') {
                                if (has_star[r][c]) {
                                        continue;
                                }
                                if (r >= B && c >= A && has_star[r - B][c - A]) {
                                        continue;
                                }
                                has_star[r][c] = true;
                        }
                }
        }
        int ans = 0;
        for (const auto &row : has_star) {
                ans += accumulate(begin(row), end(row), 0);
        }
        return ans;
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int T;
        cin >> T;
        while (T--) {
                cout << solve() << "\n";
        }
}