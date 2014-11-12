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

void Transformar(int Seleccion){
	
	char Opcion;

    
    while(1){
    system("clear");
    printf("%s                    -----------------------------------------------------------------------------------------   \n",red);
    printf("%s                   |                     *************EFECTO DE SONIDO*************                          |  \n",red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s1.Normal                                                                            %s|   \n",red,brown,red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s2.Ardillas                                                                          %s|   \n",red,brown,red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s3.Darth Vader                                                                       %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                   |     %s4.Eco                                                                               %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                   |     %s5.Salir                                                                             %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);

    printf("%s                    -----------------------------------------------------------------------------------------  \n\n",red);
    
    printf("%s                        Opcion: ",green);
    printf("%s",none);
    scanf("%s", &Opcion);
    
    switch(Opcion){
        
        case '1':
         system ("clear");
        if (Seleccion==0){
        system ("gst-launch-0.10 filesrc location=sonido.ogg ! decodebin ! audioconvert ! audioresample ! alsasink"); 
               // bifurcacion. ! queue ! audioconvert ! wavescope ! ffmpegcolorspace ! ximagesink");
              }
        if (Seleccion==1){
        system ("gst-launch filesrc location=BohemianRhapsody.ogg ! decodebin ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==2){
        system ("gst-launch filesrc location=DBZ.ogg ! decodebin ! audioconvert ! audioresample ! autoaudiosink" );
       }        
       if (Seleccion==3){
        system ("gst-launch filesrc location=PuertaNegra.ogg ! decodebin ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==4){
        system ("gst-launch filesrc location=LosPollitosDicen.ogg ! decodebin ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==5){
        system ("gst-launch filesrc location=Toxicity.ogg ! decodebin ! audioconvert ! audioresample ! autoaudiosink" );
       }
        sleep(1);
        break;
        
        case '2':
        system ("clear");
        if (Seleccion==0){
        system ("gst-launch-0.10 filesrc location=sonido.ogg ! decodebin ! audioconvert ! speed speed=2.2 ! audioconvert ! audioresample ! alsasink"); 
               // bifurcacion. ! queue ! audioconvert ! wavescope ! ffmpegcolorspace ! ximagesink");
              }
        if (Seleccion==1){
        system ("gst-launch filesrc location=BohemianRhapsody.ogg ! decodebin ! audioconvert ! speed speed=2.2 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==2){
        system ("gst-launch filesrc location=DBZ.ogg ! decodebin ! audioconvert ! speed speed=2.2 ! audioconvert ! audioresample ! autoaudiosink" );
       }        
       if (Seleccion==3){
        system ("gst-launch filesrc location=PuertaNegra.ogg ! decodebin ! audioconvert ! speed speed=2.2 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==4){
        system ("gst-launch filesrc location=LosPollitosDicen.ogg ! decodebin ! audioconvert ! speed speed=2.2 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==5){
        system ("gst-launch filesrc location=Toxicity.ogg ! decodebin ! audioconvert ! speed speed=2.2 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        sleep(1);
        break;
