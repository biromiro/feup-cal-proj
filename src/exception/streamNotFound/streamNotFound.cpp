//
// Created by Danny on 18/11/2020.
//

#include "streamNotFound.h"

StreamNotFound::StreamNotFound(std::shared_ptr<Stream> stream, const std::string &message) : stream(std::move(stream)), std::invalid_argument(message) {}

const std::shared_ptr<Stream> &StreamNotFound::getStream() const {
    return stream;
}
