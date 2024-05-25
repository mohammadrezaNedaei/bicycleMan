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
	//read file "in.txt"
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
	//read file complite

	//put max data in totalValue
	for (int i = 0; i <= 12; i++)
		for (int j = 0; j <= 12; j++)
			if (w[i][j].totalValue == 0)
				w[i][j].totalValue = 100000000;

	//put first values in d array 
	//first data is edges from 0 as start node ex) 0 to 1
	for (int i = 0; i <= 12; i++)
	{
		d[i].price = w[0][i].totalValue;
		p[i].cityNumber = 0;
	}
	//calculate data as minimum price of travel using DP
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
	//find minimum from the end nodes in path
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
	//print path and the number of chosen hotel 
	cout << d[miniMap].price << endl << 0 << endl;
	path(p, miniMap);
	cout << miniMap << " " << d[miniMap].hotelNumber << endl;
}

void path(city p[], int i)
{
	//goes throw p array for the path
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

