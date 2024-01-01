// Link:  https://leetcode.com/problems/high-access-employees/

class Solution {
private:
    
int calculateTime(string &s)
{
    int hrs  = (s[0] - '0') * 10 + (s[1] - '0') ;
    int mins = (s[2] - '0') * 10 + (s[3] - '0') ;
    
    return (hrs * 60 + mins) ;
}
    
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) 
    {
        int n = access_times.size() ;
        
        vector<string> ans ;
        
        sort(access_times.begin(), access_times.end() ) ;
        
        for(int i = 0 ; i < n ; i++)  
        {
            string name = access_times[i][0] ;
            int end = i, start = i + 1, maxCnt = 1 ;
            
            while(start < n && access_times[start][0] == name)
            {
                int startTime = calculateTime(access_times[start][1] ) ;
                int endTime   = calculateTime(access_times[end][1] ) ;
                
                while(end <= start && startTime - endTime >= 60)
                {
                    end++ ;
                    endTime = calculateTime(access_times[end][1] ) ;
                }
                
                maxCnt = max(maxCnt, start - end + 1) ;
                start++ ;
            }
            
            if(maxCnt >= 3)  ans.push_back(name) ;
            
            i = start - 1 ;
        }
        
        return ans ;
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(1)
