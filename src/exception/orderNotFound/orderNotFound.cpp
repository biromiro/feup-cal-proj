//
// Created by Danny on 21/12/2020.
//

#include "orderNotFound.h"

OrderNotFound::OrderNotFound(std::string buyer, const std::string &message): buyer(buyer), std::invalid_argument(message) {}

std::string OrderNotFound::getBuyer() const { return buyer; }