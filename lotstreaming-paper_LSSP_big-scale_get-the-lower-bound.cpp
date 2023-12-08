#include"iostream"
#include"algorithm" 
#include <stdlib.h> 
#include<stdio.h>
#include<time.h>
#include<iomanip>
#include<math.h>
#include <string>
#include <string.h>
#include <vector>
#include <random>

#define random(x) (rand()%x)

// this code is write since 2019-3-1
// this code is updated on 2023-12-8
// we are welcome you to connect us if you have any question about this code
// the email address is: wangck@sjtu.edu.cn
// thank you for your attention!!!

using namespace std;

#define bigM 255555
#define minS  1  
const double T0 = 10001;
const int maxcase = 500;
int maxcaseused = -1;

int control1 = 3;

int LYwaybool = 2;
int LY3bool1 = 2;
int LY3bool2 = 2;
int LY3bool3 = 0;

#define I  10  
const int N = I;
const int NN = I;

#define K 5
const int M = K;

int d[N + 1] = { 0,2,2,2,2,2,2,2,2,2,2 };
int d1 = 2, d2 = 2, d3 = 2, d4 = 2, d5 = 2, d6 = 2, d7 = 2, d8 = 2, d9 = 2, d10 = 2;

double processtime[I + 1][K + 1] = {
	{ 0,0,0,0,0,0 },
	{ 0, 26,59,78,88,69 },
	{ 0, 38, 62, 90, 54, 30 },
	{ 0,27,44, 64,47,61 },
	{ 0,88,10, 49,83,35  },
	{ 0,95, 23, 47,84,53 },
	{ 0, 55, 64, 20, 9, 98   },
	{0,54, 47, 61, 30, 94},
	{0,63, 68, 93, 11, 33},
	{0,23, 54, 36, 92, 77},
};

double processtimeset[I * 10 + 1][K + 1]
{
	{ 0,0,0,0,0,0 },

	{0,26,59,78,88,69},
{0,38,62,90,54,30},
{0,27,44,64,47,61},
{0,88,10,49,83,35},
{0,95,23,47,84,53},
{0,55,64,20,9,98},
{0,54,47,61,30,94},
{0,63,68,93,11,33},
{0,23,54,36,92,77},
{0,45,9,47,63,31},

{0,77,39,14,11,83},
{0,94,31,21,2,13},
{0,9,46,15,36,84},
{0,57,18,10,30,46},
{0,29,93,85,89,20},
{0,79,58,46,10,33},
{0,55,85,42,88,74},
{0,73,58,18,22,42},
{0,65,97,36,31,33},
{ 0,86,10,2,9,71 },

{0,53,93,90,65,64},
{0,19,79,92,97,38},
{0,99,88,35,27,44},
{0,62,77,13,25,46},
{0,88,94,75,61,66},
{0,93,39,55,24,31},
{0,34,74,80,97,48},
{0,72,46,67,61,27},
{0,42,17,3,75,82},
{0,65,30,93,92,51},

{0,27,79,22,93,38},
{0,92,23,93,22,84},
{0,75,66,62,64,62},
{0,94,5,53,81,10},
{0,18,15,30,94,11},
{0,41,51,34,97,93},
{0,37,2,27,54,57},
{0,58,81,30,82,81},
{0,56,12,54,11,10},
{0,20,40,77,91,40},

{0,12,26,27,52,24},
{0,72,89,97,30,57},
{0,29,86,53,62,68},
{0,16,10,16,8,58},
{0,22,16,36,45,76},
{0,61,72,28,77,70},
{0,69,96,50,90,72},
{0,71,47,41,52,56},
{0,86,9,42,39,56},
{0,16,56,86,95,55},

{0,24,51,8,59,67},
{0,1,57,54,85,99},
{0,57,82,15,73,57},
{0,86,47,47,87,47},
{0,35,82,73,87,93},
{0,9,14,33,89,35},
{0,55,79,73,48,32},
{0,8,57,35,57,77},
{0,93,88,45,59,28},
{0,11,79,75,73,75},

{0,34,24,20,65,47},
{0,40,85,61,39,62},
{0,22,19,69,68,11},
{0,6,94,28,40,6},
{0,50,59,69,82,21},
{0,64,65,35,31,60},
{0,48,42,17,29,82},
{0,74,8,59,17,2},
{0,67,10,16,69,31},
{0,77,11,57,36,13},

{0,61,27,42,13,55},
{0,86,92,93,47,48},
{0,16,8,32,6,56},
{0,42,65,30,70,84},
{0,14,34,16,19,22},
{0,92,6,95,97,51},
{0,67,42,58,41,43},
{0,77,39,12,1,50},
{0,46,2,95,57,62},
{0,77,11,57,36,13},

{0,73,34,8,62,10},
{0,84,46,37,86,60},
{0,57,97,38,46,34},
{0,52,88,30,3,96},
{0,66,52,20,22,79},
{0,67,49,68,33,62},
{0,33,88,4,90,6},
{0,62,15,78,94,15},
{0,65,55,41,98,94},
{0,7,6,2,9,39},

{0,7,62,29,10,30},
{0,41,67,39,54,10},
{0,6,30,31,89,54},
{0,14,5,3,9,3},
{0,62,26,50,52,63},
{0,1,57,37,47,63},
{0,40,28,85,5,90},
{0,16,5,70,39,60},
{0,76,41,22,31,88},
	{ 0,75,81,35,93,36 }

};

double setuptime[I + 1][I + 1][K + 1] = { 0 };

double a1[NN + 1] = { 0,0,0,0,0,0,0,0,0,0,0 };
double b1[NN + 1] = { 0,30,30,30,30,30,30,30,30,30,30 };

double an[NN + 1] = { 0,0,  0, 0,  0, 0,0,0,0,0 };
double bn[NN + 1] = { 0,30,30,30,30,30,30,30,30,30,30 };

const int m_s = 1;
const int m_b = M;

void stateergodic();
void label_shixiao(int* jj, int nn);
int label_youxiaoxing(int* jj, int nn);
void new_state_set(int* j, int n, int i, int nn, int dltj);
void statetransition(int* j, int n);
void statetransition_initial(int* j, int n);
int label_youxiaoxing_2_xiajie(int* jj, int nn);
double old_label[N + M + 1] = { 0 };
double new_label[N + M + 1] = { 0 };

std::vector < std::vector < std::vector < std::vector< std::vector < std::vector < std::vector <std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<float>>>>>>>>>>>>> f;
void vector_chushihua()
{
	int counti = 0;
	int counti1 = 0;
	f.reserve(d1 + 1);

	for (size_t i = 0; i < d1 + 1; i++)
	{
		std::vector < std::vector < std::vector < std::vector < std::vector< std::vector  < std::vector < std::vector <std::vector<std::vector<std::vector<std::vector<float>>>>>>>>>>>> submatrix;
		submatrix.reserve(d2 + 1);

		for (size_t j = 0; j < d2 + 1; j++)
		{
			std::vector < std::vector < std::vector < std::vector < std::vector < std::vector   < std::vector <std::vector<std::vector<std::vector<std::vector<float>>>>>>>>>>> submatrix1;
			submatrix1.reserve(d3 + 1);

			for (size_t j3 = 0; j3 < d3 + 1; j3++)
			{
				counti++;
				cout << counti << endl;
				std::vector < std::vector < std::vector < std::vector < std::vector < std::vector <std::vector<std::vector<std::vector<std::vector<float>>>>>>>>>> submatrix2;
				submatrix2.reserve(d4 + 1);

				for (size_t j4 = 0; j4 < d4 + 1; j4++)
				{
					counti1++;
					cout << "256per " << counti1 << endl;
					std::vector < std::vector < std::vector < std::vector < std::vector < std::vector<std::vector<std::vector<std::vector<float>>>>>>>>> submatrix3;
					submatrix3.reserve(d5 + 1);

					for (size_t j5 = 0; j5 < d5 + 1; j5++)
					{

						std::vector < std::vector < std::vector < std::vector < std::vector<std::vector<std::vector<std::vector<float>>>>>>>> submatrix4;
						submatrix4.reserve(d6 + 1);

						for (size_t j6 = 0; j6 < d6 + 1; j6++)
						{
							std::vector < std::vector < std::vector < std::vector < std::vector<std::vector<std::vector<float>>>>>>> submatrix5;
							submatrix5.reserve(d7 + 1);

							for (size_t j7 = 0; j7 < d7 + 1; j7++)
							{
								std::vector < std::vector < std::vector < std::vector<std::vector<std::vector<float>>>>>> submatrix6;
								submatrix6.reserve(d8 + 1);

								for (size_t j8 = 0; j8 < d8 + 1; j8++)
								{
									std::vector < std::vector < std::vector<std::vector<std::vector<float>>>>> submatrix7;
									submatrix7.reserve(d9 + 1);

									for (size_t j9 = 0; j9 < d9 + 1; j9++)
									{
										std::vector < std::vector<std::vector<std::vector<float>>>> submatrix8;
										submatrix8.reserve(d10 + 1);

										for (size_t j10 = 0; j10 < d10 + 1; j10++)
										{
											std::vector<std::vector<std::vector<float>>> submatrix9;
											submatrix9.reserve(N + 1);

											for (size_t j11 = 0; j11 < N + 1; j11++)
											{
												std::vector<std::vector<float>> submatrix10;
												submatrix10.reserve(maxcase + 1);

												for (size_t j12 = 0; j12 < maxcase + 1; j12++)
												{
													std::vector<float> row;
													row.resize(m_b - m_s + N + 1);

													submatrix10.push_back(row);
												}
												submatrix9.push_back(submatrix10);
											}

											submatrix8.push_back(submatrix9);
										}
										submatrix7.push_back(submatrix8);

									}
									submatrix6.push_back(submatrix7);

								}
								submatrix5.push_back(submatrix6);
							}

							submatrix4.push_back(submatrix5);

						}
						submatrix3.push_back(submatrix4);

					}
					submatrix2.push_back(submatrix3);

				}
				submatrix1.push_back(submatrix2);

			}
			submatrix.push_back(submatrix1);

		}
		f.push_back(submatrix);

	}

}

