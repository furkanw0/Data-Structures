#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Yeni bir düğüm oluşturma
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 1. Araya Ekleme (Belirtilen değerden sonraya)
void insertAfter(struct Node* prev_node, int data) {
    if (prev_node == NULL) {
        printf("Onceki dugum NULL olamaz!\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

// 2. Silme İşlemi (Belirli bir düğümü silme)
void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) return;

    // Silinecek düğüm head ise
    if (*head_ref == del) {
        *head_ref = del->next;
    }

    // Sondaki düğüm değilse, sonrakinin prev bağını güncelle
    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    // Baştaki düğüm değilse, öncekinin next bağını güncelle
    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    free(del);
}

// 3. Traversal (Gezinme)
void printList(struct Node* node) {
    struct Node* last;
    printf("\nIleriye dogru: ");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nGeriye dogru: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    // Listeyi bağla
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Baslangic Listesi:");
    printList(head);

    // Araya ekleme: 20'den sonra 25 ekle
    insertAfter(second, 25);
    printf("\n20'den sonra 25 eklendi:");
    printList(head);

    // Silme: 20'yi sil
    deleteNode(&head, second);
    printf("\n20 silindi:");
    printList(head);

    return 0;
}