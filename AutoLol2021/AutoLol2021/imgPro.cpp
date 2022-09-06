#include "header.h"


void screenshot(int horizontal, int vertical, int xInicialEsquerda, int yInicialEsquerda, const char* nomeArquivo)
{
    auto w = horizontal;//GetSystemMetrics(SM_CXFULLSCREEN);
    auto h = vertical;//GetSystemMetrics(SM_CYFULLSCREEN);

    RECT rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = horizontal;
    rc.bottom = vertical;

    auto hdc = GetDC(HWND_DESKTOP);
    auto hbitmap = CreateCompatibleBitmap(hdc, w, h);
    auto memdc = CreateCompatibleDC(hdc);
    auto oldbmp = SelectObject(memdc, hbitmap);
    BitBlt(memdc, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, hdc, xInicialEsquerda, yInicialEsquerda, SRCCOPY);

    cv::Mat mat(h, w, CV_8UC4);
    BITMAPINFOHEADER bi = { sizeof(bi), w, -h, 1, 32, BI_RGB };
    GetDIBits(hdc, hbitmap, 0, h, mat.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);
    cv::imwrite(nomeArquivo, mat);

    SelectObject(memdc, oldbmp);
    DeleteDC(memdc);
    DeleteObject(hbitmap);
    ReleaseDC(HWND_DESKTOP, hdc);
    mat.release();
}

bool MATCHING_METHOD_MODULAR(cv::Mat& ScreenMat, cv::Mat& Bmat, double percent, int& matchx, int& matchy, int metod)
{
    if (ScreenMat.empty() || Bmat.empty())
        return false;

    cv::Mat Cmat;

    try {
        cv::matchTemplate(ScreenMat, Bmat, Cmat, metod);

    }catch (cv::Exception& e)
    {
        const char* err_msg = e.what();
        std::cout << "ERRO CAPTURADO: " << err_msg << std::endl;
        return false;
    }


    double minVal;
    double maxVal;

    cv::Point minLoc;
    cv::Point maxLoc;

    minMaxLoc(Cmat, &minVal, &maxVal, &minLoc, &maxLoc);

    if (maxVal > percent)
    {
        matchx = maxLoc.x;
        matchy = maxLoc.y;

        Cmat.release();

        return true;
    }

    Cmat.release();

    return false;
    //Não Encontrou
}