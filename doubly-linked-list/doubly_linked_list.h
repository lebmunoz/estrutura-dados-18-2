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

        T& data() {
            return data_;
        }

        const T& data() const {
            return data_;
        }

        Node* prev() {
            return prev_;
        }

        const Node* prev() const {
            return prev_;
        }

        void prev(Node* node) {
            prev_ = node;
        }

        Node* next() {
            return next_;
        }
        const Node* next() const {
            return next_;
        }

        void next(Node* node) {
            next_ = node;
        }
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
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
void structures::DoublyLinkedList::push_back(const T& data) {
    insert(data, size());
}

template<typename T>
void structures::DoublyLinkedList::push_front(const T& data) {
    Node* aux = new Node(data);
    if (aux == NULL) {
        throw std::out_of_range("Memória cheia!");
    } else {
        aux->next(head);
        aux->prev(NULL);
        head = aux;
        if (aux->next() =! NULL) {
            aux->next->prev(aux);
        } else {
            tail = aux;
        }
        size_++;
    }
}

template<typename T>
void structures::DoublyLinkedList::insert(const T& data, std::size_t index) {
    Node* novo = new Node(data);
    Node* anterior;
    if (novo == NULL) {
        throw std::out_of_range("Memória cheia!");
    } else if (index > size_ || index < 0) {
        throw std::out_of_range("Posição inválida!");
    } else if (index == 0) {
        push_front(data);
    } else {
        anterior = head;
        for (int i = 0; i < index; ++i) {
            anterior = anterior->next();
        }
        novo->next(anterior->next());
        if (novo->next() != NULL) {
            novo->next->prev(novo);
        } else {
            tail = novo;
        }
        novo->next(anterior->next());
        anterior->next(novo);
        novo->prev(anterior);
        size_++;
    }
}

template<typename T>
void structures::DoublyLinkedList::insert_sorted(const T& data) {
    insert(data, 1u);
}

template<typename T>
T structures::DoublyLinkedList::pop(std::size_t index) {
    insert(data, 1u);
}

template<typename T>
T structures::DoublyLinkedList::pop_back() {
    insert(data, 1u);
}

template<typename T>
T structures::DoublyLinkedList::pop_front() {
    insert(data, 1u);
}

template<typename T>
void structures::DoublyLinkedList::remove(const T& data) {
    insert(data, 1u);
}

template<typename T>
bool structures::DoublyLinkedList::empty() const {
    insert(data, 1u);
}

template<typename T>
bool structures::DoublyLinkedList::contains(const T& data) const {
    insert(data, 1u);
}

template<typename T>
T& structures::DoublyLinkedList::at(std::size_t index) {
    insert(data, 1u);
}

template<typename T>
const T& structures::DoublyLinkedList::at(std::size_t index) const {
    insert(data, 1u);
}

template<typename T>
std::size_t structures::DoublyLinkedList::find(const T& data) const {
    insert(data, 1u);
}

template<typename T>
std::size_t structures::DoublyLinkedList::size() const {
    insert(data, 1u);
}
