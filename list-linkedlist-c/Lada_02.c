/* 
 * Legolas Tyrael B. Lada
 * CMSC 122 PE 02 List Implementation (Linked List)
 * 2022-04734
 * 
 * Linked list implementation of list.
 */
#include <stdio.h>
#include <stdlib.h>

enum MENU_CHOICE {
    ADD = 1,
    DELETE, DISPLAY, CLEAR
};
enum ADD_CHOICE {
    START=1,
    END, SPECIFIC
};

typedef struct Node Node;
typedef struct Node{
    int data;
    Node* next; 
} Node;

typedef struct {
    Node* head;
    Node* tail;
    size_t size;
} LinkedList;

// creates a node with x as value and NULL as next
Node* createNode(int x);

// inserts x to position pos
void insert(LinkedList* ll, size_t pos, int x);

// searches and removes element x from list if found.
void delete(LinkedList* ll, int x);

// abstracted add and delete choices
void choice_add(LinkedList* ll);
void choice_del(LinkedList* ll);

// displays list
void choice_dsp(LinkedList* ll);

// clears list
void choice_clr(LinkedList* ll);

// takes care of all dangling pointers
void recursive_free(Node* n);

int main(void){
    LinkedList ll = {NULL, NULL, 0};
    int choice; 
    do {
        printf("\nList MENU\n\n"
               " [1] Add Item\n"
               " [2] Delete Item\n"
               " [3] Display List\n"
               " [4] Delete List\n"
               " [0] Exit Program\n\n"
               "Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case ADD:
                choice_add(&ll);
                break;
            case DELETE:
                choice_del(&ll);
                break;
            case DISPLAY:
                choice_dsp(&ll);
                break;
            case CLEAR:
                choice_clr(&ll);
                break;
        }

    }while (choice);    // loop infinitely until choice is 0

    return 0;
}

Node* createNode(int x){
    /* 
     * creates a node with x as value and NULL as next 
     *
     * @param x data for new node
     * @return pointer to created node
     */
    Node* newNode = (Node*) malloc (sizeof (*newNode));
    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

// abstracted add choice
void choice_add(LinkedList* ll) {
    int choice, x, pos;
    printf("\nPlease enter the item to be added: ");
    scanf("%d", &x);

    printf("\n\nWhere to add the item?\n"
           " [1] Start of the list\n"
           " [2] End of the list\n"
           " [3] Specific position\n"
           " [0] Cancel\n\n"
           "Enter choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice) {
        case START:
            insert(ll, 0, x);
            break;
        case END:
            insert(ll, ll->size, x);
            break;
        case SPECIFIC:
            printf("\nEnter position: ");
            scanf("%d",&pos);
            printf("\n");
            pos = (pos >= 1 && pos <= ll->size) ? pos : ll->size+1;    // bounds check
            insert(ll, pos-1, x);
            break;
    }
}

void insert(LinkedList *ll, size_t pos, int x) {
    /* 
     * inserts x to position pos
     * 
     * @param ll the list to be mutated
     * @param pos the position to be inserted in
     * @param x the element to be inserted
     */

    if (pos > ll->size)    // catch edgecase
        pos = ll->size;

    ll->size++;

    if (pos == 0) {                         // constant time head swap
        Node* newHead = createNode(x);
        newHead->next = ll->head; 
        ll->head = newHead;

        if (ll->tail == NULL) {             // first tail
            ll->tail = ll->head;
        }
        return;
    } else if (pos == ll->size) {           // constant time tail swap
        ll->tail->next = createNode(x);
        ll->tail = ll->tail->next;
        return;
    }

    Node* newNode = createNode(x);
    Node* temp = ll->head;
    for (int i = 0; i < pos-1; i++) {
        temp = temp->next;              // linked list traversal
    }

    newNode->next = temp->next;         // linked list insertion algo
    temp->next = newNode;
}

// abstracted delete choice
void choice_del(LinkedList* ll){
    if (ll->size == 0) {                    // empty list edge case
        printf("\nThe list is empty!\n");
        return;
    }

    int x;
    printf("\nWhat item to delete: ");
    scanf("%d", &x);
    printf("\n");
    delete(ll, x);
}

void delete(LinkedList* ll, int x) {
    /* 
     * searches and removes element x from list if found.
     *
     * @param ll list to be mutated
     * @param x item to search for and delete
     */

    int counter = 2;        // position to be printed
    Node* p = ll->head;     // pointer to current

    if (p->data == x) {                                 // position 1 edge case
        ll->head = ll->head->next;
        ll->size--;
        free(p);
        printf("\nThe element %d, which was at position %d, has been deleted.\n", x, 1);
        return;
    }

    while (p->next != NULL && p->next->data != x) {     // stop at index before element
        p = p->next;                                    // linked list traversal
        counter++;
    }

    if (p->next == NULL) {                              // not found edge case
        printf("\nThe list contains no such element.\n");
        return;
    }

    ll->size--;
    Node* removed = p->next;                            // naming pointer to freed to avoid dangling pointer
    p->next = p->next->next;
    free(removed);

    printf("\nThe element %d, which was at position %d, has been deleted.\n", x, counter);
}

void choice_dsp(LinkedList* ll){
    /* 
     * displays list
     *
     * @param ll list to be displayed
     */

    Node* curr_node = ll->head;

    while (curr_node) {
        printf(" %3d |", curr_node->data);
        curr_node = curr_node->next;        // linked list traversal
    }
    printf("\n");

    // formatting
    for (int i = 1; i <= ll->size; i++) {
        printf("-----+");
    }
    printf("\n");
    for (int i = 1; i <= ll->size; i++) {
        printf(" %3d |", i);
    }
    printf("\n");
}

void choice_clr(LinkedList* ll) {
    /* 
     * clears list
     *
     * @param ll the list to be cleared
     */

    recursive_free(ll->head);                   // free all dynamically allocated nodes
    ll->tail = ll->head = NULL;
    ll->size = 0;
    printf("\nThe list has been emptied!\n");
}

void recursive_free(Node* n) {
    /* 
     * takes care of all dangling pointers
     *
     * @param n current node to free
     */

    if (n == NULL) return;    // base case

    recursive_free(n->next);
    free(n);
}

