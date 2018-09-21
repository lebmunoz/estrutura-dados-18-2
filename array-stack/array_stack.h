//  Copyright 2018 Luis Enrique Borba Munoz
#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

namespace structures {

template<typename T>
/**
* Classe Pilha de Vetor
* A classe inteira está aqui.
*/
class ArrayStack {
 public:
 /**
* Construtor padrão.
* Define valores fixos e constroi o vetor.
*/
    ArrayStack() {
        max_size_ = DEFAULT_SIZE;
        top_ = -1;
        contents = new T(max_size_);
    }
/**
* Construtor com parâmetros.
* Recebe uma quantidade variável e constroi o vetor.
*/
    explicit ArrayStack(std::size_t max) {
        max_size_ = max;
        contents = new T[max_size_];
        top_ = -1;
    }
/**
* Destrutor.
* Define o topo como -1 e desaloca o espaço de memória do vetor.
*/
    ~ArrayStack() {
        top_ = -1;
        delete[] contents;
    }
/**
* Método Empilha.
* Recebe um dado, incrementa o tamanho atual e coloca o dado no topo.
*/
    void push(const T& data) {
        if (full()) {
            throw std::out_of_range("Pilha cheia");
        } else {
        top_++;
        contents[top_] = data;
        }
    }
/**
* Método Desempilha.
* Decrementa o topo e retorna o dado que estava nele.
*/
    T pop() {
        if (empty()) {
            throw std::out_of_range("Pilha vazia");
        }
        top_--;
        return (contents[top_+1]);
    }
/**
* Método Topo.
* Retorna qual o dado que esta no topo.
*/
    T& top() {
        if (empty()) {
            throw std::out_of_range("Pilha vazia");
        }
        return contents[top_];
    }
/**
* Método Limpar.
* Define o topo como -1.
*/
    void clear() {
        top_ = -1;
    }
/**
* Método Tamanho.
* Informa qual o tamanho atual da pilha.
*/
    std::size_t size() {
        return top_+1;
    }
/**
* Método Tamanho Total.
* Informa o tamanho total da pilha.
*/
    std::size_t max_size() {
        return max_size_;
    }
/**
* Método Pilha Vazia.
* Retorna se a pilha está vazia ou não.
*/
    bool empty() {
        return (top_ == -1);
    }
/**
* Método Pilha Cheia.
* Retorna se a pilha está cheia ou não.
*/
    bool full() {
        return (top_ == max_size_-1);
    }

 private:
    T* contents;
    int top_;
    std::size_t max_size_;

    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

#endif
