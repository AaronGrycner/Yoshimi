//
// Created by aaron on 11/9/23.
//

#ifndef DEFS_H
#define DEFS_H

#include <string>

// redirects file goes in the yoshimi folder, dnsmasq does not
const std::string FILES_PATH{"/etc/yoshimi/adblock"},
    REDIRECT_FILE{FILES_PATH + "/redirects.yoshimi"},
    CONFIG_FILE{FILES_PATH + "/etc/dnsmasq.conf"},
    SOURCE_URL{"https://raw.githubusercontent.com/AdroitAdorKhan/antipopads-re/master/formats/domains.txt"};

#endif //DEFS_H
