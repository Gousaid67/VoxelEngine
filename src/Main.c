#include "window.h"
#include "worldManager.component.h"

int physics_thread(struct ENTRYPOINT_INPUT* input)
{
  volatile struct bodies* shared_mem = input->shared_mem;
  struct bodies bodylist = input->bodylist;
  LPCRITICAL_SECTION* crit_section = input->crit_section;

  free(input);

  while(1)
  {


    bodylist = ProcessPhysics(&bodylist);
    BOOL res = TryEnterCriticalSection(crit_section);
    if (res == 0)
    {
        continue;
    }
    memcpy(shared_mem, &bodylist, sizeof(bodylist));
    LeaveCriticalSection(crit_section);
  }



  return 86; //haha yes
}

int main()
{
  GH_InitWindow(physics_thread);
  return 0;
}
