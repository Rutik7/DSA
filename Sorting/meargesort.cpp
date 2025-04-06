#include<iostream>
#include<vector>
using namespace std;
//Mearge sort
class MeargeSort
{
    void meargesort(vector<int>& nums,int low,int high)
    {
        if(low == high) return;
        int mid = (low + high)/2;
        meargesort(nums,low,mid);
        meargesort(nums,mid+1,high);
        mearge(nums,low,mid,high);
    }

    void mearge(vector<int> &nums,int low,int mid,int high)
    {
        vector<int> temp;
        //low ... mid ... high
        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high)
        {
            if(nums[left]<nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low;i<=high;i++)
        {
            nums[i] = temp[i-low];
        }

    }
    public:
    vector<int> sortArray(vector<int>& nums) {
        meargesort(nums,0,nums.size()-1);
        return nums;
    }

};
int main()
{
    MeargeSort ms;
    vector<int> arr = {3,4,2,5,1,7,1};
    for(int x: arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    arr = ms.sortArray(arr);

    for(int x: arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
