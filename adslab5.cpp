#include <iostream>
#include <vector>
#define inf 2147000000
using namespace std;

const int mat[8][8] =
{
	{0, 2, inf, 8, 2, inf, inf, inf},
	{2, 0, 3, 10, 5, inf, inf, inf},
	{inf, 3, 0, inf, 12, inf, inf, 7},
	{8, 10, inf, 0, 14, 3, 1, inf},
	{2, 5, 12, 14, 0, 11, 4, 8},
	{inf, inf, inf, 3, 1, 0, 6, inf},
	{inf, inf, inf, 1, 4, 6, 0, 9},
	{inf, inf, 7, inf, 8, inf, 9, 0}
};

const int list[16][3] = {
	{1,4,7},
	{2,1,5},
	{2,1,2},
	{3,2,3},
	{3,4,6},
	{4,5,7},
	{5,2,5},
	{6,6,7},
	{7,3,8},
	{8,5,8},
	{8,1,4},
	{9,7,8},
	{10,2,4},
	{11,5,6},
	{12,3,5},
	{14,4,5}
};

bool verInTree[8];
bool edgInTree[16];

void main()
{
	setlocale(LC_ALL, "ru");
	//алгоритм Прима
	/*for (int i = 0; i < 8; i++) verInTree[i] = false;
	int n = 1;
	cout << "Enter 1 <= n <= 8\n";
	cin >> n;
	if (!(1 <= n <= 8))
	{
		cout << "Invalid n, начнём с первого\n";
		n = 1;
	}
	verInTree[n - 1] = true;
	for (int k = 0; k < 7; k++)
	{
		int imin = -1, jmin = -1, lmin = inf;
		for (int i = 0; i < 8; i++)
		{
			if (verInTree[i])
			{
				for (int j = 0; j < 8; j++)
				{
					if (i == j) continue;
					if (!verInTree[j] && mat[i][j] < lmin)
					{
						imin = i;
						jmin = j;
						lmin = mat[i][j];
					}
				}
			}
		}
		if (imin != -1 && jmin != -1 && lmin != inf)
		{
			verInTree[jmin] = true;
			printf("Ребро V%d-V%d\n", imin + 1, jmin + 1);
		}
	}*/

	cout << "\ncrascal\n\n";
	//Алгоритм Краскала

	for (int i = 0; i < 8; i++) verInTree[i] = false;
	int n = 1;
	cout << "Enter 1 <= n <= 16\n";
	cin >> n;
	if (!(1 <= n <= 16))
	{
		cout << "Invalid n, начнём с первого\n";
		n = 1;
	}
	edgInTree[n - 1] = true;
	verInTree[list[n - 1][1] - 1] = true;
	verInTree[list[n - 1][2] - 1] = true;
	printf("Ребро между V%d и V%d\n", list[n - 1][1], list[n - 1][2]);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			list[j][1] - 1;
			list[j][2] - 1;
			if (edgInTree[j]) continue;
			if (verInTree[list[j][1] - 1] && !verInTree[list[j][2] - 1] || \
				!verInTree[list[j][1] - 1] && verInTree[list[j][2] - 1])
			{
				edgInTree[j] = true;
				verInTree[list[j][1] - 1] = true;
				verInTree[list[j][2] - 1] = true;
				printf("Ребро между V%d и V%d\n", list[j][1], list[j][2]);
			}
		}
	}
}