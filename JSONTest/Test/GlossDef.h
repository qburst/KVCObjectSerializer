//
//  GlossDef.h
//  JSONTest
//
//  Created by mahadevan on 15/12/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KVCBaseObject.h"

@interface GlossDef : KVCBaseObject
{
    NSArray * GlossSeeAlso;
}

@property (nonatomic, retain) NSArray * GlossSeeAlso;

@end
