#include "MasterRenderer.h"

GLvoid glInit(GLsizei WIDTH, GLsizei HEIGHT)
{
  programIDs = new_uintVector(2);
  vbosIDs = new_uintVector(1);
  vaosIDs = new_uintVector(1);
  indexbuffersIDs = new_uintVector(1);

  Entities = init_EntityStack();

  Entity default_entity = { .vaoID = -1 };
  SelectedEntity = default_entity;

  setup_Camera(new_vec3(0.0f, 1.0f, 2.5f));

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glCullFace(GL_BACK);

  glViewport(0, 0, 1920, 1080);

  /*
  for(int StartFuncs_iterator = 0; StartFuncs_iterator < StartFuncs->size; StartFuncs_iterator++)
  { StartFuncs->func_ptrs[StartFuncs_iterator](); }
  */
}

void glClearScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Update(struct blist *local_list, struct blist *shared_mem , LPCRITICAL_SECTION *crit_section)
{
  /*
  for(int UpdateFuncs_iterator = 0; UpdateFuncs_iterator < UpdateFuncs->size; UpdateFuncs_iterator++)
  { UpdateFuncs->func_ptrs[UpdateFuncs_iterator](); }
  */

 
  UpdateEntities(crit_section, shared_mem, local_list);
  UpdateCamera(DeltaTime.QuadPart);
  UpdateControls(DeltaTime.QuadPart);
}

void Render()
{
  glDisable(GL_CULL_FACE);
  glClearScene();
  RenderEntities(DeltaTime.QuadPart);
  glEnable(GL_CULL_FACE);
}

void CLEANUP()
{
  for(int i = 0; i < vaosIDs->size; i++)
  {
    //glDeleteVertexArrays(1, vaosIDs->values[i]);
  }

  for(int i = 0; i < vbosIDs->size; i++)
  {
    //glDeleteBuffers(1, vbosIDs->values[i]);
  }

  cleanUpEntities();
}
