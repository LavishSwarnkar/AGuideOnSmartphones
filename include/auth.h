#ifndef AUTH_H
#define AUTH_H

#include <fstream>
#include <iostream>
#include <string.h>
#include "ui.h"

class User {
private:
    char username[12];
    char password[12];
    char email[30];
    char mobile_number[20];
    char hint_question[20];
    char hint_answer[20];

public:
    void setUsername(const char* name);
    void setPassword(const char* pass);
    void setEmail(const char* mail);
    void setMobileNumber(const char* mobile);
    void setHintQuestion(const char* question);
    void setHintAnswer(const char* answer);

    char* getUsername();
    char* getPassword();
    char* getEmail();
    char* getMobileNumber();
    char* getHintQuestion();
    char* getHintAnswer();
};

// Function prototypes
void loginScreen();
void registerNewUser();
void loginUser();
void changePassword();
void forgotPassword();
void adminMenu();
bool doesUserExist(const char* username);
void mainMenu();

#endif // AUTH_H