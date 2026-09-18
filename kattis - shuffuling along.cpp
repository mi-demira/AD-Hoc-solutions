using namespace std;
#include <iostream>

int main()
{
	//number cards
	int n;
	cin >> n;
	string way;
	cin >> way;

	//base case - nezavisimo in ili out
	if (n <= 2)
	{
		cout << 1 << endl;
		return 0;
	}

	//sledim samo kartata koqto e v nachaloto
	int startCard = 1;
	int shuffles = 0;

	
	if (way == "in")
	{
		//vurtim dokato kartata ne pristigne pak na sushtoto mqsto
		do {
			//ako e v ednata polovina na testeto
			if (startCard < n/2) 
			{
				//premestva se v drugata polovina s nechetni pozicii 
				startCard = 2*startCard + 1;
			}
			else
			{
				//ako e vuv vtora polovina na teste, otivat na chetni pozicii
				startCard= 2*(startCard-n/2);
			}

			shuffles++;
		} while (startCard != 1);

	}
	else if (way == "out")
	{
		
		do {
			//ako e v lqvata polovina -- otivat na chetni pozicii
			if (startCard < (n + 1) / 2) 
			{
				startCard = 2 * startCard;
			}
			else 
			{
				//izvajdame sredata za da vidim na koq poziciq trqbva da se pada - otivat na chetni pozicii
				startCard = 2 * (startCard - (n + 1) / 2) + 1;
			}
			shuffles++;
		} while (startCard != 1);

	}
	cout << shuffles << endl;
}

