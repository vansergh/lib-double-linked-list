```
==105090== Memcheck, a memory error detector
==105090== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==105090== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==105090== Command: ./double-linked-list
==105090==
//////////////////////////////
// Scalar test              //
//////////////////////////////

==============================
> Back: 0
> Front: 0
> Size: 0
> Empty: Yes
==============================
> PushBack: 1, 7, 9, 12
> Print: [1]<=>[7]<=>[9]<=>[12]
> Back: 12
> Front: 1
> Size: 4
> Empty: No
==============================
> PopFront
> Print: [7]<=>[9]<=>[12]
> Back: 12
> Front: 7
> Size: 3
> Empty: No
==============================
> PopBack
> Print: [7]<=>[9]
> Back: 9
> Front: 7
> Size: 2
> Empty: No
==============================
> PopBack
> Print: [7]
> Back: 7
> Front: 7
> Size: 1
> Empty: No
==============================
> PopBack
> Print: List is empty
> Back: 0
> Front: 0
> Size: 0
> Empty: Yes
==============================
> PopBack (list is empty)
> Print: List is empty
> Back: 0
> Front: 0
> Size: 0
> Empty: Yes
==============================
> PopFront (list is empty)
> Print: List is empty
> Back: 0
> Front: 0
> Size: 0
> Empty: Yes
==============================
> PushFront: 1, 7, 9, 12, 17
> Print: [17]<=>[12]<=>[9]<=>[7]<=>[1]
> Back: 1
> Front: 17
> Size: 5
> Empty: No
==============================
> PushFront: 1, PushBack: 9, 12
> Print: [1]<=>[17]<=>[12]<=>[9]<=>[7]<=>[1]<=>[9]<=>[12]
> Back: 12
> Front: 1
> Size: 8
> Empty: No
==============================
> FromFront: 1, 17, 12, 9, 7, 1, 9, 12
> FromBack: 12, 9, 1, 7, 9, 12, 17, 1
> Back: 12
> Front: 1
> Size: 8
> Empty: No
==============================
> Clear
> Print: List is empty
> Back: 0
> Front: 0
> Size: 0
> Empty: Yes
==============================

//////////////////////////////
// Class (std::string) test //
//////////////////////////////

==============================
> Back:
> Front:
> Size: 0
> Empty: Yes
==============================
> PushBack: cow, cat, dog, arrow
> Print: [cow]<=>[cat]<=>[dog]<=>[arrow]
> Back: arrow
> Front: cow
> Size: 4
> Empty: No
==============================
> PopFront
> Print: [cat]<=>[dog]<=>[arrow]
> Back: arrow
> Front: cat
> Size: 3
> Empty: No
==============================
> PopBack
> Print: [cat]<=>[dog]
> Back: dog
> Front: cat
> Size: 2
> Empty: No
==============================
> PopBack
> Print: [cat]
> Back: cat
> Front: cat
> Size: 1
> Empty: No
==============================
> PopBack
> Print: List is empty
> Back:
> Front:
> Size: 0
> Empty: Yes
==============================
> PopBack (list is empty)
> Print: List is empty
> Back:
> Front:
> Size: 0
> Empty: Yes
==============================
> PopFront (list is empty)
> Print: List is empty
> Back:
> Front:
> Size: 0
> Empty: Yes
==============================
> PushFront: fox, bison, dog, cat, elephant
> Print: [elephant]<=>[cat]<=>[dog]<=>[bison]<=>[fox]
> Back: fox
> Front: elephant
> Size: 5
> Empty: No
==============================
> PushFront: fish, PushBack: dolphin, shark
> Print: [fish]<=>[elephant]<=>[cat]<=>[dog]<=>[bison]<=>[fox]<=>[dolphin]<=>[shark]
> Back: shark
> Front: fish
> Size: 8
> Empty: No
==============================
> FromFront: fish, elephant, cat, dog, bison, fox, dolphin, shark
> FromBack: shark, dolphin, fox, bison, dog, cat, elephant, fish
> Back: shark
> Front: fish
> Size: 8
> Empty: No
==============================
> Clear
> Print: List is empty
> Back:
> Front:
> Size: 0
> Empty: Yes
==============================

//////////////////////////////
// Copy & Move test         //
//////////////////////////////

==============================
> Initialization
==============================
> DLList<std::string> list1 = DLList<std::string>({ "hello"s,"world"s }); // std::initializer_list&& <- move
> DLList<std::string> list2 = DLList<std::string>({ "BOSS"s,"OFFICE"s },InitListPushType::BACK); // std::initializer_list&& <- move
> DLList<std::string> list3 = {"blue"s,"red"s}; // std::initializer_list&& <- move
> DLList<std::string> list4({ "cat", "dog" }); // std::initializer_list&& <- move
> DLList<std::string> list5({ "1", "2", "3", "4", "5" }, InitListPushType::FRONT); // std::initializer_list&& <- move
> DLList<std::string> list6; // <- default empty constructor
> list6.PushBack("one");
> list6.PushBack("two");
> list6.PushBack("five");
> list6.PushFront("seven");
> list6.PushBack("eleven");
==============================
> Print list1: [hello]<=>[world]
> Print list2: [BOSS]<=>[OFFICE]
> Print list3: [blue]<=>[red]
> Print list4: [cat]<=>[dog]
> Print list5: [5]<=>[4]<=>[3]<=>[2]<=>[1]
> Print list6: [seven]<=>[one]<=>[two]<=>[five]<=>[eleven]
==============================
> Copy
==============================
> Print list1: [hello]<=>[world]
> {
>       DLList<std::string> list_r1 = list1;
>       Print list_r1: [world]<=>[hello]
>       Print list1: [hello]<=>[world]
> }
> Print list1: [hello]<=>[world]
> list_r1 deleted
==============================
> Print list2: [BOSS]<=>[OFFICE]
> DLList<std::string> list_r2(list2);
> Print list_r2: [OFFICE]<=>[BOSS]
> Print list2: [BOSS]<=>[OFFICE]
> list_r2.Clear();
> Print list_r2: List is empty
> Print list2: [BOSS]<=>[OFFICE]
==============================
> Move
==============================
> Print list3: [blue]<=>[red]
> DLList<std::string> list_r3;
> list_r3 = std::move(list3);
> Print list3: List is empty
> Print list_r3: [blue]<=>[red]
==============================
> Print list4: [cat]<=>[dog]
> DLList<std::string> list_r4(std::move(list4));
> Print list4: List is empty
> Print list_r4: [cat]<=>[dog]
==============================
==105090==
==105090== HEAP SUMMARY:
==105090==     in use at exit: 0 bytes in 0 blocks
==105090==   total heap usage: 48 allocs, 48 frees, 75,648 bytes allocated
==105090==
==105090== All heap blocks were freed -- no leaks are possible
==105090==
==105090== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```