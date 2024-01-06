class Solution {
private:
vector<pair<int, int>> dir ;
int m, n ;
    
int solve(int row, int col, vector<vector<int>> &img)
{
    int sum = img[row][col], cnt = 1 ;
    
    for(int i = 0 ; i < 8 ; i++)
    {
        auto &[dx, dy] = dir[i] ;
        
        int nRow = row + dx, nCol = col + dy ;
        
        if(nRow >= 0 && nCol >= 0 && nRow < m && nCol < n)
        {
            sum += img[nRow][nCol] ;
            cnt++ ;
        }
    }
    
    return (sum / cnt) ;
}
    
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        m = img.size(), n = img[0].size() ;
        
        dir = { {-1, -1}, {-1, 0}, {-1, +1}, {0, -1}, {0, +1}, {+1, -1}, {+1, 0}, {+1, +1} } ;
        
        vector<vector<int>> ans(m, vector<int> (n, -1) ) ;
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)  ans[i][j] = solve(i, j, img) ;
        }
        
        return ans ;
    }
};

// Time Complexity:  O(M * N * 3)
// Space Complexity: O(M * N) [For the ans[][] vector]
