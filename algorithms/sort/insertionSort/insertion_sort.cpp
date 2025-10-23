#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

void insertionSort(vector<int>& arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        size_t j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
}

int main()
{
    vector<int> __size = {5000, 16000, 24600};
    int MAX_VAL = 10000;

    for (int size : __size)
    {
        std::vector<int> A(size);
        for (int i = 0; i < size; i++) A[i] = rand() % (MAX_VAL + 1);

        auto start = high_resolution_clock::now();
        insertionSort(A);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "Размер: " << size << ", время: " << duration << " mcs\n";
    }
    
    return 0;
}
