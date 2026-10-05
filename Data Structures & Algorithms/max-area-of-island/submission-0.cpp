class Solution {
    vector<vector<int>> directions = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    int n, m;

public:

    int dfs(int x, int y,
            vector<vector<int>>& grid,
            vector<vector<int>>& visited) {

        // Invalid cell
        if (x < 0 || x >= n || y < 0 || y >= m)
            return 0;

        // Water or already visited
        if (grid[x][y] == 0 || visited[x][y])
            return 0;

        // Mark current cell
        visited[x][y] = 1;

        // Current cell contributes 1
        int area = 1;

        // Explore 4 neighbors
        for (auto& dir : directions) {

            int nx = x + dir[0];
            int ny = y + dir[1];

            area += dfs(nx, ny, grid, visited);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> visited(
            n, vector<int>(m, 0)
        );

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && !visited[i][j]) {

                    int area = dfs(i, j, grid, visited);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};