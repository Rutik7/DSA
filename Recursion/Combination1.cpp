#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
//so i solved my self
    void helper(vector<int>& candidates,int target,int index,vector<int>& ds,vector<vector<int>>& result)
    {
        if(index == candidates.size())
        {
            if(target == 0)
            {
                result.push_back(ds);
                
            }
            return;
        }

        if(candidates[index] <= target)
        {
            //picked the index
            ds.push_back(candidates[index]);
            helper(candidates,target-candidates[index],index,ds,result);
            ds.pop_back();
            //not picked
        }
        helper(candidates,target,index+1,ds,result);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;

        helper(candidates,target,0,ds,result);
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
    vector<int> arr = {2,3,6,7};
    vector<int> myds;
    Solution obj;
    obj.combinationSum(arr,7);
    return 0;
}
