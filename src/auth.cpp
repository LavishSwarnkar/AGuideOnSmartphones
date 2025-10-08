#include "auth.h"
#include "ui.h"
#include "menu.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

namespace auth {

using namespace ui;

// Helper to get string input, since gets is unsafe
void cgets(char* buffer, int max_len) {
    int i = 0;
    char c;
    while ((c = getche()) != '\r' && i < max_len - 1) {
        if (c == '\b' && i > 0) {
            std::cout << "\b \b";
            i--;
        } else if (c != '\b') {
            buffer[i++] = c;
        }
    }
    buffer[i] = '\0';
}

// --- Serialization helpers ---
void write_string(std::ofstream& fout, const std::string& s) {
    size_t len = s.length();
    fout.write(reinterpret_cast<const char*>(&len), sizeof(len));
    fout.write(s.c_str(), len);
}

std::string read_string(std::ifstream& fin) {
    size_t len;
    fin.read(reinterpret_cast<char*>(&len), sizeof(len));
    if (!fin || fin.gcount() != sizeof(len)) return "";
    std::string s(len, '\0');
    fin.read(&s[0], len);
    return s;
}

// --- User Class Methods ---
void User::setUsername(const std::string& name) { username = name; }
void User::setPassword(const std::string& pass) { password = pass; }
void User::setEmail(const std::string& mail) { email = mail; }
void User::setMobileNumber(const std::string& mobile) { mobile_number = mobile; }
void User::setHintQuestion(const std::string& question) { hint_question = question; }
void User::setHintAnswer(const std::string& answer) { hint_answer = answer; }

std::string User::getUsername() const { return username; }
std::string User::getPassword() const { return password; }
std::string User::getEmail() const { return email; }
std::string User::getMobileNumber() const { return mobile_number; }
std::string User::getHintQuestion() const { return hint_question; }
std::string User::getHintAnswer() const { return hint_answer; }

void User::serialize(std::ofstream& fout) const {
    write_string(fout, username);
    write_string(fout, password);
    write_string(fout, email);
    write_string(fout, mobile_number);
    write_string(fout, hint_question);
    write_string(fout, hint_answer);
}

void User::deserialize(std::ifstream& fin) {
    username = read_string(fin);
    password = read_string(fin);
    email = read_string(fin);
    mobile_number = read_string(fin);
    hint_question = read_string(fin);
    hint_answer = read_string(fin);
}

// --- Helper Functions ---
void promptForUserDetails(User& user) {
    char buffer[50];

    gotoxy(9, 18); cprintf("ENTER USERNAME:                      ");
    gotoxy(26, 18); cgets(buffer, 12); user.setUsername(buffer);
    drawFilledBox(17, 8, 70, 19, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 18); cprintf("ENTER PASSWORD:                        ");
    gotoxy(25, 18); cgets(buffer, 12); user.setPassword(buffer);
    drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 18); cprintf("ENTER EMAIL ID:                                          ");
    gotoxy(25, 18); cgets(buffer, 30); user.setEmail(buffer);
    drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 18); cprintf("ENTER MOBILE NO:                          ");
    gotoxy(26, 18); cgets(buffer, 20); user.setMobileNumber(buffer);
    drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 18); cprintf("ENTER HINT QUESTION:                         ");
    gotoxy(30, 18); cgets(buffer, 20); user.setHintQuestion(buffer);
    drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 18); cprintf("ENTER HINT QUESTION'S ANSWER:                                         ");
    gotoxy(39, 18); cgets(buffer, 20); user.setHintAnswer(buffer);
}

void displayUserDetails(const User& user) {
    textcolor(15); textbackground(1);
    gotoxy(9, 20); cprintf("USERNAME: %s", user.getUsername().c_str()); getch();
    drawFilledBox(20, 8, 72, 21, "Û", 1, 0, 0);

    // Not displaying password for security

    textcolor(15); textbackground(1);
    gotoxy(9, 20); cprintf("EMAIL ID: %s", user.getEmail().c_str()); getch();
    drawFilledBox(20, 8, 72, 21, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 20); cprintf("MOBILE NO: %s", user.getMobileNumber().c_str()); getch();
    drawFilledBox(20, 8, 72, 21, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 20); cprintf("HINT QUESTION: %s", user.getHintQuestion().c_str()); getch();
    drawFilledBox(20, 8, 72, 21, "Û", 1, 0, 0);
}

