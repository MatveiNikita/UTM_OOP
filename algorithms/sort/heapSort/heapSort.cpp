#include <iostream>

void heapify(int arr[], unsigned int size, unsigned int index)
{
    unsigned int bigger = index;
    unsigned int left = 2 * index + 1;
    unsigned int right = 2 * index + 2;

    if (left < size && arr[left] > arr[bigger]) bigger = left;

    if (right < size && arr[right] > arr[bigger]) bigger = right;
    
    if (bigger != index)
    {
        int temp = arr[index];
        arr[index] = arr[bigger];
        arr[bigger] = temp;
        
        heapify(arr, size, bigger);
    }
}

void heap_sort(int arr[], unsigned int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (size_t i = size - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    
}

void build_heap(int arr[], unsigned int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
}

int main(int argc, char const *argv[])
{
    
    int matrix[7] = {1, 10, 2, 3, 4, 5, 8};

    heap_sort(matrix, 7);

    for (size_t i = 0; i < 7; i++)
    {
        std::cout << matrix[i] << " ";
    }
    
    return 0;
}
