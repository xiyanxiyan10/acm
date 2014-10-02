/*
 * @brief  快速模幂运算
 * @file powMod.C
 * @author xiyan
 * @CreatedTime 2014/10/02
 * @LastChanged 2014/10/02
 * @TODO 补充快速幂, 更多测试
 */



/* @brief 返回 ( (x^n)%P)
 * @param[in] x
 * @param[in] n
 * @param[in] p
 * @note 递归解
 */
long long powMod1(long long m, long long n, long long k){
    if(n == 0){
        return 1;
    }
    long long tmp = powMod1( (m*m)%k, n/2, k);
    if( (n&1) != 0){
        tmp = (tmp * m)%k;
    }
    return tmp;
}

/* @brief 返回 ( (m^n)%k)
 * @param[in] m
 * @param[in] n
 * @param[in] k
 * @note 非递归解
 */

long long  powMod2(long long   m , long long   n , long long   k){ 
     long long   ans = 1; 
     while(n){ 
         if(n&1)//如果n是奇数 
             ans = (ans * m ) % k; 
         n = n >> 1;//位运算“右移1类似除2” 
         m = (m * m) % k; 
     } 
     return ans; 

 }


int main()
{

    return 0;
}
