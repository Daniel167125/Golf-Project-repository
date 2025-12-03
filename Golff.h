#ifndef GOLFF_H
#define GOLFF_H

#include <iostream>
#include <string>

using namespace std;

// ============================
// == GOLF CLASS (HEADER)  = FINN'S
// ============================

class Golf
{
    public:

        Golf();
        virtual ~Golf();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Getsurname(){return surname;}
        void Setsurname(string val){surname=val;}
        string Getdate() { return date; }
        void Setdate(string val) { date = val; }
        void Sethandicap(int val) { handicap = val; }
        int Getage() { return age; }
        void Setage(int val) { age = val; }
        int Getscore() { return score; }
        void Setscore(int val) { score = val; }
        void New_Scorecard();
        void Display();
        void SaveScorecard();

    private:
        string name;
        string surname;
        string date;
        int handicap;
        int age;
        int score;
};

#endif // GOLFF_H
