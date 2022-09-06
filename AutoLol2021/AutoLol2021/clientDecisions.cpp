#include "header.h"




int clientSinalizer(int &x, int &y) {

	cv::Mat screen, temp;

	char files[10][64] = {
		"templates\\CLIENT\\AceitarPartida.jpeg",
		"templates\\CLIENT\\BotaoOk.jpeg",
		"templates\\CLIENT\\Confirmar.jpeg",
		"templates\\CLIENT\\ChampEscolhido.jpeg",
		"templates\\CLIENT\\BuscarChamp.jpeg",
		"templates\\CLIENT\\EncontrarPartida.jpeg",
		"templates\\CLIENT\\HonrarColega.jpeg",
		"templates\\CLIENT\\email.jpeg",
		"templates\\CLIENT\\selecionar.jpeg",
	"templates\\CLIENT\\jogarnovamente.jpeg" };

	//take screenshot
	screenshot(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 0, 0, "templates\\CLIENT\\desktop.jpeg"); 
	screen = cv::imread("templates\\CLIENT\\desktop.jpeg");

	for (int i = 0; i < 10; i++)
	{
		temp = cv::imread(files[i]);

		if (MATCHING_METHOD_MODULAR(screen, temp, 0.95, x, y, 3) == true)
		{
			
			return i;
		}
	}

	screen.release();
	temp.release();

	return 100;
}

void mainClientDecisions()
{
	int x, y;

	for (;;)
	{
		switch (clientSinalizer(x, y))
		{
		case 0:
			std::cout << "[>>] Aceitar Partida" << std::endl;
			SetCursorPos(x + 10, y + 5);
			MOUSE_CLICK_LEFT();
			Sleep(100);
			break;
		case 1:
			std::cout << "[>>] Clicando em OK" << std::endl;
			SetCursorPos(x + 10, y + 5);
			MOUSE_CLICK_LEFT();
			Sleep(100);
			break;
		case 4:
			std::cout << "[>>] Buscando champ" << std::endl;
			selectChamp(x,y);
			break;
		case 3:
			std::cout << "[>>] Campeao escolhido, aguardando..." << std::endl;
			Sleep(500);
			break;

		case 2:
			std::cout << "[>>] Clicando em Confirmar" << std::endl;
			SetCursorPos(x + 15, y + 15);
			MOUSE_CLICK_LEFT();
			Sleep(100);
			break;
		case 5:
			std::cout << "[>>] Iniciar Fila" << std::endl;
			SetCursorPos(x + 100, y + 15);
			MOUSE_CLICK_LEFT();
			Sleep(100);
			break;
		case 6:
			std::cout << "[>>] Honrando" << std::endl;
			SetCursorPos(x + 100, y + 200);
			MOUSE_CLICK_LEFT();
			Sleep(100);
			break;
		case 9:
			std::cout << "[>>] Clicando em jogar novamente" << std::endl;
			SetCursorPos(x + 100, y + 15);
			MOUSE_CLICK_LEFT();
			Sleep(100);
			break;
		case 8:
			std::cout << "[>>] selecionando reconpensa" << std::endl;
			SetCursorPos(x + 50, y + 10);
			MOUSE_CLICK_LEFT();
			Sleep(100);
			break;
		case 7:
			std::cout << "[>>] Fechando mensagem de confirmação de email" << std::endl;//EXTREMA GAMBIARRA MAS FUNCIONA FODA-SE MAKE IT SIMPLE
			SetCursorPos(x + 325, y - 505);
			MOUSE_CLICK_LEFT();
			Sleep(100);
			break;

		default:
			break;
		}

		if (CHECK_PROCESS() == true)
		{
			std::cout << "[>>] Aguardando 30 segundos até mover a tela" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(30));
			playingMode();
		}

	}

}

void selectCaitlyn (int x, int y) {

	int aux, auy;

	SetCursorPos(x + 10, y + 5);
	MOUSE_CLICK_LEFT();
	Sleep(50);
	KEY_PRESS_AND_UP(67);//c
	KEY_PRESS_AND_UP(65);//a
	KEY_PRESS_AND_UP(73);//i
	KEY_PRESS_AND_UP(84);//t
	KEY_PRESS_AND_UP(76);//l
	KEY_PRESS_AND_UP(89);//y
	KEY_PRESS_AND_UP(78);//n

	Sleep(1000);

	screenshot(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 0, 0, "templates\\CLIENT\\desktop.jpeg");
	cv::Mat screen = cv::imread("templates\\CLIENT\\desktop.jpeg");
	cv::Mat temp = cv::imread("templates\\CLIENT\\caitlyn.jpeg");

	if (MATCHING_METHOD_MODULAR(screen, temp, 0.99, aux, auy, 3) == true) {
		SetCursorPos(aux + 25, auy + 15);
		MOUSE_CLICK_LEFT();
		Sleep(300);
		SetCursorPos(x + 90, y + 5);
		MOUSE_CLICK_LEFT();
		for (int k = 0; k < 15; k++)
		{
			KEY_PRESS_AND_UP(8);//APAGAR
		}
		SetCursorPos(x + 150, y + 30);
		MOUSE_CLICK_LEFT();
	}
	else {
		for (int k = 0; k < 15; k++)
		{
			KEY_PRESS_AND_UP(8);//APAGAR
		}
		SetCursorPos(x + 150, y + 30);
		MOUSE_CLICK_LEFT();
		std::cout << "[***] ERRO AO SELECIONAR CAMPEAO" << std::endl;
	}
	screen.release();
	temp.release();
}
void selectMiss(int x, int y) {

	int aux, auy;

	SetCursorPos(x + 10, y + 5);
	MOUSE_CLICK_LEFT();
	Sleep(50);
	KEY_PRESS_AND_UP(77);//M
	KEY_PRESS_AND_UP(73);//I
	KEY_PRESS_AND_UP(83);//S
	KEY_PRESS_AND_UP(83);//S

	Sleep(1000);

	screenshot(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 0, 0, "templates\\CLIENT\\desktop.jpeg");
	cv::Mat screen = cv::imread("templates\\CLIENT\\desktop.jpeg");
	cv::Mat temp = cv::imread("templates\\CLIENT\\missFortune.jpeg");

	if (MATCHING_METHOD_MODULAR(screen, temp, 0.99, aux, auy, 3) == true) {
		SetCursorPos(aux + 25, auy + 15);
		MOUSE_CLICK_LEFT();
		Sleep(300);
		SetCursorPos(x + 90, y + 5);
		MOUSE_CLICK_LEFT();
		for (int k = 0; k < 15; k++)
		{
			KEY_PRESS_AND_UP(8);//APAGAR
		}
		SetCursorPos(x + 150, y + 30);
		MOUSE_CLICK_LEFT();

	}
	else {
		for (int k = 0; k < 15; k++)
		{
			KEY_PRESS_AND_UP(8);//APAGAR
		}
		SetCursorPos(x + 150, y + 30);
		MOUSE_CLICK_LEFT();
		std::cout << "[***] ERRO AO SELECIONAR CAMPEAO" << std::endl;
	}

	screen.release();
	temp.release();
}

void selectChamp(int x, int y) {
	

	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(1, 2);

		if (distr(eng) == 1) {
			std::cout << "[>> Caitlyn] Selecionando..." << std::endl;
			selectCaitlyn(x,y);
		}
		else {
			std::cout << "[>> MissFortune] Selecionando..." << std::endl;
			selectMiss(x,y);
		}

}