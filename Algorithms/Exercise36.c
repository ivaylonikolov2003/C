#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void addElement(struct Node** head, struct Node** Avail) {
    if (*head == NULL || *Avail == NULL) {
        return;
    }

    struct Node* current = *head;  
    struct Node* availCurrent = *Avail;

    while (current != NULL) {
        if (current->data > 0) {
            // Ако текущият елемент е положителен
            if (current->next != NULL && current->next->next != NULL) {
                // Ако следващият елемент е на четна позиция в списъка
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                if (newNode == NULL) {
                    fprintf(stderr, "Грешка при заделяне на памет\n");
                    exit(EXIT_FAILURE);
                }

                // Задаване на стойността на новия елемент (двоен размер на следващия елемент)
                newNode->data = 2 * current->next->data;
                // Вмъкване на новия елемент след текущия елемент
                newNode->next = current->next;
                current->next = newNode;
                // Пренасочване на указателя към списъка с налични елементи
                *Avail = availCurrent->next;
                // Пренасочване на указателя към текущия елемент в списъка с налични елементи
                availCurrent = *Avail;
            }
        }
        // Преместване на указателите към следващите елементи в двата списъка
        current = current->next;
        if (availCurrent != NULL) {
            availCurrent = availCurrent->next;
        }
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* Avail = NULL;

    for (int i = 5; i > 0; i--) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            fprintf(stderr, "Грешка при заделяне на памет\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }


    for (int i = 10; i > 0; i--) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            fprintf(stderr, "Грешка при заделяне на памет\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = i;
        newNode->next = Avail;
        Avail = newNode;
    }

    printf("List: ");
    printList(head);

    addElement(&head, &Avail);

    printf("List2: ");
    printList(head);

    freeList(head);
    freeList(Avail);

    return 0;
}