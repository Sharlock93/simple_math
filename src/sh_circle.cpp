// 1 rad  = 180.0/M_PI degree
// 1 degree = M_PI/180.0 rads

#include <sh_circle.h>
#include <iostream>
#include <cmath>


sh_circle::sh_circle() {
    _position = vec2(0, 0);
    _r  = 5;
    _color = vec4(1, 1, 1, 1);
    _center = vec2(0, 0);

    float step = 360.0/CIRCLE_SEGMENTS;

    for(int i = 0; i < CIRCLE_SEGMENTS; i++) {
        _data[i] = vec2( (float)( _r*cos(i*step*torad) ),(float) ( _r*sin(i*step*torad) ));
    }

    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_data), _data, GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}


sh_circle::sh_circle(float x, float y, float r, vec2 direction,  vec4 color, vec2 center) {
    //make a circle from cos and sin, they both take radians as argument
    _position = vec2(x, y);
    _r  = r;
    _color = color;
    _center = center;
    _direction = direction;

    float step = 360.0/CIRCLE_SEGMENTS; //CIRCLE_SEGMENTS segments to make a circle

    for(int i = 0; i < CIRCLE_SEGMENTS; i++) {
        _data[i] = vec2((float)( r*cosf(i*step*torad) + x ), (float)( r*sinf(i*step*torad) + y));
    }

    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_data), _data, GL_DYNAMIC_DRAW);

}

void sh_circle::render(GLint vpos_attrib, GLint color_attrib, GLint model_trans) {
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glEnableVertexAttribArray(vpos_attrib);
    glVertexAttribPointer(vpos_attrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glUniform4fv(color_attrib, 1, (float *)&_color);
    glUniformMatrix4fv(model_trans, 1, GL_TRUE, &_transform[0][0]);   
    glDrawArrays(GL_TRIANGLE_FAN, 0, CIRCLE_SEGMENTS);
}

void sh_circle::set_position(float x, float y) {
    vec2 diff = vec2(x - _position.x, y - _position.y);
    _position = vec2(x, y);
    _transform = shatranslate(diff.x, diff.y, 0)*_transform;
}

void sh_circle::set_position(vec2 pos) {
    vec2 diff = pos - _position;
    _position = pos;
    _transform = shatranslate(diff.x, diff.y, 1)*_transform;
}

vec2 sh_circle::get_position() {
    // std::cout << "postiton: " << _position << std::endl;
    return _position;
}

void sh_circle::move_position(float speed) {
    vec2 diff = speed*_direction;
    _position = _position + diff;
    _center = _center + diff;
    _transform = shatranslate(diff.x, diff.y, 0)*_transform;
}

void sh_circle::move_position(float x, float y) {
    vec2 diff(x, y);
    _position = _position + diff;
    _center = _center + diff; 
    _transform = shatranslate(diff.x, diff.y, 0)*_transform;
}

void sh_circle::move_position(vec2 vel) {
    _position = _position + vel;
    _center = _center + vel; 
    _transform = shatranslate(vel.x, vel.y, 0)*_transform;
}

void sh_circle::set_size(float r) {
    // negative radius handle
    mat4 trans(1);

    trans = shatranslate(-_position.x, -_position.y, 0)*trans;
     
    if(r < 0)
        r *= -1;
    float ratio = r/_r;
    _r = r;
    trans = shascale(ratio, ratio, 1)*trans;
    trans = shatranslate(_position.x, _position.y, 0)*trans;
}

void sh_circle::change_size_by(float amount) {
    vec2 position = _position;
    
    move_position(-_position);
#if PONG_DEBUG
    std::cout << "Seg B " << std::endl;
    for(int i = 0; i < CIRCLE_SEGMENTS; i++) {
        std::cout << " @" << i << " " << _data[i];
        if(!(i%4)) {
            std::cout << std::endl;
        }
    }
    
    std::cout << std::endl << std::endl;
#endif


    float r = _r-amount;
    
    if(r < 0)
        r *= -1;
    
    float ratio = r/_r;

    _r = r;


    for(int i = 0; i < CIRCLE_SEGMENTS; i++) {
        _data[i] = _data[i]*ratio;
    }
    
    move_position(position);

#if PONG_DEBUG 

    std::cout << "Seg A " << std::endl;
    for(int i = 0; i < CIRCLE_SEGMENTS; i++) {
        std::cout << " @" << i << " " << _data[i];
        if(!(i%4)) {
            std::cout << std::endl;
        }
    }

#endif
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_data), _data, GL_DYNAMIC_DRAW);
}

float sh_circle::get_size() {
    // std::cout << "radius: " << _r << std::endl;
    return _r;
}


void sh_circle::set_color(vec4 color) {
    _color = color;
}

vec4 sh_circle::get_color() {
    return _color;
}

void sh_circle::rotate(float angle) {
    angle *= torad;
    mat2x2 rot(cos(angle), -sin(angle),
               sin(angle), cos(angle));

    vec2 cur_center = _center;
    move_position(-_center);
    
    _position = _position * rot;

    for(int i = 0; i < CIRCLE_SEGMENTS; i++) {
        _data[i] = _data[i]*rot;
    }

    move_position(cur_center);
    

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_data), _data, GL_DYNAMIC_DRAW);

}

void sh_circle::set_center(float x, float y) {
    _center = vec2(x, y);
}

void sh_circle::set_center(vec2 center) {
    _center = center;
}

sh_circle::~sh_circle() {
    // std::cout << "good bye world" << std::endl;
}
