#include "Server.h"
#include "accepter.h"
#include "queue.h"
#include "list.h"
#include "receiver.h"
#include "util.h"
#include <SFML/Network.hpp>
#include <iostream>
#include <thread>


void Server::run()
{
    Queue<std::string> queue;
    List<std::shared_ptr<sf::TcpSocket>> sockets;
    // TODO launch an accepter thread.
    std::thread(Accepter(queue, sockets)).detach();
    while(1)
    {
        std::string s = queue.pop();
        std::cout << "Main read: \"" << s << "\"\n";
        // TODO send to all in sockets. Be careful to synchronise.
        auto send_to_one = [&s] (std::shared_ptr<sf::TcpSocket> socket) {
            sf::Socket::Status status = socket->send(s.c_str(), s.size() + 1);
            // TODO error handling
            if (status != sf::Socket::Done)
            {
                std::cout << "Error sending\n";
                return;
            }
        };
        sockets.for_each(send_to_one);
    }
    return;
}
