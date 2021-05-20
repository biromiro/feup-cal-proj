//
// Created by nrtc on 21/12/2020.
//

#ifndef PROJECT_STREAMERHASNODONATIONS_H
#define PROJECT_STREAMERHASNODONATIONS_H
#include <iostream>

/**
 * @file streamerHasNoDonations.cpp
 *
 * @brief Exception for when a streamer tries to see which donations he has but has none currently
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a streamer tries to see which donations he has but has none currently
 *
 * Informs the streamer he has no donations
 */
class StreamerHasNoDonations : public std::logic_error {
public:
    /**
     * Constructor of the StreamerHasNoDonations class
     *
     * @param message message indicating that the streamer has no donations
     */
    explicit StreamerHasNoDonations(std::string  nickname, const std::string & message);

    [[nodiscard]] const std::string &getStreamerNickname() const;

private:
    std::string streamerNickname;
};



#endif //PROJECT_STREAMERHASNODONATIONS_H
