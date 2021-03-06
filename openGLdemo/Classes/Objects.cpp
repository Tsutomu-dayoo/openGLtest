//
//  Objects.cpp
//  openGLdemo
//
//  Created by 山口勉 on 2021/01/09.
//  Copyright © 2021年 山口勉. All rights reserved.
//

#include "Objects.hpp"
Box::Box(double x, double y, double z){
    this->m_length_x = x;
    this->m_length_y = y;
    this->m_length_z = z;
    
    m_xPosition = 5.0;
    m_yPosition = 0.0;
    m_yPosition = 0.0;
}

Box::Box(){
    m_length_x = 10.0;
    m_length_y = 10.0;
    m_length_z = 10.0;
    
    m_xPosition = 5.0;
    m_yPosition = 0.0;
    m_yPosition = 0.0;
}

void Box::Create(){
    //-------------------------------------------
    // 直方体の定義
    //-------------------------------------------
    GLdouble vertex[][3] = {
        { 0.0    , 0.0    , 0.0     },
        { m_length_x, 0.0    , 0.0      },
        { m_length_x, m_length_y, 0.0      },
        { 0.0    , m_length_y, 0.0      },
        { 0.0    , 0.0    , m_length_z },
        { m_length_x, 0.0    , m_length_z },
        { m_length_x, m_length_y, m_length_z },
        { 0.0    , m_length_y, m_length_z }
    };
    int face[][4] = {//面の定義
        { 0, 1, 2, 3 },
        { 1, 5, 6, 2 },
        { 5, 4, 7, 6 },
        { 4, 0, 3, 7 },
        { 4, 5, 1, 0 },
        { 3, 2, 6, 7 }
    };
    
    glPushMatrix();
    glColor3d(1.0, 0.0, 0.0);//色の設定
    glTranslated(m_xPosition, m_yPosition, m_yPosition);//平行移動値の設定
    glBegin(GL_QUADS);
    for (int j = 0; j < 6; ++j) {
        for (int i = 0; i < 4; ++i) {
            glVertex3dv(vertex[face[j][i]]);
        }
    }
    glEnd();
    glPopMatrix();
}

void Floor::Create(){
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

void Wall::Create(){
    m_length_x = 5;
    m_length_y = 2.5;
    m_length_z = 70;
    
    m_xPosition = 20;
    m_yPosition = 0;
    m_zPosition = 0;
    
    GLdouble vertex[][3] = {
        { 0.0    , 0.0    , 0.0     },
        { m_length_x, 0.0    , 0.0      },
        { m_length_x, m_length_z, 0.0      },
        { 0.0    , m_length_z, 0.0      },
        { 0.0    , 0.0    , m_length_y },
        { m_length_x, 0.0    , m_length_y },
        { m_length_x, m_length_z, m_length_y },
        { 0.0    , m_length_z, m_length_y }
    };
    int face[][4] = {//面の定義
        { 0, 1, 2, 3 },
        { 1, 5, 6, 2 },
        { 5, 4, 7, 6 },
        { 4, 0, 3, 7 },
        { 4, 5, 1, 0 },
        { 3, 2, 6, 7 }
    };
    
    glPushMatrix();
    glColor3d(1.0, 0.0, 0.0);//色の設定
    glTranslated(m_xPosition - (m_length_x/2), m_yPosition, m_zPosition);//平行移動値の設定
    glBegin(GL_QUADS);
    for (int j = 0; j < 6; ++j) {
        for (int i = 0; i < 4; ++i) {
            glVertex3dv(vertex[face[j][i]]);
        }
    }
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3d(1.0, 0.0, 0.0);//色の設定
    glTranslated(-m_xPosition - (m_length_x/2), m_yPosition, m_zPosition);//平行移動値の設定
    glBegin(GL_QUADS);
    for (int j = 0; j < 6; ++j) {
        for (int i = 0; i < 4; ++i) {
            glVertex3dv(vertex[face[j][i]]);
        }
    }
    glEnd();
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
