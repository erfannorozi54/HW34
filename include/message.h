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
    void virtual print(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream& os, const Message& c)
    {
        c.print(os);
        return os;
    }

private:
    std::string type;
    std::string sender;
    std::string receiver;
    std::string time;
};

class TextMessage : public Message {
public:
    TextMessage(std::string text, std::string sender, std::string receiver);
    void print(std::ostream&) const;
    std::string get_text();

private:
    std::string type;
    std::string sender;
    std::string receiver;
    std::string time;
    std::string text;
};
#endif // MESSAGE_H