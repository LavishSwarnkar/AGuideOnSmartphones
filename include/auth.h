#ifndef AUTH_H
#define AUTH_H

#include <string>

namespace auth {

class User {
private:
    std::string username;
    std::string password;
    std::string email;
    std::string mobile_number;
    std::string hint_question;
    std::string hint_answer;

public:
    void setUsername(const std::string& name);
    void setPassword(const std::string& pass);
    void setEmail(const std::string& mail);
    void setMobileNumber(const std::string& mobile);
    void setHintQuestion(const std::string& question);
    void setHintAnswer(const std::string& answer);

    std::string getUsername() const;
    std::string getPassword() const;
    std::string getEmail() const;
#include <fstream>

    std::string getMobileNumber() const;
    std::string getHintQuestion() const;
    std::string getHintAnswer() const;

    void serialize(std::ofstream& fout) const;
    void deserialize(std::ifstream& fin);
};

// Function prototypes
void loginScreen();
void registerNewUser();
void loginUser();
void changePassword();
void forgotPassword();
void adminMenu();
bool doesUserExist(const std::string& username);
void mainMenu();

} // namespace auth

#endif // AUTH_H