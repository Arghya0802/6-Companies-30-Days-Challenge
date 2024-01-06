using ll = long long ;
const ll MOD = 1e9 + 7 ;

class Solution {
private:
ll delay, forget ;
vector<ll> dp ;
    
ll solve(int day, int n)
{
    // Since, I am starting with 0-based indexing, I can go max upto (n - 1) days
    if(day >= n)  return 0 ;
    
    if(dp[day] != -1)  return dp[day] ;
    
    // If the person will forget before (N - 1) days, we don't count him
    ll res = day + forget >= n ? 1 : 0 ; 
    
    for(int i = day + delay ; i < day + forget ; i++)
    {
        ll person = solve(i, n) % MOD ;
        
        res += person, res %= MOD ;
    }
    
    return dp[day] = res ;
}
    
public:
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        dp.resize(n + 1, -1) ;
        
        this -> delay = delay ;
        this -> forget = forget ;
        
        return (int)  solve(0, n) ; 
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N)
