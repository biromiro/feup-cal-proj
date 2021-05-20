//
// Created by Danny on 17/11/2020.
//

#include "invalidFeedback.h"

InvalidFeedback::InvalidFeedback(FeedbackLikeSystem fb, const std::string &message) : std::invalid_argument(message), fb(fb) {}

FeedbackLikeSystem InvalidFeedback::getFb() const {
    return fb;
}
