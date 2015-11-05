#include "stdafx.h"
#include "basic_socket.h"


basic_socket::basic_socket()
{
    // TODO(zhord): review this (maybe better to create 2 methods: open(...) & close(...) ?)
    sd_ = ::socket(AF_INET, SOCK_STREAM, 0);
}

basic_socket::basic_socket(basic_socket&& s)
{
    sd_ = s.sd_;
    s.sd_ = invalid_socket_t;
}

basic_socket::~basic_socket()
{
    close_socket_t(sd_);
}

basic_socket& basic_socket::operator= (basic_socket&& s)
{
    sd_ = s.sd_;
    s.sd_ = invalid_socket_t;

    return *this;
}

ssize_t basic_socket::receive(void* buffer, ssize_t buffer_size)
{
    assert(buffer != nullptr);
    assert(buffer_size > 0);

    ssize_t total_received = 0;
    ssize_t n = 0;

    while (total_received < buffer_size && n != -1)
    {
        n = ::recv(sd_, static_cast<char*>(buffer) + total_received, buffer_size - total_received, 0);
        total_received += n;
    }

    return (n == -1) ? -1 : total_received;
}

ssize_t basic_socket::send(const void* buffer, ssize_t buffer_size)
{
    assert(buffer != nullptr);
    assert(buffer_size > 0);

    ssize_t total_sent = 0;
    ssize_t n = 0;
    
    while (total_sent < buffer_size && n != -1)
    {
        n = ::send(sd_, static_cast<const char*>(buffer) + total_sent, buffer_size - total_sent, 0);
        total_sent += n;
    }
    
    return (n == -1) ? -1 : total_sent;
}
