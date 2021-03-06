#pragma once
#include "BaseComponent.h"

class TextComponent;
class FpsComponent final : public Component
{
public:
	FpsComponent(GameObject* go, TextComponent* pTextComponent);
	~FpsComponent() override = default;
	FpsComponent(const FpsComponent&) = default;
	FpsComponent(FpsComponent&&) noexcept = default;
	FpsComponent& operator=(const FpsComponent&) = default;
	FpsComponent& operator=(FpsComponent&&) noexcept = default;


	virtual void Update() override;
	virtual void Render() const override {}

private:
	TextComponent* m_pTextComponent = nullptr;
};

