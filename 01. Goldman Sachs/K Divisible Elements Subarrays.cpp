class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) 
    {
        int n = nums.size(), ans = 0 ;
        unordered_set<string> set ;
        
        for(int i = 0 ; i < n ; i++)
        {
            string res = "" ;
            int cnt = 0 ;
            
            for(int j = i ; j < n ; j++)
            {
                if(cnt == k && nums[j] % p == 0)  break ;
                
                res += to_string(nums[j]) + "#" ;
                
                if(nums[j] % p == 0)  cnt++ ;
                
                if(set.find(res) == set.end() )
                {
                    set.insert(res) ;
                    ans++ ;
                }
            }

        }
        
        return ans ;
    }
};

// Time Complexity:  O(N ^ 2) [Assuming unordered-map works in O(1) average time complexity]
// Space Complexity: O(N) [Due to the unordered-map we use]
