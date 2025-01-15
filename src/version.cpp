#include <RandyConfig.h>
#include <iostream>
#include <version.hpp>

using std::cout;
using std::endl;

void setup_version(CLI::App& app) {
    auto* sub = app.add_subcommand("version", "Show version");
    sub->callback([&]() { run_version(); });
    std::string usage_msg =
        "Usage: " + std::string(Randy_TARGET_FILE) + " version [OPTIONS]";
    sub->usage(usage_msg);
}

int run_version() {
    cout << Randy_TARGET_FILE << " Version " << Randy_VERSION_MAJOR << "."
         << Randy_VERSION_MINOR << endl;
    return 0;
}
