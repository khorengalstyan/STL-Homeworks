#include <iostream>
#include <vector>
#include <cstdlib>


template<class T>
class MyAllocator {
public:
    MyAllocator() = default;

    T* allocate(int n) {
        T* array = (T*)malloc(n * sizeof(T));
        return array;
    }

    void construct(T* p, const T& v) {
        T* createdObject = new(p) T{ v };
    }

    void deallocate(T* p) {
        free(p);
        
    }

    void destroy(T* p) {
        p->~T();
    }
    
};


template<class T>
class MyVector {
private:
    T* array;
    int size;
    int capacity;
    MyAllocator<T> allocator;

public:

    MyVector(int n) {
        array = allocator.allocate(n);
        capacity = n;
        size = 0;
    }

    class Iterator {
        public:
            Iterator(T*);
            Iterator& operator++();
            Iterator& operator--();
            bool operator!=(const Iterator&) const;
            bool operator==(const Iterator&) const;
            T& operator*();
            T* operator->();
        private:
            T* it;

            Iterator begin();
            Iterator end();
    };



    int getSize() const {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    T& operator++() {
        
        
        return *this->array;
    }

    void push(T element) {
        if (size == capacity) {
            array = (T*)realloc(array, sizeof(T) * size * 2);
            capacity = size * 2;
        }
        allocator.construct(array + size, element);
        ++size;
    }
    
    bool isEmpty() {
        return size == 0;
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        allocator.destroy(array + (size - 1));
        --size;
    }

    void clear() {
        if (isEmpty()) {
            return;
        }
        allocator.deallocate(array);
        size = 0;
    }

    void printArray() {
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }



    T operator[](int index) {
        return array[index];
    }

    const T& operator[](int index) const {
        return array[index];
    }


    MyVector<T>& operator=(MyVector& newVector) {
        T* newArray = allocator.allocate(newVector.getCapacity());

        for (size_t i = 0; i < newVector.getSize(); ++i) {
            allocator.construct(newArray + i, newVector[i]);
        }
        for (size_t i = 0; i < getSize(); ++i) {
            allocator.destroy(array + i);
        }
        allocator.deallocate(array);
        array = newVector;
        size = newVector.getSize();
        capacity = newVector.getCapacity();
    
        return *this;
    }
    

};



int main() {
    
    MyVector<int> firstVector(5);
    firstVector.push(1);
    firstVector.push(5);
    firstVector.push(2);
    firstVector.push(4);
    firstVector.push(3);

    MyVector<int> second = firstVector;
    std::cout << second[3];
    //int a = ++firstVector;
    std::cout << ++firstVector;



    return 0;
}



