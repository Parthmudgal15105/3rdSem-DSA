#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
        {
            return m;
        }
        if (arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = linearSearch(arr, n, x);
    if (result != -1)
    {
        cout << "Element is present at index " << result << " using Linear Search" << endl;
    }
    else
    {
        cout << "Element is not present in array using Linear Search" << endl;
    }

    result = binarySearch(arr, 0, n - 1, x);
    if (result != -1)
    {
        cout << "Element is present at index " << result << " using Binary Search" << endl;
    }
    else
    {
        cout << "Element is not present in array using Binary Search" << endl;
    }

    return 0;
}
