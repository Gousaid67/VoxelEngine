#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <windows.h>
#include <gl/gl.h>

#include "staticRenderingVars.component.h"

#include "initGLFuncs.h"
#include "glext.h"
#include "commonIncludes.inc.h"

// Stages of shading
// VERTEX -> TESS_CONTROL -> TESS_EVALUATION -> GEOMETRY -> FRAGMENT -> COMPUTE
enum shadertype
{
  VERTEX = GL_VERTEX_SHADER,
  TESS_CONTROL = GL_TESS_CONTROL_SHADER,
  TESS_EVALUATION = GL_TESS_EVALUATION_SHADER,
  GEOMETRY = GL_GEOMETRY_SHADER,
  FRAGMENT = GL_FRAGMENT_SHADER,
  COMPUTE = GL_COMPUTE_SHADER
};

char* read_Shader(char** filename);
GLuint set_Shader(GLuint ID, char* path, enum shadertype shadertype);
void unset_Shader();

void detachDel_Shader(GLuint ID, GLuint shader);

#endif                                                                                                                                         
