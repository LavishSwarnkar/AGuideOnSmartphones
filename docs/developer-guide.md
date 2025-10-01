# Developer Guide

This guide provides a technical overview of the "A Guide on Smart-phones" application for developers who want to understand, modify, or contribute to the project.

## Codebase Structure

The application's source code is organized into a series of header files (`.h`) located in the `Header/` directory. This modular approach separates different functionalities, making the code easier to manage.

-   **`MAIN.cpp`**: The main entry point of the application. It includes `Header/LAVISH.h` and calls the initial functions to start the application.

-   **`Header/LAVISH.h`**: This is the top-level header file that includes all other necessary headers. It acts as a central include file for the project.

-   **`Header/MAIN.h`**: Contains the functions for the introductory screens: `welcome()`, `overview()`, `guideline()`, and the main `login()` screen.

-   **`Header/FUN.h`**: A crucial utility file that provides all the functions for rendering the text-based GUI and animations. See the "UI and Animations" section below for more details.

-   **`Header/PASS.h`**: Manages user authentication. It defines the `id` class to store user data and includes functions for account creation (`newp()`), login (`loginsub()`), password changes (`cp()`), and password recovery (`fp()`). It also contains the `admin()` function for the admin panel.

-   **`Header/MM.h`**: Implements the main menu (`mainmenu()`) that appears after a user logs in. It handles menu navigation and calls the appropriate functions based on user selection.

-   **`Header/MM2.h`**, **`Header/MM3.h`**, **`Header/MM4.h`**: These files contain the core logic for the application's features. They are structured in a way that `MM2.h` includes `MM3.h`, which in turn includes `MM4.h`.
    -   `MM2.h` contains the top-level functions for the main menu options like `info()`, `desc()`, `add()`, `filter()`, etc.
    -   `MM3.h` contains functions called by `MM2.h`, such as `history()` and `features()`.
    -   `MM4.h` contains the lowest-level functions that display the final content, such as `pro()` (for processor), `os()` (for operating system), etc. It also includes the `exite()` function.

-   **`Header/DATA.h`**: Defines the data structures used to store smartphone information, such as the `mi` class.

-   **`Header/FILTER.h`**: Contains the functions for filtering the smartphone database based on different criteria.

-   **`Header/export.h`**: Implements the functionality to export the smartphone data to an XLS file.

## UI and Animations

The application's distinctive text-based GUI is rendered using a set of custom functions in `Header/FUN.h`. These functions manipulate the console screen by printing special text characters at specific coordinates with different colors.

-   **`lcon()`**: This is one of the most important functions. It "draws" large, stylized text on the screen. It reads character patterns from `Data/text/ab.dat` and renders them character by character with an animation effect.

-   **`hbox()` and `fbox()`**: These functions draw hollow and filled boxes, respectively. They are used to create borders, windows, and other UI elements. They also have an animated drawing effect.

-   **`halfb()`**, **`upb()`**, **`downb()`**: These are used for full-screen animated transitions.

-   **`mosaic()`**: Creates a mosaic-like screen transition effect by randomly plotting characters on the screen.

The animations are achieved by using the `delay()` function to pause between drawing each part of a UI element.

## Data Management

All the data used by the application is stored in the `Data/` directory.

-   **Text Files (`.dat`)**: These files contain plain text used throughout the application.
    -   `ab.dat`: Stores the 5x5 character matrix definitions for the `lcon()` function.
    -   Other `.dat` files (`gl.dat`, `ov.dat`, `help.dat`, etc.) contain the text content for various information screens.
    -   `id.dat`: A binary file that stores the user account data.
    -   `mobinfo.dat`: A binary file that stores the smartphone database.

-   **Image Files (`.im`)**: These are not actual image files. They are text files that contain "ASCII art" representations of images, which are then rendered on the screen using special block characters.

## User Authentication

User authentication is handled by the code in `Header/PASS.h`.

-   The `id` class is used to represent a user account, storing the username, password, email, mobile number, and hint question/answer.
-   User data is stored in a binary file named `Data/text/id.dat`.
-   Functions like `newp()`, `loginsub()`, `cp()`, and `fp()` perform file I/O operations to read from and write to `id.dat`.
-   The admin functionality in `admin()` allows for viewing and deleting all records in `id.dat`.

## Main Application Logic

The application follows a clear, sequential flow:

1.  **Initialization**: `MAIN.cpp` calls `welcome()`, `overview()`, and `guideline()` to display the introductory screens.
2.  **Login**: The `login()` function is called, presenting the user with authentication options.
3.  **Main Menu**: Upon successful login, `mainmenu()` is called. This function enters a loop to handle user input for menu navigation.
4.  **Feature Execution**: Based on the user's selection in the main menu, the corresponding function from `MM2.h` is called (e.g., `info()`, `desc()`).
5.  **Sub-menus and Content**: These feature-specific functions may present further sub-menus (e.g., the `features()` menu) or display content directly by calling functions from `MM3.h` and `MM4.h`. These functions read data from the `.dat` and `.im` files and use the functions in `FUN.h` to render it on the screen.
6.  **Exit**: The `exite()` function is called when the user chooses to exit. It displays a "did you know" fact before terminating the program.