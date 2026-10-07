#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <utility>

template <typename T>
class CustomDeque {
private:
    T* buffer;
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity) {
        T* newBuffer = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newBuffer[i] = buffer[(head + i) % capacity];
        }
        delete[] buffer;
        buffer = newBuffer;
        head = 0;
        tail = size;
        capacity = newCapacity;
    }

public:
    explicit CustomDeque(size_t initialCapacity = 4)
        : head(0), tail(0), size(0), capacity(initialCapacity) {
        buffer = new T[capacity];
    }

    CustomDeque(std::initializer_list<T> initList)
        : head(0), tail(0), size(0), capacity(initList.size() > 4 ? initList.size() * 2 : 4) {
        buffer = new T[capacity];
        for (const auto& item : initList) {
            push_back(item);
        }
    }

    ~CustomDeque() {
        delete[] buffer;
    }

    // Copy Constructor
    CustomDeque(const CustomDeque& other)
        : head(0), tail(other.size), size(other.size), capacity(other.capacity) {
        buffer = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            buffer[i] = other.buffer[(other.head + i) % other.capacity];
        }
    }

    // Copy Assignment Operator (Copy-and-Swap)
    CustomDeque& operator=(CustomDeque other) {
        swap(*this, other);
        return *this;
    }

    // Move Constructor
    CustomDeque(CustomDeque&& other) noexcept
        : buffer(other.buffer), head(other.head), tail(other.tail), size(other.size), capacity(other.capacity) {
        other.buffer = nullptr;
        other.head = 0;
        other.tail = 0;
        other.size = 0;
        other.capacity = 0;
    }

    friend void swap(CustomDeque& first, CustomDeque& second) noexcept {
        using std::swap;
        swap(first.buffer, second.buffer);
        swap(first.head, second.head);
        swap(first.tail, second.tail);
        swap(first.size, second.size);
        swap(first.capacity, second.capacity);
    }

    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    bool isEmpty() const { return size == 0; }

    void push_back(const T& value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        buffer[tail] = value;
        tail = (tail + 1) % capacity;
        size++;
    }

    void push_front(const T& value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        head = (head == 0) ? capacity - 1 : head - 1;
        buffer[head] = value;
        size++;
    }

    void pop_back() {
        if (isEmpty()) throw std::underflow_error("Deque is empty");
        tail = (tail == 0) ? capacity - 1 : tail - 1;
        size--;
    }

    void pop_front() {
        if (isEmpty()) throw std::underflow_error("Deque is empty");
        head = (head + 1) % capacity;
        size--;
    }

    T& front() {
        if (isEmpty()) throw std::underflow_error("Deque is empty");
        return buffer[head];
    }

    const T& front() const {
        if (isEmpty()) throw std::underflow_error("Deque is empty");
        return buffer[head];
    }

    T& back() {
        if (isEmpty()) throw std::underflow_error("Deque is empty");
        size_t lastIdx = (tail == 0) ? capacity - 1 : tail - 1;
        return buffer[lastIdx];
    }

    const T& back() const {
        if (isEmpty()) throw std::underflow_error("Deque is empty");
        size_t lastIdx = (tail == 0) ? capacity - 1 : tail - 1;
        return buffer[lastIdx];
    }

    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        return buffer[(head + index) % capacity];
    }

    const T& operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of bounds");
        return buffer[(head + index) % capacity];
    }

    void clear() {
        head = 0;
        tail = 0;
        size = 0;
    }
};