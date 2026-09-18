using namespace std;
#include <iostream>
#include <string>
#include <set>
#include <map>

int main()
{
    //vkarvame kartite
    string inputCards;
    cin >> inputCards;

    //chrez set poddurjame samo unikalni elementi, zapisvame vsqka novovidqna karta
    set <string> unqCards;

    //broim kolko karti ot vsqka boq sme vidqli
    int p = 0, k = 0, h = 0, t = 0;

    //cikula e prez 3 zashtoto vsqka karta e 3 simvola
    for (char i = 0; i < inputCards.size(); i +=3)
    {
        //3te simvola na kartata v momenta
        string card = inputCards.substr(i, 3);

        //ako kartata se dublira, direktno pechat i prikluchvane na programata
        if (unqCards.count(card))
        {
            cout << "GRESKA" << endl;
            return 0;
        }
        unqCards.insert(card);

       
    }

    //proverka kolko karti ima ot vsqka boq
    for (string card : unqCards)
    {
        //vzimame simvola koito e boqta
        char c = card[0];

        if (c == 'P')
        {
            p++;
        }
        else if (c == 'K')
        {
            k++;
        }
        else if (c == 'H')
        {
            h++;
        }
        else if (c == 'T')
        {
            t++;
        }
    }

    //pechat
    cout << (13 - p) << " " << (13 - k) << " " << (13 - h) << " " << (13 - t) << endl;

}
