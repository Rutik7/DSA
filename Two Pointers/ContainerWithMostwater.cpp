//leetcode 11 container with most water
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int left = 0;
        int right = height.size()-1;

        while(left<right)
        {
            int width = right - left;
            int curr = width * min(height[left],height[right]);
            maxwater = max(maxwater,curr);
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxwater;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution obj;
    cout<<obj.maxArea(height)<<endl;
    return 0;
}