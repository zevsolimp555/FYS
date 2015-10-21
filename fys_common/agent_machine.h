#pragma once


class agent_machine
{
public:
    agent_machine();
    agent_machine(const std::wstring& login, const std::wstring& password);
    agent_machine(const agent_machine& am);
    agent_machine(agent_machine&& am);
    virtual ~agent_machine();

    std::wstring get_login() const;
    std::wstring get_password() const;

    void set_login(const std::wstring& login);
    void set_password(const std::wstring& password);

    agent_machine& operator= (const agent_machine& am);
    agent_machine& operator= (agent_machine&& am);

protected:
    // TODO(zhord): move this to 'account_information' class;
    std::wstring login_;
    std::wstring password_;
};