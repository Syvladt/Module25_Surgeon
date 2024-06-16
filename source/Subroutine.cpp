// В этом файле хранятся вызываемые функции.
// Можно было бы анализировать координаты применения инструментов, но в условии
// Написано, что процедуры не содержат сложной логики.
// Также можно было в вектор записывать установленные зажимы и потом пока их
// все не снимут - не завершать операцию, даже если шов уже выполнен, но я не врач
// и опять же это уже сложная логика.
#include <iostream>
#include <string>
#include "Surgeon.h"
// Процедура запрашивает координаты начала и конца для скальпеля и иглы
// И выводит сообщение, что разрез/шов завершены успешно
void cutter(std::string cmd, basicTools& tools, bool& incision)
{
	if (cmd == "SCALPEL")
	{
		if (incision)
		{
			std::cout << "The incision has already been completed successfully.\n";
		}
		else
		{
			std::cout << "Enter the coordinates of the beginning of the incision (x y): ";
			std::cin >> tools.ax >> tools.ay;
			std::cout << "Enter the coordinates of the end of the incision (x y): ";
			std::cin >> tools.bx >> tools.by;
			std::cout << "The incision was completed successfully\n";
			incision = true;
		}
	}
	else
	{
		std::cout << "Enter the coordinates of the beginning of the suture (x y): ";
		std::cin >> tools.ax >> tools.ay;
		std::cout << "Enter the coordinates of the end of the suture (x y): ";
		std::cin >> tools.bx >> tools.by;
		std::cout << "The suture was completed successfully\n";
	}
}
// Процедура запрашивает координаты куда устанавливается зажим/пинцет
// И выводит сообщение об успехе.
void pinch(std::string cmd, simpleTools& tools, bool incision)
{
	if (cmd == "HEMOSTAT")
	{
		std::cout << "Enter the coordinates of the hemostat installation (x y): ";
		std::cin >> tools.x >> tools.y;
		std::cout << "The hemostatic agent is installed.\n";
	}
	else
	{
		std::cout << "Enter the coordinates of the tweezer application (x y): ";
		std::cin >> tools.x >> tools.y;
		std::cout << "The doctor used the tweezers.\n";
	}
}