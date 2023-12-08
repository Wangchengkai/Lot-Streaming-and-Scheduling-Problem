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

#define random(x) (rand()%x)

using namespace std;

// this code is write since 2019-3-1
// this code is updated on 2023-12-8
// we are welcome you to connect us if you have any question about this code
// the email address is: wangck@sjtu.edu.cn
// thank you for your attention!!!

//Define the control variables
#define bigM 255555
#define minS  1  //the minimum batch size
const double T0 = 10001;
const int maxcase = 10000;
int maxcaseused = -1;

int control1 = 3;//change the control1 to control the search range of the value function(LY2)
int LYwaybool = 2;//0 the original exact way; 
//1 the (test) way saving one optimal solution for each machine; 
//2 the appro way limiting the label number; 
//3 the (test) appro with a new value function 
int LY3bool1 = 2;//(for the value function: 1 save only one, 2 save several
int LY3bool2 = 1;/// is using the M+1 label to dominate the original label: 
//1: yes 0: no 
//2: use the M+1 label to dominate and merge 
//3: use the lookahead to complete the label and calculate the time for dominating
int LY3bool3 = 0;//1: merge 0 the origin one

//Define the problem values
#define I  5  //the number of jobs
const int N = I;
const int NN = I;

#define K 5
const int M = K;//the number of machines
//const int d[N + 1] = { 0,5,5,5,5,5 };
//const int d1 = 5, d2 = 5, d3 = 5, d4 = 5, d5 = 5;
//const int d[N + 1] = { 0,4,4,4,4,4,4 };
//const int d1 = 4, d2 = 4, d3 = 4, d4 = 4, d5 = 4, d6 = 4;
//const int d[N + 1] = { 0,1,1,1,1,1,1 };
//const int d1 = 1, d2 = 1, d3 = 1, d4 = 1, d5 = 1, d6 = 1;
const int d[N + 1] = { 0,3,3,3,3,3 };
const int d1 = 3, d2 = 3, d3 = 3, d4 = 3, d5 = 3;
//const int d[N + 1] = { 0,4,4,4,4,4 };
//const int d1 = 4, d2 = 4, d3 = 4, d4 = 4, d5 = 4;



double processtime[I + 1][K + 1] = {
	{ 0,0,0,0,0,0 },
	{ 0, 26,59,78,88,69 },
	{ 0, 38, 62, 90, 54, 30 },
	{ 0,27,44, 64,47,61 },
	{ 0,88,10, 49,83,35  },
	{ 0,95, 23, 47,84,53 } };
double setuptime[I + 1][I + 1][K + 1] = { 0 };




//double a1[NN + 1] = { 0,0,500,0,500,500 };
//double b1[NN + 1] = { 0,500,1000,500,1000,1500 };
//double an[NN + 1] = { 0,0,  500, 0,  500, 500 };
//double bn[NN + 1] = { 0,500,1000,500,1000,1500 };
double a1[NN + 1] = { 0,0,500,0,500,500 };
double b1[NN + 1] = { 0,500,1000,500,1000,1500 };
double an[NN + 1] = { 0,0,  500, 0,  500, 500 };
double bn[NN + 1] = { 0,500,1000,500,1000,1500 };

//double a1[NN + 1] = { 0,0,0,0,0,0 };
//double b1[NN + 1] = { 0,0.1,0.1,0.1,0.1,0.1 };
//double an[NN + 1] = { 0,0,  0, 0,  0, 0 };
//double bn[NN + 1] = { 0,0.1,0.1,0.1,0.1,0.1 };


//const int NN = 5;
const int m_s = 1;
const int m_b = M;

//the list of functions
void stateergodic();
void label_shixiao(int* jj, int nn);
int label_youxiaoxing(int* jj, int nn);
void new_state_set(int* j, int n, int i, int nn, int dltj);
void statetransition(int* j, int n);
void statetransition_initial(int* j, int n);

double N_matlab_way(int i);
double diaoyong_matlab(int count1, double temp1, double temp2, int i, int* bb);

double old_label[N + M + 1] = { 0 };
double new_label[N + M + 1] = { 0 };
//double f[d1 + 1][d2 + 1][d3 + 1][d4 + 1][d5 + 1][N + 1][maxcase + 1][m_b - m_s + N + 1];

