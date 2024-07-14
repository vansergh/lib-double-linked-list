```
==203217== Memcheck, a memory error detector
==203217== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==203217== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==203217== Command: ./double-linked-list
==203217==
==============================
> Back: 0
> Front: 0
> Size: 0
> Empty: Yes
==============================
> PushBack: 1, 7, 9, 12, 17
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
> Print: [12]<=>[9]<=>[7]<=>[1]
> Back: 1
> Front: 12
> Size: 4
> Empty: No
==============================
> PushFront: 1, PushBack: 9, 12
> Print: [1]<=>[12]<=>[9]<=>[7]<=>[1]<=>[9]<=>[12]
> Back: 12
> Front: 1
> Size: 7
> Empty: No
==============================
> FromFront: 1, 12, 9, 7, 1, 9, 12
> FromBack: 12, 9, 1, 7, 9, 12, 1
> Back: 12
> Front: 1
> Size: 7
> Empty: No
==============================
> Clear
> Print: List is empty
> Back: 0
> Front: 0
> Size: 0
> Empty: Yes
==============================
==203217==
==203217== HEAP SUMMARY:
==203217==     in use at exit: 0 bytes in 0 blocks
==203217==   total heap usage: 15 allocs, 15 frees, 74,040 bytes allocated
==203217==
==203217== All heap blocks were freed -- no leaks are possible
==203217==
```