/**
* \brief OOP1 Experiment 1
* \author Atila Pehlivan
*/
#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;
bool TakeUserInput(int &data_size, int &min_number, int &max_number);
int main();
int *CreateDataSet(int dataSize, int min_number, int max_number);
double CalculateMean(int *data_array, int data_size);
double CalculateVariance(int *data_array, int data_size, double mean);
double CalculateStandartDeviation(int *data_array, int data_size, double mean);
double *CalculateZScore(int *data_array, int data_size, double mean, double std_deviation);
void PrintMessage(const string &message);
void PrintDataArray(int *data_array, int data_size);
void PrintMean(double mean);
void PrintVariance(double variance);
void PrintStandartDeviation(double std_deviation);
void PrintZScoreArray(double *zscore, int data_size);
double *CalculateTScore(int *data_array, int data_size, double mean, double std_deviation);
void PrintTScoreArray(double *tscore, int data_size);
int* FindEvenNumbers(int* data_array, int data_size);
void PrintNumbersForMarkedIndexes(int* data_array, int* marked_indexes, int
	data_size);
int main()
{
	srand(time(NULL));
	int dataSize, minNumber, maxNumber;
	if (!TakeUserInput(dataSize, minNumber, maxNumber))
	{
		PrintMessage("TERMINATED BY USER!");
	}
	else
	{
		int *DataArray = CreateDataSet(dataSize, minNumber, maxNumber);
		PrintDataArray(DataArray, dataSize);
		double mean = CalculateMean(DataArray, dataSize);
		PrintMean(mean);
		double variance = CalculateVariance(DataArray, dataSize, mean);
		PrintVariance(variance);
		double stdDeviation = CalculateStandartDeviation(DataArray, dataSize, mean);
		PrintStandartDeviation(stdDeviation);
		double *zscore = CalculateZScore(DataArray, dataSize, mean, stdDeviation);
		PrintZScoreArray(zscore, dataSize);
		double *tscore = CalculateTScore(DataArray, dataSize, mean, stdDeviation);
		PrintTScoreArray(tscore, dataSize);
		int *marked_index = FindEvenNumbers(DataArray, dataSize);
		PrintNumbersForMarkedIndexes(DataArray, marked_index, dataSize);
	}
	system("pause");
}
/**
* \brief Create Random Number
* \param integer dataSize, min_number, max_number
* \return integer pointer array
*/
int *CreateDataSet(int dataSize, int min_number, int max_number)
{
	int *Array = new int[dataSize];

	for (int i = 0; i < dataSize; i++)
	{
		int randomNumber = min_number + rand() % (max_number - min_number + 1);
		Array[i] = randomNumber;
	}
	return Array;
}

/**
* \brief Calculate Mean
* \param integer pointer data_array and integer data_size
* \return double mean
*/
double CalculateMean(int *data_array, int data_size)
{
	int sum = 0;
	double mean;
	for (int i = 0; i < data_size; i++)
	{
		sum = sum + *(data_array + i);
	}
	mean = (double)sum / data_size;
	return mean;
}
/**
* \brief Calculate Variance
* \param integer pointer data_array , integer data_size , double mean
* \return double variance
*/
double CalculateVariance(int *data_array, int data_size, double mean)
{
	double sum = 0;
	double variance;

	for (int i = 0; i < data_size; i++)
	{
		sum = sum + pow((*(data_array + i) - mean), 2);
	}
	variance = sum / data_size;

	return variance;
}

/**
* \brief Calculate Standart Deviation
* \param integer pointer data_array , integer data_size , double mean
* \return double deviation
*/
double CalculateStandartDeviation(int *data_array, int data_size, double mean)
{
	double sum = 0;
	double variance;
	double deviation;

	for (int i = 0; i < data_size; i++)
	{
		sum = sum + pow((*(data_array + i) - mean), 2);
	}
	variance = sum / data_size;

	deviation = sqrt(variance);

	return deviation;
}

/**
* \brief Calculate Z Score
* \param integer pointer data_array , integer data_size , double mean ,double std_deviation
* \return double pointer array
*/
double *CalculateZScore(int *data_array, int data_size, double mean, double std_deviation)
{
	double *zScore = new double[data_size];

	for (int i = 0; i < data_size; i++)
	{
		zScore[i] = (data_array[i] - mean) / std_deviation;
	}
	return zScore;
}

