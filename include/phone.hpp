#pragma once

#include <CLI/CLI.hpp>
#include <string>

struct PhoneOptions {
    std::string state;
    int         number;
};

void setup_phone(CLI::App& app);
int  run_phone(PhoneOptions const& opt);
