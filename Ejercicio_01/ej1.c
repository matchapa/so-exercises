#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* string_concat(const char * c1, const char * c2){
    char * result = (char*) malloc(strlen(c1) + strlen(c2) + 1);
    if (!result) {
        printf("Error: no se pudo asignar memoria\n");
        return NULL; // Manejo de error: no se pudo asignar memoria
    }

    strcpy(result, c1);
    strcat(result, c2);
    return result;
}  


void string_concat_dinamyc(const char* c1, const char* c2 , char** concat){
    *concat = (char*) malloc(strlen(c1) + strlen(c2) + 1);
    
    if(! *concat){
        printf("Error: no se pudo asignar memoria\n");
        return; // Manejo de error: no se pudo asignar memoria
    }

    *concat = string_concat(c1, c2);
}


void mail_split(const char* mail, char** user, char** dominio){
    if(!mail){
        printf("Error: el correo electrónico es nulo\n");
        return; // Manejo de error: el correo electrónico es nulo
    } 
    char* at = strchr(mail, '@');
    if(!at){
        printf("Error: el correo electrónico no contiene un '@'\n");
        return; // Manejo de error: el correo electrónico no contiene un '@'
    }
    int user_len = at - mail;
    int domain_len = strlen(at + 1); //Se le agrega +1 para ignorar el '@'

    *user = (char*) malloc(user_len + 1);
    *dominio = (char*) malloc(domain_len + 1);
    if(!*user || !*dominio){
        printf("Error: no se pudo asignar memoria\n");
        return; // Manejo de error: no se pudo asignar memoria
    }
    
    strncpy(*user, mail, user_len);
    (*user)[user_len] = '\0'; // Asegurarse de que el string esté terminado en nulo
    strcpy(*dominio, at + 1); // Copiar el dominio
    (*dominio)[domain_len] = '\0'; // Asegurarse de que el string esté terminado en nulo
    
    return;
}


void main(){
    const char* nombre = "Matias ", * nombre2 = "Daniel ";
    const char* apellido = "Chaparro";
    const char* mail = "matchaparro15@gmail.com";
    char* user, * dominio;

    //Ejercicio 1
    char* nombre_y_apellido = string_concat("Matias ", apellido);
    printf("Ej1: %s\n", nombre_y_apellido); // Imprime "Matias Chaparro"
    
    //Ejercicio 2
    char * nombre_completo;
    string_concat_dinamyc("Matias ", nombre2, &nombre_completo);
    string_concat_dinamyc(nombre_completo, apellido, &nombre_completo);

    printf("Ej2: %s\n", nombre_completo); // Imprime "Matias Daniel Chaparro"

    //Ejercicio 3
    mail_split(mail, &user, &dominio);
    printf("User: %s\n", user); // Imprime "matchaparro15"
    printf("Dominio: %s\n", dominio); // Imprime "gmail.com"

    return; 
}