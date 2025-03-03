class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int fresh =0 ;
            int m = grid.size() ; 
            int n = grid[0].size() ;
            int time =0 ;
    
            queue<pair<int,int>> rotten ;
    
            for (int i = 0; i<m ;i++){
                for (int j =0 ;j<n;j++){
                    if(grid[i][j]==2){
                        rotten.push({i,j}) ;
                    }
                    else if(grid[i][j]==1){
                        fresh++;
                    }
                }
            }
    
            if(fresh==0) return 0 ;
    
            //BFS 
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
            while(!rotten.empty()){
               int no_of_rot = rotten.size() ;
               bool if_rot = false ;
    
               for (int i =0 ;i<no_of_rot ;i++){
                 auto [x,y] =rotten.front() ;
                 rotten.pop() ;
    
                  for (auto [dx, dy] : directions) {
                    int nx = x+ dx ;
                    int ny = y+dy ;
    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny]=2 ;
                        fresh --;
                        rotten.push({nx ,ny}) ;
                        if_rot= true ;
                    }
                  }
                }
               if(if_rot ==true) time++ ; 
            }
    
             // checking if any fresh orange left
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == 1) {
                        return -1;
                    }
                }
            }
    
            return time;
    
        }
    };

    // link of ques : https://leetcode.com/problems/rotting-oranges/description/