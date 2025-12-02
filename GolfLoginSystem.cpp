#include <iostream>
#include <vector>
#include <string>

using namespace std;

// class to allow user to login to scorecard system

class UserLogin {
private:
    string username;
    string password;

public:
    UserLogin( string user, string pass) : username(user), password(pass) {}

    string getUsername() const { 
        return username; 
    }
    string getPassword() const { 
        return password; 
    }
};

// class to allow manager to login to scorecard system

class ManagerLogin {
private:
    string username;
    string password;

public:
    UserLogin(string user,string pass) : username(user), password(pass) {}

    string getUsername() const { 
        return username; 
    }
    string getPassword() const { 
        return password; 
    }
};

// class to manage login system

class LoginSystem {
private:
    vector<UserLogin> users; // user logins
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
    for (const auto& u : users) {
        if (u.getUsername() == user && u.getPassword() == pass) {
            return true; // valid user
        }
    }
    return false; // invalid user
}

bool validateManager(const string& user, const string& pass) {
    for (const auto& m : managers) {
        if (m.getUsername() == user && m.getPassword() == pass) {
            return true; // valid manager
        }
    }
    return false; // invalid manager
}

void addUser(const string& user, const string& pass) {
    users.push_back(UserLogin(user, pass));
    cout << "User added successfully." << endl;
}

void addManager(const string& user, const string& pass) {
    managers.push_back(ManagerLogin(user, pass));
    cout << "Manager added successfully." << endl;
}
};

void loginPlatform(LoginManager& LoginManager) {
    string username, password;
    int choice, roleChoice;

    cout << "Welcome to the scorecard login platform!"<< endl;
    cout << "Please select your login option 1. Member Login\n2. Manager Login\n3.  Register New User\n4. Register New Manager\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (LoginManager.validateUser(username, password)) {
            cout << "User login successful!" << endl;
        } else {
            cout << "Invalid username or password." << endl;
        }
    } else if (choice == 2) { 

        cout << "Enter username:";
        cin >> username;
        cout << "Enter password:";
        cin >> password;

        if (LoginManager.validateManager(username, password)) {
            cout << "Manager login successful!" << endl;
        } else {
            cout << "Invalid username or password." << endl;
        }
    } else if (choice == 3) {
        cout << "Enter new username: ";
        cin >> username;
        cout << "Enter new password: ";
        cin >> password;
        LoginManager.addUser(username, password);
    } else if (choice == 4) {
        cout << "Enter new manager username: ";
        cin >> username;
        cout << "Enter new manager password: ";
        cin >> password;
        LoginManager.addManager(username, password);
    } else {
        cout << "Invalid choice." << endl;
    }
    
}
int main() {
    LoginManager loginManager;
    loginPlatform(loginManager);
    return 0;
}
