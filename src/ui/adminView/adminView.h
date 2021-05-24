#ifndef PROJECT_ADMINVIEW_H
#define PROJECT_ADMINVIEW_H

#include "../initialPage/initialPage.h"
#include <utils/utilitaryStructures/utilFunctions.h>

/**
 * @file adminView.cpp
 *
 * @brief Deals with the Admin's View in the UI
 *
 * @ingroup UI
 */

/**
 * Implementation of the Admin's Point Of View in the UI
 *
 * Allows the admin to access not only the leaderboards, but the platform statistics as well
 */
class AdminView : public UI{
public:
    /**
     * Admin View's constructor
     *
     * @param uiManager the manager of the current UI
     */
    explicit AdminView(UIManager& uiManager);

    /**
     * Runs the UI prompt
     */
    void run() override;

private:
    UIManager& uiManager;

    /**
     * Prints the header of the UI page to the screen
     */
    static void pageOutput() ;

    void removePark();
    void checkConnectivity();
};

#endif //PROJECT_ADMINVIEW_H
