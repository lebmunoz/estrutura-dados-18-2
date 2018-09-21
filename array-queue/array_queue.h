//  Copyright 2018 Luis Enrique Borba Munoz
#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

namespace structures {

template<typename T>
/**
* Classe Fila de Vetor
* A classe inteira está aqui.
*/
class ArrayQueue {
 public:
    ArrayQueue();
/**
* Construtor com parâmetros.
* Recebe uma quantidade variável e constroi o vetor.
*/
    explicit ArrayQueue(std::size_t max);

    ~ArrayQueue();
/**
* Método Enfileira.
* Recebe um dado, incrementa o tamanho atual e coloca o dado no fim da fila.
*/
    void enqueue(const T& data);
/**
* Método Desenfileira.
* Decrementa o fim da fila e retorna o dado que estava nele.
*/
    T dequeue();
/**
* Método fim da fila.
* Retorna qual o dado que esta no fim da fila.
*/
    T& back();
/**
* Método Limpar.
* Define o fim da fila como -1.
*/
    void clear();
/**
* Método Tamanho.
* Informa qual o tamanho atual da fila.
*/
    std::size_t size();
/**
* Método Tamanho Total.
* Informa o tamanho total da fila.
*/
    std::size_t max_size();
/**
* Método fila Vazia.
* Retorna se a fila está vazia ou não.
*/
    bool empty();
/**
* Método fila Cheia.
* Retorna se a fila está cheia ou não.
*/
    bool full();

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif

template<typename T>
structures::ArrayQueue<T>::ArrayQueue() {	 	  	 	   	 	 		  	   	   	 	
    max_size_ = DEFAULT_SIZE;
    size_ = -1;
    contents = new T[max_size_];
}
template<typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max) {
    max_size_ = max;
    size_ = -1;
    contents = new T[max_size_];
}
template<typename T>
structures::ArrayQueue<T>::~ArrayQueue() {
    size_ = -1;
    delete[] contents;
}
template<typename T>
void structures::ArrayQueue<T>::enqueue(const T& data) {
    if (full()) {
        throw std::out_of_range("Fila cheia");
    } else {
        size_++;
        contents[size_] = data;
    }
}
template<typename T>
T structures::ArrayQueue<T>::dequeue() {
    if (empty()) {
        throw std::out_of_range("Fila vazia");
    } else {
        T retorno = contents[0];
        for (int i = 0; i < size_; i++) {
            contents[i] = contents[i+1];
        }
        size_--;
        return retorno;
    }	 	  	 	   	 	 		  	   	   	 	
}
template<typename T>
T& structures::ArrayQueue<T>::back() {
    if (empty()) {
        throw std::out_of_range("Fila vazia");
    }
    return contents[size_];
}
template<typename T>
void structures::ArrayQueue<T>::clear() {
    size_ = -1;
}
template<typename T>
std::size_t structures::ArrayQueue<T>::size() {
    return size_ + 1;
}
template<typename T>
std::size_t structures::ArrayQueue<T>::max_size() {
    return max_size_;
}
template<typename T>
bool structures::ArrayQueue<T>::empty() {
    return size_ == -1;
}
template<typename T>
bool structures::ArrayQueue<T>::full() {
    return max_size_ == size_ + 1;
}
	 	  	 	   	 	 		  	   	   	 	
