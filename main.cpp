#include <random>
#include <raylib.h>
#include <vector>

constexpr float MAX_INITIAL_SPEED{300.0f};
constexpr float MAX_RADIUS{7.0f};
constexpr float MIN_RADIUS{4.0f};

constexpr float DRAG{0.99f};
constexpr float GRAVITY{9.81f};
constexpr float BOUNCE{0.8f};

// el circulo a dibujar
struct Particle {
  Vector2 position{};
  Vector2 velocity{};
  float radius{};
};

// genera un float aleatorio de forma random
float random_range(float min, float max) {
  static std::mt19937 generator{std::random_device()()};
  std::uniform_real_distribution<float> range{min, max};
  return range(generator);
}

class ParticleSimulation {
public:
  static constexpr size_t INITIAL_PARTICULES_AMOUNT{100};

public:
  ParticleSimulation() {
    for (size_t i{}; i < INITIAL_PARTICULES_AMOUNT; i++) {
      Particle particle{};

      particle.position = Vector2{random_range(0.0f, GetScreenWidth()),
                                  random_range(0.0f, GetScreenHeight())};
      particle.velocity =
          Vector2{random_range(-MAX_INITIAL_SPEED, MAX_INITIAL_SPEED),
                  random_range(-MAX_INITIAL_SPEED, MAX_INITIAL_SPEED)};
      particle.radius = random_range(MIN_RADIUS, MAX_RADIUS);

      m_particles.push_back(particle);
    };
  }

  // se dibujan las particulas
  void draw() {
    for (const auto &particle : m_particles) {
      DrawCircle(particle.position.x, particle.position.y, particle.radius,
                 WHITE);
    }
  }

  void update(float dt) {
    for (auto &particle : m_particles) {
      particle.velocity.x *= DRAG;
      particle.velocity.y *= DRAG;

      particle.velocity.y += GRAVITY;

      particle.position.x += particle.velocity.x * dt;
      particle.position.y += particle.velocity.y * dt;

      bool hit_right{particle.position.x + particle.radius >= GetScreenWidth()};
      bool hit_left{particle.position.x - particle.radius <= 0};

      bool hit_down{particle.position.y + particle.radius >= GetScreenHeight()};
      bool hit_up{particle.position.y - particle.radius <= 0};

      if (hit_right) {
        particle.position.x = GetScreenWidth() - particle.radius;
        particle.velocity.x *= -BOUNCE;
      }

      if (hit_left) {
        particle.position.x = particle.radius;
        particle.velocity.x *= -BOUNCE;
      }

      if (hit_up) {
        particle.position.y = particle.radius;
        particle.velocity.y *= -BOUNCE;
      }

      if (hit_down) {
        particle.position.y = GetScreenWidth() - particle.radius;
        particle.velocity.y *= -BOUNCE;
      }
    }
  }

private:
  std::vector<Particle> m_particles{};
};

int main() {
  const int WINDOW_HEIGHT = 1000;
  const int WINDOW_WIDTH = 1000;
  const int FPS = 120;

  InitWindow(WINDOW_HEIGHT, WINDOW_WIDTH, "particle");
  SetTargetFPS(FPS);

  ParticleSimulation particle_simulation{};

  while (!WindowShouldClose()) {
    PollInputEvents();
    BeginDrawing();
    particle_simulation.draw();
    particle_simulation.update(GetFrameTime());
    ClearBackground(BLACK);
    EndDrawing();
  }

  return 0;
}
