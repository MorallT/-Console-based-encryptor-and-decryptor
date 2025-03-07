This project is a simple console-based application written in C++ that provides encryption and decryption of passwords using a basic character-shifting method. The program allows users to securely store passwords in text files, retrieve them when needed, and change them through authentication.

Features

Encryption (Encoding to File):

The user inputs a password, which is then encrypted using a basic shift cipher (+15 ASCII shift).

The encrypted password is stored in a text file for future retrieval.

Decryption (Decoding from File):

The stored encrypted password is read from the file.

The password is decrypted by reversing the shift operation (-15 ASCII shift) and displayed to the user.

Change Password Functionality:

The user is prompted to enter their current password.

If the password matches the stored password, the user can set a new password.

The new password is then encrypted and stored in the file.

How It Works

The user selects an option from the menu:

1 for encryption

2 for decryption

3 to change the password

The user provides the filename where the password will be stored.

Based on the chosen option, the program either encrypts and saves, decrypts and displays, or updates the password.

File Handling

Passwords are saved in .txt files using binary mode.

Encrypted passwords prevent direct readability in the text file.

The program ensures proper file handling with error messages for missing or inaccessible files.

Technologies Used

Programming Language: C++

File Handling: fstream for reading and writing encrypted passwords

Encryption Method: Simple character shift-based encoding (+15 ASCII shift)

Console Interaction: User input handling with getline()

Known Issues & Improvements

The filename extension is mistakenly referenced as .tx instead of .txt in decodeFromFile().

A more advanced encryption method could be implemented for increased security.

Error handling could be improved to manage invalid inputs and prevent crashes.

The program currently lacks a way to prevent unauthorized file access.

Conclusion

This project provides a simple yet effective way to store and manage encrypted passwords. While the current implementation is basic, it demonstrates fundamental encryption, file handling, and authentication concepts in C++. Future enhancements could include stronger encryption algorithms, better error handling, and a GUI for improved usability.
