//leetcode 42 Trapping rain water
#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] = height[0];
        right[n-1] = height[n-1];

        //fill the left 
        for(int i = 1;i<n;i++)
        {
            left[i] = max(height[i],left[i-1]);
        }

        //fill the right
        for(int i = n-2;i>=0;i--)
        {
            right[i] = max(height[i],right[i+1]);
        }

        //find the anser
        int maxWater=0;

        for(int i = 0 ;i<n;i++)
        {
            maxWater += min(left[i],right[i]) - height[i];
        }

        return maxWater;

    }
};

int main()
{
    Solution obj;
    vector<int> height = {4,2,0,3,2,5};
    cout<<obj.trap(height)<<endl;
    return 0;
}