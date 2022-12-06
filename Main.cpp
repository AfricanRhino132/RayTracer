#include "Renderer/Renderer.h"
#include "Objects/Sphere.h"
#include <iostream>

int main(int, char**)
{
	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow(600, 300);

	Canvas canvas(600, 300, renderer);

	auto sphere = std::make_unique<Sphere>(glm::vec3{ 0, 0, 1 }, 0.5f, nullptr);

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}

		// render scene
		canvas.Clear({ 0, 0, 0, 1});
		renderer.Render(canvas, sphere.get());
		canvas.Update();

		renderer.CopyCanvas(canvas);
		renderer.Present();
	}
	renderer.Shutdown();
	return 0;
}
