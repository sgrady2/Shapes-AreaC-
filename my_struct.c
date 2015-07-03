//This file should contain the 9 functions defined in prototypes.h

#include <prototypes.h>

void InitializeCircle(Shape *p, double rad, double x, double y)
{
	p->ft.GetArea = GetCircleArea;
	p->originX = x;
	p->originY = y;
	p->radius = rad;

}
double GetCircleArea(Shape *c)
{
	return (3.14159)*(c->radius)*(c->radius);
}
void GetCircleBoundingBox(Shape *c, double *bbox){
	bbox[0] = c->originX-c->radius;
	bbox[1] = c->originX+c->radius;
	bbox[2] = c->originY-c->radius;
	bbox[3] = c->originY+c->radius;
}
void InitializeRectangle(Shape *p, double mnX, double mxX, double mnY, 
double mxY)
{
	p->ft.GetArea = GetRectangleArea;
	p->minX = mnX;
	p->maxX = mxX;
	p->minY = mnY;
	p->maxY = mxY;
}
double GetRectangleArea(Shape *r)
{
	double side_1 = r->maxX - r->minX;
	double side_2 = r->maxY - r->minY;
	return side_1*side_2;
}
void GetRectangleBoundingBox(Shape *r,double *bbox)
{
	bbox[0] = r->minX;
        bbox[1] = r->maxX;
        bbox[2] = r->minY;
        bbox[3] = r->maxY;
}
void InitializeTriangle(Shape *p, double pt1x, double pt2x, double mnY, 
double mxY)
{
	p->ft.GetArea = GetTriangleArea;
	p->p1x = pt1x;
	p->p2x = pt2x;
	p->minY = mnY;
	p->maxY = mxY;
}
double GetTriangleArea(Shape *t)
{
	double base = (t->p2x)-(t->p1x);
	double height = ((t->maxY)-(t->minY));
	return base*height*.5;
}
void GetTriangleBoundingBox(Shape *t, double *bbox)
{
	bbox[0] = t->p1x;
        bbox[1] = t->p2x;
        bbox[2] = t->minY;
        bbox[3] = t->maxY;
}
