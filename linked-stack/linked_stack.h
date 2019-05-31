// Copyright 2019 Luis Enrique Munoz

#include "./linked_list.h"

namespace structures {

template<typename T>
//! Classe Pilha Encadeada
class LinkedStack {
 public:
    //! Construtor padrão
    LinkedStack();

    //! Deletor padrão
    ~LinkedStack();

    //! limpa pilha
    void clear();

    //! empilha
    void push(const T& data);

    //! desempilha
    T pop();

    //! dado no topo
    T& top() const;

    //! pilha vazia
    bool empty() const;

    //! tamanho da pilha
    std::size_t size() const;

 private:
    class Node {
     public:
        explicit Node(const T& data);
        Node(const T& data, Node* next);

        //! getter: info
        T& data() {
            return data_;
        }
        //! getter-constante: info
        const T& data() const {
            return data_;
        }

        //! getter: próximo
        Node* next();
        //! getter-constante: próximo
        const Node* next() const;

        //! setter: próximo
        void next(Node* next);
     private:
        T data_;
        Node* next_;
    };

    //! nodo-topo
    Node* top_;
    //! tamanho
    std::size_t size_;
    //! ACESSO À CLASSE LISTA
    LinkedList<T> lista;
};

}  // namespace structures

template<typename T>
structures::LinkedStack<T>::LinkedStack() {
    size_ = 0u;
    top_ = NULL;
}

template<typename T>
structures::LinkedStack<T>::~LinkedStack() {
    clear();
}

template<typename T>
void structures::LinkedStack<T>::clear() {
    lista.clear();
}

template<typename T>
void structures::LinkedStack<T>::push(const T& data) {
    lista.push_front(data);
}

template<typename T>
T structures::LinkedStack<T>::pop() {
    return lista.pop_front();
}

template<typename T>
T& structures::LinkedStack<T>::top() const {
    return lista.at(0);
}

template<typename T>
bool structures::LinkedStack<T>::empty() const {
    return lista.empty();
}

template<typename T>
std::size_t structures::LinkedStack<T>::size() const {
    return lista.size();
}
