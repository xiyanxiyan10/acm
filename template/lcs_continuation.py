#! /usr/bin/python

#find the max len continuity public substring of two string

import sys;
    
def lcs_con(s1, s2):
    len1 = len(s1) + 1;
    len2 = len(s2) + 1;
    if(len1 >= len2):
        lentot = len1;
    else:
        lentot = len2;

    #print "len_tot = %d, len1 = %d, len2 = %d" %(lentot, len1, len2);

    vec = [[0 for col in range(lentot)] for row in range(lentot)];
    lentot = -1;   #record tot len of this pub substring
    pos = -1;      #record the end pos of pub substring in substring
    for i in range(1, len1):
        for j in range(1, len2):
            if(s1[i - 1] == s2[j - 1]):
                    vec[i][j] = vec[i - 1 ][j - 1] + 1;
                    if(vec[i][j] > lentot):
                        lentot = vec[i][j]
                        pos = i;

    ans = "public substring : ";
    #print "len = %d" %(lentot);
    if(lentot > 0):
        for i in range(0, lentot):
            ans += s1[i + pos - lentot];
        print "%s" %(ans);


if __name__ == "__main__":
    if( len(sys.argv) < 3):
        print "argc = %d" %(len(sys.argv));
    else:
        print "s1 = %s" %(sys.argv[1]);
        print "s2 = %s" %(sys.argv[2]);
        lcs_con(sys.argv[1], sys.argv[2]); 


