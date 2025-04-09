#include <SFML/Graphics.hpp>

class Point {
protected:
    float x, y;
    sf::Color color;
    bool visible;
    float size;

public:
    Point(float x = 0, float y = 0, float s = 5, sf::Color c = sf::Color::White)
        : x(x), y(y), size(s), color(c), visible(true) {
    }

    virtual void show(sf::RenderWindow& window) {
        visible = true;
    }
    virtual void hide() {
        visible = false;
    }

    void getLocation(float& xl, float& yl) {
        xl = x;
        yl = y;
    }
    virtual void moveRandomly(float cost, const sf::Vector2u& windowSize) {
        x += (rand() / float(RAND_MAX) - 0.5f) * cost;
        y += (rand() / float(RAND_MAX) - 0.5f) * cost;

        x = std::max(size, std::min(x, (float)windowSize.x - size));
        y = std::max(size, std::min(y, (float)windowSize.y - size));
    }

    virtual void update() {
        if (rand() % 100 < 5) {
            color = sf::Color(rand() % 256, rand() % 256, rand() % 256);
        }
    }

    virtual void draw(sf::RenderWindow& window) {
        sf::CircleShape shape(size);
        shape.setPosition(x - size, y - size);
        shape.setFillColor(color);
        window.draw(shape);
    }

    virtual  ~Point() {}
};

class  Krug : public  Point {
protected:
    float  radius;
    float  startAngle, endAngle;

public:
    Krug(float  x = 0, float  y = 0, float  r = 10, sf::Color  c = sf::Color::White,
        float  start = 0, float  end = 360) : Point(x, y, 0, c), radius(r), startAngle(start), endAngle(end) {}

    void  draw(sf::RenderWindow& window)  override {
        if (endAngle - startAngle < 360) {
            sf::ConvexShape  sector;
            int  segments = 32;
            float  angleStep = (endAngle - startAngle) / segments;
            sector.setPointCount(segments + 2);

            sector.setPoint(0, sf::Vector2f(radius, radius));

            for (int i = 0; i <= segments; i++) {
                float  angle = startAngle + i * angleStep;
                float  px = radius + radius * cos(angle * 3.14159f / 180.f);
                float  py = radius + radius * sin(angle * 3.14159f / 180.f);
                sector.setPoint(i + 1, sf::Vector2f(px, py));
            }

            sector.setPosition(x - radius, y - radius);
            sector.setFillColor(color);
            window.draw(sector);
        }
        else {
            sf::CircleShape  circle(radius);
            circle.setPosition(x - radius, y - radius);
            circle.setFillColor(color);
            window.draw(circle);
        }
    }

    void  resizeSector(float  delta) {
        float  newAngle = (endAngle - startAngle) + delta;
        if (newAngle > 360)  newAngle = 360;
        if (newAngle < 10)  newAngle = 10;
        float  center = (startAngle + endAngle) / 2;
        startAngle = center - newAngle / 2;
        endAngle = center + newAngle / 2;
    }
};

class Ring : public Krug {
private:
    float width;

public:
    Ring(float x = 0, float y = 0, float r = 10, sf::Color c = sf::Color::White,
        float w = 2, float start = 0, float end = 360)
        : Krug(x, y, r, c, start, end), width(w) {
    }

    void draw(sf::RenderWindow& window) override {
        sf::Color backgroundColor = sf::Color(80, 80, 80);

        if (endAngle - startAngle < 360) {
            sf::ConvexShape outerSector;
            int  segments = 32;
            float  angleStep = (endAngle - startAngle) / segments;
            outerSector.setPointCount(segments + 2);

            outerSector.setPoint(0, sf::Vector2f(0, 0));

            for (int i = 0; i <= segments; i++) {
                float  angle = startAngle + i * angleStep;
                float  px = radius * cos(angle * 3.14159f / 180.f);
                float  py = radius * sin(angle * 3.14159f / 180.f);
                outerSector.setPoint(i + 1, sf::Vector2f(px, py));
            }

            outerSector.setPosition(x, y);
            outerSector.setFillColor(color);
            window.draw(outerSector);

            sf::ConvexShape innerSector;
            innerSector.setPointCount(segments + 2);
            innerSector.setPoint(0, sf::Vector2f(0, 0));

            for (int i = 0; i <= segments; i++) {
                float  angle = startAngle + i * angleStep;
                float  px = (radius - width) * cos(angle * 3.14159f / 180.f);
                float  py = (radius - width) * sin(angle * 3.14159f / 180.f);
                innerSector.setPoint(i + 1, sf::Vector2f(px, py));
            }

            innerSector.setPosition(x, y);
            innerSector.setFillColor(backgroundColor);
            window.draw(innerSector);
        }
        else {
            sf::CircleShape  outer(radius);
            outer.setPosition(x - radius, y - radius);
            outer.setFillColor(color);
            window.draw(outer);

            sf::CircleShape  inner(radius - width);
            inner.setPosition(x - radius + width, y - radius + width);
            inner.setFillColor(backgroundColor);
            window.draw(inner);
        }
    }


    void resizeSectorWidth(float  delta) {
        float  angleDelta = delta * 2;
        float  widthDelta = delta * 0.5f;

        float  newAngle = (endAngle - startAngle) + angleDelta;
        if (newAngle > 360)  newAngle = 360;
        if (newAngle < 10)  newAngle = 10;
        float  center = (startAngle + endAngle) / 2;
        startAngle = center - newAngle / 2;
        endAngle = center + newAngle / 2;

        width += widthDelta;
        if (width > radius - 2)  width = radius - 2;
        if (width < 2)  width = 2;
    }
};


int  main() {
    sf::RenderWindow  window(sf::VideoMode(800, 600), "SFML Shapes");
    window.setFramerateLimit(60);

    Point  testPoint(100, 100, 8, sf::Color::Green);
    Krug  testKrug(300, 200, 50, sf::Color::Red, 0, 120);
    Ring  testRing(500, 300, 70, sf::Color::Blue, 15, 0, 240);

    sf::Clock  clock;
    sf::Clock  moveClock;
    sf::Clock  resizeClock;

    while (window.isOpen()) {
        sf::Event  event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        if (moveClock.getElapsedTime().asSeconds() > 0.1f) {
            testPoint.moveRandomly(5, window.getSize());
            testKrug.moveRandomly(3, window.getSize());
            testRing.moveRandomly(2, window.getSize());
            moveClock.restart();
        }

        if (resizeClock.getElapsedTime().asSeconds() > 0.05f) {
            testKrug.resizeSector(sin(clock.getElapsedTime().asSeconds()) * 2);
            testRing.resizeSectorWidth(sin(clock.getElapsedTime().asSeconds()) * 0.1f);
            testRing.resizeSector(sin(clock.getElapsedTime().asSeconds()) * 1.5f);
            resizeClock.restart();
        }

        testPoint.update();
        testKrug.update();
        testRing.update();

        window.clear(sf::Color(80, 80, 80));
        testPoint.draw(window);
        testKrug.draw(window);
        testRing.draw(window);
        window.display();
    }

    return  0;
}

