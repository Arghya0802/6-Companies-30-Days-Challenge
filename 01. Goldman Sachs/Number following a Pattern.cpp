class Solution{   
public:
    string printMinNumberForPattern(string s)
    {
        string ans = "" ;
        int n = s.size() ;
        
        stack<int> st ;
        
        for(int i = 0 ; i <= n ; i++)
        {
            st.push(i + 1) ;
            
            if(i ==  n || s[i] == 'I')
            {
                while(!st.empty() )
                {
                    ans += (st.top() + '0') ;
                    st.pop() ;
                }
            }
        }
        
        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