bool doesUserExist(const std::string& username) {
    std::ifstream fin("data/text/id.dat", std::ios::binary);
    if (!fin) return false;
    User currentUser;
    while (fin.peek() != EOF) {
        currentUser.deserialize(fin);
        if (currentUser.getUsername() == username) {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

std::vector<User> getAllUsers() {
    std::vector<User> users;
    std::ifstream fin("data/text/id.dat", std::ios::binary);
    if (!fin) return users;
    while (fin.peek() != EOF) {
        User u;
        u.deserialize(fin);
        if (fin.fail() || u.getUsername().empty()) break;
        users.push_back(u);
    }
    fin.close();
    return users;
}

void writeAllUsers(const std::vector<User>& users) {
    std::ofstream fout("data/text/id.dat", std::ios::binary | std::ios::trunc);
    for (const auto& user : users) {
        user.serialize(fout);
    }
    fout.close();
}


// --- Main Auth Functions ---
void registerNewUser() {
    drawBorderedBox(12, 26, 55, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15); textbackground(1);
    gotoxy(29, 13); cprintf(">> CREATE NEW ACCOUNT <<");

    User newUser;
    promptForUserDetails(newUser);

    if (doesUserExist(newUser.getUsername())) {
        gotoxy(17, 19);
        cprintf("AN ID WITH SAME USERNAME ALREADY EXISTS.. TRY AGAIN..");
    } else {
        std::ofstream fout("data/text/id.dat", std::ios::app | std::ios::binary);
        newUser.serialize(fout);
        fout.close();
        gotoxy(17, 19); cprintf("CONGRATS! YOU ARE NOW A REGISTERED USER");
    }
    getch();
}

void loginUser() {
    drawBorderedBox(12, 25, 56, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15); textbackground(1);
    gotoxy(27, 13); cprintf(">> LOGIN TO YOUR ACCOUNT <<");

    char username_buffer[20], password_buffer[20];
    drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
    textcolor(15); textbackground(1);
    gotoxy(9, 18); cprintf("ENTER YOUR USERNAME:                       ");
    gotoxy(30, 18); cgets(username_buffer, 12);

    drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
    textcolor(15); textbackground(1);
    gotoxy(9, 18); cprintf("ENTER YOUR PASSWORD:                         ");
    gotoxy(30, 18); cgets(password_buffer, 12);

    std::vector<User> users = getAllUsers();
    bool loggedIn = false;
    for (const auto& user : users) {
        if (user.getUsername() == username_buffer && user.getPassword() == password_buffer) {
            loggedIn = true;
            break;
        }
    }

    if (loggedIn) {
        gotoxy(9, 20); cprintf("LOGIN SUCCESSFUL");
        delay(1000);
        menu::displayMainMenu();
    } else {
        gotoxy(9, 20); cprintf("WRONG PASSWORD/USERNAME! TRY AGAIN..");
        getch();
    }
}

void changePassword() {
    drawBorderedBox(12, 26, 55, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15); textbackground(1);
    drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
    gotoxy(28, 13); cprintf(">> CHANGE YOUR PASSWORD <<");

    char username_buffer[20];
    drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
    textcolor(15); textbackground(1);
    gotoxy(9, 18); cprintf("ENTER YOUR USERNAME:                          ");
    gotoxy(30, 18); cgets(username_buffer, 12);

    if (!doesUserExist(username_buffer)) {
        gotoxy(9, 19); cprintf("USERNAME DOES NOT EXIST! TRY AGAIN..");
    } else {
        char old_pass_buffer[20], new_pass_buffer[20];
        drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
        textcolor(15); textbackground(1);
        gotoxy(9, 18); cprintf("ENTER YOUR OLD PASSWORD:                             ");
        gotoxy(34, 18); cgets(old_pass_buffer, 12);

        drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
        textcolor(15); textbackground(1);
        gotoxy(9, 18); cprintf("ENTER YOUR NEW PASSWORD:                      ");
        gotoxy(34, 18); cgets(new_pass_buffer, 12);

        std::vector<User> users = getAllUsers();
        bool passwordChanged = false;
        User updatedUser;
        for (auto& user : users) {
            if (user.getUsername() == username_buffer && user.getPassword() == old_pass_buffer) {
                user.setPassword(new_pass_buffer);
                updatedUser = user;
                passwordChanged = true;
                break;
            }
        }

        if (passwordChanged) {
            writeAllUsers(users);
            drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
            textcolor(15); textbackground(1);
            gotoxy(9, 18); cprintf("PASSWORD CHANGED SUCCESSFULLY! ");
            gotoxy(9, 19); cprintf("NOW, YOUR DETAILS ARE AS FOLLOWS. PRESS ANY KEY TO PROCEED: ");
            getch();
            displayUserDetails(updatedUser);
            getch();
        } else {
            gotoxy(9, 19); cprintf("DETAILS ENTERED BY YOU ARE WRONG. PRESS ANY KEY TO RETURN.");
        }
    }
    getch();
}

void forgotPassword() {
    drawBorderedBox(12, 26, 55, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15); textbackground(1);
    gotoxy(29, 13); cprintf(">> RESET YOUR PASSWORD <<");

    char username_buffer[20];
    drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);
    textcolor(15); textbackground(1);
    gotoxy(9, 18); cprintf("ENTER YOUR USERNAME: ");
    cgets(username_buffer, 12);

    if (!doesUserExist(username_buffer)) {
        drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);
        textcolor(15); textbackground(1);
        gotoxy(9, 19); cprintf("USERNAME DOES NOT EXIST! TRY AGAIN..");
    } else {
        std::vector<User> users = getAllUsers();
        bool found = false;
        User targetUser;
        int user_idx = -1;
        for (int i = 0; i < users.size(); ++i) {
            if (users[i].getUsername() == username_buffer) {
                targetUser = users[i];
                user_idx = i;
                found = true;
                break;
            }
        }

        if(found) {
            char hint_answer_buffer[20];
            drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
            textcolor(15); textbackground(1);
            gotoxy(9, 18); cprintf("ANSWER YOUR HINT QUESTION: %s? ", targetUser.getHintQuestion().c_str());
            cgets(hint_answer_buffer, 20);

            if (targetUser.getHintAnswer() == hint_answer_buffer) {
                char new_pass_buffer[20];
                gotoxy(9, 19); cprintf("ENTER NEW PASSWORD: ");
                cgets(new_pass_buffer, 12);
                users[user_idx].setPassword(new_pass_buffer);
                writeAllUsers(users);

                drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
                textcolor(15); textbackground(1);
                gotoxy(9, 18); cprintf("PASSWORD RESET SUCCESSFULLY! ");
                gotoxy(9, 19); cprintf("NOW, YOUR DETAILS ARE AS FOLLOWS. PRESS ANY KEY TO PROCEED: ");
                getch();
                displayUserDetails(users[user_idx]);
            } else {
                gotoxy(9, 19); cprintf("DETAILS ENTERED BY YOU ARE WRONG. PRESS ANY KEY TO RETURN.");
            }
        }
    }
    getch();
}

void printAllUsers() {
    drawBorderedBox(12, 26, 55, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15); textbackground(1);
    gotoxy(31, 13); cprintf(">> PRINT ALL DATA <<");

    char password[20];
    gotoxy(25, 16); cprintf("> ENTER ADMINISTRATOR PASSWORD:                     ");
    gotoxy(57, 16); cgets(password, 12);

    if (std::string(password) != "admin") {
        gotoxy(20, 19); cprintf("ACCESS DENIED! PRESS ANY KEY TO RETURN.");
    } else {
        gotoxy(25, 17); cprintf("# FORMAT: USERNAME, PASSWORD");
        gotoxy(9, 18);
        std::vector<User> users = getAllUsers();
        for(size_t i=0; i<users.size(); ++i) {
            gotoxy(9, 18 + i);
            cprintf(" %zu.) %s , %s", i+1, users[i].getUsername().c_str(), users[i].getPassword().c_str());
        }
    }
    getch();
}

void deleteAllUsers() {
    drawBorderedBox(12, 26, 55, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15); textbackground(1);
    gotoxy(30, 13); cprintf(">> DELETE ALL DATA <<");

    char password[20];
    gotoxy(25, 16); cprintf("> ENTER ADMINISTRATOR PASSWORD:                   ");
    gotoxy(57, 16); cgets(password, 12);

    if (std::string(password) != "admin") {
        gotoxy(20, 19); cprintf("ACCESS DENIED! PRESS ANY KEY TO RETURN.");
    } else {
        std::ofstream("data/text/id.dat", std::ios::trunc).close();
        gotoxy(15, 19); cprintf("ALL DATA CLEARED! PRESS ANY KEY TO RETURN.");
    }
    getch();
}

void adminMenu() {
    char s1[] = "> PRINT ALL ACCOUNTS DATA";
    char s2[] = "> DELETE ALL ACCOUNTS DATA";
    int choice = 1;

    auto drawUI = [&](int selected) {
        drawFilledBox(12, 3, 78, 23, "Û", 1, 0, 0);
        drawBorderedBox(12, 29, 51, 14, "*", 15, 1, 0);
        drawBorderedBox(14, 7, 74, 22, "*", 15, 1, 0);
        gotoxy(31, 13); cprintf(">> ADMINISTRATOR <<");

        textcolor(15); textbackground(selected == 1 ? 0 : 1);
        gotoxy(20, 16); cprintf(s1);

        textcolor(15); textbackground(selected == 2 ? 0 : 1);
        gotoxy(20, 18); cprintf(s2);

        textcolor(15); textbackground(1);
        gotoxy(70, 4); cprintf("'E'-EXIT");
        gotoxy(70, 5); cprintf("'B'-BACK");
    };

    drawUI(choice);

    while (true) {
        char key = getch();
        if ((key == '2' || key == 'w' || key == 'W' || key == 72) && choice > 1) {
            choice--;
        } else if ((key == '5' || key == 's' || key == 'S' || key == 80) && choice < 2) {
            choice++;
        } else if (key == 'c' || key == 'C' || key == 13) {
            switch (choice) {
                case 1: printAllUsers(); break;
                case 2: deleteAllUsers(); break;
            }
            drawUI(choice);
        } else if (key == 'e' || key == 'E') {
            menu::exitApplication();
        } else if (key == 'b' || key == 'B') {
            return;
        }
        drawUI(choice);
    }
}

} // namespace auth