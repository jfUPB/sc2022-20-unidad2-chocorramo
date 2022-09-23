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
    
}

Event *SearchEvent(EventList *this, char *name)
{
}

void AddEvent(EventList *this, Event *event) // funcional
{
    if (this->isEmpty == 1)
    {
        this->isEmpty = 0;
        this->head = event;
        this->last = event;
        this->last->next = NULL;
    }
    else
    {
        this->last->next = event;
        this->last = event;
        this->last->next = NULL;
    }
}

void RemoveEvent(EventList *this, char *name)
{
    Event *ward = this->head;
    Event *ant;
    if (this->isEmpty == 0)
    {
        if (strcmp(this->head->eventName, name) == 0)
        {
            ward = this->head->next;
            DestroyEvent(this->head);
        }
        else
        {
            ant = this->head;
            this->head = this->head->next;
            while (this->head->next != NULL)
            {
                if (strcmp(this->head->eventName, name) == 0)
                {
                    ant->next = this->head->next;
                    DestroyEvent(this->head);
                }
                else
                {
                    ant = ant->next;
                    this->head = this->head->next;
                }
            }
        }
        if (strcmp(this->last->eventName, name) == 0)
        {
            ant->next=NULL;
            DestroyEvent(this->last);
        }
        this->head = ward;
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
        printf("%s\n", this->head->eventName);
        while (this->head->next != NULL)
        {
            this->head = this->head->next;
            printf("%s\n", this->head->eventName);
        }
        this->head = ward;
    }

    /*
    INTENTO FALLIDO
    int i = 0;
    Event *ward;

    if (this->isEmpty == 1)
    {
        printf("empty\n");
    }
    else
    {
        printf("%s\n", this->head->eventName);
        ward = this->head->next;

        if (ward->next != NULL)
        {
            while (i = 0)
            {

                printf("%s\n", ward->eventName);

                if (ward->next == NULL)
                {
                    i = 1;
                }
                else
                {
                    ward = ward->next;
                }
            }
        }
    }*/

    /*
    intento fallido #2
    while(i!=0)
        {
            if((this->head+i)->next==NULL)
            {
                i = 0;
                //printf("a");
            }
            else
            {
                printf("a");
                printf("%s\n",(this->head+i)->eventName);
                i++;
            }

        }*/
}
