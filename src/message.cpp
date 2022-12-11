#include "message.h"
#include <ctime>

Message::Message(std::string _type, std::string _sender, std::string _receiver)
{
    type = _type;
    sender = _sender;
    receiver = _receiver;
    std::time_t currentTime;
    std::time(&currentTime);
    time = ctime(&currentTime);
    time.erase(time.find_last_not_of(" \n\r\t") + 1);
}

Message::Message()
    : Message("", "", "")
{
}

std::string Message::get_type() const
{
    return type;
}

std::string Message::get_sender() const
{
    return sender;
}

std::string Message::get_receiver() const
{
    return receiver;
}

std::string Message::get_time() const
{
    return time;
}

void Message::print(std::ostream& os) const
{
    os << "***************************";
    os << "/n" << sender << " -> " << receiver;
    os << "/n"
       << "message type: " << type;
    os << "/n"
       << "message time: " << time;
}

TextMessage::TextMessage(std::string _text, std::string _sender, std::string _receiver)
    : Message("text", _sender, _receiver)
{
    text = _text;
}

void TextMessage::print(std::ostream& os) const
{
    os << "***************************";
    os << "\n"
       << sender << " -> " << receiver;
    os << "\n message type: " << type;
    os << "\n message time: " << time;
    os << "\n text: " << text << "\n";
}

std::string TextMessage::get_text()
{
    return text;
}