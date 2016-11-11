#include <iostream>
#include <vector>
#include <iomanip>

void heapAdjust(std::vector<int>& nums, int father, int sz)
{
    int child = 2 * father + 1;
    int temp = nums[father];

    while(child < sz)
    {
        if(child + 1 < sz && nums[child + 1] < nums[child])
            ++ child;

        if(nums[child] > temp)
            break;

        nums[father] = nums[child];
        father = child;
        child = 2 * child + 1;
    }

    nums[father] = temp;
}


void buildHeap(std::vector<int>& nums, int sz)
{
    for(int i = sz/2 - 1; i >= 0; -- i)
        heapAdjust(nums, i, sz);
}


void heapSort(std::vector<int>& nums, int sz)
{
    buildHeap(nums, sz);

    for(int i = sz - 1; i >= 0; -- i)
    {
        std::cout<<std::setw(4)<<nums[0];
        nums[0] = nums[i];

        heapAdjust(nums, 0, i);
    }
    std::cout<<std::endl;
}


int main()
{
    std::vector<int> nums{3, 9 , 1, 4, 5, 0, 15};
    heapSort(nums, nums.size());

    return 0;
}

