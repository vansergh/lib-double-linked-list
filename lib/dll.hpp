#ifndef DLL_HPP
#define DLL_HPP

#include <iostream>

////////////////////////////////////
// DLLNode declaration
//////////////////////////////////  

template <typename DataType>
struct DLLNode {
public:
    DLLNode(const DLLNode<DataType>&) = delete;
    DLLNode(DLLNode<DataType>&&) = delete;

    DLLNode();

    DataType data;
    DLLNode* prev{ nullptr };
    DLLNode* next{ nullptr };
};

////////////////////////////////////
// DLList declaration
//////////////////////////////////  

template <typename DataType>
class DLList {
public:
    typedef DLLNode<DataType> Node;
    typedef DLLNode<DataType>* NodePtr;

    DLList(const DLList&) = delete;
    DLList(DLList&&) = delete;
    
    DLList();
    ~DLList();

    void Clear();
    void PushBack(const DataType& data);
    void PushFront(const DataType& data);
    void PopBack();
    void PopFront();
    NodePtr Back();
    NodePtr Front();
    template <typename OperationFnc>
    void FromBack(OperationFnc& operation_fnc);
    template <typename OperationFnc>
    void FromFront(OperationFnc& operation_fnc);
    bool IsEmpty();
    unsigned long long int Size();
    void Print();
private:
    NodePtr front_{ nullptr };
    NodePtr back_{ nullptr };
    unsigned long long int size_{ 0 };
};

////////////////////////////////////
// DLLNode defenition
//////////////////////////////////  

template<typename DataType>
inline DLLNode<DataType>::DLLNode() :
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
inline void DLList<DataType>::PushBack(const DataType& data) {
    NodePtr newbie = new Node();
    newbie->data = DataType(data);
    NodePtr back_node = back_->prev;
    back_node->next = newbie;
    newbie->prev = back_node;
    newbie->next = back_;
    back_->prev = newbie;
    ++size_;
}

template<typename DataType>
inline void DLList<DataType>::PushFront(const DataType& data) {
    NodePtr newbie = new Node();
    newbie->data = DataType(data);
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
inline typename DLList<DataType>::NodePtr DLList<DataType>::Back() {
    return IsEmpty() ? back_ : back_->prev;
}

template<typename DataType>
inline typename DLList<DataType>::NodePtr DLList<DataType>::Front() {
    return IsEmpty() ? front_ : front_->next;
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
inline bool DLList<DataType>::IsEmpty() {
    return size_ == 0;
}

template<typename DataType>
inline unsigned long long int DLList<DataType>::Size() {
    return size_;
}

template<typename DataType>
inline void DLList<DataType>::Print() {
    if (IsEmpty()) {
        std::cout << "List is empty";
        return;
    }
    NodePtr index = front_->next;
    while (index != back_) {
        std::cout << "[" << index->data << "]";
        if (index->next != back_) {
            std::cout << "<=>";
        }
        index = index->next;
    }    
}

#endif
