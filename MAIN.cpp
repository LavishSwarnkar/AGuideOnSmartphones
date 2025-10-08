#include "menu.h"

// The main function serves as the entry point of the application.
// It orchestrates the initial sequence of screens that the user sees,
// starting from the welcome animation and leading up to the login interface.
int main() {
    // Display the initial welcome screen with animations.
    menu::displayWelcomeScreen();

    // Show a brief overview of the application.
    menu::displayOverview();

    // Provide guidelines to the user on how to navigate the application.
    menu::displayGuidelines();

    // Present the login screen to the user.
    menu::displayLoginScreen();

    return 0;
}