std::vector < std::vector <std::vector<std::vector<std::vector<std::vector<std::vector<std::vector<float>>>>>>>> f;
void vector_chushihua()
{
	int counti = 0;
	int counti1 = 0;
	f.reserve(d1 + 1);

	for (size_t i = 0; i < d1 + 1; i++)
	{
		std::vector  < std::vector < std::vector <std::vector<std::vector<std::vector<std::vector<float>>>>>>> submatrix;
		submatrix.reserve(d2 + 1);

		for (size_t j = 0; j < d2 + 1; j++)
		{
			std::vector   < std::vector <std::vector<std::vector<std::vector<std::vector<float>>>>>> submatrix1;
			submatrix1.reserve(d3 + 1);

			for (size_t j3 = 0; j3 < d3 + 1; j3++)
			{
				counti++;
				cout << counti << endl;
				std::vector <std::vector<std::vector<std::vector<std::vector<float>>>>> submatrix2;
				submatrix2.reserve(d4 + 1);

				for (size_t j4 = 0; j4 < d4 + 1; j4++)
				{
					counti1++;
					cout << "256per " << counti1 << endl;
					std::vector<std::vector<std::vector<std::vector<float>>>> submatrix3;
					submatrix3.reserve(d5 + 1);

					for (size_t j5 = 0; j5 < d5 + 1; j5++)
					{


						std::vector<std::vector<std::vector<float>>> submatrix5;
						submatrix5.reserve(N + 1);

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
							submatrix5.push_back(submatrix10);
						}

						submatrix3.push_back(submatrix5);



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
	maxcaseused = 0;

	//memset(f, 0, sizeof(f));
	int j[N + 1] = { 0 };
	for (j[1] = 0; j[1] <= d1; j[1]++)
		for (j[2] = 0; j[2] <= d2; j[2]++)
			for (j[3] = 0; j[3] <= d3; j[3]++)
				for (j[4] = 0; j[4] <= d4; j[4]++)
					for (j[5] = 0; j[5] <= d5; j[5]++)
						//for (j[6] = 0; j[6] <= d6; j[6]++)
						for (int n = 0; n <= N; n++)
							for (int i = 0; i <= maxcase; i++)
								for (int m = 0; m <= m_b - m_s + N; m++)
								{
									f[j[1]][j[2]][j[3]][j[4]][j[5]][n][i][m] = 0;
								}




	for (int n = 1; n <= N; n++)f[0][0][0][0][0][n][0][m_b - m_s] = T0;


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
					setuptime[0][j][k] = setuptime[i][j][k];
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
						//for (j[6] = 0; j[6] <= d6; j[6]++)
						for (int n = 1; n <= N; n++)
						{
							int bool1 = 0;
							for (int i = 1; i <= N; i++)bool1 += j[i];
							if (bool1 > 0)
								statetransition(j, n);
							//	cout << "j1:" << j[1] << " j2: " << j[2] << " j3: " << j[3] << " j4: " << j[4] << " j5: " << j[5] << "nn " << n << " MAXcase " << maxcaseused << endl;// " time0 " << f[j[1]][j[2]][j[3]][j[4]][j[5]][1][0][m_b - m_s] << endl;
						}
			cout << "j1:" << j[1] << " j2: " << j[2] << " MAXcase " << maxcaseused << endl;

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
					new_label[m_b - m_s + n] = -3 * bigM;//the job n is not important
			}
		}
	}
}

int label_youxiaoxing(int* jj, int nn)
{
	int boolnum = -1;//-1 means invalid.
	int i = 0;
	while (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][i][m_b - m_s] != 0 && i < maxcase)//means i stores the solution
	{
		if (i == maxcase) {
			cout << "the label is over space" << endl;
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
		//about domination
		int boolnum1 = 0;
		for (int ii = 0; ii < i; ii++)
		{
			int boolnum11 = 1;
			for (int m = 0; m < m_b - m_s; m++)
			{
				if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] < min1(new_label[m] - 0.1, new_label[m + 1] - 0.1 - processtime[nn][m + 1]) && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m]>-bigM / 2)
				{
					//change
					boolnum11 = 0;
				}
			}
			for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
			{
				if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] < new_label[m] - 0.1 && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m]>-bigM / 2)
				{
					boolnum11 = 0;
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
					if (min1(f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m], f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m + 1] - processtime[nn][m + 1]) > new_label[m] && new_label[m] > -bigM / 2)
					{
						boolnum2 = 0;
					}
				}
				for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
				{
					if ((f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m]) > new_label[m] && new_label[m] > -bigM / 2)
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
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][i - 1][m];
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][i - 1][m] = 0;
						}
					}
					else {
						for (int m = 0; m <= m_b - m_s + N; m++)
						{
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] = 0;
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
}

int label_youxiaoxing_1(int* jj, int nn) 
{
	for (int k = 0; k <= m_b - m_s; k++)
	{
		if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][k][k] < new_label[k] || f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][k][k] == 0)
		{
			for (int m = 0; m <= m_b - m_s + NN; m++)f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][k][m] = new_label[m];
			maxcaseused = M;
		}

	}
	return -1;
}

