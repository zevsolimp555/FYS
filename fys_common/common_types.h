#pragma once

#include <cstdint>
#include <cstddef>
#include <sys/types.h>


#ifdef _WIN32

typedef intptr_t  ssize_t;
#define SSIZE_MAX INT_MAX

typedef SOCKET socket_t;
#define invalid_socket_t (INVALID_SOCKET)
#define close_socket_t(s) if ((s) != invalid_socket_t) ::closesocket((s)); 

#elif __linux__

    // TODO(zhord): linux typedefs & defines 

#endif