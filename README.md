# Library Management System

## Overview
This is a simple **Library Management System** implemented in C++. It allows users to manage different types of library items, including **Books, Magazines, and DVDs**. The system provides functionalities to **add, borrow, return, and display** available items.

## Features
- **Add** books, magazines, and DVDs to the library.
-  **Display** available library items.
-  **Borrow** items if they are available.
-  **Return** borrowed items to the library.
-  **Simple console-based UI** for easy interaction.

## Classes Structure
- **LibraryItem**: Base class for all library items.
- **Book, Magazine, DVD**: Inherit from `LibraryItem` with specific attributes.
- **LibrarySystem**: Manages the collection of books, magazines, and DVDs.

## **Object-Oriented Programming (OOP) Concepts:**  
  - **Encapsulation**: Data members are private, accessed through getter/setter functions.  
  - **Constructors & Destructors**: Used for initialization and memory management.  
  - **Inheritance**: `Book`, `Magazine`, and `DVD` inherit from `LibraryItem`.  
  - **Static Member Functions**: Used for shared functionality across instances.  
  - **Data Hiding**: Restricting direct access to data members.  
  - **Array of Pointers to Objects**: Managing dynamic collections of items.  

## How to Use
1. **Compile and run** the program.
2. Choose an option from the menu:
   - Add new items.
   - Borrow an item if it's available.
   - Return a borrowed item.
   - Display all available items.
3. Enter the required details as prompted.

## Technologies Used
- **Programming Language**: C++
- **Paradigm**: Object-Oriented Programming (OOP)

## License
This project is open-source and free to use.

 Happy coding!

