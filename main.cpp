#include <iostream>

#define N 10
using namespace std;


void InsertSort(int a[], int n)
{
    int x;
    for(int i = 1; i < n; ++ i)
    {
        x = a[i];                         //store the value that will be inserted
        int j = i - 1;
        while((j >=  0) && (a[j] >= x))
        {
            a[j + 1] = a[j];
            -- j;
        }
        a[j + 1] = x;

        for(j = 0; j < n; ++ j)
            std::cout<<a[j]<<" ";
        std::cout<<std::endl;
    }
}

int main()
{
    int a[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    InsertSort(a, N);

    return 0;
}
