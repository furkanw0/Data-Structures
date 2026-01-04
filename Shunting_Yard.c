#include <stdio.h>

// Hanoi Kuleleri Fonksiyonu
void hanoi(int n, char kaynak, char hedef, char yardimci) {
    // Temel durum: Eğer sadece 1 disk kaldıysa onu taşı
    if (n == 1) {
        printf("Disk 1: %c -> %c\n", kaynak, hedef);
        return;
    }

    // 1. Adım: Üstteki n-1 diski kaynaktan yardımcı çubuğa taşı
    hanoi(n - 1, kaynak, yardimci, hedef);

    // 2. Adım: Kalan en büyük diski (n. disk) kaynaktan hedefe taşı
    printf("Disk %d: %c -> %c\n", n, kaynak, hedef);

    // 3. Adım: Yardımcı çubuktaki n-1 diski hedefe taşı
    hanoi(n - 1, yardimci, hedef, kaynak);
}

int main() {
    int disk_sayisi;

    printf("Hanoi Kuleleri Cozumu\n");
    printf("---------------------\n");
    printf("Disk sayisini giriniz: ");
    scanf("%d", &disk_sayisi);

    if (disk_sayisi <= 0) {
        printf("Lutfen pozitif bir tam sayi giriniz.\n");
    } else {
        printf("\nTasima Adimlari:\n");
        // A: Kaynak, C: Hedef, B: Yardımcı çubuk
        hanoi(disk_sayisi, 'A', 'C', 'B');
        printf("\nIslem tamamlandi.\n");
    }

    return 0;
}