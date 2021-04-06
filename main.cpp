#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "CombSort.h"
//#include "CountingSort.h"
#include "MergeSort.h"

void must_init(bool test, const char* description)
{
    if (test) return;

    std::cout << "couldn't initialize " << description << std::endl;
    exit(1);
}

int main()
{
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
    ALLEGRO_DISPLAY* disp = al_create_display(799, 599); // starts from 0
    must_init(disp, "display");

    must_init(al_init_primitives_addon(), "primitives");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    MergeSort* sort = new MergeSort(800);

    al_start_timer(timer);
    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            // game logic goes here.
            sort->update();

            redraw = true;
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));

            // ----- render here -----
            sort->render();

            al_flip_display();

            redraw = false;
        }
    }

    // ----- TERMINATION -----
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    delete sort;

    return 0;
}