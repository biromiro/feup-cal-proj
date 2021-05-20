//
// Created by Danny on 21/12/2020.
//

#include "orderLimitReached.h"

OrderLimitReached::OrderLimitReached(MerchRequest failedOrder, const std::string &message): order(failedOrder), std::length_error(message) {}

MerchRequest OrderLimitReached::getOrder() const { return order; }