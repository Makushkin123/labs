//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        bool visited[m][n];
        memset(visited, false, sizeof(visited));
        int D[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        stack<pair<int, int>> st;
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    count++;
                    st.push(make_pair(i, j));
                    visited[i][j] = true;
                    while (!st.empty()) {
                        int x = st.top().first;
                        int y = st.top().second;
                        bool hasUnvisitedChild = false;
                        for (int i = 0; i < 4; i++) {
                            int x_next = x + D[i][0];
                            int y_next = y + D[i][1];
                            if (0 <= x_next && x_next < m && 0 <= y_next && y_next < n && grid[x_next][y_next] == '1' && visited[x_next][y_next] == false) {
                                st.push(make_pair(x_next, y_next));
                                visited[x_next][y_next] = true;
                                hasUnvisitedChild = true;
                                break;
                            }
                        }
                        if (!hasUnvisitedChild) st.pop();
                    }
                }
            }
        }
        
        return count;
    }
};
