#include "stdafx.h"
#include "agent_machine_manager.h"


agent_machine_manager agent_machine_manager::instance_;
uint64_t agent_machine_manager::next_machine_id_ = 1;

agent_machine_manager& agent_machine_manager::instance()
{
    return instance_;
}


agent_machine_manager::agent_machine_manager()
{
}

agent_machine_manager::~agent_machine_manager()
{
}

bool agent_machine_manager::add_machine(const agent_machine& am)
{
    bool added = false;

    if (!is_machine_exist(am))
    {
        machines_[get_next_id()] = am;
        added = true;
    }

    return added;
}

void agent_machine_manager::remove_machine(const agent_machine& am)
{
    auto machine_it = std::find_if(machines_.begin(), machines_.end(),
        [&am](const agent_machines_t::value_type& machine)
    {
        return (am == (machine.second));
    });

    if (machine_it != machines_.end())
    {
        relesed_ids_.push_back((*machine_it).first);
        machines_.erase(machine_it);
    }
}

void agent_machine_manager::remove_machine_by_id(uint64_t id)
{
    if (is_machine_exist(id))
    {
        machines_.erase(id);
        relesed_ids_.push_back(id);
    }
}

void agent_machine_manager::remove_machine_by_login(const std::wstring& login)
{
    agent_machine* machine = get_machine_by_login(login);
    
    if (machine != nullptr)
        remove_machine((*machine));
}

bool agent_machine_manager::is_machine_exist(const agent_machine& am) const
{
    auto machine_cit = std::find_if(machines_.begin(), machines_.end(),
        [&am](const agent_machines_t::value_type& machine)
    {
        return (am == (machine.second));
    });

    return (machine_cit != machines_.end());
}

bool agent_machine_manager::is_machine_exist(uint64_t id) const
{
    return (get_machine_by_id(id) != nullptr);
}

bool agent_machine_manager::is_machine_exist(const std::wstring& login) const
{
    return (get_machine_by_login(login) != nullptr);
}

agent_machine* agent_machine_manager::get_machine_by_id(uint64_t id) const
{
    agent_machine* machine = nullptr;

    auto machine_cit = machines_.find(id);
    
    if (machine_cit != machines_.end())
        machine = const_cast<agent_machine*>(&(*machine_cit).second);

    return machine;
}

agent_machine* agent_machine_manager::get_machine_by_login(const std::wstring& login) const
{
    agent_machine* machine = nullptr;

    auto machine_cit = std::find_if(machines_.begin(), machines_.end(),
        [&login](const agent_machines_t::value_type& am)
    {
        auto& acc_info = am.second.get_account_information();
        return (login.compare(acc_info.get_login()) == 0);
    });

    if (machine_cit != machines_.end())
        machine = const_cast<agent_machine*>(&(*machine_cit).second);

    return machine;
}

uint64_t agent_machine_manager::get_next_id()
{
    uint64_t next_id = 0;

    if (relesed_ids_.empty())
    {
        next_id = next_machine_id_++;
    }
    else
    {
        next_id = relesed_ids_.front();
        relesed_ids_.pop_front();
    }

    return next_id;
}