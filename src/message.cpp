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
    os << "\n"
       << sender << " -> " << receiver;
    os << "\n"
       << "message type: " << type;
    os << "\n"
       << "message time: " << time << "\n";
    os << "***************************\n";
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
       << this->get_sender() << " -> " << this->get_receiver();
    os << "\n message type: " << this->get_type();
    os << "\n message time: " << this->get_time();
    os << "\n text: " << text << "\n";
    os << "***************************\n";
}

std::string TextMessage::get_text()
{
    return text;
}

VoiceMessage::VoiceMessage(std::string _sender, std::string _receiver)
    : VoiceMessage::Message("voice", _sender, _receiver)
{
    voice.push_back('a' + static_cast<unsigned char>(rand() % 26));
    voice.push_back('a' + static_cast<unsigned char>(rand() % 26));
    voice.push_back('a' + static_cast<unsigned char>(rand() % 26));
    voice.push_back('a' + static_cast<unsigned char>(rand() % 26));
    voice.push_back('a' + static_cast<unsigned char>(rand() % 26));
}

void VoiceMessage::print(std::ostream& os) const
{
    os << "***************************";
    os << "\n"
       << this->get_sender() << " -> " << this->get_receiver();
    os << "\n message type: " << this->get_type();
    os << "\n message time: " << this->get_time();
    os << "\n voice: ";
    for (auto x : voice)
        os << static_cast<int>(x) << " ";
    os << "\n";
    os << "***************************\n";
}

std::vector<unsigned char> VoiceMessage::get_voice()
{
    return voice;
}
