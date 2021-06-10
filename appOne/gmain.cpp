#include"libOne.h"
int createTriangle() {
    struct SHAPE_VERTEX vertices[3];
    vertices[0].x = 0;
    vertices[0].y = -1;
    vertices[1].x = 1;
    vertices[1].y = 1;
    vertices[2].x = -1;
    vertices[2].y = 1;
    return createShape(vertices, 3);
    
}

int createPolygon() {
    const int NUM = 60;  //ここの値を変化させることで頂点をふやせる
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        vertices[i].x = sin(deg * i);
        vertices[i].y = -cos(deg * i);
    }
    return createShape(vertices, NUM);

}

int createStar() {
    const int NUM = 10; 
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        float radius = 0.5f + 0.5f * (i%2); //ここで一つおきに半分にする
        vertices[i].x = sin(deg * i) * radius;
        vertices[i].y = cos(deg * i) * radius;
    }
    return createShape(vertices, NUM);

}

int createHeart() {
    const int NUM = 60;
    struct SHAPE_VERTEX vertices[NUM];
    float deg = 360.0f / NUM;
    angleMode(DEGREES);
    for (int i = 0; i < NUM; i++) {
        float radius = 0.5f + 0.5f * (i % 2); 
        float t = deg * i;
        vertices[i].x =
         pow(sin(t), 3);
        vertices[i].y = -(
            13 * cos(t) -
            5 * cos(2 * t) -
            2 * cos(3 * t) -
            1 * cos(4 * t)) / 16;     //ハートを描くための公式
         
    }
    return createShape(vertices, NUM);

}
void gmain() {
    window(1000, 1000);
    int idx = createHeart();
    float deg = 0;
    angleMode(DEGREES);
    while (notQuit) {
       // deg += 1;
        clear(200);
        strokeWeight(5);
        fill(255, 200, 200);
        shape(idx, 500, 500, deg, 20);
       

      
    }
}
