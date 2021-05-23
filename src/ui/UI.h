
#ifndef PROJECT_UI_H
#define PROJECT_UI_H

/**
 * @file ui.h
 *
 * @brief Base class of all UI pages
 *
 * @ingroup UI
 */

/**
 * Base class of all UI pages
 */
class UI{
public:
    /**
     * Runs the given UI page
     */
    virtual void run() = 0;
};

#endif //PROJECT_UI_H