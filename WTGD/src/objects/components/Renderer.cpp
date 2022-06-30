#include <pch.h>
#include <objects/components/Renderer.h>
#include <objects/gameobjects/AreaObject.h>

WTGD::Renderer::Renderer() : Component("Renderer")
{
	texture = nullptr;
}

WTGD::Renderer::Renderer(std::string texture_path) : Component("Renderer")
{
	delete texture;
	texture->create(10, 10);
	if (!texture->loadFromFile(texture_path))
	{
		printf("No texture found at path: %s\n", texture_path.c_str());
		return;
	}

	const auto transform = get_owner()->get_component<Transform>();
	if (!transform)
	{
		printf("No suitable transform found!");
		system("pause");
		return;
	}

	transform->get_transform()->setTexture(texture);
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
	
	const auto owner = dynamic_cast<AreaObject*>(get_owner());
	if (!owner)
	{
		printf("No suitable owner found!");
		system("pause");
		return;
	}

	owner->transform->get_transform()->setTexture(texture);
}
