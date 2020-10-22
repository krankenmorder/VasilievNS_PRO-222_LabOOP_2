#include <iostream>
#include <conio.h>
#include <stdio.h>

class Point { //определение класса Point
public: //свойства и методы доступны везде
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

class Point2 { //класс для демонстрации реализации типов видимости и реализации методов сразу в определении и после определения
protected:
    int a, b;
public:
    Point2() { //конструктор по умолчанию
        printf("Вызвался конструктор Point2 по умолчанию.\n");
        a = 0;
        b = 0;
    }
    Point2(int a, int b) { //конструктор с параметрами
        printf("Вызвался конструктор Point2 с параметрами.\n");
        this->a = a;
        this->b = b;
    }
    Point2(Point2& P) { //конструктор копирования
        printf("Вызвался конструктор Point2 копирования.\n");
        this->a = P.a;
        this->b = P.b;
    }
    ~Point2() { //деструктор Point
        printf("Вызвался деструктор Point2.\nВходные данные: ");
        printf("%d, %d\n\n", a, b);
    }

    void move(int da, int db) { //реализация метода в определении класса
        a = a + da;
        b = b + db;
    }

    void reset(); //реализация метода после определения класса
};

void Point2::reset() { //реализация метода после определения класса
    a = 0;
    b = 0;
}

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

    Point2 *ab = new Point2(12, 12); //реализация типов видимости
    ab->reset();
    ab->move(2,3);
    delete ab;
}
