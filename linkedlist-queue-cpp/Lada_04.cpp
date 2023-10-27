/*  
 * Legolas Tyrael B. Lada | 2-BSCS
 * 2022-04734
 * 
 * Implementing a Queue ADT using linked list, and use it for
 * dealing with simulated restaurant orders
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <memory>
#include <utility>

using namespace std;
#define ptr shared_ptr
typedef pair<string,string> Order;

enum Choice { EXIT, ENQUEUE, DEQUEUE, FRONT, CLEAR };

// --- Implementation

struct Node {
    Order order;
    ptr<Node> next = nullptr;

    Node(Order a) : order(a) {}         // constructor
};

class Queue {
private: 
    size_t size     = 0;
    ptr<Node> head = nullptr;
    ptr<Node> tail = nullptr;

public:
    // returns a pointer to an empty queue
    static Queue* INIT(){ return new Queue; }   

    bool EMPTY() { return size == 0; }

    // returns the head of the queue, will seg-fault on empty queue
    auto FRONT() { return head->order; }

    /* 
     * enqueues to the tail of the queue
     *
     * @param newOrder the order to be added to the tail of the queue
     */
    void ENQUEUE(Order newOrder) {
        ptr<Node> p = make_shared<Node>(newOrder);

        if (!size++)  tail = head = p;
        else          tail = tail->next = p;
    }

    /* 
     * dequeues the head of queue and returns the value,
     * (will seg-fault on empty queue)
     *
     * @return the value dequeued
     */
    Order DEQUEUE() {
        Order ret = head->order;
        head = head->next;
        --size;
        return ret;
    }
};

// --- Application

int menu(); 
void restoDequ(Queue* q);
void choiceEnq(Queue* q);
void choiceDeq(Queue* q);
void choiceTop(Queue* q);
void choiceClr(Queue* q);

int main(void) {
    Queue* jolibe = Queue::INIT();
    int choice;

    system("cls||clear");
    while (choice = menu()) {
        system("cls||clear");
        switch (choice) {
            case ENQUEUE:
                choiceEnq(jolibe);
                break;
            case DEQUEUE:
                choiceDeq(jolibe);
                break;
            case FRONT:
                choiceTop(jolibe);
                break;
            case CLEAR:
                choiceClr(jolibe);
                break;
        }
    }
    system("cls||clear");
    cout << "\nThe order system has been terminated.\n\nGoodbye.";
    
    return 0;
}

int menu() {
    int choice;
    cout << "\nJolibe Menu:\n\n"
            "\t[1] Fall in line\n"
            "\t[2] Serve order\n"
            "\t[3] Next order\n"
            "\t[4] Closing time\n"
            "\t[0] Exit\n\n"
            "Enter choice: ";
    cin >> choice;
    return choice;
}

// dequeue formatting
void restoDequ(Queue* q) {
    Order o = q->DEQUEUE();
    cout << "Now serving " << o.second << " to customer " << o.first << ".\n\n";
}

// abstracted enqueue choice
void choiceEnq(Queue* q) {
    string name, order;
    cin.ignore(10,'\n');
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "\nEnter your order: ";
    getline(cin, order);
    q->ENQUEUE(make_pair(name,order));

    system("cls||clear");
    cout << "Order placed successfully!\n\n";
}

// abstracted dequeue choice
void choiceDeq(Queue* q) {
    // edge case
    if (q->EMPTY()) {          
        cout << "The QUEUE is EMPTY. No orders to serve.\n\n";
        return;
    }
    restoDequ(q);
}

// abstracted front choice
void choiceTop(Queue* q) {
    // edge case
    if (q->EMPTY()) {
        cout << "The QUEUE is EMPTY. No order to serve.\n\n";
        return;
    }
    Order o = q->FRONT();
    cout << "Next order: " << o.second << " of customer " << o.first << ".\n\n";
}

// abstracted clear choice
void choiceClr(Queue* q) {
    if (q->EMPTY()) {
        cout << "The QUEUE is EMPTY. No order to serve.\n\n";
        return;
    }

    while (!q->EMPTY()) restoDequ(q);
    cout << "\nAll orders have been served.\n\n";
}