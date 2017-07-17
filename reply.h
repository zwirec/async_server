#ifndef HTTP_REPLY_HPP
#define HTTP_REPLY_HPP

#include <string>
#include <vector>
#include <boost/asio.hpp>
#include "header.h"

namespace http {
    namespace server {

        struct reply {
            enum status_type {
                ok = 200,
                not_found = 404,
            } status;

            std::string content;

            std::vector<boost::asio::const_buffer> to_buffers();

            std::vector<header> headers;

            static reply stock_reply(status_type status);
        };

    } // namespace server
} // namespace http

#endif // HTTP_REPLY_HPP