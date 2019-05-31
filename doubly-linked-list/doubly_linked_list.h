// Copyright 2019 Luis Enrique Munoz
#ifndef STRUCTURES_DOUBLY_LINKED_LIST_H
#define STRUCTURES_DOUBLY_LINKED_LIST_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

namespace structures {

template<typename T>
//! Classe Lista Duplamente Encadeada
class DoublyLinkedList {
 public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    //! limpa lista
    void clear();

    //! insere no fim
    void push_back(const T& data);
    //! insere no início
    void push_front(const T& data);
    //! insere na posição
    void insert(const T& data, std::size_t index);
    //! insere em ordem
    void insert_sorted(const T& data);

    //! retira da posição
    T pop(std::size_t index);
    //! retira do fim
    T pop_back();
    //! retira do início
    T pop_front();
    //! retira específico
    void remove(const T& data);

    //! lista vazia
    bool empty() const;
    //! contém
    bool contains(const T& data) const;

    //! acesso a um elemento (checando limites)
    T& at(std::size_t index);
    //! getter constante a um elemento
    const T& at(std::size_t index) const;

    //! posição de um dado
    std::size_t find(const T& data) const;
    //! tamanho
    std::size_t size() const;

 private:
    class Node {
     public:
        explicit Node(const T& data);
        Node(const T& data, Node* next);
        Node(const T& data, Node* prev, Node* next);

        T& data();
        const T& data() const;

        Node* prev();
        const Node* prev() const;

        void prev(Node* node);

        Node* next();
        const Node* next() const;

        void next(Node* node);
     private:
        T data_;
        Node* prev_;
        Node* next_;
    };

    Node* head;  // primeiro da lista
    Node* tail;  // ultimo da lista
    std::size_t size_;
};

}  // namespace structures

#endif

template<typename T>
structures::DoublyLinkedList<T>::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
    size_ = 0u;
}

template<typename T>
structures::DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
void structures::DoublyLinkedList::clear() {
    while(!empty()) {
        pop_front();
    }
}

template<typename T>
void structures::DoublyLinkedList::push_back(const T& data) {
    insert(data, size());
}

template<typename T>
void structures::DoublyLinkedList::push_front(const T& data) {
    insert(data, 1u);
}

