#include <algorithm/Connectivity.tpp>
#include "adminView.h"

AdminView::AdminView(UIManager &uiManager) : uiManager(uiManager){}

void AdminView::run() {
    char answer ;
    do{
        pageOutput();
        std::cout << "\n1 - Check graph's connectivity" << std::endl;
        std::cout << "0 - Logout" << std::endl;
        answer = _getch_();
        switch (answer) {
            case '1':
                checkConnectivity();
                break;
            case '0':
                uiManager.getCurrentSession().logout();
                break;
            default:
                break;
        }
    }while (answer != *ESC && answer != '0');
}

void AdminView::pageOutput() {
    std::cout << "** JourneyFinder ** ADMINISTRATION **" << std::endl;
}

void AdminView::checkConnectivity() {
}

