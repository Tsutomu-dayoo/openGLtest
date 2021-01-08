//
//  Floor.hpp
//  openGLdemo
//
//  Created by 山口勉 on 2021/01/08.
//  Copyright © 2021年 山口勉. All rights reserved.
//

#ifndef Floor_hpp
#define Floor_hpp

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

void Cuboid(double width, double height, double depth);
#endif /* Floor_hpp */
