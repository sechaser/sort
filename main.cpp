#include <iostream>
#include <vector>
#include <iomanip>

void print(int a[], int n)
{
    for(int i = 0; i < n; ++ i)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
}

int partition(std::vector<int>& nums, int low, int high)
{
    int key = nums[low];
    int temp;

    while(low < high)
    {
        while(low < high && nums[high] >= key)
            -- high;
        temp = nums[high];
        nums[high] = nums[low];
        nums[low] = temp;


        while(low < high && nums[low] <= key)
            ++ low;
        temp = nums[high];
        nums[high] = nums[low];
        nums[low] = temp;
    }

    for(std::vector<int>::size_type i = 0; i != nums.size(); ++ i)
        std::cout<<std::setw(4)<<nums[i];
    std::cout<<std::endl;

    return low;
}

void quickSort(std::vector<int>& nums, int low, int high)
{
    if(low < high)
    {
        int pos = partition(nums, low, high);
        quickSort(nums, low, pos - 1);
        quickSort(nums, pos + 1, high);
    }
}

int main()
{
    std::vector<int> nums{4, 9, 1, 3, 7, 8, 2, 10, 6, 5};

    quickSort(nums, 0, nums.size() - 1);

    return 0;
}
