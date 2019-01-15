
#include "Modifier.h"
class FallingHealth :
	public Modifier
{
public:

	virtual char effect() override;
	FallingHealth(const sf::Texture & text, sf::RenderWindow * window, float speedy = 6.0);
	FallingHealth();
	~FallingHealth();
};
