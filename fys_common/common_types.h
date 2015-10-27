#pragma once

#include <cstdint>
#include <cstddef>

typedef signed long ssize_t;


#ifdef _WIN32

    typedef SOCKET socket_t;

    #define invalid_socket_t (INVALID_SOCKET)
    #define close_socket_t(s) if ((s) != invalid_socket_t) ::closesocket(s); 

#elif __linux__

    // TODO(zhord): linux typedefs & defines 

#endif