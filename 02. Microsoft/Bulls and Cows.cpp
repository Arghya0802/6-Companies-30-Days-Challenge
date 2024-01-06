class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int n = secret.size(), bulls = 0, cows = 0 ;
    
        int freqS[10] = {0} ;
        int freqG[10] = {0} ;
         
        for(int i = 0 ; i < n ; i++)
        {
            char chS = secret[i], chG = guess[i] ;
            
            if(chS == chG)  bulls++ ;
            
           else 
           {
               freqS[chS - '0']++ ;
               freqG[chG - '0']++ ;
           }
        }
        
        for(int i = 0 ; i < 10 ; i++)  cows += min(freqS[i], freqG[i] ) ;
            
        string ans = to_string(bulls) + "A" + to_string(cows) + "B" ;
        
        return ans ;
    }
};

// Time Complexity:  O(N)
// Space COmplexity: O(1)
