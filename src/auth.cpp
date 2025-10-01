#include "auth.h"
#include "ui.h"
#include "menu.h"
#include <iostream>
#include <conio.h>
#include <cstring>
#include <fstream>
#include <cstdio>

using namespace std;

// User class method implementations
void User::setUsername(const char* name) { strcpy(username, name); }
void User::setPassword(const char* pass) { strcpy(password, pass); }
void User::setEmail(const char* mail) { strcpy(email, mail); }
void User::setMobileNumber(const char* mobile) { strcpy(mobile_number, mobile); }
void User::setHintQuestion(const char* question) { strcpy(hint_question, question); }
void User::setHintAnswer(const char* answer) { strcpy(hint_answer, answer); }

char* User::getUsername() { return username; }
char* User::getPassword() { return password; }
char* User::getEmail() { return email; }
char* User::getMobileNumber() { return mobile_number; }
char* User::getHintQuestion() { return hint_question; }
char* User::getHintAnswer() { return hint_answer; }

// Helper function to get user details
void promptForUserDetails(User& user) {
    char buffer[50];

    gotoxy(9, 18);
    cprintf("ENTER USERNAME:                      ");
    gotoxy(26, 18); gets(buffer); user.setUsername(buffer);
    drawFilledBox(17, 8, 70, 19, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 18);
    cprintf("ENTER PASSWORD:                        ");
    gotoxy(25, 18); gets(buffer); user.setPassword(buffer);
    drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 18);
    cprintf("ENTER EMAIL ID:                                          ");
    gotoxy(25, 18);  gets(buffer); user.setEmail(buffer);
    drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 18);
    cprintf("ENTER MOBILE NO:                          ");
    gotoxy(26, 18);  gets(buffer); user.setMobileNumber(buffer);
    drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 18);
    cprintf("ENTER HINT QUESTION:                         ");
    gotoxy(30, 18);  gets(buffer); user.setHintQuestion(buffer);
    drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 18);
    cprintf("ENTER HINT QUESTION'S ANSWER:                                         ");
    gotoxy(39, 18);  gets(buffer); user.setHintAnswer(buffer);
}

// Helper function to display user details
void displayUserDetails(User user) {
    textcolor(15); textbackground(1);
    gotoxy(9, 20);
    cprintf("USERNAME: "); cprintf(user.getUsername()); getch();
    drawFilledBox(20, 8, 72, 21, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 20);
    cprintf("PASSWORD: "); cprintf(user.getPassword()); getch();
    drawFilledBox(20, 8, 72, 21, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 20);
    cprintf("EMAIL ID: "); cprintf(user.getEmail()); getch();
    drawFilledBox(20, 8, 72, 21, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 20);
    cprintf("MOBILE NO: "); cprintf(user.getMobileNumber()); getch();
    drawFilledBox(20, 8, 72, 21, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 20);
    cprintf("HINT QUESTION: "); cprintf(user.getHintQuestion()); getch();
    drawFilledBox(20, 8, 72, 21, "Û", 1, 0, 0);

    textcolor(15); textbackground(1);
    gotoxy(9, 20);
    cprintf("HINT QUESTION'S ANSWER: "); cprintf(user.getHintAnswer());
}

