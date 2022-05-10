#include "EntityManager.h"

void UpdateEntities(LONGLONG DeltaTime)
{
  return;
}

void RenderEntities(LONGLONG DeltaTime)
{
   for(int i = 0; i < entityStack_Count(Entities); i++)
   {
     glBindVertexArray(Entities->entities[i].vaoID);

     glEnableVertexAttribArray(0);
     glEnableVertexAttribArray(1);
     glEnableVertexAttribArray(2);

     transformation_SetPosition(&Entities->entities[i]);
     transformation_SetRotation(&Entities->entities[i]);
     transformation_SetScale(&Entities->entities[i]);

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
