//leetcode 26

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[index]!=nums[i])
            {
                nums[index+1] = nums[i];
                index+=1;
            }
        }
        return index+1;
    }
};

int main()
{
    vector<int> numbers = {1,1,2,2,2,3};
    Solution obj;
    int result = obj.removeDuplicates(numbers);
    for(int i = 0;i<result;i++)
    {
        cout<<numbers[i]<<endl;
    }
   
    return 0;
}