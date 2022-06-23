#include "Renderer.h"

WTGD::Renderer::Renderer() : Component("Renderer")
{
	texture = nullptr;
}

WTGD::Renderer::Renderer(std::string texture_path) : Component("Renderer")
{
}

WTGD::Renderer::~Renderer()
{
	delete texture;
}

void WTGD::Renderer::set_texture(std::string texture_path)
{
	delete texture;
	texture = new sf::Texture();
	if (!texture->loadFromFile(texture_path))
	{
		printf("No texture found at path: %s\n", texture_path.c_str());
		return;
	}
	

}
