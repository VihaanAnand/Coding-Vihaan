// Import necessary libraries
#include <iostream>
#include <vector>
using namespace std;
// Function to solve the problem for K = 1
bool check1(vector<int> &A, int l, int r) {
        // Iterate through the subset of the array
        for (int i = l + 1; i <= r; i++) {
                // If the current element does not equal the last one (there is more than 1 unique element), return false
                if (A[i] != A[i - 1]) {
                        return false;
                }
        }
        // If all elements are equal, return true
        return true;
}
// Function to solve the problem for K = 2
bool check2(vector<int> &A, int l, int r) {
        vector<pair<int, int>> blk;
        // Iterate through the subset of the array
        for (int i = l; i <= r; i++) {
                // If the current element is equal to the last one, add it to the last block
                if (!blk.empty() && A[i] == A[i - 1]) {
                        blk.back().second++;
                }
                // Otherwise, create a new block
                else {
                        blk.push_back({A[i], 1});
                }
        }
        // Check if the number of blocks is even or ≤2
        if (blk.size() <= 2 || blk.size() % 2 == 0) {
                for (int i = 0; i + 2 < blk.size(); i++) {
                        // If the current block is not equal to the 2nd-next one, return false
                        if (blk[i] != blk[i + 2]) {
                                return false;
                        }
                }
                // If block i + 2 always equals block i, return true
                return true;
        }
        // If the number of blocks is odd, return false
        return false;
}
// Function to solve the problem for K = 3
bool check3(vector<int> &A, int l, int r) {
        // Iterate through all possible block lengths
        for (int blkLen = 1; blkLen <= r - l + 1; blkLen++){
                // Check whether the subset of the array is divisible by the block length
                if ((r - l + 1) % blkLen != 0) {
                        continue;
                }
                // Check whether the prefix is valid
                bool ok = true;
                // Iterate through the prefixes of the array
                for (int i = l; i + blkLen <= r; i++) {
                        // If the current element does not equal the one at the end of the block, the prefix is invalid
                        if (A[i] != A[i + blkLen]) {
                                ok = false;
                        }
                }
                // If the prefix is invalid, continue to the next iteration
                if (!ok) {
                        continue;
                }
                // Check the prefix with Case 1 and Case 2
                for (int i = l; i <= l + blkLen; i++) {
                        if ( /* Case 1 */ (check1(A, l, i) && check2(A, i + 1, l + blkLen - 1)) || /* Case 2 */ (check2(A, l, i) && check1(A, i + 1, l + blkLen - 1))) {
                                // If the prefix is valid, return true
                                return true;
                        }
                }
        }
        // If no block length works, return false
        return false;
};
// Function to solve the problem
void solve() {
        // Read the number of elements and the maximum value
        int n, k;
        cin >> n >> k;
        // Read the array of integers into memory
        vector<int> A(n);
        for (int i = 0; i < A.size(); i++) {
                cin >> A[i];
        }
        // Solve the problem based on the value of K
        bool answer;
        if (k == 1) {
                answer = check1(A, 0, n - 1);
        }
        else if (k == 2) {
                answer = check2(A, 0, n - 1);
        }
        else {
                answer = check3(A, 0, n - 1);
        }
        // Output the answer
        if (answer) {
                cout << "YES\n";
        }
        else {
                cout << "NO\n";
        }
}
// Main function
int main() {
        // Fast input/output
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        // Read the number of test cases
        int tc; 
        cin >> tc;
        // Process each test case
        while (tc--) {
                solve();
        }
}