#include "request_handler.h"
#include <fstream>
#include <sstream>
#include "reply.h"

namespace http {
    namespace server {

        void request_handler::handle_request(const std::string &path, reply &rep) {
            std::string request_path;
            if (!url_decode(path, request_path)) {
                return;
            }

            std::string full_path = "." + request_path;
            std::ifstream is(full_path.c_str(), std::ios::in | std::ios::binary);
            if (!is) {
                rep = reply::stock_reply(reply::not_found);
                return;
            }

            rep.status = reply::ok;
            char buf[512];
            while (is.read(buf, sizeof(buf)).gcount() > 0)
                rep.content.append(buf, is.gcount());
        }

        bool request_handler::url_decode(const std::string &in, std::string &out) {
            out.clear();
            out.reserve(in.size());
            for (std::size_t i = 0; i < in.size(); ++i) {
                if (in[i] == '%') {
                    if (i + 3 <= in.size()) {
                        int value = 0;
                        std::istringstream is(in.substr(i + 1, 2));
                        if (is >> std::hex >> value) {
                            out += static_cast<char>(value);
                            i += 2;
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                } else if (in[i] == '+') {
                    out += ' ';
                } else {
                    out += in[i];
                }
            }
            return true;
        }

        request_handler::request_handler() {

        }

    } // namespace server
} // namespace http