#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <cmath>
#include <iostream>
#include <thread>
#include <vector>
#include "My_Class.h"


void run()
{
    std::cout << "Hi from thread.\n";
}

void Hello()
{
    std::cout <<"Hello "<<
    std::this_thread::get_id()<<std::endl;
}

struct Print
{
    void print()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        std::cout << "Hi there\n";
    }
};

struct Loop
{
    bool hasToStop = false;
    void run()
    {
        while(!hasToStop);
        std::cout << "Loop is ending\n";
    }
};

int main()
{
    srand(time(NULL));
//    std::thread t(Hello);
//    t.join();
//
//    std::vector<std::thread>threads;
//    for(int i = 0; i<5; ++i)
//    {
//        threads.push_back(std::thread(Hello));
//        std::this_thread::sleep_for(std::chrono::microseconds(5));
//    }
//
//    for(auto& thread:threads)
//    {
//    thread.join();
//    }
//
//    My_Class my_obj(5);
//
//    std::thread t1{&My_Class::Do_Something
//    ,&my_obj
//    ,10 // parameter 1
//    ,-8 // parameter 2
//    ,56}; // parameter 3
//t1.join();

//    std::thread t([]{
//        std::cout << "Hi from thread\n";
//    });

//    Print print;

//    print.print();

//    std::thread t1(&Print::print, &print);
//    std::thread t1([&print]{print.print();});

//    t.join();
//    t1.join();

    Loop loop;
    std::thread tLoop(&Loop::run, &loop);
    std::thread tStop([&loop]{
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10000));
        loop.hasToStop = true;
    });
    tStop.detach();

    tLoop.join();
    return 0;
}
