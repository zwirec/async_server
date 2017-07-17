#ifndef HTTP_REQUEST_PARSER_HPP
#define HTTP_REQUEST_PARSER_HPP

#include <tuple>
#include <string>
#include <regex>

namespace http {
    namespace server {

        class request_parser {
        public:
            request_parser() {

            }

            template<typename InputIterator>
            std::string parse(InputIterator begin, InputIterator end) {
                std::regex regex(R"(GET ([^\s]*) )");
                std::smatch match;
                std::string data(begin, end);
                std::regex_search(data, match, regex);
                return match[1].str();
            }

        private:
        };

    } // namespace server
} // namespace http

#endif // HTTP_REQUEST_PARSER_HPP