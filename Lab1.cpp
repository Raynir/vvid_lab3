#include "stdafx.h"
#include "locale.h"
#include "iostream"

using namespace std;

long float checkInput(long float g)
{
	bool needcheck = true;			//для проверки типа введённых данных

	while (needcheck)				//цикл будет повторяться до тех пор, пока пользователь не введёт положительное целое число
	{
		cout << "ввидите моссу в греммах, хохо (целое положительное число): ";
		cin >> g;

		if (!cin)					//проверка введённых данных
		{
			cout << "Введённые вами символы не являются числом (или число слишком большое). Пожалуйста, попробуйте снова\n" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		else if ((g < 0) || (g > 2))
		{
			cout << "\n";
			cout << "Вы ввели отрицательное или слишком большое число. дурачок, попробуй снова))000\n" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		else
		{
			needcheck = false;						//условие остановки цикла
		}
	}
	return g;
}

void showResult(int kg, int t)
{
	cout << "Это " << t;							//дальше идёт написание слов в правильной форме. Тут тонны

	if ((t % 100 > 10) && (t % 100 < 20)) cout << " тонн и " << kg;
	else
	{
		switch (t % 10)
		{
		case 1:
		{cout << " тонна и " << kg;		break; }

		case 2:
		case 3:
		case 4:
		{cout << " тонны и " << kg;		break; }
		default:
			cout << " тонн и " << kg;
		}
	}

	if ((kg % 100 > 10) && (kg % 100 < 20)) cout << " килограмм.";		//а тут килограммы
	else
	{
		switch (kg % 10)
		{
		case 2:
		case 3:
		case 4:
		{cout << " килограмма.";	break; }
		default:
			cout << " килограмм.";
		}
	}
}

int main()
{
	setlocale(0, "rus");

	long float g = 0;					//переменные для г, кг и т
	int kg, t;

	g = checkInput(g);
	
	t = g * 1000000;
	kg = (g - (t / 1000000)) * 1000;
	
	showResult(kg, t);

	getchar();
	getchar();
	return 0;
}
