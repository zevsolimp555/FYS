#include "stdafx.h"
#include "account_information.h"


account_information::account_information()
{
}

account_information::account_information(const std::wstring& login, const std::wstring& password)
    : login_(login)
    , password_(password)
{
}

account_information::account_information(const account_information& ai)
    : login_(ai.login_)
    , password_(ai.password_)
{
}

account_information::account_information(account_information&& ai)
    : login_(std::move(ai.login_))
    , password_(std::move(ai.password_))
{
}

account_information::~account_information()
{
}

account_information& account_information::operator= (const account_information& ai)
{
    if (this != &ai)
    {
        login_ = ai.login_;
        password_ = ai.password_;
    }

    return *this;
}

account_information& account_information::operator= (account_information&& ai)
{
    if (this != &ai)
    {
        login_ = std::move(ai.login_);
        password_ = std::move(ai.password_);
    }

    return *this;
}

const std::wstring& account_information::get_login() const
{
    return login_;
}

const std::wstring& account_information::get_password() const
{
    return password_;
}

void account_information::set_login(const std::wstring& login)
{
    login_ = login;
}

void account_information::set_password(const std::wstring& password)
{
    password_ = password;
}