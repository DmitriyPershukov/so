#include <iostream>
template<typename T>
class stackm {
    int capacity;
    int count;
    T* data;
public:
    stackm();
    ~stackm();
    void push(const T& element);
    void push(T &&element);
    void pop();
    T& top();
    int size() const;
};

template<typename T>
stackm<T>::stackm() {
    capacity = 1;
    count = 0;
    data = new T[capacity];
}
template<typename T>
void stackm<T>::pop() {
    --count;
}
template<typename T>
stackm<T>::~stackm() {
    delete[] data;
}
template<typename T>
T& stackm<T>::top() {

}

template<typename T> 
class Node {
public:
    T data;
    Node* pointer;
};

template<typename T>
class stackt {
    int count;
    Node<T> root;
public:
    stackt();
    ~stackt();
    void push(const T& element);
    void push(T &&element);
    void pop();
    T& top();
    int size() const;
};

template<typename T>
stackt<T>::stackt() {
    count = 0;
}

template<typename T>
void stackt<T>::pop() {
    root = root.pointer;
    count--;
}

template<typename T>
T& stackt<T>::top() {
    return root.data;
}

template<typename T>
void stackt<T>::push(const T& element) {
    Node<T> newnode = Node<T>();
    newnode.data = element;
    newnode.pointer = root;
    root.pointer = newnode;
}

template<typename T>
void stackt<T>::push(T &&element) {
    Node<T> newnode = Node<T>();
    newnode.data = element;
    newnode.pointer = *root;
    root.pointer = *newnode;
    count++;
}

template<typename T>
int stackt<T>::size() const{
    return count;
}


int main() {
    stackt<long> sd = stackt<long>();
    sd.push(23);
    std::cout << sd.top() << std::endl;
    sd.pop();
}