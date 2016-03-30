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
    this->vertices.push_back(new CVertex(0,  *new CPoint3D(-0.1,  0,  0),    0, 0));
    this->vertices.push_back(new CVertex(1,  *new CPoint3D(-0.05, 0,  0.08), 0, 0));
    this->vertices.push_back(new CVertex(2,  *new CPoint3D( 0.05, 0,  0.08), 0, 0));
    this->vertices.push_back(new CVertex(3,  *new CPoint3D( 0.1,  0,  0),    0, 0));
    this->vertices.push_back(new CVertex(4,  *new CPoint3D( 0.05, 0, -0.08), 0, 0));
    this->vertices.push_back(new CVertex(5,  *new CPoint3D(-0.05, 0, -0.08), 0, 0));
    
    // Top hex
    this->vertices.push_back(new CVertex(6,  *new CPoint3D(-0.1,  6,  0),    0, 0));
    this->vertices.push_back(new CVertex(7,  *new CPoint3D(-0.05, 6, -0.08), 0, 0));
    this->vertices.push_back(new CVertex(8,  *new CPoint3D( 0.05, 6, -0.08), 0, 0));
    this->vertices.push_back(new CVertex(9,  *new CPoint3D( 0.1,  6,  0),    0, 0));
    this->vertices.push_back(new CVertex(10, *new CPoint3D( 0.05, 6,  0.08), 0, 0));
    this->vertices.push_back(new CVertex(11, *new CPoint3D(-0.05, 6,  0.08), 0, 0));
    
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

CSheet::CSheet(int height, int width) {
    for (int j=0; j<=height; ++j){
        for (int i=0; i<=width;++i){
            this->vertices.push_back(new CVertex(i+j*(width+1), *new CPoint3D(i*4/10-2,j*3/10+3,0),i/width,j/height));
        }
    }
    for(int i=0; i<vertices.size(); ++i){
        std::cout << vertices[i]->X[0]<< "\t" << vertices[i]->X[1]<< "\t"  << vertices[i]->X[2] << "\n";
    }
    
    for (int j=0; j<height; ++j){
        for (int i=0; i<width;++i){
            if(j%2==0){
                if (i%2==0){
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width+1)],
                                                            this->vertices[i+j*(width+1)+2+width],
                                                            this->vertices[i+j*(width+1)+width+1]));
                    
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width+1)],
                                                            this->vertices[i+j*(width+1)+1],
                                                            this->vertices[i+j*(width+1)+2+width]));
                }
                else{
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width+1)+1+width],
                                                            this->vertices[i+j*(width+1)],
                                                            this->vertices[i+j*(width+1)+1]));
                    
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width+1)+1+width],
                                                            this->vertices[i+j*(width+1)+1],
                                                            this->vertices[i+j*(width+1)+2+width]));
                }
            }
            else{
                if (i%2==0){
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width+1)+1+width],
                                                            this->vertices[i+j*(width+1)],
                                                            this->vertices[i+j*(width+1)+1]));
                    
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width+1)+1+width],
                                                            this->vertices[i+j*(width+1)+1],
                                                            this->vertices[i+j*(width+1)+2+width]));
                }
                else{
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width+1)],
                                                            this->vertices[i+j*(width+1)+2+width],
                                                            this->vertices[i+j*(width+1)+width+1]));
                    
                    this->triangles.push_back(new CTriangle(this->vertices[i+j*(width+1)],
                                                            this->vertices[i+j*(width+1)+1],
                                                            this->vertices[i+j*(width+1)+2+width]));
                }
            }
        }
    }
    std::list<CTriangle*>::const_iterator itri;
    /*for(itri=this->triangles.begin(); itri != triangles.end(); ++itri){
        std::cout << (*itri)->v0->idx << "\t" << (*itri)->v1->idx<< "\t"  << (*itri)->v2->idx << "\n";
    }*/
}

CRope::CRope() {
    
}
