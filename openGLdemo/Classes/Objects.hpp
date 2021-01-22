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
#include <OpenGL/OpenGL.h>
#include <stdio.h>

class Box{
public:
    double m_length_x;
    double m_length_y;
    double m_length_z;
    
    double m_xPosition;
    double m_yPosition;
    double m_zPosition;
    
public:
    Box(double x, double y, double z);//Boxの定義
    Box();
    virtual void Create();//Boxの生成
    void Location(double x, double y, double z);//Boxの位置
    
};

class Floor:public Box{
public:
    void Create() override;
};

class Wall:public Box{
public:
    void Create() override;
};

void Cuboid(double width, double height, double depth);
#endif /* Floor_hpp */
