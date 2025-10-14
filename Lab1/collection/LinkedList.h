#ifndef LAB1_LINKEDLIST_H
#define LAB1_LINKEDLIST_H
#include <iostream>


class LinkedList {
    struct  Node {
        int v;
        Node* next;

        Node(int value) : v(value){}
    };

    Node* head;
    int s;

public:
    LinkedList() :  head(nullptr), s(0){}
    ~LinkedList() {
        Node* curr = head;
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }

    void push_front(int val) {
        Node* new_node = new Node(val);
        if (s == 0) {
            head = new_node;
        }else {
            new_node->next = head;
            head = new_node;
        }
        s++;
    }

    void push_back(int val) {
        Node* new_node = new Node(val);
        if (s == 0) {
            head = new_node;
        }

        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new_node;
        s++;
    }

    void print() const {
        Node* curr = head;
        while (curr) {
            std::cout << curr->v << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    void pop_back() {
        if (s == 0) {
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }else {
            Node* curr = head;
            while (curr->next->next != nullptr) {
                curr = curr->next;
            }
            delete curr->next;
            curr->next = nullptr;
        }
        s--;
    }

    bool isEmpty() {
        if (s != 0) {
            return true;
        }
        return false;
    }

    int size() {
        return s;
    }
};


#endif //LAB1_LINKEDLIST_H
