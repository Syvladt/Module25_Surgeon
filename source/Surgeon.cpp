// Surgeon.cpp: Симулятор проведения операций.
// Цитирую: "Пользователь взаимодействует с программой с помощью команд.
// Команды не имеют сложной встроенной логики: они просто принимают
// нужные данные в качестве аргументов и выводят сообщения в консоль о выполнении."
// И опять же я не хирург и в какой последовательности выполнять операции ?????

#include <iostream>
#include <string>
#include <algorithm>
#include "Surgeon.h"

int main()
{
	basicTools scalpel, suture;
	simpleTools hemostat, tweezers;
	std::string cmd;
	bool incision = false;
	while(true)
	{	// Тут всё просто, принимаем команды и вызываем соответствующие функции
		// Для зажима и пинцета одна функция, т.к. их примение похожи.
		// Для скальпеля и иголки функции тоже похожи.
		std::cout << "Enter command(SCALPEL, HEMOSTAT, TWEEZERS, SUTURE): ";
		std::cin >> cmd;
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);
		if (cmd == "SCALPEL")
			cutter(cmd, scalpel, incision);
		else if (cmd == "HEMOSTAT" && incision)
			pinch(cmd, hemostat, incision);
		else if (cmd == "TWEEZERS" && incision)
			pinch(cmd, tweezers, incision);
		else if (cmd == "SUTURE" && incision)
		{	// Если координаты разреза совпадают с координатами шва - операция считается завершённой.
			// Можно было задать ещё обратное соответствие (начало разреза может быть концом шва), но суть задачи в другом.
			cutter(cmd, suture, incision);
			if (suture.ax == scalpel.ax && suture.ay == scalpel.ay && suture.bx == scalpel.bx && suture.by == scalpel.by)
			{
				std::cout << "The operation is over.\n";
				break;
			}
		}
		else if (!incision)
			std::cout << "The operation in not beging.\n";
		else
			std::cout << "Hey, where are you going? Come back and finish it.\n";
	}
	std::cout << "Thank you for use my program.\n";
	return 0;
}
