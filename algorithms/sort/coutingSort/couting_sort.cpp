#include <iostream>

void countingSort(int A[], int B[], int k, size_t size) {
    int C[k + 1] = { 0 };

    for (int j = 0; j < size; j++)
        C[A[j]]++;

    for (int i = 1; i <= k; i++)
        C[i] += C[i - 1];

    for (int j = size - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main()
{
    int A_arr[] = {3, 1, 5, 7, 10, 9, 11};

    int B_arr[7] = { 0 };

    countingSort(A_arr, B_arr, 11, 7);

    for (int x : B_arr) std::cout << x << " ";  

    return 0;
}
