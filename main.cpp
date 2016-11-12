#include <iostream>
#include <vector>
#include <iomanip>

void mergeArray(std::vector<int>& nums, int first, int mid, int last, std::vector<int>& temp)
{
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;

    while((i <= m) && (j <= n))
    {
        if(nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while(i <= m)
        temp[k++] = nums[i++];

    while(j <= n)
        temp[k++] = nums[j++];

    for(i = 0; i < k; ++ i)
        nums[first + i] = temp[i];


    for(std::vector<int>::size_type t = 0; t != nums.size(); ++ t)
        std::cout<<std::setw(4)<<nums[t];
    std::cout<<std::endl;

}

void mergeSort(std::vector<int>& nums, int low, int high, std::vector<int>& temp)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        mergeSort(nums, low, mid, temp);
        mergeSort(nums, mid + 1, high, temp);

        mergeArray(nums, low, mid, high, temp);
    }
}


int main()
{
    std::vector<int> nums{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> temp(nums.size(), 0);

    mergeSort(nums, 0, nums.size() - 1, temp);

    return 0;
}

