#include "SFApp.h"
auto score = 0;

SFApp::SFApp(std::shared_ptr<SFWindow> window) : fire(0), is_running(true), sf_window(window) {
  int canvas_w, canvas_h;
  SDL_GetRendererOutputSize(sf_window->getRenderer(), &canvas_w, &canvas_h);

  app_box = make_shared<SFBoundingBox>(Vector2(canvas_w, canvas_h), canvas_w, canvas_h);
  player  = make_shared<SFAsset>(SFASSET_PLAYER, sf_window);
  auto player_pos = Point2(canvas_w/2, 60);
  player->SetPosition(player_pos);

//Wall Placement for TOP and BOTTOM
  const int number_of_walls_top = 20;
  for(int i=0; i<number_of_walls_top; i++) {
    // place a wall at width/number_of_walls_top * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_top) * i + 15, 465.0f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int number_of_walls_bottom = 20;
  for(int i=0; i<number_of_walls_bottom; i++) {
    // place a wall at width/number_of_walls_bottom * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_bottom) * i + 15, 15.0f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  //Wall Placement for MIDDLE
  const int number_of_walls_middle_1 = 6;
  for(int i=0; i<number_of_walls_middle_1; i++) {
    // place a wall at width/number_of_walls_middle_1 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_bottom) * i + 80, 110.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int number_of_walls_middle_1_2 = 6;
  for(int i=0; i<number_of_walls_middle_1_2; i++) {
    // place a wall at width/number_of_walls_middle_1_2 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_bottom) * i + 398, 110.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }

  const int number_of_walls_middle_2 = 2;
  for(int i=0; i<number_of_walls_middle_2; i++) {
    // place a wall at width/number_of_walls_middle_2 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_bottom) * i + 15, 195.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int number_of_walls_middle_2_2 = 10;
  for(int i=0; i<number_of_walls_middle_2_2; i++) {
    // place a wall at width/number_of_walls_middle_2_2 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_bottom) * i + 180, 195.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int number_of_walls_middle_2_3 = 2;
  for(int i=0; i<number_of_walls_middle_2_3; i++) {
    // place a wall at width/number_of_walls_middle_2_3 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_bottom) * i + 595, 195.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int number_of_walls_middle_3 = 6;
  for(int i=0; i<number_of_walls_middle_3; i++) {
    // place a wall at width/number_of_walls_middle_3 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_bottom) * i + 80, 280.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int number_of_walls_middle_3_2 = 6;
  for(int i=0; i<number_of_walls_middle_3_2; i++) {
    // place a wall at width/number_of_walls_middle_3_2 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_bottom) * i + 398, 280.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int number_of_walls_middle_4 = 2;
  for(int i=0; i<number_of_walls_middle_4; i++) {
    // place a wall at width/number_of_walls_middle_4 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_bottom) * i + 15, 365.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int number_of_walls_middle_4_2 = 10;
  for(int i=0; i<number_of_walls_middle_4_2; i++) {
    // place a wall at width/number_of_walls_middle_4_2 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_bottom) * i + 180, 365.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int number_of_walls_middle_4_3 = 2;
  for(int i=0; i<number_of_walls_middle_4_3; i++) {
    // place a wall at width/number_of_walls_middle_4_3 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/number_of_walls_bottom) * i + 595, 365.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  
  //Walls to send Aliens to other side of screen
  const int edge_screen_1 = 1;
  for(int i=0; i<edge_screen_1; i++) {
    // place a wall at width/edge_screen_1 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/edge_screen_1) * i - 20, 155.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int edge_screen_2 = 1;
  for(int i=0; i<edge_screen_2; i++) {
    // place a wall at width/edge_screen_2 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/edge_screen_2) * i + 660, 240.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int edge_screen_3 = 1;
  for(int i=0; i<edge_screen_3; i++) {
    // place a wall at width/edge_screen_3 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/edge_screen_3) * i - 20, 325.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  const int edge_screen_4 = 1;
  for(int i=0; i<edge_screen_4; i++) {
    // place a wall at width/edge_screen_4 * i
    auto wall = make_shared<SFAsset>(SFASSET_WALL, sf_window);
    auto pos   = Point2((canvas_w/edge_screen_4) * i + 660, 415.f);
    wall->SetPosition(pos);
    walls.push_back(wall);
  }
  
  
  //Coin Placement
  const int number_of_coins = 10;
  for(int i=0; i<number_of_coins; i++) {
    // place a coin at width/number_of_coins * i
    auto coin = make_shared<SFAsset>(SFASSET_COIN, sf_window);
    auto pos   = Point2((canvas_w/number_of_coins) * i + 32, 60.f);
    coin->SetPosition(pos);
    coins.push_back(coin);
  }
    
  const int number_of_coins_2 = 10;
  for(int i=0; i<number_of_coins_2; i++) {
    // place a coin at width/number_of_coins_2 * i
    auto coin = make_shared<SFAsset>(SFASSET_COIN, sf_window);
    auto pos   = Point2((canvas_w/number_of_coins) * i + 32, 155.f);
    coin->SetPosition(pos);
    coins.push_back(coin);
  }
    
  const int number_of_coins_3 = 10;
  for(int i=0; i<number_of_coins_3; i++) {
    // place a coin at width/number_of_coins_3 * i
    auto coin = make_shared<SFAsset>(SFASSET_COIN, sf_window);
    auto pos   = Point2((canvas_w/number_of_coins) * i + 32, 240.f);
    coin->SetPosition(pos);
    coins.push_back(coin);
  }
    
  const int number_of_coins_4 = 10;
  for(int i=0; i<number_of_coins_4; i++) {
    // place a coin at width/number_of_coins_4 * i
    auto coin = make_shared<SFAsset>(SFASSET_COIN, sf_window);
    auto pos   = Point2((canvas_w/number_of_coins) * i + 32, 325.f);
    coin->SetPosition(pos);
    coins.push_back(coin);
  }
  
  
  //Alien Placement
  const int number_of_aliens = 1;
  for(int i=0; i<number_of_aliens; i++) {
    // place an alien at width/number_of_aliens * i
    auto alien = make_shared<SFAsset>(SFASSET_ALIEN, sf_window);
    auto pos   = Point2((canvas_w/number_of_aliens) * i + 595, 325.f);
    alien->SetPosition(pos);
    aliens.push_back(alien);
  }
  
  const int number_of_aliens_2 = 1;
  for(int i=0; i<number_of_aliens_2; i++) {
    // place an alien at width/number_of_aliens_2 * i
    auto alien = make_shared<SFAsset>(SFASSET_ALIEN, sf_window);
    auto pos   = Point2((canvas_w/number_of_aliens_2) * i + 595, 155.f);
    alien->SetPosition(pos);
    aliens.push_back(alien);
  }
  
  const int number_of_aliens_3 = 1;
  for(int i=0; i<number_of_aliens_3; i++) {
    // place an alien2 at width/number_of_aliens_3 * i
    auto alien2 = make_shared<SFAsset>(SFASSET_ALIEN2, sf_window);
    auto pos   = Point2((canvas_w/number_of_aliens_3) * i + 40, 415.f);
    alien2->SetPosition(pos);
    aliens2.push_back(alien2);
  }
  
  const int number_of_aliens_4 = 1;
  for(int i=0; i<number_of_aliens_4; i++) {
    // place an alien2 at width/number_of_aliens_4 * i
    auto alien2 = make_shared<SFAsset>(SFASSET_ALIEN2, sf_window);
    auto pos   = Point2((canvas_w/number_of_aliens_4) * i + 40, 240.f);
    alien2->SetPosition(pos);
    aliens2.push_back(alien2);
  }
  
  //Token Placement
  const int number_of_tokens = 1;
  for(int i=0; i<number_of_tokens; i++) {
    // place a token at width/number_of_tokens * i
    auto token = make_shared<SFAsset>(SFASSET_TOKEN, sf_window);
    auto pos   = Point2((canvas_w/number_of_tokens) * i + 320, 415.f);
    token->SetPosition(pos);
    tokens.push_back(token);
  }
  
  
  
 
}

SFApp::~SFApp() {
}

/**
 * Handle all events that come from SDL.
 * These are timer or keyboard events.
 */
void SFApp::OnEvent(SFEvent& event) {
  SFEVENT the_event = event.GetCode();
  switch (the_event) {
  case SFEVENT_QUIT:
    is_running = false;
    break;
  case SFEVENT_UPDATE:
    OnUpdateWorld();
    OnRender();
    break;
  case SFEVENT_PLAYER_LEFT:
    player->GoWest();
    for (auto w: walls)
    {
      if(player->CollidesWith(w))
      {
        player->GoEast();
      }
    }
    break;
  case SFEVENT_PLAYER_RIGHT:
    player->GoEast();
    for (auto w: walls)
    {
      if(player->CollidesWith(w))
      {
        player->GoWest();
      }
    }
    break;
  case SFEVENT_PLAYER_UP:
    player->GoNorth();
    for (auto w: walls)
    {
      if(player->CollidesWith(w))
      {
        player->GoSouth();
      }
    }
    break;
  case SFEVENT_PLAYER_DOWN:
    player->GoSouth();
    for (auto w: walls)
    {
      if(player->CollidesWith(w))
      {
        player->GoNorth();
      }
    }
    break;
  case SFEVENT_FIRE:
    fire ++;
    FireProjectile();
    break;
  }
}

int SFApp::OnExecute() {
  // Execute the app
  SDL_Event event;
  while (SDL_WaitEvent(&event) && is_running) {
    // wrap an SDL_Event with our SFEvent
    SFEvent sfevent((const SDL_Event) event);
    // handle our SFEvent
    OnEvent(sfevent);
  }
}

void SFApp::OnUpdateWorld() {
  // Update projectile positions
  for(auto p : projectiles) {
    p->GoNorth();
  }

  for(auto c: coins) {
    
  }
  
  for(auto t: tokens) {
    
  }

  // Update enemy positions
  for(auto a : aliens) {
  a->GoWestA();
  for (auto w: walls)
    {
      if(a->CollidesWith(w))
      {
        for(int i = 0; i < 200;i++){
          a->GoEast();
        }
      }
    } 
  }
  
  for(auto a2 : aliens2) {
  a2->GoEastA();
  for (auto w: walls)
    {
      if(a2->CollidesWith(w))
      {
        for(int i = 0; i < 200;i++){
          a2->GoWest();
        }
      }
    } 
  }
  

// Detect collisions between player and coin
  for(auto c : coins) {
      if(player->CollidesWith(c)) {
        player->HandleCollision();
        c->HandleCollision();
        score = score + 10;
        std::cout<<"Score: "<<score<<std::endl;
      }
    }
    
// Detect collisions between player and token
  for(auto t : tokens) {
      if(player->CollidesWith(t)) {
        player->HandleCollision();
        t->HandleCollision();
        score = score + 100;
        std::cout<<"Game Over - YOU WIN! Score: "<<score<<std::endl;
      }
    }
    
// Detect collisions between player and alien
  for(auto a : aliens) {
      if(player->CollidesWith(a)) {
        player->HandleCollision();
        a->HandleCollision();
        std::cout<<"Game Over - YOU LOSE! Score: "<<score<<std::endl;
      }
    }
    
  for(auto a2 : aliens2) {
      if(player->CollidesWith(a2)) {
        player->HandleCollision();
        a2->HandleCollision();
        std::cout<<"Game Over - YOU LOSE! Score: "<<score<<std::endl;
      }
    }

  // Detect collisions between projectile and wall
  for(auto p : projectiles) {
    for(auto w : walls) {
      if(p->CollidesWith(w)) {
        p->HandleCollision();
        w->HandleCollision();
      }
    }
  }

  // remove dead aliens (the long way)
  list<shared_ptr<SFAsset>> tmp;
  for(auto a : aliens) {
    if(a->IsAlive()) {
      tmp.push_back(a);
    }
  }
  aliens.clear();
  aliens = list<shared_ptr<SFAsset>>(tmp);
  
  list<shared_ptr<SFAsset>> tmp3;
  for(auto a2 : aliens2) {
    if(a2->IsAlive()) {
      tmp3.push_back(a2);
    }
  }
  aliens2.clear();
  aliens2 = list<shared_ptr<SFAsset>>(tmp3);
  
  // remove collected coins (the long way)
  list<shared_ptr<SFAsset>> tmp1;
  for(auto c : coins) {
    if(c->IsAlive()) {
      tmp1.push_back(c);
    }
  }
  coins.clear();
  coins = list<shared_ptr<SFAsset>>(tmp1);
  
  // remove collected token (the long way)
  list<shared_ptr<SFAsset>> tmp2;
  for(auto t : tokens) {
    if(t->IsAlive()) {
      tmp2.push_back(t);
    }
  }
  tokens.clear();
  tokens = list<shared_ptr<SFAsset>>(tmp2);
}

void SFApp::OnRender() {
  SDL_RenderClear(sf_window->getRenderer());

  // draw the player
  player->OnRender();

  for(auto p: projectiles) {
    if(p->IsAlive()) {p->OnRender();}
  }

  for(auto a: aliens) {
    if(a->IsAlive()) {a->OnRender();}
  }
  
  for(auto a2: aliens2) {
    if(a2->IsAlive()) {a2->OnRender();}
  }

  for(auto c: coins) {
    if(c->IsAlive()) {c->OnRender();}
  }
  
  for(auto t: tokens) {
    if(t->IsAlive()) {t->OnRender();}
  }

  for(auto w: walls) {
    w->OnRender();
  }
  
  
  
  // Switch the off-screen buffer to be on-screen
  SDL_RenderPresent(sf_window->getRenderer());
}

void SFApp::FireProjectile() {
  auto pb = make_shared<SFAsset>(SFASSET_PROJECTILE, sf_window);
  auto v  = player->GetPosition();
  pb->SetPosition(v);
  projectiles.push_back(pb);
}

