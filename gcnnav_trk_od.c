#include "gcnav.h"

trk_od* init_trk_od( crd* orig, crd* dest ) {

	trk_od* T =( trk_od* ) malloc( sizeof( trk_od ) ) ;

	fp dlat = dest -> lat - orig -> lat ;
	fp dlng = dest -> lng - orig -> lng ;

	T -> orig = orig ;
	T -> dest = dest ;
	T -> havsine_dlat = pow( sin( dlat / 2 ), 2 ) ;
	T -> sin_dlat = sin( dlat ) ;
	T -> cos_dlat = cos( dlat ) ;
	T -> havsine_dlng = pow( sin( dlng /2 ), 2 ) ;
	T -> sin_dlng = sin( dlng ) ;
	T -> cos_dlng = cos( dlng ) ;

	return T ;

};

void trk_od_havsine( trk_od * T ) {

	fp a = T -> havsine_dlat  + T -> orig -> cos_lat * T -> dest -> cos_lat * T -> havsine_dlng ;

	fp dst = 2 * atan2( sqrt(a), sqrt(1-a) ) ;

	T -> dst = dst ;
	T -> cos_dst = cos( dst ) ;
	T -> sin_dst = sin( dst ) ;

	return ;

} ;

void trk_od_brg( trk_od* T ) {


}
