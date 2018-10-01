/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "glmc.h"
#include <stdio.h>

inline void glmc_vec2f_mat2f_mult(vec2f dest, mat2f src_a, vec2f src_b){ //Multiplying 2D vector and 2x2 matrix

	dest[0]=src_a[0][0]*src_b[0]+src_a[1][0]*src_b[1];
	dest[1]=src_a[0][1]*src_b[0]+src_a[1][1]*src_b[1];
}

inline void glmc_vec3f_mat3f_mult(vec3f dest, mat3f src_a, vec3f src_b){ //Multiplying 3D vector and 3x3 matrix

	dest[0]=src_a[0][0]*src_b[0]+src_a[1][0]*src_b[1]+src_a[2][0]*src_b[2];
	dest[1]=src_a[0][1]*src_b[0]+src_a[1][1]*src_b[1]+src_a[2][1]*src_b[2];
	dest[2]=src_a[0][2]*src_b[0]+src_a[1][2]*src_b[1]+src_a[2][2]*src_b[2];	
}

inline void glmc_vec4f_mat4f_mult(vec4f dest, mat4f src_a, vec4f src_b){ //Multiplying 4D vector and 4x4 matrix
	
	dest[0]=src_a[0][0]*src_b[0]+src_a[1][0]*src_b[1]+src_a[2][0]*src_b[2]+src_a[3][0]*src_b[3];
	dest[1]=src_a[0][1]*src_b[0]+src_a[1][1]*src_b[1]+src_a[2][1]*src_b[2]+src_a[3][1]*src_b[3];
	dest[2]=src_a[0][2]*src_b[0]+src_a[1][2]*src_b[1]+src_a[2][2]*src_b[2]+src_a[3][2]*src_b[3];
	dest[3]=src_a[0][3]*src_b[0]+src_a[1][3]*src_b[1]+src_a[2][3]*src_b[2]+src_a[3][3]*src_b[3];

}