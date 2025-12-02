/// Daniel O'Hare C24410814 - Golf Login System CPP File - Programming Project assessment 


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// class to allow user to login to scorecard system

class UserLogin {
private:
    string username;  
    string password;   // private strings to hold usernames and passwords of members

public:
    UserLogin( string user, string pass) : username(user), password(pass) {}

    string getUsername() const { 
        return username; 
    }
    string getPassword() const { 
        return password; 
    } // getter functions to obtain username and password
};

// class to allow manager to login to scorecard system

class ManagerLogin {
private:
    string username;
    string password;  // private strings to hold usernames and passwords of managers

public:
    UserLogin(string user,string pass) : username(user), password(pass) {}

    string getUsername() const { 
        return username; 
    }
    string getPassword() const { 
        return password;  // getter functions to obtain username and password
    }
};

// class to manage login system

class LoginSystem {
private:
    vector<UserLogin> users; // uer logins
    vector<ManagerLogin> managers; // manger logins

public:
LoginManager() {
    // Enter example users and maagers differencing them from eachother
    users.push_back(UserLogin("Tiger Woods", "PGA2000"));

    users.push_back(UserLogin("Nelly Korda", "LPGA2025")); // example users, push_back is used to define new vector values

    users.push_back(UserLogin("Rory Mcilroy", "MASTERS123"));

    managers.push_back(ManagerLogin("John Daly", "RIPIT123"));

    managers.push_back(ManagerLogin("Padraig Harrington", "OPEN2008"));

    managers.push_back(ManagerLogin("Scottie Scheffler", "PGA2025")); // example managers, push_back is used to define new vector values

}

bool validateUser(const string& user, const string& pass) {
    for (const auto& u : users)// for loop to ensure member is real  {
        if (u.getUsername() == user && u.getPassword() == pass) {
            return true; // valid user
        }
    }
    return false; // invalid user
}

bool validateManager(const string& user, const string& pass) {
    for (const auto& m : managers) // for loop to ensure manager is real  {
        if (m.getUsername() == user && m.getPassword() == pass) {
            return true; // valid manager
        }
    }
    return false; // invalid manager
}

void addUser(const string& user, const string& pass) // function that will allow a new user to register{
    users.push_back(UserLogin(user, pass));
    cout << "User added successfully." << endl;
}
void addManager(const string& user, const string& pass) // function that will allow a new manager to register{
    managers.push_back(ManagerLogin(user, pass));
    cout << "Manager added successfully." << endl;
}
};

void loginPlatform(LoginManager& LoginManager)// function that will let uer choose login or regster {
    string username, password;
    int choice, roleChoice;

    cout << "Welcome to the scorecard login platform!"<< endl;
    cout << "Please select your login option 1. Member Login\n2. Manager Login\n3.  Register New User\n4. Register New Manager\n";
    cin >> choice; // initial user prompt to choose login or register

    if (choice == 1)// member login instance  {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (LoginManager.validateUser(username, password))// if statement to validate user exists  {
            cout << "User login successful!" << endl;
        } else {
            cout << "Invalid username or password." << endl;
        }
    } else if (choice == 2)// manaager login instanve { 

        cout << "Enter username:";
        cin >> username;
        cout << "Enter password:";
        cin >> password;

        if (LoginManager.validateManager(username, password))// if statement to validate manager exists  {
            cout << "Manager login successful!" << endl;
        } else {
            cout << "Invalid username or password." << endl;
        }
    } else if (choice == 3)// regisration option for new members {
        cout << "Enter new username: ";
        cin >> username;
        cout << "Enter new password: ";
        cin >> password;
        LoginManager.addUser(username, password);// calling on new user function to add new user to system
    } else if (choice == 4)// registration option for new managers {
        cout << "Enter new manager username: ";
        cin >> username;
        cout << "Enter new manager password: ";
        cin >> password;
        LoginManager.addManager(username, password);// calling on new manager function to add new manager to system
    } else {
        cout << "Invalid choice." << endl;
    }
    
}
int main() {
    LoginManager loginManager;
    loginPlatform(loginManager);
    return 0;// main function to run login platform
}
