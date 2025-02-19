#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Функция за премахване на всеки втори възел със зададен критерий
struct Node* removeNodes(struct Node* head, struct Node** avail) {
    if (head == NULL) {
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* newHead = head; // Новата глава на списъка

    while (current != NULL) {
        // Проверка на условието за премахване
        if ((current->data) == 3 * (current->data)) {
            // Ако текущият елемент отговаря на условието, премахваме го
            if (prev != NULL) {
                prev->next = current->next;
                free(current);
                current = prev->next;
            } else {
                // Ако текущият елемент е първи в списъка, премахваме го и обновяваме новата глава
                newHead = current->next;
                free(current);
                current = newHead;
            }

            // Поставяме премахнатия възел в списъка Avail
            current->next = *avail;
            *avail = current;
        } else {
            // Продължаваме към следващия елемент
            prev = current;
            current = current->next;
        }
    }

    return newHead;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    struct Node* avail = NULL;

    printf("Exit list: ");
    printList(head);

    head = removeNodes(head, &avail);

    printf("List after deletion: ");
    printList(head);

    printf("Avail list: ");
    printList(avail);

    return 0;
}
