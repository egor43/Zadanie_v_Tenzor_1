#ifndef TESTFIELD_H
#define TESTFIELD_H

namespace TstFl
{

class TestField //Представляет тестовое поле (квадрат с вписанной в него окружностью) и массив точек (выстрелов) = 250000 штук
{
private:
    int SideSquare; //Сторона квадрата
    double ratio; //Значение отношения: попадания в круг к попаданию вне круга
    int CountInCircle; //Колличество попаданий в круг
    double DoubleRand(double _max, double _min); //Рандом
    const unsigned int CountShots; //Колличество выстрелов

public:
    TestField(int value); //Eстанавливает длину стороны квадрата = входному параметру "а"
    double Calculation_Ratio(); //Вычисление отношения попадания в круг к попаданию вне круга
    double Calculation_MonteCarlo(); //Вычисление Pi по формуле Монте - Карло
};

}






#endif // TESTFIELD_H
