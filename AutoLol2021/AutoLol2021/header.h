#pragma once
#include <windows.h>

#include <iostream>

#include <tlhelp32.h>

#include <thread>

#include <opencv2/core.hpp>

#include <opencv2/highgui.hpp>

#include <opencv2/imgproc.hpp>

#include <opencv2/opencv.hpp>

#include <vector>

#include <string>

#include <chrono>

#include <locale>

#include <random>

//imgPro.cpp
bool MATCHING_METHOD_MODULAR(cv::Mat& ScreenMat, cv::Mat& Bmat, double percent, int& matchx, int& matchy,int metod);
void screenshot(int horizontal, int vertical, int xInicialEsquerda, int yInicialEsquerda, const char* nomeArquivo);
//-!

//gameMode.cpp
void playingMode();
int baseControlModule();
void levelPrint();
void verifyMinionsAlly();
void lowLifeDetection();
void enemyMinions();
//-!

//generalFunctions.cpp
void MOUSE_CLICK_RIGHT();
void MOUSE_CLICK_LEFT();
void KEY_PRESS_AND_UP(int key);
void KEY_PRESS_DOWN(int key);
bool CHECK_PROCESS();
void Window_Move();
void Q_UP();
void W_UP();
void E_UP();
void R_UP();
void SKILLS_FILE(char* vetSkills[], const char* fileName);
void SKILL_SELECTOR(int lvl, char* skills[]);
void ABILITIES_SEQUENCE(int lvl, char* skills[]);
//-!

//clientDecisions.cpp
int clientSinalizer(int& x, int& y);
void mainClientDecisions();
void selectMiss(int x, int y);
void selectChamp(int x, int y);
void selectCaitlyn(int x, int y);
//-!

extern int minions;
extern bool ennemyMinionDetect;