using namespace std;
#include <iostream>
#include <algorithm>


int main()
{
	int A, B, C, X, Y;

	while (true)
	{
		//1st 3 princess/ other 2 for prince
		cin >> A >> B >> C >> X >> Y;

		//end of test cases
		if (A == 0 && B == 0 && C == 0 && X == 0 && Y == 0)
			break;

		//finding the power of hers and his cards
		int princessHighest = max({ A, B, C });
		int princessLowest = min({A, B, C });
		int princessMid = (A + B + C) - princessHighest - princessLowest;

		int prMin = min({ X, Y });
		int prMax = max({ X, Y });
		//priemame che za sega nqma reshenie
		int result = -1;

		//automatic win, both cards are stronger than hers
		if (prMin > princessHighest)
		{
			result = 1; //lowest possible card
		}
		//ako min e po golqma ot mid i low na princesata, nqma znacgenie next card, samo da e higher that her mid za da ne zagubi
		//ako maks princ > that princess highest, trqbva kartata mu da e po golqma ot neiniqt mid + low
		else if (prMin > princessMid || prMax > princessHighest)
		{
			result = princessMid + 1;
		}
		else //he cant win
		{
			result = -1;
		}

		//check that the card is not in anybodys hands, if it is, add one more
		if (result != -1)
		{
			while (result == A || result== B || result == C || result== X || result == Y)
			{
				result++; //dokato ne se nameri avalable karta, tursene
			}

			//nqma reshenie ako kartata ne e v testeto
			if (result > 52)
			{
				result=- 1;
			}
		}
		
		cout << result << endl;



	}
}