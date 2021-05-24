//
// Created by biromiro on 17/05/21.
//

#ifndef FEUP_CAL_PROJ_UTILFUNCTIONS_H
#define FEUP_CAL_PROJ_UTILFUNCTIONS_H


#include <chrono>
#include <thread>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

#ifdef __linux__
#define TERMIOS_GETCH
#include <termios.h>
#endif

// COLOR ANSI CODES
constexpr const char *CLEAR_SCREEN = "\x1b[2J";
constexpr const char *LINE_UP = "\033[A";
constexpr const char *CLEAR_LINE = "\x1b[2K";
constexpr const char *GO_TO_BEGINNING_OF_LINE = "\x1b[0G";
constexpr const char *RESET = "\x1b[0m";
constexpr const char *HIDE_CURSOR = "\x1b[?25l";
constexpr const char *SHOW_CURSOR = "\x1b[?25h";
constexpr const char *GO_TO_TOP = "\033[1;1H";
constexpr const char *ESC = "\033";
constexpr const int WIDTH = 15;

#ifdef TERMIOS_GETCH
void initTermios(int echo);
void resetTermios();
char getch_(int echo);
#endif

/**
 * Gets a char from the keyboard
 *
 * @return the input char
 */
char _getch_();

/**
 * Checks if a given string is a number
 *
 * @param s the string to check
 * @return true if it is, false otherwise
 */
bool is_number(const std::string& s);

/**
 * Receives a number from the input stream, and handles such stream
 *
 * @return the number that was given in input
 */
unsigned int inputNumber();

/**
 * Extension of the getline function, dealing with the stream as well
 *
 * @param s the variable to save the input line
 */
void getlineCIN(std::string& s);

/**
 * Shrinks a given string to the column size of the leaderboard, so it doesn't overflow it
 *
 * @param value the string to shrink
 * @return the shrinked string
 */
std::string shrinkToColumnSize(std::string value);

/**
 *  Receives a float number from the input stream, and handles such stream
 *
 * @return the float given as input
 */
float inputFloat();

#endif //FEUP_CAL_PROJ_UTILFUNCTIONS_H
