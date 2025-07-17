<h1 align="center">Telephone Directory Management System</h1>
<br>
<h2>Description</h2>
The Telephone Directory Management System is a C++ console-based project designed to manage and organize personal or organizational contact information. The project leverages fundamental programming concepts such as arrays, functions, file handling, loops, and conditional statements to enable users to store, search, update, delete, and sort contacts efficiently.
<br><br>
<h2>Restrictions and Constraints</h2>
Since this is a first-semester project, the following concepts were <b><i>not</i></b> allowed:-
<ol>
  <li><b>Object-Oriented Programming (OOP):</b></li>
   - No classes or objects.
  <li><b>Dynamic Memory Allocation:</b></li>
   - No use of pointers or dynamic arrays.
  <li><b>Advanced Data Structures:</b></li>
   - No use of vectors, linked lists, or any STL containers.
  <li><b>Complex File Handling:</b></li>
   - Only basic file I/O (text files) was allowed.
  <li><b>External Libraries:</b></li>
   - The solution is implemented without any third-party libraries, relying solely on C++ standard libraries.
  <li><b>Other Restrictions:</b></li>
   - No structs or enums.
  <br>
   - No recursion or advanced algorithms.
</ol>
Despite these restrictions, the project successfully implements all required functionalities demonstrating how basic programming principles can solve real-world problems and automate manual tasks like maintaining contact records.
<br><br>
<h2>Features</h2>
<ul>
  <li><b><i>Add Contact:</i></b> Allows users to add a new contact with details like name, address, and phone numbers.</li>
  <li><b><i>Search Contact:</i></b> Search contacts based on a given pattern in fields like name, address, or phone numbers.</li>
  <li><b><i>Update Contact:</i></b> Modify details of an existing contact.</li>
  <li><b><i>Delete Contact</i></b>: Remove a contact from the directory.</li>
  <li><b><i>Sort Contacts:</i></b> Sort contacts by first name, last name, cell phone, or landline.</li>
  <li><b><i>Display Contacts by Pattern:</i></b> Print contacts that match a specific user-entered pattern across selected fields.</li>
  <li><b><i>View All Contacts:</i></b> Display all stored contacts.</li>
  <li><b><i>Persistent Storage:</i></b> Contact details are stored in a text file (`Contacts.txt`) for later use.</li>
</ul>
<br>
<h2>How It Works</h2>
<ol>
   <li><b>Data Input:</b></li>
  
   - Contacts are stored in 2-Dimensional character arrays (c-strings).
   - Each operation modifies the arrays and saves changes to the text file.
   <li><b>Key Functions:</b></li>
  
   - `AddContact()`: Adds a new contact and appends it to the file.
   - `SearchContact()`: Allows pattern-based searching in contact fields.
   - `UpdateContact()`: Modifies existing contact details.
   - `DeleteContact()`: Removes a contact from the directory.
   - `SortContacts()`: Implements bubble sort for organizing contacts.
   - `DisplayPattern()`:
      - Prints all contacts where a specific **user-provided pattern** matches any part of a field such as **first name, last name, address, cell number**, or **landline number**.
      - This helps users find contacts more efficiently by allowing partial matching.
   <li><b>File Handling:</b></li>
   
   - The project uses basic file I/O operations to read and write contact data to `Contacts.txt`.
</ol>
<br>
<h2>File Structure</h2>
Telephone-Directory-Management-System/
<br>
├── Contacts.txt ---> Stores contact details
<br>
├── Telephone_Directory_Management_System.cpp ---> Main C++ source file
<br>
├── README.md ---> Project documentation
