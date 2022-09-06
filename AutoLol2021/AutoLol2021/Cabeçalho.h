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


bool MATCHING_METHOD_MODULAR(cv::Mat& ScreenMat, cv::Mat& Bmat, double percent, int& matchx, int& matchy);
void screenshot(int horizontal, int vertical, int xInicialEsquerda, int yInicialEsquerda, const char* nomeArquivo);