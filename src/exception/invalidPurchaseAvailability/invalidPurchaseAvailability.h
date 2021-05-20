//
// Created by Danny on 21/12/2020.
//

#ifndef PROJECT_INVALIDPURCHASEAVAILABILITY_H
#define PROJECT_INVALIDPURCHASEAVAILABILITY_H

#include <iostream>
#include <exception>

/**
 * @file invalidPurchaseAvailability.cpp
 *
 * @brief Exception for when a viewer tries to order merchandising with an invalid purchase availability
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a viewer tries to order merchandising from a streamer with a
 * purchase availability below 1 or above 5, making it invalid
 *
 * Informs the viewer the purchase availability on his order is invalid
 */
class InvalidPurchaseAvailability : public std::invalid_argument {
public:
    /**
     * Constructor of the InvalidPurchaseAvailability class
     *
     * @param purchaseA invalid purchase availability
     * @param message message indicating the order's purchase availability is invalid
     */
    InvalidPurchaseAvailability(unsigned int purchaseA, const std::string &message);

    /**
     * Getter of the invalid purchase availability
     *
     * @return invalid purchase availability
     */
    [[nodiscard]] unsigned int getPurchaseA() const;
private:
    unsigned int purchaseA;
};

#endif //PROJECT_INVALIDPURCHASEAVAILABILITY_H
