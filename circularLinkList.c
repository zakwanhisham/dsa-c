#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

bool isEmpty() { return head == NULL; }

int length() {
    int length = 0;

    // If list is empty
    if (head == NULL) {
        return 0;
    }

    current = head->next;
    while (current != head) {
        ++length;
        current = current->next;
    }

    return length;
}

// Insert link at first location
void insertFirst(int key, int data) {
    // Create a link
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    if (isEmpty()) {
        head = link;
        head->next = head;
    } else {
        // Point it to old first node
        link->next = head;

        // Point first to new first node
        head = link;
    }
}

// Delete first item
struct node *deleteFirst() {
    // Save reference to first link
    struct node *tempLink = head;
    if (head->next == head) {
        head = NULL;
        return tempLink;
    }
    // Mark next to first link as first
    head = head->next;

    // Return the deleted link
    return tempLink;
}

// Display the list
void printList() {
    struct node *ptr = head;
    printf("\n[ ");

    // Start from the beginning
    if (head != NULL) {
        while (ptr->next != ptr) {
            printf("(%d,%d) ", ptr->key, ptr->data);
            ptr = ptr->next;
        }
    }
    printf(" ]");
}

int main() {
    insertFirst(1, 10);
    insertFirst(2, 20);
    insertFirst(3, 30);
    insertFirst(4, 1);
    insertFirst(5, 40);
    insertFirst(6, 56);
    printf("Original List: ");

    // Print list
    printList();

    while (!isEmpty()) {
        struct node *temp = deleteFirst();
        printf("\nDeleted value:");
        printf("(%d,%d) ", temp->key, temp->data);
    }

    printf("\nList after deleting all items: ");
    printList();
}
