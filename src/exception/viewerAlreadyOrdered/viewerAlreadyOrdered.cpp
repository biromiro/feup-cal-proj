//
// Created by Danny on 24/12/2020.
//

#include "viewerAlreadyOrdered.h"

ViewerAlreadyOrdered::ViewerAlreadyOrdered(MerchRequest order, const std::string &message): order(order), std::invalid_argument(message) {}

MerchRequest ViewerAlreadyOrdered::getOrder() const { return order; }