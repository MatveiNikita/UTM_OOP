#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

void countingSort(vector<int>& A, vector<int>& B, int k) {
    vector<int> C(k + 1, 0);

    int n = A.size();
    for (int j = 0; j < n; j++) C[A[j]]++;
    for (int i = 1; i <= k; i++) C[i] += C[i - 1];
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main() {
    int sizes[] = {5000, 16000, 24600};
    int MAX_VAL = 10000;

    for (int n : sizes) {
        vector<int> A(n);
        vector<int> B(n);

        // генерируем массив
        for (int i = 0; i < n; i++) A[i] = rand() % (MAX_VAL + 1);

        auto start = high_resolution_clock::now();
        countingSort(A, B, MAX_VAL);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start).count();
        cout << "Размер: " << n << ", время: " << duration << " mcs\n";
    }

    return 0;
}
