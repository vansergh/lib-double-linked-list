#include <iostream>
#include "../lib/dll.hpp"

void TestDLListInt() {
    auto print_fnc{
        [](const auto& item) {
            std::cout << item;
        }
    };

    DLList<int> list;
    std::cout << "==============================\n";
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PushBack: 1, 7, 9, 12" << std::endl;
    list.PushBack(1);
    list.PushBack(7);
    list.PushBack(9);
    list.PushBack(12);
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopFront" << std::endl;
    list.PopFront();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack (list is empty)" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopFront (list is empty)" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PushFront: 1, 7, 9, 12, 17" << std::endl;
    list.PushFront(1);
    list.PushFront(7);
    list.PushFront(9);
    list.PushFront(12);
    list.PushFront(17);
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PushFront: 1, PushBack: 9, 12" << std::endl;
    list.PushFront(1);
    list.PushBack(9);
    list.PushBack(12);
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    bool from_front_first = true;
    auto from_front{
        [&from_front_first](const auto& node) {
            if (!from_front_first) {
                std::cout << ", ";
            }
            from_front_first = false;
            std::cout << node->GetData();
        }
    };
    bool from_back_first = true;
    auto from_back{
        [&from_back_first](const auto& node) {
            if (!from_back_first) {
                std::cout << ", ";
            }
            from_back_first = false;
            std::cout << node->GetData();
        }
    };
    std::cout << "> FromFront: ";
    list.FromFront(from_front);
    std::cout << std::endl;
    std::cout << "> FromBack: ";
    list.FromBack(from_back);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Clear" << std::endl;
    list.Clear();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
}

void TestDLListString() {
    using namespace std::literals;
    auto print_fnc{
        [](const auto& item) {
            std::cout << item;
        }
    };

    DLList<std::string> list;
    std::cout << "==============================\n";
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PushBack: cow, cat, dog, arrow" << std::endl;
    list.PushBack("cow"s);
    list.PushBack("cat"s);
    list.PushBack("dog"s);
    list.PushBack("arrow"s);
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopFront" << std::endl;
    list.PopFront();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopBack (list is empty)" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PopFront (list is empty)" << std::endl;
    list.PopBack();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PushFront: fox, bison, dog, cat, elephant" << std::endl;
    list.PushFront("fox"s);
    list.PushFront("bison"s);
    list.PushFront("dog"s);
    list.PushFront("cat"s);
    list.PushFront("elephant"s);
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> PushFront: fish, PushBack: dolphin, shark" << std::endl;
    list.PushFront("fish"s);
    list.PushBack("dolphin"s);
    list.PushBack("shark"s);
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    bool from_front_first = true;
    auto from_front{
        [&from_front_first](const auto& node) {
            if (!from_front_first) {
                std::cout << ", ";
            }
            from_front_first = false;
            std::cout << node->GetData();
        }
    };
    bool from_back_first = true;
    auto from_back{
        [&from_back_first](const auto& node) {
            if (!from_back_first) {
                std::cout << ", ";
            }
            from_back_first = false;
            std::cout << node->GetData();
        }
    };
    std::cout << "> FromFront: ";
    list.FromFront(from_front);
    std::cout << std::endl;
    std::cout << "> FromBack: ";
    list.FromBack(from_back);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Clear" << std::endl;
    list.Clear();
    std::cout << "> Print: ";
    list.Print(print_fnc);
    std::cout << std::endl;
    std::cout << "> Back: " << list.Back() << std::endl;
    std::cout << "> Front: " << list.Front() << std::endl;
    std::cout << "> Size: " << list.Size() << std::endl;
    std::cout << "> Empty: " << (list.IsEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "==============================\n";
}

int main() {
    
        std::cout << "//////////////////////////////\n";
        std::cout << "// Scalar test              //\n";
        std::cout << "//////////////////////////////\n\n";
        TestDLListInt();
        std::cout << "\n//////////////////////////////\n";
        std::cout << "// Class (std::string) test //\n";
        std::cout << "//////////////////////////////\n\n";
        TestDLListString();
    
    return 0;
}




