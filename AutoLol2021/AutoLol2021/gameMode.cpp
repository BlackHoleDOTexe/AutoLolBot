#include "header.h"





int baseControlModule() {

	cv::Mat screen, temp;
	int x, y;

	screenshot(19,13,605,751,"templates\\baseModule\\baseControlModuleScreen.jpeg");
	screen = cv::imread("templates\\baseModule\\baseControlModuleScreen.jpeg");
	temp = cv::imread("templates\\baseModule\\inBase.jpeg");


	if (MATCHING_METHOD_MODULAR(screen, temp, 0.96, x, y, 3) == true) {

		std::cout << "[>>]Estamos na base, iniciando procedimentos 'BaseControlModule'" << std::endl;
		Sleep(1000);

		//abrir a loja
		KEY_PRESS_AND_UP(80);//p
		Sleep(500);

		//procurar e clicar
		screenshot(1024, 768, 0, 0, "templates\\baseModule\\baseControlModuleScreen.jpeg");
		screen = cv::imread("templates\\baseModule\\baseControlModuleScreen.jpeg");
		temp = cv::imread("templates\\baseModule\\item.jpeg");
		if (MATCHING_METHOD_MODULAR(screen, temp, 0.90, x, y, 3) == true) {
			SetCursorPos(x + 10, y + 5);
			MOUSE_CLICK_RIGHT();
			MOUSE_CLICK_RIGHT();
		}
		Sleep(500);

		//fechar a loja
		KEY_PRESS_AND_UP(80);//p
		Sleep(10000);

		//clicar no minimapa e sair da base.
		SetCursorPos(850,685);
		MOUSE_CLICK_RIGHT();
		Sleep(500);

		std::cout << "[>>]Terminado procedimento de compra, andando até a lane 'BaseControlModule'" << std::endl;

		Sleep(10000);


	}

	screen.release();
	temp.release();
	return 0;
}


void verifyMinionsAlly() {

	int x, y, counter = 0;

	//load templates names
	char files[15][64] =
	{ "templates\\verifyMinionsAlly\\pngfiles\\life1.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life2.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life3.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life4.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life5.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life6.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life7.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life8.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life9.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life10.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life11.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life12.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life13.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life14.png",
	"templates\\verifyMinionsAlly\\pngfiles\\life15.png" };

	cv::Mat templatesArray[15], templatesArrayNorm[15];
	cv::Mat screen, screenNorm;

	for (int j = 0; j < 15; j++) {

		templatesArray[j] = cv::imread(files[j]);
		cv::normalize(templatesArray[j], templatesArrayNorm[j], 0, 255, cv::NORM_MINMAX, CV_8UC4);
	}

	do {
		//auto start = std::chrono::high_resolution_clock::now();
		//take screenshot
		screenshot(390, 370, 610, 40, "templates\\verifyMinionsAlly\\verifyMinionsAllyScreen.png");
		screen = cv::imread("templates\\verifyMinionsAlly\\verifyMinionsAllyScreen.png");
		cv::normalize(screen, screenNorm, 0, 255, cv::NORM_MINMAX, CV_8UC4);




		//find
		for (int i = 0; i < 15; i++) {

			if (MATCHING_METHOD_MODULAR(screen, templatesArray[i], 0.96, x, y, 3) == true)
			{

				//std::cout << "minion detected" << std::endl;

				//object detected
			}
			else
			{
				counter++;
			}

		}

		if (counter == 15)
		{
			minions = 0;
			counter = 0;
		}
		else {
			minions = 1;
			counter = 0;
		}


		//not detected
		//auto end = std::chrono::high_resolution_clock::now();

		//auto int_s = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

		screen.release();
		screenNorm.release();

	} while (CHECK_PROCESS() == true);

	for (int k = 0; k < 15; k++)
	{
		templatesArray[k].release();
		templatesArrayNorm[k].release();

	}
	screen.release();
	screenNorm.release();
	
}

void lowLifeDetection() {

	int x, y;
	//take screenshot
	screenshot(77, 8, 381, 744, "templates\\lowLifeModule\\lowLifeRect.jpeg");
	cv::Mat screen = cv::imread("templates\\lowLifeModule\\lowLifeRect.jpeg");
	cv::Mat temp = cv::imread("templates\\lowLifeModule\\lowLifeTemplate.jpeg");

	if (MATCHING_METHOD_MODULAR(screen, temp, 0.90, x, y, 3) == false) {
		
		std::cout << "LowLife detected" << std::endl;

		//go base
		SetCursorPos(790,750);
		MOUSE_CLICK_RIGHT();
		KEY_PRESS_AND_UP(68);//D
		KEY_PRESS_AND_UP(70);//F
		MOUSE_CLICK_RIGHT();
		MOUSE_CLICK_RIGHT();
		Sleep(10000);
		KEY_PRESS_AND_UP(66);//B
		Sleep(13000);

	}
	screen.release();
	temp.release();

}

