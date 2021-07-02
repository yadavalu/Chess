#include <GL/gl.h>

void draw(int width, int height) 
{
    int offset = 1;
    int size = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            glBegin(GL_QUADS);
                if (i % 2 == 0) glColor3f(1.f, 1.f, 1.f);
                else glColor3f(0.f, 0.f, 0.f);
                glVertex2i(size * i, size * j);
                glVertex2i(size * i + offset, size * j);
                glVertex2i(size * i + offset, size * j + offset);
                glVertex2i(size * i, size * j + offset);
            glEnd();
        }
    }
}
