#include <stdio.h>

// Dizideki iki elemanın yerini değiştiren fonksiyon
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Max Heap: Ebeveyn çocuktan büyük olmalı
void maxHeapify(int arr[], int n, int i) {
    int largest = i;    // Kökü en büyük kabul et
    int sol = 2 * i + 1; 
    int sag = 2 * i + 2; 

    if (sol < n && arr[sol] > arr[largest])
        largest = sol;

    if (sag < n && arr[sag] > arr[largest])
        largest = sag;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest); // Alt ağacı tekrar düzenle
    }
}

// Min Heap: Ebeveyn çocuktan küçük olmalı
void minHeapify(int arr[], int n, int i) {
    int smallest = i;   // Kökü en küçük kabul et
    int sol = 2 * i + 1;
    int sag = 2 * i + 2;

    if (sol < n && arr[sol] < arr[smallest])
        smallest = sol;

    if (sag < n && arr[sag] < arr[smallest])
        smallest = sag;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Orijinal Dizi: ");
    printArray(arr, n);

    // Max Heap Oluşturma
    // (n/2 - 1)'den başlamak yaprağı olmayan son düğümden başlamak demektir
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    printf("Max Heap Hali: ");
    printArray(arr, n);

    // Min Heap Oluşturma
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    printf("Min Heap Hali: ");
    printArray(arr, n);

    return 0;
}