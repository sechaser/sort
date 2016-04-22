#include <iostream>

using namespace std;

void print(int a[], int n)
{
    for(int i = 0; i != n; ++ i)
        cout<<a[i]<<" ";

    cout<<endl;
}

void heapAdjust(int H[], int s, int length)
{
    int tmp   = H[s];           //node that need to be adjusted
    int child = 2 * s + 1;      //the left child of s

    while(child < length)
    {
        //child is the max of left child and right child
        if(((child + 1) < length) && (H[child] < H[child+1]))
            ++ child;

        if(H[s] < H[child])
        {
            H[s] = H[child];
            s    = child;
            child= 2 * s + 1;
        }

        else
            break;

        H[s] = tmp;
    }

    print(H, length);
}

void buildingHeap(int H[], int length)
{
    for(int i = (length -1)/2; i >= 0; -- i)
        heapAdjust(H, i, length);
}

void heapSort(int H[], int length)
{
    buildingHeap(H, length);

    for(int i = length - 1; i > 0; -- i)
    {
        int temp;
        temp = H[i];
        H[i] = H[0];
        H[0] = temp;

        heapAdjust(H, 0, i);
    }
}

int main()
{
    int H[10] = {3, 1, 5, 7, 2, 4, 9, 6, 10, 8};
    print(H, 10);
    heapSort(H, 10);
    print(H, 10);

    return 0;
}

