#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int key;
    struct node *next;
    struct node *prev;
};

// This link always point to first link
struct node *head = NULL;

// This link always point to the last link
struct node *last = NULL;
struct node *current = NULL;

// Is list empty
bool isEmpty() { return head == NULL; }

int length() {
    int length = 0;
    struct node *current;
    for (current = head; current != NULL; current = current->next) {
        ++length;
    }

    return length;
}

// Display the list in from first to last
void displayForward() {
    // Start from the beginning
    struct node *ptr = head;

    // Navigate till the end of the list
    printf("\n[ ");
    while (ptr != NULL) {
        printf("(%d,%d)", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf(" ]");
}

// Display the list in from last to first
void displayBackward() {
    // Start from the last
    struct node *ptr = last;

    // Navigate till the end of the list
    printf("\n[ ");
    while (ptr != NULL) {
        printf("(%d,%d)", ptr->key, ptr->data);

        // Move to next item
        ptr = ptr->prev;
        printf(" ");
    }
    printf(" ]");
}

// Insert link at the first location
void insertFirst(int key, int data) {
    // Create a link
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    if (isEmpty()) {
        // Make it the last link
        last = link;
    } else {
        // Update first prev link
        head->prev = link;
    }
    // Point it to old first link
    link->next = head;

    // Point first to new first link
    head = link;
}

// Insert link at the last location
void insertLast(int key, int data) {
    // Create a link
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    if (isEmpty()) {
        // Make it the last link
        last = link;
    } else {
        // Make link a new last link
        last->prev = link;

        // Mark old last node as prev of new link
        link->prev = last;
    }
    // Point last to new last link
    last = link;
}

// Delete first item
struct node *deleteFirst() {
    // Save reference to first link
    struct node *tempLink = head;

    // If only one link
    if (head->next == NULL) {
        last = NULL;
    } else {
        head->next->prev = NULL;
    }
    head = head->next;
    // Return the deleted link
    return tempLink;
}

// Delete link at the last location
struct node *deleteLast() {
    // Save reference to first link
    struct node *tempLink = last;

    // If only one link
    if (head->next == NULL) {
        head = NULL;
    } else {
        last->prev->next = NULL;
    }
    last = last->prev;
    // Return the deleted link
    return tempLink;
}

// Delete a link with given key
struct node *delete(int key) {
    // Start from the first link
    struct node *current = head;
    struct node *previous = NULL;

    // If list is empty
    if (head == NULL) {
        return NULL;
    }

    // Navigate through list
    while (current->key != key) {
        // If it is last node
        if (current->next == NULL) {
            return NULL;
        } else {
            // Store reference to current link
            previous = current;

            // Move to next link
            current = current->next;
        }
    }

    // Found a match, update the link
    if (current == head) {
        // Change first to point to next link
        head = head->next;
    } else {
        // Bypass the current link
        current->prev->next = current->next;
    }
    if (current == last) {
        // Change last to point to prev link
        last = current->prev;
    } else {
        current->next->prev = current->prev;
    }

    return current;
}

bool insertAfter(int key, int newKey, int data) {
    // Start from the first link
    struct node *current = head;

    // If list is empty
    if (head == NULL) {
        return false;
    }
    // Navigate through list
    while (current->key != key) {
        // If it is last node
        if (current->next == NULL) {
            return false;
        } else {
            // Move to next link
            current = current->next;
        }
    }

    // Create a link
    struct node *newLink = (struct node *)malloc(sizeof(struct node));
    newLink->key = key;
    newLink->data = data;

    if (current == last) {
        newLink->next = NULL;
        last = newLink;
    } else {
        newLink->next = current->next;
        current->next->prev = newLink;
    }

    newLink->prev = current;
    current->next = newLink;

    return true;
}

int main() {
    insertFirst(1, 10);
    insertFirst(2, 20);
    insertFirst(3, 30);
    insertFirst(4, 1);
    insertFirst(5, 40);
    insertFirst(6, 56);

    printf("\nList (First to Last): ");
    displayForward();
    printf("\n");
    printf("\nList (Last to First): ");
    displayBackward();

    printf("\nList, after deleting first record: ");
    deleteFirst();
    displayForward();

    printf("\nList, after deleting last record: ");
    deleteLast();
    displayForward();

    printf("\nList, insert after key(4): ");
    insertAfter(4, 7, 13);
    displayForward();

    printf("\nList, after delete key(4): ");
    delete (4);
    displayForward();
}
