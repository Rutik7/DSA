#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;

        while(start<end)
        {
            int num = numbers[start] + numbers[end];
            if(num == target)
            {
                return {start+1,end+1};
            }
            if(num>target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        return {-1,-1};
    }
};

int main()
{
    vector<int> numbers = {2,7,11,15};
    Solution obj;
    vector<int> result = obj.twoSum(numbers,9);
    cout<<"result: "<<result[0] << " "<<result[1]<<endl;  
    return 0;
}