void chushihuaf()
{

	int j[N + 1] = { 0 };
	for (j[1] = 0; j[1] <= d1; j[1]++)
		for (j[2] = 0; j[2] <= d2; j[2]++)
			for (j[3] = 0; j[3] <= d3; j[3]++)
				for (j[4] = 0; j[4] <= d4; j[4]++)
					for (j[5] = 0; j[5] <= d5; j[5]++)
						for (j[6] = 0; j[6] <= d6; j[6]++)
							for (j[7] = 0; j[7] <= d7; j[7]++)
								for (j[8] = 0; j[8] <= d8; j[8]++)
									for (j[9] = 0; j[9] <= d9; j[9]++)
										for (j[10] = 0; j[10] <= d10; j[10]++)

											for (int n = 0; n <= N; n++)
												for (int i = 0; i <= maxcase; i++)
													for (int m = 0; m <= m_b - m_s + N; m++)
													{
														f[j[1]][j[2]][j[3]][j[4]][j[5]][j[6]][j[7]][j[8]][j[9]][j[10]][n][i][m] = 0;
													}

	for (int n = 1; n <= N; n++)f[0][0][0][0][0][0][0][0][0][0][n][0][m_b - m_s] = T0;

}
void chushihuasettime()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (i == j)
				{
					setuptime[i][j][k] = ceil(processtime[i][k] * 0.25);

				}
				else
				{
					setuptime[i][j][k] = ceil((processtime[i][k] + processtime[j][k]) * 0.25);
				}
			}
		}
	}
}

void showdouble(double* a)
{
	cout << "showdouble" << endl;
	for (int i = 0; i < sizeof(a); i++)cout << a[i] << ",";
	cout << endl;
}
void showint(int* a)
{
	cout << "showint" << endl;
	for (int i = 0; i < sizeof(a); i++)cout << a[i] << ",";
	cout << endl;
}

void stateergodic()
{
	int j[N + 1] = { 0 };

	for (int n = 1; n <= N; n++)statetransition_initial(j, n);
	for (j[1] = 0; j[1] <= d1; j[1]++)
		for (j[2] = 0; j[2] <= d2; j[2]++)
		{
			for (j[3] = 0; j[3] <= d3; j[3]++)
				for (j[4] = 0; j[4] <= d4; j[4]++)
					for (j[5] = 0; j[5] <= d5; j[5]++)
						for (j[6] = 0; j[6] <= d6; j[6]++)
							for (j[7] = 0; j[7] <= d7; j[7]++)
								for (j[8] = 0; j[8] <= d8; j[8]++)
									for (j[9] = 0; j[9] <= d9; j[9]++)
										for (j[10] = 0; j[10] <= d10; j[10]++)
											for (int n = 1; n <= N; n++)
											{
												int bool1 = 0;
												for (int i = 1; i <= N; i++)bool1 += j[i];
												if (bool1 > 0)
													statetransition(j, n);

											}

		}

}

double max1(double a, double b)
{
	if (a <= b)
	{
		a = b;
	}
	return a;
}
double min1(double a, double b)
{
	if (a >= b)
	{
		a = b;
	}
	return a;
}

void label_shixiao(int* jj, int nn)
{
	for (int n = 1; n <= N; n++)
	{
		for (int n1 = 1; n1 <= N; n1++)
		{
			if (n1 != n && new_label[m_b - m_s + n1] > 0 && new_label[m_b - m_s + n] > 0) {
				if (new_label[m_b - m_s + n1] - a1[n1] <= new_label[m_b - m_s + n] - b1[n])
					new_label[m_b - m_s + n] = -3 * bigM;
			}

		}
	}

}

int label_youxiaoxing(int* jj, int nn)
{

	int boolnum = -1;
	int i = 0;

	while (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i][m_b - m_s] != 0 && i < maxcase)
	{

		if (i == maxcase) {

			system("pause");

		}
		i = i + 1;
	}

	if (i == 0)
	{
		return 0;
	}
	else
	{
		int boolnum1 = 0;
		for (int ii = 0; ii < i; ii++)
		{
			int boolnum11 = 1;
			for (int m = 0; m < m_b - m_s; m++)
			{
				if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] < min1(new_label[m] - 0.1, new_label[m + 1] - 0.1 - processtime[nn][m + 1]) && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]>-bigM / 2)
				{

					boolnum11 = 0;
				}
			}
			for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
			{
				if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] < new_label[m] - 0.1 && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]>-bigM / 2)
				{
					boolnum11 = 0;
				}
			}
			if (boolnum11 == 1)
			{
				boolnum1 = 1;
			}
		}

		if (boolnum1 == 0) 
		{

			int boolnum2 = 1;
			for (int ii = 0; ii < i; ii++)
			{
				boolnum2 = 1;
				for (int m = 0; m < m_b - m_s; m++)
				{
					if (min1(f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m], f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m + 1] - processtime[nn][m + 1]) > new_label[m] && new_label[m] > -bigM / 2)
					{
						boolnum2 = 0;
					}
				}
				for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
				{
					if ((f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]) > new_label[m] && new_label[m] > -bigM / 2)

					{
						boolnum2 = 0;
					}
				}

				if (boolnum2 == 1)
				{
					if (ii != i - 1)
					{
						for (int m = 0; m <= m_b - m_s + N; m++)
						{
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i - 1][m];
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i - 1][m] = 0;

						}
					}
					else {
						for (int m = 0; m <= m_b - m_s + N; m++)
						{
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] = 0;
						}
					}
					ii--;
					i--;
				}
			}
			boolnum = i;
		}

	}

	return boolnum;
}

int label_youxiaoxing_1(int* jj, int nn) {
	for (int k = 0; k <= m_b - m_s; k++)
	{
		if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][k][k] < new_label[k] || f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][k][k] == 0)
		{
			for (int m = 0; m <= m_b - m_s + NN; m++)f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][k][m] = new_label[m];

			maxcaseused = M;
		}

	}
	return -1;
}

double value_function(double* delta_value)
{
	double out = -1;
	int choose_i = 0;
	if (choose_i == 0)
	{
		out = 0;
		for (int m = 2; m <= M; m++)out += delta_value[m];
		out = out / (M - 1);
	}
	else if (choose_i == 1)
	{
		out = 0;
		for (int m = 2; m <= M; m++)out += M * delta_value[m];
		out = out / (M - 1);
	}
	else if (choose_i == 2)
	{
		out = 0;
		for (int m = 2; m <= M; m++)out = out * 1.2 + delta_value[m];
		out = out / (M - 1);
	}
	return out;
}

