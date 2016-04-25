#include <iostream>

#define N 10

void print(int a[], int n)
{
    for(int i = 0; i < n; ++ i)
        std::cout<<a[i]<<" ";
    std::cout<<std::endl;
}

void mergeArray(int a[], int first, int mid, int last, int temp[])
{
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;

    while((i <= m) && (j <= n))
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i];
            ++ i;
            ++ k;
        }
        else
        {
            temp[k] = a[j];
            ++ j;
            ++ k;
        }
    }

    while(i <= m)
    {
        temp[k] = a[i];
        ++ i;
        ++ k;
    }

    while(j <= n)
    {
        temp[k] = a[j];
        ++ j;
        ++ k;
    }

    for(i = 0; i < k; ++ i)
        a[first + i] = temp[i];

    print(a, N);
}

void mergeSort(int a[], int first, int last, int temp[])
{
    if(first < last)
    {
        int mid = (first + last)/2;
        mergeSort(a, 0, mid, temp);          //左边有序
        mergeSort(a, mid + 1, last, temp);   //右边有序

        mergeArray(a, first, mid, last, temp);
    }
}


int main()
{
    int a[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int b[N];

    mergeSort(a, 0, N-1, b);

    return 0;
}

