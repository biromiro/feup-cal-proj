#ifndef PROJECT_UI_MANAGER_H
#define PROJECT_UI_MANAGER_H

#include <auth/currentSession.h>
#include <model/journeyFinder/journeyFinder.h>
#include "UI.h"

/**
 * @file ui_manager.cpp
 *
 * @brief Manager of the UI pages
 *
 * @ingroup UI
 */

/**
 * Manager of the UI pages
 *
 * Allows the UI to access platform and current session information, as well as keeping track of the current UI
 */
class UIManager{
public:

    /**
     * UIManager's constructor
     *
     * @param platform the platform on which it operates
     * @param currentSession the current User that is logged in
     */
    explicit UIManager(CurrentSession& currentSession);

    /**
     * Gets the current platform on which the UIManager is operating
     *
     * @return the platform on which it is operating
     */
    [[nodiscard]] JourneyFinder * getPlatform() const;

    /**
     * Gets the current logged user
     *
     * @return the currentSession object of the logged in user
     */
    [[nodiscard]] CurrentSession &getCurrentSession() const;

    /**
     * Starts the UI
     */
    void run() const;

    /**
     * Sets the current UI page
     *
     * @param ui the page to set the UI to
     */
    void setCurrent(UI* ui);

    void setPlatform(const std::string& nodePath, const std::string& edgePath);
private:
    JourneyFinder* platform;
    CurrentSession& currentSession;
    UI* currentUI = nullptr;
};

#endif //PROJECT_UI_MANAGER_H