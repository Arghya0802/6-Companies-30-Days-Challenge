class Solution {
private:
int m, n ;
map<pair<int, int>, int> map ;
    
public:
    Solution(int m, int n) 
    {
        this -> m = m ;
        this -> n = n ;
    }
    
    vector<int> flip() 
    {
        int row = rand() % m ;
        int col = rand() % n ;
        
        while(map.find( {row, col} ) != map.end() )
        {
            row = rand() % m ;
            col = rand() % n ;
        }
        
        map[ {row, col} ] = 1 ;
        
        return {row , col} ;
    }
    
    void reset() 
    {
        map.clear() ;
        return ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

// Time Complexity:  O(Log N) [Everytime flip() & reset() is called as we are using ordered-map]
// Space Complexity: O(1)
