#ifndef MASTER_RENDERER_H
#define MASTER_RENDERER_H

#include <windows.h>
#include <gl/gl.h>

#include "configurations/config.h"

#include "staticRenderingVars.component.h"
#include "staticShaderManager.component.h"

#include "CameraManager.h"
#include "ControlsManager.h"
#include "EntityManager.h"
#include "WorldManager.h"

#include "initGLFuncs.h"
#include "ComponentSystem.h"
#include "matrix.h"
#include "shaderClass.h"

LARGE_INTEGER DeltaTime;

GLvoid glInit(GLsizei WIDTH, GLsizei HEIGHT);
void glClearScene();

void Update(struct blist *local_list, LPCRITICAL_SECTION *crit_section);
void Render();

void CLEANUP();

#endif
