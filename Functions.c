#include "declaration.h"

void outputFromFile(MyFilm* films) {
	char ch;
	FILE* fR; // ��������� ��'���� �����
	fR = fopen("Films.txt", "r"); // ³������� ����� ��� �������
	if (fR == NULL) // �������� �� ������� ��������
	{
		printf("Error!");
		exit(1);
	}

	system("cls");

	while ((ch = fgetc(fR)) != EOF) // ��������� ����� ����� �� ����
		printf("%c",ch);
	fclose(fR); // �������� �����

	printf("Reading is OK, 'q' to exit "); // ���������� ���� ������
	while ((ch = getchar()) != 'q')
	{
		if (ch == '\n')
			printf("Click 'q' to exit: ");
	}
}

void inputInFile(MyFilm* films) {
	static int counter; // ³���� �������� �� ������� ����������� ������ � ����
	char ch;
	FILE *fW;// ��������� ��'���� �����
	fW = fopen("Films.txt", "w"); // ³�������\��������� ����� ��� ������
	for (counter = 0; films[counter].personalRating < UINT_MAX / 2; counter++) { // �������� ����� � ����� ��� ������� ��������
		fprintf(fW, "%d)", counter + 1);
		fprintf(fW, "\tName of film: %s\n", films[counter].name.string);
		fprintf(fW, "  \tMy personal rating: %d\n", films[counter].personalRating);
		fprintf(fW, "  \tIMDB rating: %.2f\n\n", films[counter].imdbRating);
	}
	fclose(fW);// �������� �����

	system("cls");
	printf("Writing is OK, 'q' to exit "); // ���������� ���� ������
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
	ch = checkInt(0); // �������� ����� �����������, � ������ �� ���� ������
	switch (ch)
	{
	case '1': // ����� �� ���� ������
		printf("Input name: ");
		temp = getMyStr(); // ������ ��� ����� �����������
		for (i = 0; films[i].personalRating < UINT_MAX / 2; i++) { // ������� �������� �� �������� ������������� ���������
			if (!strcmp(films[i].name.string, temp.string)) { // �������� ���� �������� ����� �� �������� ���������
				outputFilm(films, i); // ������ ������� ������ ��������� ���������
				check = 0;
			}
		}
		if (check) { // ���� 1 �� �� �������� �� �������� ����������
			printf("Can't find \"%s\" name of film\n", temp.string);
		}
		free(temp.string); // ���������� ���'�� ���� ����� �����������
		break;

	case '2':
		printf("Input number: ");
		temp = getMyStr();
		int tempInt = atoi(temp.string); // ������������ � ����� ����������� char �� int
		for(i = 0; films[i].personalRating < UINT_MAX / 2; i++){ // ������� �������� �� �������� ������������� ���������
			if (films[i].personalRating == tempInt) { // �������� ���� �������� ����� �� �������� ���������
				outputFilm(films, i); // ������ ������� ������ ��������� ���������
				check = 0;
			}
		}
		if (check) { // ���� 1 �� �� �������� �� �������� ����������
			printf("Can't find %i personal rating\n", tempInt);
		}
		free(temp.string); // ���������� ���'�� ���� ����� �����������
		break;

	case '3':
		printf("Input number: ");
		temp = getMyStr();
		double tempDo = atof(temp.string); // ������������ � ����� ����������� char �� double
		for (i = 0; films[i].imdbRating < UINT_MAX / 2; i++) { // ������� �������� �� �������� ������������� ���������
			if (films[i].imdbRating == tempDo){ // �������� ���� �������� ����� �� �������� ���������
				outputFilm(films, i); // ������ ������� ������ ��������� ���������
				check = 0;
			}
		}
		if (check) { // ���� 1 �� �� �������� �� �������� ����������
			printf("Can't find %.2f IMDB rating\n", tempDo);
		}
		free(temp.string); // ���������� ���'�� ���� ����� �����������
		break;
	default:
		break;
	}

	printf("Click 'q' to exit: "); // ���������� ���� ������
	while ((ch = getchar()) != 'q')
	{
		if (ch == '\n')
			printf("Click 'q' to exit: ");
	}
}

void outputFilm(MyFilm* films, int i) { // �������� ���� ���������
	printf("%d)", i + 1);
	printf("\tName of film: %s\n", films[i].name.string);
	printf("  \tMy personal rating: %d\n", films[i].personalRating);
	printf("  \tIMDB rating: %.2f\n\n", films[i].imdbRating);
}

