// Surgeon.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
// Создаём структуры для инструментов
// Это для скальпеля и иголки
struct basicTools
{
	int ax, ay, bx, by;
};
// Это для пинцета и зажима
struct simpleTools
{
	int x, y;
};
// Описание функций
void cutter(std::string cmd, basicTools& tools, bool& incision);

void pinch(std::string cmd, simpleTools& tools, bool incision);

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
