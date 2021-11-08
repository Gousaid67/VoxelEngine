#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <windows.h>
#include <gl/gl.h>

#include "staticRenderingVars.component.h"

#include "initGLFuncs.h"
#include "glext.h"
#include "commonIncludes.inc.h"

enum shadertype
{
  VERTEX = GL_VERTEX_SHADER,
  FRAGMENT = GL_FRAGMENT_SHADER
};

char* read_Shader(char** filename);
GLuint set_Shader(GLuint ID, char* path, enum shadertype shadertype);
void unset_Shader();

void detachDel_Shader(GLuint ID, GLuint shader);

#endif                                                                                                                                         
