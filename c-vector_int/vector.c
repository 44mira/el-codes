
#include "vector.h"

vec_int* Vec_int_new() {
    /* 
     * vec constructor
     *
     * @return pointer to constructed vector with size 0, max_size 1
     */
    vec_int* r = (vec_int*) malloc (sizeof *r);

    // initialization
    r->size = 0;
    r->max_size = 1;
    r->get = (int *) malloc(sizeof r->get);

    return r;
}

void swap(int* a, int* b) {
    /*  
     * swaps the values at two int pointers
     *
     * @param a value a
     * @param b value b
     */

    int temp = *a;
    *a = *b;
    *b = temp;
}

short empty(const vec_int* v) {
    /*
     * returns size == 0
     *
     * @return the rest of size == 0
     */

    return (v->size == 0);
}

void resize(vec_int* v, size_t s) {
    /* 
     * manually alter max_size TO s, losing data when shrunk.
     *
     * @param v vector to be mutated
     * @param s size to change to
     */

    v->max_size = s;
    v->get = (int *) realloc (v->get, v->max_size * sizeof (v->get));
}

void incr_max_size(vec_int* v, size_t n) {
    /* 
     * increments vector max_size by a factor of n
     *
     * @param v vector to be mutated
     * @param v factor to resize with
     */

    resize(v, v->max_size*n);
}

void push_back(vec_int* v, int n) {
    /*
     * appends an element to the vector, doubles size if over max_size
     *
     * @param v pointer to the vector to be mutated
     * @param n element to be appended
     */

    // double max_size whenever needed
    if (v->size + 1 > v->max_size) {
        incr_max_size(v, 2);
    }
    *(v->get + v->size++) = n;
}

int pop_back(vec_int* v) {
    /*
     * removes the last element of the vector, returning it.
     * 
     * @param v pointer to the vector to be mutated
     * @return the value removed
     */

    if (v->size <= 0) exit(1);  // exit on invalid pop

    return *(v->get + v->size--);
}

void del(vec_int* v) {
    /*
     * destroys the vector, freeing the memory
     *
     * @param v the vector to be destroyed
     */

    free(v->get);       // free abstracted array first to avoid dangling pointer
    free(v);
}

void iota(vec_int* v, int start, int end) {
    /*
     * generate an increasing range of numbers
     *
     * @param v vector to be mutated
     * @param start starting value of range, inclusive
     * @param end ending value of range, exclusive
     */

    v->size = 0;
    v->max_size = end - start;
    resize(v, v->max_size);     // update max_size
    
    while (start < end) {
        *(v->get + v->size++) = start++;
    }
}

long long find(const vec_int* v, int t) {
    /*
     * find index of first occurrence of an element in vector, -1 if not found
     * 
     * @param v vector to be searched
     * @param t value to be searched for
     * @return index of found element, -1 if not found
     */

    for (int i = 0; i < v->size; i++) {
        if (*(v->get + i) == t) return i;
    }

    return -1;
}

void reverse(vec_int *v) {
    /*
     * in-place reversal of vector
     * 
     * @param v vector to be mutated
     */
    int temp;

    // swap elements from both ends along and until the median
    for (int i = 0; i <= v->size / 2; i++) {    
        swap((v->get + v->size - i - 1), (v->get + i));
    }
}

void sort(vec_int* v) {
    /*
     * in-place ascending O(n log n) sort
     * 
     * @param v vector to be mutated
     */

    quicksort(v, 0, v->size - 1);
}

void quicksort(vec_int* v, int l, int r) {
    /*  
     * abstracted sort algorithm for sort()
     *
     * @param v vector to be mutated
     * @param l left bound of subvector, inclusive
     * @param r right bound of subvector, inclusive
     */
    
    if (l < r) {                            // recurse until invalid bounds
        int pivot = partition(v, l, r);

        quicksort(v, l, pivot - 1);
        quicksort(v, pivot + 1, r);
    }
}

int partition(vec_int* v, int l, int r) {
    /* 
     * helper function for quicksort()
     *
     * @param v vector to be mutated
     * @param l left bound of subvector
     * @param r right bound of subvector
     * @return pivot
     */

    int pt = l - 1;                     // current idx
    int temp, pivot = v->get[r];

    for (int i = l; i <= r; i++) {      // swap values whenever less than or equal to pivot
        if (v->get[i] <= pivot) {
            pt++;
            swap((v->get + pt), (v->get + i));
        }
    }
    pt++;
    swap((v->get + r), (v->get + pt));  // place pivot in sorted location
    return pt;
}

void reserve(vec_int* v, size_t s) {
    /*  
     * manually increase max_size by s, reserving additional memory
     *
     * @param v vector to be mutated
     * @param s size of additional memory
     */

    resize(v, v->max_size + s);
}

void shrink_to_fit(vec_int* v) {
    /*
     * calls resize() on v with current size as s
     *
     * @param v vector to be mutated
     */
    
    resize(v, v->size);
}

void clear(vec_int* v) {
    /* 
     * removes all the elements in a vector, maintaining current max_size
     * 
     * @param v vector to be mutated
     */

    v->size = 0;
}

void erase(vec_int* v, size_t i) {
    /* 
     * removes element at i, shifting elements back. does not do anything when i > size
     *
     * @param v vector to be mutated
     * @param i index of element to be removed
     */ 

    if (i > v->size) return;    // do not do anything if invalid index;
    v->size--;                  

    int *p = v->get;
    int j = 0;

    while (j < i) {             // point to index i
        j++;
        p++;
    }

    // shift back all elements after p by 1 index, iterates size-1 times
    while (j++ < v->size) {       
        *p = *(p+1);
        p++;
    }
}

void insert(vec_int* v, int n, size_t i) {
    /*
     * inserts n at i, shifting elements forward. does not do anything when i > size 
     *
     * @param v vector to be mutated
     * @param n element to be inserted
     * @param i index to be inserted at
     */

    if (i > v->size)                        // do not do anything if invalid index;
        return;                    
    else if (v->size + 1 > v->max_size)     // increase max_size if insufficient
        incr_max_size(v, 2);

    int *p = v->get;
    int temp, j = 0;            // temp is used for swapping

    while (j < i) {             // point to index i
        j++;
        p++;
    }

    while (j < v->size) {       // iteratively insert and swap
        swap(p, &n);
        p++;
        j++;
    }
}