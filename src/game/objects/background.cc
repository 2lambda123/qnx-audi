/*
# Copyright 2021, qnx-audi - https://github.com/h4570/qnx-audi
# Licenced under Apache License 2.0
# Sandro Sobczyński <sandro.sobczynski@gmail.com>
*/

#include "game/objects/background.hh"

// ----
// Constructors/Destructors
// ----

Background::Background(const Screen &screen)
    : m_image("background")
{
    m_scale = 1.0F;
#ifdef TARGET_AUDI
    m_width = (GLfloat)screen.getWidth();
    m_height = (GLfloat)screen.getHeight();
#else
    m_width = 640.0F;
    m_height = 360.0F;
#endif
}

Background::~Background()
{
}

// ----
// Methods
// ----

void Background::update()
{
    setRenderPackage();
    m_image.render(m_renderPackage);
}