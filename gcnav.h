#ifndef GCNAV_H_
#define GENAV_H_

#include <math.h>
#include <stdio.h>


/*comment out for 64 bit double float point*/
#define USE_FLOAT

#ifndef USE_FLOAT /*DOUBLE*/

	typedef double fp ;

#else /*USE_FLOAT*/

	typedef float fp ;
#	define sin sinf
#	define cos cosf
#	define sqrt sqrtf
#	define pow powf
#	define acos acosf
#	define atan atanf
#	define atan2 atan2f

#endif /*USE_FLOAT*/

extern fp PI ;
extern fp TO_DEG ;
extern fp TO_RAD ;
extern fp RADIUS_KM ;
extern fp RADIUS_MI ;

fp to_deg( fp rad ) ;

fp to_rad( fp deg ) ;

/* std is a 0 for imperal miles or a 1 for metric km*/

fp to_linar_dst( fp rad_dst, int std ) ;

fp to_rad_dst( fp lin_dst, int std ) ;


struct coordinate {
		fp lat ;
		fp sin_lat ;
		fp cos_lat ;
		fp lng ;
		fp sin_lng ;
		fp cos_lng ;
}coordinate ; /*struct coordinate or crd lat lng and sin cos if lat lng */

typedef struct coordinate crd ;

/* init crd with lat lattitude and lng longitude in raidans and deg */

crd* init_crd( fp lat, fp lng ) ;

crd* init_crd_deg( fp deg_lat, fp deg_lng ) ;

/*free rm crd */

void free_crd( crd* C ) ;

/*struct for track created from 2 crd* orig orgin and dest destination */

struct track_orig_dest {
	crd* orig ;
	crd* dest ;
	fp havsine_dlat ; //haversine of dif in lat
	fp havsine_dlng ;
	fp cos_dlat ;
	fp cos_dlng ;
	fp sin_dlat ;
	fp sin_dlng ;
	fp dst ;
	fp cos_dst ;
	fp sin_dst ;
	fp brg ;
}track_orig_dest ; //track_orig_dest trk_od to be used for creating a trk_under_way trk_uw

typedef struct track_orig_dest trk_od ;

trk_od* init_trk_od( crd* orig, crd* dest ) ;

#endif /*GCNAV_H_*/
