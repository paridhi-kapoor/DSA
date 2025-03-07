
// FIFO IS USED HERE TO FIND THE CYCLE IN A DIRECTED GRAPH
class Solution {
    public:
      // Function to detect cycle in a directed graph.
      bool isCyclic(vector<vector<int>> &adj) {
          int v =adj.size() ;
          vector<int > ind(v,0) ;
          
          for (int i =0 ; i<v ;i++){
              for(auto &it : adj[i]){
                  ind [it] ++ ;
              }
          }
          queue<int>q ;
          
          for (int i=0 ; i<v ;i++){
              if(ind [i]==0) q.push(i) ;
          }
          
          while(!q.empty()){
              int node = q.front() ;
              q.pop() ;
              
              for(auto &it : adj[node]) {
                  ind[it] -- ;
                  if(ind[it]==0) q.push(it) ;
                  
              }
          }
          
          for(int i = 0; i<v ;i++){
              if(ind[i]>0) return 1 ;
          }
          return 0 ;
        
      }
  };
  