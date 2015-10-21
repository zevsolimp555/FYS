#pragma once

#include "agent_machine.h"


class agent_machine_manager
{
    typedef std::map<uint64_t, agent_machine> agent_machines_t;

public:
    bool add_machine(const agent_machine& am);
    void remove_machine(const agent_machine& am);
    void remove_machine_by_id(uint64_t id);
    void remove_machine_by_login(const std::wstring& login);

    bool is_machine_exist(const agent_machine& am) const;
    bool is_machine_exist(uint64_t id) const;
    bool is_machine_exist(const std::wstring& login) const;

    agent_machine* get_machine_by_id(uint64_t id) const;
    agent_machine* get_machine_by_login(const std::wstring& login) const;
    
    static agent_machine_manager& instance();

private:
    agent_machine_manager();
    ~agent_machine_manager();

    uint64_t get_next_id();

private:
    static agent_machine_manager instance_;
    static uint64_t next_machine_id_;
    
    agent_machines_t machines_;
    std::deque<uint64_t> relesed_ids_;
};