#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

//struct Msg_Registration
//{
//sf::Uint8 msg_type = EMSgType::Registration;
//sf::Uint32 player_Id;
//std::string player_username;
//}
//
//struct Msg_Position
//{
//sf::Uint8 msg_type = EMsgType::Posistion;
//sf::Uint32 player_Id;
//sf::Vector2f position,velocity,acceleration;
//float player_orientation;
//}

class Server {
public:
    void run();


};


#endif // SERVER_H_INCLUDED
