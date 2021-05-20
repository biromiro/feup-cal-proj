//
// Created by Danny on 21/12/2020.
//

#ifndef PROJECT_ORDERNOTFOUND_H
#define PROJECT_ORDERNOTFOUND_H

#include <iostream>
#include <exception>

/**
 * @file orderNotFound.cpp
 *
 * @brief Exception for when a viewer tries to remove his order from the queue but there is no order under his name
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a viewer tries to remove his order from a streamer's queue
 * but there's no order under his name currently awaiting processing
 *
 * Informs the viewer there's no order under his name
 */
class OrderNotFound : public std::invalid_argument {
public:
    /**
     * Constructor of the OrderNotFound class
     *
     * @param buyer nickname of the viewer whose order couldn't be found
     * @param message message indicating the viewer's order couldn't be found
     */
    OrderNotFound(std::string buyer, const std::string &message);

    /**
     * Getter of the nickname of the viewer whose order couldn't be found
     *
     * @return nickname of the viewer whose order couldn't be found
     */
    std::string getBuyer() const;
private:
    std::string buyer;
};

#endif //PROJECT_ORDERNOTFOUND_H
