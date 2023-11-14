//
// Created by aaron on 11/9/23.
//

#ifndef HEADER_H
#define HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_set>
#include <sys/stat.h>

#include "defs.h"

void check_directory();
void check_redirect_file();
void check_config_file();
void get_sources();
void check_files();
void schedule_task();

#endif //HEADER_H
