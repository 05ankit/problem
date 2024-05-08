int maxi;
vector<bool> visited;
vector<vector<int>> adj;


int dfs(int v){
//max no of nodes on a branch
int currMax=0;
visited[v]=true;
for(auto u: adj[v]){
if(!visited[u]){
int val = dfs(u);
maxi=max(maxi,currMax+val+1);
if(val>currMax){
currMax=val;
}
}
}
//considering the case where there is only one leg
maxi=max(maxi,currMax+1);
return currMax+1;
}
int Solution::solve(vector<int> &A) {
    maxi=0;
adj.assign(A.size(),vector<int>());
visited.assign(A.size(),false);
int root=-1;
for(int i=0;i<A.size();i++){
if(A[i]==-1){
root=i;
continue;
}
adj[A[i]].push_back(i);
adj[i].push_back(A[i]);
}
dfs(root);
return maxi-1;
}
