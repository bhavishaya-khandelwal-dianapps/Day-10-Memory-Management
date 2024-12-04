//todo -- Memory Management -> Memory management is a method in the operating system to manage operations between main memory and disk during process execution. The main aim of memory management is to achieve efficient utilization of memory.  



//? Thread : A thread is a basic unit of CPU utilization. 
//* It comprises - 
//? A thread ID, 
//* A Program Counter -> Keeps track of the memory address of the next instruction to be executed in a program. 
//? A register set, 
//* A Stack


#include<bits/stdc++.h>
#include<thread>
#include<unistd.h>
using namespace std;


void taskA() {
    for(int i = 0 ; i < 10 ; i++) {
        sleep(1);
        printf("Task A: %d\n", i);
        fflush(stdout);
    }
}

void taskB() {
    for(int i = 0 ; i < 10 ; i++) {
        sleep(1);
        printf("Task B : %d\n", i);
        fflush(stdout);
    }
}

int main() {
    thread t1(taskA);
    thread t2(taskB);

    t1.join();
    t2.join();
}