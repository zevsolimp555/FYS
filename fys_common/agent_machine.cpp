#include "stdafx.h"
#include "agent_machine.h"


agent_machine::agent_machine()
{
}

agent_machine::agent_machine(const account_information& acc_info)
    : acc_info_(acc_info)
{
}

agent_machine::agent_machine(const agent_machine& am)
    : acc_info_(am.acc_info_)
{
}

agent_machine::agent_machine(agent_machine&& am)
    : acc_info_(std::move(am.acc_info_))
{
}

agent_machine::~agent_machine()
{
}

agent_machine& agent_machine::operator= (const agent_machine& am)
{
    if (this != &am)
    {
        acc_info_ = am.acc_info_;
    }

    return *this;
}

agent_machine& agent_machine::operator= (agent_machine&& am)
{
    if (this != &am)
    {
        acc_info_ = std::move(am.acc_info_);
    }

    return *this;
}

const account_information& agent_machine::get_account_information() const
{
    return acc_info_;
}

void agent_machine::set_account_information(const account_information& acc_info)
{
    acc_info_ = acc_info;
}

bool agent_machine::operator== (const agent_machine& am) const
{
    bool equal = true;
    equal &= (acc_info_ == am.acc_info_);

    return equal;
}

bool agent_machine::operator!= (const agent_machine& am) const
{
    return !(*this == am);
}