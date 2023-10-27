/*
 * Legolas Tyrael B. Lada
 * CMSC 122 PE 03 Stack Linked List Implementation
 * 2022-04734
 *
 * This program utilizes a linked list to create a Stack Data Structure.
 */
#include <iostream>
#include <iomanip>
/*
 * I will be using smart pointers for memory safety instead of
 * manually freeing nodes.
 */
#include <memory>

#define sp shared_ptr // shorthand macro
using std::sp, std::cout, std::cin, std::setw, std::string;

typedef string Dish;

enum MENU {
    EXIT, ADD, POP, TOP, CLEAR
};

template <typename T>
class Node {
private:
    T data;
    sp<Node<T>> next = nullptr;

public:
    // constructor setting data to x
    Node(T x) : data(x) {}

    T getData() { return data; }

    void setNext(sp<Node<T>> &n) { next = n; }

    sp<Node<T>> getNext() { return next; }
};

template <typename T>
class Stack {
private:
    sp<Node<T>> head = nullptr;
    size_t size = 0;

public:
    Stack() {}
    Stack(sp<Node<T>> &h) : head(h) {} // constructor setting head to h

    bool empty() { return size == 0; }

    size_t getSize() { return size; }

    Stack &push(T new_var) {
        /*
         * adds a new element to the top of the stack
         *
         * @param new_var the element to be put at the top of the stack
         * @return a reference to the Stack object that called it
         */

        Node<T> newNode(new_var); // creates temporary node
        sp<Node<T>> temp = std::make_shared<Node<T>>(newNode);

        if (size++ != 0)
            temp->setNext(head);
        head = temp;

        return *this; // for method chaining
    }

    T peek() {
        /*
         * returns the top element of the stack without removing it, 0 on invalid peek
         *
         * @return the element at the top of the stack
         */
        return head->getData();
    }

    T pop() {
        /*
         * removes the top element of the stack and returns it, 0 on invalid pop
         *
         * @return the element removed from the top of the stack
         */

        if (size == 0) { // edgecase
            return " ";
        }

        T retval = head->getData(); // keep track of popped value
        head = head->getNext();     // move pointer forward
                                    // shared_ptr frees itself when no longer referred to
        size--;
        return retval;
    }

    void display() {
        sp<Node<T>> temp = head;
        int i = size;

        if (i == 0) { // empty stack edgecase
            cout << "\nEMPTY STACK\n";
            return;
        }

        cout << "\nValue          : |";
        while (temp != nullptr) {
            cout << setw(3) << temp->getData() << " |";
            temp = temp->getNext(); // traversal
        }

        cout << "\n\nStack Position : |";
        while (i--) {
            cout << setw(3) << i + 1 << " |";
        }
    }

    void clear() {
        /*
         * clears the stack by removing the reference to the head, cascading and freeing every
         * other node.
         */
        head = nullptr;
        size = 0;
    }
};

int menu(void); // abstracted menu

// abstracted choices
void choiceAdd  (Stack<Dish>& st);
void choicePop  (Stack<Dish>& st);
void choicePeek (Stack<Dish>& st);
void choiceClear(Stack<Dish>& st);

int main(void) {
    Stack<Dish> st; // stack object to be manipulated
    int flag = 1;

    while (flag) {
        switch (menu()) {
            case ADD:
                choiceAdd(st);
                break;
            case POP:
                choicePop(st);
                break;
            case TOP:
                choicePeek(st);
                break;
            case CLEAR:
                choiceClear(st);
                break;
            case EXIT:
                cout << "\nWashing machine process has been terminated.\n";
                flag = EXIT;
        }
    }
}

int menu(void) {
    int choice;
    cout << "\n\nKitchenware Washing Machine\n\n"
            " [1] Add kitchenware\n"
            " [2] Wash kitchenware\n"
            " [3] Top kitchenware\n"
            " [4] Wash all\n"
            " [0] Exit\n\n"
            "Enter choice: ";
    cin >> choice;
    cout << "\n";
    return choice;
}

void choiceAdd(Stack<Dish>& st) {
    /* 
     * Abstracted menu for pushing an item to the stack
     *
     * @param st the stack to be pushed onto
     */

    Dish kitchenware; 
    cout << "\nInput kitchenware to be added: \n";
    cin >> kitchenware;

    st.push(kitchenware);
}

void choicePop(Stack<Dish> &st) {
    /* 
     * Abstracted menu for popping an item from the stack
     *
     * @param st the stack to be popped from
     */

    cout << "\n";
    if (st.empty()) {       // edgecase
        cout << "The STACK is EMPTY. No more kitchenware to wash.\n";
        return;
    }

    cout << st.pop() << " is being washed.\n";
}

void choicePeek(Stack<Dish> &st) {
    /* 
     * Abstracted menu for peeking the top item of the stack
     *
     * @param st stack to be peeked from
     */

    cout << "\n";
    if (st.empty()) {       // edgecase
        cout << "The STACK is EMPTY. No more kitchenware to wash.\n";
        return;
    }

    cout << st.peek() << " is next to be washed\n";
}

void choiceClear(Stack<Dish> &st) {
    /* 
     * Abstracted menu for clearing the entire stack
     *
     * @param st stack to be cleared
     */

    cout << "\n";
    if (st.empty()) {       // edgecase
        cout << "The STACK is EMPTY. No more kitchenware to wash.\n";
        return;
    }

    /* cant use st.clear() because of specifications */
    while (!st.empty()) {
        cout << st.pop() << " is being washed.\n";
    }
    cout << "\n All kitchenware have been washed.\n";
}