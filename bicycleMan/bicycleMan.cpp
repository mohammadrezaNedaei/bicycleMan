#include <iostream>

using namespace std;

struct edge
{
	int hotelNumber;
	int totalValue;
};
struct city
{
	int cityNumber;
	int hotelNumber;
};

struct bestPrice
{
	int price;
	int hotelNumber;
};

void path(city[], int);

int main()
{
	int n = 12;
	edge w[13][13];
	bestPrice d[13];
	city p[13];
	w[0][1].totalValue = 50000 * 22 + 700000; 
	w[0][1].hotelNumber = 1;
	w[0][2].totalValue = 50000 * 8 + 800000;
	w[0][2].hotelNumber = 1;
	w[0][3].totalValue = 50000 * 12 + 800000;
	w[0][3].hotelNumber = 1;
	w[1][4].totalValue = 50000 * 8 + 500000;
	w[1][4].hotelNumber = 1;
	w[1][5].totalValue = 50000 * 10 + 700000;
	w[1][5].hotelNumber = 1;
	w[2][4].totalValue = 50000 * 25 + 500000;
	w[2][4].hotelNumber = 1;
	w[2][5].totalValue = 50000 * 10 + 700000;
	w[2][5].hotelNumber = 1;
	w[4][6].totalValue = 50000 * 25 + 500000;
	w[4][6].hotelNumber = 1;
	w[4][7].totalValue = 50000 * 30 + 700000;
	w[4][7].hotelNumber = 1;
	w[4][8].totalValue = 50000 * 18 + 700000;
	w[4][8].hotelNumber = 1;
	w[4][9].totalValue = 50000 * 27 + 600000;
	w[4][9].hotelNumber = 1;
	w[5][6].totalValue = 50000 * 12 + 500000;
	w[5][6].hotelNumber = 1;
	w[5][7].totalValue = 50000 * 10 + 700000;
	w[5][7].hotelNumber = 1;
	w[5][8].totalValue = 50000 * 8 + 700000;
	w[5][8].hotelNumber = 1;
	w[5][9].totalValue = 50000 * 7 + 600000;
	w[5][9].hotelNumber = 1;
	w[6][10].totalValue = 50000 * 28 + 500000;
	w[6][10].hotelNumber = 1;
	w[6][11].totalValue = 50000 * 13 + 700000;
	w[6][11].hotelNumber = 1;
	w[6][12].totalValue = 50000 * 15 + 600000;
	w[6][12].hotelNumber = 1;
	w[7][10].totalValue = 50000 * 8 + 500000;
	w[7][10].hotelNumber = 1;
	w[7][11].totalValue = 50000 * 10 + 700000;
	w[7][11].hotelNumber = 1;
	w[7][12].totalValue = 50000 * 10 + 600000;
	w[7][12].hotelNumber = 1;
	w[8][10].totalValue = 50000 * 15 + 500000;
	w[8][10].hotelNumber = 1;
	w[8][11].totalValue = 50000 * 10 + 700000;
	w[8][11].hotelNumber = 1;
	w[8][12].totalValue = 50000 * 7 + 600000;
	w[8][12].hotelNumber = 1;

	//readfile
	for (int i = 0; i <= 12; i++)
		for (int j = 0; j <= 12; j++)
			if (w[i][j].totalValue < 0)
				w[i][j].totalValue = 100000000;

	for (int i = 0; i <= 12; i++)
	{
		d[i].price = w[0][i].totalValue;
		p[i].cityNumber = 0;
	}
	for (int k = 1; k <= 4; k++)
		for (int i = 0; i <= 12; i++)
			for (int j = 0; j <= 12; j++)
				if (w[j][i].totalValue + d[j].price < d[i].price)
				{
					d[i].price = w[j][i].totalValue + d[j].price;
					d[i].hotelNumber = w[j][i].hotelNumber;
					p[i].cityNumber = j;
					p[i].hotelNumber = w[j][i].hotelNumber;
				}
	int mini = 100000000;
	int miniMap;
	for (int i = 0; i < 3; i++)
	{
		if (d[n - i].price < mini)
		{
			mini = d[n - i].price;
			miniMap = n - i;
		}
	}
	cout << d[miniMap].price << endl << 0 << endl;
	path(p, miniMap);
	cout << miniMap << " " << d[miniMap].hotelNumber << endl;
}

void path(city p[], int i)
{
	if (p[i].cityNumber != 0)
	{
		path(p, p[i].cityNumber);
		cout << p[i].cityNumber << " " << p[i].hotelNumber << endl;
		return;
	}
	if (i == 0)
		return;
	path(p,i - 1);
}

