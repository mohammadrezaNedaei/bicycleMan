#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct edge
{
	int hotelNumber = 0;
	int totalValue = 0;
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
	int counter, lastStop = 3, hotelNum = 0, n = 0;
	edge w[20][20];
	bestPrice d[20];
	city p[20];
	ifstream in("in.txt");
	in >> counter;
	string line;
	for (int i = 0; i < counter; i++)
	{
		in >> lastStop;
		n += lastStop;
	}
	getline(in, line);
	while (getline(in, line))
	{
		if (line == "")
			break;
		stringstream datas;
		datas.str(line);
		int i, j, k;
		datas >> i; datas >> j; datas >> k;
		w[i][j].totalValue += k * 50000;
	}
	while (getline(in, line))
	{
		stringstream datas;
		datas.str(line);
		int i, j, counter = 1, minimum = 100000000;
		datas >> i;
		while (datas >> j)
		{
			if (j < minimum)
			{
				minimum = j;
				hotelNum = counter;
			}
			counter++;
		}
		counter = 0;
		while (counter < n)
		{
			if (w[counter][i].totalValue != 0)
			{
				w[counter][i].totalValue += minimum;
				w[counter][i].hotelNumber = hotelNum;
			}
			counter++;
		}
	}
	for (int i = 0; i <= 12; i++)
		for (int j = 0; j <= 12; j++)
			if (w[i][j].totalValue == 0)
				w[i][j].totalValue = 100000000;

	for (int i = 0; i <= 12; i++)
	{
		d[i].price = w[0][i].totalValue;
		p[i].cityNumber = 0;
	}
	for (int k = 1; k <= counter; k++)
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
	int miniMap = 0;
	for (int i = 0; i < lastStop; i++)
	{
		if (n - i < 0)
		{
			break;
		}
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

