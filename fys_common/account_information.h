#pragma once


class account_information
{
public:
    account_information();
    account_information(const std::wstring& login, const std::wstring& password);
    account_information(const account_information& ai);
    account_information(account_information&& ai);
    virtual ~account_information();

    const std::wstring& get_login() const;
    const std::wstring& get_password() const;

    void set_login(const std::wstring& login);
    void set_password(const std::wstring& password);

    account_information& operator= (const account_information& ai);
    account_information& operator= (account_information&& ai);

    bool operator== (const account_information& ai) const;
    bool operator!= (const account_information& ai) const;

protected:
    std::wstring login_;
    std::wstring password_;
};