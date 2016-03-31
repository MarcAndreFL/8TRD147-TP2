#version 410

uniform mat4 modelview_proj_matrix;
uniform mat4 modelview_matrix;

uniform mat3 normal_matrix;
uniform vec3 light_pos;
uniform vec3 cam_pos;
uniform int isSheet;
uniform float time;
float speed=10.0;
float amplitude=0.2;
float frequency=0.3;
float pi = 3.14159;

float animTimeRise = 0.5;
float animTimeDown = 3;
float animSleepTime = 1;
float animEndSleepTime = 2;

in vec4     pos;
in vec2     texcoord;
in vec3     N0;

out vec2 var_texcoord;

out vec3 N;
out vec3 V;
out vec3 var_light_pos;


void main (void)
{
    if(isSheet==1){
        var_texcoord = texcoord;
    
        vec4 newPos = pos;
        float sTime = time;
        float currentAnimEndTime = animTimeRise;
        
        newPos.z =  amplitude*sin(frequency*3.14159*2.0*newPos.x+ speed*sTime);
        newPos.z += amplitude*sin(frequency*3.14159*2.0*newPos.y+ speed*sTime);
        
        if (time >= animTimeRise + animSleepTime && time < animSleepTime + animTimeDown + animTimeRise) {
            sTime = animSleepTime + animTimeDown + animTimeRise - time;
            currentAnimEndTime = animTimeDown;
        } else if (time >= animSleepTime + animTimeDown + animTimeRise
                   && time <= animSleepTime + animTimeDown + animTimeRise + animEndSleepTime) {
            sTime = 1.0/60.0;
        } else if (time >= animSleepTime + animTimeDown + animTimeRise + animEndSleepTime) {
            sTime = 0;
        }
        
        float offsetZ =  (6 - newPos.y) * clamp(sTime, 0.0, currentAnimEndTime) / currentAnimEndTime;
        newPos.z = newPos.z * offsetZ + offsetZ;

        
        
        
        
        N = normalize(normal_matrix*N0);
        V = normalize(vec3(modelview_matrix*newPos));
        var_light_pos = normal_matrix*light_pos;
    
        gl_Position	= modelview_proj_matrix*newPos;
    }
    else{
        var_texcoord = texcoord;
        
        N = normalize(normal_matrix*N0);
        V = normalize(vec3(modelview_matrix*pos));
        var_light_pos = normal_matrix*light_pos;
        
        gl_Position	= modelview_proj_matrix*pos;
    }
}


