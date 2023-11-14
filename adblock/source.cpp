//
// Created by aaron on 11/9/23.
//

#include "header.h"

void schedule_task() {
    std::ifstream in("/etc/crontabs/root");
    std::ofstream out;
    std::string line;

    while (getline(in, line)) {
        if (line.find("0 0 * * * /bin/adblock") != std::string::npos) {
            return;
        }
    }

    in.close();
    out.open("/etc/crontabs/root", std::ios::app);

    out << "0 0 * * * /bin/adblock" << std::endl;
}

// checks for the directory, and checks
void check_directory() {
    if (const std::ifstream directory(FILES_PATH); !directory) {
        system(std::string("mkdir -p " + FILES_PATH).c_str());
    }
}

// checks for the redirect file, and check
void check_redirect_file() {
    if (!std::filesystem::exists(REDIRECT_FILE)) {
        std::ofstream redirect_file(REDIRECT_FILE);
        redirect_file.close();
    }
}

void check_config_file() {
    std::fstream config_file(CONFIG_FILE, std::ios::app);
    std::string line;

    while(getline(config_file, line)) {
        // if the line contains the redirect file, return true before adding
        if (line.find("conf-file=" + REDIRECT_FILE) != std::string::npos) {
            return;
        }

        // add redirect file
        config_file << "conf-file=" << REDIRECT_FILE << std::endl;
    }
}

// download sources file and write to redirects file
void get_sources() {
    std::ifstream srcs;
    std::ofstream redirects{REDIRECT_FILE};
    std::string line;

    // download sources file
    system(std::string("curl -o " + FILES_PATH + "/sources.txt " + SOURCE_URL).c_str());

    srcs = std::ifstream(FILES_PATH + "/sources.txt");

    // write sources to redirects file
    while (getline(srcs, line)) {
        redirects << "address=/" << line << "/127.0.0.1\n";
    }

    // cleanup
    redirects.close();
    srcs.close();
    system(std::string("rm " + FILES_PATH + "/sources.txt").c_str());
}

void check_files() {
    check_directory();
    check_redirect_file();
    check_config_file();
}