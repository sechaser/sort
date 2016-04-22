#include <iostream>

#define N 11

using namespace std;

void dualSelectionSort(int a[], int n)
{
    int temp;

    for(int i = 0; i < n/2; ++ i)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; ++ j)
        {
            if(a[j] < a[minIndex])
                minIndex = j;
        }

        temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;

        int maxIndex = i;

        for(int j = i + 1; j < n - i; ++ j)
        {
            if(a[j] > a[maxIndex])
                maxIndex = j;
        }

        temp = a[maxIndex];
        a[maxIndex] = a[n-(i+1)];
        a[n-(i+1)]  = temp;

        for(int j = 0; j < n; ++ j)
            std::cout<<a[j]<<" ";
        std::cout<<std::endl;
    }
}

int main()
{
    int a[N] = {10, 8, 6, 4, 2, 1, 3, 5, 7, 9, 11};

    dualSelectionSort(a, N);

    return 0;
}

