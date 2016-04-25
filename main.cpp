#include <iostream>

#define N 10

using namespace std;

void simpleSelectionSort(int a[], int n)
{
    int temp;

    for(int i = 0; i < (n-1); ++ i)
    {
        int index = i;
        for(int j = i + 1; j < n; ++ j)
        {
            if(a[j] < a[index])
                index = j;
        }

        temp = a[index];
        a[index] = a[i];
        a[i] = temp;


        for(int j = 0; j < n; ++ j)
            std::cout<<a[j]<<" ";
        std::cout<<std::endl;
    }
}

int main()
{
    int a[N] = {10, 8, 6, 4, 2, 1, 3, 5, 7, 9};

    simpleSelectionSort(a, N);

    return 0;
}

