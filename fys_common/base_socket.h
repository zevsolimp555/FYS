#pragma once


class base_socket
{
public:
    base_socket();
    base_socket(base_socket&& s);
    virtual ~base_socket();

    socket_t get_sd() const { return sd_; }
    bool is_valid() const { return (sd_ != invalid_socket_t); }

    // TODO(zhord): fix type conversion from size_t -> ssize_t
    ssize_t receive_all(void* buffer, size_t buffer_len, size_t data_len);
    ssize_t send_all(const void* buffer, size_t buffer_len);

    base_socket& operator= (base_socket&& s);
    operator socket_t() { return sd_; }

protected:
    virtual ssize_t receive(void* buffer, size_t buffer_len);
    virtual ssize_t send(const void* buffer, size_t buffer_len);

private:
    base_socket(const base_socket&) = delete;
    base_socket& operator= (const base_socket&) = delete;

protected:
    socket_t sd_;
};