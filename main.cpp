#include <iostream>
#include "Golf.h"
#include <fstream>
using namespace std;

int main(){



//==========User Prompt===========
    int z=0 ;
    cout << " Welcome!" << endl;
    cout<<"Please Select:"<<endl;
    cout<<"1) Create a new scorecard "<<endl;
    cout<<"2) View tournament leaderboard "<<endl;
{


   for (int i = 0; i < 50; i++){
        cout <<" Please enter a number 1-2. "<<endl;
        cin>> z;

        if (cin && (z == 1 || z == 2)){
            cout<<"Thank you"<<endl;
            break;
        }
        else{
       //cout <<" Invalid. Please enter a number 1-2. "<<endl;
       cin.clear();
       cin.ignore(1000, '\n');
       z++;}
   }

   if(z ==1){
        cout<< "Create new scorecard. "<<endl;
        Golf player;
        player.New_Scorecard();
        }
        else if (z == 2){
                cout << "Tournament Leaderboard: \n"<<endl;
                Golf myGolf[3];

                    myGolf[0].Setname("Tiger");
                    myGolf[0].Setsurname("Woods");
                    myGolf[0].Sethandicap(2);
                    myGolf[0].Setscore(76);

                    myGolf[1].Setname("Nelly");
                    myGolf[1].Setsurname("Korda");
                    myGolf[1].Sethandicap(6);
                    myGolf[1].Setscore(79);

                    myGolf[2].Setname("Rory");
                    myGolf[2].Setsurname("McIlroy");
                    myGolf[2].Sethandicap(3);
                    myGolf[2].Setscore(81);

        cout<<" 1st Place  \n"<<endl;
       myGolf[0].Display();
       cout<<" 2nd Place  \n"<<endl;
       myGolf[1].Display();
       cout<<" 3rd Place  \n"<<endl;
       myGolf[2].Display();
       cout<<" \n Thank You For Playing \n"<<endl;
       }

       else if (z== 3){
            ifstream file("scorecards.txt");
       if (! file)
        {
        cout << "No scorecards found.  \n"<<endl;
    }
    else
    {
        cout << "\n      Saved Scorecards     \n"<<endl;
        cout << file.rdbuf()<<endl;   // prints entire file
    }
}

 return 0;
   }
}






