#include <ui/userView/userView.h>
#include "registerPage.h"

RegisterPage::RegisterPage(UIManager &uiManager) : uiManager(uiManager){}

void RegisterPage::run() {
    char answer = ' ';
    std::string nickname, password;
    pageOutput();
    if(!userRegister()) return;
    uiManager.setCurrent(new UserView(uiManager));
    uiManager.run();
}

void RegisterPage::pageOutput() {
    std::cout << "** Welcome to JourneyFinder! **" << std::endl;
}

bool RegisterPage::userRegister()  {
    std::string nickname, password;
    bool valid = false;
    char answer = 0;
    do{
        if(valid) answer = _getch_();
        getUserInfo(nickname,password);
        std::cout << "Are you happy with your choices?" << std::endl;
        std::cout << "Nickname :" << nickname << "\t" << "Password: " << password << "\n";
        std::cout << "\n1 - I wish to redo my choices" << std::endl;
        std::cout << "PRESS ANY OTHER KEY TO PROCEED" << std::endl;
        answer = _getch_();
        if(answer != '1') break;
        valid = true;
    }while (answer != *ESC);

    if(answer == *ESC) return false;
    try{
        uiManager.getCurrentSession().getUserDatabase()->add(new User(nickname, password));
    }catch(std::exception& e){
        std::cerr << e.what();
        _getch_();
        return false;
    }
    uiManager.getCurrentSession().login(nickname,password);
    return true;
}


void RegisterPage::getUserInfo(std::string& nickname, std::string& password){
    std::string checkPassword;
    do{
        pageOutput();
        std::cout << "\nPlease enter the following information:" << std::endl;
        std::cout << "\nNickname: ";
        getlineCIN(nickname);
        if(uiManager.getCurrentSession().getUserDatabase()->has(nickname)){
            std::cerr << "Nickname already taken!";
            _getch_();
            continue;
        }
        break;
    }while (true);
    do{
        std::cout << "Password: ";
        getlineCIN(password);
        std::cout << "Please re-enter your password: ";
        getlineCIN(checkPassword);
        if(password != checkPassword){
            std::cerr << "Passwords don't match!";
            _getch_();
            continue;
        }else break;
    }while(true);
}
