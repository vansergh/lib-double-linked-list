#ifndef DLL_HPP
#define DLL_HPP

////////////////////////////////////
// DLList declaration
//////////////////////////////////  

template <typename DataType>
class DLList {
private:

    ////////////////////////////////////
    // DLLNode declaration
    //////////////////////////////////  

    class DLLNode {
    public:
        DataType& GetData();
    private:
        friend DLList;
        DLLNode(const DLLNode&) = delete;
        DLLNode(DLLNode&&) = delete;

        DLLNode();

        DataType data;
        DLLNode* prev;
        DLLNode* next;
    };    

    typedef DLLNode Node;
    typedef Node* NodePtr;
    typedef unsigned long long int size_t;

    NodePtr front_{ nullptr };
    NodePtr back_{ nullptr };
    size_t size_{ 0 };

public:

    DLList(const DLList&) = delete;
    DLList(DLList&&) = delete;
    
    DLList();
    ~DLList();

    void Clear();
    void PushBack(DataType&& data);
    void PushFront(DataType&& data);
    void PopBack();
    void PopFront();
    DataType& Back();
    DataType& Front();
    template <typename OperationFnc>
    void FromBack(OperationFnc& operation_fnc);
    template <typename OperationFnc>
    void FromFront(OperationFnc& operation_fnc);
    bool IsEmpty() const;
    size_t Size() const;
    template <typename PrintFnc>
    void Print(const PrintFnc& print_fnc) const;
};

////////////////////////////////////
// DLLNode defenition
//////////////////////////////////  

template<typename DataType>
inline DataType& DLList<DataType>::DLLNode::GetData()
{
    return data;
}

template<typename DataType>
inline DLList<DataType>::DLLNode::DLLNode() :
    next{ nullptr },
    prev{ nullptr }    
{
    // Default constructor    
}

////////////////////////////////////
// DLList defenition
//////////////////////////////////  

template<typename DataType>
inline DLList<DataType>::DLList() :
    front_{ new Node() },
    back_{ new Node() },
    size_{ 0 }
{
    back_->prev = front_;
    back_->data = DataType();
    front_->next = back_;
    front_->data = DataType();
}

template<typename DataType>
inline DLList<DataType>::~DLList() {
    Clear();
    delete back_;
    delete front_;
}

template<typename DataType>
inline void DLList<DataType>::Clear() {
    if (IsEmpty()) {
        return;
    }
    NodePtr index = front_->next;
    NodePtr current;
    while (index != back_) {
        current = index;
        index = index->next;
        delete current;
    }
    front_->next = back_;
    back_->prev = front_;
    size_ = 0;
}

template<typename DataType>
inline void DLList<DataType>::PushBack(DataType&& data) {
    NodePtr newbie = new Node();
    newbie->data = data;
    NodePtr back_node = back_->prev;
    back_node->next = newbie;
    newbie->prev = back_node;
    newbie->next = back_;
    back_->prev = newbie;
    ++size_;
}

template<typename DataType>
inline void DLList<DataType>::PushFront(DataType&& data) {
    NodePtr newbie = new Node();
    newbie->data = data;
    NodePtr front_node = front_->next;
    front_node->prev = newbie;
    newbie->next = front_node;
    newbie->prev = front_;
    front_->next = newbie;
    ++size_;
}

template<typename DataType>
inline void DLList<DataType>::PopBack() {
    if (IsEmpty()) {
        return;
    }
    NodePtr back_node = back_->prev;
    back_->prev = back_node->prev;
    back_node->prev->next = back_;
    delete back_node;
    --size_;
}

template<typename DataType>
inline void DLList<DataType>::PopFront() {
    if (IsEmpty()) {
        return;
    }
    NodePtr front_node = front_->next;
    front_->next = front_node->next;
    front_node->next->prev = front_;
    delete front_node;
    --size_;
}

template<typename DataType>
inline DataType& DLList<DataType>::Back() {
    return IsEmpty() ? back_->data : back_->prev->data;
}

template<typename DataType>
inline DataType& DLList<DataType>::Front() {
    return IsEmpty() ? front_->data : front_->next->data;
}

template<typename DataType>
template<typename OperationFnc>
inline void DLList<DataType>::FromBack(OperationFnc& operation_fnc) {
    if (IsEmpty()) {
        return;
    }
    NodePtr index = back_->prev;
    NodePtr current;
    while (index != front_) {
        current = index;
        index = index->prev;
        operation_fnc(current);
    }    
}

template<typename DataType>
template<typename OperationFnc>
inline void DLList<DataType>::FromFront(OperationFnc& operation_fnc) {
    if (IsEmpty()) {
        return;
    }
    NodePtr index = front_->next;
    NodePtr current;
    while (index != back_) {
        current = index;
        index = index->next;
        operation_fnc(current);
    }
}

template<typename DataType>
inline bool DLList<DataType>::IsEmpty() const {
    return size_ == 0;
}

template<typename DataType>
typename DLList<DataType>::size_t DLList<DataType>::Size() const {
    return size_;
}

template<typename DataType>
template<typename PrintFnc>
inline void DLList<DataType>::Print(const PrintFnc& print_fnc) const {
    if (IsEmpty()) {
        print_fnc("List is empty");
        return;
    }
    NodePtr index = front_->next;
    while (index != back_) {
        print_fnc("[");
        print_fnc(index->data);
        print_fnc("]");
        if (index->next != back_) {
            print_fnc("<=>");
        }
        index = index->next;
    }    
}

#endif

