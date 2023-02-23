#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <cmath>
#include <iostream>
#include <thread>
#include <vector>
//#include "My_Class.h"

void Server()
{
    sf::TcpListener listener;
    sf::Socket::Status status;
    status = listener.listen(4300);

    if(status != sf::Socket::Done)
    {
    std::cout<< "Error Listening\n";
    return;
    }
    sf::TcpSocket socket;
    status = listener.accept(socket); // blocking

    if(status != sf::Socket::Done)
    {
    std::cout<<"Error accepting\n";
    return;
    }

    sf::Packet packet;
    status = socket.receive(packet);

    if(status != sf::Socket::Done)
    {
    std::cout<<"Error recieving\n";
    return;
    }

    std::string message;
    packet >> message;
    std::cout<<message;
    packet.clear();
    packet << "servermsg";
    status = socket.send(packet);
    if(status != sf::Socket::Done)
    {
    std::cout<<"Error sending\n";
    return;
    }
}

void Client()
{
    sf::TcpSocket socket;
    socket.connect("localhost", 4300);
    sf::Packet packet;
    packet << "Hi\n";
    socket.send(packet);
    packet.clear();
    socket.receive(packet);
    std::string msg;
    packet >> msg;
    std::cout << msg;
}

int main()
{
    srand(time(NULL));
    std::thread serverThread(&Server);
    std::this_thread::sleep_for(std::chrono::microseconds(10));
    Client();
    serverThread.join();
//    std::thrsrand(time(NULL));
//    std::thread t(Hello);
//    t.join();
//
//    std::vector<std::thread>threads;
//  srand(time(NULL));
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

    //Loop loop;
    //std::thread tLoop(&Loop::run, &loop);
    //std::thread tStop([&loop]{
      //  std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10000));
       // loop.hasToStop = true;
    //});
    //tStop.detach();

    //tLoop.join();
    //return 0;  for(int i = 0; i<5; ++i)
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

   // Loop loop;
    //std::thread tLoop(&Loop::run, &loop);
   // std::thread tStop([&loop]{
    //    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10000));
     //   loop.hasToStop = true;
    //});
   // tStop.detach();

    //tLoop.join();
    //return 0;ead t(Hello);
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

    //Loop loop;
    //std::thread tLoop(&Loop::run, &loop);
    //std::thread tStop([&loop]{
    //    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 10000));
    //    loop.hasToStop = true;
    //});
    //tStop.detach();

    //tLoop.join();
    return 0;
}
