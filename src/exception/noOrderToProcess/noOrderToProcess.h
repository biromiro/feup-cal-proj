//
// Created by Danny on 17/11/2020.
//

#ifndef PROJECT_NICKNAMENOTFOUND_H
#define PROJECT_NICKNAMENOTFOUND_H

#include <iostream>
#include <exception>
#include <utility>

/**
 * @file noOrderToProcess.cpp
 *
 * @brief Exception for when a streamer has no orders to process
 *
 * @ingroup exception
 */

/**
 * Implementation of the exception for when a streamer has no orders to process
 *
 * Informs the streamer that he has no orders to process
 */
class NoOrderToProcess : public std::invalid_argument {
public:
    /**
     * Constructor of the NoOrderToProcess class
     *
     * @param message message indicating the streamer he has no more orders
     */
    NoOrderToProcess(const std::string & message);

};

#endif //PROJECT_NICKNAMENOTFOUND_H
