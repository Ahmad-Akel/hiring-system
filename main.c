#include <stdio.h>
/**
 *The main idea
The personnel agency needs a SW tool for managing its agenda for its effective operation. To this end, it maintains two basic ones
lists (linear list). The first maintains a list of candidates seeking work, the second the individual job positions offered by companies.
Data for these lists can be imported from a CSV file. If a recruitment agency recommends someone for an interview, they register them
in the dynamic field of interviews.
**/
int main() {
/**
* Main module
The main file of the main.c program contains the logic for editing the interview and also the menu for calling the functions of the agenda module.
Main menu
1. Load the data into the list of candidates / positions from the CSV file
2. Write a list of candidates / positions
3. Add the candidate / position to the list from the keyboard
4. Remove the candidate / position from the list
5. Cancel the list of candidates / positions
6. Find a candidate / position
7. Add an interview
8. Edit the interview status
9. List interviews
10. Exit the program - necessary allocation of all allocated memory resources
**/
    printf("1-Nacti data do seznamu kandidatu/pozic ze souboru CSV\n");
    printf("2-Vypis seznam kandidatu/pozic\n");
    printf("3-Pridej z klavesnice kandidata/pozici do seznamu\n");
    printf("4-Odeber kandidata/pozici ze seznamu\n");
    printf("5-Zrus seznam kandidata/pozic\n");
    printf("6-Najdi kandidata/pozici\n");
    printf("7-Pridej pohovor\n");
    printf("8-Edituj stav pohovoru\n");
    printf("9-Vypis pohovory\n");
    printf("10-Ukoncit program – nutna dealokace vsech alokovanych pametovych prostredku\n");
    return 0;
}
