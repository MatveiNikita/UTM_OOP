#include <iostream>

int getMax(int arr[], size_t size)
{
    int maxElm = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > maxElm) maxElm = arr[i];
    }
    return maxElm;
}

void countSort(int arr[], size_t size, int expr)
{
    int output[size];
    int count[10] = { 0 };

    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / expr) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / expr) % 10] - 1] = arr[i];
        count[(arr[i] / expr) % 10]--;
    }

    for (size_t i = 0; i < size; i++)
        arr[i] = output[i];
    
}

void radixSort(int arr[], size_t size)
{
    int m = getMax(arr, size);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, size, exp);
    
}


int main(int argc, char const *argv[])
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    
    return 0;
}
