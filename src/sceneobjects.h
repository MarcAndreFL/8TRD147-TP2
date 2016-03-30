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
};

class CPole : public CMesh {
public:
    CPole();
};

class CSheet : public CMesh {
public:
    CSheet(int height, int width);
};

class CRope : public CMesh {
public:
    CRope();
};

#endif /* sceneobjects_h */
