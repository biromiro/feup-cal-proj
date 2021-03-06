#include <algorithm/Connectivity.tpp>
#include "adminView.h"

AdminView::AdminView(UIManager &uiManager) : uiManager(uiManager){}

void AdminView::run() {
    char answer ;
    do{
        pageOutput();
        std::cout << "\n1 - Check graph's connectivity" << std::endl;
        std::cout << "\n2 - Remove park" << std::endl;
        std::cout << "0 - Logout" << std::endl;
        answer = _getch_();
        switch (answer) {
            case '1':
                checkConnectivity();
                break;
            case '2':
                removePark();
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
    std::cout << "** MyJourney! ** ADMINISTRATION **" << std::endl;
}

void AdminView::checkConnectivity() {
    Connectivity<NodeInfo> c = uiManager.getPlatform()->checkConnectiviy();

    std::cout << "The graph is " << (c.isConnected() ? "" : "not ") << "strongly connected." << std::endl;
    std::cout << "It has " << c.getNumConnectedComponents() << " strongly connected components." << std::endl;
    if(!c.isConnected())
        std::cout << "Each strongly connected component has an average of " << c.getAverageNodePerComponent() << " nodes." << std::endl;

    std::cout << "\nType anything to go back." << std::endl;
    _getch_();

}

void AdminView::removePark() {
    std::cout << "Please insert the park id: ";
    size_t park = inputNumber();

    try{
        uiManager.getPlatform()->removePark(park);
        std::cout << "\nDeleted park!\n";
    } catch(std::exception &e){
        std::cerr << e.what();
    }

    _getch_();
}

