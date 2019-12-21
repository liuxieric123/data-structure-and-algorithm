vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> adj;
        for (auto v: edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        bool visited[n];
        for (int i = 0; i < n; ++i) visited[i] = false;
        vector<int> ret;
        int minHeigh = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int h = height(adj, i, visited);
            if (h < minHeigh) {
                ret = {};
                minHeigh = h;
                ret.push_back(i);
            } else if (h == minHeigh) {
                ret.push_back(i);
            } else continue;
        }
        return ret;
    }

    int height(map<int, vector<int>>& adj, int start, bool *visited) {
        if (visited[start]) return 0;
        visited[start] = true;
        int maxHeight = 0;
        for (auto i : adj[start]) {
            if (visited[i]) continue;
            maxHeight = max(maxHeight, height(adj, i, visited));
        }
        visited[start] = false;
        return maxHeight + 1;
    }