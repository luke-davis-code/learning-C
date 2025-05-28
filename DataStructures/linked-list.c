#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
} node;

// Print out the contents of the list, seperated by commas
void printList(node* head_p) {
    while (head_p != NULL) {
        printf("%d", head_p -> number);
        if (head_p -> next != NULL) {
            printf(", ");
        }
        head_p = head_p -> next;
    }
    printf("\n");
}

// Add an element to the beginning of the list
void add(node** list_p, int item) {
    node* new_node_p = malloc(sizeof(node));
    if (new_node_p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node_p->number = item;
    new_node_p -> next = *list_p;
    *list_p = new_node_p;
}

// Retreive the first element from the list
int get(node** list_p){
    if (*list_p == NULL) {
        printf("List is empty\n");
        return 0;
    }
    node* temp = *list_p;
    int i = temp -> number;
    *list_p = temp -> next;
    free(temp);
    return i;
}

// Return 1 if list is empty, 0 else
int isEmpty(node* list_p) {
    if (list_p == NULL) {
        return 1;
    }
    return 0;
}

/* Take in two linked lists, in (unsorted) and out (sorted), and return list obtained by taking node at beginning of in and inserting into
 * appropiate place in out list (keep it sorted)*/
node* insert(node** in, node** out) {
    // If out null or in is first item in next list
    if (*out == NULL || (*in)->number < (*out)->number) {
        (*in) -> next = *out;
        *out = *in;
    }
    // Ensure in exists
    else if (*in != NULL) {
        node* temp = *in;
        *in = (*in)->next;
        node* head = *out;
        while (head -> next != NULL && head -> next -> number < temp -> number ) {
            head = head -> next;
        }
        temp -> next = head -> next;
        head -> next = temp;
    }
    return *out;
}

node* insertionSort(node** list_p) {
    if (*list_p == NULL) {
        return NULL;
    }
    else {
        // Get second element
        node* temp = *list_p;
        *list_p = temp -> next;
        *list_p = insertionSort(list_p);
        return insert(&temp, list_p);
    }
}

int main() {
    // make lists
    node *list1 = NULL;

    add(&list1, 1);
    add(&list1, 2);
    add(&list1, 3);

    printList(list1);

    list1 = insertionSort(&list1);

    printList(list1);

//    // Make a cycle
//    // Get last item in list
//    node* n2 = list -> next;
//    n2 -> next = list;
//
//    printList(list);
    // THIS CREATES AN INFINITE LOOP AS EXPECTED

    // free memory
    free(list1);

    return 0;
}
