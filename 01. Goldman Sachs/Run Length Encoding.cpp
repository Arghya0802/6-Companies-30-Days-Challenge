/*You are required to complete this function */

string encode(string src)
{
    src += '#' ;
    string ans = "" ;
    
    char prev = src[0] ;
    int cnt = 0, n = src.size() ;
    
    
    for(int i = 0 ; i < n ; i++)
    {
        if(src[i] == prev)  cnt++ ;
        
        else
        {
            ans += prev, ans += to_string(cnt) ;
            prev = src[i], cnt = 1 ;
        }
    }
    
    return ans ;
}   

// Time Complexity:  O(N)
// Space Complexity: O(1) [If we exclude the ans string]
