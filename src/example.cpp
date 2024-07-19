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

void TestCopyMove() {
    using namespace std::literals;
    auto print_fnc{
        [](const auto& item) {
            std::cout << item;
        }
    };

    
    std::cout << "==============================\n";
    std::cout << "> Initialization\n";
    std::cout << "==============================\n";

    std::cout << "> DLList<std::string> list1 = DLList<std::string>({ \"hello\"s,\"world\"s }); // std::initializer_list&& <- move" << std::endl;
    DLList<std::string> list1 = DLList<std::string>({ "hello"s,"world"s });

    std::cout << "> DLList<std::string> list2 = DLList<std::string>({ \"BOSS\"s,\"OFFICE\"s },InitListPushType::BACK); // std::initializer_list&& <- move" << std::endl;
    DLList<std::string> list2 = DLList<std::string>({ "BOSS"s,"OFFICE"s }, InitListPushType::BACK);
    
    std::cout << "> DLList<std::string> list3 = {\"blue\"s,\"red\"s}; // std::initializer_list&& <- move" << std::endl;
    DLList<std::string> list3 = { "blue"s,"red"s };

    std::cout << "> DLList<std::string> list4({ \"cat\", \"dog\" }); // std::initializer_list&& <- move" << std::endl;
    DLList<std::string> list4({ "cat", "dog" });
    
    std::cout << "> DLList<std::string> list5({ \"1\", \"2\", \"3\", \"4\", \"5\" }, InitListPushType::FRONT); // std::initializer_list&& <- move" << std::endl;
    DLList<std::string> list5({ "1", "2", "3", "4", "5" }, InitListPushType::FRONT);

    std::cout << "> DLList<std::string> list6; // <- default empty constructor" << std::endl;
    DLList<std::string> list6;
    std::cout << "> list6.PushBack(\"one\");" << std::endl;
    std::cout << "> list6.PushBack(\"two\");" << std::endl;
    std::cout << "> list6.PushBack(\"five\");" << std::endl;
    std::cout << "> list6.PushFront(\"seven\");" << std::endl;
    std::cout << "> list6.PushBack(\"eleven\");" << std::endl;
    list6.PushBack("one");
    list6.PushBack("two");
    list6.PushBack("five");
    list6.PushFront("seven");
    list6.PushBack("eleven");
    std::cout << "==============================\n";
    std::cout << "> Print list1: ";list1.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list2: ";list2.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list3: ";list3.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list4: ";list4.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list5: ";list5.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list6: ";list6.Print(print_fnc);std::cout << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Copy\n";
    std::cout << "==============================\n";
    std::cout << "> Print list1: ";list1.Print(print_fnc);std::cout << std::endl;
    std::cout << "> {" << std::endl;
    std::cout << "> \tDLList<std::string> list_r1 = list1;" << std::endl;
    {
        DLList<std::string> list_r1 = list1;
        std::cout << "> \tPrint list_r1: ";list_r1.Print(print_fnc);std::cout << std::endl;
        std::cout << "> \tPrint list1: ";list1.Print(print_fnc);std::cout << std::endl;        
    }
    std::cout << "> }" << std::endl;
    std::cout << "> Print list1: ";list1.Print(print_fnc);std::cout << std::endl;
    std::cout << "> list_r1 deleted" << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Print list2: ";list2.Print(print_fnc);std::cout << std::endl;
    std::cout << "> DLList<std::string> list_r2(list2);" << std::endl;
    DLList<std::string> list_r2(list2);
    std::cout << "> Print list_r2: ";list_r2.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list2: ";list2.Print(print_fnc);std::cout << std::endl;
    std::cout << "> list_r2.Clear();" << std::endl;
    list_r2.Clear();
    std::cout << "> Print list_r2: ";list_r2.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list2: ";list2.Print(print_fnc);std::cout << std::endl;    
    std::cout << "==============================\n";    
    std::cout << "> Move\n";
    std::cout << "==============================\n";
    std::cout << "> Print list3: ";list3.Print(print_fnc);std::cout << std::endl;    
    std::cout << "> DLList<std::string> list_r3;" << std::endl;
    DLList<std::string> list_r3;
    std::cout << "> list_r3 = std::move(list3);" << std::endl;
    list_r3 = std::move(list3);
    std::cout << "> Print list3: ";list3.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list_r3: ";list_r3.Print(print_fnc);std::cout << std::endl;
    std::cout << "==============================\n";
    std::cout << "> Print list4: ";list4.Print(print_fnc);std::cout << std::endl;    
    std::cout << "> DLList<std::string> list_r4(std::move(list4));" << std::endl;
    DLList<std::string> list_r4(std::move(list4));
    std::cout << "> Print list4: ";list4.Print(print_fnc);std::cout << std::endl;
    std::cout << "> Print list_r4: ";list_r4.Print(print_fnc);std::cout << std::endl;
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
    std::cout << "\n//////////////////////////////\n";
    std::cout << "// Copy & Move test         //\n";
    std::cout << "//////////////////////////////\n\n";
    TestCopyMove();
    return 0;
}




