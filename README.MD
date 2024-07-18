```
==197715== Memcheck, a memory error detector
==197715== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==197715== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==197715== Command: ./double-linked-list
==197715==
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
==197715==
==197715== HEAP SUMMARY:
==197715==     in use at exit: 0 bytes in 0 blocks
==197715==   total heap usage: 26 allocs, 26 frees, 74,592 bytes allocated
==197715==
==197715== All heap blocks were freed -- no leaks are possible
==197715==
==197715== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```