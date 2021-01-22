//
//  main.cpp
//  openGLdemo
//
//  Created by 山口勉 on 2018/11/29.
//  Copyright © 2018年 山口勉. All rights reserved.
//

#include <iostream>
#define GL_SILENCE_DEPRECATION
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include "Objects.hpp"

const GLfloat lightPosition1[4] = {0.0f,3.0f, 5.0f, 1.0f};
const GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 };
const GLfloat lightPosition2[4] = {5.0f,3.0f, 0.0f, 1.0f};
const GLfloat red[] = { 1.0, 0.0, 0.0, 1.0 };

const GLfloat teapotAmbient[4] = {0.3f,0.5f, 0.0f, 1.0f};
const GLfloat teapotDiffuse[4] = {1.0f,1.0f, 0.3f, 1.0f};
const GLfloat teapotSpecular[4] = {1.0f,1.0f, 1.0f, 1.0f};
const GLfloat teapotShininess[4] = {20.0f};

//----------------------------------------------------
// 直方体の定義
//----------------------------------------------------
GLdouble vertex[][3] = {
    { 0.0, 0.0, 0.0 },
    { 2.0, 0.0, 0.0 },
    { 2.0, 2.0, 0.0 },
    { 0.0, 2.0, 0.0 },
    { 0.0, 0.0, 30.0 },
    { 2.0, 0.0, 30.0 },
    { 2.0, 2.0, 30.0 },
    { 0.0, 2.0, 30.0 }
};
int face[][4] = {//面の定義
    { 0, 1, 2, 3 },
    { 1, 5, 6, 2 },
    { 5, 4, 7, 6 },
    { 4, 0, 3, 7 },
    { 4, 5, 1, 0 },
    { 3, 2, 6, 7 }
};

void setup(void) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//背景色
    glEnable(GL_DEPTH_TEST);//デプスバッファを使用
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition1);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
    glLightfv(GL_LIGHT0, GL_SPECULAR, red);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, green);
    glLightfv(GL_LIGHT1, GL_SPECULAR, green);
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess);
}

void draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//バッファの消去
    
    /*
    //直方体
    glPushMatrix();
    glColor3d(1.0, 0.0, 0.0);//色の設定
    glTranslated(30.0, 50.0, 0.0);//平行移動値の設定
    glBegin(GL_QUADS);
    for (int j = 0; j < 6; ++j) {
        for (int i = 0; i < 4; ++i) {
            glVertex3dv(vertex[face[j][i]]);
        }
    }
    glEnd();
    glPopMatrix();
    */
    
    Wall wall;
    wall.Create();
    Floor floor;
    floor.Create();
    
    Box box;
    box.Create();
    //glutSolidTeapot(0.5);
    
    glFlush();
}


void resize(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)width/(double)height, 0.1, 1000.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, -150.0, 70.0,//0.0, -100.0, 0.0,//視点の位置,x,y,z
              0.0, 100.0, 0.0,//0.0, 100.0, 0.0,//視界の中心位置の参照座標x,y,z
              0.0, 0.0, 1.0);//視界の上方向のベクトルx,y,z
}
/* 図形の描画 */
void display(void){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutWireTeapot(0.5);
    glFlush();
}


int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Wire_teapot");//Windowの生成
    glutReshapeFunc(resize);
    glutDisplayFunc(draw);//描画時に呼び出す関数
    setup();
    glutMainLoop();
    return 0;
}