void outputSetFilms(MyFilm* films) { // �������� �� ���������
	char ch;
	system("cls"); // ������� ������
	for (int i = 0; films[i].personalRating < UINT_MAX/2; i++) {
		printf("%d)", i+1);
		printf("\tName of film: %s\n", films[i].name.string);
		printf("  \tMy personal rating: %d\n", films[i].personalRating);
		printf("  \tIMDB rating: %.2f\n\n", films[i].imdbRating);
	}
	printf("Click 'q' to exit: "); // ���������� ���� ������
	while ((ch = getchar()) != 'q')
	{
		if(ch == '\n')
			printf("Click 'q' to exit: ");
	}
}

void inputInform(MyFilm* films) {
	char ch[256]; // ��������� ����� �� ��� �����������
	int i, check;
	i = 0;

	while (1) {
		system("cls");
		check = 1;

		printf("Input name of film: ");
		films[i].name = getMyStr(); // ������ ������������ ������ ����� ������
		printf("\n");

		printf("Input IMDB rating: ");
		while (!testVal(ch, 1)); // �������� ����� � ������ ������ double
		films[i].imdbRating = atof(ch); // ������������ ����� � double �� ��������� ����� ���������
		printf("\n");

		printf("Input personal rating: ");
		while (!testVal(ch, 0)); // �������� ����� � ������ ������ int
		films[i].personalRating = atoi(ch); // ������������ ����� � int �� ��������� ����� ���������
		printf("\n");

		if (i++ == size_ar) { // �� ������, �� ������
			size_ar++;
			//Dont work, TODO;
			films = (MyFilm*)realloc(films, sizeof(MyFilm) * size_ar);
			if (films == NULL) {
				exit("Unable to allocate");
			}
		}

		printf("Record another movie? \nClick button 'y' for yes or 'q' to exit: "); // ���� ������� ������ �� ���� ����� ��� �����
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

int testVal(char* str, int type) { // ������� �������� ������� �����
	while (type && isdigit(*str = getchar()) || *str == '.' || *str == ',' || *str == '\n') { // �� ������ type �������� �� ������� �����
		if (*str++ == '\n') {
			*(str - 1) = '\0';
			return 1;
		}
	}
	while (!type && isdigit(*str = getchar()) || *str == '\n') { // �� ������ type �������� �� ���� �����
		if (*str++ == '\n') {
			*(str - 1) = '\0';
			return 1;
		}
	}

	while ((* str = getchar()) != '\n') { // ����-���� �� ��������� ���� ���� ��������
		str++;
	}
	printf("Wrong input, try again: "); // ������ �� ������� �� ���
	return 0;
	
}

char checkInt(int check) { // ������� �������� ������� �����
	char temp, ch;
	int digit, charac; // ���� ����� ��� �������� �� ����������� �����
	digit = charac = 0;
	if (check){ // ���� �� ������� ����
		system("cls");
		printf("Select movie recording menu: \n1) Input films; \n2) Show a set of films; \n3) Record into a file; \n4) Read from file; \n5) Find by characteristic; \n6) Exit; \nChoise: ");
	}
	else { // ���� �� ���� ������
		system("cls");
		printf("Select search parameter: \n1) Name; \n2) Personal rating; \n3) IMDB; \nChoise: ");
	}
	while (temp = getchar()) { // �������� ������ �����, ���� ���� �� ���� ������ ���������� ���
		charac++;
		if (charac == 1 && isdigit(temp)) {
			digit++;
			ch = temp;
		}
		else if (digit == 1 && charac == 2 && temp == '\n') {
			break;
		}
		else if (temp == '\n') {
			if (check){ // ���� �� ������� ����
				system("cls");
				printf("Select movie recording menu: \n1) Input films; \n2) Show a set of films; \n3) Record into a file; \n4) Read from file; \n5) Find by characteristic; \n6) Exit; \nChoise: ");
			}
			else { // ���� �� ���� ������
				system("cls");
				printf("Select search parameter: \n1) Name; \n2) Personal rating; \n3) IMDB; \nChoise: ");
			}
			charac = 0;
			digit = 0;
		}
	}
	return ch; // ������� ��������� �����
}

