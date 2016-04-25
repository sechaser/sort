#include <iostream>

#define N 10

using namespace std;

void print(int a[], int n)
{
    for(int i = 0; i < n; ++ i)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
}

int partition(int a[], int low, int high)
{
    int key = a[low];
    int temp;
    while(low < high)
    {
        while((low < high) && (a[high] >= key))
            -- high;
        temp = a[low];
        a[low] = a[high];
        a[high] = temp;

        while((low < high) && (a[low] <= key))
            ++ low;
        temp = a[low];
        a[low] = a[high];
        a[high] = temp;
    }
    std::cout<<"low = "<<low<<" ";
    print(a, N);
    return low;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pos = partition(a, low, high);
        quickSort(a, low, pos - 1);
        quickSort(a, pos + 1, high);
    }
}

int main()
{
    int a[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    quickSort(a, 0, 9);

    return 0;
}
