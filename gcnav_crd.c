#include "gcnav.h"


crd* init_crd( fp lat, fp lng ){

	crd* C =( crd* ) malloc( sizeof(crd) ) ;

	C -> lat = lat ;
	C -> sin_lat = sin( lat ) ;
	C -> cos_lat = cos( lat ) ;
	C -> lng = lng ;
	C -> sin_lng = sin( lng ) ;
	C -> cos_lng = cos( lng ) ;

	return C ;
} ;

crd* init_crd_deg( fp deg_lat, fp deg_lng ) {

	fp lat = to_deg( deg_lat ) ;
	fp lng = to_deg( deg_lng ) ;

	return init_crd( lat, lng ) ;

};

void free_crd( crd* C ) {

	free( *C ) ;

	return ;

};
