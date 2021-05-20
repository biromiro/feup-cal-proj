//
// Created by Danny on 18/11/2020.
//

#ifndef PROJECT_NOSTREAMWITHID_H
#define PROJECT_NOSTREAMWITHID_H

#include <iostream>
#include <exception>

/**
 * @file noStreamWithID.cpp
 *
 * @brief Exception for when the ID being searched doesn't correspond to any stream
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when the user searches for a stream through its ID
 * but there's no stream with the ID searched
 *
 * Informs the user there's no stream with the searched ID
 */
class NoStreamWithID : public std::invalid_argument {
public:
    /**
     * Constructor of the NoStreamWithID class
     *
     * @param streamID ID searched that corresponds to no stream
     * @param message message indicating there's no stream with the searched ID
     */
    NoStreamWithID(unsigned int streamID, const std::string & message);

    /**
     * Getter of the searched ID
     *
     * @return searched ID that corresponds to no stream
     */
    [[nodiscard]] unsigned int getStreamId() const;

private:
    unsigned int streamID;
};

#endif //PROJECT_NOSTREAMWITHID_H
