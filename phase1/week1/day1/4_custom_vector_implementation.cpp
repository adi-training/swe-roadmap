#ifndef CUSTOM_VECTOR_HPP
#define CUSTOM_VECTOR_HPP

#include <cstddef>
#include <stdexcept>
#include <utility>

template <typename T>
class CustomVector {
private:
    T* m_data = nullptr;
    size_t m_size = 0;
    size_t m_capacity = 0;

    void reallocate(size_t new_capacity) {
        // 1. Allocate new memory on the Heap
        T* new_buffer = new T[new_capacity];

        // 2. Move existing elements to new memory
        for (size_t i = 0; i < m_size; ++i) {
            new_buffer[i] = std::move(m_data[i]);
        }

        // 3. Deallocate old buffer
        delete[] m_data;

        // 4. Update internal pointers and metadata
        m_data = new_buffer;
        m_capacity = new_capacity;
    }

public:
    // Default Constructor
    CustomVector() {
        reallocate(2); // Baseline initial capacity
    }

    // Destructor - Clean RAII release of heap memory
    ~CustomVector() {
        delete[] m_data;
    }

    // Prevent implicit shallow copies (Rule of Three/Five)
    CustomVector(const CustomVector&) = delete;
    CustomVector& operator=(const CustomVector&) = delete;

    // Push Back (Lvalue)
    void push_back(const T& value) {
        if (m_size >= m_capacity) {
            reallocate(m_capacity * 2);
        }
        m_data[m_size++] = value;
    }

    // Push Back (Rvalue)
    void push_back(T&& value) {
        if (m_size >= m_capacity) {
            reallocate(m_capacity * 2);
        }
        m_data[m_size++] = std::move(value);
    }

    // Pop Back
    void pop_back() {
        if (m_size > 0) {
            m_size--;
        }
    }

    // Element Access Overloads
    T& operator[](size_t index) {
        return m_data[index];
    }

    const T& operator[](size_t index) const {
        return m_data[index];
    }

    T& at(size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("CustomVector index out of bounds!");
        }
        return m_data[index];
    }

    // Getters
    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
    bool empty() const { return m_size == 0; }
};

#endif // CUSTOM_VECTOR_HPP