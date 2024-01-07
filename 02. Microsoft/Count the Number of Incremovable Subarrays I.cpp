class Solution {
private:
int n ;
    
bool isIncreasing(vector<int> &nums, set<int> &set)
{
    int prev = 0 ;
    
    for(int i = 0 ; i < n ; i++)
    {
        if(set.find(i) == set.end() )  
        {
            if(prev >= nums[i] )  return false ;
            
            prev = nums[i] ;
        }
    }
    
    return true ;
}
    
public:
    int incremovableSubarrayCount(vector<int>& nums) 
    {
        n = nums.size() ;
        int ans = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            set<int> set ;
            
            for(int j = i ; j < n ; j++)
            {
                set.insert(j) ;
                
                if(isIncreasing(nums, set) )  
                    ans++ ;
                
            } 
            
        }
        
        return ans ;
    }
};

// Time Complexity:  O(N ^ 3)
// Space Complexity: O(N)
