using namespace std;
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int T;
    cin >> T;
    int testC = 0;

    while (T--)
    {
        //input cards
        vector <string> cards(52);

        for (int i = 0; i < 52;i++)
        {
            //inputing the cards
            cin >> cards[i];
        }

        int Y = 0;
        //mahame 25 karti otgore ot testeto - top card is the 27th
        int topCardIndex = 26;


        for (int i = 0; i < 3;i++)
        {
            int X;
            //vzimame kartata nai-otgore 
            string topCard = cards[topCardIndex];

            //value of card -vzimame purviqt simvol
            char value = topCard[0];

            if (value >= '2' && value <= '2')
            {
                X = (int)value;
            }
            else
            {
                X = 10;
            }

            Y += X;

            //mahame segashnata karta i oshte 10 - X karti ot testeto
            topCardIndex -= 1 + (10 - X);
        
        }

        string a;
        //namirane na Y card in teste

        //Y e v ostatuka na masa karti
        if (Y <= topCardIndex + 1)
        {
            a = cards[Y - 1];
        }
        else //izvun kartite koito bqha na masata
        {
            //tursim na koi index e (karti na masata + kolko indeksa preskachame) / -1 bcz 0 based index
            int index = 27 + (Y - (topCardIndex + 1) - 1);
            a = cards[index];
        }

        cout << "Case " << ++testC << ": " << a << endl;

    }
}

