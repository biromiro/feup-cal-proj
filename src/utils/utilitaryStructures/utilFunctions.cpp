//
// Created by biromiro on 17/05/21.
//

#include "utilFunctions.h"

void ms_sleep(int sleepMs) {
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepMs));
}