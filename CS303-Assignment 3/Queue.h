#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

using namespace std;

template <typename T>
class Queue {
public:
    Queue() : head(nullptr), tail(nullptr), count(0) {}  // Constructor initializes empty queue

    ~Queue() {  // Destructor
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T element) {  // Adds an element to the end of the queue
        Node* newNode = new Node{ element, nullptr };  // Create a new node
        if (isEmpty()) {  // If the queue is empty, both head and tail point to the new node
            head = tail = newNode;
        }
        else {  // If not empty, add the new node to the end and update tail
            tail->next = newNode;
            tail = newNode;
        }
        count++;  // Increment the number of elements
    }

    T dequeue() {  // Removes an element from the front of the queue
        if (isEmpty()) {
            throw out_of_range("Queue is empty");  // Throw exception if queue is empty
        }
        Node* temp = head;  // Temporary pointer to the head node
        T data = head->data;  // Store data to return
        head = head->next;  // Move head to the next node
        if (!head) {  // If head becomes nullptr, set tail to nullptr as well
            tail = nullptr;
        }
        delete temp;  // Free the memory of the dequeued node
        count--;  // Decrement the count
        return data;  // Return the dequeued element
    }

    T front() const {  // Returns the element at the front without removing it
        if (isEmpty()) {
            throw out_of_range("Queue is empty");  // Throw exception if queue is empty
        }
        return head->data;  // Return the front element
    }

    bool isEmpty() const {  // Checks if the queue is empty
        return count == 0;
    }

    int size() const {  // Returns the number of elements in the queue
        return count;
    }

private:
    struct Node {  // Inner node structure for queue elements
        T data;  // Data of the node
        Node* next;  // Pointer to the next node
    };

    Node* head;  // Pointer to the front of the queue
    Node* tail;  // Pointer to the end of the queue
    int count;   // Count of elements in the queue
};

#endif
