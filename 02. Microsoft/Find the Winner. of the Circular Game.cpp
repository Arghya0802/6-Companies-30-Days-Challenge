class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        set<int> set ;
        
        for(int i = 1 ; i <= n ; i++)  set.insert(i) ;
        
        int i = 1 ;
        
        while(set.size() > 1)
        {
            int cnt = 0, neighbor, cntA = 0 ;
            
            while(cnt < k)
            {
                neighbor = (i + cntA) % (n + 1) ;
                
                if(set.find(neighbor) != set.end() )  cnt++ ;
                
                cntA++ ;
            }
            
            set.erase(neighbor) ;
            i = neighbor + 1 ;
            
        }
        
        return *set.begin() ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
