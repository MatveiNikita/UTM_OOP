#include <iostream>

// QUICKSORT(A, p, r)
// 1 if p < r
// 2 	then q ← PARTITION(A, p, r)
// 3	QUICKSORT(A, p, q − 1)
// 4	QUICKSORT(A, q + 1, r)

// PARTITION(A, p, r)
// 1.   x ← A[r]
// 2    i←p−1
// 3    for j ← p to r − 1
// 4	do if A[j] ⩽ x
// 5 		then i ← i + 1
// 6			Обменять A[i] ↔ A[j]
// 7    Обменять A[i + 1] ↔ A[r]
// 8  return i + 1

int partition(int arr[], int start, int end);


void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int middle = partition(arr, start, end);
        quickSort(arr, start, middle - 1);
        quickSort(arr, middle + 1, end);
    }
}


int partition(int arr[], int start, int end)
{
    int x = arr[end];
    int i = start - 1;

    for (size_t j = start; j <= end - 1; j++)
    {
        if (arr[j] < x)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[end]);

    return i + 1;
}
int main()
{
    int arr[] = {3, 1, 5, 7, 10, 9, 11};

    quickSort(arr, 0, 7);

    for (size_t i = 0; i < 7; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    return 0;
}
