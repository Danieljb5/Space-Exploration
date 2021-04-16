
#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        if(!m_tileset.loadFromFile(tileset))
            return false;
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        for(unsigned int x = 0; x < width; x++)
        {
            for(unsigned int y = 0; y < height; y++)
            {
                int tileNumber = tiles[x + y * width];
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
                sf::Vertex* quad = &m_vertices[(x + y * width) * 4];
                quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);
                quad[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y);
                quad[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y);
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }
        }
        return true;
    }

    bool isValid()
    {
        return m_vertices.getVertexCount() > 0;
    }

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = &m_tileset;
        target.draw(m_vertices, states);
    }

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

#endif