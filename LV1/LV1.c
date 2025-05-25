#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gen_arr(float V[], int n, float lower, float upper) {
    for (int i = 0; i < n; i++) {
        V[i] = lower + ((float)rand() / RAND_MAX) * (upper - lower);
    }
}

//O(n)
int seq_search(float V[], int n, float x) {
    for (int i = 0; i < n; i++) {
        if (V[i] == x)
            return i;
    }
    return -1;
}
int partition(float V[], int low, int high) {
    float pivot = V[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (V[j] < pivot) {
            i++;
            float temp = V[i];
            V[i] = V[j];
            V[j] = temp;
        }
    }
    float temp = V[i + 1];
    V[i + 1] = V[high];
    V[high] = temp;
    return i + 1;
}

//O(n^2)
void quick_sort(float V[], int low, int high) {
    if (low < high) {
        int pi = partition(V, low, high);
        quick_sort(V, low, pi - 1);
        quick_sort(V, pi + 1, high);
    }
}

//O(log n)
int bin_search(float V[], int n, float x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (V[mid] == x)
            return mid;
        else if (V[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void test_case(int n) {
    float* arr = (float*)malloc(n * sizeof(float));
    float x = -1.0; // Value not in array

    gen_arr(arr, n, 0.0, 1.0);

    clock_t start, end;
    double duration;

    // Sequential Search
    start = clock();
    for (int i = 0; i < 10; i++) seq_search(arr, n, x); // repeat 10x
    end = clock();
    duration = ((double)(end - start) / CLOCKS_PER_SEC * 1000) / 10;
    printf("n = %d | Sequential Search: %.4f ms | ", n, duration);

    // Sort
    gen_arr(arr, n, 0.0, 1.0); // regenerate data before sorting
    start = clock();
    quick_sort(arr, 0, n - 1);
    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("Sort: %.2f ms | ", duration);

    // Binary Search
    start = clock();
    for (int i = 0; i < 1000000; i++) bin_search(arr, n, x); // repeat 1000000x
    end = clock();
    duration = ((double)(end - start) / CLOCKS_PER_SEC * 1000) / 1000000;
    printf("Binary Search: %.6f ms\n", duration);

    free(arr);
}

int main()
{
    // LV1 test
    srand((unsigned)time(NULL));

    int test_sizes[] = { 10000, 20000, 50000, 100000, 200000, 500000, 10000000 };
    int num_tests = sizeof(test_sizes) / sizeof(test_sizes[0]);

	for (int i = 0; i < num_tests; i++) 
    {
		test_case(test_sizes[i]);
	}

    //LV2 test


	return 1;
}
