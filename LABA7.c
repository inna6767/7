#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int simvol(char c);
float kalk(float x, char op, float y);
void zadenie3(void);

int main(void)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

     //Задание 1
    char c1;
    int res1;
    printf("Задание 1:\n");
    printf("Введите символ: ");
    scanf(" %c", &c1);
    res1 = simvol(c1);
    if (res1 == 1)
        printf("Это цифра\n");
    else if (res1 == 2)
        printf("Это буква\n");
    else
        printf("Неизвестный символ\n");

     //Задание 2
    float x, y, res2;
    char op;
    printf("\nЗадание 2:\n");
    printf("Введите выражение (например, 2 + 3): ");
    if (scanf("%f %c %f", &x, &op, &y) != 3) {
        printf("Ошибка ввода\n");
        return 1;
    }
    if (op == '/' && y == 0.0f) {
        printf("Ошибка: деление на ноль\n");
    }
    else if (op != '+' && op != '-' && op != '*' &&
        op != '/' && op != '^') {
        printf("Ошибка: неизвестная операция\n");
    }
    else if (op == '^') {
        if ((int)y != y || y < 0 || y > 3) {
            printf("Ошибка: поддерживаются только степени 0, 1, 2, 3\n");
        }
        else {
            res2 = kalk(x, op, y);
            printf("Результат: %.2f\n", res2);
        }
    }
    else {
        res2 = kalk(x, op, y);
        printf("Результат: %.2f\n", res2);
    }

     //Задание 3: 
    zadenie3();

    return 0;
}

//Задание 1 
int simvol(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 2;
    else
        return 0;
}

 //Задание 2 
float kalk(float x, char op, float y)
{
    float result = 0.0f;
    if (op == '+')
        result = x + y;
    else if (op == '-')
        result = x - y;
    else if (op == '*')
        result = x * y;
    else if (op == '/')
        result = x / y;
    else if (op == '^') {
        if (y == 0)      result = 1.0f;
        else if (y == 1) result = x;
        else if (y == 2) result = x * x;
        else if (y == 3) result = x * x * x;
    }
    return result;
}

 //Задание 3 
void zadenie3(void)
{
    int number;
    printf("\nЗадание 3:\n");
    printf("Введите число от 1 до 12: ");
    if (scanf("%d", &number) != 1) {
        printf("Ошибка ввода! Ожидалось целое число.\n");
        return;
    }
    printf("Римское представление: ");
    switch (number) {
    case 1:  printf("I\n");   break;
    case 2:  printf("II\n");  break;
    case 3:  printf("III\n"); break;
    case 4:  printf("IV\n");  break;
    case 5:  printf("V\n");   break;
    case 6:  printf("VI\n");  break;
    case 7:  printf("VII\n"); break;
    case 8:  printf("VIII\n");break;
    case 9:  printf("IX\n");  break;
    case 10: printf("X\n");   break;
    case 11: printf("XI\n");  break;
    case 12: printf("XII\n"); break;
    default:
        printf("\nОшибка: введено число вне диапазона от 1 до 12!\n");
        break;
    }
}