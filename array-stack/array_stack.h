//! Copyright 2018 Luis Enrique Munoz
#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

namespace structures {

template<typename T>
//! Classe principal
class ArrayStack {
 public:
    //! Construtor padrão
    ArrayStack();

    //! Construtor com parâmetros
    explicit ArrayStack(std::size_t max);

    //! Destrutor
    ~ArrayStack();

    //! empilha
    void push(const T& data);

    //! desempilha
    T pop();

    //! Getter do topo da pilha
    T& top();

    //! limpa
    void clear();

    //! tamanho atual
    std::size_t size();

    //! Tamanho total da pilha
    std::size_t max_size();

    //! vazia
    bool empty();

    //! cheia
    bool full();

 private:
    static const auto DEFAULT_SIZE = 10u;

    T* contents;
    int top_;
    std::size_t max_size_;
};

}  // namespace structures

#endif

template<typename T>
structures::ArrayStack<T>::ArrayStack() {	 	  	 	   	 	 		  	   	   	 	
    max_size_ = DEFAULT_SIZE;
    top_ = -1;
    contents = new T(max_size_);
}

template<typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max) {
    max_size_ = max;
    top_ = -1;
    contents = new T(max_size_);
}

template<typename T>
structures::ArrayStack<T>::~ArrayStack() {
    while (!empty()) {
        pop();
    }
}

template<typename T>
bool structures::ArrayStack<T>::empty() {
    return top_ == -1;
}

template<typename T>
bool structures::ArrayStack<T>::full() {
    return top_ == max_size_;
}

template<typename T>
void structures::ArrayStack<T>::push(const T& data) {
    
}

template<typename T>
T structures::ArrayStack<T>::pop() {	 	  	 	   	 	 		  	   	   	 	
    
}
