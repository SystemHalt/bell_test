#include "Connection.h"

#include "Poco/Net/TCPServer.h"
#include "Poco/Net/TCPServerParams.h"
#include "Poco/Net/TCPServerConnectionFactory.h"

static constexpr Poco::UInt16 PORT = 28888;

void RunTcpServer() {
    using namespace Poco::Net;

    ServerSocket socket(PORT);

    TCPServerParams *params = new TCPServerParams();
    params->setMaxThreads(1);
    params->setMaxQueued(2);
    params->setThreadIdleTime(10);

    TCPServer server{new TCPServerConnectionFactoryImpl<TcpConnection>(), socket, params};

    server.start();

    while (true);
}

int main() {

    RunTcpServer();

    return 0;
}