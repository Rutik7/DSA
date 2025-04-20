#include<iostream>
#include<vector>
using namespace std;

class Solution {

public:
    void helper(vector<int>& nums,int index,vector<int>& ds,vector<vector<int>>& result)
    {
        result.push_back(ds);

        for(int i = index ; i<nums.size() ; i++)
        {
            if(i!=index && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            helper(nums,i+1,ds,result);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        helper(nums,0,ds,result);
        //sort(result.begin(),result.end());
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
    vector<int> arr = {1,2,2};
    obj.subsets(arr);
    return 0;
}