#pragma once
#pragma warning(disable : 4996) // ����� ������� VS
#include <stdio.h>  
#include <stdlib.h>
#include <string.h> 
#include <malloc.h>
#include <conio.h>
#include <ctype.h>

typedef struct { // ��������� ��� ���������� �������� ���'�� �� ����� ������
    char* string; // �������� �� ������
    size_t sizec; // ��������� ����� ������
    size_t sizeb; // ������������ ����� ��� ������� �������� ���'��
}MyString;

typedef struct { // ������ ������
    int personalRating; // ֳ�� ����� �� ������� �������
    double imdbRating; // ������� ����� �� �������
    MyString name; // ��������� ��'� ������
}MyFilm;

MyString getMyStr(); // ��'��� ������������ ������

void outputFromFile(MyFilm*); // ��'��� ������� ������� � �����
void inputInFile(MyFilm*); // ��'��� ������� ������ � ����
void outputFilm(MyFilm*, int); // ��'��� ������� ������ � ������� ���� ���������
void search(MyFilm*); // ��'��� ������� ������ �� ����������
char checkInt(int); // ��'��� ������� �������� �������� ��� ����
void inputInform(MyFilm*); // ��'��� ������� ������ ���������� ������
void outputSetFilms(MyFilm*); // ��'��� ������� ������ � ������� ������� ��� �������� 
int size_ar; // ��'��� ��������� ����� �� ����� ������ ��������