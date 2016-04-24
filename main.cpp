#include <iostream>

#define N 10

using namespace std;

void print(int a[], int n)
{
    for(int i = 0; i < n; ++ i)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
}

void bubbleSort(int a[], int n)
{
    for(int i = 0; i < (n-1); ++ i)
    {
        for(int j = 0; j < (n - i); ++ j)
        {
            int temp;
            if(a[j] > a[j + 1])
            {
                temp  = a[j];
                a[j]  = a[j+1];
                a[j+1]= temp;
            }
        }
        print(a, n);
    }
}

int main()
{
    int a[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    bubbleSort(a, N);

    return 0;
}

