#include "EntityManager.h"

void UpdateEntities(LONGLONG DeltaTime, LPCRITICAL_SECTION *crit_section, struct blist *shared_mem, struct blist *local_list)
{

  BOOL res = TryEnterCriticalSection(crit_section);
  if(res == 0)
  {
    return;
  }
  size_t size = shared_mem->size;
  memcpy(local_list->planets, shared_mem->planets, sizeof(struct body) * size);
  LeaveCriticalSection(crit_section);
  struct body farthest_object = local_list->planets[size - 1];


  double kepler_scalar = 1000 / calcDVec3length(farthest_object.position);


  for(int i = 0; i < entityStack_Count(Entities); i++)
  {
    Entities->entities[i].position = dvec3ToVec3(multiplyDVec3ByDouble(local_list->planets[i].position, kepler_scalar));
    Entities->entities[i].velocity = dvec3ToVec3(multiplyDVec3ByDouble(local_list->planets[i].velocity, kepler_scalar));

  }


}

void RenderEntities(LONGLONG DeltaTime)
{
  for(int i = 0; i < entityStack_Count(Entities); i++)
  {
   glBindVertexArray(Entities->entities[i].vaoID);

   glEnableVertexAttribArray(0);
   glEnableVertexAttribArray(1);
   glEnableVertexAttribArray(2);

   transformation_SetPosition(Entities->entities[i].position);
   transformation_SetScale(&Entities->entities[i]);
   transformation_SetRotation(&Entities->entities[i]);

   m4_MVPMatrix = make_MVPMatrix();
   load_MVPMatrix();

   if(Entities->entities[i].mesh.edges->size == 0)
   {
     glDrawArrays(GL_TRIANGLES, 0, Entities->entities[i].triangleCount);
     continue;
   }
   glDrawElements(GL_TRIANGLES, Entities->entities[i].mesh.edges->size, GL_UNSIGNED_INT, (GLvoid*)0);
 }

 glDisableVertexAttribArray(0);
 glDisableVertexAttribArray(1);
 glDisableVertexAttribArray(2);
 glBindVertexArray(0);
}
