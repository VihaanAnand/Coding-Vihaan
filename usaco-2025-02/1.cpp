// Import necessary libraries
#include <array>
#include <iostream>
#include <vector>
using namespace std;
// Function to apply an update to the grid and adjust the answer
void apply(vector<string> &grid, vector<vector<int>> &canonical, int &ans, int &n, int x, int y, int scale) {
        // If the cell is unpainted, return
        if (grid[x][y] == '.') {
                return;
        }
        // Identify the coordinates of the cell if it was in the top left quadrant (canonical)
        x = min(x, n - 1 - x);
        y = min(y, n - 1 - y);
        // Temporarily ignore the optimal painted state for the 4 squares
        ans -= min(canonical[x][y], 4 - canonical[x][y]);
        // Perform the update
        canonical[x][y] += scale;
        // Recompute the answer (optimal painted state for the 4 squares)
        ans += min(canonical[x][y], 4 - canonical[x][y]);
}
// Main function
int main() {
        // Fast input/output
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        // Read the number of rows and updates
        int n, q;
        cin >> n >> q;
        // Read the grid into memory
        vector<string> grid(n);
        for (int i = 0; i < grid.size(); i++) {
                cin >> grid[i];
        }
        // Initialise the canonical representation of the grid (top left quadrant)
        vector<vector<int>> canonical(n / 2);
        for (int i = 0; i < canonical.size(); i++) {
                canonical[i].resize(n / 2);
        }
        // Calculate the initial answer before any updates
        int ans = 0;
        // Iterate through each cell in the grid
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        // Initialise canonical representation while calculating initial answer
                        apply(grid, canonical, ans, n, i, j, 1);
                }
        }
        // Output the initial answer
        cout << ans << "\n";
        // Process each update
        while (q--) {
                // Read the coordinates of the cell to be updated
                int x, y;
                cin >> x >> y;
                // Convert to 0-based indexing
                x--;
                y--;
                // Remove old canonical representation
                apply(grid, canonical, ans, n, x, y, -1);
                // Update the grid by flipping the cell
                grid[x][y] = '#' + '.' - grid[x][y];
                // Add new canonical representation
                apply(grid, canonical, ans, n, x, y, 1);
                // Output the updated answer
                cout << ans << "\n";
        }
}