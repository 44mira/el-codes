
#include <stdio.h>

#define MAX_SIZE 10

/* 
 * list struct
 *
 * @attr arr[10] array under the hood
 * @attr end index of last element
 */
typedef struct {
    int arr[10];
    int size;
} list;

// swaps two integers
void swap(int* a, int* b);

// inserts an element into the list, shifting elements to the right when needed
void insert(list* ns, int pos, int x);

// removes an element from the list, shifting elements to the left when needed
void delete(list* ns, int x);

// abstracted menu choices
void choice_add(list* ns);
void choice_del(list* ns);

// clears the contents of the list
void choice_clr(list* ns);

// displays contents of the list
void choice_dsp(list* ns);

int main(void) {
    int choice;
    list nums;
    nums.size = 0;

    do {
        printf("List MENU\n\n"
               " [1] Add Item\n"
               " [2] Delete Item\n"
               " [3] Display List\n"
               " [4] Delete List\n"
               " [0] Exit Program\n\n"
               " Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                choice_add(&nums);
                break;
            case 2:
                choice_del(&nums);
                break;
            case 3:
                choice_dsp(&nums);
                break;
            case 4:
                choice_clr(&nums);
        }
    } while (choice);           // loops infinitely until choice is 0
    
    return 0;
}

void swap(int* a, int* b){
    /* 
     * swaps two integers
     * 
     * @param a first integer to be swapped
     * @param b second integer to be swapped
     */

    int temp = *a;
    *a = *b;
    *b = temp;
}

void choice_add(list* ns) {
    if (ns->size+1 > MAX_SIZE) {         // edge case
        printf("\nThe list is full!\n");
        return;
    }

    int temp, idx;

    printf("\nPlease enter the item to be added: ");
    scanf("%d",&temp);

    printf("\n\nWhere to add the item?\n"
           " [1] Start of the list\n"
           " [2] End of the list\n"
           " [3] Specific position\n"
           " [0] Cancel\n\n"
           " Enter choice: ");
    scanf("%d",&idx);
    printf("\n");

    switch (idx) {
        case 1:
            insert(ns, 0, temp);
            break;
        case 2:
            insert(ns, ns->size, temp);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &idx);
            printf("\n");
            idx = (idx > ns->size+1 || idx < 1) ? ns->size+1 : idx;     // invalid position defaulting to current end
            insert(ns, idx-1, temp);                                    // idx-1 to return to 0-indexed format 
            break;
        default:
            return;
    }
}

void insert(list* ns, int pos, int x) {
    /*  
     * inserts an element into the list, shifting elements to the right when needed
     *
     * @param ns pointer to list struct to be mutated
     * @param pos position to insert to
     * @param x element to be inserted
     */

    /* 
     * edge case already checked in abstracted input, no longer have to check here
     * pos is already 0-indexed
     */

    int hold = x;
    int* curr = ns->arr + pos;   // current pointer
    ns->size++;

    while (curr - ns->arr < ns->size) {     // pointer arithmetic to determine out of bounds
        swap(&hold, curr++);                 
    }
}

void choice_del(list* ns) {
    if (ns->size == 0) {                    // edge case
        printf("\nThe list is empty!\n");
        return;
    }

    int temp;

    printf("\nPlease enter the item to be removed: ");
    scanf("%d", &temp);

    delete(ns, temp);
}

void delete(list* ns, int x) {
    /* 
     * removes an element from the list, shifting elements to the left when needed
     *
     * @param ns list to be mutated
     * @param x element to be removed
     */

    int* p = ns->arr;

    while (p - ns->arr < ns->size && *p != x) {     // linear search using pointer arithmetic, exits on out of bounds
        p++;
    }
    
    if (p - ns->arr == ns->size && *p != x) {       // on not found
        printf("\nThe list contains no such element.\n");
        return;
    }

    ns->size--;

    while (p - ns->arr < ns->size) {                // left shifting from found pointer
        *p = *(p+1);
        p++;
    }
}

void choice_dsp(list* ns) {
    /* 
     * displays the contents of the list
     *
     * @param ns list to be printed
     */
    for (int i = 0; i<ns->size; i++) {
        printf("%3d ", ns->arr[i]);
    }
    printf("\n--- --- --- --- --- --- --- --- --- ---\n");
    for (int i = 1; i<=ns->size; i++) {
        printf("%3d ", i);
    }
    printf("\n\n");
}

void choice_clr(list* ns){
    /* 
     * clears the contents of the list
     *
     * @param ns list to be cleared
     */

    printf("\nThe list has been emptied!\n");
    ns->size = 0;           // resetting size to 0 "deletes" all of the elements in the list.
}