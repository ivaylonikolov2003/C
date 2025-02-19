#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    char used;
    int data;
    struct node *next;
};
 
struct node* createNode(int data, char used )
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->used = used;
    newNode->next = NULL;
 
    return newNode;
}
 
struct node* addToEmpty(struct node* last, int data){
    if (last != NULL)
    {
        return last;
    }
 
    struct node* newNode = createNode(data, 1);
 
    last = newNode;
    last->next = last;
 
    return last;
}
 
struct node* addBegin(struct node* last, int data)
{
    if (last == NULL)
    {
        return addToEmpty(last, data);
    }
 
    struct node* newNode = createNode(data, 1);
 
    newNode->next = last->next;
    last->next = newNode;
 
    return last;
}
 
struct node* addAfter(struct node* last, int data, int element)
{
    if (last == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
 
    struct node *newNode, *temp;
    temp = last->next;
    int size = 0;
 
    do
    {
        size++;
        if (temp->data == element)
        {
            if(temp->next == last->next)
            {
                struct node* first = last->next;
 
                struct node* previous = temp;
                for(int i = 0; i < size+1; i++)
                {
                    previous->next = createNode(0, 0);
                    previous = previous->next;
                }
                previous->next = first;
                last = previous;
            }
 
 
            if(temp->next->used == 0)
            {
                temp->next->data = data;
                temp->next->used = 1;
            } else
            {
                struct node* newNode = createNode(data, 1);
                newNode->next = temp->next;
                temp->next = newNode;
            }
 
            return last;
        }
        temp = temp->next;
    } while (temp != last->next);
 
    printf("%d is not in the list.\n", element);
    return last;
};
struct node* addBefore(struct node* last, int data, int element)
{
    if (last == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
 
    struct node *newNode, *temp;
    temp = last->next;
    do
    {
        if (temp->next->data == element)
        {
            struct node* newNode = createNode(data, 1);
 
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == last)
            {
                last = newNode;
            }
            return last;
        }
        temp = temp->next;
    } while (temp != last->next);
 
    printf("%d is not in the list.\n", element);
    return last;
}
 
struct node* deleteFirstNode(struct node* last)
{
    struct node* newNode;
 
    if (last == NULL)
    {
        printf("List is empty!\n");
        return last;
    }
 
    newNode = last->next;
 
    if (last->next == last)
    {
        free(newNode);
        last = NULL;
    }
    else
    {
        last->next = newNode->next;
        free(newNode);
    }
 
    return last;
}
struct node* deleteLastNode(struct node* last)
{
    struct node* newNode, *secondLast;
 
    if (last == NULL)
    {
        printf("List is empty!\n");
        return last;
    }
 
    while(true)
    {
        if(last->used != 0)
            if(last->next->used == 0)
                break;
 
        last = last->next;
    }
 
    newNode = last->next;
    if (last->next == last)
    {
        free(newNode);
        last = NULL;
    }
    else
    {
        secondLast = last;
        while (newNode->next != last)
        {
            newNode = newNode->next;
            secondLast = newNode;
        }
        secondLast->next = last->next;
        free(last);
        last = secondLast;
    }
 
    return last;
}

void reverseList(struct node** last)
{
    if (*last == NULL)
    {
        printf("List is empty!\n");
        return;
    }
 
    struct node* current = *last;
    struct node* first = current->next;
 
    while(true)
    {
        struct node* prev = first;
        while(true)
        {
            if(prev->next == current)
                break;
            prev = prev->next;
        }
 
        current->next = prev;
        current = prev;
 
        if(current == first)
        {
            current->next = *last;
            break;
        }
    }
 
    *last = first;
}
void printList(struct node* last)
{
    struct node* ptr;
    if (last == NULL)
    {
        printf("List is empty!");
        return;
    }
    ptr = last->next;
    do
    {
        if(ptr->used)
            printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != last->next);
}
 
int main()
{
    struct node* last = NULL;
    last = addToEmpty(last , 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addBegin(last, 5);
    last = addAfter(last, 10, 5);
    last = addAfter(last, 7, 6);
    last = addBefore(last, 9, 2);
 
    printf("Original list: ");
    printList(last);
 
    last = deleteFirstNode(last);
    printf("\nList after deleting the first node: ");
    printList(last);
 
    last = deleteLastNode(last);
    printf("\nList after deleting the last node: ");
    printList(last);
 
    reverseList(&last);
    printf("\nList after reversing: ");
    printList(last);
 
    return 0;
}