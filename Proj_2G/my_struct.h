//This file should contain your struct definition for Circle, Triangle, 
//and Rectangle


typedef struct {
	double minX;
	double minY;
	double maxX;
	double maxY;
} Rectangle;



typedef struct {
	double originX;
	double originY;
	double radius;
}Circle;



typedef struct {
	double p1x;
	double p2x;
	double minY;
	double maxY;

} Triangle;



typedef union {
        Triangle t;
        Circle c;
        Rectangle r;

}ShapeUnion;



enum ShapeType{
	Tri,
	Rect,
	Circ

};

struct Shape;

typedef struct{
	double (*GetArea)(struct Shape *);
	double (*GetBoundingBox) (struct Shape *, double *);
}FunctionTable;

struct Shape{
	ShapeUnion su;
	enum ShapeType st;
	FunctionTable ft;
};
