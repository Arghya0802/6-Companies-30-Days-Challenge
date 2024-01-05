using pp = pair<int, pair<int, int>> ;

class Solution {
private:
int m, n ;
int dx[4] = {-1, +1, 0, 0} ;
int dy[4] = {0, 0, -1, +1} ;
    
vector<vector<int>> dist ;
    
bool isValid(int nRow, int nCol, int steps, vector<vector<int>> &isWater)
{
    if(nRow < 0 || nRow >= m || nCol < 0 || nCol >= n)  return false ;
    
    if(isWater[nRow][nCol] == 1)  return false ;
    
    int height = dist[nRow][nCol] - steps ;
    
    return height <= 1 ;
}
    
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        m = isWater.size(), n = isWater[0].size() ;
        
        dist.resize(m, vector<int> (n, -1) ) ;

        queue<pp> q ;
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(isWater[i][j] == 1) 
                {
                    q.push( { 0, { i, j } } ) ;
                    dist[i][j] = 0 ;
                }
            }
        }
        
        while(!q.empty() )
        {
            auto[steps, ind] = q.front() ;
            q.pop() ;
            
            auto[row, col] = ind ;
            
            for(int i = 0 ; i < 4 ; i++)
            {
                int nRow = row + dx[i] ;
                int nCol = col + dy[i] ;
                
                if(isValid(nRow, nCol, steps + 1, isWater) )
                {
                    isWater[nRow][nCol] = 1 ;
                    dist[nRow][nCol] = steps + 1 ;
                    
                    q.push( { steps + 1, { nRow, nCol } } ) ;
                }
            }
        }
        
        return dist ;
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M * M) [Maintaing the queue data structure]
