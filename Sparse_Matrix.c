#include <stdio.h>

#define ROW 4
#define COL 5

int main() {
    // 1. Normal Matris Tanımlama (Örnek: 4x5)
    int matrix[ROW][COL] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    // 2. Sıfır olmayan eleman sayısını bulma
    int size = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (matrix[i][j] != 0) {
                size++;
            }
        }
    }

    // 3. Sparse Matris (3-Sütun Gösterimi) Dizisi Oluşturma
    // Satır sayısı = size + 1 (ilk satır üst veriler içindir)
    // Sütun sayısı = 3 (Satır, Sütun, Değer)
    int sparseMatrix[size + 1][3];

    // Üst veri (Meta-data) tanımlama
    sparseMatrix[0][0] = ROW;   // Orijinal matris satır sayısı
    sparseMatrix[0][1] = COL;   // Orijinal matris sütun sayısı
    sparseMatrix[0][2] = size;  // Toplam sıfır olmayan eleman sayısı

    // 4. Dönüşüm İşlemi
    int k = 1;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;           // Satır indeksi
                sparseMatrix[k][1] = j;           // Sütun indeksi
                sparseMatrix[k][2] = matrix[i][j]; // Değer
                k++;
            }
        }
    }

    // 5. Sonuçları Yazdırma
    printf("--- Sparse Matrix (3-Sutun Gosterimi) ---\n");
    printf("Satir\tSutun\tDeger\n");
    printf("--------------------------\n");
    for (int i = 0; i < size + 1; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }

    return 0;
}