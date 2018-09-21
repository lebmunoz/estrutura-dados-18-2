//! Copyright 2018 Luis Enrique Munoz
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>
//! Classe principal
class LinkedList {
 public:
    //! construtor padrão
    LinkedList();

    //! destrutor
    ~LinkedList();

    //! limpar lista
    void clear();

    //! inserir no fim
    void push_back(const T& data);

    //! inserir no início
    void push_front(const T& data);

    //! inserir na posição
    void insert(const T& data, std::size_t index);

    //! inserir em ordem
    void insert_sorted(const T& data);

    //! acessar um elemento na posição index
    T& at(std::size_t index);

    //! retirar da posição
    T pop(std::size_t index);

    //! retirar do fim
    T pop_back();

    //! retirar do início
    T pop_front();

    //! remover específico
    void remove(const T& data);

    //! lista vazia
    bool empty() const;

    //! contém
    bool contains(const T& data) const;

    //! posição do dado
    std::size_t find(const T& data) const;

    //! tamanho da lista
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

     private:
        T data_;
        Node* next_{nullptr};
    };

    //! último nodo da lista
    Node* end() {	 	  	 	   	 	 		  	   	   	 	
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }

    Node* head{nullptr};
    std::size_t size_{0u};
};

}  // namespace structures

#endif

template<typename T>
structures::LinkedList<T>::LinkedList() {
    size_ = 0u;
    head = NULL;
}

template<typename T>
structures::LinkedList<T>::~LinkedList() {
    clear();
}

template<typename T>
void structures::LinkedList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
void structures::LinkedList<T>::push_back(const T& data) {
    insert(data, size());
}	 	  	 	   	 	 		  	   	   	 	

template<typename T>
void structures::LinkedList<T>::push_front(const T& data) {
    Node* novo = new Node(data, head);
    if (novo == NULL) {
        throw std::out_of_range("Sem espaço em memória");
    } else {
        novo->next(head);
        head = novo;
		size_++;
    }
}

template<typename T>
void structures::LinkedList<T>::insert(const T& data, std::size_t index) {
    if (index >= size_+1 || index < 0) {
    	throw std::out_of_range("Erro de posição");
    } else if (empty() || index == 0) {
    	push_front(data);
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
void structures::LinkedList<T>::insert_sorted(const T& data) {
    if (empty()) {	 	  	 	   	 	 		  	   	   	 	
        push_front(data);
    } else {
        Node* auxiliar = head;
        size_t i = 0u;
        while (i < size() && auxiliar->data() < data) {
            auxiliar = auxiliar->next();
            i++;
        }
        insert(data, i);
    }
}

template<typename T>
T& structures::LinkedList<T>::at(std::size_t index) {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else if (index >= size_+1 || index < 0) {
    	throw std::out_of_range("Erro de posição");
    } else {
        Node* auxiliar = head;
        for (size_t i = 0u; i < index; i++) {
            auxiliar = auxiliar->next();
        }
        return auxiliar->data();
    }
}

template<typename T>
T structures::LinkedList<T>::pop(std::size_t index) {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else if (index >= size_+1 || index < 0) {
    	throw std::out_of_range("Erro de posição");
    } else if (index == 1) {
        return pop_front();
    } else {	 	  	 	   	 	 		  	   	   	 	
        T volta;
        Node* eliminar;
        Node* anterior = head;
    	for (size_t i = 0u; i < index-2; i++) {
    		anterior = anterior->next();
    	}
    	eliminar = anterior->next();
    	volta = eliminar->data();
    	anterior->next(eliminar->next());
    	size_--;
    	delete eliminar;
    	return volta;
    }
}

template<typename T>
T structures::LinkedList<T>::pop_back() {
    return pop(size());
}

template<typename T>
T structures::LinkedList<T>::pop_front() {
	if (empty()) {
        throw std::out_of_range("Lista vazia");
	} else {
		T volta;
		Node* eliminar = head;
		volta = eliminar->data();
		head = eliminar->next();
		size_--;
		delete eliminar;
		return volta;
	}
}

template<typename T>
void structures::LinkedList<T>::remove(const T& data) {	 	  	 	   	 	 		  	   	   	 	
    pop(find(data));
}

template<typename T>
bool structures::LinkedList<T>::empty() const {
    return (size() == 0);
}

template<typename T>
bool structures::LinkedList<T>::contains(const T& data) const {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else {
        Node* auxiliar = head;
        size_t i = 0u;
        while (i < size()) {
            if (auxiliar->data() == data) {
                return true;
            } else {
                auxiliar = auxiliar->next();
                i++;
            }
        }
        return false;
    }
}

template<typename T>
std::size_t structures::LinkedList<T>::find(const T& data) const {
	if (empty()) {
        throw std::out_of_range("Lista vazia");
	} else {
	    Node* auxiliar = head;
        size_t i = 0u;
        while (i < size()) {
            if (auxiliar->data() == data) {	 	  	 	   	 	 		  	   	   	 	
                return i;
            }
            auxiliar = auxiliar->next();
            i++;
        }
        return i;
	}
}

template<typename T>
std::size_t structures::LinkedList<T>::size() const {
    return size_;
}
