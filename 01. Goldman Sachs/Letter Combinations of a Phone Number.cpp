class Solution {
private:
vector<string> ans ;
vector<string> keypad ;
    
void solve(int i, string &s, string &digits)
{
    if(i == digits.size() )
    {
        ans.push_back(s) ;
        return ;
    }
    
    string key = keypad[digits[i] - '0'] ;
    
    for(int j = 0 ; j < key.size() ; j++)
    {
        s += key[j] ;
        
        solve(i + 1, s, digits) ;
        
        s.pop_back() ;
    }
    
    return ;
}
    
public:
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size() == 0)  return ans ;
        
        keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"} ;
        
        string curr = "" ;
        
        solve(0, curr, digits) ;
        
        return ans ;
    }
};

// Time Complexity:  O(Exponential)
// Space Complexity: O(N) 