double delta[maxcase][M + 1] = { 0 };
int label_youxiaoxing_2(int* jj, int nn) {
	int boolnum = -1;
	int i = 0;

	while (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i][m_b - m_s] != 0 && i < maxcase)
	{
		if (i == maxcase) {

			system("pause");
		}
		i = i + 1;
	}

	double deltanew[M + 1] = { 0 };
	for (int m = 0; m <= m_b - m_s; m++)
	{
		deltanew[m] = new_label[m] - new_label[m - 1];
	}

	if (i >= maxcase)
	{
		double xielv_new = value_function(deltanew);

		for (int k = 0; k < i; k++)for (int m = 1; m <= m_b - m_s; m++)
		{
			delta[k][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][k][m] - f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][k][m - 1];
		}
		double xielv[maxcase] = { 0 };
		for (int k = 0; k < i; k++)xielv[k] = value_function(delta[k]);

		int replace_num = -1; double tempvalue = bigM;
		int diedai_times = 0;
		while (diedai_times <= control1)
		{
			tempvalue = bigM;
			for (int kk = 0; kk < i; kk++) {
				if (fabs(xielv[kk] - xielv_new) < tempvalue)
				{
					tempvalue = fabs(xielv[replace_num] - xielv_new);
					replace_num = kk;
				}
			}
			if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][replace_num][0] <= new_label[1])
			{
				break;
			}
			else
			{
				xielv[replace_num] = 2 * bigM; replace_num = -1; diedai_times++;
			}
			if (tempvalue == bigM)
			{

				break;
			}
		}

		if (replace_num != -1)for (int m = 0; m <= m_b - m_s + N; m++)f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][replace_num][m] = new_label[m];
		boolnum = -1;

	}
	else {

		if (i == 0)
		{
			return 0;
		}
		else
		{
			int boolnum1 = 0;
			for (int ii = 0; ii < i; ii++)
			{
				int boolnum11 = 1;
				for (int m = 0; m < m_b - m_s; m++)
				{
					if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] < min1(new_label[m] - 0.1, new_label[m + 1] - 0.1 - processtime[nn][m + 1]) && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]>-bigM / 2)
					{

						boolnum11 = 0;
					}
				}
				for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
				{
					if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] < new_label[m] - 0.1 && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]>-bigM / 2)
					{
						boolnum11 = 0;
					}
				}
				if (boolnum11 == 1)
				{
					boolnum1 = 1;
				}
			}

			if (boolnum1 == 0) 
			{

				int boolnum2 = 1;
				for (int ii = 0; ii < i; ii++)
				{
					boolnum2 = 1;
					for (int m = 0; m < m_b - m_s; m++)
					{
						if (min1(f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m], f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m + 1] - processtime[nn][m + 1]) > new_label[m] && new_label[m] > -bigM / 2)
						{
							boolnum2 = 0;
						}
					}
					for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
					{
						if ((f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]) > new_label[m] && new_label[m] > -bigM / 2)

						{
							boolnum2 = 0;
						}
					}

					if (boolnum2 == 1)
					{
						if (ii != i - 1)
						{
							for (int m = 0; m <= m_b - m_s + N; m++)
							{
								f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i - 1][m];
								f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i - 1][m] = 0;

							}
						}
						else {
							for (int m = 0; m <= m_b - m_s + N; m++)
							{
								f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] = 0;
							}
						}
						ii--;
						i--;
					}
				}
				boolnum = i;
			}

		}

	}

	return boolnum;
}

double value_function_forMoreThanM(double* prevalue, int boolnum)
{
	double tt[N + 1] = { 0 };
	for (int n = 1; n <= N; n++)tt[n] = (a1[n] + b1[n]) / 2;

	for (int m = m_b + 1; m <= m_b + NN; m++)if (prevalue[m]<-bigM / 2 || prevalue[m]>bigM / 2)cout << " mdzz " << m << " : " << prevalue[m];

	double out = 0;
	if (boolnum == 1)
	{
		for (int m = m_b + 1; m <= m_b + NN; m++)
		{

			out += (prevalue[m] - T0) * tt[m - M];

		}
	}
	else if (boolnum == 2)
	{
		out = 3 * bigM;
		for (int m = m_b + 1; m <= m_b + NN; m++) {
			if ((prevalue[m] - tt[m - M]) < out)
			{
				out = prevalue[m] - tt[m - M];
			}
		}
	}

	return out;
}

int label_youxiaoxing_3(int* jj, int nn) {
	double tempf[maxcase + 1][M + NN + 2] = { 0 };
	for (int ms = 0; ms < maxcase + 1; ms++)for (int m = 0; m < m_b - m_s + NN + 2; m++)tempf[ms][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ms][m];

	int boolnum = -1;
	int i = 0;

	double new_total = value_function_forMoreThanM(new_label, 1);
	double new_key = value_function_forMoreThanM(new_label, 2);

	while (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i][m_b - m_s] != 0 && i < maxcase)
	{

		if (i == maxcase) {

			system("pause");

		}
		i = i + 1;
	}

	if (i == 0)
	{
		return 0;
	}
	else
	{
		int boolnum1 = 0;
		for (int ii = 0; ii < i; ii++)
		{
			int boolnum11 = 1;
			for (int m = 0; m < m_b - m_s; m++)
			{
				if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] < min1(new_label[m] - 0.1, new_label[m + 1] - 0.1 - processtime[nn][m + 1]) && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]>-bigM / 2)
				{

					boolnum11 = 0;
				}
			}

			if (LY3bool2 == 1)
			{
				for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
				{
					if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] < new_label[m] - 0.1 && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]>-bigM / 2)
					{
						boolnum11 = 0;
					}
				}
			}
			else if (LY3bool2 == 2)
			{
				double old_total = value_function_forMoreThanM(tempf[ii], 1);
				double old_key = value_function_forMoreThanM(tempf[ii], 2);

				if (new_total > old_total)boolnum11 = 0;
				if (new_key > old_key)boolnum11 = 0;

			}

			if (boolnum11 == 1)
			{
				boolnum1 = 1;
			}
		}

		if (boolnum1 == 0) 
		{

			int boolnum2 = 1;
			for (int ii = 0; ii < i; ii++)
			{
				boolnum2 = 1;
				for (int m = 0; m < m_b - m_s; m++)
				{
					if (min1(f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m], f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m + 1] - processtime[nn][m + 1]) > new_label[m] && new_label[m] > -bigM / 2)
					{
						boolnum2 = 0;
					}
				}
				if (LY3bool2 == 1)
				{
					for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
					{
						if ((f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]) > new_label[m] && new_label[m] > -bigM / 2)

						{
							boolnum2 = 0;
						}
					}
				}
				else if (LY3bool2 == 2)
				{
					double old_total = value_function_forMoreThanM(tempf[ii], 1);
					double old_key = value_function_forMoreThanM(tempf[ii], 2);

					if (new_total < old_total)boolnum2 = 0;
					if (new_key < old_key)boolnum2 = 0;

				}

				if (boolnum2 == 1)
				{
					if (ii != i - 1)
					{
						for (int m = 0; m <= m_b - m_s + N; m++)
						{
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i - 1][m];
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i - 1][m] = 0;

						}
					}
					else {
						for (int m = 0; m <= m_b - m_s + N; m++)
						{
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] = 0;
						}
					}
					ii--;
					i--;
				}
			}
			boolnum = i;
		}

	}

	return boolnum;
}

void new_state_set(int* j, int n, int i, int nn, int dltj)
{
	memset(old_label, 0, sizeof(old_label));
	memset(new_label, 0, sizeof(new_label));
	for (int m1 = 0; m1 <= m_b - m_s + N; m1++)old_label[m1] = f[j[1]][j[2]][j[3]][j[4]][j[5]][j[6]][j[7]][j[8]][j[9]][j[10]][n][i][m1];

	new_label[m_b - m_s] = old_label[m_b - m_s] - setuptime[nn][n][m_b] - processtime[n][m_b] * dltj;
	for (int m1 = m_b - m_s - 1; m1 >= 0; m1--)new_label[m1] = (min1(new_label[m1 + 1], old_label[m1])) - setuptime[nn][n][m1 + m_s] - processtime[n][m1 + m_s] * dltj;

	for (int m1 = m_b - m_s + 1; m1 <= m_b - m_s + N; m1++)new_label[m1] = old_label[m1];

	if ((j[n] + dltj) == d[n])
	{
		double temp1 = new_label[0]; for (int m = 1; m < m_s; m++)temp1 -= (setuptime[nn][n][m] + processtime[n][m] * dltj);
		new_label[m_b - m_s + n] = temp1;
	}

	int jj[N + 1] = { 0 }; for (int n1 = 0; n1 <= N; n1++)jj[n1] = j[n1]; jj[n] += dltj;
	if (LY3bool2 != 2 || LYwaybool != 3)
		label_shixiao(jj, nn);

	int temp;
	if (LYwaybool == 0)temp = label_youxiaoxing(jj, nn);
	else if (LYwaybool == 1)temp = label_youxiaoxing_1(jj, nn);
	else if (LYwaybool == 2)temp = label_youxiaoxing_2(jj, nn);
	else if (LYwaybool == 3)temp = label_youxiaoxing_3(jj, nn);

	if (temp > maxcaseused) { maxcaseused = temp; }
	if (temp != -1)
	{

		for (int m = 0; m <= m_b - m_s + N; m++)
		{
			f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][temp][m] = new_label[m];
		}

	}

}

