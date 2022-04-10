#include "TribePCH.h"
#include "LevelComponent.h"
#include "RenderManager.h"
#include "ResourceManager.h"

LevelComponent::LevelComponent(GameObject* go, int maxHeight, const std::string& tileSprite, const glm::ivec2& tileSize)
	: Component(go)
	, m_Height(maxHeight)
	, m_TileSize(tileSize)
	, m_pTexture(ResourceManager::LoadTexture(tileSprite))
{

}

void LevelComponent::Update()
{
	
}

void LevelComponent::Render() const
{
	
}

bool LevelComponent::GetPositionForTile(const glm::ivec2& location, glm::vec3& position)
{
	if (location.x < 0 || location.x >= m_Width)
		throw "Invalid Crossection horizontal location";

	if (location.y < 0 || location.y >= m_Height)
		throw "Invalid Crossection vertical location";

	
	const SDL_Rect windowSize = RenderManager::GetWindowRect();

	// formula to calculate where the crossection should be rendered

	// remove the margin from both sides from window
	position.x = float(windowSize.w - m_HorizontalMargin);
	position.y = float(windowSize.h - m_TopMargin);
	// divide by levelWidth/Height and multiply with the location.x/y to find the position
	position.x /= m_Width;
	position.x += location.x * (m_TileSize.x * g_PixelScale);
	position.y /= m_Height;
	position.y += location.y * (m_TileSize.y * g_PixelScale);
	// add the margins back
	position.x += m_HorizontalMargin;
	position.y += m_TopMargin;

	return true;
}
