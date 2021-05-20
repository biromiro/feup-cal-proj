//
// Created by Danny on 18/11/2020.
//

#include "invalidStreamBuild.h"

InvalidStreamBuild::InvalidStreamBuild(const std::string &message) : std::runtime_error(message) {}