void new_state_go(int* j, int n, int i, int nn, int dltj)
{
	memset(old_label, 0, sizeof(old_label));
	memset(new_label, 0, sizeof(new_label));
	for (int m1 = 0; m1 <= m_b - m_s + N; m1++)old_label[m1] = f[j[1]][j[2]][j[3]][j[4]][j[5]][j[6]][j[7]][j[8]][j[9]][j[10]][n][i][m1];

	new_label[m_b - m_s] = old_label[m_b - m_s] - setuptime[nn][n][m_b] - processtime[n][m_b] * dltj;
	for (int m1 = m_b - m_s - 1; m1 >= 0; m1--)new_label[m1] = min1(new_label[m1 + 1], old_label[m1]) - setuptime[nn][n][m1 + m_s] - processtime[n][m1 + m_s] * dltj;

	for (int m1 = m_b - m_s + 1; m1 <= m_b - m_s + N; m1++)new_label[m1] = old_label[m1];

	if ((j[n] + dltj) == d[n])
	{
		double temp1 = new_label[0]; for (int m = 1; m < m_s; m++)temp1 -= (setuptime[nn][n][m] + processtime[n][m] * dltj);
		new_label[m_b - m_s + n] = temp1;
	}

}

void statetransition(int* j, int n)
{
	int lastnum[N + 1] = { 0 };
	for (int n = 1; n <= N; n++)lastnum[n] = d[n] - j[n];

	int i = 0;
	while (f[j[1]][j[2]][j[3]][j[4]][j[5]][j[6]][j[7]][j[8]][j[9]][j[10]][n][i][m_b - m_s] != 0 && i < maxcase) { i++; }

	for (int ii = 0; ii < i; ii++)
		for (int nn = 0; nn <= N; nn++)
			for (int dltj = 1; dltj <= lastnum[n]; dltj++)
			{

				new_state_set(j, n, ii, nn, dltj);
			}

}

void statetransition_initial(int* j, int n)
{

	int lastnum[N + 1] = { 0 };
	for (int n = 1; n <= N; n++)lastnum[n] = d[n] - j[n];

	double label_all[M + 1];
	for (int nn = 1; nn <= N; nn++)
		for (int dltj = 1; dltj <= lastnum[n]; dltj++)
		{
			memset(new_label, 0, sizeof(new_label));
			memset(label_all, 0, sizeof(label_all));

			label_all[M] = T0 - setuptime[nn][n][M] - processtime[n][M] * dltj;
			for (int m = M - 1; m >= 1; m--)
				label_all[m] = label_all[m + 1] - setuptime[nn][n][m] - processtime[n][m] * dltj;
			for (int m = 0; m <= m_b - m_s; m++)
				new_label[m] = label_all[m + m_s];
			if (dltj == d[n])
			{
				double temp1 = new_label[0];
				for (int m = 1; m < m_s; m++)temp1 -= (setuptime[nn][n][m] + processtime[n][m] * dltj);
				new_label[m_b - m_s + n] = temp1;
			}

			for (int m = 0; m <= m_b - m_s + N; m++)
			{
				f[j[1] + dltj * (n == 1)][j[2] + dltj * (n == 2)][j[3] + dltj * (n == 3)][j[4] + dltj * (n == 4)][j[5] + dltj * (n == 5)]
					[j[6] + dltj * (n == 6)][j[7] + dltj * (n == 7)][j[8] + dltj * (n == 8)][j[9] + dltj * (n == 9)][j[10] + dltj * (n == 10)][nn][0][m] = new_label[m];
			}

		}

}

double LAT[maxcase][NN + 1] = { 0 };
double fu_EI[maxcase];
int duqu()
{
	for (int i = 0; i < maxcase; i++)
	{
		for (int n = 0; n <= NN; n++)
		{
			LAT[i][n] = 0;
		}
	}
	for (int i = 0; i < maxcase; i++)
	{
		fu_EI[i] = 0;
	}
	int i = 0;
	while (f[d1][d2][d3][d4][d5][d6][d7][d8][d9][d10][0][i][m_b - m_s] != 0 || f[d1][d2][d3][d4][d5][d6][d7][d8][d9][d10][0][i][m_b - m_s - 1] != 0)
	{
		for (int n = 1; n <= NN; n++)LAT[i][n] = bigM / 2;
		for (int m = m_b + 1; m <= m_b + N; m++)
		{
			if (f[d1][d2][d3][d4][d5][d6][d7][d8][d9][d10][0][i][m - m_s] > -bigM)
				LAT[i][m - m_b] = f[d1][d2][d3][d4][d5][d6][d7][d8][d9][d10][0][i][m - m_s];
		}
		if (NN != N) {

		}
		else
		{
			fu_EI[i] = -bigM;
		}

		i++;

	}

	return i;
}

double U_math_way(int i)
{

	for (int n = 1; n <= NN; n++)
	{
		if (LAT[i][n] <= -bigM / 2)
		{
			LAT[i][n] = bigM;
		}
	}

	double max_an_LATn = -bigM;
	for (int n = 1; n <= NN; n++)
	{
		max_an_LATn = max1(max_an_LATn, an[n] - LAT[i][n]);
	}

	max_an_LATn = max1(max_an_LATn, fu_EI[i]);

	double max_bn_LATn = -bigM;
	for (int n = 1; n <= NN; n++)
	{
		max_bn_LATn = max1(max_bn_LATn, bn[n] - LAT[i][n]);
	}

	double b_LAT[NN + 1] = { 0 };
	for (int n = 1; n <= NN; n++)
	{
		b_LAT[n] = bn[n] - LAT[i][n];
	}
	int J[NN + 1] = { 0 };
	for (int n = 1; n <= NN; n++)
	{
		J[n] = n;
	}
	double tempc; int tempJ;
	for (int n = 1; n <= NN; n++)
	{
		int stop1 = 1;
		for (int nn = 1; nn <= NN - 1; nn++)
		{
			if (b_LAT[nn] > b_LAT[nn + 1])
			{
				tempc = b_LAT[nn]; b_LAT[nn] = b_LAT[nn + 1]; b_LAT[nn + 1] = tempc;
				tempJ = J[nn]; J[nn] = J[nn + 1]; J[nn + 1] = tempJ;
				stop1 = 0;
			}
		}
		if (stop1) { break; }
	}
	for (int n = 1; n <= NN; n++)
	{

	}

	int k = 1;
	while (max_an_LATn > b_LAT[k])
	{
		k++;
	}

	int c_j[NN + 1];
	for (int n = 0; n <= NN; n++)
	{
		c_j[n] = 0;
	}
	for (int n = 1; n <= NN - k + 1; n++)
	{
		c_j[n] = J[n + k - 1];
	}
	b_LAT[0] = max_an_LATn;
	int JJ = NN - k + 1;

	double m[NN + 1][NN + 2]; for (int n = 0; n <= NN; n++) { for (int nn = 0; nn <= NN + 1; nn++) { m[n][nn] = 0; } }
	int line[NN + 1]; for (int nn = 0; nn <= NN; nn++) { line[nn] = 0; }
	int count[NN + 1]; for (int nn = 0; nn <= NN; nn++) { count[nn] = 0; }

	int tempchachong;
	for (int jj = 0; jj < JJ; jj++)
	{
		for (int ii = 1; ii <= JJ - jj + 1; ii++)
		{

			int mm = JJ - jj + 1 - ii, nn = JJ - jj;
			for (int nnn = 0; nnn <= mm; nnn++) { count[nnn] = nnn; }

			while (1)
			{
				for (int nn1 = 0; nn1 <= NN; nn1++) { line[nn1] = 0; }
				for (int l = 1; l <= mm; l++)
				{
					line[l] = count[l];
				}
				tempchachong = 0;
				for (int l = 1; l <= mm - 1; l++)
				{
					if (line[l] >= line[l + 1]) { tempchachong = 1; }
				}

				if (tempchachong == 0)
				{

					long double temp2 = 1;
					for (int l = JJ - nn + 1; l <= JJ; l++)
					{
						int select = 0;
						for (int ll = 1; ll <= mm; ll++)
						{
							if (line[ll] == JJ - l + 1) { select = 1; }
						}
						if (select)
						{

							temp2 = temp2 / (bn[c_j[l]] - an[c_j[l]]);

						}
						else
						{
							temp2 = temp2 * (LAT[i][c_j[l]] - an[c_j[l]]) / (bn[c_j[l]] - an[c_j[l]]);

						}

					}
					m[jj][ii] = m[jj][ii] + temp2;
				}
				if (mm == 0) { break; }
				count[mm]++;
				for (int nnn = mm; nnn >= 2; nnn--)
				{
					if (count[nnn] > nn) {
						count[nnn - 1]++;
						count[nnn] = 1;
					}
				}
				if (count[1] > nn - mm + 1) { break; }
			}

		}
	}

	double temp1 = 0;
	for (int jj = 0; jj <= JJ - 1; jj++)
	{
		for (int ii = 1; ii <= JJ + 1 - jj; ii++)
		{

			if (jj == 0)
			{
				temp1 = temp1 + (pow((bn[c_j[jj + 1]] - LAT[i][c_j[jj + 1]]), JJ + 2 - jj - ii) - pow(max_an_LATn, JJ + 2 - jj - ii)) * m[jj][ii] / (JJ + 2 - jj - ii);
			}
			else
			{
				temp1 = temp1 + (pow((bn[c_j[jj + 1]] - LAT[i][c_j[jj + 1]]), JJ + 2 - jj - ii) - pow((bn[c_j[jj]] - LAT[i][c_j[jj]]), JJ + 2 - jj - ii)) * m[jj][ii] / (JJ + 2 - jj - ii);
			}

		}
	}
	double ex = max_bn_LATn - temp1;
	double U_time = ex + T0;

	return U_time;
}

