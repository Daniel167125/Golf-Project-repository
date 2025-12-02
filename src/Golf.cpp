#include "Golf.h"
#include <fstream>

Golf::Golf(){  //Default Constructor
    name="N/A";
    surname="N/A";
    handicap=0;
    age=0;
    score=0;
    }
void Golf::Display(){
    cout<< " Player Information "<<endl;

    cout<<"   "<<name<<" "<<surname<<endl;
    cout<<"   Handicap  =  "<<handicap<<endl;
    cout<<"   Competition Score is  "<<score<<endl;
    cout<<"\n"<<endl;
}

Golf::~Golf() //Default destructor
{
  //cout<<" \n Thank You For Playing \n"<<endl;
}
void Golf::New_Scorecard(){
    string date;
    cout<<"Please enter your first name: "<<endl;
    cin>>name;
    //cout<<"Enter your surname: "<<endl;
    //cin>>surname;
    cout<<"Enter the date (DD/MM/YYYY): "<<endl;
    cin >>date;

   int h=0;    //player's handicap
   int p=0;

   int index[18] ={5, 17, 1, 15, 3, 7, 13, 9, 11, 6, 16, 18, 2, 14, 12, 8, 10, 4}; //Ranked difficulty of each hole
   int par[18]= {4, 3, 4, 5, 4, 5, 3, 5, 4, 4, 4, 3, 4, 5, 3, 4, 5, 4};            //Strokes allowed for each hole


                                    //taken from lab 3
    for (int i=0; i<50; i++){        //gives the user 5 attempts to enter a valid handicap
        cout<<"Please enter your handicap 0-54: ";
        cin >> h;

        if(cin && h >= 0 && h <= 54){   //makes sure a users handicap is above 54 or below 0 as per rules
            cout<<"Your handicap is: "<<h<<endl;
            cout<<"Thank you"<<endl;
            break;                       //exit loop
        }
        else{
            cout<<"Invalid handicap, please try again."<<endl; //printed when the given was not 0-54
            cin.clear();                             //this resets the input sysytem
            cin.ignore(1000, '\n');           //Taken from lab 3

            p++;
            }
    }
int holesplayed[18];                     //array created with 18 numbers 0-17

                                         //p ->holes played
    for (int p = 0; p < 18; p++)         //everytime p is under 18 it loops until i=18
    {
        holesplayed[p] = 0;              //starting number of the array

                                         // Give 1 shot to every hole for every full 18 handicap
        if (h >= 18) holesplayed[p]++;

        if (h >= 36) holesplayed[p]++;

                                         // Extra shots for the lowest index holes
        if (index[p] <= (h % 18))        //(h % 18) is the the modulus remainder
            holesplayed[p]++;            // Give an extra stroke to the holes with the lowest stroke index
    }

                                         // Asking for the number of strokes on each hole
    int strokes[18];                     //Stores the number of strokes the player takes on each of the 18 holes
    int Totalstrokes = 0;
    int Netscore = 0;

    for (int p = 0; p < 18; p++)         //loop intil p=18
    {
        while (true)                     //while the counter 'p' remains < 18
        {
            cout << "Enter strokes for hole " << (p + 1)<< " (Par " << par[p]<< ", Index " << index[p] << "): ";
                                         //p+1 simply increases the hole count

            cin >> strokes[p];           //given strokes for the hole p

            if (cin && strokes[p] > 0)   //making sure number is positive
            {
                break;                   // valid exit loop
            }
            else
            {
                cout << "Invalid number. Try again.\n";
                cin.clear();             //invalid input
                cin.ignore(1000, '\n');
            }
        }

        Totalstrokes += strokes[p];       //total calculated i(strokes) = total strokes
        Netscore   += strokes[p] - holesplayed[p];  //total strokes-holesplayed
    }

          // printed results//

    cout << "Your total strokes: " << Totalstrokes << endl;
    cout << "Your net score:   " << Netscore   << endl;

    score = Totalstrokes;
    handicap = h;

    ofstream file(name , ios::app);  // append mode so old scorecards stay
    file << "Name: " << name << "\n";
    file << "Date: " << date << "\n";
    file << "Handicap: " << h << "\n";
    file << "Score: " << score << "\n";
    file.close();

    return;
}





