#include<iostream>
#include<vector>

using namespace std;
class CQuickSort
{
    /*a. 1st picke the pivot element and placed its correct place*/
    int partion(vector<int>& arr,int low,int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;
        while(i<j)
        {
            while(arr[i] <= pivot && i<= high - 1)
            {
                i++;
            }
            while(arr[j] > pivot && j>= low + 1)
            {
                j--;
            }
            if(i<j)
            {
                swap(arr[i],arr[j]);
            }
        }

        swap(arr[low],arr[j]);
        return j;
    }

    void qs(vector<int>& arr,int low,int high)
    {
        if(low<high)
        {
            int pivotindex = partion(arr,low,high);
            qs(arr,low,pivotindex-1);
            qs(arr,pivotindex+1 , high);
        }
    }
    public:
    vector<int> QuickSort (vector<int>& nums)
    {
        qs(nums,0,nums.size() - 1);
        return nums;
    }
};


int main()
{
    CQuickSort qs;
    vector<int> arr = {3,4,2,5,1,7,1};
    for(int x: arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    arr = qs.QuickSort(arr);

    for(int x: arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}