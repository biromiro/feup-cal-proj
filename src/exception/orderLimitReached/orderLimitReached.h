//
// Created by Danny on 21/12/2020.
//

#ifndef PROJECT_ORDERLIMITREACHED_H
#define PROJECT_ORDERLIMITREACHED_H

#include <iostream>
#include <exception>
#include "../../model/transactions/merch/merchRequest.h"

/**
 * @file orderLimitReached.cpp
 *
 * @brief Exception for when a viewer tries to order merchandising but the limit has been reached already
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a viewer tries to order merchandising from a streamer
 * but that streamer has already reached the limit of orders awaiting processing
 *
 * Informs the viewer the limit for orders has been reached for that streamer
 */
class OrderLimitReached : public std::length_error {
public:
    /**
     * Constructor of the OrderLimitReached class
     *
     * @param failedOrder order that couldn't be added
     * @param message message indicating the limit for orders has been reached
     */
    OrderLimitReached(MerchRequest failedOrder, const std::string &message);

    /**
     * Getter of the order that couldn't be added
     *
     * @return order that couldn't be added
     */
    [[nodiscard]] MerchRequest getOrder() const;
private:
    MerchRequest order;
};

#endif //PROJECT_ORDERLIMITREACHED_H
