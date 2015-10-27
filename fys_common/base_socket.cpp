#include "stdafx.h"
#include "base_socket.h"


base_socket::base_socket()
{
    sd_ = ::socket(AF_INET, SOCK_STREAM, 0);
}

base_socket::base_socket(base_socket&& s)
{
    sd_ = s.sd_;
    s.sd_ = invalid_socket_t;
}

base_socket::~base_socket()
{
    close_socket_t(sd_);
}

base_socket& base_socket::operator= (base_socket&& s)
{
    sd_ = s.sd_;
    s.sd_ = invalid_socket_t;

    return *this;
}

ssize_t base_socket::receive_all(void* buffer, size_t buffer_len, size_t data_len)
{
    size_t total_received = 0;
    ssize_t n = 0;

    while (total_received < data_len && total_received < buffer_len && n != -1)
    {
        n = receive(static_cast<char*>(buffer) + total_received, buffer_len - total_received);
        total_received += n;
    }

    return (n == -1) ? -1 : total_received;
}

ssize_t base_socket::send_all(const void* buffer, size_t buffer_len)
{
    size_t total_sent = 0;
    ssize_t n = 0;

    while (total_sent < buffer_len && n != -1)
    {
        n = send(static_cast<const char*>(buffer) + total_sent, buffer_len - total_sent);
        total_sent += n;
    }

    return (n == -1) ? -1 : total_sent;
}

ssize_t base_socket::receive(void* buffer, size_t buffer_len)
{
    return ::recv(sd_, static_cast<char*>(buffer), buffer_len, 0);
}

ssize_t base_socket::send(const void* buffer, size_t buffer_len)
{
    return ::send(sd_, static_cast<const char*>(buffer), buffer_len, 0);
}