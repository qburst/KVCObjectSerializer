//
//  KVCTestObject.m
//  JSONTest
//
//  Created by mahadevan on 26/10/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "KVCTestObject.h"

@implementation KVCTestObject

@synthesize isAvailable;
@synthesize kName;
@synthesize kAge;
@synthesize addressField;
@synthesize kChildrenArray;
@synthesize kChildObject;
@synthesize doubleValue;

-(id) init {
    if (self = [super init]) {

    }
    return self;   
}

- (NSString *)getComponentTypeForCollection:(NSString *)propertyName {
    if ([propertyName isEqualToString:@"kChildrenArray"]) {
        return @"KVCChildObject";
    }
    return nil;
}

-(NSString *)getPropertyNameForJsonKey:(NSString *)jsonKey {
    if ([jsonKey isEqualToString:@"kAddress"]) {
        return @"addressField";
    } else if ([jsonKey isEqualToString:@"kAvailable"]) {
        return @"isAvailable";
    }
    return nil;
}
@end
