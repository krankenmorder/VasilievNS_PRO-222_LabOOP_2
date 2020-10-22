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
    Point(Point &P) { //конструктор копирования
        printf("Вызвался конструктор Point копирования.\n");
        this->x = P.x;
        this->y = P.y;
    }
    ~Point() { //деструктор Point
        printf("Вызвался деструктор Point.\nВходные данные: ");
        printf("%d, %d\n\n", x, y);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Point P; //статически созданные объекты
    Point P2(10,10);
    Point P3(P2);

    Point *dinP = new Point; //динамически созданные объекты
    Point *dinP2 = new Point(11, 11);
    Point *dinP3 = new Point(*dinP2);

    delete dinP; //удаление динамически созданных объектов
    delete dinP2;
    delete dinP3;
}
