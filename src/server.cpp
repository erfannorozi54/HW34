#include "server.h"

std::vector<User> Server::get_users()
{
    return users;
}

std::map<std::string, std::string> Server::get_public_keys()
{
    return public_keys;
}

std::vector<Message*> Server::get_messages()
{
    return messages;
}

User Server::create_user(std::string _username)
{
    for (auto x : users)
        if (x.get_username() == _username)
            throw std::logic_error("Hello");
    std::string pu_key {}, pr_key {};
    crypto::generate_key(pu_key, pr_key);
    users.push_back(*(new User { _username, pr_key, this }));
    public_keys.insert({_username, pu_key});
    // std::cout << pu_key << std::endl;
    return users[users.size() - 1];
}

bool Server::create_message(Message* msg, std::string signature)
{
    if(msg->get_type() == "text"){
        if (public_keys.find(msg->get_sender()) != public_keys.end()){
            if (crypto::verifySignature(public_keys[msg->get_sender()], msg->get_text(), signature)) {
                if(std::find_if(users.begin(),users.end(),[msg](User u){return u.get_username()==msg->get_receiver();})!=users.end()){
                    messages.push_back(msg);
                    return true;
                }
            }
        }
        return false;
    }
    else{
        if (public_keys.find(msg->get_sender()) != public_keys.end()){
            std::vector<unsigned char> temp {msg->get_voice()};
            std::string x(temp.begin(),temp.end());
            if (crypto::verifySignature(public_keys[msg->get_sender()],x , signature)) {
                if(std::find_if(users.begin(),users.end(),[msg](User u){return u.get_username()==msg->get_receiver();})!=users.end()){
                    messages.push_back(msg);
                    return true;
                }
            }
        }
        return false;
    }
}

std::vector<Message*> Server::get_all_messages_from(std::string username){
    std::vector<Message *> x {};
    std::for_each(messages.begin(),messages.end(),[&x,username](Message* y){if(y->get_sender()==username)x.push_back(y);});
    return x;
    // auto temp = std::find_if(messages.begin(),messages.end(),);
}
std::vector<Message*> Server::get_all_messages_to(std::string username){
    std::vector<Message *> x {};
    std::for_each(messages.begin(),messages.end(),[&x,username](Message* y){if(y->get_receiver()==username)x.push_back(y);});
    return x;
}

std::vector<Message*> Server::get_chat(std::string user1, std::string user2){
    std::vector<Message *> x {};
    std::for_each(messages.begin(),messages.end(),[&x,user1,user2](Message* y){
        if((y->get_sender()==user1 && y->get_receiver()==user2)||(y->get_sender()==user2 && y->get_receiver()==user1) )
        x.push_back(y);});
    return x;
}