double value_function(double* delta_value)
{
	double out = -1;
	int choose_i = 0;
	if (choose_i == 0)//slope
	{
		out = 0;
		for (int m = 2; m <= M; m++)out += delta_value[m];
		out = out / (M - 1);
	}
	else if (choose_i == 1)//label
	{
		out = 0;
		for (int m = 2; m <= M; m++)out += M * delta_value[m];
		out = out / (M - 1);
	}
	else if (choose_i == 2)//cumulative
	{
		out = 0;
		for (int m = 2; m <= M; m++)out = out * 1.2 + delta_value[m];
		out = out / (M - 1);
	}
	return out;
}

double delta[maxcase][M + 1] = { 0 };
int label_youxiaoxing_2(int* jj, int nn) {
	int boolnum = -1;//-1 means invalid.
	int i = 0;
	while (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][i][m_b - m_s] != 0 && i < maxcase)
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

	if (i >= maxcase)//domination
	{
		double xielv_new = value_function(deltanew);
		for (int k = 0; k < i; k++)for (int m = 1; m <= m_b - m_s; m++)
		{
			delta[k][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][k][m] - f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][k][m - 1];
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
			if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][replace_num][0] <= new_label[1])
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
		if (replace_num != -1)for (int m = 0; m <= m_b - m_s + N; m++)f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][replace_num][m] = new_label[m];
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
					if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] < min1(new_label[m] - 0.1, new_label[m + 1] - 0.1 - processtime[nn][m + 1]) && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m]>-bigM / 2)
					{
						boolnum11 = 0;
					}
				}
				for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
				{
					if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] < new_label[m] - 0.1 && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m]>-bigM / 2)
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
						if (min1(f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m], f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m + 1] - processtime[nn][m + 1]) > new_label[m] && new_label[m] > -bigM / 2)
						{
							boolnum2 = 0;
						}
					}
					for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
					{
						if ((f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m]) > new_label[m] && new_label[m] > -bigM / 2)
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
								f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][i - 1][m];
								f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][i - 1][m] = 0;
							}
						}
						else {
							for (int m = 0; m <= m_b - m_s + N; m++)
							{
								f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] = 0;
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
			out += (prevalue[m] - T0) * tt[m - M];// *(b1[m - M] - a1[m - M]);
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
	for (int ms = 0; ms < maxcase + 1; ms++)for (int m = 0; m < m_b - m_s + NN + 2; m++)tempf[ms][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ms][m];

	int boolnum = -1;
	int i = 0;
	double new_total = value_function_forMoreThanM(new_label, 1);
	double new_key = value_function_forMoreThanM(new_label, 2);

	while (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][i][m_b - m_s] != 0 && i < maxcase)
	{

		if (i == maxcase) {
			cout << "the label is over space" << endl;
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
				if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] < min1(new_label[m] - 0.1, new_label[m + 1] - 0.1 - processtime[nn][m + 1]) && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m]>-bigM / 2)
				{
					boolnum11 = 0;
				}
			}


			if (LY3bool2 == 1)
			{
				for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
				{
					if (f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] < new_label[m] - 0.1 && f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m]>-bigM / 2)
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
					if (min1(f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m], f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m + 1] - processtime[nn][m + 1]) > new_label[m] && new_label[m] > -bigM / 2)
					{
						boolnum2 = 0;
					}
				}
				if (LY3bool2 == 1)
				{
					for (int m = m_b - m_s; m <= m_b - m_s + N; m++)
					{
						if ((f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m]) > new_label[m] && new_label[m] > -bigM / 2)
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
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] = f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][i - 1][m];
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][i - 1][m] = 0;
						}
					}
					else {
						for (int m = 0; m <= m_b - m_s + N; m++)
						{
							f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][ii][m] = 0;
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
	for (int m1 = 0; m1 <= m_b - m_s + N; m1++)old_label[m1] = f[j[1]][j[2]][j[3]][j[4]][j[5]][n][i][m1];
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
	if (LYwaybool == 0)temp = label_youxiaoxing(jj, nn);//the original way
	else if (LYwaybool == 1)temp = label_youxiaoxing_1(jj, nn);//the way saving one optimal solution
	else if (LYwaybool == 2)temp = label_youxiaoxing_2(jj, nn);//the way limiting the maximum number of labels
	else if (LYwaybool == 3)temp = label_youxiaoxing_3(jj, nn);//the way choosing the label by a value function

	if (temp > maxcaseused) { maxcaseused = temp; }
	if (temp != -1)
	{
		for (int m = 0; m <= m_b - m_s + N; m++)
		{
			f[jj[1]][jj[2]][jj[3]][jj[4]][jj[5]][nn][temp][m] = new_label[m];
		}
	}
}


