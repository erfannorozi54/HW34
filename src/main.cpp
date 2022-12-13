#include <iostream>
#include <gtest/gtest.h>
#include <ctime>
#include "message.h"
#include "user.h"
#include "server.h"
#include "stl.h"


int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section
        // Message y {"text","erfan","amin"};
        // std::cout << y << std::endl;
        // TextMessage x{"Hello!!","erfan","amin"};
        // std::cout << x << std::endl;
        // VoiceMessage msg{"erfan","amin"};
        // std::cout << msg <<std::endl;
        // RSA* temp {crypto::createPrivateRSA("erfan")};
        // srd::cout << temp << std::endl;
        // Server server;
        // User david = server.create_user("david");
        // User jenifer = server.create_user("jenifer");
        // std::cout << server.get_public_keys()["david"] << std::endl;
        // bool result = david.send_text_message("hello jenifer", "jenifer");
        // std::cout << result << std::endl;
        // std::vector<int> x {2,3,1,2,3,1,1,45,6,4,3};
        // std::vector<int>::iterator y{};
        // y = std::find_if(x.begin(),x.end(),1);
        // if (y == x.end())
        //     std::cout << "Not found" << std::endl;
        // else
        //     std::cout << y - x.begin() << std::endl;
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}

bool f(int& x){
    
    return true;
}