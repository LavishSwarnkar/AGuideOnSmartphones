# Installation and Setup Guide

This guide provides step-by-step instructions on how to set up and run "A Guide on Smart-phones" on your computer.

## System Requirements

To run this application, you will need the following:

- A modern operating system (Windows, macOS, or Linux).
- **DOSBox**: An emulator that creates a DOS environment. This is required to run the application's executable.
- **Turbo C++**: Required only if you want to compile the source code.

## Running the Application (Recommended)

The easiest way to run the application is by using the pre-compiled executable file with DOSBox.

### Step 1: Download the Project

First, download the project files to your local machine. You can download the zip file from the project's main page or clone the repository if you have Git installed.

### Step 2: Install DOSBox

Download and install DOSBox from the official website: [https://www.dosbox.com/download.php?main=1](https://www.dosbox.com/download.php?main=1)

Follow the installation instructions for your operating system.

### Step 3: Run the Application in DOSBox

1.  **Extract the project files**: If you downloaded a zip file, extract it to a folder on your `C:` drive. For example, `C:\smartphones`.
2.  **Launch DOSBox**: Open the DOSBox application.
3.  **Mount the project directory**: In the DOSBox command prompt, you need to mount the directory where you extracted the project files. Type the following command and press Enter:

    ```
    mount C C:\smartphones
    ```
    This command tells DOSBox to treat the `C:\smartphones` directory as the `C:` drive within the emulator.

4.  **Change to the C: drive**: Type `C:` and press Enter to switch to the mounted drive.

5.  **Run the application**: Type `MAIN` and press Enter to start the application.

    ```
    C:\> MAIN
    ```
The application should now launch, and you will see the welcome screen.

## Compiling from Source (Optional)

If you wish to modify the code or recompile the application, you will need Turbo C++.

### Step 1: Set up Turbo C++

1.  **Download Turbo C++**: You can find versions of Turbo C++ online that are packaged for modern operating systems.
2.  **Install Turbo C++**: Follow the instructions to install it on your system.

### Step 2: Compile the Code

1.  **Open Turbo C++**: Launch the Turbo C++ IDE.
2.  **Set the include and library paths**: Go to **Options > Directories** and make sure the include and library paths are set correctly for your Turbo C++ installation.
3.  **Open the source file**: Open `MAIN.cpp` in the editor.
4.  **Compile the project**: Go to **Compile > Compile** to compile the source code. If there are no errors, this will generate `MAIN.OBJ`.
5.  **Link the object files**: Go to **Compile > Link** to link the object files and create the executable `MAIN.EXE`.
6.  **Run the application**: You can run the application from within the Turbo C++ IDE by going to **Run > Run**, or you can run the newly compiled `MAIN.EXE` in DOSBox as described in the previous section.