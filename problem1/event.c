#include "event.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Event *CreateEvent(char *name)
{
    Event *event = malloc(sizeof(Event));
    name[15]=0;//en event.h el nombre solo tiene 16 puestos
    strncpy (event -> eventName, name, strlen(name) + 1);//se incluye el null
    event -> next = NULL;
    return event;
}

void DestroyEvent(Event *this)
{
    free(this);
}
