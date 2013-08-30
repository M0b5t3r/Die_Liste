#include <windows.h>
#include <gl\glew.h>
#include <gl\glu.h>
#include <math.h>
#include <iostream>

#include "stdafx.h"
#include "screen_interface.h"
#include "simple_types.h"
#include "polygon.h"
#include "matrix.h"
#include "input_interface.h"
#include "DataLoader.h"

uchar handle_input( void );

int WINAPI WinMain( HINSTANCE hinst, HINSTANCE pinst, LPSTR cmdl, int cmds )
{
	//DataLoader dl("compound.tg4");
	//dl.funkt();                       Marius Style
	screen_interface.open_window( hinst, 1280, 1024 );

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 30, GLdouble( x_res ) / y_res, 0.1f, 10000.0f );
	glMatrixMode( GL_MODELVIEW );
	glPolygonMode( GL_FRONT_AND_BACK, GL_POLYGON);
	glEnable( GL_DEPTH_TEST );
	
	//Für Texturen laden
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE ); 

	GLuint texture_id; //zur Identifikation der Textur
	glGenTextures( 1, &texture_id ); //IdentifikationsID generieren und in texture_id speichern
	glBindTexture( GL_TEXTURE_2D, texture_id ); //Festlegen der aktuellen Textur

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR ); //MAGNIFICATION -> vergrößerungsartefakte; unschärfefilter
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR ); //MINIFICATION -> verkleinerungsartefakte; schärfefilter

	glEnable( GL_TEXTURE_2D ); //Texturprojektion aktivieren (rechenintensiv)
	//Für Texturen laden - Ende

	DataLoader* dl = new DataLoader("compound.tg4");

	while(handle_input() == 0)
	{
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		for(int i = 0; i < dl->get_CountOfPolygons() ; i++ )
		{
			(dl->get_Polygon3D()+i)->DrawPolygon();
		}

		screen_interface.swap_buffers();
	}
  return input.msg.wParam;
}

uchar handle_input( void )
{
  if( input.check() == 1 ) return 1;
  if( input.event_key == VK_ESCAPE ) return 1;

  return 0;
}



