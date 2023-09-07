# C vector<int> implementation

I did this because I really wanted to code *SOMETHING* in C. 

Overall, this little side-project : 
- helped me to practice applying good coding principles such as proper docstrings and composition of functions from the functional programming paradigm.
- acquainted me even better with C (and pointers)
- made me try to think of how vector<int> is implemented
- experience trying to implement an interface without OOP
- most importantly, *made me write code.*

## FUNCTION SIGNATURES IN vector.h

```c
// vec constructor
vec_int* Vec_int_new();

// swaps the values at two int pointers
void swap(int* a, int* b);

// returns size == 0
short empty(const vec_int* v);

// manually alter max_size TO s, losing data when shrunk.
void resize(vec_int* v, size_t s);

// increments vector max_size by a factor of n
void incr_max_size(vec_int* v, size_t n);

// appends an element to the vector, doubles size if over max_size
void push_back(vec_int* v, int n); 

// removes the last element of the vector, returning it.
int pop_back(vec_int* v);

// destroys the vector, freeing the memory
void del(vec_int* v);

// generate an increasing range of numbers
void iota(vec_int* v, int start, int end);

// find index of first occurrence of an element in vector, -1 if not found
long long find(const vec_int* v, int t);

// in-place O(n) reversal of vector
void reverse(vec_int* v);

// in-place ascending O(n log n) sort
void sort(vec_int* v);

// abstracted sort algorithm for sort()
void quicksort(vec_int* v, int l, int r);

// helper function for quicksort()
int partition(vec_int* v, int l, int r);

// manually increase max_size by s, reserving additional memory
void reserve(vec_int* v, size_t s);

// calls resize() on v with current size as s
void shrink_to_fit(vec_int* v);

// removes all the elements in a vector, maintaining current max_size
void clear(vec_int* v);

// removes element at i, shifting elements back. does not do anything when i > size
void erase(vec_int* v, size_t i);

// inserts n at i, shifting elements forward. does not do anything when i > size
void insert(vec_int* v, int n, size_t i);
```
