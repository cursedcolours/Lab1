#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

#define black al_map_rgb(0,0,0)			// Macros for common colors
#define white al_map_rgb(255,255,255)
#define blue al_map_rgb(117, 191, 207)
#define brown al_map_rgb(163, 130, 96)
#define peach al_map_rgb(240, 206, 178)

#define height 480						// macros to make changing h/w easy
#define width 640

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

	if (!al_init_primitives_addon()) {	// if primitives don't init properly, kill program
		fprintf(stderr, "failed to initialize primitives. \n");
		return -1;
	}
	
	al_clear_to_color(black);	// blank black screen

	// drawing our face
	al_draw_ellipse(160.0, 120.0, 75.0, 30.0, white, 1); // draws first eye socket
	al_draw_ellipse(480.0, 120.0, 75.0, 30.0, white, 1); // draws second eye socket

	al_draw_rectangle(90.0, 80.0, 230.0, 85.0, brown, 2); // draws first eyebrow
	al_draw_rectangle(410.0, 80.0, 550.0, 85.0, brown, 2); // draws second eyebrow

	al_draw_filled_triangle(320.0, 140.0, 250.0, 240.0, 380.0, 240.0, peach); // draw nose

	al_draw_filled_circle(160, 120, 30, blue); // draws first iris
	al_draw_filled_circle(480, 120, 30, blue); // draws second iris

	// white line for mouth

	al_flip_display();
	al_rest(10.0); // keeps image on screen for 30 secs

	al_destroy_display(display);	// memory cleanup

	return 0;
}