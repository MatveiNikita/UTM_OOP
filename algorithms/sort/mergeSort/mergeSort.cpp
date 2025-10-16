#include <iostream>

// MERGE(A, p, q, r)
// n1 ← q − p + 1
// n2 ← r − q
// for i ← 1 to n1
//    do L[i] ← A[p + i − 1]
// for j ← 1 to n2
//    do R[j] ← A[q + j]
// L[n1 + 1] ← ∞
// R[n2 + 1] ← ∞
// i←1
// j←1
// for k ← p to r
//  do if L[i] ⩽ R[j]
//      then A[k] ← L[i]
//          i←i+1
//     else A[k] ← R[j]
//          j ←j+1

void merge(int arr[], unsigned int start, unsigned int midle, unsigned int end)
{
    unsigned int n1 = midle - start + 1;
    unsigned int n2 = end - midle;

    int Left[n1 + 1], Right[n2 + 1];
    
    for (unsigned int i = 0; i < n1; i++)
    {   
        Left[i] = arr[start + i];
    }

    for (unsigned int j = 0; j < n2; j++)
    {
        Right[j] = arr[midle + 1 + j];
    }
    
    Left[n1] = 100000;
    Right[n2] = 100000;

    unsigned int i = 0;
    unsigned int j = 0;

    for (unsigned int k = start; k <= end; k++)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;

        } else {
            arr[k] = Right[j];
            j++;
        }
    }
}

void merge_sort (int arr[], unsigned int start, unsigned int end)
{
    if (start < end)
    {
        unsigned int midle = (start + end) / 2;
        merge_sort(arr, start, midle);
        merge_sort(arr, midle + 1, end);
        merge(arr, start, midle, end);
    }
    
}
int main(int argc, char const *argv[])
{
    int arr[] = {6, 3, 8, 4, 9, 1, 2};
    unsigned int size = 7;

    merge_sort(arr, 0, size);
        
    return 0;
}
