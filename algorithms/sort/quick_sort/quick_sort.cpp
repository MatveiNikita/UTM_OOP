#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int partition(vector<int> arr, int start, int pivot);

void quickSort(vector<int> arr, int start, int pivot)
{
    if (start < pivot)
    {
        int middle = partition(arr, start, pivot);
        quickSort(arr, start, middle - 1);
        quickSort(arr, middle + 1, pivot);
    }
}


int partition(vector<int> arr, int start, int pivot)
{
    int x = arr[pivot];
    int i = start - 1;

    for (size_t j = start; j <= pivot - 1; j++)
    {
        if (arr[j] < x)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[pivot]);

    return i + 1;
}


int main() {
    int sizes[] = {5000, 16000, 24600};
    int MAX_VAL = 10000;

    for (int n : sizes) {
        vector<int> A(n), B(n);

        for (int i = 0; i < n; i++) A[i] = rand() % (MAX_VAL + 1);

        auto start = high_resolution_clock::now();
        quickSort(A, 0, n);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "Размер: " << n << ", время: " << duration << "mcs" << endl;
    }

    return 0;
}