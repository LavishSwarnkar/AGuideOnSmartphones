# API Reference

This document provides a detailed reference for the major functions and classes in the "A Guide on Smart-phones" application, organized by the header file in which they are defined.

## `Header/FUN.h` - UI and Animation Functions

This file contains all the core functions for rendering the text-based GUI and creating animations.

| Function                                             | Description                                                                                                |
| ---------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| `halfb(int t, int l, int r, int b, int c, int d)`      | Draws an animated box that fills from the center outwards. Used for screen transitions.                    |
| `downb(int c)`                                       | Creates a screen wipe animation from top to bottom.                                                        |
| `upb(int c)`                                         | Creates a screen wipe animation from bottom to top.                                                        |
| `hbox(t, l, r, b, p, c, bg, d)`                       | Draws an animated **h**ollow **box** on the screen. Used for creating borders and windows.                 |
| `fbox(t, l, r, b, p, c, bg, d)`                       | Draws an animated **f**illed **box** on the screen.                                                        |
| `lcon(char s[], int x, int y, int c, int bg)`          | Renders **l**arge, animated text (**con**sole text). It reads character patterns from `Data/text/ab.dat`.    |
| `mosaic(int c)`                                      | Creates a mosaic-like screen transition effect.                                                            |

## `Header/MAIN.h` - Introductory and Login Screens

This file contains the functions that control the initial flow of the application.

| Function      | Description                                                               |
| ------------- | ------------------------------------------------------------------------- |
| `welcome()`   | Displays the initial animated welcome screen with the project title.      |
| `overview()`  | Displays a screen with a brief overview of the application's features.    |
| `guideline()` | Displays a screen with guidelines on how to navigate and use the app.     |
| `login()`     | The main login menu. It handles user input for logging in, creating an account, etc. |

## `Header/PASS.h` - User Authentication

This file manages all aspects of user authentication and account management.

### `id` Class
A class that represents a user account.
- `un`: username
- `pass`: password
- `email`: email address
- `mono`: mobile number
- `hintq`: hint question
- `hinta`: hint answer

### Functions

| Function          | Description                                                              |
| ----------------- | ------------------------------------------------------------------------ |
| `acchk(char s[])` | **Ac**count **ch**ec**k**. Checks if a user account with the given username exists. |
| `input(id &i1)`   | Prompts the user to input their details to create or update an account.  |
| `print(id i1)`    | Prints the details of a given user account to the screen.                |
| `pall()`          | **P**rint **all**. An admin function to print all user accounts.         |
| `delall()`        | **Del**ete **all**. An admin function to delete all user accounts.       |
| `admin()`         | The main function for the admin panel.                                   |
| `newp()`          | **New** **p**rofile. Creates a new user account.                         |
| `loginsub()`      | **Login** **sub**-routine. Handles the user login process.               |
| `cp()`            | **C**hange **p**assword. Allows a logged-in user to change their password. |
| `fp()`            | **F**orgot **p**assword. Handles the password recovery process.          |

## `Header/MM.h` - Main Menu

This file contains the main menu of the application.

| Function     | Description                                                                                                   |
| ------------ | ------------------------------------------------------------------------------------------------------------- |
| `mainmenu()` | The core function for the main menu. It displays the menu options, handles user navigation, and calls the appropriate feature functions. |

## `Header/MM2.h` - Main Feature Functions

This file contains the high-level functions for the main features of the application.

| Function   | Description                                                                |
| ---------- | -------------------------------------------------------------------------- |
| `help()`   | Displays the help screen with navigation instructions.                     |
| `about()`  | Displays the "About" screen with information about the project.            |
| `info()`   | The menu for the "Smartphone Information" section (History and Features).  |
| `desc()`   | The menu for browsing "Some Popular Smartphones Description" by brand.     |
| `add()`    | The menu for adding, modifying, or exporting smartphone data.              |
| `filter()` | The main function for the "Smart Phones Filtering" feature.                |
| `sta()`    | Displays the application **sta**tus (total number of phones in the database). |
| `ama()`    | Displays the **Ama**ze Me section with fun facts.                          |

## `Header/MM3.h` - Sub-Feature Functions

This file contains the functions for the sub-menus.

| Function     | Description                                                          |
| ------------ | -------------------------------------------------------------------- |
| `history()`  | Displays the history of smartphones, reading from data files.        |
| `features()` | The menu for browsing the different features of smartphones (Processor, OS, etc.). |

## `Header/MM4.h` - Content Display Functions

This file contains the functions that display the final content to the user.

| Function                               | Description                                                                |
| -------------------------------------- | -------------------------------------------------------------------------- |
| `pimage(st, c, x, y)`                  | **P**rints an **image** (ASCII art) from a specified file.                 |
| `ptext(st, c, x, y, tb, t)`            | **P**rints formatted **text** from a specified file.                       |
| `pro()`, `os()`, `mem()`, `bat()`, etc. | Functions that display information about a specific smartphone feature.    |
| `exite()`                              | Displays a "did you know" fact and then **exit**s the application.         |