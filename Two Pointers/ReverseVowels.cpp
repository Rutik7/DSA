//leecode 345
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isvowel(char ch)
    {
        ch = tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
            return true;

        return false;
    }
    string reverseVowels(string s) {

        int start = 0;
        int end = s.length() - 1;
        while(start < end)
        {
            while(start<end && !isvowel(s[start]))
            {
                start++;
            }
            while(start<end && !isvowel(s[end]))
            {
                end--;
            }

            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        return s;
    }
};

int main()
{
    Solution obj;
    string s = obj.reverseVowels("IceCreAm");
    
    for(int i = 0;i<s.size() ;i++)
    {
        cout<<s[i];
    }
    return 0;
}