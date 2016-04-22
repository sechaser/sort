#include <iostream>

#define N 11
using namespace std;


void ShellSort(int a[], int n)
{
    int step = n/2;
    while(step >= 1)
    {
        for(int i = step; i < n; ++ i)
        {
            int j = i - step;
            int x = a[i];

            while((j >= 0) && (a[j] > x))
            {
                a[j + step] = a[j];
                j = j - step;
            }

            a[j+step] = x;

            for(int k = 0; k < n; ++ k)
                std::cout<<a[k]<<" ";
            std::cout<<std::endl;
        }

        step = step/2;
    }
}

int main()
{
    int a[N] = {2, 9, 10, 7, 6, 4, 8, 11, 0, 1, 5};

    ShellSort(a, N);

    return 0;
}



