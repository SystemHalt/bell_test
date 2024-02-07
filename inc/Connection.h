#pragma once

#include "Poco/Net/TCPServerConnection.h"

class TcpConnection : public Poco::Net::TCPServerConnection {

public:
    TcpConnection(const Poco::Net::StreamSocket &s)
        : Poco::Net::TCPServerConnection(s) {}

    void run() override;
private:
    static constexpr std::size_t BUFFER_SIZE = 255;
    const std::string HELLO_MESSAGE = "Welcome to POCO TCP server. Enter you string:\n";

    void reverseString(std::string& str, std::size_t maxSize);
};