#ifndef PICTURE_H
#define PICTURE_H

#include <stdio.h>

#include "simple_types.h"

void exit_error( char *message );
void exit_nofile( char *user, char *filename );
void exit_nomemory( char *user, char *array );
void message( char *title, char *message );

class picture
{
	public:
		long xsize, ysize;
		color *content;

		void load( char *filename );

		picture( void ) : xsize( 0 ), ysize( 0 ), content( NULL ) { }
		picture( char *filename ) {  load( filename );  }
		picture( const picture &p ) {  exit_error( "picture: Aufruf Kopierkonstruktor.\n ");  }
		~picture( void ) {  if( content ) delete [] content;  }  

	private:
		void load_bmp_8( FILE *bmp_file );
		void load_bmp_24( FILE *bmp_file );

};


#endif