double label_realtime_U_mathway(double* LAT_time)
{

	for (int n = 1; n <= NN; n++)
	{
		if (LAT_time[n] <= -bigM / 2)
		{
			LAT_time[n] = bigM;
		}
	}

	double max_an_LATn = -bigM;
	for (int n = 1; n <= NN; n++)
	{
		max_an_LATn = max1(max_an_LATn, an[n] - LAT_time[n]);
	}

	double fu_EI1 = 0;
	if (NN != N) {
		fu_EI1 = -LAT_time[M + NN + 1];
	}
	else
	{
		fu_EI1 = -bigM;
	}
	max_an_LATn = max1(max_an_LATn, fu_EI1);

	double max_bn_LATn = -bigM;
	for (int n = 1; n <= NN; n++)
	{
		max_bn_LATn = max1(max_bn_LATn, bn[n] - LAT_time[n]);
	}

	double b_LAT[NN + 1] = { 0 };
	for (int n = 1; n <= NN; n++)
	{
		b_LAT[n] = bn[n] - LAT_time[n];
	}
	int J[NN + 1] = { 0 };
	for (int n = 1; n <= NN; n++)
	{
		J[n] = n;
	}
	double tempc; int tempJ;
	for (int n = 1; n <= NN; n++)
	{
		int stop1 = 1;
		for (int nn = 1; nn <= NN - 1; nn++)
		{
			if (b_LAT[nn] > b_LAT[nn + 1])
			{
				tempc = b_LAT[nn]; b_LAT[nn] = b_LAT[nn + 1]; b_LAT[nn + 1] = tempc;
				tempJ = J[nn]; J[nn] = J[nn + 1]; J[nn + 1] = tempJ;
				stop1 = 0;
			}
		}
		if (stop1) { break; }
	}
	for (int n = 1; n <= NN; n++)
	{

	}

	int k = 1;
	while (max_an_LATn > b_LAT[k])
	{
		k++;
	}

	int c_j[NN + 1];
	for (int n = 0; n <= NN; n++)
	{
		c_j[n] = 0;
	}
	for (int n = 1; n <= NN - k + 1; n++)
	{
		c_j[n] = J[n + k - 1];
	}
	b_LAT[0] = max_an_LATn;
	int JJ = NN - k + 1;

	double m[NN + 1][NN + 2]; for (int n = 0; n <= NN; n++) { for (int nn = 0; nn <= NN + 1; nn++) { m[n][nn] = 0; } }
	int line[NN + 1]; for (int nn = 0; nn <= NN; nn++) { line[nn] = 0; }
	int count[NN + 1]; for (int nn = 0; nn <= NN; nn++) { count[nn] = 0; }

	int tempchachong;
	for (int jj = 0; jj < JJ; jj++)
	{
		for (int ii = 1; ii <= JJ - jj + 1; ii++)
		{

			int mm = JJ - jj + 1 - ii, nn = JJ - jj;
			for (int nnn = 0; nnn <= mm; nnn++) { count[nnn] = nnn; }

			while (1)
			{
				for (int nn1 = 0; nn1 <= NN; nn1++) { line[nn1] = 0; }
				for (int l = 1; l <= mm; l++)
				{
					line[l] = count[l];
				}
				tempchachong = 0;
				for (int l = 1; l <= mm - 1; l++)
				{
					if (line[l] >= line[l + 1]) { tempchachong = 1; }
				}

				if (tempchachong == 0)
				{

					long double temp2 = 1;
					for (int l = JJ - nn + 1; l <= JJ; l++)
					{
						int select = 0;
						for (int ll = 1; ll <= mm; ll++)
						{
							if (line[ll] == JJ - l + 1) { select = 1; }
						}
						if (select)
						{

							temp2 = temp2 / (bn[c_j[l]] - an[c_j[l]]);

						}
						else
						{
							temp2 = temp2 * (LAT_time[c_j[l]] - an[c_j[l]]) / (bn[c_j[l]] - an[c_j[l]]);

						}

					}
					m[jj][ii] = m[jj][ii] + temp2;
				}
				if (mm == 0) { break; }
				count[mm]++;
				for (int nnn = mm; nnn >= 2; nnn--)
				{
					if (count[nnn] > nn) {
						count[nnn - 1]++;
						count[nnn] = 1;
					}
				}
				if (count[1] > nn - mm + 1) { break; }
			}

		}
	}

	double temp1 = 0;
	for (int jj = 0; jj <= JJ - 1; jj++)
	{
		for (int ii = 1; ii <= JJ + 1 - jj; ii++)
		{

			if (jj == 0)
			{
				temp1 = temp1 + (pow((bn[c_j[jj + 1]] - LAT_time[c_j[jj + 1]]), JJ + 2 - jj - ii) - pow(max_an_LATn, JJ + 2 - jj - ii)) * m[jj][ii] / (JJ + 2 - jj - ii);
			}
			else
			{
				temp1 = temp1 + (pow((bn[c_j[jj + 1]] - LAT_time[c_j[jj + 1]]), JJ + 2 - jj - ii) - pow((bn[c_j[jj]] - LAT_time[c_j[jj]]), JJ + 2 - jj - ii)) * m[jj][ii] / (JJ + 2 - jj - ii);
			}

		}
	}
	double ex = max_bn_LATn - temp1;
	double U_time = ex + T0;

	return U_time;
}

int seq[50] = { 0 };
int seqsize[50] = { 0 };

