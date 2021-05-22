#ifndef PROJECT_NOPARKFOUND_H
#define PROJECT_NOPARKFOUND_H

#include <iostream>
#include <exception>

class NoParkFound : public std::invalid_argument {
public:

    NoParkFound(size_t destinyID, const std::string & message);

    [[nodiscard]] unsigned int getDestinyID() const;

private:
    size_t destinyID;
};

#endif //PROJECT_NOPARKFOUND_H
