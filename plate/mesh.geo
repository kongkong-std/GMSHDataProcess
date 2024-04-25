// physical entity
/*
* rectangular domain
*     length a = 5, width b = 3
*/
lc = 1.;

// Point data
Point(1) = {0, 0, 0, lc};
Point(2) = {5, 0, 0, lc};
Point(3) = {5, 1, 0, lc};
Point(4) = {5, 2, 0, lc};
Point(5) = {5, 3, 0, lc};
Point(6) = {0, 3, 0, lc};

// Line data
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Line(6) = {6, 1};

// Curve data
Curve Loop(1) = {1, 2, 3, 4, 5, 6};

// Plane data
Plane Surface(1) = {1};

//Recombine Surface(1);

// command line
/*
* gmsh mesh.geo -2 -format msh4 -o mesh.msh
*/