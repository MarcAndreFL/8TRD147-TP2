
#include "glUtil.h"
#include "point3d.h"
#import <Foundation/Foundation.h>

class CMesh;
class CSkyBox;


@interface CRenderer : NSObject {
	
    float rotx, roty, rotz;
}


-(id) init;
-(void) resizeWithWidth:(GLuint)width AndHeight:(GLuint)height;
-(void) render:(CMesh*)mesh position:(CPoint3D)pos scale:(CPoint3D)scale;
-(void) dealloc;
-(void)incr_rot:(float)dx :(float)dy :(float)dz;
-(void)incr_camposz:(float)dz;

// Variables uniforms
-(void)set_diffuse_contrib:(float)val;
-(void)set_ambiant_contrib:(float)val;
-(void)set_spec_contrib:(float)val;
-(void)set_mat_shininess:(float)val;

@end
