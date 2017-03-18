#include <iostream>
#include <vector>
using namespace std;


vector<int> findPrimeNum();
void testTheConjecture(vector<int>& primeSet);
int* createNumArray();


int main()
{
	vector<int> primeSet = findPrimeNum();
	testTheConjecture(primeSet);

	return 0;
}

vector<int> findPrimeNum()
{

	int* numArray = createNumArray();

	int markArray[100] = {0};
	markArray[0] = 1;

    int countPrime = 0;
    vector<int> primeSet;


	for (int i = 0; i < 100; i++)
	{
		if (markArray[i] == 0)
		{
			for (int j = i+ numArray[i]; j <= 100;)
			{
				markArray[j] = 1;
				j = j + numArray[i];
			}
			primeSet.push_back(numArray[i]);
		}
	}

	cout << "Primes:" << "\n" << "\n";

	int temp = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (markArray[temp] == 1)
				cout << "  .";
			else if (numArray[temp] <= 9)
			cout << "  " << numArray[temp];
			else cout << " " << numArray[temp];
			temp++;
		}
		cout << "\n";
	}

	return primeSet;
}

void testTheConjecture(vector<int>& primeSet)
{
	cout << "\n" << "Test of Goldbach's Conjecture:" << "\n" << "\n";

	int headMark = 0;

	for (int i = 4; i <= 100; i = i + 2)
	{
		std::cout.width(3);
		std::cout << std::right << i << ":";
		headMark = 1;
		for (int j = 0; j < primeSet.size(); j++)
		{
			if (primeSet[j] > i/2) break;
			for (int k = 0; k < primeSet.size(); k++)
			{
				if (primeSet[j] + primeSet[k] == i)
				{
					if (headMark == 1)
					{
						std::cout.width(3);
						std::cout << std::right << primeSet[j];
						std::cout.width(3);
						std::cout << std::right << primeSet[k] << "\n";
						headMark = 0;
					}
					else
					{
						std::cout.width(7);
						std::cout << std::right << primeSet[j];
						std::cout.width(3);
						std::cout << std::right << primeSet[k] << "\n";
					}
				}
			}
		}
		if (i <=99) std::cout << "\n";
	}
}

int* createNumArray()
{
	int num = 1;
	int* numArray = new int [100];

	for (int i = 0; i < 100; i++)
	{
			numArray[i] = num;
			num++;
	}

	return numArray;
}
