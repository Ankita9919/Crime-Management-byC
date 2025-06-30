#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CRIMES 100

struct Crime {
    int id;
    char description[100];
    char location[50];
    char date[15];  
    char status[20]; 
};

struct Crime crimes[MAX_CRIMES];
int crime_count = 0;

void addCrime();
void viewAllCrimes();
void searchCrime();
void deleteCrime();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addCrime(); break;
            case 2: viewAllCrimes(); break;
            case 3: searchCrime(); break;
            case 4: deleteCrime(); break;
            case 5: printf("Exiting the system. Goodbye!\n"); exit(0);
            default: printf("Invalid choice. Try again!\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Crime File Management System ---\n");
    printf("1. Add New Crime\n");
    printf("2. View All Crimes\n");
    printf("3. Search for a Crime\n");
    printf("4. Delete a Crime Record\n");
    printf("5. Exit\n");
}

void addCrime() {
    if (crime_count >= MAX_CRIMES) {
        printf("Error: Cannot add more crimes. Memory full!\n");
        return;
    }
    struct Crime newCrime;
    newCrime.id = crime_count + 1;

    printf("Enter Crime Description: ");
    getchar();
    fgets(newCrime.description, sizeof(newCrime.description), stdin);
    strtok(newCrime.description, "\n");

    printf("Enter Location: ");
    fgets(newCrime.location, sizeof(newCrime.location), stdin);
    strtok(newCrime.location, "\n");

    printf("Enter Date (DD-MM-YYYY): ");
    fgets(newCrime.date, sizeof(newCrime.date), stdin);
    strtok(newCrime.date, "\n");

    printf("Enter Status (Pending/Resolved): ");
    fgets(newCrime.status, sizeof(newCrime.status), stdin);
    strtok(newCrime.status, "\n");

    crimes[crime_count] = newCrime;
    crime_count++;
    printf("Crime Record Added Successfully! Crime ID: %d\n", newCrime.id);
}

void viewAllCrimes() {
    if (crime_count == 0) {
        printf("No crime records available.\n");
        return;
    }
    printf("\n--- All Crime Records ---\n");
    for (int i = 0; i < crime_count; i++) {
        printf("ID: %d\n", crimes[i].id);
        printf("Description: %s\n", crimes[i].description);
        printf("Location: %s\n", crimes[i].location);
        printf("Date: %s\n", crimes[i].date);
        printf("Status: %s\n", crimes[i].status);
        printf("---------------------------\n");
    }
}

void searchCrime() {
    int id;
    printf("Enter Crime ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < crime_count; i++) {
        if (crimes[i].id == id) {
            printf("\n--- Crime Details ---\n");
            printf("ID: %d\n", crimes[i].id);
            printf("Description: %s\n", crimes[i].description);
            printf("Location: %s\n", crimes[i].location);
            printf("Date: %s\n", crimes[i].date);
            printf("Status: %s\n", crimes[i].status);
            return;
        }
    }
    printf("Crime with ID %d not found.\n", id);
}

void deleteCrime() {
    int id, found = 0;
    printf("Enter Crime ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < crime_count; i++) {
        if (crimes[i].id == id) {
            found = 1;
            for (int j = i; j < crime_count - 1; j++) {
                crimes[j] = crimes[j + 1];
            }
            crime_count--;
            printf("Crime record with ID %d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Crime with ID %d not found.\n", id);
    }
}