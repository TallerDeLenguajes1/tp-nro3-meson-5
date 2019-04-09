#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

    enum TRaza {Orco, Humano, Mago, Enano, Elfo};

    char Nombres[6][10] = {"Dengue","Naty","Elena","Chancho","Sergito","Ale"};
    char Apellidos[6][10] = {"Caliente","Urano","Fulanita","Purgador","Mechudo","Prohibido"};

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
void CargarNPersonajes (int , TPersonaje *);
void Danios(TPersonaje *, TPersonaje *);

int main()
{
    srand(time(NULL));

    int cantitdadDePersonajes;

   	TPersonaje *arregloDePersonajes=NULL;

   	TPersonaje *prueba;
   	prueba = (TPersonaje *)malloc(sizeof(TPersonaje));

   	CargarDatos(prueba);

    MostrarDatos(prueba);

   	CargarCaract(prueba);

   	MostrarCaract(prueba);

    printf("Ingrese la cantidad de personajes que desea crear\n");
   	scanf("%d", &cantitdadDePersonajes);

   	CargarNPersonajes(cantitdadDePersonajes, arregloDePersonajes);

   	for(int i = 0; i<3; i++)
   	{

   	}

    return 0;
}

void CargarDatos(TPersonaje *datosACargar)
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

void CargarNPersonajes(int numeroDePersonajes, TPersonaje *arregloDePersonajes)
{
    arregloDePersonajes = (TPersonaje *)malloc(sizeof(TPersonaje) * numeroDePersonajes);

   	for(int i = 0; i < numeroDePersonajes; i++)
    {
        CargarDatos(arregloDePersonajes+i);
        CargarCaract(arregloDePersonajes+i);
    }
}

void Danios(TPersonaje *personaje1, TPersonaje *personaje2)
{
	int PD1 = personaje1->Caracteristicas->Destreza * personaje1->Caracteristicas->Fuerza * personaje1->Caracteristicas->Nivel;
	int PD2 = personaje2->Caracteristicas->Destreza * personaje2->Caracteristicas->Fuerza * personaje2->Caracteristicas->Nivel;

	int ED1 = 1 + rand()%100;
	int ED2 = 1 + rand()%100;

	int VA1 = PD1*ED1;
	int VA2 = PD2*ED2;

	int PDEF1 = personaje1->Caracteristicas->Velocidad * personaje1->Caracteristicas->Armadura;
	int PDEF2 = personaje2->Caracteristicas->Velocidad * personaje2->Caracteristicas->Armadura;

	int MDP = 50000;

	int DP1 = ((VA1-PDEF1)/MDP)*100;
	int DP2 = ((VA2-PDEF2)/MDP)*100;

	personaje1->DatosPersonales->Salud = personaje1->DatosPersonales->Salud - DP2;
	personaje2->DatosPersonales->Salud = personaje2->DatosPersonales->Salud - DP1;
}

void Recuento(TPersonaje *personaje1, TPersonaje *personaje2)
{
	if (personaje1->DatosPersonales->Salud == 0 || personaje2->DatosPersonales->Salud == 0)
	{
		if (personaje1->DatosPersonales->Salud == 0)
		{
			printf("La salud del personaje 1 llego a cero. El personaje 2 gana\n");
		}
		else
		{
			printf("La salud del personaje 2 llego a cero. El personaje 1 gana\n");
		}
	}
	else
	{
		printf("La salud del jugador 1 es de %d\n", personaje1->DatosPersonales->Salud);
		printf("La salud del jugador 2 es de %d\n", personaje2->DatosPersonales->Salud);
	}
}

void Ganador(TPersonaje *personaje1, TPersonaje *personaje2)
{
	if (personaje1->DatosPersonales->Salud != 0 && personaje2->DatosPersonales->Salud != 0)
	{
		if (personaje1->DatosPersonales->Salud > personaje2->DatosPersonales->Salud)
		{
			printf("El jugador 1 Gana\n");
		}
		else
		{
			printf("El jugador 2 Gana\n");
		}
	}
}