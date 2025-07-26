#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for generic linked list
struct Node {
    void *data;
    struct Node *next;
};

// Insert a node at the head of the list
struct Node* insertAtHead(struct Node* head, void *data, size_t data_size) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = malloc(data_size);
    newNode->next = head;
    memcpy(newNode->data, data, data_size);
    return newNode;
}

// Print the list using a function pointer for data type
void printList(struct Node *head, void (*fptr)(void *)) {
    while (head != NULL) {
        fptr(head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Free the linked list memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}

// Helper function to print an integer
void printInt(void *n) {
    printf("%d -> ", *(int *)n);
}

// Helper function to print a float
void printFloat(void *f) {
    printf("%.1f -> ", *(float *)f);
}

int main() {
    // Create an integer linked list: 10 -> 20 -> 30 -> 40
    struct Node *head = NULL;
    unsigned i_size = sizeof(int);
    int i_arr[4] = {40, 30, 20, 10};
    for (int i = 0; i < 4; i++) {
        head = insertAtHead(head, &i_arr[i], i_size);
    }

    printf("\nInteger Linked List:\n");
    printList(head, printInt);
    freeList(head);

    // Create a float linked list: 10.1 -> 20.2 -> 30.3 -> 40.4
    head = NULL;
    unsigned f_size = sizeof(float);
    float f_arr[4] = {40.4, 30.3, 20.2, 10.1};
    for (int i = 0; i < 4; i++) {
        head = insertAtHead(head, &f_arr[i], f_size);
    }

    printf("\nFloat Linked List:\n");
    printList(head, printFloat);
    freeList(head);

    return 0;
}
