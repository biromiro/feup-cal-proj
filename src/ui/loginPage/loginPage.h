
#ifndef PROJECT_LOGINPAGE_H
#define PROJECT_LOGINPAGE_H

#include "../initialPage/initialPage.h"
#include <utils/utilitaryStructures/utilFunctions.h>

/**
 * @file loginPage.cpp
 *
 * @brief Deals with the Login Page in the UI
 *
 * @ingroup UI
 */

/**
 * Implementation of the Login's Page in the UI
 *
 * Allows any user to login, given correct information
 */

class LoginPage : public UI{
public:

    /**
     * Login Page's constructor
     *
     * @param uiManager the manager of the current UI
     */
    explicit LoginPage(UIManager& uiManager);

    /**
     * Runs the login page output
     */
    void run() override;
private:
    UIManager& uiManager;

    /**
     * Prints the header of the UI page to the screen
     */
    static void pageOutput() ;
};

#endif //PROJECT_LOGINPAGE_H