//
// Created by Danny on 24/12/2020.
//

#ifndef PROJECT_VIEWERALREADYORDERED_H
#define PROJECT_VIEWERALREADYORDERED_H

#include <iostream>
#include <exception>
#include "../orderLimitReached/orderLimitReached.h"

/**
 * @file viewerAlreadyOrdered.cpp
 *
 * @brief Exception for when a viewer tries to order merchandising while having an order awaiting processing
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a viewer tries to order merchandising from a streamer while
 * still having an order from that streamer awaiting processing
 *
 * Informs the viewer he's already ordered from that streamer
 */
class ViewerAlreadyOrdered : public std::invalid_argument {
public:
    /**
     * Constructor of the ViewerAlreadyOrdered class
     *
     * @param order order that couldn't be added
     * @param message message telling the viewer he's already ordered from that streamer
     */
    ViewerAlreadyOrdered(MerchRequest order, const std::string &message);

    /**
     * Getter of the order that couldn't be added
     *
     * @return order that couldn't be added
     */
    [[nodiscard]] MerchRequest getOrder() const;
private:
    MerchRequest order;
};

#endif //PROJECT_VIEWERALREADYORDERED_H
