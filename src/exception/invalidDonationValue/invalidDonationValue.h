//
// Created by nrtc on 26/12/2020.
//

#ifndef PROJECT_INVALIDFEEDBACK_H
#define PROJECT_INVALIDFEEDBACK_H

#include <iostream>
#include <exception>

/**
 * @file invalidDonationValue.cpp
 *
 * @brief Exception for when a donation with an invalid value is given
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when an invalid donation value is formed
 *
 * Informs the viewer that his donation is invalid
 */
class InvalidDonationValue : public std::invalid_argument {
public:
    /**
     * Constructor of the InvalidDonationValue class
     *
     * @param value invalid donation value
     * @param message message indicating the donation value is invalid
     */
    InvalidDonationValue(float value, const std::string & message);

    /**
     * Getter of the invalid donation value
     *
     * @return viewer's invalid feedback
     */
    [[nodiscard]] float getValue() const;

private:
    float value;
};

#endif //PROJECT_INVALIDFEEDBACK_H
