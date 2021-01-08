//
//  Objects.hpp
//  openGLdemo
//
//  Created by 山口勉 on 2021/01/09.
//  Copyright © 2021年 山口勉. All rights reserved.
//

#ifndef Objects_hpp
#define Objects_hpp

#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>

#include <stdio.h>

class Floor{
private:
    double m_length_x;
    double m_length_y;
    double m_length_z;
    
public:
    void CreateFloor();
};

class Wall{
private:
    double m_width;
    double m_height;
    double m_depth;
    
    double m_xPosition;
    double m_yPosition;
    double m_zPosition;
    
public:
    void Draw();
};

void Cuboid(double width, double height, double depth);
#endif /* Floor_hpp */
