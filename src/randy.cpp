#include <RandyConfig.h>
#include <CLI/CLI.hpp>
#include <phone.hpp>
#include <version.hpp>
#include "CLI/CLI.hpp"

int main(int argc, char** argv) {
    CLI::App app {" "};
    setup_phone(app);
    setup_version(app);

    app.require_subcommand();
    std::string usage_msg =
        "Usage: " + std::string(Randy_TARGET_FILE) + " SUBCOMMAND [OPTIONS]";
    app.usage(usage_msg);
    CLI11_PARSE(app, argc, argv);
    return 0;
}
