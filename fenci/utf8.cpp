//
//  utf8.cpp
//  fenci
//
//  Created by Optimus Tian on 01/02/2017.
//  Copyright © 2017 Optimus Tian. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <set>
int getSize(unsigned char c)
{
    if((c>>2)==0x3F)
        return 6;
    if((c>>3)==0x1F)
        return 5;
    if((c>>4)==0x0F)
        return 4;
    if((c>>5)==0x07)
        return 3;
    if((c>>6)==0x03)
        return 2;
    return 1;
}

std::string fetchString(const char *p,int length = 1)
{
    int len=0;
    const char *start=p;
    while(length--)
    {
        int s=getSize(*p);
        p+=s;
        len+=s;
    }
    return std::string(start,start+len);
}

const char * useek(const char *p,int length=1)
{
    while(length--)
        p+=getSize(*p);
    return p;
}

std::string revert(std::string &s)
{
    std::string ans;
    const char *p=s.c_str();
    std::vector<std::string> ve;
    while(*p)
    {
        ve.push_back(fetchString(p));
        p=useek(p);
    }
    while(!ve.empty())
    {
        ans+=ve.back();
        ve.pop_back();
    }
    return ans;
}

std::string split(std::string &s)
{
    std::string sig[]={"，","。","／","？","《","》","；","‘","：","“","【","】","「","」","、","|","·","～","！","@","#","¥","%","……","&","*","（","）","-","——","=","+"};
    std::set<std::string> se;
    for(int i=31;i>=0;i--)
        se.insert(sig[i]);
    std::string ans;
    const char *p=s.c_str();
    while(*p)
    {
        std::string fetch=fetchString(p);
        if(!se.count(fetch))
            ans+=fetch;
        else
            ans+=' ';
        p=useek(p);
    }
    return ans;
}

int ustrlen(const char *p)
{
    int ans=0;
    while(*p)
    {
        p=useek(p);
        ans++;
    }
    return ans;
}
