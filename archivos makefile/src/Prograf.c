#include <termios.h>
#include <stdio.h>
#include <math.h>

#include <malloc.h>
#include <string.h>
 
#include "stdlib.h"
#include <unistd.h>
#include <fcntl.h>

#define red "\033[0;31m"
#define cyan  "\033[0;36m"        
#define green "\033[0;32m"        
#define blue  "\033[0;34m"        

 #define black  "\033[0;30m"
#define brown  "\033[0;33m"
#define magenta  "\033[0;35m"
#define gray  "\033[0;37m"
#define none   "\033[0m"

void Transformar(){
	
	char Opcion;

    
    while(1){
    system("clear");
    printf("%s                    -----------------------------------------------------------------------------------------   \n",red);
    printf("%s                   |                     *************EFECTO DE SONIDO*************                          |  \n",red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s1.Ardillas                                                                          %s|   \n",red,brown,red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s2.Darth Vader                                                                       %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                   |     %s3.Eco                                                                               %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                   |     %s4.Salir                                                                             %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);

    printf("%s                    -----------------------------------------------------------------------------------------  \n\n",red);
    
    printf("%s                        Opcion: ",green);
    printf("%s",none);
    scanf("%s", &Opcion);
    
    switch(Opcion){
        
        case '1':
        system ("clear");
        system ("gst-launch-0.10 filesrc location=sonido.ogg ! decodebin ! audioconvert ! pitch tempo=0.8 pitch=1.2 rate=1.2 output-rate=1.2 ! audioconvert ! audioresample ! alsasink");
        break;
        
        case '2': 
        system("clear");
        system ("gst-launch-0.10 filesrc location=sonido.ogg ! decodebin ! audioconvert ! pitch tempo=0.8 pitch=0.9 rate=0.9 output-rate=0.9 ! audioconvert ! audioresample ! alsasink");
        break;
        
        case '3': 
        system("clear");
        system ("gst-launch-0.10 filesrc location=sonido.ogg ! decodebin ! audioconvert ! pitch tempo=1 pitch=1 rate=1 output-rate=1 ! audioecho intensity=0.6 feedback=0.4 delay=400000000 ! audioconvert ! audioresample ! alsasink");
        break;
        
        case '4':
        system("clear");
        return;
        break;
        
        default: printf("                      Opcion Invalida!!\n"); sleep(1);
        
}

}

}

int main(){
	
  
	
	char Opcion;
	
    while(1){
	//sleep(5);
    system("clear");
    printf("%s                    -----------------------------------------------------------------------------------------   \n",red);
    printf("%s                   |                               ***SINTETIZADOR DE VOZ***                                 |  \n",red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s1.Grabar Sonido                                                                     %s|   \n",red,brown,red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s2.Salir                                                                             %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                    -----------------------------------------------------------------------------------------  \n\n",red);
    
    printf("%s                        Opción: ",green);
    printf("%s",none);
    scanf("%s", &Opcion);
    
    switch(Opcion){
        
        case '1':
        system ("clear");
        system ("gst-launch-0.10 alsasrc ! audioconvert ! audioresample ! vorbisenc ! oggmux ! filesink location=sonido.ogg"); 
        system ("clear");
        Transformar();
        break;
        
        
        case '2':
        system("clear");
        return(0);
        break;
        
        default: printf("                      Opción Inválida!!\n"); 
        sleep(1);
        
}

}
	
	
	
	
	
	
 }
