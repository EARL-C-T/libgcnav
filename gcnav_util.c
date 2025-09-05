#include "gcnav.h"

/*some constants PI and numbers used for conversions*/

const fp PI = 3.1415926535897932384626433832795028842 ;
const fp TO_DEG = 57.295779513082320876798154814105170332 ;
const fp TO_RAD = 0.017453292519943295769236907684886127134 ;
const fp RADIUS_KM = 6378.0008 ;
const fp RADIUS_MI = 3958.7564 ;

fp to_deg( fp rad ) {
	return rad * TO_DEG ;
} ;

fp to_rad( fp deg ) {
	return deg * TO_RAD ;
} ;

/*std 0 == imperal Mi 1 == metric Km */

fp to_linar_dst( fp dst_rad, int std ) {
	switch ( std ) {
	case 0:
		return dst_rad * RADIUS_MI ;
		break ;
	case 1:
		return dst_rad * RADIUS_KM ;
		break ;
	default:
		printf("ERROR STD MUST BE 0 IMPERAL OR 1 METRIC \n") ;
		return 0.000000 ;
		break ;
	}

} ;

fp to_rad_dst ( fp dst_lin, fp std ) {
	switch( std ) {
	case 0:
		return RADIUS_MI / dst_lin ;
		break ;
	case 1:
		return RADIUS_KM / dst_lin ;
		break ;
	default:
		printf("ERROR STD MUST BE 0 IMPERAL OR 1 METRIC \n") ;
		return 0.000000 ;
		break ;
	}

} ;



