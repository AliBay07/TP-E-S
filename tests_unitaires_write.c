#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "stdes.c"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

// La fonction de test pour iobuf_write
void test_iobuf_write() {
    // Cas de test 1: Écriture de données dans un fichier en mode écriture ('W')
    IOBUF_FILE *file1 = iobuf_open("files/test_file1.txt", 'W');
    const char *data1 = "Test data 1";
    int result1 = iobuf_write(data1, sizeof(char), strlen(data1), file1);
    iobuf_close(file1);

    // Cas de test 2: Écriture de données nulles dans un fichier en mode écriture ('W')
    IOBUF_FILE *file2 = iobuf_open("files/test_file1.txt", 'W');
    const char *data2 = NULL;
    int result2 = iobuf_write(data2, sizeof(char), 0, file2);
    iobuf_close(file2);

    // Cas de test 3: Tentative d'écriture dans un fichier en mode lecture ('R')
    IOBUF_FILE *file3 = iobuf_open("files/test_file1.txt", 'R');
    const char *data3 = "Test data 3 in read only mode";
    int result3 = iobuf_write(data3, sizeof(char), strlen(data3), file3);
    iobuf_close(file3);

    // Affichage des résultats avec la fonction d'affichage personnalisée
    iobuf_printf("Test 1: Result = %d\n", result1);
    iobuf_printf("Test 2: Result = %d\n", result2);
    iobuf_printf("Test 3: Result = %d\n", result3);
}

int main() {
    // Appel de la fonction de test
    test_iobuf_write();

    return 0;
}
