#include <stdio.h>

#define MAX_SIZE 100

// Diziyi ekrana yazdıran fonksiyon
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 1. Araya Ekleme (Belirli bir indise)
int insertAt(int arr[], int *size, int pos, int value) {
    if (*size >= MAX_SIZE) {
        printf("Hata: Dizi dolu!\n");
        return 0;
    }
    if (pos < 0 || pos > *size) {
        printf("Hata: Gecersiz indis!\n");
        return 0;
    }

    // Elemanları sağa kaydır
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    (*size)++; // Eleman sayısını artır
    return 1;
}

// 2. Silme İşlemi (Belirli bir indisten)
int deleteAt(int arr[], int *size, int pos) {
    if (*size <= 0) {
        printf("Hata: Dizi zaten bos!\n");
        return 0;
    }
    if (pos < 0 || pos >= *size) {
        printf("Hata: Gecersiz indis!\n");
        return 0;
    }

    // Elemanları sola kaydır
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Eleman sayısını azalt
    return 1;
}

int main() {
    int arr[MAX_SIZE] = {10, 20, 30, 40, 50};
    int size = 5;

    printf("Baslangic Dizisi: ");
    printArray(arr, size);

    // Araya (2. indise) 25 ekleyelim
    insertAt(arr, &size, 2; 25);
    printf("2. indise 25 eklendi: ");
    printArray(arr, size);

    // 3. indisteki elemanı silelim
    deleteAt(arr, &size, 3);
    printf("3. indis silindi: ");
    printArray(arr, size);

    return 0;
}