#include "declaration.h"

int main()
{
	char ch;
	size_ar = 100; // Розмір масиву структур
	MyFilm* films = (MyFilm*)malloc(sizeof(MyFilm) * size_ar); // Створення масиву структур згідно розміру кожної з них

	while (1) { // Циклічне меню для користувача
		ch = checkInt(1);// Перевірка вводу
		switch (ch)
		{
		case '1':
			inputInform(films);// Виклик функції запису структур
			break;
		case '2':
			outputSetFilms(films);// Виклик функції виводу значення структур
			break;
		case '3':
			inputInFile(films);// Записати данні у файл
			break;
		case '4':
			outputFromFile(films);// Зчитати данні з файла
			break;
		case '5':
			search(films);// Пошук за значенням
			break;
		case '6':
			return 0;// Вихід з програми
		default:
			break;
		}
	}

}