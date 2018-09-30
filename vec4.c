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
#include <math.h>
	
inline void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c){ //4d from 2d
	
	dest[0]=src_a[0];
	dest[1]=src_a[1];	
	dest[2]=src_b;
	dest[3]=src_c;
}

inline void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b){ //4d from 3d
	
	dest[0]=src_a[0];
	dest[1]=src_a[1];
	dest[2]=src_a[2];
	dest[3]=src_b;
}

inline void glmc_vec4f_copy(vec4f dest, vec4f src){ //4d to 4d
    dest[0]=src[0];
	dest[1]=src[1];
	dest[2]=src[2];
	dest[3]=src[3];
}

inline float glmc_vec4f_sqrlength(vec4f vec){ //Calculates square of length of vector
	return vec[0]*vec[0]+vec[1]*vec[1]+vec[2]*vec[2]+vec[3]*vec[3];
}

inline float glmc_vec4f_length(vec4f vec){ //Calculates square of length of vector
	return sqrt(glmc_vec4f_sqrlength(vec));
}

inline int  glmc_vec4f_is_normalized(vec4f src){ //Checks if vector is normalized
	if(glmc_vec4f_length(src)==1)
		return 1;
	else
		return 0;
}

inline void glmc_vec4f_normalize(vec4f dest, vec4f src){//Normalizes vector
	float l=glmc_vec4f_length(src);
	
	dest[0]=src[0]/l;
	dest[1]=src[1]/l;
	dest[2]=src[2]/l;
	dest[3]=src[3]/l;
	
}

inline void glmc_vec4f_add(vec4f dest, vec4f src_a, vec4f src_b){ // dest = src_a + src_b
	dest[0]=src_a[0]+src_b[0];
	dest[1]=src_a[1]+src_b[1];
	dest[2]=src_a[2]+src_b[2];
	dest[3]=src_a[3]+src_b[3];
}

inline void glmc_vec4f_add_dest(vec4f src_dest, vec4f src_b){// dest += src_a
	
	src_dest[0]=src_dest[0]+src_b[0];
	src_dest[1]=src_dest[1]+src_b[1];
	src_dest[2]=src_dest[2]+src_b[2];
	src_dest[3]=src_dest[3]+src_b[3];
	
}

inline void glmc_vec4f_sub(vec4f dest, vec4f src_a, vec4f src_b){// dest = src_a - src_b
	dest[0]=src_a[0]-src_b[0];
	dest[1]=src_a[1]-src_b[1];
	dest[2]=src_a[2]-src_b[2];
	dest[3]=src_a[3]-src_b[3];
}

inline void glmc_vec4f_sub_dest(vec4f src_dest, vec4f src_b){ // dest -= src_a
	src_dest[0]=src_dest[0]-src_b[0];
	src_dest[1]=src_dest[1]-src_b[1];
	src_dest[2]=src_dest[2]-src_b[2];
	src_dest[3]=src_dest[3]-src_b[3];
}

inline void glmc_vec4f_mul(vec4f dest, vec4f src_a, vec4f src_b){// dest = src_a * src_b
	dest[0]=src_a[0]*src_b[0];
	dest[1]=src_a[1]*src_b[1];
	dest[2]=src_a[2]*src_b[2];
	dest[3]=src_a[3]*src_b[3];
}

inline void glmc_vec4f_mul_dest(vec4f src_dest, vec4f src_b){// dest *= src_a
	src_dest[0]=src_dest[0]*src_b[0];
	src_dest[1]=src_dest[1]*src_b[1];
	src_dest[2]=src_dest[2]*src_b[2];
	src_dest[3]=src_dest[3]*src_b[3];
}

inline void glmc_vec4f_mul_s(vec4f dest, vec4f src_a, float src_b){// dest = src_a * scalar
	dest[0]=src_a[0]*src_b;
	dest[1]=src_a[1]*src_b;
	dest[2]=src_a[2]*src_b;
	dest[3]=src_a[3]*src_b;
}

inline void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b){// dest = src_a / src_b
	dest[0]=src_a[0]/src_b[0];
	dest[1]=src_a[1]/src_b[1];
	dest[2]=src_a[2]/src_b[2];
	dest[3]=src_a[3]/src_b[3];
}

inline void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_b){// dest /= src_a
	src_dest[0]=src_dest[0]/src_b[0];
	src_dest[1]=src_dest[1]/src_b[1];
	src_dest[2]=src_dest[2]/src_b[2];
	src_dest[3]=src_dest[3]/src_b[3];
}

inline void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b){// dest = src_a / scalar
	dest[0]=src_a[0]/src_b;
	dest[1]=src_a[1]/src_b;
	dest[2]=src_a[2]/src_b;
	dest[3]=src_a[3]/src_b;
}

inline void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b){// dest += src_a + src_b
	dest[0]=dest[0]+src_a[0]+src_b[0];
	dest[1]=dest[1]+src_a[1]+src_b[1];
	dest[2]=dest[2]+src_a[2]+src_b[2];
	dest[3]=dest[3]+src_a[3]+src_b[3];
}

inline void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b){// dest += src_a - src_b
	dest[0]=dest[0]+src_a[0]-src_b[0];
	dest[1]=dest[1]+src_a[1]-src_b[1];
	dest[2]=dest[2]+src_a[2]-src_b[2];
	dest[3]=dest[3]+src_a[3]-src_b[3];
}

inline void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b){// dest += src_a * src_b
	dest[0]=dest[0]+src_a[0]*src_b[0];
	dest[1]=dest[1]+src_a[1]*src_b[1];
	dest[2]=dest[2]+src_a[2]*src_b[2];
	dest[3]=dest[3]+src_a[3]*src_b[3];
}

inline void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b){// dest -= src_a * src_b
	dest[0]=dest[0]-src_a[0]*src_b[0];
	dest[1]=dest[1]-src_a[1]*src_b[1];
	dest[2]=dest[2]-src_a[2]*src_b[2];
	dest[3]=dest[3]-src_a[3]*src_b[3];	
}

inline float glmc_vec4f_dot(vec4f src_a, vec4f src_b){ //Calculates dot product of vectors

	return src_a[0]*src_b[0]+src_a[1]*src_b[1]+src_a[2]*src_b[2]*src_b[3]*src_b[3];
}

inline void glmc_vec4f_reflect(vec4f r, vec4f i, vec4f n){
	vec4f normalized;
	glmc_vec4f_normalize(normalized, n);
	vec4f product;
	glmc_vec4f_mul_s(product, normalized, 2*glmc_vec4f_dot(normalized, i));
	glmc_vec4f_sub(r, i, product);
}

inline void glmc_vec4f_refract(vec4f r, vec4f i, vec4f n, float eta){
	vec4f I;
	glmc_vec4f_normalize(I, i);
	vec4f N;
	glmc_vec4f_normalize(N, n);
	float d=glmc_vec4f_dot(N, I);
	float k=1.0- eta*eta*(1- d*d);

	if(k<0.0){
		r[0]=0.0f;
		r[0]=0.0f;
		r[0]=0.0f;
		r[0]=0.0f;
	}
	else{
		vec4f product1;
		glmc_vec4f_mul_s(product1, I, eta);
		vec4f product2;
		glmc_vec4f_mul_s(product2, N, eta*d+sqrt(k));
		glmc_vec4f_sub(r, product1, product2);
	}

}