#include "user.h"

User::User(std::string _username, std::string _private_key, Server* _server)
    : server { _server }
{
    username = _username;
    private_key = _private_key;
}

std::string User::get_username()
{
    return username;
}

bool User::send_text_message(std::string text, std::string receiver){
    TextMessage* msg {new TextMessage(text,username, receiver)};
    std::string signature = crypto::signMessage(private_key, text);
    return server->create_message(msg,signature);
}

bool User::send_voice_message(std::string receiver){
    VoiceMessage* msg {new VoiceMessage(username, receiver)};
    std::vector<unsigned char> x {msg->get_voice()};
    std::string s(x.begin(), x.end());
    std::string signature = crypto::signMessage(private_key, s);
    return server->create_message(msg,signature);
}