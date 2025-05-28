#include <stdio.h>
#include <stdlib.h>

// Hash table size chosen beforehand
#define HASHSIZE 26


// Linked list implementation (for using chaining)
typedef struct node {
    char* data;
    struct node* next;
} node;

// Print out the contents of the list, seperated by commas
void printList(node* head_p) {
    while (head_p != NULL) {
        printf("%s", head_p -> data);
        if (head_p -> next != NULL) {
            printf(", ");
        }
        head_p = head_p -> next;
    }
    printf("\n");
}

// Insert function for linked list
void add(node** head, char* word) {
    node* new_node = malloc(sizeof(node));
    // Check if memory allocated correctly
    if (new_node == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    new_node->data = word;
    new_node->next = *head;
    *head = new_node;
}

typedef struct hashtable {
    node* heads[HASHSIZE];
    size_t size;
} hashtable;

size_t hash(char* word) {
    return
}

void put(hashtable h, size_t key, int value){
    if (h.heads[key] == NULL) {
      }
}


int main() {
    node* head = NULL;
    add(&head, "first");
    printList(head);
    return 0;
}

