#ifndef DLL_HPP
#define DLL_HPP

#include <initializer_list>

// Push type (push back or push front) for initializer_list constructor
enum class InitListPushType { BACK, FRONT };

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
        DLLNode() = delete;

        DLLNode(DataType&& in_data, DLLNode* in_prev, DLLNode* in_next);
        DLLNode(const DataType& in_data, DLLNode* in_prev, DLLNode* in_next);

        DataType data;
        DLLNode* prev;
        DLLNode* next;
    };

    typedef DLLNode Node;
    typedef Node* NodePtr;
    typedef unsigned long long int size_t;

    size_t size_{ 0 };
    DataType empty_;
    NodePtr front_;
    NodePtr back_;

    NodePtr CopyNodes_(const DLList& other);
    NodePtr InitFromList_(std::initializer_list<DataType> init_list, InitListPushType push_type);    

public:

    DLList();
    DLList(std::initializer_list<DataType> init_list, InitListPushType push_type = InitListPushType::BACK);
    DLList(const DLList& other);
    DLList(DLList&& other);
    ~DLList();

    DLList& operator=(const DLList& other);
    DLList& operator=(DLList&& other);

    void Clear();
    void PushBack(DataType&& data);
    void PushBack(const DataType& data);
    void PushFront(DataType&& data);
    void PushFront(const DataType& data);
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
inline DataType& DLList<DataType>::DLLNode::GetData() {
    return data;
}

template<typename DataType>
inline DLList<DataType>::DLLNode::DLLNode(DataType&& in_data, DLList<DataType>::DLLNode* in_prev, DLList<DataType>::DLLNode* in_next) :
    data{ std::move(in_data) },
    next{ in_prev },
    prev{ in_next }
{
    if (in_prev != nullptr) {
        in_prev->prev = this;    
    }
    if (in_next != nullptr) {
        in_next->next =  this;    
    }
}

template<typename DataType>
inline DLList<DataType>::DLLNode::DLLNode(const DataType& in_data, DLList<DataType>::DLLNode* in_prev, DLList<DataType>::DLLNode* in_next) :
    data{ DataType(in_data) },
    next{ in_prev },
    prev{ in_next }
{
    if (in_prev != nullptr) {
        in_prev->prev = this;    
    }
    if (in_next != nullptr) {
        in_next->next =  this;    
    }
}

////////////////////////////////////
// DLList defenition
//////////////////////////////////  

template<typename DataType>
inline typename DLList<DataType>::NodePtr DLList<DataType>::CopyNodes_(const DLList& other) {
    back_ = nullptr;
    if (other.IsEmpty()) {
        return nullptr;
    }
    NodePtr index = other.back_;

    back_ = new Node(index->data, nullptr, nullptr);
    front_ = back_;
    front_->next = back_;
    front_->prev = back_;
    back_->next = front_;
    back_->prev = front_;
    index = index->prev;

    while (index != other.back_) {
        back_ = new Node(index->data, front_, back_);      
        index = index->prev;
    }

    return front_;
}

template<typename DataType>
inline typename DLList<DataType>::NodePtr DLList<DataType>::InitFromList_(std::initializer_list<DataType> init_list, InitListPushType push_type) {
    front_ = nullptr;
    back_ = nullptr;
    if (push_type == InitListPushType::BACK) {
        for (auto it = init_list.begin(); it != init_list.end(); ++it) {
            PushBack(*it);
        }
    }
    else {
        for (auto it = init_list.begin(); it != init_list.end(); ++it) {
            PushFront(*it);
        }        
    }
    return front_;
}

template<typename DataType>
inline DLList<DataType>::DLList() :
    size_{ 0 },
    empty_{ DataType() },
    front_{ nullptr },
    back_{ nullptr }
{
    // Default constructor
}

template<typename DataType>
inline DLList<DataType>::DLList(std::initializer_list<DataType> init_list, InitListPushType push_type) :
    size_{ 0 },
    empty_{ DataType() },
    front_{ InitFromList_(init_list, push_type) }
{
    // std::initializer_list constructor
}

template<typename DataType>
inline DLList<DataType>::DLList(const DLList& other) :
    size_{ other.size_ },
    empty_{ DataType() },
    front_{ CopyNodes_(other) }
{
    // Copy constructor
}

template<typename DataType>
inline DLList<DataType>::DLList(DLList&& other) :
    size_{ other.size_ },
    empty_{ DataType() },
    front_{ other.front_ },
    back_{ other.back_ }
{
    other.back_ = nullptr;
    other.front_ = nullptr;
    other.Clear();
}

