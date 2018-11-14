namespace structures {

template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList()
    ~DoublyLinkedList()
    void clear()

    //! insere no fim
    void push_back(const T& data)
    //! insere no início
    void push_front(const T& data)
    //! insere na posição
    void insert(const T& data, std::size_t index)
    //! insere em ordem
    void insert_sorted(const T& data)

    //! retira da posição
    T pop(std::size_t index)
    //! retira do fim
    T pop_back()
    //! retira do início
    T pop_front()
    //! retira específico
    void remove(const T& data)

    //! lista vazia
    bool empty() const
    //! contém
    bool contains(const T& data) const

    //! acesso a um elemento (checando limites)
    T& at(std::size_t index)
    //! getter constante a um elemento
    const T& at(std::size_t index) const

    //! posição de um dado
    std::size_t find(const T& data) const
    //! tamanho
    std::size_t size() const
private:
    class Node {
    public:
        Node(const T& data)
        Node(const T& data, Node* next)
        Node(const T& data, Node* prev, Node* next)

        T& data()
        const T& data() const

        Node* prev()
        const Node* prev() const

        void prev(Node* node)

        Node* next()
        const Node* next() const

        void next(Node* node)
    private:
        T data_;
        Node* prev_;
        Node* next_;
    };

    //! primeiro da lista
    Node* head; 
    //! ultimo da lista
    Node* tail; 
    std::size_t size_;
};

}
