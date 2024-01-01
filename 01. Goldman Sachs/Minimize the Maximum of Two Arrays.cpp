// Link:  https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/

using ll = long long ;

class Solution {
private:
ll lcm, d1, d2, cntA, cntB ;
    
ll isOkay(ll mid)
{
    ll notDiv_by_A = mid - (mid / d1) ;
    ll notDiv_by_B = mid - (mid / d2) ;
    ll notDiv_by_AB = mid - (mid / lcm) ;
    
    return (notDiv_by_A >= cntA) && (notDiv_by_B >= cntB) && (notDiv_by_AB >= cntA + cntB) ; 
}
    
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) 
    {
        d1 = divisor1, d2 = divisor2, cntA = uniqueCnt1, cntB = uniqueCnt2 ;
        
        ll hcf = __gcd(d1, d2) ;
        lcm = (d1 * d2) / hcf ;
        
        ll low = 1, high = 2 * 1e10 ;
        ll ans = -1 ;
        
        while(low <= high)
        {
            ll mid = low + (high - low) / 2 ;
            
            if(isOkay(mid) ) 
            {
                ans = mid, high = mid - 1 ;
            }
            
            else low = mid + 1 ;
        }
        
        return (int) ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
