#pragma once
#pragma warning(disable : 4996) // Уникає помикли VS
#include <stdio.h>  
#include <stdlib.h>
#include <string.h> 
#include <malloc.h>
#include <conio.h>
#include <ctype.h>

typedef struct { // Структура для динамічного виділення пам'яті під назви фільмів
    char* string; // Вказівник на строку
    size_t sizec; // Фактичний розмір строки
    size_t sizeb; // Максимальний розмір для першого виділення пам'яті
}MyString;

typedef struct { // Шаблон фільму
    int personalRating; // Ціле число під власний рейтинг
    double imdbRating; // Знакове число під рейтинг
    MyString name; // Створення ім'я фільму
}MyFilm;

MyString getMyStr(); // Об'ява структурного методу

void outputFromFile(MyFilm*); // Об'ява функції читання з файлу
void inputInFile(MyFilm*); // Об'ява функції запису у файл
void outputFilm(MyFilm*, int); // Об'ява функції виводу у консоль однієї структури
void search(MyFilm*); // Об'ява функції пошуку за параметром
char checkInt(int); // Об'ява функції перевірки значення для меню
void inputInform(MyFilm*); // Об'ява функції запису екземпляра фільма
void outputSetFilms(MyFilm*); // Об'ява функції виводу у консоль значень всіх структур 
int size_ar; // Об'ява глобальної змінної під розмір масиву структур