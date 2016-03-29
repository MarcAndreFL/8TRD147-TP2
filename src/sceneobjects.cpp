//
//  sceneobjects.cpp
//  8trd147-d2
//
//  Created by Frédéric Bolduc on 2016-03-29.
//
//

#include <stdio.h>

#include "sceneobjects.h"
#include "mesh.h"
#include "point3d.h"

CFloor::CFloor() {
    this->vertices.push_back(new CVertex(0, *new CPoint3D(4, 0, 4), 1, 1));
    this->vertices.push_back(new CVertex(1, *new CPoint3D(4, 0, -4), 1, 0));
    this->vertices.push_back(new CVertex(2, *new CPoint3D(-4, 0, -4), 0, 0));
    this->vertices.push_back(new CVertex(3, *new CPoint3D(-4, 0, 4), 0, 1));
    
    this->triangles.push_back(new CTriangle(this->vertices[0], this->vertices[1], this->vertices[2]));
    this->triangles.push_back(new CTriangle(this->vertices[0], this->vertices[2], this->vertices[3]));
}

CPole::CPole() {
    //** TODO: Define UVs
    // Bottom hex
    this->vertices.push_back(new CVertex(0, *new CPoint3D(-3, 0, 0), 0, 0));
    this->vertices.push_back(new CVertex(1, *new CPoint3D(-0.5, 0, 0.866), 0, 0));
    this->vertices.push_back(new CVertex(2, *new CPoint3D(0.5, 0, 0.866), 0, 0));
    this->vertices.push_back(new CVertex(3, *new CPoint3D(3, 0, 0), 0, 0));
    this->vertices.push_back(new CVertex(4, *new CPoint3D(0.5, 0, -0.866), 0, 0));
    this->vertices.push_back(new CVertex(5, *new CPoint3D(-0.5, 0, -0.866), 0, 0));
    
    // Top hex
    this->vertices.push_back(new CVertex(6, *new CPoint3D(-3, 6, 0), 0, 0));
    this->vertices.push_back(new CVertex(7, *new CPoint3D(-0.5, 6, -0.866), 0, 0));
    this->vertices.push_back(new CVertex(8, *new CPoint3D(0.5, 6, -0.866), 0, 0));
    this->vertices.push_back(new CVertex(9, *new CPoint3D(3, 6, 0), 0, 0));
    this->vertices.push_back(new CVertex(10, *new CPoint3D(0.5, 6, 0.866), 0, 0));
    this->vertices.push_back(new CVertex(11, *new CPoint3D(-0.5, 6, 0.866), 0, 0));
    
    //** TODO: Tris
    
}

CSheet::CSheet() {
    
}

CRope::CRope() {
    
}
