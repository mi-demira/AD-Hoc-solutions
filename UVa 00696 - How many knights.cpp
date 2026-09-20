using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	int M, N;

	//za pechata
	vector<string> outputs;
	while (cin >> M >> N)
	{
		if (M == 0 && N == 0)
		{
			break;
		}

		int result = 0;
		//if there i one row/one column - togava se slagat kone navsqkude na drugiqt dimention - ne mogat da se atakuvat
		if (min(N, M) == 1)
		{
			result = max(N, M);
		}
		//ako ediniqt dimention e 2
		else if (min(N, M) == 2)
		{
			//kolko konq se pobirat ako se reduvat 2*2 pulni i 2*2 prazni - nqma shans da se zasekat, a kogato sa blok 2*2 nqma kak da se vzemat
			result = (max(M, N) / 4) * 4;
			//ako ostava 1 kolona  + dobavqme kone
			if (max(M, N) % 4 == 1)
			{
				result += 2;
			}
			//2 koloni i poveche ostavat - 4 konq
			else if (max(M, N) % 4 >= 2)
			{
				result += 4;
			}

		}
		//ako duskata e po-golemi dimentions - konete zaemat okolo polovinata duska - slagame gi na edni i sushti cvetove za da ne se vzemat
		else
		{
			result = (M * N+1) / 2;
		}
		
		//zapazvame za konkretniqt test case
		string t = to_string(result) + " knights may be placed on a " +	to_string(M) + " row " + to_string(N) + " column board.";
		outputs.push_back(t);
		
	}

	for (string s : outputs)
	{
		cout << s << endl;

	}


}

