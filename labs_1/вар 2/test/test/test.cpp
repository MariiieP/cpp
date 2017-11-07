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


/* Функция InputMatrixcub ввода значений в матрицу. */
int InputMatrixcub(int *matrix, int x, int y, int z)
{
	for (int i = 0; i<x; i++)
	{
		for (int j = 0; j<y; j++)
		{
			for (int k = 0; k<z; k++)
			{
				cout << "INPUT" << ' ' << i << ' ' << j << ' ' << k << '\t';
				cin >> matrix[i*j*z + k]; //ввод
			}
		}
	}
	return 0;
}

/*Функция PrintMultiArr печатает двумерный массив на экран.*/
void PrintMultiArr(int *arr, int y, int x) {

	for (int i = 0; i < y; i++)
	{
		cout << endl;
		for (int j = 0; j < x; j++)
			cout << *(arr + i * x + j) << ' ';
	}
	cout << endl;
}


void main()
{
	const int OX = 2;
	const int OY = 2;
	const int OZ = 2;

	//инициализация всей 1-mat1,2-mat2,3-mat3 матрицы нулём
	int mat1[OX][OY] = { 0 };
	int mat2[OX][OZ] = { 0 };
	int mat3[OY][OZ] = { 0 };

	//печать матриц
	cout << "Ox, Oy\n";
	PrintMultiArr(&mat1[0][0], OX, OY);
	cout << "Ox, Oz\n";
	PrintMultiArr(&mat2[0][0], OX, OZ);
	cout << "Oy, Oz\n";
	PrintMultiArr(&mat3[0][0], OY, OZ);

	//инициаоизация 3-х мерной матрицы нулём и ее заполнение
	int matcub[OX][OY][OZ] = { 0 };
	InputMatrixcub(&matcub[0][0][0], OX, OY, OZ);

	//поиск проэкции
	for (int x = 0; x < OX; x++)
		for (int y = 0; y <OY; y++)
			for (int z = 0; z < OZ; z++)
			{
				if (matcub[x][y][z] != 0) {
					mat1[x][y] = 1;
					mat2[x][z] = 1;
					mat3[y][z] = 1;
				}
			}

	//вывод измененной 1-mat1,2-mat2,3-mat3 матрицы 
	cout << "Ox, Oy\n";
	PrintMultiArr(&mat1[0][0], OX, OY);
	cout << "Ox, Oz\n";
	PrintMultiArr(&mat2[0][0], OX, OZ);
	cout << "Oy, Oz\n";
	PrintMultiArr(&mat3[0][0], OY, OZ);
	system("pause");

}