double temp_label[M + NN + 2];
void sublot_size(double* ans, double* a1, double* b1)
{
	for (int a = 1; a < 50; a++)
	{
		seq[a] = 0;
	}
	cout << endl;
	for (int a = 1; a < 50; a++)
	{
		seqsize[a] = 0;
	}

	double rel[m_b - m_s + N + 1] = { 0 }; for (int m = 0; m <= m_b - m_s + N; m++)rel[m] = ans[m];
	int now1 = 1;
	int lastsize[N + 1] = { 0 }; for (int n = 1; n <= N; n++) { lastsize[n] = d[n]; }
	cout << "lattsize:" << endl;
	showint(lastsize);

	int prevN = 0;
	int endorder = 0; int count1 = 0;
	while (endorder == 0)
	{
		count1++;
		for (int n = 1; n <= N; n++)for (int dltj = 1; dltj <= lastsize[n]; dltj++)
		{
			int oldsize[N + 1] = { 0 }; for (int nn = 1; nn <= N; nn++) { oldsize[nn] = lastsize[nn]; } oldsize[n] -= dltj;
			for (int i = 0; i <= maxcaseused; i++)
			{

				new_state_go(oldsize, n, i, prevN, dltj);

				int bool1 = 0;
				/*		cout << "duibi " << endl;
						showdouble(new_label);
						showdouble(rel);*/

				for (int nn = 0; nn <= m_b - m_s; nn++) { if (new_label[nn] != rel[nn])bool1 = 1; }
				if (bool1 == 0)
				{
					seq[now1] = n; seqsize[now1] = dltj;
					for (int m = 0; m <= m_b - m_s + N; m++)rel[m] = old_label[m];

					now1++;
					lastsize[n] -= dltj;
					prevN = n;

					i = maxcase + 1;
					endorder = 1; for (int nn = 1; nn <= N; nn++)if (lastsize[nn] > 0)endorder = 0;
				}

			}

		}
		if (count1 > 50) {
			for (int i = 1; i <= N; i++)if (lastsize[i] > 0) { seq[now1] = i; seqsize[now1] = lastsize[i]; }
			break;
		}
	}

}

double min_label_real_time_U(double* a1, double* b1)
{
	int i = duqu();

	int counti = -1;
	double temp = bigM;
	for (int ii = 0; ii < i; ii++)
	{

	}

	for (int ii = 0; ii < i; ii++)
	{
		double time1 = U_math_way(ii);

		if (time1 < temp) { counti = ii; }
		temp = min1(temp, time1);
	}
	cout << "min real time: " << temp << endl;

	double temp2[M + NN + 2] = { 0 };
	for (int m = 0; m <= m_b - m_s + N; m++) {
		temp2[m] = f[d1][d2][d3][d4][d5][d6][d7][d8][d9][d10][0][counti][m];
	}
	sublot_size(temp2, a1, b1);
	for (int a = 1; a < 50; a++)
	{
		cout << seq[a] << ",";
	}
	cout << endl;
	for (int a = 1; a < 50; a++)
	{
		cout << seqsize[a] << ",";
	}
	cout << endl;
	return temp;
}

double t[N + 1] = { 0 };

double label_real_time(int i)
{

	double case_t[N + 1] = { 0,t[1],t[2],t[3],t[4],t[5] };

	for (int n = NN + 1; n <= N; n++)
	{
		case_t[n] = t[n];
	}
	double temp = -bigM;
	for (int n = 1; n <= NN; n++)
	{
		if ((case_t[n] - LAT[i][n]) <= bigM / 2)temp = max1(temp, (case_t[n] - LAT[i][n]));
	}
	temp = max1(temp, fu_EI[i]);
	temp = temp + T0;

	return temp;
}

double min_label_real_time(double* a1, double* b1)
{
	int i = duqu();
	cout << i << endl;

	for (int ii = 0; ii < i; ii++)
	{
		cout << "ceshi:" << ii << "  " << LAT[ii][1] << "  " << LAT[ii][2] << "  " << LAT[ii][3] << "  " << LAT[ii][4] << "  " << LAT[ii][5] << endl;
	}
	int counti = -1;
	double temp = bigM;
	for (int ii = 0; ii < i; ii++)
	{
		cout << "the label " << ii << " correspond to the makespan" << label_real_time(ii) << endl;
		if (label_real_time(ii) < temp) { counti = ii; }
		temp = min1(temp, label_real_time(ii));
	}
	cout << "min real time: " << temp << endl;

	double temp2[M + NN + 2] = { 0 };
	for (int m = 1; m <= M + NN + 1; m++) {
		temp2[m] = f[d1][d2][d3][d4][d5][d6][d7][d8][d9][d10][0][counti][m];
	}
	sublot_size(temp2, a1, b1);
	cout << "optimal result" << endl;
	for (int a = 0; a < 50; a++)
	{
		cout << seq[a] << " , ";
	}
	cout << endl;
	for (int a = 0; a < 50; a++)
	{
		cout << seqsize[a] << " , ";
	}
	cout << endl;
	return temp;
}

double yansuan()
{

	double time[50][M + 1] = { 0 };

	double tcase[N + 1] = { 0 };
	for (int n = 1; n <= N; n++)tcase[n] = t[n];
	double tstartbool[N + 1] = { 0 };
	int now1 = 1;
	while (seq[now1] != 0)
	{
		double temp1 = t[seq[now1]]; for (int m = 1; m < m_s; m++)temp1 += setuptime[seq[now1 - 1]][seq[now1]][m] + processtime[seq[now1]][m] * seqsize[now1];
		time[now1][0] = temp1;

		time[now1][m_s] = max1(time[now1 - 1][m_s], temp1) + setuptime[seq[now1 - 1]][seq[now1]][m_s] + processtime[seq[now1]][m_s] * seqsize[now1];
		for (int m = m_s + 1; m <= m_b; m++)time[now1][m] = max1(time[now1 - 1][m], time[now1][m - 1]) + setuptime[seq[now1 - 1]][seq[now1]][m] + processtime[seq[now1]][m] * seqsize[now1];
		cout << time[now1][m_b] << endl;
		cout << "now" << now1 << endl;
		now1++;

	}
	for (int m = m_b + 1; m <= M; m++)time[now1 - 1][m] = time[now1 - 1][m - 1] + setuptime[seq[now1 - 2]][seq[now1 - 1]][m] + processtime[seq[now1 - 1]][m] * seqsize[now1 - 1];

	for (int n = 1; n <= 30; n++)
	{
		cout << endl;
		for (int m = 0; m <= M; m++)
			cout << time[n][m] << " '  ";
	}

	return time[now1 - 1][M];
}

double yansuan1()
{

	double time[50][M + 1] = { 0 };
	for (int i = 0; i <= 49; i++)for (int j = 0; j <= M; j++)time[i][j] = T0;

	double tcase[N + 1] = { 0 };
	for (int n = 1; n <= N; n++)tcase[n] = t[n];
	double tstartbool[N + 1] = { 0 };
	int now1 = 49;
	while (seq[now1] == 0)now1--;

	double temp1 = T0; for (int m = M; m > m_b; m--)temp1 -= setuptime[seq[now1 - 1]][seq[now1]][m] + processtime[seq[now1]][m] * seqsize[now1];
	time[now1][M] = temp1;

	time[now1][m_b] = temp1 - setuptime[seq[now1 - 1]][seq[now1]][m_b] - processtime[seq[now1]][m_b] * seqsize[now1];
	for (int m = m_b - 1; m >= m_s; m--)time[now1][m] = time[now1][m + 1] - setuptime[seq[now1 - 1]][seq[now1]][m] - processtime[seq[now1]][m] * seqsize[now1];
	now1--;

	while (now1 > 0)
	{

		time[now1][m_b] = time[now1 + 1][m_b] - setuptime[seq[now1 - 1]][seq[now1]][m_b] - processtime[seq[now1]][m_b] * seqsize[now1];
		for (int m = m_b - 1; m >= m_s; m--)time[now1][m] = min1(time[now1 + 1][m], time[now1][m + 1]) - setuptime[seq[now1 - 1]][seq[now1]][m] - processtime[seq[now1]][m] * seqsize[now1];
		cout << time[now1][m_s] << endl;

		now1--;

	}
	for (int m = m_s - 1; m >= 1; m--)time[now1 + 1][m] = time[now1 + 1][m + 1] - setuptime[seq[now1]][seq[now1 + 1]][m] - processtime[seq[now1 + 1]][m] * seqsize[now1 + 1];

	for (int n = 0; n <= 30; n++)
	{
		cout << endl;
		for (int m = 0; m <= M; m++)
			cout << time[n][m] << " '  ";
	}

	return 0;
}

