#ifndef POLYGON_H
#define POLYGON_H

#include "simple_types.h"
#include "matrix.h"

class polygon
{
  private:
    long point_count;
    color c;

    vertex position;
    vertex *points;
    
  public:
    vertex pos( void ) {  return position;  }

    void update_pos( matrix m );
    void display( void );

    polygon( long pc, color ac, vertex *vs );
   ~polygon( void ) {  if( points ) delete [] points;  }
};

void polygon::update_pos( matrix m )
{
  position = m * position;

  for( long x=0 ; x<point_count ; x++ )
     points[ x ] = m * points[ x ];
}

void polygon::display( void )
{
  glColor3ubv( (GLubyte *) &c );

  glBegin( GL_LINE_LOOP );

    for( long x=0 ; x<point_count ; x++ )
       glVertex3dv( (GLdouble *) &points[ x ] );

  glEnd();
}

polygon::polygon( long pc, color ac, vertex *vs )
{
  point_count = pc;  c = ac;

  if( (points = new vertex[ point_count ]) == NULL )
    exit_error( "polygon::polygon(): Fehler während der Reservierung von Arbeitspeicher.\n" );

  for( long x=0 ; x<point_count ; x++ ) points[ x ] = vs[ x ];

  position = vertex( 0, 0, 0 );
}

#endif