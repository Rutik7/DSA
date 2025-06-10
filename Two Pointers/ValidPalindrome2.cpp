#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool check(string &s,int start,int end)
    {
        while(start<end)
        {
            if(s[start]!=s[end])
                return false;
            
            start++;
            end--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        if(s.length() <=2) return true;
       
        int start = 0;
        int end = s.length() -1;
        
        while(start < end)
        {

            if(s[start] == s[end])
            {
                start++;
                end--;
            }
            else  
                return check(s,start,end-1) || check(s,start+1,end);
            
        }
        return true;
    }
};

int main()
{
    Solution obj;
    cout<<obj.validPalindrome("abcba")<<endl;
    return 0;
    
}