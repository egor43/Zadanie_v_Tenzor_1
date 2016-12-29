#include"testfield.h"
#include"point.h"
#include<cstdlib>
#include<ctime>


TstFl::TestField::TestField(int value): CountShots(250000), CountInCircle(-1), SideSquare(value), ratio(-1) {}

double TstFl::TestField::DoubleRand(double min, double max)
{
    return min + (max - min) * ((double)rand() / (double)RAND_MAX);
}

double TstFl::TestField::Calculation_Ratio()
{
    int count=0; //Счетчик попаданий в круг
    srand(time(0)); //Чтоб рандом рандомно рандомил как рандом!
    for (int i = 0; i < CountShots; ++i)
    {
        double r=SideSquare/2.0;
        switch(rand()%4) //Рандомно делим квадрат на четверти.   (!!! Возможно это нужно было сделать в классе "Point" !!!)
        {
            case 0: //X>0,Y>0
            {
                point::Point Pnt(DoubleRand(0,SideSquare/2.0), DoubleRand(0,SideSquare/2.0)); //Заполняем точку координатами
                if((Pnt.GetX()*Pnt.GetX()+Pnt.GetY()*Pnt.GetY())<=(r*r)) count++; //Проверяем попадание в круг
                break;
            }
            case 1: //X<0,Y>0
            {
                point::Point Pnt(DoubleRand(0,SideSquare/2.0)*(-1), DoubleRand(0,SideSquare/2.0));
                if((Pnt.GetX()*Pnt.GetX()+Pnt.GetY()*Pnt.GetY())<=(r*r)) count++;
                break;
            }
            case 2: //X>0,Y<0
            {
                point::Point Pnt(DoubleRand(0,SideSquare/2.0), DoubleRand(0,SideSquare/2.0)*(-1));
                if((Pnt.GetX()*Pnt.GetX()+Pnt.GetY()*Pnt.GetY())<=(r*r)) count++;
                break;
            }
            case 3: //X<0,Y<0
            {
                point::Point Pnt(DoubleRand(0,SideSquare/2.0)*(-1), DoubleRand(0,SideSquare/2.0)*(-1));
                if((Pnt.GetX()*Pnt.GetX()+Pnt.GetY()*Pnt.GetY())<=(r*r)) count++;
                break;
            }
        }
    }
    CountInCircle=count;
    return count/(double)(CountShots-count);
}

double TstFl::TestField::Calculation_MonteCarlo()
{
    if(CountInCircle<0)
    {
        Calculation_Ratio();
    }
    return 4*(CountInCircle/(double)CountShots);
}
