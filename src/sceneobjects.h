//
//  sceneobjects.h
//  8trd147-d2
//
//  Created by Frédéric Bolduc on 2016-03-29.
//
//

#ifndef sceneobjects_h
#define sceneobjects_h

#include "mesh.h"

class CFloor : public CMesh {
public:
    CFloor();
    void Draw(GLint prog, float time);
};

class CPole : public CMesh {
public:
    CPole();
    void Draw(GLint prog, float time);
};

class CSheet : public CMesh {
public:
    CSheet(int height, int width);
    void Draw(GLint prog, float time);
};

class CRope : public CMesh {
public:
    CRope();
    void Draw(GLint prog, float time);
};

#endif /* sceneobjects_h */
