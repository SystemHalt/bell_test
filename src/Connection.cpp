#include "Connection.h"

#include <algorithm>
#include <iostream>
#include <string>

void TcpConnection::run() {
    Poco::Net::StreamSocket &ss = socket();

    try {
        ss.sendBytes(HELLO_MESSAGE.c_str(), HELLO_MESSAGE.size());

        std::string buffer(BUFFER_SIZE, '\0');

        while (true) {
            int size = ss.receiveBytes(buffer.data(), buffer.size());

            reverseString(buffer, size);

            ss.sendBytes(buffer.data(), size);
        }
    } catch (Poco::Exception &e) {
        std::cerr << "Reverse server error: " << e.displayText() << std::endl;
    }
}

void TcpConnection::reverseString(std::string& str, std::size_t maxSize) {
    if (str.size() == 0 || maxSize == 0) {
        return;
    }

    auto id  = str.find('\n', maxSize - 1);
    auto end = str.begin() + std::min(id, maxSize);
    std::reverse(str.begin(), end);
}