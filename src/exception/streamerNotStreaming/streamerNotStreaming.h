//
// Created by biromiro on 19/11/20.
//

#ifndef PROJECT_STREAMERNOTSTREAMING_H
#define PROJECT_STREAMERNOTSTREAMING_H

#include <iostream>

/**
 * @file streamerNotStreaming.cpp
 *
 * @brief Exception for when a streamer tries to end a stream but he's not streaming
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a streamer tries to end a stream but he's not streaming
 *
 * Informs the streamer that he can't end his stream because he's not streaming
 */
class StreamerNotStreaming : public std::logic_error {
public:
    /**
     * Constructor of the StreamerNotStreaming class
     *
     * @param message message indicating that the streamer isn't streaming
     */
    explicit StreamerNotStreaming(const std::string & message);
};


#endif //PROJECT_STREAMERNOTSTREAMING_H
