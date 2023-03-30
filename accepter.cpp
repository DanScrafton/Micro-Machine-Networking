#include "accepter.h"
#include "receiver.h"
#include "util.h"
#include <iostream>
#include <sstream>
#include <thread>

Accepter::Accepter(Queue<std::string>& q, List<std::shared_ptr<sf::TcpSocket>>& s):
    queue_(q),
    socket_(s)
{}

void Accepter::operator()()
{
    sf::TcpListener listener;

    if (listener.listen(TCP_PORT) != sf::Socket::Done)
    {
    std::cerr<<"Error listening to port accepter\n";
    return;
    }
    // TODO the listener has to listen.
    std::cout << "Bound to port\n";
    unsigned short userid = 0;
    // randomise user id
    //send this to player
    while (true)
    {
        std::shared_ptr<sf::TcpSocket> socket = std::make_shared<sf::TcpSocket>();
        // TODO accept a connection on socket
        sf::Socket::Status status = listener.accept(*socket);
        // TODO: handle error
//        if ()
        socket_.push(socket);
        std::stringstream ss;
        ss << "Accepted a connection from: "
            << socket->getRemoteAddress()
            << ":"
            << socket->getRemotePort()
            << std::endl;
        std::cout << ss.str();
        std::shared_ptr<Receiver> receiver = std::make_shared<Receiver>(socket, queue_);
        // TODO launch a thread to receive with the receiver
        std::thread(&Receiver::recv_loop, receiver).detach();
    }
}