void new_state_go(int* j, int n, int i, int nn, int dltj)
{
	memset(old_label, 0, sizeof(old_label));
	memset(new_label, 0, sizeof(new_label));
	for (int m1 = 0; m1 <= m_b - m_s + N; m1++)old_label[m1] = f[j[1]][j[2]][j[3]][j[4]][j[5]][n][i][m1];

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
	while (f[j[1]][j[2]][j[3]][j[4]][j[5]][n][i][m_b - m_s] != 0 && i < maxcase) { i++; }
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
				f[j[1] + dltj * (n == 1)][j[2] + dltj * (n == 2)][j[3] + dltj * (n == 3)][j[4] + dltj * (n == 4)][j[5] + dltj * (n == 5)][nn][0][m] = new_label[m];
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
	while (f[d1][d2][d3][d4][d5][0][i][m_b - m_s] != 0 || f[d1][d2][d3][d4][d5][0][i][m_b - m_s - 1] != 0)
	{
		for (int n = 1; n <= NN; n++)LAT[i][n] = bigM / 2;
		for (int m = m_b + 1; m <= m_b + N; m++)
		{
			if (f[d1][d2][d3][d4][d5][0][i][m - m_s] > -bigM)
				LAT[i][m - m_b] = f[d1][d2][d3][d4][d5][0][i][m - m_s];
		}
		if (NN != N) {
		}
		else
		{
			fu_EI[i] = -bigM;
		}

		i++;
		if (i >= maxcase) { cout << "over space" << endl; break; }
	}

	for (int n = 0; n <= NN; n++)cout << LAT[0][n] << endl;
	return i;//there are i solutions. they are stored in 0 - i-1.
}

