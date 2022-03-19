#include "TribePCH.h"
#include "Tribe.h"
#include <thread>

#include "InputManager.h"
#include "SceneManager.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "GameObject.h"
#include "Scene.h"
#include "Timer.h"

#include "Components.h"


using namespace std;

/**
 * Code constructing the scene world starts here
 */
void Tribe::LoadGame() const
{
	Scene* scene = SceneManager::CreateScene("Demo");
	Font* pFont = ResourceManager::LoadFont("Lingua.otf", 36);

	// background
	auto go = new GameObject("Background");
	{
		const auto pTransform = go->AddComponent(new TransformComponent(go));
		go->AddComponent(new RenderComponent(go, pTransform, "background.jpg", true));
	}
	scene->Add(go);

	// fps object
	go = new GameObject("Fps object");
	{
		const auto pTransform = go->AddComponent(new TransformComponent(go));
		const auto pRender = go->AddComponent(new RenderComponent(go, pTransform));
		const auto pText = go->AddComponent(new TextComponent(go, pRender, " ", pFont, { 255,255,0,255 }));
		go->AddComponent(new FpsComponent(go, pText));
	}
	scene->Add(go);

	auto* pPeterPepper = new GameObject("PeterPepper");
	{
		auto pPeter = pPeterPepper->AddComponent(new PeterPepperComponent(pPeterPepper));

		InputManager::InputAction input;
			input.keyboardKey = SDL_SCANCODE_D;
			input.pCommand = new Command([pPeter] { pPeter->DoDamage(); });
		InputManager::AddInputMethod(input);
	}
	scene->Add(pPeterPepper);

	auto* pDeadDisplay = new GameObject("DeadSign");
	{
		const auto pTransform = pDeadDisplay->AddComponent(new TransformComponent(pDeadDisplay, 100,100));
		const auto pRender = pDeadDisplay->AddComponent(new RenderComponent(pDeadDisplay, pTransform));
		const auto pText = pDeadDisplay->AddComponent(new TextComponent(pDeadDisplay, pRender, "The player has died!", pFont, { 255,0,0,255 }, false));

		pDeadDisplay->AddComponent(new DeadSignComponent(pDeadDisplay, pText));
	}
	scene->Add(pDeadDisplay);

	auto* pLivesDisplay = new GameObject("LivesDisplay");
	{
		const auto pTransform = pLivesDisplay->AddComponent(new TransformComponent(pLivesDisplay, 100, 70));
		const auto pRender = pLivesDisplay->AddComponent(new RenderComponent(pLivesDisplay, pTransform));
		const auto pText = pLivesDisplay->AddComponent(new TextComponent(pLivesDisplay, pRender, "", pFont));

		pLivesDisplay->AddComponent(new RemainingLivesComponent(pLivesDisplay, pText));
	}
	scene->Add(pLivesDisplay);

	auto* pEnemyObject = new GameObject("Enemy");
	{
		auto pEnemy = pEnemyObject->AddComponent(new EnemyComponent(pEnemyObject));

		InputManager::InputAction input;
		input.keyboardKey = SDL_SCANCODE_F;
		input.keyboardStroke = InputManager::KeyboardStroke::released;
		input.pCommand = new Command([pEnemy] { pEnemy->KillEnemy(); });
		InputManager::AddInputMethod(input);
	}
	scene->Add(pEnemyObject);

	auto* pBurger = new GameObject("Burger");
	{
		auto pBurgerComp = pBurger->AddComponent(new BurgerComponent(pBurger));

		InputManager::InputAction input;
		input.keyboardKey = SDL_SCANCODE_G;
		input.keyboardStroke = InputManager::KeyboardStroke::released;
		input.pCommand = new Command([pBurgerComp] { pBurgerComp->DropBurger(); });
		InputManager::AddInputMethod(input);
	}
	scene->Add(pBurger);

	auto* pPointsDisplay = new GameObject("PointDisplay");
	{
		const auto pTransform = pPointsDisplay->AddComponent(new TransformComponent(pPointsDisplay, 100, 40));
		const auto pRender = pPointsDisplay->AddComponent(new RenderComponent(pPointsDisplay, pTransform));
		const auto pText = pPointsDisplay->AddComponent(new TextComponent(pPointsDisplay, pRender, "", pFont));

		pPointsDisplay->AddComponent(new PointsDisplayComponent(pPointsDisplay, pText));
	}
	scene->Add(pPointsDisplay);
}

void Tribe::Run()
{
	// intitializes the window
	RenderManager::Init();

	// tell the resource manager where he can find the game data
	ResourceManager::Init("../Data/");

	LoadGame();

	{			
		Timer::Start();
		for (bool running = true; running;)
		{
			// update all time related info
			Timer::Update();

			// process an input
			running = InputManager::ProcessInput();


			SceneManager::Update();

			RenderManager::Render();
			
			
			this_thread::sleep_for(Timer::GetSleepTime());
		}
	}
}
