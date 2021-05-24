#ifndef PROJECT_VIEWERVIEW_H
#define PROJECT_VIEWERVIEW_H

#include "../initialPage/initialPage.h"
#include <utils/utilitaryStructures/utilFunctions.h>

/**
 * @file viewerView.cpp
 *
 * @brief Deals with the User View Page in the UI
 *
 * @ingroup UI
 */

/**
 * Implementation of the User's Page in the UI
 *
 */
class UserView : public UI{
public:

    /**
     * Viewer View's constructor
     *
     * @param uiManager the manager of the current UI
     */
    explicit UserView(UIManager& uiManager);

    /**
     * Runs the viewer View output prompt
     */
    void run() override;
private:

    int myTime = 1, myMaxRange = 200;

    UIManager& uiManager;

    /**
    * Prints the header of the UI page to the screen
    */
    void pageOutput() const;

    void generateJourney();

    void addPOI();

    void setConfigs();

    void clearPOI();

    void feedBack();
};

#endif //PROJECT_VIEWERVIEW_H