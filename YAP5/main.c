#include <SFML/Graphics.h>

enum upNDown {
	up,
	down
};
enum leftNRight
{
	left,
	right
};

enum upNdown currentMoveByY;
enum leftNRight currentMoveByX;

sfBool rotateY = sfFalse;
sfBool rotateX = sfFalse;

int main()
{
	sfVideoMode mode = { 800,600,32 };
	sfRenderWindow* window;
	sfFont* font;
	sfText* text;
	sfEvent event;

	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	if (!window)
		return 1;

	font = sfFont_createFromFile("C:\\Windows\\Fonts\\arial.ttf");
	if (!font)
		return 1;

	text = sfText_create();
	sfText_setString(text, "Is it Buffer?");
	sfText_setFont(text, font);
	sfVector2f textPos = { 300,300 };
	sfText_setPosition(text, textPos);
	sfText_setCharacterSize(text, 50);
	sfText_setColor(text, sfColor_fromRGB(0, 0, 0));

	sfTime time = { 100 };
	
	sfRectangleShape *shape1 = sfRectangleShape_create();
	sfRectangleShape_setOrigin(shape1, (sfVector2f) {25,25});
	sfRectangleShape_setPosition(shape1, (sfVector2f) {400,400});
	sfRectangleShape_setSize(shape1, (sfVector2f) { 200, 200 });
	sfRectangleShape_setFillColor(shape1, sfRed);



	while (sfRenderWindow_isOpen(window))
	{
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		sfSleep(time);
		sfRenderWindow_clear(window, sfWhite);
		
		sfRenderWindow_drawRectangleShape(window, shape1,NULL);

		sfRectangleShape_rotate(shape1, 0.1);


		sfRenderWindow_drawText(window, text, NULL);
		sfRenderWindow_display(window);
	}

	sfRectangleShape_destroy(shape1);
	sfText_destroy(text);
	sfFont_destroy(font);
	sfRenderWindow_destroy(window);

	return 0;
}