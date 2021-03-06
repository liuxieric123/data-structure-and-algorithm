class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        for (auto e: prerequisites) {
            adj[e[1]].push_back(e[0]);
        }
        vector<int> order;
        bool visited[numCourses];
        bool checked[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            visited[i] = false;
            checked[i] = false;
        }
        for(int i = 0; i < numCourses; ++i) {
            if (!checked[i] && hasCycle(adj, i, order, visited, checked)) return vector<int>{};
        }
        reverse(order.begin(), order.end());
        return order;
    }

    bool hasCycle(map<int, vector<int>>& adj, int start, vector<int> &order, bool *visited, bool *checked) {
        if (visited[start]) return true;
        visited[start] = true;
        for (auto i : adj[start]) {
            if (!checked[i] && hasCycle(adj, i, order, visited, checked)) return true;
        }
        checked[start] = true;
        order.push_back(start);
        visited[start] = false;
        return false;
    }

     vector<int> findOrder1(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        int inDegree[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            inDegree[i] = 0;
        }
        for(auto e: prerequisites) {
            adj[e[1]].push_back(e[0]);
            ++inDegree[e[0]];
        }
        queue<int> qu;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) qu.push(i);
        }
        int count = 0;
        vector<int> order;
        while (!qu.empty()) {
            int vertex = qu.front();
            qu.pop();
            ++count;
            order.push_back(vertex);
            for(auto v: adj[vertex]) {
                if (--inDegree[v] == 0) qu.push(v);
            }
        }
        return count == numCourses ? order : vector<int>{};
    }
};