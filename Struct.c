#include "declaration.h"

MyString getMyStr() {
    MyString myStr; // Екземпляр під динамічну строку
    myStr.string = NULL; // Вкізівник вказує на нульове значення
    myStr.sizeb = 32; // Ліміт блока пам'яті
    myStr.sizec = 0; // Лічильник символів
    int checkMax = 0; // Перевірочний біт на переповнення блоку пам'яті
    int memoryTest = 1; // Перевірочний біт на помилку виділення пам'яті
    char ch = '\0'; // Змінна для прийому значеннь користувача

    if ((myStr.string = (char*)malloc(myStr.sizeb)) == NULL) { // Виділення блоку пам'яті
        memoryTest = 0;
        printf("Unable to reallocate %d bytes of memory for string\n", myStr.sizeb);
    }

    while (1) { // Цикл запису строки
        if (memoryTest && checkMax && (myStr.string = (char*)realloc(myStr.string, myStr.sizeb + 32)) == NULL) { // Виділення новогу блоку пам'яті
            memoryTest = 0;
        }
        checkMax = 0;

        while (memoryTest && ch != '\n' && myStr.sizec < myStr.sizeb - 1) {
            ch = getchar();
            myStr.string[myStr.sizec++] = ch; // Запис символу та збільшення ітератора sizec
        }

        if (ch == '\n' || !memoryTest) { // Перевірка на помилки та кінця вводу
            if (!memoryTest) {
                myStr.string = NULL;
                myStr.sizeb = 32;
                myStr.sizec = 0;
                printf("Unable to reallocate memory for character buffer.\n");
            }
            if (ch == '\n') {
                myStr.string[myStr.sizec - 1] = '\0';
                myStr.sizec--;
            }
            return myStr; // Повертає значення вказівника динамічно віділеної пам'яті
        }
        else {
            myStr.sizeb += 32; // Якщо ліміт то збільшити блок виділеної пам'яті
            checkMax = 1;
        }

    }
}