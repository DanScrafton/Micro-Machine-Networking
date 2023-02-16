#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <cmath>
#include <iostream>
#include <thread>
#include <vector>


void run()
{
    std::cout << "Hi from thread.\n";
}

void Hello()
{
std::cout <<"Hello "<<
std::this_thread::get_id()<<std::endl;
}

int main()
{
    std::thread t(Hello);
    t.join();

    std::vector<std::thread>threads;
    for(int i = 0; i<5; ++i)
    {
        threads.push_back(std::thread(Hello));
        std::this_thread::sleep_for(std::chrono::microseconds(5));
    }

    for(auto& thread:threads)
    {
    thread.join();
    }


    return 0;
}
