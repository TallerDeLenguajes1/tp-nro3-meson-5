#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define PERSONAJES 6

	//  BRANCH DEGUER //
	enum TRaza {Orco, Humano, Mago, Enano, Elfo};

	char Nombres[6][10] = {"Dengue", "Naty", "Elena", "Chancho", "Sergito"};
	char Apellidos[6][10] = {"Caliente", "Urano", "Fulanita", "Purgador", "Mechudo"};

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
void CargarCaract(TPersonaje *);
void MostrarCaract(TPersonaje *);
void CargarChar_Raza(TPersonaje *DatosRaza); //Traducir el entero del enum TRaza a caracteres
void CargarPersonajes(TPersonaje *); //N personajes
void MostrarPersonajes(TPersonaje*); //N personajes


int main()
{
	srand(time(NULL));

	TPersonaje *PJ;
	PJ = (TPersonaje *)malloc(sizeof(TPersonaje)*PERSONAJES);

	CargarPersonajes(PJ);
	MostrarPersonajes(PJ);
	//MostrarDatos(PJ);
   
	//	CargarCaract(PJ);
   
	//	MostrarCaract(PJ);
   
	return 0;
}

void CargarDatos(TPersonaje *datosACargar)
{
	{
		datosACargar->DatosPersonales = (TDatos *)malloc(sizeof(TDatos));																	
    	
		datosACargar->DatosPersonales->Edad = rand()%301;
		datosACargar->DatosPersonales->Salud = 100;
	    
		int opApellido=rand()%5;
		int Aleatorio=rand()%5;

		datosACargar->DatosPersonales->ApellidoNombre = (char *)malloc(21*sizeof(char));
	    
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
}
void MostrarDatos(TPersonaje *datosAMostrar)
{
	printf("Nombre: %s\n", datosAMostrar->DatosPersonales->ApellidoNombre);
	CargarChar_Raza(datosAMostrar);
	printf("Edad: %d\n", datosAMostrar->DatosPersonales->Edad);
	printf("Salud: %.2f\n", datosAMostrar->DatosPersonales->Salud);
}
void CargarCaract(TPersonaje *Personaje)
{
	Personaje->Caracteristicas = (TCaracteristicas *)malloc(sizeof(TCaracteristicas));	
	Personaje->Caracteristicas->Velocidad = 1 + rand()%((10+1)-1);
	Personaje->Caracteristicas->Destreza = 1 + rand()%((5+1)-1);
	Personaje->Caracteristicas->Fuerza = 1 + rand()%((10+1)-1);
	Personaje->Caracteristicas->Nivel = 1 + rand()%((10+1)-1);
	Personaje->Caracteristicas->Armadura = 1 + rand()%((10+1)-1);
}
void MostrarCaract(TPersonaje *Personaje)
{
	printf("Velocidad: %d\n", Personaje->Caracteristicas->Velocidad);
	printf("Destreza: %d\n", Personaje->Caracteristicas->Destreza);
	printf("Fuerza: %d\n", Personaje->Caracteristicas->Fuerza);
	printf("Nivel: %d\n", Personaje->Caracteristicas->Nivel);
	printf("Armadura: %d\n", Personaje->Caracteristicas->Armadura);
}
void CargarChar_Raza(TPersonaje *DatosRaza)
{
   switch(DatosRaza->DatosPersonales->Raza){
		case 0: 
			printf("Raza: Orco\n");
			break;
		case 1: 
			printf("Raza: Humano\n");
			break;
		case 2: 
			printf("Raza: Mago\n");
			break;
		case 3: 
			printf("Raza: Enano\n");
			break;
		case 4: 
			printf("Raza: Elfo\n");
			break;
   	}
}
void CargarPersonajes(TPersonaje *pjs){
	TPersonaje *pjs_aux;
	
	for (int i = 0; i < PERSONAJES; ++i){
		CargarDatos(pjs_aux);
		*(pjs + i) = *pjs_aux; //Para podes asignar
	}
}
void MostrarPersonajes(TPersonaje *pjs){
	for (int i = 0; i < PERSONAJES; ++i){
		MostrarDatos(pjs+i);
		MostrarCaract(pjs+i);
	}
}