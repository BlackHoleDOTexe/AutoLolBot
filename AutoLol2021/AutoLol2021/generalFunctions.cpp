#include "header.h"
bool CHECK_PROCESS()
{
    HANDLE SnapShot_Processos = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    PROCESSENTRY32 Process_Entry;

    Process_Entry.dwSize = sizeof(PROCESSENTRY32);

    Process32First(SnapShot_Processos, &Process_Entry);

    while (Process32Next(SnapShot_Processos, &Process_Entry))
        if (lstrcmp(Process_Entry.szExeFile, L"League of Legends.exe") == 0)
            return true;

    return false;
}

void Window_Move() {

    HWND hWND1;
    LPCSTR lol = "League of Legends (TM) Client";
    hWND1 = FindWindowA(NULL, lol);
    SetWindowPos(hWND1, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);

}

void Q_UP() {
    KEY_PRESS_DOWN(VK_CONTROL);
    KEY_PRESS_AND_UP(81);
    KEY_PRESS_AND_UP(VK_CONTROL);
}

void W_UP() {
    KEY_PRESS_DOWN(VK_CONTROL);
    KEY_PRESS_AND_UP(87);
    KEY_PRESS_AND_UP(VK_CONTROL);
}

void E_UP() {
    KEY_PRESS_DOWN(VK_CONTROL);
    KEY_PRESS_AND_UP(69);
    KEY_PRESS_AND_UP(VK_CONTROL);
}

void R_UP() {
    KEY_PRESS_DOWN(VK_CONTROL);
    KEY_PRESS_AND_UP(82);
    KEY_PRESS_AND_UP(VK_CONTROL);
}


void SKILLS_FILE(char* vetSkills[], const char* fileName) {

    FILE* in_file = fopen(fileName, "r");

    if (in_file == NULL)
        exit(-1);
    else
        //std::cout << "Arquivo skills.txt aberto com sucesso!" << std::endl;

        for (int i = 0; i <= 17; i++) {
            fscanf(in_file, "%c", &vetSkills[i]);
        }

}

void SKILL_SELECTOR(int lvl, char* skills[]) {

    if ((char)skills[lvl - 1] == 'q' || (char)skills[lvl - 1] == 'Q') {
        Q_UP();
    }
    else if ((char)skills[lvl - 1] == 'w' || (char)skills[lvl - 1] == 'W') {
        W_UP();
    }
    else if ((char)skills[lvl - 1] == 'e' || (char)skills[lvl - 1] == 'E') {
        E_UP();
    }
    else if ((char)skills[lvl - 1] == 'r' || (char)skills[lvl - 1] == 'R') {
        R_UP();
    }
}

void ABILITIES_SEQUENCE(int lvl, char* skills[]) {
    switch (lvl) {
    case 1:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 2:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 3:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 4:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 5:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 6:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 7:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 8:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 9:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 10:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 11:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 12:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 13:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 14:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 15:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 16:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 17:
        SKILL_SELECTOR(lvl, skills);
        break;
    case 18:
        SKILL_SELECTOR(lvl, skills);
        break;
    default:
        break;
    }

}

void MOUSE_CLICK_RIGHT() {
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, WHEEL_DELTA, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, WHEEL_DELTA, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void MOUSE_CLICK_LEFT() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, WHEEL_DELTA, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, WHEEL_DELTA, 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

/// <summary>
/// EDUARDO GODOY 08/05/2020
/// Envia o comando para pressionar a tecla passada por parâmetro (virtual key) e a libera em seguida simulando um toque.
/// </summary>
/// <param name="key"></param>

void KEY_PRESS_AND_UP(int key) {
    INPUT input;
    WORD vkey = key;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = vkey;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));

    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

/// <summary>
/// EDUARDO GODOY 08/05/2020
/// Envia o comando para pressionar a tecla passada por parâmetro (virtual key) e mantem ela pressionada.
/// </summary>
/// <param name="key"></param>

void KEY_PRESS_DOWN(int key) {
    INPUT input;
    WORD vkey = key;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = MapVirtualKey(vkey, MAPVK_VK_TO_VSC);
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = vkey;
    input.ki.dwFlags = 0;
    SendInput(1, &input, sizeof(INPUT));

}
