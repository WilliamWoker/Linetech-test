//============================================================================
// Name        : Task1.cpp
// Author      : WilliamWoker
// Version     :
// Copyright   : 
// Description : A program for comparing the arithmetic average and the median
//				 value from a set of numbers from an external file. The
//				 program is optimized to minimum memory consumption and
//				 maximum performance. Based on the proposed data file, I
//				 assumed that the program should work with an array of numbers
//				 from 0 to 255 in the amount of about 10,000 values.
//============================================================================

#include <iostream>
#include <future>
#include <vector>
#include <algorithm>
#include <fstream>

double calculateArithmeticAverage(const std::vector<unsigned char> &dataSet) //using reference for memory economy and return double for greater accuracy
{
	//protection against an empty vector
	if (dataSet.empty())
		return 0.0;

	//arithmetic average calculating algorithm
	double sum = 0; //using double for a more precise answer
	for (unsigned short i = 0; i < dataSet.size(); i++) //using unsigned short because of 10000 records in data.txt
		sum += dataSet.at(i);
	return sum / dataSet.size();
}

//	for (unsigned long i = 0; i < dataSet.size(); i++)
//			std::cout << dataSet.at(i) << " ";
//	std::cout << std::endl;

double findMedianValue(std::vector<unsigned char> dataSet) //it is possible to duplicate vector, but I use a reference, since sorting the vector of the original one will not affect its further use, but optimizes the use of memory and execution time.
{
	//protection against an empty vector
	if (dataSet.empty())
		return 0.0;

	//arithmetic average calculating algorithm
	sort(dataSet.begin(), dataSet.end());
	if (dataSet.size() % 2 != 0)
		return (double) dataSet.at(dataSet.size() / 2);
	return (double) (dataSet.at((dataSet.size() - 1) / 2)
	        + dataSet.at(dataSet.size() / 2)) / 2.0;
}

int main()
{
	std::vector<unsigned char> dataSet; //vector for saving data for processing. it is possible to use array for greater efficiency, but I chose a vector in case of small file changes.

	//writing data from the file to a vector
	std::string line;
	std::ifstream fileStream("data.txt");
	if (fileStream.is_open())
	{
		while (getline(fileStream, line)) //line-by-line reading quickly separates numbers
		{
			dataSet.push_back(std::stoi(line)); //no stouc function, so i used stoi to convert string to int and than to unsigned char
		}
	}
	fileStream.close();

//	some code to show functions results

//	for (unsigned long i = 0; i < dataSet.size(); i++)
//		std::cout << dataSet.at(i) << " ";
//	std::cout << std::endl;

//	std::cout << calculateArithmeticAverage(dataSet) << std::endl;
//	std::cout << findMedianValue(dataSet) << std::endl;

	//async calling functions
	std::future<double> futureArithmeticAverage = std::async(std::launch::async,
	        calculateArithmeticAverage, dataSet);
	std::future<double> futureMedianValue = std::async(std::launch::async,
	        findMedianValue, dataSet);

	//place to do something

	//getting async results
	double arithmeticAverageResult = futureArithmeticAverage.get();
	double medianValueResult = futureMedianValue.get();

	//comparing results and showing main result
	if (arithmeticAverageResult > medianValueResult)
		std::cout << "arithmetic average is bigger" << std::endl;
	else if (arithmeticAverageResult < medianValueResult)
		std::cout << "median value is bigger" << std::endl;
	else
		std::cout << "arithmetic average and median value are equal"
		        << std::endl;

	return 0;
}
