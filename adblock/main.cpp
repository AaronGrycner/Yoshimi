#include "header.h"

// todo: make it schedule a task to check for updates every 24 hours
// todo: make a webcrawler that gathers known ad domains and runs them through a language learning model

// this script checks that a dnsmasq config file exists, and that it references the redirect file,
// and that the redirect file exists and is updated
// it then schedules a cron task to run the script every 24 hours

int main() {
    system("lsblk");

    try {
        check_files();
        get_sources();
        schedule_task();
    }
    catch (const std::exception &e) {
        std::cerr << e.what();
        return 1;
    }

    return 0;
}
