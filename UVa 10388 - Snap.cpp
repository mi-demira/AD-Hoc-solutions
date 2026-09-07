using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        //razdavane na kartite
        string s1, s2;
        cin >> s1 >> s2;

        //purvi dadeni karti sa nai-otzad
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        //vkarvame gi vuv vektori
        vector <char> janeD(s1.begin(), s1.end());
        vector <char> johnD(s2.begin(), s2.end());

        //vektori v koito shte vkarvame vzetite karti (s lice nagore)
        vector <char> janeUp, johnUp;

        //broqch stupki
        int steps = 0;

        while (steps<1000)
        {
            //preobrushtane na karti ako testeto svurshi,ako 1 dvete sa svurshili, prikluchva igra
            if (janeD.empty())
            {
                if (janeUp.empty())
                    break;
                reverse(janeUp.begin(), janeUp.end());
                janeD = janeUp;
                janeUp.clear();
            }
            if (johnD.empty())
            {
                if (johnUp.empty()) 
                    break;

                reverse(johnUp.begin(), johnUp.end());
                johnD = johnUp;
                johnUp.clear();
            }


            //dvamata obrushtat po 1 karta
            char cardJane = janeD.back(); 
            janeD.pop_back(); //premahva izigranata karta

            char cardJohn = johnD.back();
            johnD.pop_back();

            //veche sa oburnati nagore
            janeUp.push_back(cardJane);
            johnUp.push_back(cardJohn);

            steps++;

            //ako sa ravni, Snap na random princip
            if (cardJane == cardJohn)
            {
                int winNum = (random() / 141) % 2;

                if (winNum == 0)
                {
                    cout << "Snap! for Jane: ";

                    //v kraq na jane up- dobavi kartite na john s lice nagore
                    janeUp.insert(janeUp.end(), johnUp.begin(), johnUp.end());
                    //vsichki karti se iztrivat
                    johnUp.clear();

                    //pechat otgore nadolu
                    for (auto it = janeUp.rbegin(); it != janeUp.rend(); ++it)
                    {
                        cout << *it;
                    }


                    cout << endl;
                }
            
                else
                {
                    cout << "Snap! for John: ";

                    johnUp.insert(johnUp.end(), janeUp.begin(), janeUp.end());
                    janeUp.clear();

                    for (auto it = johnUp.rbegin(); it != johnUp.rend(); ++it)
                    {
                        cout << *it;
                    }

                    cout << endl;
                    
                }
            }
            
            //proverka dali ne sa svurshili kartite sled hoda
            if (janeD.empty() && janeUp.empty()) break;
            if (johnD.empty() && johnUp.empty()) break;
        }

        //proverka koi pecheli
        if (janeD.empty() && janeUp.empty())
        {
            cout << "John wins!" << endl;
        }
        else if (johnD.empty() && johnUp.empty())
        {
            cout << "Jane wins!" << endl;

        }
        else
        {
            cout << "Keeps going and going ..." << endl;
        }

        if (T > 0) cout << endl;

    }
}
