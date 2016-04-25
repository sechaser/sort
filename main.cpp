#include <iostream>

#define N 10

void bucketSort(int a[], int b[], int n)
{
    for(int i = 0; i < n; ++ i)
    {
        b[a[i]] = a[i];
    }

    for(int i = 0; i < n; ++ i)
        std::cout<<b[i]<<" ";
    std::cout<<std::endl;
}

int main()
{
    int a[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int b[N];
    bucketSort(a, b, N);
    return 0;
}

