using namespace std;
#include <iostream>
#include <cmath>

int main()
{
    int king, queen, queenTo;

    //eof
    while (cin >> king >> queen >> queenTo)
    {
        //na edna i sushta kletka sa
        if (king == queen)
        {
            cout << "Illegal state" << endl;
            continue;
        }

        //prevrushtame poziicite v redove i koloni 
        int kRow = king / 8; //ot 0 - 7
        int kColumn = king % 8; //ot 1 do 8
        int qRow = queen / 8;
        int qColumn = queen % 8;
        int qtRow = queenTo / 8;
        int qtColumn = queenTo % 8;

        //kralicata trqbva da se dviji i ne trqbva da nastupi kralq
        if (!((qtRow == qRow || qtColumn == qColumn) && queenTo != queen))
        {
            cout << "Illegal move" << endl;
            continue;
        }
        
        //ako se dviji po redovete i carq e tam
        if (qRow == qtRow && kRow == qRow)
        {
            //proverka ot koq do koq kolona e dvijenieto i posokata
            int startCol = min(qColumn, qtColumn);
            int endCol = max(qColumn, qtColumn);

            //proverka dali carq e tam
            if (kColumn > startCol && kColumn < endCol)
            {
                cout << "Illegal move" << endl;
                continue;
            }
        }

        //dvijenie po kolonite
        if (qColumn == qtColumn && kColumn == qColumn)
        {
            //proverka ot kude do kude
            int startRow=min(qRow, qtRow);
            int endRow = max(qRow, qtRow);

            if (kRow > startRow && kRow < endRow)
            {
                cout << "Illegal move" << endl;
                continue;
            }
        }

        //da ne stupva caricata kudeto carq moje da q vzeme - manhatunsko razstoqnie
        //kolko reda i kolko koloni gi razdelqt, ako e ravno na 1, znachi che dostijima ot carq nezavisimo v koq posoka
        if (king == queenTo || abs(kRow - qtRow) + abs(kColumn - qtColumn) == 1)
        {
            cout << "Move not allowed"<<endl;
            continue;
        }

        //kogato carq e v ugul 
        if ((king == 0 && queenTo == 9) || (king == 7 && queenTo == 14) || (king == 56 && queenTo == 49) || (king == 64 && queenTo == 54))
        {
            cout << "Stop! " << endl;
            continue;
        }

        //only prints when all the tests dont get to - "continue"
        cout << "Continue\n";
    }
}

