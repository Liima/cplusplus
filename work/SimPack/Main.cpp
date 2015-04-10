#include "SimApp.h"
#include <gtk/gtk.h>
#include <iostream>


int main(int argc, char* argv[])
{	
	srand(time(NULL));
	SimApp(argc, argv, "Particle Simulator", 500, 600);
}

