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



int main()
{


    return 0;
}

