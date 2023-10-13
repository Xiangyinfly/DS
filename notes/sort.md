## 两个数的交换
    void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    }
    该方法不适用两个数内存位置相同！
>异或的性质：交换律，结合律，0^n=n,n^n=0

