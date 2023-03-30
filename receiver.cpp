#include "receiver.h"
#include "util.h"
#include <chrono>
#include <cstring>
#include <iostream>
#include <sstream>
#include <thread>

Receiver::Receiver(std::shared_ptr<sf::TcpSocket> s,
        Queue<std::string> &q):
    socket_(s),
    queue_(q)
{
}

void Receiver::recv_loop()
{
    char buffer[256];
    {
        std::stringstream ss;
        ss << socket_->getRemoteAddress() << ":" << socket_->getRemotePort() << std::endl;
        std::cout << ss.str();
    }
    sf::IpAddress sender = socket_->getRemoteAddress();
    while(1)
    {
        std::memset(buffer, 0, 256);
        std::size_t received;
        sf::Socket::Status status;
        // TODO receive a message here
        //return status code
        status = socket_->receive(buffer, 256, received);
        if (status != sf::Socket::Done)
        {
            // TODO: hanlde error
        }
        std::cout<<"Recieved"<<received<<"bytes from "<< sender << " on port" << TCP_PORT << std::endl;
        {
            std::stringstream ss;
            ss << "Received: \"" << buffer << "\", " << received << " bytes." << std::endl;
            std::cout << ss.str();
        }
        queue_.push(std::string(buffer));
    }
}

