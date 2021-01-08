//
//  Floor.cpp
//  openGLdemo
//
//  Created by 山口勉 on 2021/01/08.
//  Copyright © 2021年 山口勉. All rights reserved.
//

#include "Floor.hpp"

void Floor::CreateFloor(){
    m_length_x = 300;
    m_length_y = 300;
    //m_length_z = 5.0;
    
    //Cuboid(m_length_x, m_length_y, m_length_z);
    glBegin(GL_LINES);
    glColor3b(0.0 , 0.0 , 0.0);
    for(double ly = -m_length_y ;ly <= m_length_y; ly+=10.0){
        glVertex3d(-m_length_y, ly,0);
        glVertex3d(m_length_y, ly,0);
    }
    for(double lx = -m_length_y ;lx <= m_length_y; lx+=10.0){
        glVertex3d(lx, m_length_y,0);
        glVertex3d(lx, -m_length_y,0);
        
        
    }
    glEnd();
}

void Cuboid::draw(){
    glPushMatrix();
    
    glPopMatrix();
}

void Cuboid(double width, double height, double depth){
    glBegin(GL_QUADS);
    //前
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(width/2,height/2,depth/2);
    glVertex3f(-width/2,height/2,depth/2);
    glVertex3f(-width/2,-height/2,depth/2);
    glVertex3f(width/2,-height/2,depth/2);
    
    //左
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(width/2,height/2,depth/2);
    glVertex3f(width/2,height/2,-depth/2);
    glVertex3f(width/2,-height/2,-depth/2);
    glVertex3f(width/2,-height/2,depth/2);
    
    //右
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(-width/2,height/2,-depth/2);
    glVertex3f(-width/2,height/2,depth/2);
    glVertex3f(-width/2,-height/2,depth/2);
    glVertex3f(-width/2,-height/2,-depth/2);
    
    //後
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(width/2,height/2,-depth/2);
    glVertex3f(-width/2,height/2,-depth/2);
    glVertex3f(-width/2,-height/2,-depth/2);
    glVertex3f(width/2,-height/2,-depth/2);
    
    //上
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(width/2,height/2,depth/2);
    glVertex3f(-width/2,height/2,depth/2);
    glVertex3f(-width/2,height/2,-depth/2);
    glVertex3f(width/2,height/2,-depth/2);
    
    //下
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(width/2,-height/2,depth/2);
    glVertex3f(-width/2,-height/2,depth/2);
    glVertex3f(-width/2,-height/2,-depth/2);
    glVertex3f(width/2,-height/2,-depth/2);
    
    glEnd();

}
