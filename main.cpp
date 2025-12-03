#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>

#include "Golff.h"

using namespace std;

// =========================================================
// ======= OISINS' STRUCTURE
// =========================================================

struct User {
    string name;
    bool isMember = false;
};

struct ScoreEntry {
    string player;
    string course;
    int holes;
    int strokes;
};

static User currentUser{ "", false };
static vector<ScoreEntry> scoreLog;

void pauseScreen() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// =========================================================
// FINN'S SCORECARD SYSTEM = FROM .CPP FILE
// =========================================================

void runSystem()
{
    int z = 0;
    cout << "Welcome!\n";
    cout << "Please Select:\n";
    cout << "1) Create a new scorecard\n";
    cout << "2) View tournament leaderboard\n";

    for (int i = 0; i < 50; i++) {
        cout << "Please enter a number 1–2.\n";
        cin >> z;

        if (cin && (z == 1 || z == 2)) {
            cout << "Thank you\n";
            break;
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            z++;
        }
    }

    if (z == 1) {
        cout << "Create new scorecard.\n";
        Golf player;
        player.New_Scorecard();   // ORIGINAL FUNCTION
    }
    else if (z == 2) {
        cout << "Last Tournament Leaderboard: \n \n";

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

        cout << "1st Place\n";
        myGolf[0].Display();
        cout << "2nd Place\n";
        myGolf[1].Display();
        cout << "3rd Place\n";
        myGolf[2].Display();

        cout << "\nThank You For Playing\n\n";
    }
}

// =========================================================
//=============== DANIEL’S /OISIN'S LOGIN SYSTEM
// =========================================================

class UserLogin { // class to allow for members to log in
private:
    string username;
    string password; // parameters for logins as a member

public:
    UserLogin(string user, string pass) : username(user), password(pass) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; } // getter functions for this class
};

class ManagerLogin { // class to allow managers to login
private:
    string username;
    string password; // parameters for login as a manager

public:
    ManagerLogin(string user, string pass) : username(user), password(pass) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; } // getter functions for manager class
};

class LoginManager { // class designed to manage the difference between login types
private:
    vector<UserLogin> users;
    vector<ManagerLogin> managers; // vectors to hold the login information of each class

public:
    LoginManager() {
        users.push_back(UserLogin("TigerWoods", "PGA2000"));
        users.push_back(UserLogin("NellyKorda", "LPGA2025"));
        users.push_back(UserLogin("RoryMcilroy", "MASTERS123")); // member examples

        managers.push_back(ManagerLogin("JohnDaly", "RIPIT123"));
        managers.push_back(ManagerLogin("PadraigHarrington", "OPEN2008"));
        managers.push_back(ManagerLogin("ScottieScheffler", "PGA2025")); // manager examples
    }

    bool validateUser(const string& user, const string& pass) {
        for (const auto& u : users)
            if (u.getUsername() == user && u.getPassword() == pass)
                return true;
        return false; // validate that the member belongs to its class
    }

    bool validateManager(const string& user, const string& pass) {
        for (const auto& m : managers)
            if (m.getUsername() == user && m.getPassword() == pass)
                return true;
        return false; // validate that the manager belongs to its class
    }

    void addUser(const string& user, const string& pass) {
        users.push_back(UserLogin(user, pass));
        cout << "User added successfully.\n";
    }

    void addManager(const string& user, const string& pass) {
        managers.push_back(ManagerLogin(user, pass));
        cout << "Manager added successfully.\n";
    }
};


static LoginManager g_loginManager;

void memberLogin()
{
    string username, password;
    cout << "\n-- Member Login --\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;// prompt to allow user to login

    if (g_loginManager.validateUser(username, password)) {
        cout << "Login successful.\n";
        currentUser.name = username;
        currentUser.isMember = true;
    } else {
        cout << "Invalid credentials.\n";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    pauseScreen();// sets cases for incorrect and correct logins
}

void registerMember()
{
    string username, password;
    cout << "\n-- Register Member --\n";
    cout << "New username: ";
    cin >> username;
    cout << "New password: ";
    cin >> password;

    g_loginManager.addUser(username, password);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    pauseScreen();// allows for the size of the vector to be increased and adds new login to loginsystem class
}

void managerLogin()
{
    string username, password;
    cout << "\n-- Manager Login --\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password; // manager login prompts

    if (g_loginManager.validateManager(username, password)) {
        cout << "Manager login successful.\n";
    } else {
        cout << "Invalid manager credentials.\n";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    pauseScreen();// sets cases for correct and incorrect logins
}

void registerManager()
{
    string username, password;
    cout << "\n-- Register Manager --\n";
    cout << "New manager username: ";
    cin >> username;
    cout << "New manager password: ";
    cin >> password;

    g_loginManager.addManager(username, password);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
      pauseScreen();// allows for new manager to be added to loginsystem
}

// =========================================================
// =======================OISÍN — COMPETITION MANAGER
// =========================================================

void guestLogin()
{
    string name;
    cout << " \n-- Guest Login  --\n";
    cout << "Enter name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);// allows for guest login that will not interact with any other login class

    if (!name.empty()) {
        currentUser.name = name;
        currentUser.isMember = false;
        cout << "Guest logged in: " << name << "\n";
    } else {
        cout << "Name cannot be empty.\n";
    }

     pauseScreen();// cases for correct and incorrect inputs
}

void competitionManager()
{
    int choice;
    cout << "\n-- Competition Manager --\n";
    cout << "1)  Register for competition\n";
    cout << "2)  View all saved scorecards\n";
    cout << "3)  Back\n";
    cout << " Choose option:  ";
    cin >>  choice;// options for competition manager to perofrm

    if (choice ==1) {
        cout << " Registered for competition: " << currentUser.name << "\n";
    }
    else if (choice == 2) {
        ifstream file("scorecards.txt");
        if (!file) {
            cout << "No saved scorecards.\n";
        } else {
            cout << file.rdbuf();
        }
    }

    pauseScreen();// cases for manager to operate after succesul login
}

// =========================================================
// ==================main menu
// =========================================================

int main()
{
    while (true) {

        cout << "\n====== MAIN MENU ======\n";
        cout << "1) Enter Scorecard\n";
        cout << "2) Member Login\n";
        cout << "3) Register Member\n";
        cout << "4) Manager Login\n";
        cout << "5) Register Manager\n";
        cout << "6) Competition Manager\n";
        cout << "7) Exit\n";
        cout << "Select option: ";   // main window appearance

        int option;

        // safe input handling
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 1–8.\n";
            continue;// allows user to continue on interface after incorrect input
        }
//============================================================
//============Troubleshooting


        switch(option)
        {
            case 1: runSystem(); break;
            case 2: memberLogin(); break;
            case 3: registerMember(); break;
            case 4: managerLogin(); break;
            case 5: registerManager(); break;
            case 6: competitionManager(); break;// details the classes that each case should interact with when select


            case 7:
                cout << "Exiting...\n";
                return 0;// exit application

            default:
                cout << "Invalid option. Enter number 1 – 8.\n";
                pauseScreen();
                break;
        }
    }

    return 0;
}

