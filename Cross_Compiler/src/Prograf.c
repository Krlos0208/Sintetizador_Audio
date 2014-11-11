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
        
        case '3': 
        system("clear");
                if (Seleccion==0){
        system ("gst-launch-0.10 filesrc location=sonido.ogg ! decodebin ! audioconvert ! speed speed=0.6 ! audioconvert ! audioresample ! alsasink"); 
               // bifurcacion. ! queue ! audioconvert ! wavescope ! ffmpegcolorspace ! ximagesink");
              }
        if (Seleccion==1){
        system ("gst-launch filesrc location=BohemianRhapsody.ogg ! decodebin ! audioconvert ! speed speed=0.6 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==2){
        system ("gst-launch filesrc location=DBZ.ogg ! decodebin ! audioconvert ! speed speed=0.6 ! audioconvert ! audioresample ! autoaudiosink" );
       }        
       if (Seleccion==3){
        system ("gst-launch filesrc location=PuertaNegra.ogg ! decodebin ! audioconvert ! speed speed=0.6 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==4){
        system ("gst-launch filesrc location=LosPollitosDicen.ogg ! decodebin ! audioconvert ! speed speed=0.6 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==5){
        system ("gst-launch filesrc location=Toxicity.ogg ! decodebin ! audioconvert ! speed speed=0.6 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        sleep(1);
        break;
        
         
        
        case '4': 
        system("clear");
                if (Seleccion==0){
        system ("gst-launch-0.10 filesrc location=sonido.ogg ! decodebin ! audioconvert ! audioecho delay=500000000 intensity=0.6 feedback=0.4 ! audioconvert ! audioresample ! alsasink"); 
               // bifurcacion. ! queue ! audioconvert ! wavescope ! ffmpegcolorspace ! ximagesink");
              }
        if (Seleccion==1){
        system ("gst-launch filesrc location=BohemianRhapsody.ogg ! decodebin ! audioconvert ! audioecho delay=500000000 intensity=0.6 feedback=0.4 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==2){
        system ("gst-launch filesrc location=DBZ.ogg ! decodebin ! audioconvert ! audioecho delay=500000000 intensity=0.6 feedback=0.4 ! audioconvert ! audioresample ! autoaudiosink" );
       }        
       if (Seleccion==3){
        system ("gst-launch filesrc location=PuertaNegra.ogg ! decodebin ! audioconvert ! audioecho delay=500000000 intensity=0.6 feedback=0.4 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==4){
        system ("gst-launch filesrc location=LosPollitosDicen.ogg ! decodebin ! audioconvert ! audioecho delay=500000000 intensity=0.6 feedback=0.4 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        if (Seleccion==5){
        system ("gst-launch filesrc location=Toxicity.ogg ! decodebin ! audioconvert ! audioecho delay=500000000 intensity=0.6 feedback=0.4 ! audioconvert ! audioresample ! autoaudiosink" );
       }
        sleep(1);
        break;
        
        case '5':
        system("clear");
        return;
        break;
        
        default: printf("                      Opcion Invalida!!\n"); sleep(1);
        
}

}

}
void TiempoReal(){
	
	char Opcion;

    
    while(1){
    system("clear");
    printf("%s                    -----------------------------------------------------------------------------------------   \n",red);
    printf("%s                   |                     *************EFECTO DE SONIDO*************                          |  \n",red);
    printf("%s                   |                                                                                         |   \n",red);
    //printf("%s                   |     %s1.Ardillas                                                                          %s|   \n",red,brown,red);
   // printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s1.Normal                                                                            %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                   |     %s2.Eco                                                                               %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                   |     %s3.Salir                                                                             %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);

    printf("%s                    -----------------------------------------------------------------------------------------  \n\n",red);
    
    printf("%s                        Opcion: ",green);
    printf("%s",none);
    scanf("%s", &Opcion);
    
    switch(Opcion){
        
        //case '1':
        //system ("clear");
        //system ("gst-launch-0.10 -e alsasrc device=plughw:0,0 ! audioconvert ! tee name=bifurcacion \
                   bifurcacion. ! queue ! speed speed=2.2 ! audioconvert ! alsasink \
                   bifurcacion. ! queue ! audioconvert ! wavescope ! ffmpegcolorspace ! ximagesink");
        //sleep(1);
        //break;
        
        //case '2': 
        //system("clear");
        //system ("gst-launch-0.10 -e alsasrc device=plughw:0,0 ! audioconvert ! tee name=bifurcacion \
                   bifurcacion. ! queue ! speed speed=0.6 ! audioconvert ! alsasink \
                   bifurcacion. ! queue ! audioconvert ! wavescope ! ffmpegcolorspace ! ximagesink");
        //sleep(1);
        //break;
        case '1': 
        system("clear");
        system ("gst-launch-0.10 alsasrc device=plughw:0,0 ! audioconvert ! alsasink");
        sleep(1);
        break;
        
        case '2': 
        system("clear");
        system ("gst-launch-0.10 alsasrc device=plughw:0,0 ! audioconvert ! audioecho intensity=0.6 feedback=0.4 delay=500000000 ! audioconvert ! alsasink");
        sleep(1);
        break;
        
        case '3':
        system("clear");
        return;
        break;
        
        default: printf("                      Opcion Invalida!!\n"); sleep(1);
        
}

}

	
}
int Canciones(){
	
	char Opcion;

    
    while(1){
    system("clear");
    printf("%s                    -----------------------------------------------------------------------------------------   \n",red);
    printf("%s                   |                     *************LISTA DE CANCIONES*************                        |  \n",red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s1.Bohemian Rhapsody                                                                 %s|   \n",red,brown,red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s2.DBZ intro                                                                         %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                   |     %s3.La Puerta Negra                                                                   %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                   |     %s4.Los Pollitos Dicen                                                                %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                   |     %s5.Toxicity                                                                          %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                    -----------------------------------------------------------------------------------------  \n\n",red);
    
    printf("%s                        Opcion: ",green);
    printf("%s",none);
    scanf("%s", &Opcion);
    
    switch(Opcion){
        
        case '1':
        system ("clear");
        return 1;
        sleep(1);
        break;
        
        case '2':
        system ("clear");
        return 2;
        sleep(1);
        break;
        
        case '3':
        system ("clear");
        return 3;
        sleep(1);
        break;
        
        case '4':
        system ("clear");
        return 4;
        sleep(1);
        break;
        
        case '5':
        system ("clear");
        return 5;
        sleep(1);
        break;
}
}
}
int main(){
	
  
	int Seleccion;
	
	char Opcion;
	
    while(1){
	//sleep(5);
    system("clear");
    printf("%s                    -----------------------------------------------------------------------------------------   \n",red);
    printf("%s                   |                               ***SINTETIZADOR DE VOZ***                                 |  \n",red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s1.Grabar Sonido                                                                     %s|   \n",red,brown,red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s2.Tiempo Real                                                                       %s|   \n",red,brown,red);
    printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s3.Canciones                                                                         %s|   \n",red,brown,red);
    printf("%s                   |                                                                                         |   \n",red);
    //printf("%s                   |     %s4.Karaoke                                                                         %s|   \n",red,brown,red);
    //printf("%s                   |                                                                                         |   \n",red);
    printf("%s                   |     %s4.Salir                                                                             %s|    \n",red,brown,red);
    printf("%s                   |                                                                                         |\n",red);
    printf("%s                    -----------------------------------------------------------------------------------------  \n\n",red);
    
    printf("%s                        Opcion: ",green);
    printf("%s",none);
    scanf("%s", &Opcion);
    
    switch(Opcion){
        
        case '1':
        system ("clear");
        system ("gst-launch-0.10 alsasrc device=plughw:0,0 ! audioconvert ! audioresample ! vorbisenc ! oggmux ! filesink location=sonido.ogg"); 
        Seleccion=0;
        Transformar(Seleccion);
        break;
        
        case '2':
        system ("clear");
        TiempoReal();
        break;
        
        case '3':
        Seleccion=Canciones();
        Transformar(Seleccion);
         break;
        
        //case '4':
        //system ("clear");
        //system ("gst-launch-0.10 -e filesrc location=Cucaracha.mp4 ! decodebin name=decodificador                  decodificador. ! ffmpegcolorspace ! ximagesink                  decodificador. ! audioconvert ! alsasink \
        alsasrc device=plughw:0,0 ! audioconvert ! alsasink" );
        //break;
        
        case '4':
        system("clear");
        return(0);
        break;
        
        default: printf("                      Opción Inválida!!\n"); 
        sleep(1);
        
}

}
 }
