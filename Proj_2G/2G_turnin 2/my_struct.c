//This file should contain the 9 functions defined in prototypes.h

#include <prototypes.h>

void InitializeCircle(struct Shape *p, double rad, double x, double y)
{
	p->ft.GetBoundingBox = GetCircleBoundingBox;
	p->ft.GetArea = GetCircleArea;
	p->su.c.originX = x;
	p->su.c.originY = y;
	p->su.c.radius = rad;

}
double GetCircleArea(struct Shape *c)
{
	return (3.14159)*(c->su.c.radius)*(c->su.c.radius);
}
void GetCircleBoundingBox(struct Shape *c, double *bbox){
	bbox[0] = c->su.c.originX-c->su.c.radius;
	bbox[1] = c->su.c.originX+c->su.c.radius;
	bbox[2] = c->su.c.originY-c->su.c.radius;
	bbox[3] = c->su.c.originY+c->su.c.radius;
}
void InitializeRectangle(struct Shape *p, double mnX, double mxX, double 
mnY, 
double mxY)
{
	p->ft.GetBoundingBox = GetRectangleBoundingBox;
	p->ft.GetArea = GetRectangleArea;
	p->su.r.minX = mnX;
	p->su.r.maxX = mxX;
	p->su.r.minY = mnY;
	p->su.r.maxY = mxY;
}
double GetRectangleArea(struct Shape *r)
{
	double side_1 = r->su.r.maxX - r->su.r.minX;
	double side_2 = r->su.r.maxY - r->su.r.minY;
	return side_1*side_2;
}
void GetRectangleBoundingBox(struct Shape *r,double *bbox)
{
	bbox[0] = r->su.r.minX;
        bbox[1] = r->su.r.maxX;
        bbox[2] = r->su.r.minY;
        bbox[3] = r->su.r.maxY;
}
void InitializeTriangle(struct Shape *p, double pt1x, double pt2x, 
double mnY, 
double mxY)
{
	p->ft.GetBoundingBox = GetTriangleBoundingBox;
	p->ft.GetArea = GetTriangleArea;
	p->su.t.p1x = pt1x;
	p->su.t.p2x = pt2x;
	p->su.t.minY = mnY;
	p->su.t.maxY = mxY;
}
double GetTriangleArea(struct Shape *t)
{
	double base = (t->su.t.p2x)-(t->su.t.p1x);
	double height = ((t->su.t.maxY)-(t->su.t.minY));
	return base*height*.5;
}
void GetTriangleBoundingBox(struct Shape *t, double *bbox)
{
	bbox[0] = t->su.t.p1x;
        bbox[1] = t->su.t.p2x;
        bbox[2] = t->su.t.minY;
        bbox[3] = t->su.t.maxY;
}
