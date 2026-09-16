using namespace std;
#include <iostream>
#include <string>


int main()
{
	//kolko ruce ima v igrata
	int N;
	cin >> N;

	//boqta koqto e koz
	char dominant;
	cin >> dominant;

	int points = 0;

	//input cards
	for (int i = 1; i <= N * 4; i++)
	{
		string card;
		cin >> card;

		if (card[1] == dominant)
		{
			if (card[0] == 'J')
			{
				points += 20;
			}
			else if (card[0] == '9')
			{
				points += 14;
			}
		}
		else
		{

			if (card[0] == 'J')
			{
				points += 2;
			}
			
		}
		
		switch (card[0])
		{
		case 'A':
			points += 11;
			break;
		case 'K':
			points += 4;
			break;
		case 'Q':
			points += 3;
			break;
		case 'T':
			points += 10;
			break;
		}
	}

	cout << points << endl;
}
