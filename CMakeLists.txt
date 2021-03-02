cmake_minimum_required(VERSION 3.17)
project(DS_C_ C)

set(CMAKE_C_STANDARD 99)

add_executable(PrintN algorithm/PrintN.c)
add_executable(main main.c)
add_executable(polynomial algorithm/polynomial.c)
add_executable(MaxSubseqSum algorithm/MaxSubseqSum.c)
add_executable(SeqStack stack/SeqStack.c)
add_executable(SeqQueue queue/SeqQueue.c)
add_executable(LinkList linearlist/LinkList.c)
add_executable(LinearDyna linearlist/LinearDyna.c)

add_executable(LinkListHead linearlist/LinkListHead.c)
add_executable(LinearList linearlist/LinearList.c)
add_executable(LinkedList algorithm/LinkedList.c)
add_executable(Test test/Test.c)
add_executable(TestOne test/TestOne.c)