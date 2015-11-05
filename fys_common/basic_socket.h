#pragma once


class basic_socket
{
public:
    basic_socket();
    basic_socket(basic_socket&& s);
    virtual ~basic_socket();

    socket_t get_sd() const { return sd_; }
    bool is_valid() const { return (sd_ != invalid_socket_t); }

    ssize_t receive(void* buffer, ssize_t buffer_size);
    ssize_t send(const void* buffer, ssize_t buffer_size);

    basic_socket& operator= (basic_socket&& s);
    operator socket_t() { return sd_; }

private:
    basic_socket(const basic_socket&) = delete;
    basic_socket& operator= (const basic_socket&) = delete;

protected:
    socket_t sd_;
};
