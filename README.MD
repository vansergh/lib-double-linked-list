```
==203194== Memcheck, a memory error detector
==203194== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==203194== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==203194== Command: ./double-linked-list
==203194==
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
> Clear
> Print: List is empty
> Back: 0
> Front: 0
> Size: 0
> Empty: Yes
==============================
==203194==
==203194== HEAP SUMMARY:
==203194==     in use at exit: 0 bytes in 0 blocks
==203194==   total heap usage: 15 allocs, 15 frees, 74,040 bytes allocated
==203194==
==203194== All heap blocks were freed -- no leaks are possible
==203194==
==203194== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```