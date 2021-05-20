//
// Created by Danny on 17/11/2020.
//

#ifndef PROJECT_INVALIDFEEDBACK_H
#define PROJECT_INVALIDFEEDBACK_H

#include <iostream>
#include <exception>

/**
 * @file invalidFeedback.cpp
 *
 * @brief Exception for when a viewer tries to give invalid feedback to a stream
 *
 * @ingroup exception
 */


enum class FeedbackLikeSystem;

/**
 * Implementation of the exception for when a viewer tries to give feedback to a stream
 * but it's different than the LIKE or DISLIKE votes allowed
 *
 * Informs the viewer that his feedback is invalid
 */
class InvalidFeedback : public std::invalid_argument {
public:
    /**
     * Constructor of the InvalidFeedback class
     *
     * @param fb invalid feedback
     * @param message message indicating the viewer's feedback is invalid
     */
    InvalidFeedback(FeedbackLikeSystem fb, const std::string & message);

    /**
     * Getter of the viewer's invalid feedback
     *
     * @return viewer's invalid feedback
     */
    FeedbackLikeSystem getFb() const;

private:
    enum FeedbackLikeSystem fb;
};

#endif //PROJECT_INVALIDFEEDBACK_H
