#include "Scene.hpp"

Scene::Scene() {}

Scene::~Scene() {
	Shutdown();
}

void Scene::Startup(SDL_Renderer* aRenderer) {
	mRenderer = aRenderer;

	// ------ Initilize Enemy ------
	int row = 0;
	int col = 0;
	for (int i=0; i<40; i++) {
		if (i%10==0) {
			row++;
			col = 0;
		}
		
		std::shared_ptr<EnemyGameEntity> theEnemy = std::make_shared<EnemyGameEntity>(mRenderer);
		theEnemy->AddDefaultTransform();
		theEnemy->GetTransformComponent()->SetXY(col*40+120, row*40); // Set the initial position
		col++;

		std::shared_ptr<Collision2DComponent> theCollision2D = std::make_shared<Collision2DComponent>();
		std::shared_ptr<TextureComponent> theEnemyTexture = std::make_shared<TextureComponent>();
		theEnemyTexture->CreateTextureComponent(mRenderer, "./art/enemy.bmp"); 

		theEnemy->AddComponent(theCollision2D);
		theEnemy->AddComponent(theEnemyTexture);
		
		// ------ Create a projectile for the enemy ------
		std::shared_ptr<Projectile> theProjectile = std::make_shared<Projectile>();
		theProjectile->AddDefaultTransform();
		theProjectile->GetTransformComponent()->SetW(10.f);

		std::shared_ptr<Collision2DComponent> theProjectileCollision2D = std::make_shared<Collision2DComponent>();
		std::shared_ptr<TextureComponent> theProjectileTexture = std::make_shared<TextureComponent>();
		theProjectileTexture->CreateTextureComponent(aRenderer, "./art/rocket.bmp");

		theProjectile->AddComponent(theProjectileTexture);
		theProjectile->AddComponent(theProjectileCollision2D);
		theEnemy->AddGameEntity(theProjectile);
		// ------ Create a projectile for the enemy ------

		enemies.push_back(std::move(theEnemy));
	}
	// ------ Initilize Enemy ------

	// ------ Initilize Hero ------
	hero = std::make_shared<GameEntity>();
	hero->AddDefaultTransform();
	hero->GetTransformComponent()->SetXY(gWindow_w/2 - 32/2, gWindow_h-40);

	std::shared_ptr<TextureComponent> theHeroTexture = std::make_shared<TextureComponent>();
	std::shared_ptr<Collision2DComponent> theHeroCollision2D = std::make_shared<Collision2DComponent>();
	std::shared_ptr<InputComponent> theInputComponent = std::make_shared<InputComponent>(); 
	theHeroTexture->CreateTextureComponent(mRenderer, "./art/hero.bmp");
	hero->GetTransformComponent()->SetW(18.f); // Make our hero smaller

	hero->AddComponent(theHeroTexture);
	hero->AddComponent(theInputComponent);
	hero->AddComponent(theHeroCollision2D);

	// ------ Create a projectile for the hero ------
	std::shared_ptr<Projectile> theProjectile = std::make_shared<Projectile>(); 
	theProjectile->AddDefaultTransform();
	theProjectile->GetTransformComponent()->SetW(20.f);
	theProjectile->SetSpeed(200.f);
	
	std::shared_ptr<Collision2DComponent> theProjectileCollision2D = std::make_shared<Collision2DComponent>();
	std::shared_ptr<TextureComponent> theProjectileTexture = std::make_shared<TextureComponent>();
	theProjectileTexture->CreateTextureComponent(aRenderer, "./art/rocket.bmp");

	theProjectile->AddComponent(theProjectileCollision2D);
	theProjectile->AddComponent(theProjectileTexture);
	hero->AddGameEntity(theProjectile);
	// ------ Create a projectile for the hero ------
	// ------ Initilize Hero ------
}

void Scene::Shutdown() {}

void Scene::Input(float deltaTime) {
	hero->Input(deltaTime);
}

void Scene::Update(float deltaTime) {
	// ------ Update Hero ------
	/// Update hero first to prevent intersecting with the projectile at the beginning
	hero->Update(deltaTime);

	// ------ Update Enemy ------
	for (int i=0; i<enemies.size(); i++) {
		std::shared_ptr<Projectile> theHeroProjectile = std::dynamic_pointer_cast<Projectile>(hero->GetGameEntityAt(0));
		std::shared_ptr<Projectile> theEnemyProjectile = std::dynamic_pointer_cast<Projectile>(enemies[i]->GetGameEntityAt(0));
		bool enemyIsHit = enemies[i]->IsIntersect(theHeroProjectile);
		bool gameOver = hero->IsIntersect(theEnemyProjectile);
		if (enemyIsHit && enemies[i]->IsRenderable() && theHeroProjectile->IsRenderable()) {
			//SDL_Log("Collide");
			enemies[i]->SetRenderable(false);
			SDL_Log("Enemy %i is removed", i);
			mPoints += 1;
			SDL_Log("Points: %d\n", mPoints);
		}
	
		if (gameOver && enemies[i]->IsRenderable()) {
			SDL_Log("You Lossss!");
			SDL_Log("Total Points: %d\n", mPoints);
			SetActiveStatus(false);
		}
		enemies[i]->Update(deltaTime);
		theEnemyProjectile->Update(deltaTime);
	}

	if (mPoints == 40) {
		SDL_Log("You WIN!");
		SetActiveStatus(false);
	}

}

void Scene::Render() {
	// Select the color for drawing.
	SDL_SetRenderDrawColor(mRenderer, 32, 32, 64, SDL_ALPHA_OPAQUE);
	// Clear the entire screen to our selected color.
	SDL_RenderClear(mRenderer);

	// ------ Render Enemy ------
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	for (int i=0; i<enemies.size(); i++) {
		enemies[i]->Render(mRenderer);
	}

	// ------ Render Hero ------
	hero->Render(mRenderer);

	// Up until now everything was drawn behind the scenes.
	// This will show the new contents of the window.
	SDL_RenderPresent(mRenderer);
}


void Scene::SetActiveStatus(bool status) {
	mIsActive = status;
}

bool Scene::IsActive() {
	return mIsActive;
}
