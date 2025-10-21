#include <iostream>
#include <vector>


void insertionSort(std::vector<int>& arr)
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

int main(int argc, char const *argv[])
{
    std::vector<int> A = {5, 2, 4, 6, 1, 3};

    insertionSort(A);

    for (int x : A) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
