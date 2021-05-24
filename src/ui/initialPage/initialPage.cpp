//
// Created by nrtc on 23/05/2021.
//

#include "initialPage.h"
#include <utils/utilitaryStructures/utilFunctions.h>
#include <ui/loginPage/loginPage.h>
#include <ui/registerPage/registerPage.h>

InitialPage::InitialPage(UIManager &uiManager) : uiManager(uiManager){
    maps["Porto_SCC"] =std::pair<std::string,std::string>(
            "resources/Porto/SCC/porto_strong_nodes_latlng.txt",
            "resources/Porto/SCC/porto_strong_edges.txt");

    maps["Porto_FULL"] = std::pair<std::string,std::string>(
            "resources/Porto/Full/porto_full_nodes_latlng.txt",
            "resources/Porto/Full/porto_full_edges.txt");

    maps["Espinho_SCC"] =std::pair<std::string,std::string>(
            "resources/Espinho/SCC/espinho_strong_nodes_latlng.txt",
            "resources/Espinho/SCC/espinho_strong_edges.txt");

    maps["Espinho_FULL"] = std::pair<std::string,std::string>(
            "resources/Espinho/Full/espinho_full_nodes_latlng.txt",
            "resources/Espinho/Full/espinho_full_edges.txt");

    maps["Penafiel_SCC"] =std::pair<std::string,std::string>(
            "resources/Espinho/SCC/espinho_strong_nodes_latlng.txt",
            "resources/Espinho/SCC/espinho_strong_edges.txt");

    maps["Penafiel_FULL"] = std::pair<std::string,std::string>(
            "resources/Penafiel/Full/penafiel_full_nodes_latlng.txt",
            "resources/Penafiel/Full/penafiel_full_edges.txt");
}

void InitialPage::run() {
    char answer;
    bool started = false;
    std::string graph_str;
    do{
        if(started) answer = _getch_();
        if(answer != *ESC) {
            std::cout << "Please select one of the following graphs:\n";
            size_t j = 0;
            for(auto const& [key, val] : maps){
                if((j++)%3 == 0) std::cout << "\n";
                std::cout << key << " ";
            }
            std::cout << "\n";
            getlineCIN(graph_str);
            //tries to login
            if (maps.find(graph_str) != maps.end()){

                //sets up the page according to the user who logged in
                uiManager.setPlatform(maps[graph_str].first, maps[graph_str].second);
                break;
            }

                //could not login
            else std::cerr << "No such map! Try again.";
            started = true;
        }
    }while(true);
    do{
        pageOutput();
        answer = _getch_();
        switch (answer) {
            case '1':
                uiManager.setCurrent(new LoginPage(uiManager));
                uiManager.run();
                break;
            case '2':
                uiManager.setCurrent(new RegisterPage(uiManager));
                uiManager.run();
                break;
            default:
                break;
        }
    }while(answer != '0');
}

void InitialPage::pageOutput() {
    std::cout << "** Welcome to MyJourney! **" << std::endl;
    std::cout << "\n\t1 - Login" << std::endl;
    std::cout << "\t2 - Register" << std::endl;
    std::cout << "\t0 - Quit and Save" << std::endl;
    std::cout << "\n*******************************" << std::endl;
}

