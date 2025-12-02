// /C:/Users/oisin/Documents/Year2/Programming/project/golf.cpp
#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct User {
    std::string name;
    bool isMember = false;
};

struct ScoreEntry {
    std::string player;
    std::string course;
    int holes;
    int strokes;
};

static std::vector<ScoreEntry> scoreLog;
static User currentUser{ "", false };

void pause() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showMenu() {
    std::cout << "\n--- Golf CLI ---\n";
    std::cout << "1) Member Login\n";
    std::cout << "2) Guest Login\n";
    std::cout << "3) Management Login\n";
    std::cout << "4) Competition Manager\n";
    std::cout << "5) Exit\n";
    std::cout << "Select an option (1-5): ";
} 

void memberLogin() {
    std::string id, pw;
    std::cout << "\n-- Member Login --\n";
    std::cout << "Member ID: ";
    std::cin >> id;
    std::cout << "Password: ";
    std::cin >> pw;
    // Simple hardcoded check for demo purposes
    if ((id == "member1" && pw == "pass1") || (id == "member2" && pw == "pass2")) {
        currentUser.name = id;
        currentUser.isMember = true;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Member login successful. Welcome, " << id << "!\n";
    } else {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid member credentials.\n";
    }
    pause();
}

void guestLogin() {
    std::string name;
    std::cout << "\n-- Guest Login --\n";
    std::cout << "Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    if (!name.empty()) {
        currentUser.name = name;
        currentUser.isMember = false;
        std::cout << "Guest session started for " << name << ".\n";
    } else {
        std::cout << "Name cannot be empty.\n";
    }
    pause();
}

void management() {
    std::string pw;
    std::cout << "\n-- Management --\n";
    std::cout << "Enter admin password: ";
    std::cin >> pw;
    if (pw != "admin123") {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Access denied.\n";
        pause();
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (true) {
        std::cout << "\nManagement Menu:\n";
        std::cout << "1) View score log\n";
        std::cout << "2) Clear score log\n";
        std::cout << "3) Back\n";
        std::cout << "Choice: ";
        int choice = 0;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (choice == 1) {
            if (scoreLog.empty()) {
                std::cout << "Score log is empty.\n";
            } else {
                for (size_t i = 0; i < scoreLog.size(); ++i) {
                    const auto &s = scoreLog[i];
                    std::cout << i+1 << ") " << s.player << " | " << s.course << " | holes: " << s.holes << " | strokes: " << s.strokes << "\n";
                }
            }
            pause();
        } else if (choice == 2) {
            scoreLog.clear();
            std::cout << "Score log cleared.\n";
            pause();
        } else if (choice == 3) {
            break;
        }
    }
}

void logIt() {
    if (currentUser.name.empty()) {
        std::cout << "No user logged in. Please login as member or guest first.\n";
        pause();
        return;
    }
    ScoreEntry s;
    s.player = currentUser.name;
    std::cout << "\n-- Log It (record score) --\n";
    std::cout << "Course name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, s.course);
    std::cout << "Holes played (e.g. 9 or 18): ";
    while (!(std::cin >> s.holes) || s.holes <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a positive number for holes: ";
    }
    std::cout << "Strokes: ";
    while (!(std::cin >> s.strokes) || s.strokes <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter a positive number for strokes: ";
    }
    scoreLog.push_back(s);
    std::cout << "Score recorded for " << s.player << ".\n";
    pause();
}

void competition() {
    std::cout << "\n-- Competition --\n";
    std::vector<std::string> comps = {
        "Morning Scramble - Sat 09:00",
        "Club Championship Qualifier - Sun 10:00",
        "Evening Par 3 Challenge - Fri 18:00"
    };
    for (size_t i = 0; i < comps.size(); ++i) {
        std::cout << (i+1) << ") " << comps[i] << "\n";
    }
    std::cout << "Enter number to register or 0 to return: ";
    int choice = -1;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    if (choice > 0 && choice <= static_cast<int>(comps.size())) {
        if (currentUser.name.empty()) {
            std::cout << "Please login before registering for a competition.\n";
        } else {
            std::cout << currentUser.name << " registered for: " << comps[choice-1] << "\n";
        }
    }
    pause();
}

int main() {
    while (true) {
        showMenu();
        int opt = 0;
        if (!(std::cin >> opt)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (opt) {
            case 1: memberLogin(); break;
            case 2: guestLogin(); break;
            case 3: management(); break;
            case 4: logIt(); break;
            case 5: competition(); break;
            case 6: std::cout << "Exiting...\n"; return 0;
            default: std::cout << "Invalid option.\n"; pause(); break;
        }
    }
    return 0;
}