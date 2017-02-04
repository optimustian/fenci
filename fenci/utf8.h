//
//  utf8.h
//  fenci
//
//  Created by Optimus Tian on 01/02/2017.
//  Copyright © 2017 Optimus Tian. All rights reserved.
//

#ifndef utf8_h
#define utf8_h

int getSize(unsigned char c);

std::string fetchString(const char *p,int length = 1);

const char * useek(const char *p,int length=1);

std::string revert(std::string &s);

std::string split(std::string &s);

int ustrlen(const char *p);

#endif /* utf8_h */
