#include "declaration.h"

void outputFromFile(MyFilm* films) {
	char ch;
	FILE* fR; // Створення об'єкта файла
	fR = fopen("Films.txt", "r"); // Відкриття файлу для читання
	if (fR == NULL) // Перевірка на помилку відкриття
	{
		printf("Error!");
		exit(1);
	}

	system("cls");

	while ((ch = fgetc(fR)) != EOF) // Виводення вмісту файла до кінця
		printf("%c",ch);
	fclose(fR); // Закриття файлу

	printf("Reading is OK, 'q' to exit "); // Стандартне меню виходу
	while ((ch = getchar()) != 'q')
	{
		if (ch == '\n')
			printf("Click 'q' to exit: ");
	}
}

void inputInFile(MyFilm* films) {
	static int counter; // Вічний лічильник на випадок додадковогу запису у файл
	char ch;
	FILE *fW;// Створення об'єкта файла
	fW = fopen("Films.txt", "w"); // Відкриття\створення файлу для запису
	for (counter = 0; films[counter].personalRating < UINT_MAX / 2; counter++) { // Циклічний запис у файлу всіх значень структур
		fprintf(fW, "%d)", counter + 1);
		fprintf(fW, "\tName of film: %s\n", films[counter].name.string);
		fprintf(fW, "  \tMy personal rating: %d\n", films[counter].personalRating);
		fprintf(fW, "  \tIMDB rating: %.2f\n\n", films[counter].imdbRating);
	}
	fclose(fW);// Закриття файлу

	system("cls");
	printf("Writing is OK, 'q' to exit "); // Стандартне меню виходу
	while ((ch = getchar()) != 'q')
	{
		if (ch == '\n')
			printf("Click 'q' to exit: ");
	}

}

void search(MyFilm* films) {
	MyString temp;
	char ch;
	int check = 1;
	int i = 0;
	ch = checkInt(0); // Перевірка вводу користувача, з флагом під меню пошуку
	switch (ch)
	{
	case '1': // Пошук по імені фільму
		printf("Input name: ");
		temp = getMyStr(); // Строка для вводу користувача
		for (i = 0; films[i].personalRating < UINT_MAX / 2; i++) { // Циклічна перевірка до останньої ініціалізованної структури
			if (!strcmp(films[i].name.string, temp.string)) { // Перевірка збігу значення вводу та значення структури
				outputFilm(films, i); // Виклик функції виводу необхідної структури
				check = 0;
			}
		}
		if (check) { // Якщо 1 то не знайдено за вказаним параметром
			printf("Can't find \"%s\" name of film\n", temp.string);
		}
		free(temp.string); // Визволення пам'яті після вводу користувача
		break;

	case '2':
		printf("Input number: ");
		temp = getMyStr();
		int tempInt = atoi(temp.string); // Перетворення з вводу користувача char на int
		for(i = 0; films[i].personalRating < UINT_MAX / 2; i++){ // Циклічна перевірка до останньої ініціалізованної структури
			if (films[i].personalRating == tempInt) { // Перевірка збігу значення вводу та значення структури
				outputFilm(films, i); // Виклик функції виводу необхідної структури
				check = 0;
			}
		}
		if (check) { // Якщо 1 то не знайдено за вказаним параметром
			printf("Can't find %i personal rating\n", tempInt);
		}
		free(temp.string); // Визволення пам'яті після вводу користувача
		break;

	case '3':
		printf("Input number: ");
		temp = getMyStr();
		double tempDo = atof(temp.string); // Перетворення з вводу користувача char на double
		for (i = 0; films[i].imdbRating < UINT_MAX / 2; i++) { // Циклічна перевірка до останньої ініціалізованної структури
			if (films[i].imdbRating == tempDo){ // Перевірка збігу значення вводу та значення структури
				outputFilm(films, i); // Виклик функції виводу необхідної структури
				check = 0;
			}
		}
		if (check) { // Якщо 1 то не знайдено за вказаним параметром
			printf("Can't find %.2f IMDB rating\n", tempDo);
		}
		free(temp.string); // Визволення пам'яті після вводу користувача
		break;
	default:
		break;
	}

	printf("Click 'q' to exit: "); // Стандартне меню виходу
	while ((ch = getchar()) != 'q')
	{
		if (ch == '\n')
			printf("Click 'q' to exit: ");
	}
}

void outputFilm(MyFilm* films, int i) { // Виводить одну структуру
	printf("%d)", i + 1);
	printf("\tName of film: %s\n", films[i].name.string);
	printf("  \tMy personal rating: %d\n", films[i].personalRating);
	printf("  \tIMDB rating: %.2f\n\n", films[i].imdbRating);
}

