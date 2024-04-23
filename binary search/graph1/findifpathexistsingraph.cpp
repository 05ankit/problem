class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1)
        {
            return true;
        }
        unordered_map<int, vector<int>> adj;
        for(auto& i: edges)
        {
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> vis;
        for(int i=0;i<n;i++)
        {
            vis.push_back(0);
        }
        vis[source]=1;
        q.push(source);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto i: adj[node])
            {
                if(!vis[i])
                {
                    vis[i]=1;
                    q.push(i);
                }
                if(vis[destination])
                {
                    return true;
                }
            }
        }
        return false;
    }
};
