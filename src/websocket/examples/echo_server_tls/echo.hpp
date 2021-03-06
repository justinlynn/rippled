/*
 * Copyright (c) 2011, Peter Thorson. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the WebSocket++ Project nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL PETER THORSON BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef ECHO_SERVER_HANDLER_HPP
#define ECHO_SERVER_HANDLER_HPP

#include "../../src/websocketpp.hpp"
#include "../../src/interfaces/session.hpp"
#include <boost/shared_ptr.hpp>

#include <string>
#include <vector>

using websocketpp::session::server_ptr;
using websocketpp::session::server_handler;

namespace websocketecho {

class echo_server_handler : public server_handler {
public:
    // The echo server allows all domains is protocol free.
    void validate(server_ptr session) {}
    
    // an echo server is stateless. 
    // The handler has no need to keep track of connected clients.
    void on_fail(server_ptr session) {}
    void on_open(server_ptr session) {}
    void on_close(server_ptr session) {}
    
    // both text and binary messages are echoed back to the sending client.
        void on_message(server_ptr session,websocketpp::utf8_string_ptr msg) {
        std::cout << *msg << std::endl;
        session->send(*msg);
    }
    void on_message(server_ptr session,websocketpp::binary_string_ptr data) {
        session->send(*data);
    }
};

}

#endif // ECHO_SERVER_HANDLER_HPP
