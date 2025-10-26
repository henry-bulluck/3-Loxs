// To get some practice with pointers, define a doubly linked list of heap-allocated strings.
// Write functions to insert, find, and delete items from it.
// Test them.

#include <stdio.h>
#include <stdlib.h>

// Define node
typedef struct Node {
    char* data;
    struct Node* next;
    struct Node* prev;
} Node;
// Define Linked List
typedef struct DoublyLinkedList
{
    struct Node* head;
    struct Node* tail;
} LinkedList;

// Functions for linked lists

LinkedList* createList(){
    // Creates linked list
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    // Assignes values of list
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void printList(LinkedList* list){
    printf("[");

    Node* node = list->head;

    while(node != NULL){
        printf("%s, ", node->data);

        node = node->next;
    }

    printf("]\n");
}

Node* createNode(char* data){
    // Creates node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Assigns values of Node
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insertBefore(LinkedList* list, Node* node, char* data){
    // Creates new node with data
    Node* newNode = createNode(data);

    newNode->next = node; // current node comes after new node

    // if current node is the head
    if(node->prev == NULL){
        list->head = newNode; // New node becomes head
    }
    else{
        // otherwise new node comes after previous node
        newNode->prev = node->prev;
        node->prev->next = newNode;
    }

    node->prev = newNode; // new node comes before new node
}

void insertAfter(LinkedList* list, Node* node, char* data){
    // Creates new node with data
    Node* newNode = createNode(data);

    newNode->prev = node; // Current node comes before new node

    // If current node is tail
    if(node->next == NULL){
        list->tail = newNode; // New node becomes tail
    }
    else{
        // Otherwise new node comes after previous node
        newNode->next = node->next;
        node->next->prev = newNode;
    }

    node->next = newNode; // New node comes after current node
}

void insertHead(LinkedList* list, char* data){
    // If the list is empty
    if(list->head == NULL){
        // Creates new node with data
        Node* newNode = createNode(data);
        // Sets head and tail to new node
        list->head = newNode;
        list->tail == newNode;
    }
    else{
        insertBefore(list, list->head, data); // Otherwise insert before new head
    }
}

void insertTail(LinkedList* list, char* data){
    // If the list is empty
    if(list->tail == NULL){
        insertHead(list, data);
    }
    else{
        insertAfter(list, list->tail, data);
    }
}

void removeNode(LinkedList* list, Node* node){
    if(node->prev == NULL){
        list->head = node->next;
    }
    else{
        node->prev->next = node->next;
    }
    if(node->next == NULL){
        list->tail = node->prev;
    }
    else{
        node->next->prev = node->prev;
    }

    free(node);
}

// Main
int main(){
    LinkedList* a = createList();

    printList(a);

    char* b = "Hello";
    insertHead(a,b);

    printList(a);

    insertHead(a,"Fuck");

    printList(a);

    return 0;
}