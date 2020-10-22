#include <iostream>
#include <conio.h>
#include <stdio.h>

class Point { //определение класса Point
public:
    int x, y; //атрибуты(св-ва) объекта класса Point
    Point() { //конструктор по умолчанию
        printf("Вызвался конструктор Point по умолчанию.\n");
        x = 0;
        y = 0;
    }
    Point(int x, int y) { //конструктор с параметрами
        printf("Вызвался конструктор Point с параметрами.\n");
        this->x = x;
        this->y = y;
    }
    Point(Point &p) { //конструктор копирования
        printf("Вызвался конструктор Point копирования.\n");
        this->x = p.x;
        this->y = p.y;
    }
    ~Point() { //деструктор Point
        printf("Вызвался деструктор Point.\nВходные данные: ");
        printf("%d, %d\n", x, y);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Point p;
    Point p2(10,10);
    Point p3(p2);
}
