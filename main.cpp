#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "server.h"

int main(int argc, char* argv[])
{
    try
    {
        std::string port;
        // Check command line arguments.
        if (argc < 2)
        {
            std::cerr << "Enter port:" << std::endl;
            std::cin >> port;
        } else {
            port = argv[1];
        }

        // Initialise the server.
        http::server::server s(argv[1]);

        // Run the server until stopped.
        s.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}