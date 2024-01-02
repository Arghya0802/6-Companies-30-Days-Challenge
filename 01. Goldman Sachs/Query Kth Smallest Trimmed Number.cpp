using pp = pair<string, int> ;

class Solution {
private:
int m, n ;
    
int solve(vector<string> &nums, int trim, int k)
{
    priority_queue<pp> maxQ ;
    
    for(int i = 0 ; i < m ; i++)
    {
        string pref = "" ;
        
        for(int j = trim ; j < n ; j++)  pref += nums[i][j] ;
        
        if(maxQ.size() < k)  maxQ.push( {pref, i} ) ;
        
        else if(maxQ.top().first > pref)
        {
            maxQ.pop() ;
            maxQ.push( {pref, i} ) ;
        }
    }
    
    return maxQ.top().second ;
}
    
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        m = nums.size(), n = nums[0].size() ;
        
        vector<int> ans ;
        
        for(auto &query: queries)
        {   
            int k = query[0], trim = n - query[1] ;
            
            int kthSmall = solve(nums, trim, k) ;
            
            ans.push_back(kthSmall) ;
        }
        
        return ans ;
    }
};

// Time Complexity:  O(Q * N * Log K)
// Space Complexity: O(K)
