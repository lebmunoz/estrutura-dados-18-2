//! Copyright [2019] Luis Enrique Borba Munoz


#ifndef STRUCTURES_STRING_LIST_H
#define STRUCTURES_STRING_LIST_H

#include <cstdint>
#include <stdexcept>  // C++ exceptions
#include <cstring>



namespace structures {


//! ...
template<typename T>
class ArrayList {
 public:
    //! ...
    ArrayList() {
        max_size_ = DEFAULT_MAX;
        size_ = -1;
        contents = new T[max_size_];
    }
    //! ...
    explicit ArrayList(std::size_t max_size) {
        max_size_ = max_size;
        size_ = -1;
        contents = new T[max_size_];
    }
    //! ...
    ~ArrayList() {
        size_ = -1;
        delete[] contents;
    }

    //! ...
    void clear() {
        size_ = -1;
    }
    //! ...
    void push_back(const T& data) {
        insert(data, size_+1);
    }
    //! ...
    void push_front(const T& data) {
        insert(data, 0);
    }
    void insert(const T& data, std::size_t index) {
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
    //! ...
    void insert_sorted(const T& data) {
        if (full()) {
            throw std::out_of_range("Lista cheia");
        } else {
            std::size_t i;
            for (i = 0; i < size() && data > contents[i]; i++) {}
            insert(data, i);
        }
    }
    //! ...
    T pop(std::size_t index) {
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
    //! ...
    T pop_back() {
        return pop(size_);
    }
    //! ...
    T pop_front() {
        return pop(0);
    }
    //! ...
    void remove(const T& data) {
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
    //! ...
    bool full() const {
        return max_size_ == size_ + 1;
    }
    //! ...
    bool empty() const {
        return size_ == -1;
    }
    //! ...
    bool contains(const T& data) const {
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
    //! ...
    std::size_t find(const T& data) const {
        std::size_t atual = 0;
        while (atual <= size_ && data != contents[atual]) {
            atual++;
        }
        return atual;
    }
    //! ...
    std::size_t size() const {
        return size_+1;
    }
    //! ...
    std::size_t max_size() const {
        return max_size_;
    }
    //! ...
    T& at(std::size_t index) {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        } else if (index > size_+2 || index < 0) {
            throw std:: out_of_range("Posição inválida");
        } else {
            return contents[index];
        }
    }
    //! ...
    T& operator[](std::size_t index) {
        return contents[index];
    }
    //! ...
    const T& at(std::size_t index) const {
        if (empty()) {
            throw std::out_of_range("Lista vazia");
        } else if (index > size_+2 || index < 0) {
            throw std:: out_of_range("Posição inválida");
        } else {
            return contents[index];
        }
    }
    //! ...
    const T& operator[](std::size_t index) const {
        return contents[index];
    }

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_MAX = 10u;
};



//-------------------------------------



//! ...
//! ArrayListString e' uma especializacao da classe ArrayList
class ArrayListString : public ArrayList<char *> {
 public:
    //! ...
    ArrayListString() : ArrayList() {}
    //! ...
    explicit ArrayListString(std::size_t max_size) : ArrayList(max_size) {}
    //! ...
    ~ArrayListString();

    //! ...
    void clear();
    //! ...
    void push_back(const char *data);
    //! ...
    void push_front(const char *data);
    //! ...
    void insert(const char *data, std::size_t index);
    //! ...
    void insert_sorted(const char *data);
    //! ...
    char *pop(std::size_t index);
    //! ...
    char *pop_back();
    //! ...
    char *pop_front();
    //! ...
    void remove(const char *data);
    //! ...
    bool contains(const char *data);
    //! ...
    std::size_t find(const char *data);

 private:
    T* contents_char;
    std::size_t size_;
    std::size_t max_size_;
};

}  // namespace structures

#endif

template<typename T>
structures::ArrayList<T>::~ArrayListString() {
    for (int i = 0; i < contents_char.length(); ++i)
    {
        ~ArrayList();
    }
}
template<typename T>
void structures::ArrayList<T>::clear() {
    size_ = -1;
}

template<typename T>
void structures::ArrayList<T>::push_back(const char *data) {
    insert()
}
