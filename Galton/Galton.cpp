#include <iostream>
#include "Galton.h"
#include <array>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <ctime>

int const decisions = 20;
int	const balls = 3000;
int const iterations = 50;

char const c = 219;

int arr[balls];
int sarr[decisions * 2];
int aarr[decisions];

int iter = 0;
int devisor = 25;

int main()
{
	srand(time(0));

	for (int iter = 1; iter <= iterations; iter++)
	{

		for (int i = 0; i < balls; i++)
		{
			arr[i] = 0;
		}
		for (int i = 0; i < decisions * 2; i++)
		{
			sarr[i] = 0;
		}

		for (int i = 0; i < balls; i++)
		{
			int y = 0;
			for (int j = 0; j < decisions; j++)
			{				
				int a = rand() % 2;
				if (a == 0) { y--; }
				if (a == 1) { y++; }
			}
			arr[i] = y;
		}

		for (int i = 0; i < balls; i++)
		{
			arr[i] += decisions;
			sarr[arr[i]]++;
		}

		for (int i = 0; i < decisions; i++)
		{
			aarr[i] = sarr[i * 2];
		}
		
	print:
		std::cout << iter << "/" << "?" << "\n";
		for (int j = 0; j < decisions; j++)
		{	
			std::cout << "]";
			for (int i = 0; i < aarr[j] / devisor; i++)
			{
				std::cout << c;
			}
			std::cout << "\n";
		}

		/*char in;
		std::cin >> in;
		if (in == (char)43)
		{
			if (devisor > 1) { break; }
			devisor--;			
			goto print;
		}
		if (in == (char)45)
		{
			devisor++;
			goto print;
		}*/		
		PrintArray(aarr);
		std::cin.ignore();
	}
}

void PrintArray(int ass[])
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << ass[i] << "\n";
	}
	return;
}