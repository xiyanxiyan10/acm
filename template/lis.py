#! /usr/bin/python
#lis problame template

import sys;

def binary_search(vec, size, key):
    """binary search"""
    l = 0;
    r = size - 1;
    while l < r:
        mid = l + (r - l)/2;
        if(vec[mid] >= key):
            r = mid;
        else:
            l = mid + 1;
    return l;

def lis_cnt(s):
    """find the lis len, O(nlgn) algorithm"""
    lentot = len(s);
    vec = [0 for col in range(lentot)];
    vec[0] = s[0];
    lencnt = 1;
    for i in range(1, lentot):
        if s[i] >= vec[lencnt -1]:  
            vec[lencnt] = s[i];
            lencnt+= 1;
        else:
            pos = binary_search(vec, lencnt, s[i]);
            vec[pos] = s[i];
        print vec;  
        print lencnt;

    print "lis len of string %s is %d" %(s, lencnt);

def lis_str(s):
    """find the lis len, O(n^2) algorithm"""
    lentot = len(s);
    lencnt = -1;
    vec = [1 for col in range(lentot)];
    for i in range(0, lentot):
        for j in range(0, i):
            if s[i] >= s[j]:
                vec[i] = max(vec[i], vec[j] + 1);
                lencnt = max(lencnt, vec[i]);

    print "lis len of string %s is %d" %(s, lencnt);

if __name__ == "__main__":
    if( len(sys.argv) < 2):
        print "argc = %d" %(len(sys.argv));
    else:
        print "s = %s" %(sys.argv[1]);
        lis_cnt(sys.argv[1]);
        lis_str(sys.argv[1]);


