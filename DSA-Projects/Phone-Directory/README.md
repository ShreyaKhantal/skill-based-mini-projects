```md
# Contact Management System

## Overview
The **Contact Management System** is a simple C++ program that allows users to manage their contact directory. The program supports adding, removing, searching, displaying, and modifying contacts. The contacts are stored in a doubly linked list and saved to a file for persistence. It also ensures that each contact's name and phone number are unique. 

This system is useful for organizing and maintaining a contact list with operations such as searching for a contact by name, modifying an existing contact, and saving the directory to a file.

## Features
- **Add Contact**: Allows users to add new contacts by providing a name and phone number.
- **Remove Contact**: Users can remove contacts by specifying the contact's name.
- **Search for a Contact**: Find a contact by name and view the associated phone number.
- **Modify Contact**: Users can modify either the name or phone number of an existing contact.
- **Display Directory**: View the list of all contacts currently stored in the directory.
- **Save Directory**: Save the contact list to a file for future access.
- **Load from File**: The program automatically loads contacts from a file (`phone.txt`) on startup.

## System Requirements
- C++ Compiler (e.g., GCC)
- C++11 or later

## Compilation and Execution

### 1. Save the Code
Save the code in a file named `contact_manager.cpp`.

### 2. Compile the Program
To compile the program, open your terminal/command prompt and run the following command:

For **Linux/macOS**:
```bash
g++ contact_manager.cpp -o contact_manager
```

For **Windows** (using MinGW or similar):
```bash
g++ contact_manager.cpp -o contact_manager.exe
```

### 3. Run the Program
Once the program is compiled, run it as follows:

For **Linux/macOS**:
```bash
./contact_manager
```

For **Windows**:
```bash
contact_manager.exe
```

### 4. Menu Options
After running the program, you’ll be presented with the following options:

1. **Add Contact**:  
   - Prompt to enter the contact name and phone number.  
   - Ensures the name and phone number are unique in the directory.

2. **Remove Contact**:  
   - Prompt to enter the contact's name for deletion.  
   - Removes the contact from the directory if found.

3. **Search Number**:  
   - Prompt to enter the name of the contact you want to search for.  
   - Displays the phone number associated with the contact.

4. **Display Directory**:  
   - Displays all the contacts currently stored in the directory.

5. **Modify Contact**:  
   - Prompt to modify either the contact's name or phone number.

6. **Save to Directory**:  
   - Saves the current contact directory to the file `phone.txt`.

7. **Exit**:  
   - Exits the program.

### 5. File Persistence
- The contact directory is saved to a file named `phone.txt`.
- On startup, the program automatically loads the contacts from this file into memory.
- If the file does not exist, the program starts with an empty directory.

### 6. Error Handling
- The program checks for:
  - **Duplicate names**: If a name already exists, it prompts the user to enter a different name.
  - **Duplicate phone numbers**: Ensures no two contacts share the same phone number.
  - **Invalid phone numbers**: Only 10-digit numbers are accepted.

## Example Usage

**Add a Contact**:
```
Enter Name: John Doe
Enter Number: 1234567890
Contact Added
```

**Search a Contact**:
```
Enter Name: John Doe
Number: 1234567890
```

**Modify a Contact**:
```
Enter 0 to modify name and 1 to modify number: 1
Enter Name for number to be modified: John Doe
Enter Modified Number: 0987654321
```

**Display Directory**:
```
John Doe : 1234567890
Jane Doe : 0987654321
```

**Remove a Contact**:
```
Enter Name to remove: John Doe
Contact Deleted
```

## File Format

The contact data is saved to `phone.txt` in the following format:
```
John Doe 1234567890
Jane Doe 0987654321
```

## Contributing

Feel free to fork this project and make improvements! If you have any suggestions or find bugs, please create an issue or submit a pull request.
