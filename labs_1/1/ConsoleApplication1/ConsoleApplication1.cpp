// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
//Автор: Пукась Мария
/*В трехмерном массиве m*n*p, состоящем из нулей и единиц, хранится сеточное изображение
некоторого трехмерного тела. Найти в двумерных массивах три проекции (тени) этого тела. */
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>


using namespace std;


int ** make2d(int x, int y)
{	
	int ** ta = new int*[x];
	for (int i = 0; i < x; i++) {
		ta[i] = new int[y];
		for (int j = 0; j < y; j++)
			ta[i][j] = 0;
	}
	return ta;
}

void random(int *** cube, int x, int y, int z)
{
	srand(GetTickCount());
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				if ((rand() % 17) == 0)
					cube[i][j][k] = 1;
			}
		}
	}
}


void print(int ** matrix, int p1, int p2)
{
	for (int i = 0; i < p1; i++)
	{
		for (int j = 0; j < p2; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}


void print3d(int *** matrix, int p1, int p2, int p3)
{
	for (int i = 0; i < p1; i++)
	
		for (int j = 0; j < p2; j++)
		{ 
			for (int k = 0; k < p2; k++)
			printf("%d ", matrix[i][j][k]);
		printf("\n");
	}
	printf("\n");
}


int *** make3d(int MX, int MY, int MZ)
{
	int *** xyz = new int**[MX];

	for (int i = 0; i < MX; i++)
	{
		xyz[i] = new int *[MY];
		for (int j = 0; j < MY; j++)
		{
			xyz[i][j] = new int[MZ];
			for (int k = 0; k < MZ; k++)
			{
				xyz[i][j][k] = 0;
			}
		}
	}
	return xyz;
}
void del2d(int ** a, int x)
{
	for (int i = 0; i < x; i++)
		delete[]  a[i];
	delete[] a;
}

#define OX 5
#define OY 5
#define OZ 5

void main()
{
	int ***xyz = make3d(OX, OY, OZ);

	//создание 2d массивов
	cout << "Ox, Oy\n";
	int **xy = make2d(OX, OY);
	print(xy, OX, OY);

	cout << "Ox, Oz\n";
	int **xz = make2d(OX, OZ);
	print(xy, OX, OZ);

	cout << "Oy, Oz\n";
	int **yz = make2d(OY, OZ);
	print(xy, OY, OZ);

	//заполнение случайными числами 3d массив
	random(xyz, OX, OY, OZ);

	//обход всех точек 3d массива
	for (int x = 0; x < OX; x++)
		for (int y = 0; y < OY; y++)
			for (int z = 0; z < OZ; z++)
			{
				if (xyz[x][y][z] == 0) continue;
				xy[x][y] = 1;
				xz[x][z] = 1;
				yz[y][z] = 1;
			}

	//печать измененных 2d массивов
	cout << "Ox, Oy\n";
	print(xy, OX, OY);
	cout << "Ox, Oz\n";
	print(xz, OX, OZ);
	cout << "Oy, Oz\n";
	print(yz, OY, OZ);

/*   ??
	//удаление из памяти
	del2d(xyz, OX);
	del2d(xz, OY);
	del2d(yz, OZ);
*/
	system("pause");
}