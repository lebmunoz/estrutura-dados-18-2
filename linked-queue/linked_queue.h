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
    //! Elemento
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        //! getter: dado
        T& data() {
            return data_;
        }

        //! getter const: dado
        const T& data() const {
            return data_;
        }

        //! getter: próximo
        Node* next() {
            return next_;
        }

        //! getter const: próximo
        const Node* next() const {
            return next_;
        }

        //! setter: próximo
        void next(Node* node) {
            next_ = node;
        }

        //! setter: dado
        void data(T data) {
            data_ = data;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };

    //! nodo-cabeça
    Node* head;
    //! nodo-fim
    Node* tail;
    //! tamanho
    std::size_t size_;
};

}  // namespace structures

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
    Node* novo = new Node(data, NULL);
    if (empty()) {
        head = novo;
    } else {
        tail->next(novo);
    }
    novo->next(NULL);
    novo->data(data);
    tail = novo;
    size_++;
    }

template<typename T>
T structures::LinkedQueue<T>::dequeue() {
    Node* deleta;
    T retorno;
    if (empty()) {
        throw std::out_of_range("Fila vazia!");
    } else {
        deleta = head;
        retorno = deleta->data();
        head = deleta->next();
        if (size_ == 1) {
            tail = NULL;
        }
        size_--;
        delete deleta;
    }
    return retorno;
}

template<typename T>
T& structures::LinkedQueue<T>::front() const {
    if (size() == 0) {
        throw std::out_of_range("Fila vazia");
    } else {
        return head->data();
    }
}


template<typename T>
T& structures::LinkedQueue<T>::back() const {
    if (size() == 0) {
        throw std::out_of_range("Fila vazia");
    } else {
        return tail->data();
    }
}

template<typename T>
bool structures::LinkedQueue<T>::empty() const {
    return size_ == 0;
}

template<typename T>
std::size_t structures::LinkedQueue<T>::size() const {
    return size_;
}
