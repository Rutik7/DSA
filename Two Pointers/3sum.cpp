//leetcode 3sum

#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin() , nums.end());
        int n = nums.size();

        for(int i = 0;i<n ; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int start = i+1;
            int end = n-1;
            while(start<end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum < 0)
                {
                    start++;
                }
                else if(sum>0)
                {
                    end--;
                }
                else
                {
                    vector<int> temp ({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                    result.push_back(temp);
                    while(start<end && nums[start]==nums[start-1])
                        start++;
                    
                    while(start<end && nums[end]==nums[end+1])
                        end--;
                }
            }
        }

        return result;
    }
};
void printresult(vector<vector<int>> & result)
{
    for(int i = 0 ;i<result.size();i++)
    {
        for(int j = 0;j<result[i].size() ; j++)
        {
            cout<<result[i][j] << " ";
        }
        cout<<endl;
    }
}
int main()
{
    vector<int> test = {-1,0,1,2,-1,-4};
    Solution obj;
    vector<vector<int>> result = obj.threeSum(test);

    printresult(result);
    return 0;
}