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

CPole::CPole() {    // Bottom hex
    this->vertices.push_back(new CVertex(0,  *new CPoint3D(-0.1,  0,  0),    0, 1));
    this->vertices.push_back(new CVertex(1,  *new CPoint3D(-0.05, 0,  0.08), 0.2, 1));
    this->vertices.push_back(new CVertex(2,  *new CPoint3D( 0.05, 0,  0.08), 0.4, 1));
    this->vertices.push_back(new CVertex(3,  *new CPoint3D( 0.1,  0,  0),    0.6, 1));
    this->vertices.push_back(new CVertex(4,  *new CPoint3D( 0.05, 0, -0.08), 0.8, 1));
    this->vertices.push_back(new CVertex(5,  *new CPoint3D(-0.05, 0, -0.08), 1, 1));
    
    // Top hex
    this->vertices.push_back(new CVertex(6,  *new CPoint3D(-0.1,  6,  0),    0, 0));
    this->vertices.push_back(new CVertex(7,  *new CPoint3D(-0.05, 6, -0.08), 0.2, 0));
    this->vertices.push_back(new CVertex(8,  *new CPoint3D( 0.05, 6, -0.08), 0.4, 0));
    this->vertices.push_back(new CVertex(9,  *new CPoint3D( 0.1,  6,  0),    0.6, 0));
    this->vertices.push_back(new CVertex(10, *new CPoint3D( 0.05, 6,  0.08), 0.8, 0));
    this->vertices.push_back(new CVertex(11, *new CPoint3D(-0.05, 6,  0.08), 1, 0));
    
    // Bottom hex tris
    this->triangles.push_back(new CTriangle(this->vertices[0], this->vertices[5], this->vertices[1]));
    this->triangles.push_back(new CTriangle(this->vertices[1], this->vertices[5], this->vertices[2]));
    this->triangles.push_back(new CTriangle(this->vertices[2], this->vertices[5], this->vertices[4]));
    this->triangles.push_back(new CTriangle(this->vertices[2], this->vertices[4], this->vertices[3]));
    
    // Top hex tris
    this->triangles.push_back(new CTriangle(this->vertices[6], this->vertices[11], this->vertices[7]));
    this->triangles.push_back(new CTriangle(this->vertices[7], this->vertices[11], this->vertices[10]));
    this->triangles.push_back(new CTriangle(this->vertices[7], this->vertices[10], this->vertices[8]));
    this->triangles.push_back(new CTriangle(this->vertices[8], this->vertices[10], this->vertices[9]));
    
    // Lateral faces tris
    this->triangles.push_back(new CTriangle(this->vertices[0], this->vertices[7], this->vertices[5]));
    this->triangles.push_back(new CTriangle(this->vertices[0], this->vertices[6], this->vertices[7]));

    this->triangles.push_back(new CTriangle(this->vertices[4], this->vertices[5], this->vertices[7]));
    this->triangles.push_back(new CTriangle(this->vertices[4], this->vertices[7], this->vertices[8]));

    this->triangles.push_back(new CTriangle(this->vertices[4], this->vertices[8], this->vertices[9]));
    this->triangles.push_back(new CTriangle(this->vertices[4], this->vertices[9], this->vertices[3]));

    this->triangles.push_back(new CTriangle(this->vertices[2], this->vertices[3], this->vertices[9]));
    this->triangles.push_back(new CTriangle(this->vertices[2], this->vertices[9], this->vertices[10]));

    this->triangles.push_back(new CTriangle(this->vertices[2], this->vertices[10], this->vertices[11]));
    this->triangles.push_back(new CTriangle(this->vertices[2], this->vertices[11], this->vertices[1]));

    this->triangles.push_back(new CTriangle(this->vertices[1], this->vertices[11], this->vertices[0]));
    this->triangles.push_back(new CTriangle(this->vertices[0], this->vertices[11], this->vertices[6]));
}


/*
    AUTHOR: Marc-André Fortin-Leclerc
    DESCRIPTION: Generates a sheet with a specified amount of vertices in height and width.  By the way, the coordinates (-2,6,0),(2,6,0),(2,3,0),(-2,3,0) are hard coded in this constructor. 
 */
CSheet::CSheet(int height, int width) {
    
    //Add vertices of the sheet
    for (int j=0; j<height; ++j){
        for (int i=0; i<width;++i){
            
            //If it's the first vertex, we put it at (-2,6) by not adding +1 to i and j
            if(i==0 && j==0)this->vertices.push_back(new CVertex(i+j*(width),
                                                 *new CPoint3D((float)(i)*4/width-2,(float)(j)*3/(height)+3,0),
                                                 (float)i/width,(float)j/height));
            //If it's a vertex with i==0, we only add +1 to the y position of the vertex
            else if(i==0)this->vertices.push_back(new CVertex(i+j*(width),
                                                              *new CPoint3D((float)(i)*4/width-2,(float)(j+1)*3/(height)+3,0),
                                                              (float)i/width,(float)(j+1)/height));
            //If it's a vertex with j==0, we only add +1 to the x position of the vertex
            else if(j==0)this->vertices.push_back(new CVertex(i+j*(width),
                                                              *new CPoint3D((float)(i+1)*4/width-2,(float)(j)*3/(height)+3,0),
                                                              (float)(i+1)/width,(float)j/height));
            //Else we add +1 to both x and y position
            else this->vertices.push_back(new CVertex(i+j*(width),
                                                      *new CPoint3D((float)(i+1)*4/width-2,(float)(j+1)*3/(height)+3,0),
                                                      (float)(i+1)/width,(float)(j+1)/height));
        }
    }
    
    //Add triangles to our mesh using the "X" technique
    for (int j=0; j<height-1; ++j){
        for (int i=0; i<width-1;++i){
            if(j%2==0){
                if (i%2==0){
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width)],
                                                            this->vertices[i+j*(width)+1+width],
                                                            this->vertices[i+j*(width)+width]));
                    
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width)],
                                                            this->vertices[i+j*(width)+1],
                                                            this->vertices[i+j*(width)+1+width]));
                }
                else{
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width)+1+width],
                                                            this->vertices[i+j*(width)+width],
                                                            this->vertices[i+j*(width)+1]));
                    
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width)+width],
                                                            this->vertices[i+j*(width)],
                                                            this->vertices[i+j*(width)+1]));
                }
            }
            else{
                if (i%2==0){
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width)+width],
                                                            this->vertices[i+j*(width)],
                                                            this->vertices[i+j*(width)+1]));
                    
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width)+width],
                                                            this->vertices[i+j*(width)+1],
                                                            this->vertices[i+j*(width)+1+width]));
                }
                else{
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width)],
                                                            this->vertices[i+j*(width)+1+width],
                                                            this->vertices[i+j*(width)+width]));
                    
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width)],
                                                            this->vertices[i+j*(width)+1],
                                                            this->vertices[i+j*(width)+1+width]));
                }
            }
        }
    }
}

CRope::CRope() {
    
}
