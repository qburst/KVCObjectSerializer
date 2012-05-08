//
//  GlossEntry.h
//  JSONTest
//
//  Created by mahadevan on 15/12/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "KVCBaseObject.h"
#import "GlossDef.h"

@interface GlossEntry : KVCBaseObject
{
    NSString * Abbrev;
    NSString * Acronym;
    GlossDef * GlossDef;
    NSString * GlossSee;
    NSString * GlossTerm;
    NSString * ID;
    NSString * SortAs;
    
}
@property(nonatomic, retain) NSString * Abbrev;
@property(nonatomic, retain) NSString * Acronym;
@property(nonatomic, retain) GlossDef * GlossDef;
@property(nonatomic, retain) NSString * GlossSee;
@property(nonatomic, retain) NSString * GlossTerm;
@property(nonatomic, retain) NSString * ID;
@property(nonatomic, retain) NSString * SortAs;

@end
