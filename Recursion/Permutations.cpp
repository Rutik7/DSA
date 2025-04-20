#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:

    void helper(vector<int>& nums, vector<int>& ds,vector<vector<int>>& result,vector<bool>&taken)
    {
        if(ds.size() == nums.size())
        {
            result.push_back(ds);
            return;
        }
        for(int i = 0;i<nums.size();i++)
        {
            if(taken[i] == false)
            {
                ds.push_back(nums[i]);
                taken[i] = true;
                helper(nums,ds,result,taken);
                ds.pop_back();
                taken[i] = false;
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool>taken(n,false);

        vector<int>ds;
        vector<vector<int>>result;
        helper(nums,ds,result,taken);
        printall(result);
        return result;
    }

    void printall(vector<vector<int>> &result)
    {
        for(int i = 0;i<result.size() ; i++)
        {
            cout<<"[";
            for(int j = 0 ; j<result[i].size() ; j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1,2,3};
    obj.permute(arr);
    return 0;
}