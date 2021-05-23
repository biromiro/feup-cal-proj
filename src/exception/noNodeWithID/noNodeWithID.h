#ifndef PROJECT_NOSTREAMWITHID_H
#define PROJECT_NOSTREAMWITHID_H

#include <iostream>
#include <exception>

class NoNodeWithID : public std::invalid_argument {
public:

    NoNodeWithID(size_t nodeID, const std::string & message);

    [[nodiscard]] unsigned int getNodeID() const;

private:
    size_t nodeID;
};

#endif //PROJECT_NOSTREAMWITHID_H
