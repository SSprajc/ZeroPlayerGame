#include "game_of_life.h"
#include <memory>
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	if (((rand() % 100) + 1) <= 25)
	{
		return true;
	}
	return false;
	
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	if (_generacija[i][j])
	{
		return true;
	}
	return false;
}



game_of_life::game_of_life()
{
}

void game_of_life::sljedeca_generacija()
{
	int n = sizeof(bool) * 20 * 40;
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int brojac = 0;
			if (_generacija[i - 1][j - 1])
			{
				if (!((i - 1) < 0 || ((j - 1) < 0)))
				{
					brojac++;
				}
			}
			if (_generacija[i - 1][j])
			{
				if (!((i - 1) < 0))
				{
					brojac++;
				}
			}
			if (_generacija[i - 1][j + 1])
			{
				if (!((i - 1) < 0 || ((j + 1) > 39)))
				{
					brojac++;
				}
			}
			if (_generacija[i][j + 1])
			{
				if (!((j + 1) > 39))
				{
					brojac++;
				}
			}
			if (_generacija[i][j - 1])
			{
				if (!((j - 1) < 0))
				{
					brojac++;
				}
			}
			if (_generacija[i + 1][j - 1])
			{
				if (!((i + 1) > 19 || ((j - 1) < 0)))
				{
					brojac++;
				}
			}
			if (_generacija[i + 1][j])
			{
				if (!((i + 1) > 19))
				{
					brojac++;
				}
			}
			if (_generacija[i + 1][j + 1])
			{
				if (!((i + 1) > 19 || ((j + 1) > 39)))
				{
					brojac++;
				}
			}
			if (_generacija[i + 1][j + 1])
			{
				if (!((i + 1) > 19 || ((j + 1) > 39)))
				{
					brojac++;
				}
			}
			else if (brojac == 3)
			{
				_sljedeca_generacija[i][j] = true;
			}
			if (!(brojac == 2 || brojac == 3))
			{
				_sljedeca_generacija[i][j] = false;
			}
		}
	}
	
	memcpy(_generacija, _sljedeca_generacija, n);
}

void game_of_life::iscrtaj()
{
	srand(time(0));
	if (_generacija[0][0] == 204)
	{
		for (int i = 0; i < REDAKA; i++)
		{
			for (int j = 0; j < STUPACA; j++)
			{
				if (slucajna_vrijednost())
				{
					cout << "O";
					_generacija[i][j] = true;
				}
				else
				{
					cout << "|";
					_generacija[i][j] = false;
				}
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < REDAKA; i++)
		{
			for (int j = 0; j < STUPACA; j++)
			{
				if (_generacija[i][j])
				{
					cout << "O";
				}
				else
				{
					cout << "|";
				}
			}
			cout << endl;
		}
	}
}
