# A Guide on Smart-phones - Documentation

Welcome to the official documentation for "A Guide on Smart-phones," a Turbo C++ application that provides a comprehensive guide to smartphones in a unique, text-based GUI.

This documentation is designed to help both users and developers understand the application in depth.

## Table of Contents

- [Installation and Setup](./installation.md)
- [User Guide](./user-guide.md)
- [Developer Guide](./developer-guide.md)
- [API Reference](./api-reference.md)

## Project Overview

"A Guide on Smart-phones" is a C++ application that runs in a DOS environment and simulates a graphical user interface using only text characters. It was developed in Turbo C++ and showcases a variety of creative programming techniques to deliver an interactive and animated user experience.

The application allows users to:
- Browse a database of smartphones.
- View detailed specifications for each phone.
- Filter smartphones based on various criteria.
- Add new smartphone data to the application.
- Export data to an XLS file.

## Application Architecture

The application is built using a modular structure, with different functionalities separated into various header files. Here is a high-level overview of the architecture:

- **Entry Point (`MAIN.cpp`)**: The application starts here, initializing the main components and calling the initial sequence of functions.
- **UI and Animations (`Header/FUN.h`)**: A core module that provides functions for rendering all the UI elements, including boxes, animated text, and screen transitions.
- **User Authentication (`Header/PASS.h`)**: Manages user accounts, including creation, login, password changes, and recovery.
- **Main Menu (`Header/MM.h`)**: The central navigation hub of the application, which appears after the user logs in.
- **Application Features (`Header/MM2.h`, `Header/MM3.h`, `Header/MM4.h`)**: These files contain the logic for the main features of the application, such as displaying smartphone information, filtering, and data management.
- **Data (`Data/`)**: A directory containing all the data files used by the application. This includes text for UI elements, images represented as text, and the smartphone database.