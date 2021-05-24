#include "userView.h"

UserView::UserView(UIManager &uiManager) : uiManager(uiManager){}

void UserView::run() {
    char answer;
    do{
        pageOutput();
        std::cout << "1 - Generate MyJourney!\n";
        std::cout << "2 - Add a point of interest\n";
        std::cout << "3 - Update a park's capacity information\n";
        std::cout << "4 - My Configurations\n";
        std::cout << "5 - Clear my POI\n";
        std::cout << "0 - Logout" << std::endl;
        answer = _getch_();
        switch (answer) {
            case '1':
                generateJourney();
                break;
            case '2':
                addPOI();
                break;
            case '3':
                feedBack();
                break;
            case '4':
                setConfigs();
                break;
            case '5':
                clearPOI();
                break;
            case '0':
                uiManager.getCurrentSession().logout();
                break;
            default:
                break;
        }
    }while (answer != '0');
    clearPOI();
}

void UserView::pageOutput() const {
    std::cout << "** MyJourney! **" << uiManager.getCurrentSession().getNickname() << "**\n" << std::endl;
}

void UserView::generateJourney() {
    size_t origin, destiny;
    char answer = 0;
    do{
        std::cout << "Please insert the origin node ID: ";
        origin = inputNumber();
        std::cout << "Please insert the destiny node ID: ";
        destiny = inputNumber();
        try{
            uiManager.getPlatform()->generateJourney(origin, destiny, myTime, myMaxRange);
            std::cout << "Journey successfully generated. Please check out the server for a animated preview!\n";
            std::cout << "0 to re-generate.";
        } catch(std::exception &e){
            std::cerr << e.what();
            std::cerr << std::flush;
            std::cout << "0 to retry.";
        }
        answer = _getch_();
        if(answer != '0') break;
    }while (answer != *ESC);
}

void UserView::addPOI() {
    size_t poi;
    char answer = 0;
    do{
        std::cout << "Please insert the POI node ID: ";
        poi = inputNumber();
        try{
            uiManager.getPlatform()->addPointOfInterest(poi);
            std::cout << "POI successfully added!\n";
            std::cout << "0 to add a new one.";
        } catch(std::exception &e){
            std::cerr << e.what();
            std::cout << "0 to retry.";
        }
        answer = _getch_();
        if(answer != '0') break;
    }while (answer != *ESC);
}

void UserView::setConfigs() {
    char answer = 0;
    std::cout << "Your current parking time: " << myTime << std::endl;
    std::cout << "Your current parking radius limit: " << myMaxRange << std::endl;

    std::cout << "Please insert your new parking time: ";
    myTime = inputFloat();

    std::cout << "Please insert your new parking radius limit: ";
    myMaxRange = inputFloat();

    std::cout << "Settings successfully changed!";

    answer = _getch_();
}

void UserView::clearPOI() {
    uiManager.getPlatform()->clearPointsOfInterest();
}

void UserView::feedBack() {
    std::cout << "Please insert the park id: ";
    size_t park = inputNumber();

    std::cout << "\nPlease insert the current capacity: ";
    int cap = inputNumber();
    try{
        NodeInfo node = uiManager.getPlatform()->updateParkCapacity(park, cap);
        std::cout << "\nUpdated capacity to " << node.getCurrentCapacity() << "/" << node.getMaxCapacity() << "!\n";
    } catch(std::exception &e){
        std::cerr << e.what();
    }

    _getch_();
}
