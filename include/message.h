#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>

class Message {
public:

    Message(std::string, std::string, std::string);
    Message();
    std::string get_type() const;
    std::string get_sender() const;
    std::string get_receiver() const;
    std::string get_time() const;
    
private:
    std::string type;
    std::string sender;
    std::string receiver;
    std::string time;
};
#endif // MESSAGE_H