using ll = long long ;

class DataStream {
private:
ll value, k ;
ll cnt = 0 ;
    
public:
    DataStream(int value, int k) 
    {
        this -> value = value ;
        this -> k = k ;
    }
    
    bool consec(int num) 
    {
        cnt = (ll) num == value ? cnt + 1 : 0 ;
        
        return cnt >= k ;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

// Time Complexity:  O(1) for consec() function
// Space Complexity: O(1)
