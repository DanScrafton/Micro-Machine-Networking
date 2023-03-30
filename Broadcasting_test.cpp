#include <iostream>
#include <SFML/Network.hpp>

bool check_server_tcp_port(sf::IpAddress ip_address,unsigned short tcp_port)
{
    sf::TcpSocket tcp_socket;
    sf::Time timeout = sf::microseconds(2);
    sf::Socket::Status status = tcp_socket.connect(ip_address,tcp_port,timeout);
    tcp_socket.disconnect();
    if(status == sf::Socket::Done)
    {
        return true;
    }
    return false;
}

//int main(int argc, const char *argv[])
//{
//unisgined short port 4300;
//if (check_server_tcp_port(sf::IpAddress::LocalHost, port))
//{
//std::cout<"Port " << port << " is listening\n";
//}
//else
//{
//std::cout<< "Port "<< port<< "isn't listening\n";
//}
//return 0;
//}
