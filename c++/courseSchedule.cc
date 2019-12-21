class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        int inDegree[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            inDegree[i] = 0;
        }
        for (auto v: prerequisites) {
            adj[v[1]].push_back(v[0]);
            ++inDegree[v[0]];
        }
        queue<int> qu;
        
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0){
                qu.push(i);
            }        
        }
        int count = 0;
        while(!qu.empty()) {
            int vertex = qu.front();
            qu.pop();
            ++count;
            for (auto i: adj[vertex]) {
                --inDegree[i];
                if (inDegree[i] == 0) {
                    qu.push(i);
                }
            }
        }
        return count == numCourses;
    }
};