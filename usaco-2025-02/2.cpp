// Import necessary libraries
#include <iostream>
#include <vector>
using namespace std;
// Main function
int main() {
        // Fast input/output
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        // Read array of integers into memory
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
                cin >> A[i];
        }
        // Calculate the number of elements of A equal to i
        // cnt[i] = # of times i appears in A
        vector<int> cnt(N + 1);
        for (int i = 0; i < A.size(); i++) {
                int value = A[i];
                cnt[value]++;
        }
        // Calculate the number of non-negative integers less than i that do not appear in A
        // missing_lt_i = how many numbers in 0 ≤ x < i are missing from A?
        int missing_lt_i = 0;
        // Iterate through all of the integers
        for (int i = 0; i <= N; i++) {
                // Output the updated answer
                cout << max(cnt[i], missing_lt_i) << "\n";
                // Update the number of integers that are missing
                if (cnt[i] == 0) {
                        missing_lt_i++;
                }
        }
}