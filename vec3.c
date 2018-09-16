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
	
void glmc_vec3f_from_2f(vec3f dest, vec2f src_a, float src_b){
	for(int i=0; i<2; i++){
		dest[i]=src_a[i];
	}
	dest[2]=src_b;
}

void glmc_vec3f_from_4f(vec3f dest, vec4f src){
	for(int i=0; i<3; i++){
		dest[i]=src[i];
	}
}

void glmc_vec3f_copy(vec3f dest, vec3f src){
	for(int i=0; i<3; i++){
		dest[i]=src[i];
	}
}

float glmc_vec3f_sqrlength(vec3f vec){
	float ans=0.0;
	for(int i=0; i<3; i++){
		ans=ans+vec[i]*vec[i];
	}
	return ans;
}

float glmc_vec3f_length(vec3f vec){
	return sqrt(glmc_vec3f_sqrlength(vec));
}

int  glmc_vec3f_is_normalized(vec3f src){
	if(glmc_vec3f_length(src)==1)
		return 1;
	else
		return 0;
}

void glmc_vec3f_normlize(vec3f dest, vec3f src){
	float l=glmc_vec3f_length(src);

	for(int i=0; i<3; i++){
		dest[i]=src[i]/l;
	}
}

void glmc_vec3f_add(vec3f dest, vec3f src_a, vec3f src_b){ 
	for(int i=0; i<3; i++){
		dest[i]=src_a[i]+src_b[i];
	}
}

void glmc_vec3f_add_dest(vec3f src_dest, vec3f src_b){
	for(int i=0; i<3; i++){
		src_dest[i]=src_dest[i]+src_b[i];
	}
}

void glmc_vec3f_sub(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0; i<3; i++){
		dest[i]=src_a[i]-src_b[i];
	}
}

void glmc_vec3f_sub_dest(vec3f src_dest, vec3f src_b){
	for(int i=0; i<3; i++){
		src_dest[i]=src_dest[i]-src_b[i];
	}
}

void glmc_vec3f_mul(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0; i<3; i++){
		dest[i]=src_a[i]*src_b[i];
	}
}

void glmc_vec3f_mul_dest(vec3f src_dest, vec3f src_b){
	for(int i=0; i<3; i++){
		src_dest[i]=src_dest[i]*src_b[i];
	}
}

void glmc_vec3f_mul_s(vec3f dest, vec3f src_a, float src_b){
	for(int i=0; i<3; i++){
		dest[i]=src_a[i]*src_b;
	}
}

void glmc_vec3f_div(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0; i<3; i++){
		dest[i]=src_a[i]/src_b[i];
	}
}

void glmc_vec3f_div_dest(vec3f src_dest, vec3f src_b){
	for(int i=0; i<3; i++){
		src_dest[i]=src_dest[i]/src_b[i];
	}
}

void glmc_vec3f_div_s(vec3f dest, vec3f src_a, float src_b){
	for(int i=0; i<3; i++){
		dest[i]=src_a[i]/src_b;
	}
}

void glmc_vec3f_addadd(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0; i<3; i++){
		dest[i]=dest[i]+src_a[i]+src_b[i];
	}
}

void glmc_vec3f_subadd(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0; i<3; i++){
		dest[i]=dest[i]+src_a[i]-src_b[i];
	}
}

void glmc_vec3f_madd(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0; i<3; i++){
		dest[i]=dest[i]+src_a[i]*src_b[i];
	}
}

void glmc_vec3f_msub(vec3f dest, vec3f src_a, vec3f src_b){
	for(int i=0; i<3; i++){
		dest[i]=dest[i]-src_a[i]*src_b[i];
	}	
}

float glmc_vec3f_dot(vec3f src_a, vec3f src_b){
	float dot=0.0;
	for(int i=0; i<3; i++){
		dot=dot+src_a[i]*src_b[i];
	}
	return dot;
}

void  glmc_vec3f_cross(vec3f dest, vec3f src_a, vec3f src_b){
	dest[0]=src_a[1]*src_b[2]-src_b[1]*src_a[2];
	dest[1]=src_a[2]*src_b[0]-src_b[2]*src_a[0];
	dest[2]=src_a[0]*src_b[1]-src_b[0]*src_a[1];
}