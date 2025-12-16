#include <iostream>
#include <vector>
using namespace std;

// Checks if the given cell (r, c) can be visited
bool isSafe(vector<vector<char>> &grid, int r, int c, vector<vector<bool>> &visited)
{
    int n = grid.size();
    int m = grid[0].size();

    // Cell is within bounds, contains land ('L'), and is not yet visited
    return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 'L' && !visited[r][c]);
}

// Performs DFS to mark all connected land cells
void dfs(vector<vector<char>> &grid, int r, int c, vector<vector<bool>> &visited)
{
    // Mark current cell as visited
    visited[r][c] = true;

    // All 8 possible directions (vertical, horizontal, diagonal)
    vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Explore all connected neighbours
    for (int k = 0; k < 8; k++)
    {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (isSafe(grid, nr, nc, visited))
            dfs(grid, nr, nc, visited);
    }
}

// finding number of distinct islands in the grid
int countIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // Matrix to track visited cells
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int islands = 0;

    // Traverse every cell in the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Start a new DFS when an unvisited land cell is found
            if (grid[i][j] == 'L' && !visited[i][j])
            {
                dfs(grid, i, j, visited);
                islands++;
            }
        }
    }

    return islands;
}

int main()
{
    vector<vector<char>> grid = {
        {'L', 'W', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}};

    // printing the number of islands
    cout << countIslands(grid) << endl;

    return 0;
}
