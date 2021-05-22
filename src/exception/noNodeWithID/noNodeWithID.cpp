#include "noNodeWithID.h"

NoNodeWithID::NoNodeWithID(size_t nodeID, const std::string &message) : std::invalid_argument(message), nodeID(nodeID){}

unsigned int NoNodeWithID::getNodeID() const {
    return nodeID;
}
