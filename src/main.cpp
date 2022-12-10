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
        std::time_t x;
        time(&x);
        std::cout << std::ctime(&x) << "Hello" << std::endl;
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