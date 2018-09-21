// Copyright 2018 Luis Enrique Munoz
#ifndef STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>
    //! Classe de fila encadeada
class LinkedQueue {
 public:
    //! Construtor padrão
    LinkedQueue();

    //! Deletor padrão
    ~LinkedQueue();

    //! limpar
    void clear();

    //! enfilerar
    void enqueue(const T& data);

    //! desenfilerar
    T dequeue();

    //! primeiro dado
    T& front() const;

    //! último dado
    T& back() const;

    //! fila vazia
    bool empty() const;

    //! tamanho
    std::size_t size() const;

 private:
    //! nodo-cabeça
    Node* head;
    //! nodo-fim
    Node* tail;
    //! tamanho
    std::size_t size_;
};

}  // Namespace structures

#endif

template<typename T>
structures::LinkedQueue<T>::LinkedQueue() {
    size_ = 0u;
    head = NULL;
    tail = NULL;
}

template<typename T>
structures::LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template<typename T>
void structures::LinkedQueue<T>::clear() {
    while (!empty()) {
        dequeue();
    }
}

template<typename T>
void structures::LinkedQueue<T>::enqueue(const T& data) {
    if (empty()) {
        Node* novo = new Node(data, head);
        if (novo == NULL) {
            throw std::out_of_range("Sem memória!");
        } else {
            novo->next(head);
            head = novo;
            size_++;
        }
    } else {
        Node* anterior = head;
        for (size_t i = 1u; i < index; i++) {
            anterior = anterior->next();
        }
        Node* novo = new Node(data, anterior->next());
        if (novo == NULL) {
            throw std::out_of_range("Memória cheia");
        }
        anterior->next(novo);
        size_++;
    }
}

template<typename T>
T structures::LinkedQueue<T>::dequeue() {

}

template<typename T>
T& structures::LinkedQueue<T>::front() const {

}

template<typename T>
T& structures::LinkedQueue<T>::back() const {

}

template<typename T>
bool structures::LinkedQueue<T>::empty() const {

}

template<typename T>
std::size_t structures::LinkedQueue<T>::size() const {

}
