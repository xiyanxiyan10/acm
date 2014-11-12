/*
 * @brief hdu 5060
 * @file 5060.c
 * @author xiyan
 * @CreatedTime 2014/11/12
 * @LastChanged 2014/11/12
 * @note
 *      type: geometry
 *
 *
 */
#include <stdio.h>

float R,HR,HZ;
const float pai = 3.141592653589793238462643;

float s0, s1;   /*s0 圆球体积, s1圆柱体积*/
float ans;      /*答案，所求概率*/


int main()
{
    while( 1 == scanf("%f", &R)){
        scanf("%f%f", &HR, &HZ);

        s0 = (4.0/3.0)*pai*R*R*R;   /*球体积*/
        s1 = 2.0*pai*HR*HR*HZ;      /*柱体积*/
     
        /*TODO 积分? */

    }

    return 0;
}