// Function to check if a user exists
bool doesUserExist(const char* username) {
    User currentUser;
    ifstream fin("data\\text\\id.dat", ios::binary);
    while (fin.read((char*)&currentUser, sizeof(currentUser))) {
        if (strcmp(username, currentUser.getUsername()) == 0) {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

// Function to register a new user
void registerNewUser() {
    drawBorderedBox(12, 26, 55, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15);
    textbackground(1);
    gotoxy(29, 13); cprintf(">> CREATE NEW ACCOUNT <<");

    ofstream fout("data\\text\\id.dat", ios::app | ios::binary);
    if (!fout) {
        cprintf("ERROR");
        return;
    }

    User newUser;
    promptForUserDetails(newUser);

    if (doesUserExist(newUser.getUsername())) {
        gotoxy(17, 19);
        cprintf("AN ID WITH SAME USERNAME ALREADY EXISTS.. TRY AGAIN..");
    } else {
        fout.write((char*)&newUser, sizeof(newUser));
        gotoxy(17, 19); cprintf("CONGRATS! YOU ARE NOW A REGISTERED USER");
    }
    fout.close();
    getch();
}

// Function to log in a user
void loginUser() {
    drawBorderedBox(12, 25, 56, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15); textbackground(1);
    gotoxy(27, 13); cprintf(">> LOGIN TO YOUR ACCOUNT <<");

    User existingUser, storedUser;
    drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
    textcolor(15); textbackground(1);
    gotoxy(9, 18); cprintf("ENTER YOUR USERNAME:                       ");
    gotoxy(30, 18); gets(existingUser.getUsername());

    drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
    textcolor(15); textbackground(1);
    gotoxy(9, 18); cprintf("ENTER YOUR PASSWORD:                         ");
    gotoxy(30, 18); gets(existingUser.getPassword());

    ifstream fin("data\\text\\id.dat", ios::binary);
    if (!fin) {
        cout << "ERROR";
        return;
    }

    bool loggedIn = false;
    while (fin.read((char*)&storedUser, sizeof(storedUser))) {
        if (strcmp(existingUser.getUsername(), storedUser.getUsername()) == 0 &&
            strcmp(existingUser.getPassword(), storedUser.getPassword()) == 0) {
            loggedIn = true;
            break;
        }
    }
    fin.close();

    if (loggedIn) {
        gotoxy(9, 20);
        cprintf("LOGIN SUCCESSFUL");
        delay(1000);
        mainMenu();
    } else {
        gotoxy(9, 20);
        cprintf("WRONG PASSWORD/USERNAME! TRY AGAIN..");
        getch();
    }
}

// Function to change a user's password
void changePassword() {
    drawBorderedBox(12, 26, 55, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15); textbackground(1);
    drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
    gotoxy(28, 13);
    cprintf(">> CHANGE YOUR PASSWORD <<");

    User userToUpdate, storedUser;
    char newPassword[20];

    drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
    textcolor(15); textbackground(1);
    gotoxy(9, 18);
    cprintf("ENTER YOUR USERNAME:                          ");
    gotoxy(30, 18);
    gets(userToUpdate.getUsername());

    if (!doesUserExist(userToUpdate.getUsername())) {
        gotoxy(9, 19);
        cprintf("USERNAME DOES NOT EXIST! TRY AGAIN..");
    } else {
        drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
        textcolor(15); textbackground(1);
        gotoxy(9, 18);
        cprintf("ENTER YOUR OLD PASSWORD:                             ");
        gotoxy(34, 18); gets(userToUpdate.getPassword());

        drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
        textcolor(15); textbackground(1);
        gotoxy(9, 18);
        cprintf("ENTER YOUR NEW PASSWORD:                      ");
        gotoxy(34, 18); gets(newPassword);

        fstream file("data\\text\\id.dat", ios::in | ios::out | ios::binary);
        bool passwordChanged = false;
        while (file.read((char*)&storedUser, sizeof(storedUser))) {
            if (strcmp(storedUser.getPassword(), userToUpdate.getPassword()) == 0) {
                storedUser.setPassword(newPassword);
                long pos = -sizeof(storedUser);
                file.seekp(pos, ios::cur);
                file.write((char*)&storedUser, sizeof(storedUser));
                passwordChanged = true;
                break;
            }
        }
        file.close();

        if (passwordChanged) {
            drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
            textcolor(15); textbackground(1);
            gotoxy(9, 18);
            cprintf("PASSWORD CHANGED SUCCESSFULLY! ");
            gotoxy(9, 19);
            cprintf("NOW, YOUR DETAILS ARE AS FOLLOWS. PRESS ANY KEY TO PROCEED: ");
            getch();
            displayUserDetails(storedUser);
            getch();
        } else {
            gotoxy(9, 19);
            cprintf("DETAILS ENTERED BY YOU ARE WRONG. PRESS ANY KEY TO RETURN.");
        }
    }
    getch();
}

// Function to reset a user's password
void forgotPassword() {
    drawBorderedBox(12, 26, 55, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15); textbackground(1);
    gotoxy(29, 13); cprintf(">> RESET YOUR PASSWORD <<");

    User userToUpdate, storedUser;
    char username[20];

    drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);
    textcolor(15); textbackground(1);
    gotoxy(9, 18);
    cprintf("ENTER YOUR USERNAME: ");
    gets(username);
    userToUpdate.setUsername(username);

    if (!doesUserExist(userToUpdate.getUsername())) {
        drawFilledBox(16, 8, 70, 19, "Û", 1, 0, 0);
        textcolor(15); textbackground(1);
        gotoxy(9, 19);
        cprintf("USERNAME DOES NOT EXIST! TRY AGAIN..");
    } else {
        fstream file("data\\text\\id.dat", ios::in | ios::out | ios::binary);
        bool found = false;
        while (file.read((char*)&storedUser, sizeof(storedUser))) {
            if (strcmp(storedUser.getUsername(), userToUpdate.getUsername()) == 0) {
                found = true;
                break;
            }
        }

        if(found) {
            drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
            textcolor(15); textbackground(1);
            gotoxy(9, 18);
            cprintf("ANSWER YOUR HINT QUESTION: ");
            cprintf(storedUser.getHintQuestion()); cprintf("? ");
            gotoxy(9, 19); gets(userToUpdate.getHintAnswer());

            if (strcmp(userToUpdate.getHintAnswer(), storedUser.getHintAnswer()) == 0) {
                gotoxy(9, 19); cprintf("ENTER NEW PASSWORD: ");
                char newPassword[20];
                gets(newPassword);
                storedUser.setPassword(newPassword);
                long pos = -sizeof(userToUpdate);
                file.seekp(pos, ios::cur);
                file.write((char*)&storedUser, sizeof(storedUser));

                drawFilledBox(16, 8, 72, 19, "Û", 1, 0, 0);
                textcolor(15); textbackground(1);
                gotoxy(9, 18);
                cprintf("PASSWORD RESET SUCCESSFULLY! ");
                gotoxy(9, 19);
                cprintf("NOW, YOUR DETAILS ARE AS FOLLOWS. PRESS ANY KEY TO PROCEED: ");
                getch();
                displayUserDetails(storedUser);
            } else {
                gotoxy(9, 19);
                cprintf("DETAILS ENTERED BY YOU ARE WRONG. PRESS ANY KEY TO RETURN.");
            }
        }
        file.close();
    }
    getch();
}

// Admin functions
void printAllUsers() {
    drawBorderedBox(12, 26, 55, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15); textbackground(1);
    gotoxy(31, 13); cprintf(">> PRINT ALL DATA <<");

    User currentUser;
    char password[20], adminPass[20] = "admin";
    int i = 1, l = 0, k = 0;

    gotoxy(25, 16);
    cprintf("> ENTER ADMINISTRATOR PASSWORD:                     ");
    gotoxy(57, 16); gets(password);

    if (strcmp(password, adminPass) != 0) {
        gotoxy(20, 19);
        cprintf("ACCESS DENIED! PRESS ANY KEY TO RETURN.");
        getch();
        return;
    } else {
        gotoxy(25, 17);
        cprintf("# FORMAT: USERNAME, PASSWORD");
        gotoxy(9, 18); cprintf("                                    ");
        gotoxy(9, 18);
        ifstream fin("data\\text\\id.dat", ios::binary);
        while (fin.read((char*)&currentUser, sizeof(currentUser))) {
            cout << " " << i << ".) ";
            cprintf(" ");
            cprintf(currentUser.getUsername());
            cprintf(" , ");
            cprintf(currentUser.getPassword());
            i++;
            l += strlen(currentUser.getUsername());
            l += strlen(currentUser.getPassword());
            l += 10;
            if (l > (61 + (k * 61))) {
                gotoxy(9, 19 + k);
                k++;
            }
        }
        fin.close();
    }
    getch();
}

void deleteAllUsers() {
    drawBorderedBox(12, 26, 55, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    textcolor(15); textbackground(1);
    gotoxy(30, 13); cprintf(">> DELETE ALL DATA <<");

    char password[20], adminPass[20] = "admin";
    gotoxy(25, 16);
    cprintf("> ENTER ADMINISTRATOR PASSWORD:                   ");
    gotoxy(57, 16); gets(password);

    if (strcmp(password, adminPass) != 0) {
        gotoxy(20, 19);
        cprintf("ACCESS DENIED! PRESS ANY KEY TO RETURN.");
        getch();
        return;
    } else {
        ofstream fout("data\\text\\id.dat", ios::binary);
        fout.close();
        gotoxy(15, 19);
        cprintf("ALL DATA CLEARED! PRESS ANY KEY TO RETURN.");
    }
    getch();
}

void adminMenu() {
    char s1[50] = "> PRINT ALL ACCOUNTS DATA";
    char s2[50] = "> DELETE ALL ACCOUNTS DATA";
    char key = '0';
    int choice = 1, refreshed = 0;

    drawFilledBox(12, 3, 78, 23, "Û", 1, 0);
    textcolor(0); textbackground(14);
    drawBorderedBox(12, 29, 51, 14, "*", 15, 1);
    drawBorderedBox(14, 7, 74, 22, "*", 15, 1);
    gotoxy(31, 13); cprintf(">> ADMINISTRATOR <<");
    textcolor(15); textbackground(1);
    gotoxy(20, 16); cprintf(s1);
    textcolor(0); textbackground(7);
    gotoxy(20, 18); cprintf(s2);
    textcolor(15); textbackground(1);
    gotoxy(70, 4); cprintf("'E'-EXIT");
    gotoxy(70, 5); cprintf("'B'-BACK");

    while (1) {
        key = getch();
        if ((key == '2' || key == '4' || key == 'w' || key == 'a' || key == 'W' || key == 'A' || key == 72 || key == 75) && choice != 1)
            choice -= 1;
        else if ((key == '5' || key == '6' || key == 's' || key == 'd' || key == 'S' || key == 'D' || key == 80 || key == 77) && choice != 2)
            choice += 1;
        else if (key == 'c' || key == 'C' || key == 13) {
            drawFilledBox(12, 3, 78, 23, "Û", 1, 0, 0);
            drawBorderedBox(12, 26, 55, 14, "*", 15, 1);
            textcolor(15); textbackground(1);
            switch (choice) {
            case 1: printAllUsers(); refreshed = 0; break;
            case 2: deleteAllUsers(); refreshed = 0; break;
            }
        } else if (key == 'e' || key == 'E')
            exit(0);
        else if (key == 'b' || key == 'B')
            return;

        if (refreshed) {
            drawFilledBox(12, 3, 78, 23, "Û", 1, 0, 0);
            drawBorderedBox(12, 29, 51, 14, "*", 15, 1, 0);
            drawBorderedBox(14, 7, 74, 22, "*", 15, 1, 0);
            gotoxy(31, 13); cprintf(">> ADMINISTRATOR <<");
            textcolor(15); textbackground(1);
            gotoxy(20, 16); cprintf(s1);
            textcolor(0); textbackground(7);
            gotoxy(20, 18); cprintf(s2);
            textcolor(15); textbackground(1);
            gotoxy(70, 4); cprintf("'E'-EXIT");
            gotoxy(70, 5); cprintf("'B'-BACK");
        }

        switch (choice) {
        case 1:
            textcolor(15); textbackground(1);
            gotoxy(20, 16); cprintf(s1);
            textcolor(0); textbackground(7);
            gotoxy(20, 18); cprintf(s2);
            break;
        case 2:
            textcolor(0); textbackground(7);
            gotoxy(20, 16); cprintf(s1);
            textcolor(15); textbackground(1);
            gotoxy(20, 18); cprintf(s2);
            break;
        }
    }
}