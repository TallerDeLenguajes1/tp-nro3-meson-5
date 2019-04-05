#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

    enum TRaza{Orco, Humano, Mago, Enano, Elfo};

    char Nombres[6][10]={"Dengue", "Naty", "Sil", "Chancho", "Sergito"};

    char Apellidos[6][10]={"Caliente", "Urano", "Fulanita", "Pestilent", "Mechudo"};

    typedef struct
    {
		TRaza Raza; //nota 1
		char *ApellidoNombre; //nota 2
		int Edad; //entre 0 a 300
		double Salud; //100
	}TDatos;

	typedef struct
	{
		int Velocidad;// 1 a 10
		int Destreza; //1 a 5
		int Fuerza;//1 a 10
		int Nivel; //1 a 10
		int Armadura; //1 a 10
	}TCaracteristicas;

	typedef struct
	{
		TDatos * DatosPersonales;
		TCaracteristicas * Caracteristicas;
	}TPersonaje;

void CargarDatos(TPersonaje *);
void MostrarDatos(TPersonaje *);
void CargarCaract(TCaracteristicas *Personaje);


int main()
{
    srand(time(NULL));

    TPersonaje *prueba;
    TCaracteristicas *prueba2;

    CargarDatos(prueba);

    MostrarDatos(prueba);

    CargarCaract(prueba2);

    return 0;
}
void CargarDatos(TPersonaje *datosACargar)
{
	datosACargar->DatosPersonales = (TDatos *)malloc(sizeof(TDatos));
    datosACargar->DatosPersonales->Edad = rand()%301;
    datosACargar->DatosPersonales->Salud = 100;
    
    int opApellido=rand()%5;

    int Aleatorio=rand()%5;

    strcpy(datosACargar->DatosPersonales->ApellidoNombre, Apellidos[opApellido]);

    strcat(datosACargar->DatosPersonales->ApellidoNombre, " ");

    strcat(datosACargar->DatosPersonales->ApellidoNombre, Nombres[Aleatorio]);

    switch(Aleatorio){
    	case 0: 
    	       datosACargar->DatosPersonales->Raza = Orco;
    	       break;
    	case 1: 
    	       datosACargar->DatosPersonales->Raza = Humano;
    	       break;
    	case 2: 
    	       datosACargar->DatosPersonales->Raza = Mago;
    	       break;
    	case 3: 
    	       datosACargar->DatosPersonales->Raza = Enano;
    	       break;
    	case 4: 
    	       datosACargar->DatosPersonales->Raza = Elfo;
    	       break;
    }
}

void MostrarDatos(TPersonaje *datosAMostrar)
{
	printf("El personaje se llama: %s\n", datosAMostrar->DatosPersonales->ApellidoNombre);
    printf("El personaje es de raza: %d\n", datosAMostrar->DatosPersonales->Raza);
    printf("El personaje tiene una edad de: %d\n", datosAMostrar->DatosPersonales->Edad);
    printf("El personaje tiene una salud de: %.2f\n", datosAMostrar->DatosPersonales->Salud);
}
void CargarCaract(TCaracteristicas *Personaje){
   	Personaje = (TCaracteristicas *)malloc(sizeof(TCaracteristicas)); //No estoy seguro si hace falta la reserva
    Personaje->Velocidad = 1 + rand()%((10+1)-1);
    Personaje->Destreza = 1 + rand()%((5+1)-1);
    Personaje->Fuerza = 1 + rand()%((10+1)-1);
    Personaje->Nivel = 1 + rand()%((10+1)-1);
    Personaje->Armadura = 1 + rand()%((10+1)-1);
}