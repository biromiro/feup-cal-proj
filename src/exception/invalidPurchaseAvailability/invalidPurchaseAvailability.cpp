//
// Created by Danny on 21/12/2020.
//

#include "invalidPurchaseAvailability.h"

InvalidPurchaseAvailability::InvalidPurchaseAvailability(unsigned int purchaseA, const std::string &message): purchaseA(purchaseA), std::invalid_argument(message) {}

unsigned int InvalidPurchaseAvailability::getPurchaseA() const { return purchaseA; }