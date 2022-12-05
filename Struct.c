#include "declaration.h"

MyString getMyStr() {
    MyString myStr; // ��������� �� �������� ������
    myStr.string = NULL; // ������� ����� �� ������� ��������
    myStr.sizeb = 32; // ˳�� ����� ���'��
    myStr.sizec = 0; // ˳������� �������
    int checkMax = 0; // ����������� �� �� ������������ ����� ���'��
    int memoryTest = 1; // ����������� �� �� ������� �������� ���'��
    char ch = '\0'; // ����� ��� ������� �������� �����������

    if ((myStr.string = (char*)malloc(myStr.sizeb)) == NULL) { // �������� ����� ���'��
        memoryTest = 0;
        printf("Unable to reallocate %d bytes of memory for string\n", myStr.sizeb);
    }

    while (1) { // ���� ������ ������
        if (memoryTest && checkMax && (myStr.string = (char*)realloc(myStr.string, myStr.sizeb + 32)) == NULL) { // �������� ������ ����� ���'��
            memoryTest = 0;
        }
        checkMax = 0;

        while (memoryTest && ch != '\n' && myStr.sizec < myStr.sizeb - 1) {
            ch = getchar();
            myStr.string[myStr.sizec++] = ch; // ����� ������� �� ��������� ��������� sizec
        }

        if (ch == '\n' || !memoryTest) { // �������� �� ������� �� ���� �����
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
            return myStr; // ������� �������� ��������� �������� ������ ���'��
        }
        else {
            myStr.sizeb += 32; // ���� ��� �� �������� ���� ������� ���'��
            checkMax = 1;
        }

    }
}