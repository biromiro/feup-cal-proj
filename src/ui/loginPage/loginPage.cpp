
#include <ui/adminView/adminView.h>
#include <ui/userView/userView.h>
#include "loginPage.h"

LoginPage::LoginPage(UIManager &uiManager) : uiManager(uiManager){}

void LoginPage::run() {
    char answer = ' ';
    bool started = false;
    std::string nickname, password;
    do{
        if(started) answer = _getch_();
        pageOutput();
        if(answer != *ESC) {
            std::cout << "Nickname: ";
            getlineCIN(nickname);
            std::cout << "Password: ";
            getlineCIN(password);

            //tries to login
            if (uiManager.getCurrentSession().login(nickname, password)){

                //sets up the page according to the user who logged in
                if(uiManager.getCurrentSession().getCurrentUser()->isAdmin()) {
                    uiManager.setCurrent(new AdminView(uiManager));
                    uiManager.run();
                } else {
                    uiManager.setCurrent(new UserView(uiManager));
                    uiManager.run();
                }
                return;
            }

            //could not login
            else std::cerr << "Invalid Combination! Try again.";
            started = true;

        }
    }while(answer != *ESC);
}

void LoginPage::pageOutput() {
    std::cout << "** Welcome to MyJourney! **" << std::endl;
}
