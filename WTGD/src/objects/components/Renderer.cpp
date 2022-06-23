#include "Renderer.h"

WTGD::Renderer::Renderer()
{
}

WTGD::Renderer::Renderer(std::string texture_path)
{
}

WTGD::Renderer::~Renderer()
{
	delete texture;
}

void WTGD::Renderer::set_texture(std::string texture_path)
{
}
