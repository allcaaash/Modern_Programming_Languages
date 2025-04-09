#include <iostream>

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    ForwardList() : head(nullptr), tail(nullptr) {}

    void push_back(const T& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(const T& key) {
        if (!head) return false;

        Node* current = head;
        Node* prev = nullptr;

        // —равниваем данные через оператор !=
        if (!(current->data != key)) {  // Ёквивалентно current->data == key
            head = current->next;
            if (tail == current) tail = nullptr;
            delete current;
            return true;
        }

        while (current && (current->data != key)) {
            prev = current;
            current = current->next;
        }

        if (!current) return false;

        prev->next = current->next;
        if (current == tail) tail = prev;
        delete current;
        return true;
    }

    T* findData(const T& key) {
        Node* current = head;
        while (current) {
            if (current->data == key) return &(current->data);
            current = current->next;
        }
        return nullptr;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~ForwardList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};