int label_youxiaoxing_2_xiajie(int* jj, int nn) {
	int boolnum = -1;
	int i = 0;

	while (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i][m_b - m_s] != 0 && i < maxcase)
	{

		i = i + 1;
	}

	double deltanew[M + 1] = { 0 };
	for (int m = 0; m <= m_b - m_s; m++)
	{
		deltanew[m] = new_label[m] - new_label[m - 1];
	}

	if (i >= maxcase)
	{
		int mix1 = -1;
		int mix2 = -1;

		int temp = bigM;

		for (int k = 0; k < i; k++)
			if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][k][0] <= temp)
				mix1 = k;
		for (int k = 0; k < i; k++)
			if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][k][0] <= temp && k != mix1)
				mix2 = k;

		for (int m = 0; m <= m_b - m_s + N; m++)if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][mix1][m] < f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][mix2][m])f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][mix1][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][mix2][m];

		for (int m = 0; m <= m_b - m_s + N; m++)f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][mix2][m] = new_label[m];

		double xielv_new = value_function(deltanew);

		int replace_num = -1;
		boolnum = -1;

	}
	else {

		if (i == 0)
		{
			return 0;
		}
		else
		{
			int boolnum1 = 0;
			for (int ii = 0; ii < i; ii++)
			{
				int boolnum11 = 1;
				for (int m = 0; m < m_b - m_s; m++)
				{
					if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] < min1(new_label[m] - 0.1, new_label[m + 1] - 0.1 - processtime[nn][m + 1]) && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]>-bigM / 2)
					{

						boolnum11 = 0;
					}
				}
				for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
				{
					if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] < new_label[m] - 0.1 && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]>-bigM / 2)
					{
						boolnum11 = 0;
					}
				}

				for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
				{
					if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] > -bigM / 2 && new_label[m] < -bigM / 2)
					{
						boolnum11 = 0;
					}
				}

				if (boolnum11 == 1)
				{
					boolnum1 = 1;
				}
			}

			if (boolnum1 == 0) 
			{

				int boolnum2 = 1;
				for (int ii = 0; ii < i; ii++)
				{
					boolnum2 = 1;
					for (int m = 0; m < m_b - m_s; m++)
					{
						if (min1(f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m], f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m + 1] - processtime[nn][m + 1]) > new_label[m] && new_label[m] > -bigM / 2)
						{
							boolnum2 = 0;
						}
					}
					for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
					{
						if ((f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m]) > new_label[m] && new_label[m] > -bigM / 2)

						{
							boolnum2 = 0;
						}
					}

					for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
					{
						if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] < -bigM / 2 && new_label[m] > -bigM / 2)
						{
							boolnum2 = 0;
						}
					}

					if (boolnum2 == 1)
					{
						if (ii != i - 1)
						{
							for (int m = 0; m <= m_b - m_s + N; m++)
							{
								f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i - 1][m];
								f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][i - 1][m] = 0;

							}
						}
						else {
							for (int m = 0; m <= m_b - m_s + N; m++)
							{
								f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][ii][m] = 0;
							}
						}
						ii--;
						i--;
					}
				}
				boolnum = i;
			}

		}

	}

	return boolnum;
}

void new_state_set_xiajie(int* j, int n, int i, int nn, int dltj)
{
	memset(old_label, 0, sizeof(old_label));
	memset(new_label, 0, sizeof(new_label));
	for (int m1 = 0; m1 <= m_b - m_s + N; m1++)old_label[m1] = f[j[1]][j[2]][j[3]][j[4]][j[5]][j[6]][j[7]][j[8]][j[9]][j[10]][n][i][m1];

	new_label[m_b - m_s] = old_label[m_b - m_s] - setuptime[nn][n][m_b] - processtime[n][m_b] * dltj;
	for (int m1 = m_b - m_s - 1; m1 >= 0; m1--)new_label[m1] = (min1(new_label[m1 + 1], old_label[m1])) - setuptime[nn][n][m1 + m_s] - processtime[n][m1 + m_s] * dltj;

	for (int m1 = m_b - m_s + 1; m1 <= m_b - m_s + N; m1++)new_label[m1] = old_label[m1];

	if ((j[n] + dltj) == d[n])
	{
		double temp1 = new_label[0]; for (int m = 1; m < m_s; m++)temp1 -= (setuptime[nn][n][m] + processtime[n][m] * dltj);
		new_label[m_b - m_s + n] = temp1;
	}

	int jj[N + 1] = { 0 }; for (int n1 = 0; n1 <= N; n1++)jj[n1] = j[n1]; jj[n] += dltj;
	if (LY3bool2 != 2 || LYwaybool != 3)
		label_shixiao(jj, nn);

	int temp;
	if (LYwaybool == 0)temp = label_youxiaoxing(jj, nn);
	else if (LYwaybool == 1)temp = label_youxiaoxing_1(jj, nn);
	else if (LYwaybool == 2)temp = label_youxiaoxing_2_xiajie(jj, nn);
	else if (LYwaybool == 3)temp = label_youxiaoxing_3(jj, nn);

	if (temp > maxcaseused) { maxcaseused = temp; }
	if (temp != -1)
	{

		for (int m = 0; m <= m_b - m_s + N; m++)
		{
			f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][jj[6]][jj[7]][jj[8]][jj[9]][jj[10]][nn][temp][m] = new_label[m];
		}

	}

}

void statetransition_xiajie(int* j, int n)
{
	int lastnum[N + 1] = { 0 };
	for (int n = 1; n <= N; n++)lastnum[n] = d[n] - j[n];

	int i = 0;
	while (f[j[1]][j[2]][j[3]][j[4]][j[5]][j[6]][j[7]][j[8]][j[9]][j[10]][n][i][m_b - m_s] != 0 && i < maxcase) { i++; }

	for (int ii = 0; ii < i; ii++)
		for (int nn = 0; nn <= N; nn++)
			for (int dltj = 1; dltj <= lastnum[n]; dltj++)
			{

				new_state_set_xiajie(j, n, ii, nn, dltj);
			}

}

void stateergodic_xiajie()
{
	int j[N + 1] = { 0 };

	for (int n = 1; n <= N; n++)statetransition_initial(j, n);
	for (j[1] = 0; j[1] <= d1; j[1]++)
		for (j[2] = 0; j[2] <= d2; j[2]++)
		{
			for (j[3] = 0; j[3] <= d3; j[3]++)
				for (j[4] = 0; j[4] <= d4; j[4]++)
					for (j[5] = 0; j[5] <= d5; j[5]++)
						for (j[6] = 0; j[6] <= d6; j[6]++)
							for (j[7] = 0; j[7] <= d7; j[7]++)
								for (j[8] = 0; j[8] <= d8; j[8]++)
									for (j[9] = 0; j[9] <= d9; j[9]++)
										for (j[10] = 0; j[10] <= d10; j[10]++)

											for (int n = 1; n <= N; n++)
											{
												int bool1 = 0;
												for (int i = 1; i <= N; i++)bool1 += j[i];
												if (bool1 > 0)
													statetransition_xiajie(j, n);

											}

		}

}

double min_label_real_time_U_xiajie(double* a1, double* b1)
{
	int i = duqu();

	int counti = -1;
	double temp = bigM;
	for (int ii = 0; ii < i; ii++)
	{

	}

	for (int ii = 0; ii < i; ii++)
	{
		double time1 = U_math_way(ii);

		if (time1 < temp) { counti = ii; }
		temp = min1(temp, time1);
	}

	return temp;
}

double average_arrival[N] = { 0.1, 0.1 , 0.1, 0.1, 0.1, 0.1 , 0.1, 0.1, 0.1,0.1 };

struct sequence
{
	vector<int>seq;
	vector<int>best_seq;
	vector<int>the_best_seq;
	vector<int>current_best_seq;
	vector<int> subsize_seq;
	float min_LAT = M;
	vector<float> LAT;
	int count_item[N];

};

