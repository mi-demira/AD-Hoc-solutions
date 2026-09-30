using namespace std;
#include <iostream>

//samo maks 2 hoda sa vuzmojni - dori v zadachata da e dadeno maks 4
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		//starting coordinates
		char y1; int x1;
		cin >> y1 >> x1;

		//where it should go
		char y2; int x2;
		cin >> y2 >> x2;

		//transforming the char into int (+1 so it can start from )
		int iy2 = y2 - 'A' + 1;
		int iy1 = y1 - 'A' + 1;


		//ako ne sa na edin cvqt - ne e vuzmojno chetnite sa na cherno, necg=hetnite sborove na bqlo, ako ne sa ednakva chetnost, impossible
		int startCoord = x1 + iy1;
		int endCoord = x2 + iy2;

		if (startCoord % 2 != endCoord%2)
		{
			cout << "Impossible!" << endl;
			continue;
		}

		//ako i dvata koordinata sa ednakvi
		if (x1 == x2 && iy1 == iy2)
		{
			cout << "0 " << y1 << x1 << endl;
			continue;
		}

		//namira se na sushtiqt diagonal (1 move) - ako absolutnata razlika mejdu kolonite e ravna na razlikata na redovete
		int difCol = abs(iy1 - iy2);
		int difRow = abs(x1 - x2);
		if (difCol == difRow)
		{
			cout << "1 " << y1 << x1 << " " << y2 << x2 << endl;
			continue;
		}

		//2 move - presichane na diagonalite - tursim presechnata tochka
		bool found = false;

		//iterirane prez vsichki kvadratcheta na duskata (64)
		for (int ix = 1; ix <= 8; ix++) //rows
		{
			for (int iy = 1; iy <= 8;iy++)//columns
			{
				//proverka - dali tazi tochka se namira v diagonala
				if (abs(x1 - ix) == abs(iy1 - iy) && abs(x2 - ix) == abs(iy2 - iy))
				{
					//prevrushtane na coordinat obratno v bukva
					char col = iy + 'A' - 1;

					cout << "2 " << y1 << x1 << " " << col << ix << " " << y2 << x2 << endl;

					found = true;
					break;
				}

			}
			if (found) 
				break;
		}
		


	}
}

