#include <allegro5/allegro.h>
#include <stdio.h>

#define black al_map_rgb(0,0,0)
#define white al_map_rgb(255,255,255)

int main(int argc, char** argv) {
	ALLEGRO_DISPLAY* display = NULL;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro.\n");
		return -1;
	}

	display = al_create_display(640, 480);
	if (!display) {
		fprintf(stderr, "failed to create display. \n");
	}

	al_clear_to_color(black);

	al_flip_display();

	al_rest(10.0);

	al_destroy_display(display);

	return 0;
}