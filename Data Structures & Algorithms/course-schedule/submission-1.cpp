class Solution {
public:

    bool isCycle(vector<vector<int>>& prerequisites, vector<bool>& visited, vector<bool>& inRecursion, unordered_map<int, vector<int>>& adj, int node) {

        visited[node] = true;
        inRecursion[node] = true;

        for(auto& ng : adj[node]) {
            if(inRecursion[ng]) {
                return true;
            }

            if(!visited[ng]) {
                if(isCycle(prerequisites, visited, inRecursion, adj, ng) == true) {
                    return true;
                }
            }

        }

        inRecursion[node] = false;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        unordered_map<int, vector<int>> adj;
        for(auto& it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        for(int i = 0 ; i < numCourses ; i++) {
            if(!visited[i]) {
                if(isCycle(prerequisites, visited, inRecursion, adj, i)) {
                    return false;
                }
            }
        }

        return true;

    }
};
