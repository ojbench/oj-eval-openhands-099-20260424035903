
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Function to perform BFS/DFS to find the sum of fish in a connected water region
int exploreRegion(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    
    // Use BFS to explore all connected water cells
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    
    int fishCount = 0;
    
    // Directions for adjacent cells (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();
        
        // Add the fish in this cell
        fishCount += grid[row][col];
        
        // Check all four adjacent cells
        for (auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            
            // Check if the new position is within bounds and is an unvisited water cell
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && 
                grid[newRow][newCol] > 0 && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }
    
    return fishCount;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    // Read the grid
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Create a visited array to keep track of visited cells
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    int maxFish = 0;
    
    // Explore each unvisited water cell
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                int fishInRegion = exploreRegion(grid, visited, i, j);
                maxFish = max(maxFish, fishInRegion);
            }
        }
    }
    
    cout << maxFish << endl;
    
    return 0;
}
