#include<iostream>
#include<vector>
using namespace std;

class Solution {

public:
    void helper(vector<int>&nums,vector<int>& ds,vector<vector<int>>& result,int index)
    {
        if(index == nums.size())
        {
            result.push_back(ds);
            return;
        }
        
            ds.push_back(nums[index]);
            helper(nums,ds,result,index+1);
            ds.pop_back();
            helper(nums,ds,result,index+1);
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>myds;
        vector<vector<int>> result;
        helper(nums,myds,result,0);
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
    vector<int> arr = {1,2,3};
    obj.subsets(arr);
    return 0;
}