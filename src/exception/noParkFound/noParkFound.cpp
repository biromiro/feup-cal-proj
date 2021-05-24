#include "noParkFound.h"

NoParkFound::NoParkFound(size_t destinyID, const std::string &message) : std::invalid_argument(message), destinyID(destinyID){}

unsigned int NoParkFound::getDestinyID() const {
    return destinyID;
}
