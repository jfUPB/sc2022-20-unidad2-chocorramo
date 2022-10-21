#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->isEmpty = 1;
    eventList->head = NULL;
    eventList->last = NULL;
    return eventList;
}

void DestroyEventList(EventList *this)
{
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *found = this->head;
        if (this->isEmpty == 0)
        {
           while (found != NULL)
          {
              if (strcmp(name, found->eventName)==0)
              return found;
              found = found->next;
          }
        }
    else{
     found = NULL;
     return found;
    }
}

void AddEvent(EventList *this, Event *event) // funcional
{
      Event *agrega = this->head;

    if (this->isEmpty == 1)
    {
        this->isEmpty = 0;
        this->head = event;
        this->head->next = NULL;
        this->last = event;
        this->last->next = NULL;
    }
    else
    {
        while (agrega != NULL)
        {
            if (strcmp(agrega->eventName, event->eventName) == 0)
            {
                return;
                
            }
            
            agrega = agrega->next;
        }

        this->last->next = event;
        this->last = event;
    }
}

void RemoveEvent(EventList *this, char *name)
{
    
if (this->isEmpty == 0) //Revisión de que la lista no esté vacía, es decir contenga algo
    {
         Event *act = this->head->next;
         Event *anter = this->head;
         if(strcmp(name, anter->eventName)==0)
         {
              if(anter->next == NULL)
              {
                    this->head = NULL;
                    this->last = NULL;
                    this->isEmpty = 1;
                    DestroyEvent(anter);
              }
              else
              {
                    this->head=act;
                    DestroyEvent(anter);
              }
         } 
         while (act != NULL)
         {
              if(strcmp(name, act->eventName)==0)
              {
                   anter->next = act->next;
                   if (this->last->next == NULL)
                   {
                        this->last = anter;
                        DestroyEvent(act);
                   }
              }
              anter = act;
              act = act->next;
         }
    }

}

void ListEvents(EventList *this) // Funcional
{
    Event *ward = this->head;
    if (this->isEmpty == 1)
    {
        printf("empty\n");
    }
    else
    {
        while (ward != NULL)
        {
            printf("%s\n", ward->eventName);
            ward=ward->next;
        }
    }
}
