//leetcode 125 valid Palindrome

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() -1;

        while(start<end)
        {
            while(start<end && !isalnum(s[start]))
            {
                start++;
            }
            while(start<end && !isalnum(s[end]))
            {
                end--;
            }

            if(tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};

int main()
{
    Solution obj;
    cout<<obj.isPalindrome("A man, a plan, a canal: Panama")<<endl;
    return 0;
}