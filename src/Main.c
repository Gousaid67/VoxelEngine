#include "window.h"
#include "./configurations/bodies.h"
#include "parser.h"


int physics_thread()
{

    struct bodies bodylist;
    LoadPlanetData(&bodylist);

    ProcessPhysics(&bodylist);

    return 86; //haha yes
}

int main()
{
  GH_InitWindow(physics_thread);
  return 0;
}
