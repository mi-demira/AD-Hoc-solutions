using namespace std;
#include <iostream>
#include <algorithm>

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		char piece;
		int m, n;
		cin >> piece;
		cin >> m >> n;

		int num = 0;
		switch (piece)
		{
			//top - bazira se na po-malkoto izmerenie na duskata (vsqko ima nujda ot razlichen red i kolona)
		case 'r':
			num = min(n, m);
			break;
			//nai-efektivno e postavqne na vsichki kone na poleta ot edin cvqt - otskachat na protivopolojen cvqt
			//taka zaemat okolo polovinata pole - zakrugleno nagore ako broq poleta e necheten
		case 'k':
			num = (m*n+1)/2;
			break;
			//kralq se razpolaga prez edno pole + edna kolona za da ne se dokosvat - 2 na 2 reach
		case 'Q':
			num = ((m + 1) / 2) + ((n + 1) / 2);
			break;
			//pri konkretnite granici ili ako e kvadratna duskata (2 carici ne mogat da spodelqt edin i sushti red i kolona)
			//ako limita beshe 2*2 - 1 carica \, ako limita beshe 3*3 - 2 kralici (base cases)
		case 'K':
			num = min(n, m);
			break;

		}

		cout << num << endl;
	}
}

