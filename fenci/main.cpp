//
//  main.cpp
//  fenci
//
//  Created by Optimus Tian on 01/02/2017.
//  Copyright © 2017 Optimus Tian. All rights reserved.
//

#include <iostream>
#include "utf8.h"
#include <string>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    string origin = split(s);
    map<string,double> singleWordMap;
    map<string,double> doubleWordMap;
    const char *p;

    FILE *fp = fopen("/Users/optimustian/Downloads/so/news.sohunews.440806.txt.utf8.txt","r");
    const char *pr;
    char buf[10245];

    while(fgets(buf, 10245, fp))
    {
        fgets(buf, 10245, fp);
        fgets(buf, 10245, fp);
        fgets(buf, 10245, fp);
        fgets(buf, 10245, fp);
        s += string(buf);
        fgets(buf, 10245, fp);
    }

    p = s.c_str();
    int length = ustrlen(p);

    while(*p)
    {
        singleWordMap[fetchString(p)]++;
        p = useek(p);
    }

    p = s.c_str();
    for(map<string,double>::iterator pr = singleWordMap.begin(); pr != singleWordMap.end(); pr++)
        pr->second /= length;
        
    p = s.c_str();
    while((*p) || (*(p+1)))
    {
        doubleWordMap[fetchString(p,2)]++;
        p = useek(p);
    }

    for(map<string,double>::iterator pr = doubleWordMap.begin(); pr != doubleWordMap.end(); pr++)
    {
        pr->second /= length;
        const char *ppr = pr->first.c_str();
        int len = ustrlen(ppr);

        double p = 1;
        const char *pppr=ppr;
        for(int i = 1; i <= len; i++)
        {
            p *= singleWordMap[fetchString(pppr)];
            pppr = useek(pppr);
        }
        //if(p>1e-8)
        if(len == 2 && pr->second > 10000 * p)
        {
            //if(singleWordMap[first])
            cout<< pr->first <<endl;
            len = 0;
        }
        //cout<<pr->first<<" "<<pr->second<<" "<<singleWordMap[first]*singleWordMap[second]<<endl;
    }
}
