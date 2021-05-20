//
// Created by nrtc on 21/12/2020.
//

#include "streamerHasNoDonations.h"

#include <utility>

StreamerHasNoDonations::StreamerHasNoDonations(std::string  nickname,const std::string &message) : logic_error(message),
streamerNickname(std::move(nickname)){}

const std::string &StreamerHasNoDonations::getStreamerNickname() const {
    return streamerNickname;
}
