Developer Doc
Getting Started
The “Wallet App” is a combination of functions written in C and compiled with GCC as a
command line program that uses file handling and dynamic memory allocation to store and
show relevant data upon user request directly from CMD and updates the edit/updates to
existing .txt file to store the data.
Functions
main()
The main function runs when the program starts, and it redirect to other functions and make the
program run.
menu()
it uses switch and cases to redirect the program to different functions and system(“cls”) to clear
the screen and system(“pause”) to pause the program.
load()
this function loads the data from transactions.dat to linked list using dynamic memory allocation
and creates a dynamic database for users to use while using the program.
save()
the save() function saves the dynamic database from the allocated memory to transactions.dat
file when user close the function using menu. It is used to load the previous data after user
reopen the program.
see()
This function used to make the wallet.txt file visible to users using pointers and file handling
using the menu driven method.display()
this function gets the data from memory that is structured as a linked list prints the linked list and
also prints a calculated amount of Incomes, Expenses and Total of the incomes minus
Expenses.
sort()
this function is used to sort the transactions.dat file into a Ascending order to show the mostly
expensive transaction and cheapest item on the list using sorted link list stored in memory and
for display, it’s reusing the display() function.
create()
this function is used to take input from the user to add a new transaction and as an Income or
Expense based on user selection and it used time.h to automatically get the current time on
user's operating system.
It’s using a linked list and structure to store data on dynamic memory.
