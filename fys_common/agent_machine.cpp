#include "stdafx.h"
#include "agent_machine.h"


agent_machine::agent_machine()
{
}

agent_machine::agent_machine(const std::wstring& login, const std::wstring& password)
    : login_(login)
    , password_(password)
{
}

agent_machine::agent_machine(const agent_machine& am)
    : login_(am.login_)
    , password_(am.password_)
{
}

agent_machine::agent_machine(agent_machine&& am)
    : login_(std::move(am.login_))
    , password_(std::move(am.password_))
{
}

agent_machine::~agent_machine()
{
}

agent_machine& agent_machine::operator= (const agent_machine& am)
{
    if (this != &am)
    {
        login_ = am.login_;
        password_ = am.password_;
    }

    return *this;
}

agent_machine& agent_machine::operator= (agent_machine&& am)
{
    if (this != &am)
    {
        login_ = std::move(am.login_);
        password_ = std::move(am.password_);
    }

    return *this;
}

std::wstring agent_machine::get_login() const
{
    return login_;
}

std::wstring agent_machine::get_password() const
{
    return password_;
}


void agent_machine::set_login(const std::wstring& login)
{
    login_.assign(login);
}

void agent_machine::set_password(const std::wstring& password)
{
    password_.assign(password);
}