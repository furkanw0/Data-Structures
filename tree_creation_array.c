#include <stdio.h>
#include <stdlib.h>

// Ağaç Düğüm Yapısı
struct Node {
    int data;
    struct Node *left, *right;
};

// Yeni bir düğüm oluşturma fonksiyonu
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Diziyi kullanarak Rekürsif Ağaç Oluşturma
struct Node* insertLevelOrder(int arr[], int i, int n) {
    struct Node* root = NULL;
    
    // Eğer geçerli bir indeks ise düğüm oluştur
    if (i < n) {
        root = newNode(arr[i]);

        // Sol çocuğu yerleştir (2*i + 1)
        root->left = insertLevelOrder(arr, 2 * i + 1, n);

        // Sağ çocuğu yerleştir (2*i + 2)
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

// Ağacı test etmek için Inorder Gezinme
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Diziyi ağaca dönüştür
    struct Node* root = insertLevelOrder(arr, 0, n);

    printf("Olusturulan Agacin Inorder Gezintisi: \n");
    inOrder(root);
    printf("\n");

    return 0;
}