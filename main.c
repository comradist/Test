#include "declaration.h"

int main()
{
	char ch;
	size_ar = 100; // ����� ������ ��������
	MyFilm* films = (MyFilm*)malloc(sizeof(MyFilm) * size_ar); // ��������� ������ �������� ����� ������ ����� � ���

	while (1) { // ������� ���� ��� �����������
		ch = checkInt(1);// �������� �����
		switch (ch)
		{
		case '1':
			inputInform(films);// ������ ������� ������ ��������
			break;
		case '2':
			outputSetFilms(films);// ������ ������� ������ �������� ��������
			break;
		case '3':
			inputInFile(films);// �������� ���� � ����
			break;
		case '4':
			outputFromFile(films);// ������� ���� � �����
			break;
		case '5':
			search(films);// ����� �� ���������
			break;
		case '6':
			return 0;// ����� � ��������
		default:
			break;
		}
	}

}