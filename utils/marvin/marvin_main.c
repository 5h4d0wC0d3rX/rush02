#include <unistd.h>
#include <fcntl.h>

void displayMenuAndGetNumber() {
    int choice;
    char buffer[100];
    char numberBuffer[100];

    // Liste des dictionnaires disponibles
    const char* dictionaries[] = {
        "English",
        "French",
        "Dothraki",
        "Minion",
        "Leet Speak",
        "Quenya (Elvish)",
        "Sindarin (Elvish)",
        "Black Speech (Mordor)",
        "Na'vi (Avatar)",
        "Ancient Greek",
        "Egyptian Hieroglyphs",
        "Old Norse",
        "Morse Code",
        "Russian",
        "Mayan",
        "Sumerian"
    };
    int numDictionaries = sizeof(dictionaries) / sizeof(dictionaries[0]);

    // Afficher le menu
    const char *menuMessage = "Please choose a dictionary by entering the corresponding number:\n";
    write(STDOUT_FILENO, menuMessage, 64); // La longueur de cette chaîne est 64
    int i = 0;
    while (i < numDictionaries) {
        char line[100];
        int len = 0;
        
        // Convertir l'entier en chaîne de caractères
        if (i == 0) {
            line[len++] = '0';
        } else {
            int temp = i;
            char tempBuffer[10];
            int tempLen = 0;
            while (temp > 0) {
                tempBuffer[tempLen++] = (temp % 10) + '0';
                temp /= 10;
            }
            // Inverser la chaîne
            while (tempLen > 0) {
                line[len++] = tempBuffer[--tempLen];
            }
        }

        line[len++] = ':';
        line[len++] = ' ';

        // Ajouter le nom du dictionnaire
        const char *dictName = dictionaries[i];
        while (*dictName != '\0') {
            line[len++] = *dictName++;
        }
        line[len++] = '\n';

        write(STDOUT_FILENO, line, len);
        i++;
    }

    // Demander à l'utilisateur de choisir un dictionnaire
    const char *promptMessage = "Enter the number of the dictionary you want to choose: ";
    write(STDOUT_FILENO, promptMessage, 49); // La longueur de cette chaîne est 49

    ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';
        choice = 0;
        int j = 0;
        while (buffer[j] >= '0' && buffer[j] <= '9') {
            choice = choice * 10 + (buffer[j] - '0');
            j++;
        }

        if (choice >= 0 && choice < numDictionaries) {
            char choiceMessage[100];
            int len = 0;

            // Ajouter le message de choix
            const char *choiceMsg = "You have chosen the ";
            while (choiceMsg[len] != '\0') {
                choiceMessage[len] = choiceMsg[len];
                len++;
            }

            // Ajouter le nom du dictionnaire choisi
            const char *chosenDict = dictionaries[choice];
            while (*chosenDict != '\0') {
                choiceMessage[len++] = *chosenDict++;
            }
            choiceMessage[len++] = ' ';
            choiceMessage[len++] = 'd';
            choiceMessage[len++] = 'i';
            choiceMessage[len++] = 'c';
            choiceMessage[len++] = 't';
            choiceMessage[len++] = 'i';
            choiceMessage[len++] = 'o';
            choiceMessage[len++] = 'n';
            choiceMessage[len++] = 'a';
            choiceMessage[len++] = 'r';
            choiceMessage[len++] = 'y';
            choiceMessage[len++] = '.';
            choiceMessage[len++] = '\n';

            write(STDOUT_FILENO, choiceMessage, len);
        } else {
            const char *invalidMessage = "Invalid choice. Please run the program again and choose a valid number.\n";
            write(STDOUT_FILENO, invalidMessage, 75); // La longueur de cette chaîne est 75
            return;
        }
    }

    // Demander à l'utilisateur d'écrire un chiffre
    const char *numberPrompt = "Please enter a number to convert using the chosen dictionary: ";
    write(STDOUT_FILENO, numberPrompt, 63); // La longueur de cette chaîne est 63

    bytesRead = read(STDIN_FILENO, numberBuffer, sizeof(numberBuffer) - 1);
    if (bytesRead > 0) {
        numberBuffer[bytesRead] = '\0';
        int number = 0;
        int j = 0;
        while (numberBuffer[j] >= '0' && numberBuffer[j] <= '9') {
            number = number * 10 + (numberBuffer[j] - '0');
            j++;
        }
        char numberMessage[100];
        int len = 0;

        // Ajouter le message du nombre
        const char *numberMsg = "You entered the number: ";
        while (numberMsg[len] != '\0') {
            numberMessage[len] = numberMsg[len];
            len++;
        }

        // Convertir le nombre en chaîne de caractères
        if (number == 0) {
            numberMessage[len++] = '0';
        } else {
            char tempBuffer[10];
            int tempLen = 0;
            int temp = number;
            while (temp > 0) {
                tempBuffer[tempLen++] = (temp % 10) + '0';
                temp /= 10;
            }
            // Inverser la chaîne
            while (tempLen > 0) {
                numberMessage[len++] = tempBuffer[--tempLen];
            }
        }
        numberMessage[len++] = '\n';

        write(STDOUT_FILENO, numberMessage, len);
        // Ici, vous pouvez ajouter du code pour convertir et afficher le nombre dans le dictionnaire choisi
    }
}