int factorial(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
int choose(int n, int r)
{
	int result = 1;
	result = factorial(n) / (factorial(r) * factorial(n - r));
	return result;
}
int record_seq[500][NN] = { 0 };

std::random_device rd;
std::mt19937 g(rd());
void permutation(int n, int r) {

	int c = choose(n, r);

	vector<int>random_seq;
	for (int i = 0; i < NN; i++)
	{
		random_seq.push_back(i + 1);
	}

	for (int i = 0; i < c; i++)
	{

		std::shuffle(random_seq.begin(), random_seq.end(), g);
		std::sort(random_seq.begin(), random_seq.begin() + r);
		for (int j = 0; j < r; j++)
		{

			record_seq[i][j] = random_seq[j];

		}

	}

	int temp = 0;

	while (true)
	{
		int flag3 = 0;
		for (int i = 0; i < c; i++)
		{
			for (int k = 0; k < i; k++)
			{
				int flag = 0;
				for (int j = 0; j < r; j++)
				{
					if (record_seq[i][j] == record_seq[k][j])
					{
						flag++;
					}
					if (flag == r)
					{
						flag3++;
						std::shuffle(random_seq.begin(), random_seq.end(), g);
						std::sort(random_seq.begin(), random_seq.begin() + r);
						for (int j = 0; j < r; j++)
						{

							record_seq[i][j] = random_seq[j];

						}
					}
				}
			}
		}
		if (flag3 == 0)
		{
			break;
		}

	}

}

double p_value(int c, int r)
{
	double p = 0;
	for (int i = 0; i < r; i++)
	{
		p -= average_arrival[record_seq[c][i] - 1];
	}
	return p;
}

double q_value(int ii, int c, int r)
{
	double q = 0;
	for (int i = 0; i < r; i++)
	{
		if (LAT[ii][record_seq[c][i]] > -bigM / 2) {
			q -= (average_arrival[record_seq[c][i] - 1] * LAT[ii][record_seq[c][i]]);

		}
		else
		{
			q -= (average_arrival[record_seq[c][i] - 1] * bigM);
		}
	}

	return q;
}

double E_mathway(int ii)
{

	double max_an_LATn = -bigM;
	for (int n = 1; n <= NN; n++)
	{

		if (LAT[ii][n] >= -bigM / 2)	max_an_LATn = max1(max_an_LATn, -LAT[ii][n]);
	}

	max_an_LATn = max1(max_an_LATn, fu_EI[ii]);

	long double result = 0;

	for (int i = 0; i < NN; i++)
	{
		permutation(NN, i + 1);
		int c = choose(NN, i + 1);
		long double result_temp = 0;
		for (int j = 0; j < c; j++)
		{
			double p = p_value(j, i + 1);
			double q = q_value(ii, j, i + 1);
			double pow_e = p * (max_an_LATn)+q;

			result_temp += exp(pow_e) / p;

		}
		result_temp *= pow(-1.0, i + 1);
		result += result_temp;

	}
	result += max_an_LATn;

	return result;
}

double min_label_real_time_E(double* a1, double* b1)
{

	int i = duqu();

	int counti = -1;
	double temp = bigM;
	for (int ii = 0; ii < i; ii++)
	{
		double time1 = E_mathway(ii);

		if (time1 < temp) { counti = ii; }
		temp = min1(temp, time1);
	}

	cout << "min real time: " << temp + T0 << endl;


	double temp2[M + NN + 2] = { 0 };
	for (int m = 0; m <= m_b - m_s + N; m++) {
		temp2[m] = f[d1][d2][d3][d4][d5][d6][d7][d8][d9][d10][0][counti][m];
	}
	sublot_size(temp2, a1, b1);
	cout << "optimal result" << endl;
	for (int a = 1; a < 50; a++)
	{
		cout << seq[a] << ",";
	}
	cout << endl;
	for (int a = 1; a < 50; a++)
	{
		cout << seqsize[a] << ",";
	}
	cout << endl;
	return temp;
}

double min_label_real_time_E_xiajie(double* a1, double* b1)
{

	int i = duqu();

	int counti = -1;
	double temp = bigM;
	for (int ii = 0; ii < i; ii++)
	{
		double time1 = E_mathway(ii);

		if (time1 < temp) { counti = ii; }
		temp = min1(temp, time1);
	}

	cout << "xiajie: " << temp + T0 << endl;

	cout << endl;
	return temp;
}

#include "fstream"
#include"iostream"
#include<sstream>

void readUsefulArcs(string file_ml_result, int counti) 
{
	cout << "test1" << counti << endl;;

	ifstream ifile(file_ml_result, ios::in);
	string line, lineforcolumn, lineOld;
	getline(ifile, lineforcolumn);
	for (int i = 0; i < counti; i++)getline(ifile, lineOld);

	getline(ifile, line);
	istringstream sin(line);
	string tmp;
	getline(sin, tmp, ',');

	int tempTotal = 0;
	for (int i = 1; i <= N; i++) {
		getline(sin, tmp, ',');
		cout << "test2. " << tmp << endl;
		d[i] = (stoi(tmp));
		tempTotal += stoi(tmp);
	}

	for (int i = 1; i <= N; i++) {
		getline(sin, tmp, ',');
		a1[i] = (stof(tmp));
	}
	for (int i = 1; i <= N; i++) {
		getline(sin, tmp, ',');
		b1[i] = (stof(tmp));
	}

	d1 = d[1];
	d2 = d[2];
	d3 = d[3];
	d4 = d[4];
	d5 = d[5];
	d6 = d[6];
	d7 = d[7];
	d8 = d[8];
	d9 = d[9];
	d10 = d[10];
}

void readUsefulArcs_E(string file_ml_result, int counti) {
	cout << "test1" << counti << endl;;

	ifstream ifile(file_ml_result, ios::in);
	string line, lineforcolumn, lineOld;
	getline(ifile, lineforcolumn);
	for (int i = 0; i < counti; i++)getline(ifile, lineOld);

	getline(ifile, line);
	istringstream sin(line);
	string tmp;
	getline(sin, tmp, ',');

	int tempTotal = 0;
	for (int i = 1; i <= N; i++) {
		getline(sin, tmp, ',');
		cout << "test2. " << tmp << endl;
		d[i] = (stoi(tmp));
		tempTotal += stoi(tmp);
	}

	for (int i = 1; i <= N; i++) {
		getline(sin, tmp, ',');

	}
	for (int i = 1; i <= N; i++) {
		getline(sin, tmp, ',');
		average_arrival[i - 1] = 1 / (stof(tmp));
	}

	d1 = d[1];
	d2 = d[2];
	d3 = d[3];
	d4 = d[4];
	d5 = d[5];
	d6 = d[6];
	d7 = d[7];
	d8 = d[8];
	d9 = d[9];
	d10 = d[10];
}

void printToCsv(string title, string value) {
	string file_train_save = "outDataLB.csv";
	ofstream myfile(file_train_save, ios::out | ios::app);
	myfile << title << ':' << value << endl;;
	myfile.close();
}

void printToCsv(double title, double value, double time) {
	string file_train_save = "outDataLB_Nnew.csv";
	ofstream myfile(file_train_save, ios::out | ios::app);
	myfile << title << '\t' << value << '\t' << time << endl;;
	myfile.close();
}

int main(int argc, char* argv[])
{
	int caseNum = atoi(argv[1]);

	for (int counti = caseNum; counti <= caseNum; counti++)
	{

		maxcaseused = 0;

		cout << "compute the " << counti << " -th case" << endl;

		string file_train_save = "test2.csv";
		readUsefulArcs_E(file_train_save, counti);

		double a11[NN + 1] = { 0  ,0, 0, 0 , 0,  0,		0,  0,  0,  0, 0 };
		double b11[NN + 1] = { 0  ,30,30,30,30, 30,    30, 30, 30, 30,30 };
		for (int i = 1; i <= N; i++) {
			b11[i] = 3.0 / average_arrival[i - 1];
		}
		cout << "a:" << " ";
		for (auto s : a11) { cout << s << " "; }
		cout << endl;
		cout << "b: ";
		for (auto s : b11) { cout << s << " "; }
		cout << endl;

		for (int i1 = 1; i1 <= NN; i1++) { a1[i1] = a11[i1]; b1[i1] = b11[i1]; }
		for (int n = 0; n <= NN; n++) { an[n] = a1[n]; bn[n] = b1[n]; }

		vector_chushihua();
		chushihuaf();
		for (int i1 = 1; i1 <= I; i1++)
			for (int j1 = 0; j1 <= K; j1++)
			{

				processtime[i1][j1] = processtimeset[i1][j1];
			}
		chushihuasettime();

		maxcaseused = 0;

		clock_t start11, end11;
		start11 = clock();

		stateergodic_xiajie();
		cout << maxcaseused << endl;

		duqu();

		double makespanResult = min_label_real_time_E_xiajie(a1, b1);

		end11 = clock();

		double time4 = (end11 - start11) / (double)CLOCKS_PER_SEC;
		cout << "time use:" << (end11 - start11) / (double)CLOCKS_PER_SEC << "sec" << endl;

		printToCsv("indexOfCase", to_string(caseNum));
		printToCsv("makespan", to_string(makespanResult));
		printToCsv("time cost:", to_string(time4));

		printToCsv(caseNum, makespanResult, time4);

		string str1, str2;

		printToCsv(" ", " ");

		f.clear();
	}

	yansuan1();
	return 0;
}