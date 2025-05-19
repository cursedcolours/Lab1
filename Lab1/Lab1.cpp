#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <time.h>

#define black al_map_rgb(0,0,0)			// Macros for common colors
#define white al_map_rgb(255,255,255)
#define height 640
#define width 480

int main(int argc, char** argv) {
	ALLEGRO_DISPLAY* display = NULL;

	if (!al_init()) {	// If allegro doesn't init properly, kill program
		fprintf(stderr, "failed to initialize allegro.\n");
		return -1;
	}

	display = al_create_display(width, height);
	if (!display) {		// if display doesn't init properly, kill program
		fprintf(stderr, "failed to create display. \n");
		return -1;
	}

	if (!al_init_primitives_addon()) {
		fprintf(stderr, "failed to initialize primitives. \n");
		return -1;
	}

	/* i have no idea what this does but Dr. Pollack said to add it
	in the textbook. */
	bool clear = false;
	bool done = false;

	srand(time(NULL));
	ALLEGRO_EVENT_QUEUE* eq = NULL;
	al_install_keyboard();
	eq = al_create_event_queue();
	al_register_event_source(eq, al_get_keyboard_event_source());
	al_register_event_source(eq, al_get_display_event_source(display));

	al_clear_to_color(black);	// blank black screen

	while (!done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(eq, &ev);

		
	}

	al_destroy_display(display);	// memory cleanup

	return 0;
}