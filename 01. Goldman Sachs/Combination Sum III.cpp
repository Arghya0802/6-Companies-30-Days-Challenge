// Link: https://leetcode.com/problems/combination-sum-iii/

class Solution {
private:
vector<vector<int>> ans ;
int n ;
    
void solve(int i, int target, vector<int> &nums)
{
    if(nums.size() == n)
    {
        if(target == 0) ans.push_back(nums) ;
        
        return ;
    }
    
    for(int x = i ; x <= 9 ; x++)
    {
        if(x > target)  break ;
        
        nums.push_back(x) ;
        
        solve(x + 1, target - x, nums) ;
        
        nums.pop_back() ;
    }
    
    return ;
}
    
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        this -> n = k ;
        vector<int> A ;
        
        solve(1, n, A) ;
        
        return ans ;
    }
};

// Time Complexity:  O(Exponential)
// Space Complexity: O(N)
