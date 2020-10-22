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
protected: //свойства доступны только в данном классе и классах-потомках
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

class ColorPoint: public Point2 { //класс-наследник класса Point
public:
    int color;
    ColorPoint(): Point2(){ //конструктор по умолчанию
        printf("Вызвался конструктор ColorPoint по умолчанию.\n");
        color = 0;
    }
    ColorPoint(int x, int y, int color): Point2(x, y){ //конструктор с параметрами
        printf("Вызвался конструктор ColorPoint с параметрами.\n");
        this->color = color;
    }
    ColorPoint(ColorPoint& P) { //конструктор копирования
        printf("Вызвался конструктор ColorPoint копирования.\n");
        this->a = P.a;
        this->b = P.b;
        this->color = P.color;
    }
    ~ColorPoint() { //деструктор Point
        printf("Вызвался деструктор ColorPoint.\nВходные данные: ");
        printf("%d, %d, color = %d\n\n", a, b, color);
    }
    void changeColor(int newColor) {
        color = newColor;
    }
};

class Line { //класс для демонстрации композиции объектов
private:
    Point *p1;
    Point *p2;
public:
    Line() { //конструктор по умолчанию
        printf("Вызвался конструктор Line по умолчанию (автоматическое создание двух точек).\n");
        p1 = new Point;
        p2 = new Point;
    }
    Line(int x1, int y1, int x2, int y2) { //конструктор с параметрами
        printf("Вызвался конструктор Line с параметрами.\n");
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
    }
    Line(Line& L) { //конструктор копирования
        printf("Вызвался конструктор Line копирования.\n");
        p1 = new Point(*(L.p1));
        p2 = new Point(*(L.p2));
    }
    ~Line() { //деструктор Point
        printf("Вызвался деструктор Line.\nВходные данные: ");
        printf("%i, %i\n\n", p1, p2);
        delete p1;
        delete p2;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Point P; //статически созданные объекты
    Point P2(10,10);
    Point P3(P2);

    system("pause");
    printf("\n");

    Point *dinP = new Point; //динамически созданные объекты
    Point *dinP2 = new Point(11, 11);
    Point *dinP3 = new Point(*dinP2);

    system("pause");
    printf("\n");

    delete dinP; //удаление динамически созданных объектов
    delete dinP2;
    delete dinP3;

    system("pause");
    printf("\n");

    Point2 *ab = new Point2(12, 12); //реализация типов видимости
    ab->reset();
    ab->move(2,3);
    delete ab;

    system("pause");
    printf("\n");

    Point2 *color1 = new ColorPoint(1, 2, 30); //помещение объекта в переменную другого типа (класса-предка)
    delete color1;

    ColorPoint* color2 = new ColorPoint(1, 2, 30); //реализация класса-потомка 
    delete color2;

    system("pause");
    printf("\n");

    Line *l1 = new Line(); //
    Line *l2 = new Line(*l1);
    delete l1;
    delete l2;

    system("pause");
    printf("\n");
}