/**
* \brief Calculate T Score
* \param integer pointer data_array, integer data_size , double mean , double std_deviation
* \return double pointer array
*/
double *CalculateTScore(int *data_array, int data_size, double mean, double std_deviation)
{
	double *tScore = new double[data_size];

	for (int i = 0; i < data_size; i++)
	{
		tScore[i] = (10 * (data_array[i] - mean) / std_deviation) + 50;
	}
	return tScore;
}
/**
* \brief Take information from user
* \param ireference integer data_size, min_number, max_number
* \return double 
*/
bool TakeUserInput(int &data_size, int &min_number, int &max_number)
{
	cout << "+" << setfill('-') << setw(13) << "+" << endl;
	cout << "|"" USER INPUT " << "|" << endl;
	cout << "+" << setfill('-') << setw(13) << "+" << endl;
	cout << "  Enter the 'Data Size' (0 for terminate program) : ";
	cin >> data_size;
	if (data_size > 0)
	{
		cout << "  Enter the 'Minimum Number' : ";
		cin >> min_number;
		cout << "  Enter the 'Maximum Number' : ";
		cin >> max_number;
		return true;
	}
	else
		return false;
}
/**
* \brief Print Message on console
* \param const string reference
*/
void PrintMessage(const string &message)
{
	cout << "+" << setfill('-') << setw(22) << "+" << endl;
	cout << "| " + message + " |" << endl;
	cout << "+" << setfill('-') << setw(22) << "+" << endl;
}
/**
* \brief Print Data on console
* \param integer pointer data_array, integer data_size
*/
void PrintDataArray(int *data_array, int data_size)
{
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	cout << "|" << setw(12) << setfill(' ') << "DATA ARRAY" << setw(8) << setfill(' ') << "|" << endl;
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	for (int i = 0; i < data_size; i++)
	{
		cout << "|" << setw(19) << setfill(' ') << *(data_array + i) << "|" << endl;
	}
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
}
void PrintMean(double mean)
{
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	cout << "|" << setw(10) << setfill(' ') << "MEAN" << setw(10) << setfill(' ') << "|" << endl;
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	cout << "|" << setw(19) << setfill(' ') << mean << "|" << endl;
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
}
void PrintVariance(double variance)
{
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	cout << "|" << setw(10) << setfill(' ') << "VARIANCE" << setw(10) << setfill(' ') << "|" << endl;
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	cout << "|" << setw(19) << setfill(' ') << variance << "|" << endl;
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
}
void PrintStandartDeviation(double std_deviation)
{
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	cout << "|" << setw(17) << setfill(' ') << "STANDART DEVIATION" << setw(2) << setfill(' ') << "|" << endl;
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	cout << "|" << setw(19) << setfill(' ') << std_deviation << "|" << endl;
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
}
void PrintZScoreArray(double *zscore, int data_size)
{
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	cout << "|" << setw(12) << setfill(' ') << "Z-SCORE" << setw(8) << setfill(' ') << "|" << endl;
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	for (int i = 0; i < data_size; i++)
	{
		cout << "|" << setw(19) << setfill(' ') << *(zscore + i) << "|" << endl;
	}
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
}

void PrintTScoreArray(double *tscore, int data_size)
{
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	cout << "|" << setw(13) << setfill(' ') << "T-SCORE" << setw(7) << setfill(' ') << "|" << endl;
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	for (int i = 0; i < data_size; i++)
	{
		cout << "|" << setw(19) << setfill(' ') << *(tscore + i) << "|" << endl;
	}
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
}
/**
* \brief this function find even numbers from given data_array 
* \param integer pointer data_array , integer data_size
* \return integer pointer array
*/
int * FindEvenNumbers(int * data_array, int data_size)
{

	int *returnArray = new int[data_size];
	for (int i = 0; i < data_size; i++)
	{
		if(*(data_array+i)%2 == 0)
		{
			*(returnArray + i) = 1;
		}
		else
		{
			*(returnArray + i) = 0;
		}
	}
	return returnArray;
}
/**
* \brief print marked number on console
* \param integer pointer data_array , integer data_size , integer pointer marked_indexes
* \return nothing
*/
void PrintNumbersForMarkedIndexes(int * data_array, int * marked_indexes, int data_size)
{
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	cout << "|" << setw(10) << setfill(' ') << "MARKED-SCORE" << setw(10) << setfill(' ') << "|" << endl;
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
	for (int i = 0; i < data_size; i++)
	{
		if(*(marked_indexes+i)==1)
		{
			cout << "|" << setw(19) << setfill(' ') << *(data_array+i) << "|" << endl;
		}
	}
	cout << "+" << setfill('-') << setw(20) << "+" << endl;
}
