//
// Created by Danny on 18/11/2020.
//

#include "invalidStreamToAdd.h"

InvalidStreamToAdd::InvalidStreamToAdd(std::shared_ptr<Stream> stream, const std::string &message) : stream(std::move(std::move(stream))), std::invalid_argument(message) {}

const std::shared_ptr<Stream> &InvalidStreamToAdd::getStream() const {
    return stream;
}
