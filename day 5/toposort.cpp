

//DFS APPROACH 
class Solution {
    public :
    void DFS(int node ,vector<vector<int>>& adj, vector<bool> &visited , stack<int> &stack) {
        visited[node] =1 ;
        
        for (int i =0 ;i< adj[node].size();i++){
            if(!visited[adj[node][i]]){
                DFS(adj[node][i],adj,visited,stack) ;
            }
        }
        
        stack.push(node) ;
    }
    
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
       int v = adj.size() ;
       vector<bool> visited (v,0) ;
       stack<int>st ;
       
       for(int i =0 ;i<v ;i++){
           if(!visited[i]){
               DFS(i,adj,visited,st) ;
           }
       }
       
       vector<int>ans ;
       
       while(!st.empty()) {
           ans.push_back(st.top()) ;
           st.pop();
    }
    
    return ans ;
    }
};