// ************************************************uniform distribution************************************************
double U_math_way(int i)//the current label is the i-th label
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

	//Now, b_LAT[1] is the smallest value, and J[1] is the index of the smallest value.
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
	//compute m
	int tempchachong;
	for (int jj = 0; jj < JJ; jj++)
	{
		for (int ii = 1; ii <= JJ - jj + 1; ii++)
		{
			//choose ii from JJ-jj
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

double label_realtime_U_mathway(double* LAT_time)//the label is the i th label
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

//get the size of the sublot
int seq[50] = { 0 };
int seqsize[50] = { 0 };

double temp_label[M + NN + 2];
void sublot_size(double* ans, double* a1, double* b1)//input the full label
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
	cout << i << endl;
	int counti = -1;
	double temp = bigM;
	for (int ii = 0; ii < i; ii++)
	{
		double time1 = U_math_way(ii);
		if (time1 < temp) { counti = ii; }
		temp = min1(temp, time1);
	}
	cout << "min real time: " << temp << endl;
	cout << "the best one is the " << counti << " -th label" << endl;
	cout << "Save at most " << maxcaseused + 1 << " -th labels in the process " << endl;
	double temp2[M + NN + 2] = { 0 };
	for (int m = 0; m <= m_b - m_s + N; m++) {
		temp2[m] = f[d1][d2][d3][d4][d5][0][counti][m];
	}
	sublot_size(temp2, a1, b1);
	cout << "the optimal sublot size is " << endl;
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
	//request that the job after NN+1 must be deterministic
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
		if (label_real_time(ii) < temp) { counti = ii; }
		temp = min1(temp, label_real_time(ii));
	}
	cout << "min real time: " << temp << endl;
	cout << "the smallest label is the " << counti << " -th one" << endl;
	cout << "Save at most " << maxcaseused + 1 << " -th labels in the process " << endl;
	double temp2[M + NN + 2] = { 0 };
	for (int m = 1; m <= M + NN + 1; m++) {
		temp2[m] = f[d1][d2][d3][d4][d5][0][counti][m];
	}
	sublot_size(temp2, a1, b1);
	cout << "the optimal sublot size is " << endl;
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

//confirm 
double yansuan()//in one case
{
	//seq,seqsize
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

double yansuan1()//in one case
{
	//seq,seqsize
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
		//cout << "now " << now1 << endl;
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

//**************************************************exponential distribution***********************************
double average_arrival[N] = { 0.001, 0.001 , 0.001, 0.001, 0.001 };/* ,150,300,450,200,300 };*///here is in fact:  1/lambda

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

//the core part, permutation
int factorial(int n)//value of n!
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}
int choose(int n, int r)//value of nCr
{
	int result = 1;
	result = factorial(n) / (factorial(r) * factorial(n - r));
	return result;
}
int record_seq[500][NN] = { 0 };//for permutation

void permutation(int n, int r) {//get the all random sequence of n choose r, in order to calculate p & q

	int c = choose(n, r);

	vector<int>random_seq;
	for (int i = 0; i < NN; i++)
	{
		random_seq.push_back(i + 1);//create a sequence{1,2,...,N}
	}

	for (int i = 0; i < c; i++)
	{
		//note that "random_shuffle" is removed after C++ 14, if you cannot get it, please use "std::shuffle" instead.
		random_shuffle(random_seq.begin(), random_seq.end());//shuffle the sequence
		std::sort(random_seq.begin(), random_seq.begin() + r);//permutation
		for (int j = 0; j < r; j++)
		{
			record_seq[i][j] = random_seq[j];// record the first r values of the sequence
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
					if (record_seq[i][j] == record_seq[k][j])// when there are some same values
					{
						flag++;
					}
					if (flag == r)// some same values appear, refresh the i-th sequence
					{
						flag3++;
						//note that "random_shuffle" is removed after C++ 14, if you cannot get it, please use "std::shuffle" instead.
						random_shuffle(random_seq.begin(), random_seq.end());
						std::sort(random_seq.begin(), random_seq.begin() + r);
						for (int j = 0; j < r; j++)
						{

							record_seq[i][j] = random_seq[j];
							//	cout << random_seq[j];

						}
					}
				}
			}
		}
		if (flag3 == 0)//the whole group has no same sequence
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

double E_mathway(int ii)// the expected value of delay
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
	cout << "the smallest label is the " << counti << " -th label" << endl;
	cout << "Save at most " << maxcaseused + 1 << " labels in the process" << endl;

	double temp2[M + NN + 2] = { 0 };
	for (int m = 0; m <= m_b - m_s + N; m++) {
		temp2[m] = f[d1][d2][d3][d4][d5][0][counti][m];
	}
	sublot_size(temp2, a1, b1);
	cout << "optimal sublot size " << endl;
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

//***********************************************************************Normal***********************************************************************
double miu[NN + 1] = { 0,250,750,250,750,1000 };
double sigma[NN + 1] = { 0,250 / 3,250 / 3,250 / 3,250 / 3,500 / 3 };

// the original code is have several visions, we give one version using integral here.
// if you do not have "engine.h" and "engine.lib", please delete the following code (until the Normal end).
#include "engine.h"
Engine* ep;
double min_label_real_time_N(double* a1, double* b1)
{
	if (!(ep = engOpen("\0")))
	{
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		return EXIT_FAILURE;
	}
	int i = duqu();

	int counti = -1;
	double temp = bigM;
	for (int ii = 0; ii < i; ii++)
	{
		double time1 = N_matlab_way(ii);
		if (time1 < temp) { counti = ii; }
		temp = min1(temp, time1);
	}

	// close engine
	engClose(ep);

	cout << "min real time: " << temp << endl;
	cout << "the optimal label is the " << counti << " -th label" << endl;
	cout << "save at most " << maxcaseused + 1 << " labels in the process" << endl;
	double temp2[M + NN + 2] = { 0 };
	for (int m = 0; m <= m_b - m_s + N; m++) {
		temp2[m] = f[d1][d2][d3][d4][d5][0][counti][m];
	}
	sublot_size(temp2, a1, b1);
	cout << "the optimal sublot is " << endl;
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

double N_matlab_way(int i)
{
	double an[NN + 1] = { 0 }, bn[NN + 1] = { 0 };
	for (int n = 1; n <= NN; n++)
	{
		an[n] = miu[n] - 3 * sigma[n];
		bn[n] = miu[n] + 3 * sigma[n];
	}
	double an_LAT[NN + 1] = { 0 };
	for (int n = 1; n <= NN; n++)
	{
		an_LAT[n] = an[n] - LAT[i][n];
	}
	double temp1 = fu_EI[i];
	for (int n = 1; n <= NN; n++)
	{
		if (an_LAT[n] < bigM / 2 && an_LAT[n]>temp1) {
			temp1 = an_LAT[n];
		}
	}
	double bn_LAT[NN + 1] = { 0 };
	for (int n = 1; n <= NN; n++)
	{
		bn_LAT[n] = bn[n] - LAT[i][n];
	}
	double temp2 = -bigM;
	for (int n = 1; n <= NN; n++)
	{
		if (bn_LAT[n] < bigM / 2 && bn_LAT[n]>temp2) {
			temp2 = bn_LAT[n];
		}
	}

	if (temp2 <= temp1) {
		return 0;
	}

	int count1 = 0; int bb[NN + 1 + 10] = { 0 };
	for (int n = 1; n <= NN; n++)
	{
		if (an_LAT[n] < bigM / 2)
		{
			count1++;
			bb[count1] = n;
		}
	}
	double jifeng = diaoyong_matlab(count1, temp1, temp2, i, bb);
	double result = jifeng + temp1 + T0;

	return result;
}


double diaoyong_matlab(int count1, double temp1, double temp2, int i, int* bb)
{
	mxArray* miu1 = NULL, * sigma1 = NULL;
	mxArray* LAT1 = NULL;
	mxArray* miu2 = NULL, * sigma2 = NULL;
	mxArray* LAT2 = NULL;
	mxArray* miu3 = NULL, * sigma3 = NULL;
	mxArray* LAT3 = NULL;
	mxArray* miu4 = NULL, * sigma4 = NULL;
	mxArray* LAT4 = NULL;
	mxArray* miu5 = NULL, * sigma5 = NULL;
	mxArray* LAT5 = NULL;


	string str0 = "L=" + to_string(temp1);
	string str1 = "H=" + to_string(temp2);
	engEvalString(ep, str0.c_str());
	engEvalString(ep, str1.c_str());

	string str2 = "miu1=" + to_string(miu[bb[1]]);
	string str3 = "sigma1=" + to_string(sigma[bb[1]]);
	string str4 = "LAT1=" + to_string(LAT[i][bb[1]]);

	string str21 = "miu2=" + to_string(miu[bb[2]]);
	string str31 = "sigma2=" + to_string(sigma[bb[2]]);
	string str41 = "LAT2=" + to_string(LAT[i][bb[2]]);

	string str22 = "miu3=" + to_string(miu[bb[3]]);
	string str32 = "sigma3=" + to_string(sigma[bb[3]]);
	string str42 = "LAT3=" + to_string(LAT[i][bb[3]]);

	string str23 = "miu4=" + to_string(miu[bb[4]]);
	string str33 = "sigma4=" + to_string(sigma[bb[4]]);
	string str43 = "LAT4=" + to_string(LAT[i][bb[4]]);

	string str24 = "miu5=" + to_string(miu[bb[5]]);
	string str34 = "sigma5=" + to_string(sigma[bb[5]]);
	string str44 = "LAT5=" + to_string(LAT[i][bb[5]]);



	string str51 = "fun = @(x) (1-cdf('norm',(x-miu1+LAT1)/sigma1,0,1));";
	string str52 = "fun = @(x) (1-cdf('norm',(x-miu1+LAT1)/sigma1,0,1).*cdf('norm',(x-miu2+LAT2)/sigma2,0,1));";
	string str53 = "fun = @(x) (1-cdf('norm',(x-miu1+LAT1)/sigma1,0,1).*cdf('norm',(x-miu2+LAT2)/sigma2,0,1).*cdf('norm',(x-miu3+LAT3)/sigma3,0,1));";
	string str54 = "fun = @(x) (1-cdf('norm',(x-miu1+LAT1)/sigma1,0,1).*cdf('norm',(x-miu2+LAT2)/sigma2,0,1).*cdf('norm',(x-miu3+LAT3)/sigma3,0,1).*cdf('norm',(x-miu4+LAT4)/sigma4,0,1));";
	string str55 = "fun = @(x) (1-cdf('norm',(x-miu1+LAT1)/sigma1,0,1).*cdf('norm',(x-miu2+LAT2)/sigma2,0,1).*cdf('norm',(x-miu3+LAT3)/sigma3,0,1).*cdf('norm',(x-miu4+LAT4)/sigma4,0,1).*cdf('norm',(x-miu5+LAT5)/sigma5,0,1));";

	double* pc;
	double pc1;
	if (count1 == 1)
	{
		engEvalString(ep, str2.c_str());
		engEvalString(ep, str3.c_str());
		engEvalString(ep, str4.c_str());
		engEvalString(ep, str51.c_str());
		engEvalString(ep, "q = integral(fun,L,H);");


		mxArray* Result = mxCreateDoubleMatrix(1, 1, mxREAL);
		Result = engGetVariable(ep, "q");
		//cout << Result << endl;
		pc = mxGetPr(Result);

		//cout << "PC:" << pc << endl;
		pc1 = *pc;
		//fgetc(stdin);

		// clean operation(don't forget!!!)
		mxDestroyArray(Result);
		engEvalString(ep, "clear;");

		// close engine
		//engClose(ep);
		return pc1;
	}
	if (count1 == 2)
	{

		engEvalString(ep, str2.c_str());
		engEvalString(ep, str3.c_str());
		engEvalString(ep, str4.c_str());
		engEvalString(ep, str21.c_str());
		engEvalString(ep, str31.c_str());
		engEvalString(ep, str41.c_str());
		engEvalString(ep, str52.c_str());
		engEvalString(ep, "q = integral(fun,L,H);");


		mxArray* Result = mxCreateDoubleMatrix(1, 1, mxREAL);
		Result = engGetVariable(ep, "q");
		//cout << Result << endl;
		pc = mxGetPr(Result);

		//cout << "PC:" << pc << endl;
		pc1 = *pc;
		//fgetc(stdin);

		// clean operation(don't forget!!!)
		mxDestroyArray(Result);
		engEvalString(ep, "clear;");

		// close engine
		//engClose(ep);
		return pc1;
	}
	if (count1 == 3)
	{
		engEvalString(ep, str2.c_str());
		engEvalString(ep, str3.c_str());
		engEvalString(ep, str4.c_str());
		engEvalString(ep, str21.c_str());
		engEvalString(ep, str31.c_str());
		engEvalString(ep, str41.c_str());
		engEvalString(ep, str22.c_str());
		engEvalString(ep, str32.c_str());
		engEvalString(ep, str42.c_str());
		engEvalString(ep, str53.c_str());
		engEvalString(ep, "q = integral(fun,L,H);");


		mxArray* Result = mxCreateDoubleMatrix(1, 1, mxREAL);
		Result = engGetVariable(ep, "q");
		//cout << Result << endl;
		pc = mxGetPr(Result);

		//cout << "PC:" << pc << endl;
		pc1 = *pc;

		// clean operation(don't forget!!!)
		mxDestroyArray(Result);
		engEvalString(ep, "clear;");

		// close engine
		//engClose(ep);
		return pc1;
	}
	if (count1 == 4)
	{
		engEvalString(ep, str2.c_str());
		engEvalString(ep, str3.c_str());
		engEvalString(ep, str4.c_str());
		engEvalString(ep, str21.c_str());
		engEvalString(ep, str31.c_str());
		engEvalString(ep, str41.c_str());
		engEvalString(ep, str22.c_str());
		engEvalString(ep, str32.c_str());
		engEvalString(ep, str42.c_str());
		engEvalString(ep, str23.c_str());
		engEvalString(ep, str33.c_str());
		engEvalString(ep, str43.c_str());
		engEvalString(ep, str54.c_str());
		engEvalString(ep, "q = integral(fun,L,H);");


		mxArray* Result = mxCreateDoubleMatrix(1, 1, mxREAL);
		Result = engGetVariable(ep, "q");
		//cout << Result << endl;
		pc = mxGetPr(Result);

		//cout << "PC:" << pc << endl;
		pc1 = *pc;
		//fgetc(stdin);

		// clean operation(don't forget!!!)
		mxDestroyArray(Result);
		engEvalString(ep, "clear;");

		// close engine
		//engClose(ep);
		return pc1;
	}
	if (count1 == 5)
	{
		engEvalString(ep, str2.c_str());
		engEvalString(ep, str3.c_str());
		engEvalString(ep, str4.c_str());
		engEvalString(ep, str21.c_str());
		engEvalString(ep, str31.c_str());
		engEvalString(ep, str41.c_str());
		engEvalString(ep, str22.c_str());
		engEvalString(ep, str32.c_str());
		engEvalString(ep, str42.c_str());
		engEvalString(ep, str23.c_str());
		engEvalString(ep, str33.c_str());
		engEvalString(ep, str43.c_str());
		engEvalString(ep, str24.c_str());
		engEvalString(ep, str34.c_str());
		engEvalString(ep, str44.c_str());
		engEvalString(ep, str55.c_str());
		engEvalString(ep, "q = integral(fun,L,H);");


		mxArray* Result = mxCreateDoubleMatrix(1, 1, mxREAL);
		Result = engGetVariable(ep, "q");
		//cout << Result << endl;
		pc = mxGetPr(Result);

		//cout << "PC:" << pc << endl;
		pc1 = *pc;
		//fgetc(stdin);

		// clean operation(don't forget!!!)
		mxDestroyArray(Result);
		engEvalString(ep, "clear;");


		return pc1;

	}

	/*	engEvalString(ep, "q = integral(fun,L,H);");

	double *pc;
	mxArray *Result = mxCreateDoubleMatrix(1, 1, mxREAL);
	Result = engGetVariable(ep, "q");
	cout << Result << endl;
	pc = mxGetPr(Result);

	cout << "PC:" << pc << endl;
	double *pc1 = pc;
	//fgetc(stdin);

	// clean operation(don't forget!!!)
	mxDestroyArray(Result);
	engEvalString(ep, "close;");

	// close engine
	engClose(ep);
	return *pc1;*/
}
//***********************************************************************Normal end*******************************************************************


// Determine if any sublabel is invalidated during the process.
// The value of the invalid sublabel is set to -bigM
int number[NN + 1];
int sublabel_shixiao(double* a1, double* b1)
{
	//modify the new_label
	double LAT1[NN + 1];
	LAT1[0] = 0;
	for (int n = 1; n <= NN; n++)
	{
		LAT1[n] = new_label[n + M];
	}
	for (int n = 0; n <= NN; n++)
	{
		number[n] = 0;
	}
	int temp2 = 0;
	for (int n = 1; n <= NN; n++)
	{
		int temp1 = 0;
		for (int nn = 1; nn <= NN; nn++)
		{
			if (b1[n] - LAT1[n] <= a1[nn] - LAT1[nn]
				&& LAT1[nn] >= (-bigM / 2) && LAT1[n] != 0
				&& LAT1[nn] != 0 && LAT1[n] != T0 && LAT1[nn] != T0) {
				temp1 = 1;
			}
		}
		if (temp1 == 1)
		{
			number[n] = 1;
			new_label[M + n] = -bigM;
			temp2 = 1;
		}
	}
	return temp2;
}
#include<iomanip>
#include"iostream"
#include"iostream"
#include "fstream"
#include<sstream>
void printToCsv(double index, string str, double value, double time) {
	string file_train_save = "smallScale_withoutseq_norm.csv";
	ofstream myfile(file_train_save, ios::out | ios::app);
	myfile << index << ',' << str << ',' << value << ',' << time;

	for (int i = 1; i <= I; i++) {
		for (int k = 1; k <= K; k++) {
			myfile << processtime[i][k] << ',';
		}
		myfile << endl;
	}
	for (int i = 1; i < 50; i++) {
		myfile << seq[i] << ",";
	}
	myfile << endl;
	for (int i = 1; i < 50; i++) {
		myfile << seqsize[i] << ",";
	}
	myfile << endl;

	myfile.close();

}

int main(int argc, char* argv[])
{


	int countRead = 1;
	for (int i = 1; i <= I; i++) {
		for (int k = 1; k <= K; k++) {
			processtime[i][k] = atof(argv[countRead]);
			cout << countRead << " : " << atof(argv[countRead]) << endl;
			countRead++;
		}
	}
	for (int i = 1; i <= I; i++) {
		miu[i] = atof(argv[countRead]);
		cout << "miu " << miu[i] << endl;
		countRead++;
	}
	for (int i = 1; i <= I; i++) {
		sigma[i] = atof(argv[countRead]);
		cout << "sigma " << sigma[i] << endl;
		countRead++;
	}

	for (int n = 0; n <= NN; n++) {
		a1[n] = miu[n] - 3.0 * sigma[n];
		b1[n] = miu[n] + 3.0 * sigma[n];
		an[n] = a1[n]; bn[n] = b1[n];
	}

	double instanceIndex = atof(argv[countRead]);

	vector_chushihua();
	chushihuaf();
	chushihuasettime();

	cout << "Index of the cases " << instanceIndex << endl;
	//the random cases
	{
		cout << "indexOfTheRandomCase " << instanceIndex << " Ran" << endl;

		chushihuaf();

		chushihuasettime();

		clock_t tempstart, tempend;
		tempstart = clock();

		stateergodic();
		cout << maxcaseused << endl;
		double r1 = min_label_real_time_N(a1, b1);
		//label_details();
		tempend = clock();
		double time4 = (double)(tempend - tempstart) / CLOCKS_PER_SEC;
		cout << "cost: " << time4 << " sec" << endl;
		printToCsv(instanceIndex, "Random", r1, time4);
		maxcaseused = 0;
		for (int a = 0; a < 50; a++) {
			seq[a] = 0;
			seqsize[a] = 0;
		}
		memset(LAT, 0, sizeof(LAT));
		memset(fu_EI, 0, sizeof(fu_EI));
	}
	//	system("pause");

	//  Comparision: the deterministic cases
	{
		cout << "indexOfNonRandomCase " << instanceIndex << " Deterministic" << endl;
		chushihuaf();
		chushihuasettime();
		for (int n = 0; n <= NN; n++) {
			a1[n] = miu[n];
			b1[n] = a1[n] + 0.1;
			an[n] = a1[n]; bn[n] = b1[n];
		}
		clock_t tempstart, tempend;
		tempstart = clock();

		stateergodic();
		cout << maxcaseused << endl;
		double r2 = min_label_real_time_U(a1, b1);
		tempend = clock();
		double time4 = (double)(tempend - tempstart) / CLOCKS_PER_SEC;
		cout << "cost: " << time4 << " sec" << endl;
		printToCsv(instanceIndex, "Quedin", r2, time4);
		maxcaseused = 0;
		for (int a = 0; a < 50; a++) {
			seq[a] = 0;
			seqsize[a] = 0;
		}

		memset(LAT, 0, sizeof(LAT));
		memset(fu_EI, 0, sizeof(fu_EI));
	}

	system("pause");
	return 0;
}