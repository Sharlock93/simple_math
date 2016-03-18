#include "../headers/sh_diamond_square.h"
#include <random>
#include <iostream>
int rough = 0;

//Note(sharo): converts a 2D index with 'weight' column per row
//into 1D index for C arrays.
inline int convert_to_index(int row, int col, int weight) {
    //Note(sharo): this wraps around so the points on the edges are equal
    //thus you must subtract or add one to the row or column to fix the off
    //by one error.
    
    if(row > weight) row++; 
    if(col > weight) col++;
    if(row <= -1) row--; 
    if(col <= -1) col--; 

    row = row%weight;
    col = col%weight;

    if(row < 0) {
        while(row < 0)
            row += weight;
    }

    if(col < 0) { 
        while(col < 0)
            col += weight;
    }

    return (row)*(weight) + ( col );
}

float get_neigh_average(float *points, int row, int col,int col_stride, int stride) {
    //Note(sharo): assumed row, col are the middle point
    
    int t = convert_to_index(row-col_stride, col, stride); 
    int l = convert_to_index(row+col_stride, col, stride); 
    int r = convert_to_index(row, col-col_stride, stride); 
    int b = convert_to_index(row, col+col_stride, stride);  

#if DEBUG 
    std::cout << "r,c: " << row << " " << col;
    std::cout << " t,b,l,r: " << t << " " << b  << " " << l  << " " << r << std::endl;
#endif

    float ave = (points[t]+
                 points[l]+
                 points[b]+
                 points[r])/4.0;
    return ave;
}

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<float> dist;

void square_step(float *points, int x, int y, int col_stride, int stride) { 
    //Note(sharo): x, y, are the row and column of the middle point
    int l = convert_to_index(x, y - col_stride, stride);
    int t = convert_to_index(x-col_stride, y  , stride);
    int r = convert_to_index(x, y+col_stride  , stride);
    int b = convert_to_index(x+col_stride, y  , stride);
    
#if DEBUG
    std::cout << "LTRB: " << l << " "
                          << t << " "
                          << r << " "
                          << b << " ";
    std::cout << "x,y,rn: " << x << " " << y << " " << col_stride<< std::endl;
#endif
     
    points[t] = get_neigh_average(points, x, y - col_stride, col_stride, stride) + dist(mt);
    points[l] = get_neigh_average(points, x - col_stride, y, col_stride, stride) + dist(mt);
    points[r] = get_neigh_average(points, x, y + col_stride, col_stride, stride) + dist(mt);    
    points[b] = get_neigh_average(points, x + col_stride, y, col_stride, stride) + dist(mt); 
}

//Note(sharo): diamond step, will edit the points variable.
//x, y: are the middle point
void diamond_step(float* points, int x, int y, int col_stride, int stride) {

    int middle_index = convert_to_index(x, y, stride);

    float c1 = points[convert_to_index(x-col_stride, y-col_stride, stride)];
    float c2 = points[convert_to_index(x-col_stride, y+col_stride, stride)];
    float c3 = points[convert_to_index(x+col_stride, y-col_stride, stride)];
    float c4 = points[convert_to_index(x+col_stride, y+col_stride, stride)];

#if DEBUG
    std::cout << "index, (c1, c2, c3, c4): "
              << middle_index << " "
              << c1 << " "
              << c2 << " "
              << c3 << " " 
              << c4 << std::endl;
#endif

    points[middle_index] = (c1 + c2 + c3 + c4)/4.0 + dist(mt); 
}

//Todo(sharo): maybe add a seed variable for the random generator?
void diamond_square(float *points, float detail, float rough_const, float max_height) {

    std::cout << detail << std::endl; 
    
    //Note(sharo): this just remaking the random device
    dist = decltype(dist)(-max_height, max_height); 
    rough = max_height;
   
    //Note(sharo): amount to decrease the range by after each iteration
    //also reusing the same variable 
    rough_const = pow(2, -rough_const);

    //Note(sharo); seed the corners randomly
    points[0] = dist(mt);  
    points[convert_to_index(0, detail, detail+1)] = dist(mt);
    points[convert_to_index(detail, 0, detail+1)] = dist(mt); 
    points[convert_to_index(detail, detail, detail+1)] =  dist(mt);

 
    int col_stride = detail/2;
    //Note(sharo): repeat until the length is bigger than 1
    for(int i = detail; i > 1; i /= 2) { 
        for(int j = 0; j < detail; j += i) {  
            for(int k = 0; k < detail; k += i) {
                diamond_step(points, j+col_stride, k+col_stride, col_stride, detail+1);
            }  
        }

        for(int j = 0; j < detail; j += i) {
            for(int k = 0; k < detail; k += i) {            
                square_step(points, j+col_stride, k+col_stride, col_stride, detail+1);
            }
        } 

        std::cout << "hello world" << std::endl;
        //Note(sharo); decrease range of rough
        rough *= rough_const;
        col_stride = floor(col_stride/2.0);
    }
}
