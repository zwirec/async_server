cmake_minimum_required(VERSION 3.7)
project(async_server)



set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)


set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.63 COMPONENTS date_time filesystem system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(async_server main.cpp connection.cpp connection.h connection_manager.cpp connection_manager.h header.h reply.cpp reply.h request.h request_handler.cpp request_handler.h request_parser.h server.cpp server.h)
    target_link_libraries(async_server ${Boost_LIBRARIES})
endif()

