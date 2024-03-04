#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <list>
#include <deque>

#define MIN_VAL 1e-5f
#define MAX_VAL 1e+8f

#define PI 3.14159265

//basic structures -------------------------------------

typedef struct pnt
{
	double x;
	double y;
	pnt(double x=0.0, double y=0.0): x(x), y(y) {}
}ponto;

typedef struct vp
{
    double x;
    double y;
    int type;
	int rot;
    vp(double x=0.0, double y=0.0,int type=0,int rot=0): x(x), y(y), type(type), rot(rot) {}
}vxpos;


///p0,p1 - connection points between adjacent segments
typedef struct srct
{
	ponto p0,p1;
}srecta;

/// Bezier_Type 0:Quadratic; 1:Cubic;
typedef struct crv
{
	int bezier_type;
	ponto p0,p1,c0,c1;
	crv(int bezier_type=0): bezier_type(bezier_type) {}
}curva;

/// Elipse_Type 0:Circle; 1:Elipse;
/// c0: center0, c1:center1 (not needed in circle)
typedef struct elps
{
    //P0 e P1 servem para identificar os vectores que definem o angulo que define o arco... Caso completo fica orientado no eixo do X com Y=0
	int elipse_type;
	ponto p0,p1,c0,c1;
	//RaioCirculo = Sqrt(p0x^2+p0y^2);
	elps(int elipse_type=0): elipse_type(elipse_type){}
}elipse;

typedef struct sgmt
{
	int sgm_id;
	int sgm_type;
	ponto p0,p1,c0,c1;
	int sub_type;
	sgmt(int sgm_id=0, int sgm_type=0, int sub_type=0): sgm_id(sgm_id), sgm_type(sgm_type), sub_type(sub_type) {}
}segmento;

#ifdef SGM_ARRAY_TYPE_VECTOR
	typedef std::vector<segmento> SGM_ARRAY_TYPE;
	typedef std::vector<segmento>::iterator SGM_ARRAY_ITERATOR;
#else
	#ifdef SGM_ARRAY_TYPE_DEQUE
		typedef std::deque<segmento> SGM_ARRAY_TYPE;
		typedef std::deque<segmento>::iterator SGM_ARRAY_ITERATOR;
	#else
		typedef std::list<segmento> SGM_ARRAY_TYPE;
		typedef std::list<segmento>::iterator SGM_ARRAY_ITERATOR;
		typedef std::list<segmento>::const_iterator SGM_ARRAY_CONST_ITERATOR;

	#endif
#endif


/// Plg_Type: Orientation definition 0:External; -1:Internal(Hole);
typedef struct plgn
{
	int plg_id;
	int plg_type;
	SGM_ARRAY_TYPE sgm;
	plgn(int plg_id=0, int plg_type=0): plg_id(plg_id), plg_type(plg_type) {}
}poligono;

#ifdef PLG_ARRAY_TYPE_VECTOR
	typedef std::vector<poligono> PLG_ARRAY_TYPE;
	typedef std::vector<poligono>::iterator PLG_ARRAY_ITERATOR;
#else
	#ifdef PLG_ARRAY_TYPE_DEQUE
		typedef std::deque<poligono> PLG_ARRAY_TYPE;
		typedef std::deque<poligono>::iterator PLG_ARRAY_ITERATOR;
	#else
		typedef std::list<poligono> PLG_ARRAY_TYPE;
		typedef std::list<poligono>::iterator PLG_ARRAY_ITERATOR;
		typedef std::list<poligono>::const_iterator PLG_ARRAY_CONST_ITERATOR;

	#endif
#endif

/// Form_Type: Undefined. Ex:(0:SimplePolygon; 1:ConvexHull; 2:MBR; 3:Circle/Elipse; 4:All; ...)
/// Can also be 0:Board; 1:Piece;
typedef struct frm
{
	int frm_id;
	int frm_type;
	PLG_ARRAY_TYPE plg;
    frm(int frm_id=0, int frm_type=0): frm_id(frm_id), frm_type(frm_type) {}
}forma;

#ifdef FRM_ARRAY_TYPE_VECTOR
	typedef std::vector<forma> FRM_ARRAY_TYPE;
	typedef std::vector<forma>::iterator FRM_ARRAY_ITERATOR;
#else
	#ifdef FRM_ARRAY_TYPE_DEQUE
		typedef std::deque<forma> FRM_ARRAY_TYPE;
		typedef std::deque<forma>::iterator FRM_ARRAY_ITERATOR;
	#else
		typedef std::list<forma> FRM_ARRAY_TYPE;
		typedef std::list<forma>::iterator FRM_ARRAY_ITERATOR;
		typedef std::list<forma>::const_iterator FRM_ARRAY_CONST_ITERATOR;

	#endif
#endif

#endif //END OF DEFINITION OF TYPES_H
