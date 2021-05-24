//
// Created by nrtc on 23/05/2021.
//

#include "UIManager.h"

UIManager::UIManager(CurrentSession &currentSession):
currentSession(currentSession) {}

JourneyFinder * UIManager::getPlatform() const {
    return platform;
}

CurrentSession &UIManager::getCurrentSession() const {
    return currentSession;
}

void UIManager::run() const {
    currentUI->run();
}

void UIManager::setCurrent(UI *ui) {
    currentUI = ui;
}

void UIManager::setPlatform(const std::string& nodePath, const std::string& edgePath) {
    platform = new JourneyFinder(nodePath, edgePath);
}