template<typename DataType>
inline DLList<DataType>::~DLList() {
    Clear();
}

template<typename DataType>
inline DLList<DataType>& DLList<DataType>::operator=(const DLList& other) {
    if (this == &other) {
        Clear();
        size_ = other.size_;
        front_ = CopyNodes_(other);
    }
    return *this;
}

template<typename DataType>
inline DLList<DataType>& DLList<DataType>::operator=(DLList&& other) {
    if (this != &other) {
        Clear();
        front_ = other.front_;
        back_ = other.back_;
        size_ = other.size_;
        other.front_ = nullptr;
        other.back_ = nullptr;
        other.Clear();
    }
    return *this;
}

template<typename DataType>
inline void DLList<DataType>::Clear() {
    if (IsEmpty()) {
        return;
    }
    if (size_ > 1) {
        NodePtr index = front_;
        NodePtr current{ nullptr };
        while (index != back_) {
            current = index;
            index = index->next;
            delete current;
        }        
    }
    delete back_;
    front_ = nullptr;
    back_ = nullptr;    
    size_ = 0;
}

template<typename DataType>
inline void DLList<DataType>::PushBack(DataType&& data) {
    back_ = new Node(std::move(data), front_, back_);
    if (size_ == 0) {
        front_ = back_;
        front_->next = back_;
        front_->prev = back_;
        back_->next = front_;
        back_->prev = front_;
    }
    ++size_;
}

template<typename DataType>
inline void DLList<DataType>::PushBack(const DataType& data) {
    back_ = new Node(data, front_, back_);
    if (size_ == 0) {
        front_ = back_;
        front_->next = back_;
        front_->prev = back_;
        back_->next = front_;
        back_->prev = front_;
    }
    ++size_;    
}

template<typename DataType>
inline void DLList<DataType>::PushFront(DataType&& data) {
    front_ = new Node(std::move(data), front_, back_);
    if (size_ == 0) {
        back_ = front_;
        back_->next = front_;
        back_->prev = front_;
        front_->next = back_;
        front_->prev = back_;
    }
    ++size_;
}

template<typename DataType>
inline void DLList<DataType>::PushFront(const DataType& data) {
    front_ = new Node(data, front_, back_);
    if (size_ == 0) {
        back_ = front_;
        back_->next = front_;
        back_->prev = front_;
        front_->next = back_;
        front_->prev = back_;
    }
    ++size_;    
}

template<typename DataType>
inline void DLList<DataType>::PopBack() {
    if (IsEmpty()) {
        return;
    }
    if (size_ == 1) {
        delete back_;
        back_ = nullptr;
        front_ = nullptr;
    }
    else {
        NodePtr back_prev = back_->prev;
        back_prev->next = back_->next;
        back_->next->prev = back_prev;
        delete back_;
        back_ = back_prev;
    }
    --size_;
}

template<typename DataType>
inline void DLList<DataType>::PopFront() {
    if (IsEmpty()) {
        return;
    }
    if (size_ == 1) {
        delete front_;
        back_ = nullptr;
        front_ = nullptr;
    }
    else {
        NodePtr front_next = front_->next;
        front_next->prev = front_->prev;
        front_->prev->next = front_next;
        delete front_;
        front_ = front_next;
    }
    --size_;
}

template<typename DataType>
inline DataType& DLList<DataType>::Back() {
    return IsEmpty() ? empty_ : back_->data;
}

template<typename DataType>
inline DataType& DLList<DataType>::Front() {
    return IsEmpty() ? empty_ : front_->data;
}

template<typename DataType>
template<typename OperationFnc>
inline void DLList<DataType>::FromBack(OperationFnc& operation_fnc) {
    if (IsEmpty()) {
        return;
    }
    NodePtr index = back_;
    do {
        operation_fnc(index);
        index = index->prev;
    } while (index != back_);
}

template<typename DataType>
template<typename OperationFnc>
inline void DLList<DataType>::FromFront(OperationFnc& operation_fnc) {
    if (IsEmpty()) {
        return;
    }
    NodePtr index = front_;
    do {
        operation_fnc(index);
        index = index->next;
    } while (index != front_);
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
    NodePtr index = front_;
    do {
        print_fnc("[");
        print_fnc(index->data);
        print_fnc("]");
        if (index->next != front_) {
            print_fnc("<=>");
        }
        index = index->next;
    } while (index != front_);
}

#endif

