using ll = long long ;

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) 
    {
        ll N = n ;
        
        ll totA = (N * (N + 1) ) / 2 ;
        ll totB = (N * (N + 1) * (2 * N + 1) ) / 6 ;
        
        ll sumA = 0, sumB = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            ll val = arr[i] ;
            sumA += val, sumB += (val * val) ;
        }
        
        ll x = sumA - totA ;
        ll y = sumB - totB ;
        ll z = (y / x) ;
        
        int repeating = (z + x) / 2 ;
        int missing = (z - x) / 2 ;
        
        return {repeating, missing} ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
