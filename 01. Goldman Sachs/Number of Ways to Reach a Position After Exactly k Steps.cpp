using ll = long long ;
const ll MOD = 1e9 + 7 ;

class Solution {
private:
int end ;
vector<vector<ll>> dp ;
    
ll solve(int pos, int k)
{
    if(k == 0)  return pos == end ;
    
    if(dp[pos + 1000][k] != -1)  return dp[pos + 1000][k] ;
    
    ll ans = 0 ;
    
    ll left  = solve(pos - 1, k - 1) % MOD ;
    ll right = solve(pos + 1, k - 1) % MOD ;
    
    ans += left,  ans %= MOD ;
    ans += right, ans %= MOD ;
    
    return dp[pos + 1000][k] = ans ;
}
    
public:
    int numberOfWays(int startPos, int endPos, int k) 
    {
        dp.resize(3002, vector<ll> (1002, -1) ) ;
        
        this -> end = endPos ;
        
        return (int) solve(startPos, k) ;                    
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
