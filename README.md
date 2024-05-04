# GUI_Text_Editor

## GTK+ Text Editor
This is a simple text editor application built using the GTK+ toolkit and the C programming language. The editor provides a basic graphical user interface (GUI) with functionality to open, save, and edit text files.

## Features
- Open existing text files
- Save text files
- Edit text content
- Quit the application

## Requirements

- GTK+ 3 or higher
- A C compiler (e.g., GCC)
- A Unix-based operating system (e.g., Linux, macOS) or Windows with a Unix-like environment (e.g., Cygwin, MinGW)

## Building

1. Ensure that you have GTK+ and its development files installed on your system.
2. Compile the source code using a C compiler with GTK+ support:

_``gcc -o text-editor main.c `pkg-config --cflags --libs gtk+-3.0``_
This command will produce an executable named text-editor.

## Running
To run the text editor application, execute the compiled binary:

_`./text-editor`_

## Usage
Upon launching the application, you will see the main window with a menu bar containing the following options:

## -File
   **- Open:** Open a file chooser dialog to select and open a text file.
   
   **- Save:** Open a file chooser dialog to save the contents of the text view.
   
   **- Quit:** Exit the text editor application.
   
Use the menu options to perform the respective actions.

## Contributing
Contributions to enhance the functionality of this text editor are welcome. If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request.
# License
This project is released under the MIT License.
