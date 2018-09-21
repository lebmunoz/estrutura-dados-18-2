//  Copyright 2018 Luis Enrique Borba Munoz
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>

namespace structures {

template<typename T>
//! Classe principal da lista com vetores
class ArrayList {
 public:
//! Construtor da lista com vetores com parametro fixo
    ArrayList();
//! Construtor da lista com vetores com parametro dinamico
    explicit ArrayList(std::size_t max_size);
//! Destrutor da lista com vetores
    ~ArrayList();
//! Método para limpar a lista
    void clear();
//! Método Inserir no fim da lista
    void push_back(const T& data);
//! Método Inserir no início da lista
    void push_front(const T& data);
//! Método Inserir um dado na posição passada
    void insert(const T& data, std::size_t index);
//! Método Inserir ordenado
    void insert_sorted(const T& data);
//! Método remover um dado da posição passada
    T pop(std::size_t index);
//! Método remover do final
    T pop_back();
//! Método remover do início
    T pop_front();
//! Método para remover um dado específico
    void remove(const T& data);
//! Teste de lista cheia
    bool full() const;
//! Teste de lista vazia
    bool empty() const;
//! Testa se a lista possui o dado passado
    bool contains(const T& data) const;
//! Procura se um dado está na lista e retorna a posição dele
    std::size_t find(const T& data) const;
//! Método para informar o tamanho atual da lista
    std::size_t size() const;
//! Método para informar o tamanho total da lista
    std::size_t max_size() const;
//! Informa o endereço de uma certa posição
    T& at(std::size_t index);
//! Operador de acesso do vetor de dados
    T& operator[](std::size_t index);
//! "Getter" do endereço da posição passada
    const T& at(std::size_t index) const;
//! "Getter" do dado na posição passada, de dentro do array
    const T& operator[](std::size_t index) const;

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_MAX = 10u;
};

}  // namespace structures

#endif

template<typename T>
structures::ArrayList<T>::ArrayList() {	 	  	 	   	 	 		  	   	   	 	
    max_size_ = DEFAULT_MAX;
    size_ = -1;
    contents = new T[max_size_];
}

template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size) {
    max_size_ = max_size;
    size_ = -1;
    contents = new T[max_size_];
}

template<typename T>
structures::ArrayList<T>::~ArrayList() {
    size_ = -1;
    delete[] contents;
}
template<typename T>
void structures::ArrayList<T>::clear() {
    size_ = -1;
}
template<typename T>
void structures::ArrayList<T>::push_back(const T& data) {
    insert(data, size_+1);
}
template<typename T>
void structures::ArrayList<T>::push_front(const T& data) {
    insert(data, 0);
}
template<typename T>
void structures::ArrayList<T>::insert(const T& data, std::size_t index) {
    if (full()) {
        throw std::out_of_range("Lista cheia");
    } else if (index > size_+2 || index < 0) {
        throw std:: out_of_range("Posição inválida");
    } else {	 	  	 	   	 	 		  	   	   	 	
        size_++;
        for (int i = size_; i > index; i--) {
            contents[i] = contents[i-1];
        }
        contents[index] = data;
    }
}
template<typename T>
void structures::ArrayList<T>::insert_sorted(const T& data) {
    if (full()) {
        throw std::out_of_range("Lista cheia");
    } else {
        std::size_t i;
        for (i = 0; i < size() && data > contents[i]; i++) {}
        insert(data, i);
    }
}
template<typename T>
T structures::ArrayList<T>::pop(std::size_t index) {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else if (index > size_ || index < 0) {
        throw std:: out_of_range("Posição inválida");
    } else {
        T retorno = contents[index];
        size_--;
        for (int i = index; i < size(); i++) {
            contents[i] = contents[i+1];
        }
        return retorno;
    }
}
template<typename T>
T structures::ArrayList<T>::pop_back() {
    return pop(size_);
}	 	  	 	   	 	 		  	   	   	 	
template<typename T>
T structures::ArrayList<T>::pop_front() {
    return pop(0);
}
template<typename T>
void structures::ArrayList<T>::remove(const T& data) {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else {
        std::size_t pos_apagar = find(data);
        size_--;
        for (int i = pos_apagar; i < size(); i++) {
            contents[i] = contents[i+1];
        }
    }
}
template<typename T>
bool structures::ArrayList<T>::full() const {
    return max_size_ == size_ + 1;
}
template<typename T>
bool structures::ArrayList<T>::empty() const {
    return size_ == -1;
}
template<typename T>
bool structures::ArrayList<T>::contains(const T& data) const {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else {
        int atual = 0;
        while (atual < size()) {
            if (data == contents[atual]) {
                return true;
            }
            atual++;
        }	 	  	 	   	 	 		  	   	   	 	
        return false;
    }
}
template<typename T>
std::size_t structures::ArrayList<T>::find(const T& data) const {
    std::size_t atual = 0;
    while (atual <= size_ && data != contents[atual]) {
        atual++;
    }
    return atual;
}
template<typename T>
std::size_t structures::ArrayList<T>::size() const {
    return size_+1;
}
template<typename T>
std::size_t structures::ArrayList<T>::max_size() const {
    return max_size_;
}
template<typename T>
T& structures::ArrayList<T>::at(std::size_t index) {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else if (index > size_+2 || index < 0) {
        throw std:: out_of_range("Posição inválida");
    } else {
        return contents[index];
    }
}
template<typename T>
T& structures::ArrayList<T>::operator[](std::size_t index) {
    return contents[index];
}
template<typename T>
const T& structures::ArrayList<T>::at(std::size_t index) const {
    if (empty()) {	 	  	 	   	 	 		  	   	   	 	
        throw std::out_of_range("Lista vazia");
    } else if (index > size_+2 || index < 0) {
        throw std:: out_of_range("Posição inválida");
    } else {
        return contents[index];
    }
}
template<typename T>
const T& structures::ArrayList<T>::operator[](std::size_t index) const {
    return contents[index];
}
