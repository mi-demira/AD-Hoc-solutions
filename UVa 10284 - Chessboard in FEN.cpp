using namespace std;
#include <iostream>
#include <string>
#include <vector>

int solve(string fen)
{
	//inicializirame duskata prazna
	char board[8][8];
	bool attacked[8][8];

	for (int i = 0; i < 8;i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = '.';
			attacked[i][j] = false;

		}
	}

	//za sledene
	int cur_row = 0, cur_col = 0;

	//minavame prez stringa
	for (char c:fen)
	{
		//razgranichavane na redovete
		if (c == '/')
		{
			cur_row++;
			cur_col = 0;
		}
		//ako e chislo
		else if (isdigit(c))
		{
			//izvajdame ascii codes (ascii code 5 - ascii code 0)
			cur_col += (c - '0');
		}
		//inache postavqma figurata
		else
		{
			board[cur_row][cur_col] = c;
			cur_col++;
		}
	}

	//kolko mogat da se vzemat
	for (int row = 0;row < 8;row++)
	{
		for (int col = 0; col < 8; col++)
		{
			//ako e tochka, preskachame kum sledvashta iteraciq
			if (board[row][col] == '.') 
				continue;
			char piece = board[row][col];

			switch (piece)
			{
				//samo peshkite imat razlichni posoki na ataka bazirano na cvqt
			case 'P':
				//proverka dali e v granici, i ako e - priemame che moje da vzima v diagonal (gorni)
				//lqv diagonal
				if ((row - 1 >= 0 && col - 1 >= 0))
				{
					attacked[row - 1][col - 1] = true;
				}
				//desen diagonal
				if (row - 1 >= 0 && col + 1 < 8)
				{
					attacked[row - 1][col + 1] = true;
				}
				break;
			case 'p':
				//dolen lqv
				if (row + 1 < 8 && col - 1 >= 0)
					attacked[row + 1][col - 1] = true;
				//dolen desen
				if (row + 1 < 8 && col + 1 < 8)
					attacked[row + 1][col + 1] = true;
				
				break;
			case 'N':case 'n':
			{
				//direction vectors - kakvi sa vuzmojnite hodove - za konq sa 8
				vector <int> directionRows = { -1,1,-2,2,-2,2 ,-1,1 };
				vector <int> directionCols = { -2,-2,-1,-1,1,1,2,2 };

				for (int i = 0; i < 8;i++)
				{
					//current row + where it will go
					int newRow = row + directionRows[i];
					int newCol = col + directionCols[i];

					//proverka 
					if (newRow < 8 && newRow >= 0 && newCol < 8 && newCol >= 0)
					{
						attacked[newRow][newCol] = true;
					}

				}

				break;
			}
			case 'B': case 'b': {
				//oficer - 4 diagonala
				vector <int> directionRows = { 1, 1,-1,-1};
				vector <int> directionCols = { -1,1,-1,1 };

				for (int i = 0;i < 4; i++)
				{
					//current row + where it will go
					int newRow = row + directionRows[i];
					int newCol = col + directionCols[i];

					//vurvi dokato ne uceli druga figura
					while (newRow < 8 && newRow >= 0 && newCol < 8 && newCol >= 0)
					{
						attacked[newRow][newCol] = true;

						if (board[newRow][newCol] != '.')
						{
							break;
						}
						//ako ne se blusnem, produljavame
						newRow += directionRows[i];
						newCol += directionCols[i];
					}
				}
				break;
				
			}
			case 'r': case 'R':
			{
				//top - 4 vuzmojni posoki
				vector <int> directionRows = { -1, 1,0,0 };
				vector <int> directionCols = { 0,0,-1,1 };

				for (int i = 0;i < 4; i++)
				{
					//current row + where it will go
					int newRow = row + directionRows[i];
					int newCol = col + directionCols[i];

					//vurvi dokato ne uceli druga figura
					while (newRow < 8 && newRow >= 0 && newCol < 8 && newCol >= 0)
					{
						attacked[newRow][newCol] = true;

						if (board[newRow][newCol] != '.')
						{
							break;
						}
						//ako ne se blusnem, produljavame
						newRow += directionRows[i];
						newCol += directionCols[i];
					}
				}
				break;

			}
			case 'Q': case 'q':
			{
				vector<int> directionRows = { -1, 1,  0, 0,  -1, -1, 1, 1 };
				vector<int> directionCols = { 0, 0, -1, 1,  -1,  1,-1, 1 };

				for (int i = 0;i < 8; i++)
				{
					//current row + where it will go
					int newRow = row + directionRows[i];
					int newCol = col + directionCols[i];

					//vurvi dokato ne uceli druga figura
					while (newRow < 8 && newRow >= 0 && newCol < 8 && newCol >= 0)
					{
						attacked[newRow][newCol] = true;

						if (board[newRow][newCol] != '.')
						{
							break;
						}
						//ako ne se blusnem, produljavame
						newRow += directionRows[i];
						newCol += directionCols[i];
					}
				}
				break;
				
			}
				
			case 'K': case 'k':
			{
				vector<int> directionRows = { -1, 1,  0, 0,  -1, -1, 1, 1 };
				vector<int> directionCols = { 0, 0, -1, 1,  -1,  1,-1, 1 };

				for (int i = 0; i < 8;i++)
				{
					int newRow = row + directionRows[i];
					int newCol = col + directionCols[i];

					if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
					{
						attacked[newRow][newCol] = true;
					}
				}

				break;
			}
				
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 8;i++)
	{
		for (int j = 0; j < 8;j++)
		{
			if (board[i][j] == '.' && attacked[i][j] == false)
			{
				result++;
			}

		}
	}
	return result;
}

int main()
{
	string FEN;
	while (cin >> FEN)
	{
		int r=solve(FEN);
		cout << r << endl;

	}

}


