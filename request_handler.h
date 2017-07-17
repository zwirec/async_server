#ifndef HTTP_REQUEST_HANDLER_HPP
#define HTTP_REQUEST_HANDLER_HPP

#include <string>

namespace http {
    namespace server {

        struct reply;
        struct request;

        class request_handler {
        public:
            request_handler(const request_handler &) = delete;

            request_handler();

            request_handler &operator=(const request_handler &) = delete;

            void handle_request(const std::string &req, reply &rep);

        private:
            static bool url_decode(const std::string &in, std::string &out);
        };

    } // namespace server
} // namespace http

#endif // HTTP_REQUEST_HANDLER_HPP