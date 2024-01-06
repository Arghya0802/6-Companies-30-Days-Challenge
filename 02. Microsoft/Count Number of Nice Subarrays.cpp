class Solution {
private:
int n ;
    
int nice_Subarrays(vector<int> &nums, int k)
{
    int end = 0, total = 0, cnt = 0 ;
    
    for(int start = 0 ; start < n ; start++)
    {
        cnt += nums[start] % 2 == 1 ;
        
        while(end <= start && cnt > k)
        {
            cnt -= nums[end] % 2 == 1 ;
            end++ ;
        }
        
        total += (start - end + 1) ;
    }
    
    return total ;
}
    
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        n = nums.size() ;
        
        int ans1 = nice_Subarrays(nums, k) ;
        int ans2 = nice_Subarrays(nums, k - 1) ;
        
        return (ans1 - ans2) ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
