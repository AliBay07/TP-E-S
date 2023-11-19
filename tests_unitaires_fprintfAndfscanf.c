#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "stdes.c"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

void test_iobuf_fscanfAndfprintf(){
    IOBUF_FILE *file = iobuf_open("files/test_file1.txt", 'W');
    /*// Écriture de données dans le fichier avec fprintf
    iobuf_fprintf(file, "Test fprintf: %s %d %c\n", "Hello", 42, 'A');
    iobuf_close(file);

    // Lecture des données depuis le fichier
    file = iobuf_open("files/test_file1.txt", 'R');
    char str[100];
    int num;
    char character;
    //lecture depuis le fichier dans str
    iobuf_fscanf(file, "Test fprintf: %s %d %c", str, &num, &character);
    iobuf_printf("Résultats de la lecture fscanf: %s %d %c\n", str, num, character);
    iobuf_close(file);
    iobuf_flush(file);*/
    // Test avec iobuf_fprintf pour écrire des nombres dans un fichier
    file = iobuf_open("files/test_file1.txt", 'W');
    iobuf_fprintf(file, "Nombres : %d\n", 123, "Hello");
    iobuf_close(file);

    // Lecture des nombres depuis le fichier avec iobuf_fscanf
    file = iobuf_open("files/test_file1.txt", 'R');
    int intVal;
    iobuf_fscanf(file, "Nombres : %d", &intVal);
    iobuf_printf("Lecture des nombres : %d\n", intVal);
    iobuf_close(file);

    //PORBLEME INTVAL EST INITIALIS2 AVEC VAL ALEATOIRES ET CONCATENATION DES NB LUS? IL FAUT REMPLACER
}

int main()
{
    test_iobuf_fscanfAndfprintf();
    return 0;
}