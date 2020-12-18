#include <iostream>
#include <conio.h>

class Country {
    /*
private:
    int pop, area; //обращение к свойству объекта будет недоступно (a->pop)
    */
protected:
    int pop, area;
public:
    Country() {//конструктор без параметров
        printf("Country()\n");
        pop = 0;
        area = 0;
    }
    Country(int pop, int area) {//конструктор с параметрами
        printf("Country(int pop,int area)\n");
        this->pop = pop;
        this->area = area;
    }
    Country(const Country& c) {//копирующий конструктор
        printf("Country(const Countr &c)\n");
        pop = c.pop;
        area = c.area;
    }
    ~Country() {//деструктор
        printf("%d, %d\n", pop, area);
        printf("~Country()\n");
    }
    void growth(int popg, int areag) {//реализация метода сразу по определению
        pop = pop + popg;
        area = area + areag;
    }
    void reset();
};

void Country::reset() {//реализация метода после определения
        pop = 0;
        area = 0;
}

class City: public Country {//класс наследник 
protected:
    int percent;

public:
    City() : Country() {//конструктор без параметров
        printf("City()\n");
        pop = 0;
        area = 0;
        percent = 0;
    }
    City(int pop, int area, int percent) : Country(pop, area) {//конструктор с параметрами
        printf("City(int pop, int area, int percent)\n");
        this->percent= percent;
    }
    City(const City& c) {//копирующий конструктор
        printf("City(const Countr &c)\n");
        pop = c.pop;
        area = c.area;
        percent = c.percent;
    }
    ~City() {//деструктор
        printf("%d, %d, %d\n", pop, area, percent);
        printf("~City()\n");
    }
    void newpercent(int new_percent) {//реализация метода сразу по определению
        percent = new_percent;
    }
};

class district {//композиция
protected:
    Country *a;
    Country *b;
public:
    district() {//конструктор без параметров
        printf("district()\n");
        a = new Country;
        b = new Country;
    }
    district(int pop1, int area1, int pop2, int area2) {//конструктор с параметрами
        printf("district(int pop,int area)\n");
        a = new Country(pop1, pop2);
        b = new Country(area1, area2);
    }
    district(const district& c) {//копирующий конструктор
        printf("district(const district &c)\n");
        a = new Country(*(c.a));
        b = new Country(*(c.b));
    }
    ~district() {//деструктор
        //printf("%d, %d\n", pop, area);
        delete a;
        delete b;
        printf("~district()\n");
    }
};

int main()
{
    /*{
        Country a; //статически создаваемые объекты
        Country b(10, 20);
        Country c(b);
    }*/

    /*{ 
        Country *a = new Country;//динамически созданные объекты
        Country *b = new Country(10, 20);
        Country *c = new Country(*b);//разиминовываем объект б
        delete a;
        delete b;
        delete c;
    }*/

    /*{
        Country *a = new Country(5, 10);
        a->reset();//вызов методов объекта
        a->growth(3, 3);
        delete a;
    }*/

    {//создаем объект класса наследника проверяем работу конструкторов и деструкторов
        City* j = new  City(10, 20, 30);
        delete j;
    }


    _getch();
    return 0;
}