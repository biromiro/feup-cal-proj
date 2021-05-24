//
// Created by biromiro on 17/05/21.
//

#include <algorithm>
#include <sstream>
#include "utilFunctions.h"

#ifdef TERMIOS_GETCH
static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    current = old; /* make new settings same as old settings */
    current.c_lflag &= ~ICANON; /* disable buffered i/o */
    if (echo) {
        current.c_lflag |= ECHO; /* set echo mode */
    } else {
        current.c_lflag &= ~ECHO; /* set no echo mode */
    }
    tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios()
{
    tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    std::cin >> std::ws;
    ch = getchar();
    resetTermios();
    return ch;
}

char _getch_()
{
    return getch_(0);
}
#endif

#ifdef _WIN32
char _getch_()
{
    std::cin >> std::ws;
    char ch = std::cin.get();
    return ch;
}
#endif

bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
                                      s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

unsigned int inputNumber(){
    unsigned int num = 0;
    std::string str;
    getlineCIN(str);
    if(is_number(str)){
        std::stringstream strs(str);
        strs >> num;
        return num;
    }else{
        return 0;
    }
}

bool isFloat( std::string myString ) {
    std::istringstream iss(myString);
    float f;
    iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

float inputFloat(){
    float num = 0;
    std::string str;
    getlineCIN(str);
    if(isFloat(str)){
        std::stringstream strs(str);
        strs >> std::noskipws >> num;
        return num;
    }else{
        return 0;
    }
}

void getlineCIN(std::string& s){
    std::cin >> std::ws;
    getline(std::cin,s);
}