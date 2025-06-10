#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        while(start <=  end)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }

    }
};

int main()
{
    Solution obj;
    vector<char> string = {'h','e','l','l','o','\0'};
    obj.reverseString(string);
    
    for(int i = 0;i<string.size() ;i++)
    {
        cout<<string[i];
    }
    return 0;
}