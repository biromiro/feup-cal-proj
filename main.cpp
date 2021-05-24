//
// Created by nrtc on 03/05/2021.
//

#include <utils/graphLoad/GraphLoader.tpp>
#include "src/utils/graph/Graph.tpp"
#include <iostream>
#include <algorithm/Connectivity.tpp>
#include <algorithm/Pathfinding.h>
#include <src/model/db/userDatabase.h>
#include <model/journeyFinder/journeyFinder.h>
#include <ui/UIManager.h>
#include <ui/initialPage/initialPage.h>

int main(){


    UserDatabase db("resources/database.txt");

    CurrentSession currentSession =  CurrentSession(&db);
    UIManager ui(currentSession);

    ui.setCurrent(new InitialPage(ui));
    ui.run();


    return 0;
}