void levelPrint() {

	cv::Mat screen, temp;

	int x, y, lvl = 0;

	char* vetSkills[18];

	SKILLS_FILE(vetSkills, "templates\\levelModule\\skillUpModule\\skills.txt");
	temp = cv::imread("templates\\levelModule\\skillUpModule\\pointB.jpeg");

	do
	{
		//take screenshot from game
		screenshot(1024, 768, 0, 0, "templates\\levelModule\\skillUpModule\\box.jpeg");
		screen = cv::imread("templates\\levelModule\\skillUpModule\\box.jpeg");




		if (MATCHING_METHOD_MODULAR(screen, temp, 0.90, x, y, 3) == true)
		{
			ABILITIES_SEQUENCE(lvl, vetSkills);
			lvl++;
			Sleep(5000);
		}
		screen.release();
		Sleep(3000);
		std::cout << "[>>]Aguardando para upar habilidade 'levelThread'" << std::endl;
	} while (CHECK_PROCESS() == true);
	screen.release();
	temp.release();

}

void enemyMinions() {
	cv::Mat screen, temp;

	int x, y;

	temp = cv::imread("templates\\enemmyWave\\life.jpeg");

	do {
		screenshot(1024, 768, 0, 0, "templates\\enemmyWave\\screen.jpeg");
		screen = cv::imread("templates\\enemmyWave\\screen.jpeg");

		if (MATCHING_METHOD_MODULAR(screen, temp, 0.96, x, y, 3) == true) {

			ennemyMinionDetect = true;

			Sleep(20000);//cooldown genérico foda-se

		}
		ennemyMinionDetect = false;
		screen.release();
		Sleep(3000);
		
		std::cout << "[>>]Aguardando wave inimiga 'enemmyWaveAtk'" << std::endl;

	} while (CHECK_PROCESS() == true);

	screen.release();
	temp.release();

}



void playingMode()
{

	int  x, y;

	Window_Move();

	Sleep(1000);

	cv::Mat screen, temp;

	temp = cv::imread("templates\\baseModule\\inBase.jpeg");

	do
	{
		Sleep(1000);
		screenshot(1024,768,0,0, "templates\\baseModule\\BaseControlModuleScreen.jpeg");
		screen = cv::imread("templates\\baseModule\\BaseControlModuleScreen.jpeg");

	} while (MATCHING_METHOD_MODULAR(screen,temp,0.96,x,y, 3) == false);

	for (int i = 0; i < 3; i++) {
		screenshot(1024, 768, 0, 0, "templates\\baseModule\\BaseControlModuleScreen.jpeg");
		screen = cv::imread("templates\\baseModule\\BaseControlModuleScreen.jpeg");
		temp = cv::imread("templates\\baseModule\\cameraLock.jpeg");
		if (MATCHING_METHOD_MODULAR(screen, temp, 0.95, x, y, 3) == true) {
			KEY_PRESS_AND_UP(89);//y
		}
		Sleep(1000);
	}//verificar 3 vezes para ter garantia

	screen.release();
	temp.release();
	
	std::thread* lvlthread = new std::thread(levelPrint);
	std::thread* ennemyWaveAtk = new std::thread(enemyMinions);
	std::thread* allyMinion = new std::thread(verifyMinionsAlly);


	bool PRESS_X = false;

	do
	{
		
		lowLifeDetection();
		baseControlModule();


		if (ennemyMinionDetect == true) {

			//attack with E and Q

			SetCursorPos(700, 250);
			Sleep(100);
			KEY_PRESS_AND_UP(69);//E KEY
			KEY_PRESS_AND_UP(81);//Q KEY
			Sleep(100);
			ennemyMinionDetect = false;
			
			if (minions == 1 && PRESS_X == false)
			{
				//atack
				SetCursorPos(977, 567);
				KEY_PRESS_AND_UP(88);//press X
				PRESS_X = true;
			}
			else
			{
				if (PRESS_X == true) {
					//back
					SetCursorPos(850, 685);
					MOUSE_CLICK_RIGHT();
					PRESS_X = false;
				}
			}
		}else if (minions == 1 && PRESS_X == false)
		{
			//atack
			SetCursorPos(977, 567);
			KEY_PRESS_AND_UP(88);//press X
			PRESS_X = true;
		}
		else
		{
			if (minions == 0 && PRESS_X == true) {
				//back
				SetCursorPos(850, 685);
				MOUSE_CLICK_RIGHT();
				PRESS_X = false;
			}
		}

		if (GetKeyState(VK_F10))
		{
			exit(0);//fecha bot
		}

	} while (CHECK_PROCESS() == true);

	Sleep(2000);
	lvlthread->detach();
	ennemyWaveAtk->detach();
	allyMinion->detach();
	delete(lvlthread);
	delete(ennemyWaveAtk);
	delete(allyMinion);
}