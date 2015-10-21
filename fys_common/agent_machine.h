#pragma once

#include "account_information.h"


class agent_machine
{
public:
    agent_machine();
    agent_machine(const account_information& acc_info);
    agent_machine(const agent_machine& am);
    agent_machine(agent_machine&& am);
    virtual ~agent_machine();

    const account_information& get_account_information() const;
    void set_account_information(const account_information& acc_info);

    agent_machine& operator= (const agent_machine& am);
    agent_machine& operator= (agent_machine&& am);

protected:
    account_information acc_info_;
};