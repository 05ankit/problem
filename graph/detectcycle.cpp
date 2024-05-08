bool cycle(int source,vector<bool>&visited,vector<bool>&dfsVisited, vector<int>adj[])
    {
        visited[source]=true;
        dfsVisited[source]=true;
        
        
        for(auto x:adj[source])
        {
            if(!visited[x])
            {
                if(cycle(x,visited,dfsVisited,adj))
                return true;
            }
            else if(visited[x]==true && dfsVisited[x]==true)
            {
                return true;
            }
        }
        dfsVisited[source]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool>visited(V,false), dfsVisited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(cycle(i,visited,dfsVisited,adj))
                return true;
            }
        }
        return false;
