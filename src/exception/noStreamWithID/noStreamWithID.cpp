//
// Created by Danny on 18/11/2020.
//

#include "noStreamWithID.h"

NoStreamWithID::NoStreamWithID(unsigned int streamID, const std::string &message) : streamID(streamID), std::invalid_argument(message) {}

unsigned int NoStreamWithID::getStreamId() const {
    return streamID;
}
