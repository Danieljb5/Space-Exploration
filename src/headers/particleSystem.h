
#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <SFML/Graphics.hpp>
#include <math.h>

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:
    ParticleSystem(unsigned int count, float lifetime = 3.f, float speed = 1.f, sf::Color colour = sf::Color::White) :
    m_particles(count),
    m_vertices(sf::Points, count),
    m_lifetime(sf::seconds(lifetime)),
    m_emitter(0.f, 0.f),
    m_colour(colour),
    m_speed(speed)
    {}

    void setEmitter(sf::Vector2f position)
    {
        m_emitter = position;
    }

    void update(float dt)
    {
        for(std::size_t i = 0; i < m_particles.size(); i++)
        {
            Particle &p = m_particles[i];
            p.lifetime -= sf::seconds(dt);
            if(p.lifetime.asSeconds() <= 0)
                resetParticle(i);
            m_vertices[i].position += p.velocity * dt;
            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
            ratio *= m_colour.a;
            m_vertices[i].color = m_colour;
            m_vertices[i].color.a = static_cast<sf::Uint8>(ratio);
        }
    }

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = NULL;
        target.draw(m_vertices, states);
    }


private:
    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

    void resetParticle(std::size_t index)
    {
        float angle = (std::rand() % 360) * 3.14f / 180.f;
        float speed = (std::rand() % (int)(m_speed * 50.f)) + (m_speed * 50.f);
        m_particles[index].velocity = {std::cos(angle) * speed, std::sin(angle) * speed};
        float tmp = (m_lifetime.asSeconds() / 3.f) * 2000.f;
        float lifetime = ((std::rand() % (int)tmp) + ((m_lifetime.asSeconds() / 3.f) * 1000.f));
        m_particles[index].lifetime = sf::milliseconds(lifetime);

        m_vertices[index].position = m_emitter;
    }

    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
    sf::Color m_colour;
    float m_speed;
};

#endif