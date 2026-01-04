#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// 1. Traversal (Listeyi Yazdırma)
void printList(struct Node* last) {
    if (last == NULL) {
        printf("Liste bos.\n");
        return;
    }
    struct Node* temp = last->next; // İlk düğümden başla (last->next her zaman ilk düğümdür)
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(Bas)\n");
}

// 2. Araya Ekleme (Belirli bir değerden sonraya ekler)
struct Node* insertAfter(struct Node* last, int item, int data) {
    if (last == NULL) return NULL;

    struct Node *temp, *p;
    p = last->next; // İlk düğümden aramaya başla
    
    do {
        if (p->data == item) {
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;

            if (p == last) last = temp; // Eğer sona eklediysek last'ı güncelle
            return last;
        }
        p = p->next;
    } while (p != last->next);

    printf("%d degeri listede bulunamadi!\n", item);
    return last;
}

// 3. Silme İşlemi
struct Node* deleteNode(struct Node* last, int key) {
    if (last == NULL) return NULL;

    struct Node *curr = last->next, *prev = last;

    // Durum 1: Liste tek düğümden oluşuyorsa
    if (curr == last && curr->data == key) {
        free(curr);
        return NULL;
    }

    // Durum 2: Silinecek düğümü ara
    do {
        if (curr->data == key) {
            prev->next = curr->next;
            if (curr == last) last = prev; // Son düğüm silindiyse last'ı kaydır
            free(curr);
            return last;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);

    printf("%d degeri silinmek icin bulunamadi.\n", key);
    return last;
}

// Yardımcı Fonksiyon: Boş listeye ilk elemanı ekleme
struct Node* addToEmpty(struct Node* last, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    last = temp;
    last->next = last; // Kendine bağlanır
    return last;
}

int main() {
    struct Node* last = NULL;

    last = addToEmpty(last, 10);
    last = insertAfter(last, 10, 20); //