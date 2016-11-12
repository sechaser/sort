#include <iostream>
#include <vector>
#include <iomanip>


void shellSort(std::vector<int>& nums, int sz)
{
    int step = sz / 2;
    int temp;
    int prev;

    while(step >= 1)
    {
        for(int beg = step; beg < sz; ++ beg)
        {
            temp = nums[beg];
            prev = beg - step;

            while(prev >= 0 && nums[prev] > temp)
            {
                nums[prev + step] = nums[prev];
                prev = prev - step;
            }

            nums[prev + step] = temp;
        }

        for(std::vector<int>::size_type i = 0; i != nums.size(); ++ i)
            std::cout<<std::setw(4)<<nums[i];
        std::cout<<std::endl;

        step = step / 2;
    }
}

int main()
{
    std::vector<int> nums{2, 9, 10, 7, 6, 4, 8, 11, 0, 1, 5};
    shellSort(nums, nums.size());

    return 0;
}



