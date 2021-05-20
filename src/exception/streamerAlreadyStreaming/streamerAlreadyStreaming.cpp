//
// Created by Danny on 18/11/2020.
//

#include "streamerAlreadyStreaming.h"

StreamerAlreadyStreaming::StreamerAlreadyStreaming(std::shared_ptr<Streamer> streamer, const std::string &message) : streamer(std::move(streamer)), std::logic_error(message) {}

const std::shared_ptr<Streamer> &StreamerAlreadyStreaming::getStreamer() const {
    return streamer;
}