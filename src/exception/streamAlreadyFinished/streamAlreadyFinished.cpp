//
// Created by Danny on 18/11/2020.
//

#include "streamAlreadyFinished.h"

StreamAlreadyFinished::StreamAlreadyFinished(std::shared_ptr<Stream> stream, const std::string &message) : stream(std::move(stream)), std::logic_error(message) {}

const std::shared_ptr<Stream> &StreamAlreadyFinished::getStream() const {
    return stream;
}