class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        int n = s.size() ;
        
        string pref = "" ;
        unordered_map<string, int> map ;
        
        int end = 0, k = 9 ;
        
        for(int start = 0 ; start < n ; start++)
        {
            pref += s[start] ;
            
            if(start >= k)
            {
                map[pref]++ ;
                
                pref = pref.substr(1) ;
                
            }
        }
        
        vector<string> ans ;
        
        for(auto &[DNA, freq] : map)
        {
            if(freq > 1)  ans.push_back(DNA) ;
        }
        
        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
