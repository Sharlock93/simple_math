#ifndef DIAMOND_SQUARE
#define DIAMOND_SQUARE
// #define DEBUG
//Note(sharo): 

inline int convert_to_index(int row, int col, int stride);

float get_neigh_average(float *points, int x, int y, int col_stride, int stride);
void square_step       (float *points, int x, int y, int col_stride, int stride);
void diamond_step      (float *points, int x, int y, int col_stride, int stride); 
void diamond_square    (float *points, float detail, float rough_const, float max_height);

#endif /* ifndef DIAMOND_SQUARE */
