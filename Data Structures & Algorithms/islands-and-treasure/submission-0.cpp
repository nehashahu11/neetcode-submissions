class Solution {
public:

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m;
    int n;
    void BFS(int i, int j, vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        q.push({{i, j}, 0});

        int level = 1;
        while(!q.empty()) {
            int s = q.size();
            
            while(s--) {
                auto coords = q.front().first;
                int x = coords.first;
                int y = coords.second;

                int prevLevel = q.front().second;
                q.pop();

                for(auto& dir : directions) {
                    int i_ = x + dir[0];
                    int j_ = y + dir[1];

                    if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] == -1 || grid[i_][j_] == 0) continue;

                    if(grid[i_][j_] > 0) {
                        if(prevLevel+1 < grid[i_][j_]) {
                            q.push({{i_, j_}, prevLevel+1});
                            grid[i_][j_] = prevLevel+1;
                        }
                    }
                }
                level++;
            }
        }


    }


    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 0) {
                    BFS(i, j, grid);
                }
            }
        }
    }
};
