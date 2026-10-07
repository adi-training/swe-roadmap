#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <utility>

template <typename T>
class CustomLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node() : data(T()), prev(nullptr), next(nullptr) {}
        explicit Node(const T& val, Node* p = nullptr, Node* n = nullptr)
            : data(val), prev(p), next(n) {}
    };

    Node* dummyHead;
    Node* dummyTail;
    size_t size;

    void init() {
        dummyHead = new Node();
        dummyTail = new Node();
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
        size = 0;
    }

public:
    // Iterator Class
    class Iterator {
    private:
        Node* current;
        friend class CustomLinkedList;

    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

        explicit Iterator(Node* ptr = nullptr) : current(ptr) {}

        reference operator*() const { return current->data; }
        pointer operator->() const { return &(current->data); }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            current = current->next;
            return temp;
        }

        Iterator& operator--() {
            current = current->prev;
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            current = current->prev;
            return temp;
        }

        bool operator==(const Iterator& other) const { return current == other.current; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    // Constructor
    CustomLinkedList() { init(); }

    // Initializer List Constructor
    CustomLinkedList(std::initializer_list<T> initList) {
        init();
        for (const auto& item : initList) {
            push_back(item);
        }
    }

    // Destructor
    ~CustomLinkedList() {
        clear();
        delete dummyHead;
        delete dummyTail;
    }

    // Copy Constructor
    CustomLinkedList(const CustomLinkedList& other) {
        init();
        for (Node* curr = other.dummyHead->next; curr != other.dummyTail; curr = curr->next) {
            push_back(curr->data);
        }
    }

    // Copy Assignment (Copy-and-Swap)
    CustomLinkedList& operator=(CustomLinkedList other) {
        swap(*this, other);
        return *this;
    }

    // Move Constructor
    CustomLinkedList(CustomLinkedList&& other) noexcept
        : dummyHead(other.dummyHead), dummyTail(other.dummyTail), size(other.size) {
        other.dummyHead = nullptr;
        other.dummyTail = nullptr;
        other.size = 0;
    }

    // Friend Swap
    friend void swap(CustomLinkedList& first, CustomLinkedList& second) noexcept {
        using std::swap;
        swap(first.dummyHead, second.dummyHead);
        swap(first.dummyTail, second.dummyTail);
        swap(first.size, second.size);
    }

    // Core Member Functions
    size_t getSize() const { return size; }
    bool isEmpty() const { return size == 0; }

    void push_front(const T& value) {
        Node* firstReal = dummyHead->next;
        Node* newNode = new Node(value, dummyHead, firstReal);
        dummyHead->next = newNode;
        firstReal->prev = newNode;
        size++;
    }

    void push_back(const T& value) {
        Node* lastReal = dummyTail->prev;
        Node* newNode = new Node(value, lastReal, dummyTail);
        lastReal->next = newNode;
        dummyTail->prev = newNode;
        size++;
    }

    void pop_front() {
        if (isEmpty()) throw std::underflow_error("Cannot pop from empty list");
        Node* nodeToDelete = dummyHead->next;
        Node* newFirst = nodeToDelete->next;
        dummyHead->next = newFirst;
        newFirst->prev = dummyHead;
        delete nodeToDelete;
        size--;
    }

    void pop_back() {
        if (isEmpty()) throw std::underflow_error("Cannot pop from empty list");
        Node* nodeToDelete = dummyTail->prev;
        Node* newLast = nodeToDelete->prev;
        newLast->next = dummyTail;
        dummyTail->prev = newLast;
        delete nodeToDelete;
        size--;
    }

    T& front() {
        if (isEmpty()) throw std::underflow_error("List is empty");
        return dummyHead->next->data;
    }

    T& back() {
        if (isEmpty()) throw std::underflow_error("List is empty");
        return dummyTail->prev->data;
    }

    void clear() {
        Node* curr = dummyHead->next;
        while (curr != dummyTail) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
        size = 0;
    }

    Iterator begin() const { return Iterator(dummyHead->next); }
    Iterator end() const { return Iterator(dummyTail); }
};