void outputSetFilms(MyFilm* films) { // Виводить всі структури
	char ch;
	system("cls"); // Очистка консолі
	for (int i = 0; films[i].personalRating < UINT_MAX/2; i++) {
		printf("%d)", i+1);
		printf("\tName of film: %s\n", films[i].name.string);
		printf("  \tMy personal rating: %d\n", films[i].personalRating);
		printf("  \tIMDB rating: %.2f\n\n", films[i].imdbRating);
	}
	printf("Click 'q' to exit: "); // Стандартне меню виходу
	while ((ch = getchar()) != 'q')
	{
		if(ch == '\n')
			printf("Click 'q' to exit: ");
	}
}

void inputInform(MyFilm* films) {
	char ch[256]; // Тимчасова змінна під ввід користувача
	int i, check;
	i = 0;

	while (1) {
		system("cls");
		check = 1;

		printf("Input name of film: ");
		films[i].name = getMyStr(); // Виклик структурного методу вводу строки
		printf("\n");

		printf("Input IMDB rating: ");
		while (!testVal(ch, 1)); // Перевірка вводу з флагом пошуку double
		films[i].imdbRating = atof(ch); // Перетворення вводу у double та ініціалізую змінну структури
		printf("\n");

		printf("Input personal rating: ");
		while (!testVal(ch, 0)); // Перевірка вводу з флагом пошуку int
		films[i].personalRating = atoi(ch); // Перетворення вводу у int та ініціалізую змінну структури
		printf("\n");

		if (i++ == size_ar) { // Не працює, не чіпати
			size_ar++;
			//Dont work, TODO;
			films = (MyFilm*)realloc(films, sizeof(MyFilm) * size_ar);
			if (films == NULL) {
				exit("Unable to allocate");
			}
		}

		printf("Record another movie? \nClick button 'y' for yes or 'q' to exit: "); // Меню запросу ввести ще один фільм або вийти
		do {
			char temp = '\0';
			switch (temp = getchar())
			{
			case 'q':
				return 1;
			case 'y':
				fseek(stdin, 0, SEEK_END);
				check = 0;
				break;
			case '\n':
				printf("Try again, 'y' or 'q': ");
				break;
			default:
				break;
			}
		} while (check);

	}
}

int testVal(char* str, int type) { // Функція перевірки введеної змінної
	while (type && isdigit(*str = getchar()) || *str == '.' || *str == ',' || *str == '\n') { // За флагом type перевіряє на знакове число
		if (*str++ == '\n') {
			*(str - 1) = '\0';
			return 1;
		}
	}
	while (!type && isdigit(*str = getchar()) || *str == '\n') { // За флагом type перевіряє на ціле число
		if (*str++ == '\n') {
			*(str - 1) = '\0';
			return 1;
		}
	}

	while ((* str = getchar()) != '\n') { // Будь-який не чисельний ввод буде зкинутий
		str++;
	}
	printf("Wrong input, try again: "); // Запрос на введеня ще раз
	return 0;
	
}

char checkInt(int check) { // Функція перевірки введеної змінної
	char temp, ch;
	int digit, charac; // Змінні флаги для оминання не правильного вводу
	digit = charac = 0;
	if (check){ // Флаг під головне меню
		system("cls");
		printf("Select movie recording menu: \n1) Input films; \n2) Show a set of films; \n3) Record into a file; \n4) Read from file; \n5) Find by characteristic; \n6) Exit; \nChoise: ");
	}
	else { // Флаг під меню пошуку
		system("cls");
		printf("Select search parameter: \n1) Name; \n2) Personal rating; \n3) IMDB; \nChoise: ");
	}
	while (temp = getchar()) { // Циклічний запрос вводу, доти поки не буде логічно правильний ввід
		charac++;
		if (charac == 1 && isdigit(temp)) {
			digit++;
			ch = temp;
		}
		else if (digit == 1 && charac == 2 && temp == '\n') {
			break;
		}
		else if (temp == '\n') {
			if (check){ // Флаг під головне меню
				system("cls");
				printf("Select movie recording menu: \n1) Input films; \n2) Show a set of films; \n3) Record into a file; \n4) Read from file; \n5) Find by characteristic; \n6) Exit; \nChoise: ");
			}
			else { // Флаг під меню пошуку
				system("cls");
				printf("Select search parameter: \n1) Name; \n2) Personal rating; \n3) IMDB; \nChoise: ");
			}
			charac = 0;
			digit = 0;
		}
	}
	return ch; // Повертає необхідну змінну
}

